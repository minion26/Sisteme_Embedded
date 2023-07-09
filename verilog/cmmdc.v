module CMMDC(Clk, A, B, rez, start, ack);
input Clk, start;
input [7:0] A, B;
output reg ack;
output reg [7:0] rez;
reg [7:0] stare;
reg [7:0] X, Y;
always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            X<=A;
            Y<=B;
            rez<=0;
            ack<=0;
            stare<=1;
        end
        else stare<=0;
    else if(stare == 1)
        if(X == Y)begin
            rez <= X;
            stare <= 2;
        end
        else if (X > Y) begin
            X <= X - Y;
            stare <= 1;
        end
        else if (Y > X) begin
            Y <= Y - X;
            stare <= 1;
        end
    else if(stare == 2) begin
        ack <= 1;
        stare <=0;
    end
initial begin
    stare<=0;
    ack<=0;
end
endmodule

module ceas(c);
output reg c;
always 
    #5 c<=~c;
initial
    c<=0;
endmodule

module main();
reg start;
reg[7:0] A, B;
wire ack;
wire[7:0] rez;
wire Clk;
ceas cc(Clk);
CMMDC c(Clk, A, B, rez, start, ack);
initial begin
    $monitor("%d %d %d %d",$time, A, B, rez);
    A<=2;
    B<=6;
    #4 start <= 1;
    #10 start <= 0;
    #200 $finish();
end
endmodule

