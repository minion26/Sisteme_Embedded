module SQRT(Clk, A, I, start, ack);
input Clk, start;
input [7:0] A;
output reg ack;
output reg [3:0] I;
reg [7:0] X;
reg [1:0] stare;
reg[7:0] P; //produsul
always @(posedge Clk)
    if(stare==0)
        if(start==1) begin
            X<=A;
            I<=0;
            P<=1;
            ack<=0;
            stare<=1;
        end
        else stare<=0;
    else if(stare==1)
        if(P <= X) begin
            I <= I + 1;
            P <= I * I;
            stare <= 1;
        end
        else begin
            I <= I - 2;
            stare <= 2;
            ack <= 1;
        end
    else if(stare==2)
            stare <= 0;
initial begin
    stare <= 0;
    ack <= 0;
end
endmodule


module ceas(c);
output reg c;
always 
    #5 c <= ~c; //perioada unui semnal dupa cat se repeta identic : 10 = 5 * 2
initial 
    c <= 0;
endmodule


module main();
reg start;
reg [7:0] A;
wire ack;
wire [3:0] I;
wire Clk;
ceas cc(Clk);
SQRT s(Clk, A, I, start, ack);
initial begin
    $monitor("%d %d %d",$time, A, I);
    A<=81;
    #4 start <= 1;
    #10 start <= 0;
    #200 $finish();
end
endmodule
        
