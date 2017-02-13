% OCR_curve.m
a=0.0515
b=0.1140
p=0.02000
tr=4.85
fid1=fopen('reset.out','w');
for m=0:0.01:0.99;
    t2=tr/abs(m.^2-1);
    cb3=1.15.*t2;
    cb4=0.85.*t2;
          fprintf(fid1,'%f %f %f %f \n',m,t2,cb3,cb4);
end
fclose(fid1);

fid2=fopen('trip.out','w');
for n=1.01:0.01:500;
    t1=(a./(n.^p-1))+b;
    cb1=1.15.*t1;
    cb2=0.85.*t1;
    fprintf(fid1,'%f %f %f %f \n',n,t1,cb1,cb2);
end
fclose(fid2);

fid3=fopen('reset.out','r');
R=fscanf(fid3,'%f %f %f %f',[4,100]);
fclose(fid3);

fid4=fopen('trip.out','r');
T=fscanf(fid4,'%f %f %f %f',[4,49900]);
fclose(fid4);

loglog(R(1,:),R(3,:),'-r',R(1,:),R(2,:),'-g',R(1,:),R(4,:),'-b',T(1,:),T(3,:),'-r',T(1,:),T(2,:),'-g',T(1,:),T(4,:),'-b');
axis([0.01 500 0.1 100]);
xlabel('Multiples of pickup');
ylabel('Seconds');
title('  Reset Characteristics                 Trip Characteristics','fontsize',15);
legend('1.15t(I)','t(I)','0.85t(I)','1.15t(I)','t(I)','0.85t(I)');