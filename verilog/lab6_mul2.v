module MUL2(Clk, A, B, start, R, ack);
input Clk, start; //1 bit
input [3:0] A, B; //pe 4 biti
output reg ack;
output reg [7:0] R;
reg [3:0] X,Y;
reg [1:0] stare;
always @(posedge Clk)
    if(stare==0)
        if(start==1) begin
            X <= A;
            Y <= B;
            R <= 0;
            ack <= 0;
            stare <= 1; //ma duc in s1
        end
        else stare <= 0; //raman in s0
    else if(stare==1)
        if(~Y==1) begin
            R <= R & Y;
            
        end