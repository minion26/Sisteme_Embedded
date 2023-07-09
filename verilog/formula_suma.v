//input vector cu 7 elemente = v
//input un nr n
//i=0 sum=0
//while i <= 7 do
//  suma_mica = n + i
//  inmultire = v[i] * suma_mica
//  sum = sum + inmultire
module FORMULA(input Clk, input start, input [15:0] n,
 output reg [15:0]sum, output reg ack);
reg [15:0] v[6:0];
reg [2:0] stare;
reg [15:0] i;
always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            i <= 0;
            sum <= 0;
            ack<=0;
            v[0]<=1;
            v[1]<=1;
            v[2]<=1;
            v[3]<=1;
            v[4]<=1;
            v[5]<=1;
            v[6]<=1;
            stare <=1;
        end
        else stare <= 0;
    else if(stare == 1)
        if (i < 7)begin
            sum <= sum + v[i] * (n+i);
            i<=i+1;
            stare <= 1;
        end
        else if(i == 7)begin
            sum <= sum + v[i] * (n+i);
            ack<=1;
            stare<=2;
        end
    else if(stare == 2)begin
        //ack<=1;
        stare <= 0;
    end
initial begin
    $monitor("%d %d %d",$time, i,  sum);
    stare <= 0;
    ack<=0;
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
reg [15:0] n;
wire [15:0] sum;
wire ack;
wire Clk;
ceas cc(Clk);
FORMULA f(Clk, start, n, sum, ack);
initial begin
    //$monitor("%d %d %d",$time, n,  sum);
    n<=1;
    #4 start <= 1;
    #10 start <= 0;
    #200 $finish();

end
endmodule