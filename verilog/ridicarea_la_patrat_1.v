//m^n
//p=1, n
//while n > 0 do
//    p=p*m, n--
module patrat(Clk, A, B, P, start, ack);
input Clk, start;
input[3:0] A, B;
output reg ack;
output reg [15:0] P;
reg [3:0] M, N;
reg [1:0] stare;
always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            M <= A;
            N <= B;
            P <= 1;
            ack <= 0;
            stare <= 1;
        end
        else stare <=0;
    else if(stare == 1)
        if(N > 0)begin
            P <= P * M;
            N <= N - 1;
            stare <= 1;
        end
        else if(N == 0)begin
            ack <= 1;
            stare <= 2;
        end
    else if(stare == 2)
        stare <= 0;
initial begin
    //astea sunt instantiate in interior ca 0, nu e din main dat
    stare <= 0;
    ack <= 0;
end
endmodule

module ceas(c);
output reg c;
always
    #5 c <= ~c;
initial
    c <= 0;
endmodule

module main();
reg start;
reg [3:0] A, B;
wire [15:0] P;
wire ack;
wire Clk;
ceas cc(Clk);
patrat p(Clk, A, B, P, start, ack);
initial begin
    $monitor("%d %d %d %d",$time, A, B, P);
    A <= 3;
    B <= 2;
    #4 start <= 1;
    #10 start <= 0;
    #200 $finish();

end
endmodule