`timescale 1ns / 1ps

module adder_1bit(
    input a,
    input b,
    input carry_in,
    output add,
    output carry_out
    );
    
    logic e,f,x;
    xor_gate x1(.a(a),.b(b),.y(e));
    and_gate an1(.a(a),.b(b),.y(f));
    and_gate an2(.a(e),.b(carry_in),.y(z));
    xor_gate x2(.a(e),.b(carry_in),. y(add));
    or_gate o1(.a(z),.b(f),.y(carry_out));
    
    

     
    
         
endmodule
