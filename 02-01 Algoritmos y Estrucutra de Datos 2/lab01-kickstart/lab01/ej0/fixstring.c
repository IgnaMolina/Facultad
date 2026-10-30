#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    
    int i = 0;
    int sum = 0;

    while (s[i] != '\0') {
    
        sum = sum + 1;
        i = i+1;
    }
    return sum;
}

bool fstring_eq(fixstring s1, fixstring s2) {

    int i = 0;
    bool check = true;

    if (fstring_length (s1) != fstring_length (s2))
    {
        check = false;
    }
      else { 
       while (s1[i] != '\0' && s2[i] != '\0')
       {
           if (s1[i] != s2[i])
           {
              check = false;
           }
           i = i+1;
         
                                         
        };  
    }
    return check;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool check = true; 
    int tam_s1 = 0;
    int tam_s2 = 0;
    
    while (s1[i] != '\0' || s2[i] != '\0' ) {   
        if (s1[i] != s2[i]) {  
            tam_s1 = tam_s1 + s1[i];
            tam_s2 = tam_s2 + s2[i]; 
        }
        i= i + 1; 
    }

    if (tam_s1 > tam_s2) {
        check = false;
    }

    return check; 
}

