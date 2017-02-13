PI=3.1415926;							
Fs=720;
DN=73;
N=12;									
p=1.4142;
R=2*PI/N;
DELTA_T=0.0013888889;	

fid1 = fopen('PMU129R5D80KG.txt','rt');
D=fscanf(fid1, '%lf %lf %lf %lf ',[4,145]);
fclose(fid1);

fid2 = fopen('RMSvaia2.out','w');
 for i=12:145;
        realia(i) = (2/(N)) * ...
              ( (D(4,i) - D(4,i-6)) + ...
            0.866025404 * (D(4,i-11) - D(4,i-7) - D(4,i-5) + D(4,i-1)) + ...
			  0.5 * (D(4,i-10) - D(4,i-8) - D(4,i-4) + D(4,i-2)) );
		imagia(i) = (2/(N)) * ...
		      ( (D(4,i-9)- D(4,i-3)) + ...
			0.866025404 * (D(4,i-10) + D(4,i-8) - D(4,i-4) - D(4,i-2)) + ...
			  0.5 * (D(4,i-11) + D(4,i-7) - D(4,i-5) - D(4,i-1)) ); 
		sqriia(i) = sqrt( (realia(i)*realia(i)) + (imagia(i)*imagia(i)) ) * (sqrt(2) / 2);


		sqriiasqrt(i) = (D(3,i)*D(3,i)) + (D(3,i-1)*D(3,i-1)) + (D(3,i-2)*D(3,i-2)) + ...
						(D(3,i-3)*D(3,i-3)) + (D(3,i-4)*D(3,i-4)) + (D(3,i-5)*D(3,i-5)) + ...
						(D(3,i-6)*D(3,i-6)) + (D(3,i-7)*D(3,i-7)) + (D(3,i-8)*D(3,i-8)) + ...
						(D(3,i-9)*D(3,i-9)) + (D(3,i-10)*D(3,i-10)) + (D(3,i-11)*D(3,i-11)) ;

        
        sqriiaavv(i) = sqriiasqrt(i) / N;

		
		sqriiarms(i) = sqrt(sqriiaavv(i));

		
		fprintf(fid2, '%d %f %f %f %f \n',i,realia(i),imagia(i),sqriia(i),sqriiarms(i));
                end
	fclose(fid2);
    
