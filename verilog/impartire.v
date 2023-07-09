//count = 0;
// a/b
//while a >= b do
//   a=a-b; count++

module IMP(Clk, start, A, B, count, ack);
input Clk, start;
input [15:0] A, B;
output reg [15:0] count;
output reg ack;
reg [15:0] M, N;
reg [2:0] stare;

always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            M <= A;
            N <= B;
            count <= 0;
            ack <= 0;
            stare <= 1;
        end
        else stare <= 0;
    else if(stare == 1)
        if(M >= N)begin
            M <= M - N;
            count <= count + 1;
            stare <= 1;
        end
        else begin
            ack <= 1;
            stare <= 2;
        end
    else if(stare == 2) stare <= 0;
initial begin
    ack<=0;
    stare<=0;
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
reg[15:0] A, B;
wire ack;
wire Clk;
wire [15:0] count;
ceas c(Clk);
IMP imp(Clk, start, A, B, count, ack);
initial begin
    $monitor("%d %d %d %d", $time, A, B, count);
    A<=7;
    B<=2;
    #5 start <= 1;
    #10 start <= 0;
    #200 $finish();
end
endmodule