#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <fstream>
#include <stdlib.h>


using namespace std;

#define NX 16
#define NY 16
#define N NX*NY
#define NStep 3000000
#define NEqu 2000000

// #define KB 1.38E-23 

double spins[NX+2][NY+2];
double energy, energy2;
double magnetization, magnetization2;
double AveE, AveE2, AveMag, AveMag2, AveMagAbs;
double Cv, Xi;
double InitialT = 0.2;
double FinalT =5.0;
int y, x, i, j, k;
int counter;
double TrialSpin;
double DeltaU;
double KB = 1;
double Eplus, Eminus, beta;

int DetermineSpins(){
	if ( ((double)rand() / (double)RAND_MAX) < 0.5) {
		return -1;
		}
	else {
		return 1;
		}

}

int main (){

	time_t t1 = clock();
	ofstream file; 	
 	ofstream file2;
 	ofstream file3;
 	ofstream file4;
 	ofstream file5;
 	ofstream file6;

 	file.open ("E-T.dat");
 	file2.open ("M-T.dat");
 	file3.open("Cv-T.dat");
 	file4.open("X-T.dat");
 	file5.open("heatI.dat");
 	file6.open("heatF.dat");

	for (  double T = InitialT; T <= FinalT; T = T + 0.1){

 		beta = 1.0/T;
		energy = 0;
		magnetization = 0;
		AveE = 0;
		AveE2 = 0;
		AveMag = 0;
		AveMag2 = 0;
		AveMagAbs = 0;

		for (x = 0; x <= NX+1; x++) {
			for (y = 0; y <= NY+1; y++){
				spins[x][y] = DetermineSpins();
			}					
		}

		for (k = 0; k <= NX+1; k++){
			spins[0][k] = spins[NX][k];
			spins[NX+1][k] = spins[1][k];
			spins[k][0] = spins[k][NY];
			spins[k][NY+1] = spins[k][1]; 
		}

		// if ( T == 0.1) {
		// 	for (x = 0; x <= NX+1; x++) {
		// 		for (y = 0; y <= NY+1; y++){
		// 			cout<<x<<","<<y<<"="<<spins[x][y]<<"	|";
		// 		}					
		// 		cout<<"\n";	
		// 	}
		// }


		if ( T == 5) {
			for (x = 1; x <= NX; x++) {
				for (y = 1; y <= NY; y++ ){
					file5<<spins[x][y]<<"	";
				}					
			file5<<"\n";
			}
		}
		
		counter = 0;
	 	for ( int iNStep = 1; iNStep <= NStep; iNStep++ ){
	 		counter = counter + 1; 
			int i = rand() % NX+1;
			int j = rand() % NY+1;
			TrialSpin = - spins[i][j];
			
			DeltaU = -2.0*(spins[i][j+1] + spins[i][j-1] + spins[i-1][j] + spins[i+1][j]);
			// srand (time(NULL));
			double r = (double)rand()/(double)RAND_MAX;				
			
			if ( r < exp(-1.0*beta*DeltaU)/(exp(-1*beta*DeltaU)+ 1.0) ){
				spins[i][j] = 1.0;
			}
			else{

				spins[i][j] = -1.0;	
			}


			// if (spins[i][j] == -TrialSpin){		
			if (i == 1)		spins[NX+1][j] = spins [1][j];
			if (i == NX)	spins[0][j] = spins[NX][j]; 	
			if (j == 1)		spins[i][NY+1] = spins[i][1];
			if (j == NY)	spins[i][0] = spins[i][NY]; 
			// }

			// if ( T == 4.5) {
			// 	cout<<"\n";
			// 	for (x = 0; x <= NX+1; x++) {
			// 		for (y = 0; y <= NY+1; y++){
			// 			cout<<x<<","<<y<<"="<<spins[x][y]<<"	|";
			// 		}					
			// 		cout<<"\n";	
			// 	}
			// }


			if ( counter >= NEqu ) {
				energy = 0.0;
				magnetization = 0.0;
				for (x = 1; x <= NX; x++){
					// #pragma omp parallel for
				  	for ( y = 1; y <= NY ; y++){
				  		// #pragma omp atomic
						energy = energy - spins[x][y] * (spins[x][y+1] + spins[x][y-1] + spins[x-1][y] + spins[x+1][y]);
				    	magnetization = magnetization + spins[x][y];
				 
					} 
				}

				energy = energy/(N*2.0);
				AveE = AveE + energy;
				AveE2 = AveE2 + energy*energy;

				magnetization = magnetization/N;
				AveMag = AveMag + magnetization;
				AveMagAbs = AveMagAbs + abs(magnetization);
				AveMag2 = AveMag2 + magnetization*magnetization;
			}
		
		}


			AveE = AveE/(NStep-NEqu);
			AveE2 = AveE2/(NStep-NEqu);
			AveMag = AveMag/((NStep-NEqu));
			AveMag2 = AveMag2/((NStep-NEqu));
			AveMagAbs = AveMagAbs/((NStep-NEqu));

			Cv = N*(AveE2 - pow(AveE,2))/(T*T);
			Xi = (AveMag2 - AveMagAbs*AveMagAbs)/(N*T);
			file<<AveE<<"	"<<T<<"\n";
			file2<<AveMag/(N)<<"	"<<T<<"\n";
			file3<<Cv<<"	"<<T<<"\n";
			file4<<Xi<<"	"<<T<<"\n";
	
	}

	for (x = 1; x <= NX; x++) {
		for (y = 1; y <= NY; y++ ){
			file6<<spins[x][y]<<"	";
		}					
		file6<<"\n";
	}

	time_t t2 = clock();
    printf("Time: %f\n",(t2-t1)/(float)CLOCKS_PER_SEC);
	return 0;
}



