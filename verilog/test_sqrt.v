module SQRT(Clk, A, start, sol, ack);
input Clk, start;
input [7:0] A;
output reg ack;
output reg [3:0] sol;
reg [7:0] X, aux, copieA;
reg [1:0] stare;

always @(posedge Clk)
	if (stare == 0) begin
		X <= 1;
		aux <= X * X;
		copieA <= A;
		sol <= 0;
		ack <= 0;
		stare <= 1;
	end
	else
		if (stare == 1)
			if (aux > copieA) begin
				sol <= X - 2;
				stare = 2;
			end
			else
				begin
					X <= X + 1;
					aux <= X * X;
					stare  <= 1;
				end
		else
			if(stare == 2) begin
				stare <= 0;
			end
				
		

initial begin
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
reg [7:0] A;
wire ack;
wire [3:0] sol;
wire Clk;
ceas cc(Clk);
SQRT m(Clk, A, start, sol, ack);
initial begin
    $monitor ("%t %d %d", $time, A, sol);
    A <= 81;
	#121 $finish();
    end
endmodule
