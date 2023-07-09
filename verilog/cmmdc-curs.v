module cmmdc(Clk,start,x,y,r,ack);
input Clk,start;
input [7:0]x,y;
output reg [7:0]r;
output reg ack;
reg [7:0]a,b;
reg [1:0]state;
always @(posedge Clk)
    if(state==0)
        if(start==1) begin
            a<=x;
            b<=y;
            ack<=0;
            state<=1;
        end
    else state<=0;
    else if(state==1)
        if(a==b) begin
            r<=a;
            state<=2;
        end
        else if(a>b) begin
            a<=a-b;
            state<=1;
        end
        else begin
            b<=b-a;
            state<=1;
        end
    else if(state==2) begin
        ack<=1;
        state<=0;
    end

initial begin
state<=0;
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
cmmdc c(Clk, satrt, A, B, rez, ack);
initial begin
    $monitor("%d %d %d %d",$time, A, B, rez);
    A<=2;
    B<=4;
    #4 start <= 1;
    #10 start <= 0;
    #200 $finish();
end
endmodule

