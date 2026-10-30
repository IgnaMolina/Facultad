`timescale 1ns / 1ps

module alu(
    input a_in_0,
    input a_in_1,
    input a_in_2,
    input a_in_3,
    input b_in_0,
    input b_in_1,
    input b_in_2,
    input b_in_3,
    input alu_op_0,
    input alu_op_1,
    input alu_op_2,
    output alu_result_0,
    output alu_result_1,
    output alu_result_2,
    output alu_result_3,
    output zero_flag,
    output carry_flag
    );
   
       
    //------------------------- AND (000) -------------------------
    logic and_out_4,and_out_5,and_out_6,and_out_7;
    and_gate A1(.a(a_in_0),.b(b_in_0),.y(and_out_4));
    and_gate A2(.a(a_in_1),.b(b_in_1),.y(and_out_5));
    and_gate A3(.a(a_in_2),.b(b_in_2),.y(and_out_6));
    and_gate A4(.a(a_in_3),.b(b_in_3),.y(and_out_7));
    //------------------------- OR  (001) -------------------------
    logic or_out_8,or_out_9,or_out_10,or_out_11;
    or_gate O1(.a(a_in_0),.b(b_in_0),.y(or_out_8));
    or_gate O2(.a(a_in_1),.b(b_in_1),.y(or_out_9));
    or_gate O3(.a(a_in_2),.b(b_in_2),.y(or_out_10));
    or_gate O4(.a(a_in_3),.b(b_in_3),.y(or_out_11));
    //------------------------- ADD (010) -------------------------
    logic add_out_12,add_out_13,add_out_14,add_out_15,carry_out_1,carry_out_2,carry_out_3,carry_out_4;
    adder_1bit D1(.a(a_in_0),.b(b_in_0),.carry_in(1'b0),.add(add_out_12),.carry_out(carry_out_1));
    adder_1bit D2(.a(a_in_1),.b(b_in_1),.carry_in(carry_out_1),.add(add_out_13),.carry_out(carry_out_2));
    adder_1bit D3(.a(a_in_2),.b(b_in_2),.carry_in(carry_out_2),.add(add_out_14),.carry_out(carry_out_3));
    adder_1bit D4(.a(a_in_3),.b(b_in_3),.carry_in(carry_out_3),.add(add_out_15),.carry_out(carry_out_4));
    //------------------------- SUB (110) -------------------------
    logic not_out_1,not_out_2,not_out_3,not_out_4;
    not_gate N1(.a(b_in_0),.y(not_out_1));
    not_gate N2(.a(b_in_1),.y(not_out_2));
    not_gate N3(.a(b_in_2),.y(not_out_3));
    not_gate N4(.a(b_in_3),.y(not_out_4));
    
    logic carry_in_4,carry_in_5,carry_in_6, add_out_16,add_out_17,add_out_18,add_out_19;
    adder_1bit D5(.a(not_out_1),.b(1'b1),.carry_in(1'b0),.carry_out(carry_in_4),.add(add_out_16));
    adder_1bit D6(.a(not_out_2),.b(1'b0),.carry_in(carry_in_4),.carry_out(carry_in_5),.add(add_out_17));
    adder_1bit D7(.a(not_out_3),.b(1'b0),.carry_in(carry_in_5),.carry_out(carry_in_6),.add(add_out_18));
    adder_1bit D8(.a(not_out_4),.b(1'b0),.carry_in(carry_in_6),.add(add_out_19));
    
    logic carry_in_7,carry_in_8,carry_in_9,carry_in_10,and_out_23, and_out_24, and_out_25, and_out_26 ;
    adder_1bit D9(.a(a_in_0),.b(add_out_16),.carry_in(1'b0),.add(and_out_23),.carry_out(carry_in_7));
    adder_1bit D10(.a(a_in_1),.b(add_out_17),.carry_in(carry_in_7),.add(and_out_24),.carry_out(carry_in_8));
    adder_1bit D11(.a(a_in_2),.b(add_out_18),.carry_in(carry_in_8),.add(and_out_25),.carry_out(carry_in_9));
    adder_1bit D12(.a(a_in_3),.b(add_out_19),.carry_in(carry_in_9),.add(and_out_26),.carry_out(carry_in_10));

    //------------------------- PIB (111) -------------------------
    
    //---------------------------- MUX ----------------------------
    
    mux8_1 M1(.d0(and_out_4),.d1(or_out_8),.d2(add_out_12),.d3(1'b0),.d4(1'b0),.d5(1'b0),.d6(and_out_23),.d7(b_in_0),.sel_0(alu_op_0),.sel_1(alu_op_1),.sel_2(alu_op_2),.y(alu_result_0));
    mux8_1 M2(.d0(and_out_5),.d1(or_out_9),.d2(add_out_13),.d3(1'b0),.d4(1'b0),.d5(1'b0),.d6(and_out_24),.d7(b_in_1),.sel_0(alu_op_0),.sel_1(alu_op_1),.sel_2(alu_op_2),.y(alu_result_1));
    mux8_1 M3(.d0(and_out_6),.d1(or_out_10),.d2(add_out_14),.d3(1'b0),.d4(1'b0),.d5(1'b0),.d6(and_out_25),.d7(b_in_2),.sel_0(alu_op_0),.sel_1(alu_op_1),.sel_2(alu_op_2),.y(alu_result_2));
    mux8_1 M4(.d0(and_out_7),.d1(or_out_11),.d2(add_out_15),.d3(1'b0),.d4(1'b0),.d5(1'b0),.d6(and_out_26),.d7(b_in_3),.sel_0(alu_op_0),.sel_1(alu_op_1),.sel_2(alu_op_2),.y(alu_result_3));
    //--------------------------- FLAGS ---------------------------
    
    logic or_gate_out_1,or_gate_out_2,or_out51;
    or_gate zero1(.a(alu_result_0),.b(alu_result_1),.y(or_gate_out_1));
    or_gate zero2(.a(alu_result_2),.b(alu_result_3),.y(or_gate_out_2));
    or_gate zero3(.a(or_gate_out_1),.b(or_gate_out_2),.y(or_out_5));
    not_gate zeroflag(.a(or_out_5),.y(zero_flag));
    
    mux8_1 M5(.d0(1'b0),.d1(1'b0),.d2(carry_out_4),.d3(1'b0),.d4(1'b0),.d5(1'b0),.d6(carry_in_10),.d7(1'b0),.sel_0(alu_op_0),.sel_1(alu_op_1),.sel_2(alu_op_2),.y(carry_flag));   
endmodule
