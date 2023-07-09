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

module patrat2(Clk, A, B, P, start, ack);
input Clk, start;
input[15:0] A, B;
output reg ack;
output reg [15:0] P;

reg [15:0] rezultatMUL;
reg startMUL;
wire [15:0] outMUL;
wire doneMUL; //ack

reg [15:0] M, N;
reg [2:0] stare;

MUL m(Clk, P, M, startMUL, outMUL, doneMUL);

always @(posedge Clk)
    if(stare == 0)
        if(start == 1)begin
            M <= A;
            N <= B;
            ack <= 0;
            P <= 1;
            rezultatMUL <= 1;
            stare <= 1;
        end
        else stare <= 0;
    else if(stare == 1) begin
        if (N == 0)
            stare <=5;
        else
            stare <=2;
    end
    else if(stare == 2)begin
        startMUL <= 1;
        stare <= 3;
    end
    else if( stare == 3)begin
        startMUL <= 0;
        stare <= 4;
    end
    else if(stare == 4)
        if(doneMUL == 0)
            stare <= 4;
        else begin
            //rezultatMUL <= outMUL;
            P <= outMUL;
            N <= N - 1;
            stare <= 1;
        end
    else if(stare == 5)begin
        ack <= 1;
        stare <=0;
    end
    
initial begin
    //astea sunt instantiate in interior ca 0, nu e din main dat
    //$monitor("%d %d %d %d %d %d %d", P, N, rezultatMUL, outMUL, startMUL, doneMUL, ack);
    stare <= 0;
    ack <= 0;
    startMUL <= 0;
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
reg [15:0] A, B;
wire [15:0] P;
wire ack;
wire Clk;
ceas cc(Clk);
patrat2 p2(Clk, A, B, P, start, ack);
initial begin
    $monitor("%d %d %d %d",$time, A, B, P);
    A <= 3;
    B <= 1;
    #5 start <= 1;
    #10 start <= 0;
    #9999 $finish();

end
endmodule