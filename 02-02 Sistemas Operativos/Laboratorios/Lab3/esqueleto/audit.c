#include "fat_file.h"
#include "fat_fs_tree.h"
#include "fat_table.h"
#include "fat_types.h"
#include "audit.h"
#include "fat_fuse_ops.h"
#include "fat_volume.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

//Modularizacion: Crea un archivo o directorio bajo un parent si no existe, devuelve el nodo o NULL si falla.
static fat_tree_node audit_ensure(fat_volume vol, fat_tree_node parent_node, const char *path, bool is_dir){
    //Buscamos en el arbol de memoria un nodo con ese path, si ya existe lo devuelve, evita crear dos veces /.autid.
    fat_tree_node node = fat_tree_node_search(vol->file_tree, path);
    if(node != NULL){
        return node; //Ya existe
    }
    //Extraigo el nodo del padre con fat_tree_get_file
    fat_file parent = fat_tree_get_file(parent_node);
    //Creo un nuevo file, f, con su tamaño y el path que le paso (dependiendo si es la carpeta audit o el archivo log). Le pasamos True o False dependiendo si es un file o un directory.
    fat_file f = fat_file_init(vol->table, is_dir, strdup(path));
    if(f == NULL){
        return NULL;
    }
    //El archivo va a estar en el primer espacio lbire del padre
    f->pos_in_parent = parent->dir.nentries;
    //Agrego f al arbol de memoria
    vol->file_tree = fat_tree_insert(vol->file_tree, parent_node, f);
    //Escribo la entrada de directorio en disco (el claustro del padre) y suma 1 al directorio del padre
    fat_file_add_child_direntry(parent, f->dentry, f->pos_in_parent);
    //Busco el nodo creado, ya que fat_tree_insert da la raiz creo, y lo devuelvo
    return fat_tree_node_search(vol->file_tree, path);
}
int audit_init (fat_volume vol){
    fprintf(stderr, ">>> audit_init llamado\n");
    fat_tree_node root = fat_tree_node_search(vol->file_tree, "/");
    if(root == NULL){
        return 1;
    }

    fat_tree_node dir = audit_ensure(vol, root, "/.audit", true);
    if(dir == NULL){
        return 1;
    }

    fat_tree_node log = audit_ensure(vol, dir, "/.audit/events.bin", false);
    if(log == NULL){
        return 1;
    }
    return 0;
}