clear;clc;close all;

fid=fopen('matrix_col_1.txt');
data=textscan(fid,'%d %f');
fclose(fid);
x=data{1};
matrixcol1_y=data{2};

fid=fopen('matrix_col_max.txt');
data=textscan(fid,'%d %f')
fclose(fid);
matrixcolmax_y=data{2};

fid=fopen('matrix_row_1.txt');
data=textscan(fid,'%d %f')
fclose(fid);
matrixrow1_y=data{2};

fid=fopen('matrix_row_max.txt');
data=textscan(fid,'%d %f')
fclose(fid);
matrixrowmax_y=data{2};



figure;
title('matrix multiplication');
xlabel('n [-]');
ylabel('t [s]');
hold on;
plot(x,matrixcol1_y);
plot(x,matrixcolmax_y);
plot(x,matrixrow1_y);
plot(x,matrixrowmax_y);
legend('col_1','col_m','row_1','row_m','Location','northwest');
hold off;