A=input('A값 설정');
B=input('B값 설정');
p=input('p값 설정');
tr=input('tr값 설정');
pick=input('I pickup값 설정');
n=input('순시trip 배수 n값 설정');

fid1=fopen('RMSvaia1.out','r');
K=fscanf(fid1,'%f %f %f %f %f',[5,134]);
fclose(fid1);

fid2=fopen('Delay1.out','w');
for i=1:134;
    M=K(4,i)./pick;
    if M<1
        t1=tr./(M.^2-1);
        t2=t1+0.02;
    elseif M>1
        t11=(A./(M.^p-1))+B;
        t3=0.85.*t11;
        t4=1.15.*t11;
    else
        M=n.*M;
    end
    fprintf(fid2,'%f %f %f %f \n',M,t11,t3,t4);
end
fclose(fid2);

fid3=fopen('Delay1.out','r');
L=fscanf(fid2,'%f %f %f %f',[4,134]);
fclose(fid3);

ocr=(A./(M.^p-1))+B;
loglog(L(1,:),L(3,:),'-r')
axis([0.57 0.7 60 200])
xlabel('Ratio(I/Is)')
ylabel('Time [sec]')

        