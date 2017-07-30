close all;
clc;

imu4=importdata('implicitdata4.csv');
imu8=importdata('implicitdata8.csv');
exu4=importdata('explicitdata4.csv');
exu8=importdata('explicitdata8.csv');
CNu4=importdata('CNdata4.csv');
CNu8=importdata('CNdata8.csv');
GSu4=importdata('GSdata4.csv');
GSu8=importdata('GSdata8.csv');
exact4=importdata('exact4.csv');
exact8=importdata('exact8.csv');
errorimp4=importdata('imperror4.csv');
errorimp8=importdata('imperror8.csv');
errorexp4=importdata('experror4.csv');
errorexp8=importdata('experror8.csv');
errorCN4=importdata('CNerror4.csv');
errorCN8=importdata('CNerror8.csv');
errorGS4=importdata('GSerror4.csv');
errorGS8=importdata('GSerror8.csv');
figure(1);

subplot(2,9,1);mesh(exu4);title('Explicit: 0.4');
subplot(2,9,2);mesh(imu4);title('Implicit: 0.4');
subplot(2,9,3);mesh(CNu4);title('CN: 0.4');
subplot(2,9,4);mesh(GSu4);title('GS: 0.4');

subplot(2,9,5);mesh(exu8);title('Explicit: 0.8');
subplot(2,9,6);mesh(imu8);title('Implicit: 0.8');
subplot(2,9,7);mesh(CNu8);title('CN: 0.8');
subplot(2,9,8);mesh(GSu8);title('GS: 0.8');


subplot(2,9,10);mesh(errorexp4);title('Explicit % Error: 0.4');
subplot(2,9,11);mesh(errorimp4);title('Implicit % Error: 0.4');
subplot(2,9,12);mesh(errorCN4);title('CN % Error: 0.4');
subplot(2,9,13);mesh(errorGS4);title('GS % Error: 0.4');

subplot(2,9,14);mesh(errorexp8);title('Explicit % Error: 0.8');
subplot(2,9,15);mesh(errorimp8);title('Implicit % Error: 0.8');
subplot(2,9,16);mesh(errorCN8);title('CN % Error: 0.8');
subplot(2,9,17);mesh(errorGS8);title('GS % Error: 0.8');

subplot(2,9,9);mesh(exact4);title('Exact: 0.4');
subplot(2,9,18);mesh(exact8);title('Exact: 0.8');

