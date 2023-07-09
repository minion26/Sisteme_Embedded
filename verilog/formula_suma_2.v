module MUL(Clk, A, B, start, R, ack);
input Clk, start; //1 bit
input [15:0] A, B; //pe 4 biti
output reg ack;
output reg [15:0] R;
reg [15:0] X,Y;
reg [1:0] stare;
always @(posedge Clk)
    if(stare==0)
        if(start==1) begin
            X <= A;
            Y <= B;
            R <= 0;
            ack <= 0;
            stare <= 1;
        end
        else  stare <=0; //start=0
    else if(stare==1)
        if(Y==0) begin
            ack <= 1;
            stare <= 2;
        end
        else begin
            R <= R + X;
            Y <= Y - 1;
            stare <= 1;
        end
    else if(stare==2) 
            stare <= 0;
initial begin
    stare <= 0;
    ack <= 0;
end
endmodule

module FORMULA(input Clk, input start, input [15:0] n,
 output reg [15:0]sum, output reg ack);

reg [15:0] v[6:0];
reg [2:0] stare;
reg [15:0] i;
reg [15:0] element; //element din vector
reg [15:0] element2;

reg [15:0] rezultatMUL;
reg startMUL;
wire [15:0] outMUL;
wire doneMUL;

MUL m(Clk, element, element2, startMUL, outMUL, doneMUL);

always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            i <= 0;
            sum <= 0;
            ack<=0;
            rezultatMUL <= 0;
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
        if (i >= 7)begin
            stare <= 5;
        end
        else
            stare <= 2;
    else if(stare == 2)begin
        element<=v[i];
        element2<=i+n;
        startMUL<=1;
        stare<=3;
    end
    else if(stare == 3)begin
        startMUL <= 0;
        stare <=4;
    end
    else if(stare==4)
        if(doneMUL == 0)
            stare <= 4;
        else begin
            sum <= sum + outMUL;
            i <= i+1;
            stare <= 1;
        end
    else if(stare==5)begin
        ack<=1;
        stare<=0;
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
    #5 start <= 1;
    #10 start <= 0;
    #99999 $finish();

end
endmodule