#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>


using namespace std;

#define NX 10
#define NY 10
#define NZ 10

#define N NX*NY*NZ
#define NStep 3000
#define NEqu 2000

// #define KB 1.38E-23 

int spins[NX+2][NY+2][NZ+2];
double energy, energy2, T;
double magnetization, magnetization2;
double AveE, AveE2, AveMag, AveMag2,AveMagAbs;
double Cv, Xi;
double InitialT = 0.2;
double FinalT =5.0;
int y, x, z ,i, j, k, l,kp, zk;
int counter;
int cellCounter;
int TrialSpin;
double DeltaU;
double KB = 1;
double Eplus, Eminus, beta;
int SavedCell[(NX+2)*(NY+2)*(NZ+2)];
typedef int spinArray[NX+2][NY+2][NZ+2];


int DetermineSpins(){
	if ( ((double)rand() / (double)RAND_MAX) < 0.5) {
		return -1;
		}
	else {
		return 1;
		}

}


int ClusterGrowth(int pCellCounter,int pSavedCell[] ,int iCellValue, int m, int n, int o, int pSpins[NX+2][NY+2][NZ+2]){
	// if (m == 0 || n == 0) return 0;
	// if (m == NX + 2 || n == NX + 2 ) return 0;
	int condition, p,q;
	int spinValue = pSpins[m][n][o];
	q = 0;
	p = 0;
	condition = 0;
	double addProb = (double)rand()/(double)RAND_MAX;

	if (spinValue == iCellValue && addProb < (1.0 - exp(-2.0/T) ) ) { 

		while ( condition == 0 ) {
			
			if (pSavedCell[p] == o*NX*NY + m*NX + n) {
				condition = 1;
				q = 1;
			} 

			if (pSavedCell[p] == 0) {condition = 1;
			// cout<<pSavedCell[p]<<"	"<<p<<"	"<<iCellValue<<endl;
			}
			p++;
		
		}

		if ( q == 0 ) {
			pSpins[m][n][o] = -pSpins[m][n][o];
			pSavedCell[pCellCounter] = o*NX*NY + m*NX + n;
			// pSpins[8][7] = 2;
			// cout<<pSavedCell[2]<<"	"<<pSpins[8][7]<<"	"<<pCellCounter<<endl;
			pCellCounter = pCellCounter + 1;	



			//Boundry Condition
			if (m == 1)		spins[NX+1][n][o] = spins [1][n][o];
			if (m == NX)	spins[0][n][o] = spins[NX][n][o]; 	
			if (n == 1)		spins[m][NY+1][o] = spins[m][1][o];
			if (n == NY)	spins[m][0][o] = spins[m][NY][o]; 
			if (o == 1) 	spins[m][n][NZ+1] = spins[m][n][1];
			if (o == NZ) 	spins[m][n][0] = spins[m][n][NZ];
		
		if (o == NZ){
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n, 0,pSpins);
		}	
		else{
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n, o+1,pSpins);
		}


		if (o == 1){
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n, NZ+1 , pSpins);
		}	
		else{
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n, o-1 , pSpins);
		}


		if (n == NY){
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, 0, o,pSpins);
		}	
		else{
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n+1, o,pSpins);
		}

		
		if (n == 1){
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, NY+1, o,pSpins);
		}
		
		else{	
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m, n-1, o,pSpins);
		}
		

		if ( m == 1) {  
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, NX+1, n, o,pSpins);
		}
		else{
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m-1, n, o,pSpins);
		}


		if (m == NX){
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, 0, n, o,pSpins);
		}
		else{
			ClusterGrowth(pCellCounter,pSavedCell, iCellValue, m+1, n, o,pSpins);
		}
	}
}
	return 0;			
}

int main (){

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

 	cellCounter = 0;
	for ( T = InitialT; T <= FinalT; T = T + 0.1){

 		beta = 1.0/T;
		energy = 0;
		magnetization = 0;
		AveE = 0;
		AveE2 = 0;
		AveMag = 0;
		AveMag2 = 0;

		for (x = 0; x <= NX+1; x++) {
			for (y = 0; y <= NY+1; y++){
				for (z = 0; z <= NZ+1; z++){
					spins[x][y][z] = DetermineSpins();
				}
			}					
		}

		for (k = 0; k <= NX+1; k++){
			for (kp = 0; kp <= NX+1; kp++){
				spins[0][k][kp] = spins[NX][k][kp];
				spins[NX+1][k][kp] = spins[1][k][kp];
				spins[k][0][kp] = spins[k][NY][kp];
				spins[k][NY+1][kp] = spins[k][1][kp]; 

				spins[k][kp][0] = spins[k][kp][NZ];
				spins[k][kp][NZ+1] = spins[k][kp][1];
			}
		}

		// if ( T == 0.1) {
		// 	for (x = 0; x <= NX+1; x++) {
		// 		for (y = 0; y <= NY+1; y++){
		// 			cout<<x<<","<<y<<"="<<spins[x][y]<<"	|";
		// 		}					
		// 		cout<<"\n";	
		// 	}
		// }


		// if ( T == 5) {
		// 	for (x = 1; x <= NX; x++) {
		// 		for (y = 1; y <= NY; y++ ){
		// 			file5<<spins[x][y]<<"	";
		// 		}					
		// 	file5<<"\n";
		// 	}
		// }
		
		counter = 0;
	 	for ( int iNStep = 1; iNStep <= NStep; iNStep++ ){
	 		counter = counter + 1; 
			int i = rand() % NX+1;
			int j = rand() % NY+1;
			int l = rand() % NZ+1;


			//Boundry Condition
			if (i == 1)		spins[NX+1][j][l] = spins [1][j][l];
			if (i == NX)	spins[0][j][l] = spins[NX][j][l]; 	
			if (j == 1)		spins[i][NY+1][l] = spins[i][1][l];
			if (j == NY)	spins[i][0][l] = spins[i][NY][l]; 

			if (l == 1) 	spins[i][j][NZ+1] = spins[i][j][1];
			if (l == NZ) 	spins[i][j][0] = spins[i][j][NZ];
		
		
			for (int kk = 0; kk <= 2*(NX+2)*(NY+2); kk++){
			SavedCell[kk] = 0;
			}
			// cout<<"hi"<<endl;
			int iCellValue = spins[i][j][l];
			ClusterGrowth(cellCounter, SavedCell, iCellValue, i, j, l, spins);
			// cout<<SavedCell[3]<<"	"<<cellCounter<<endl;
			cellCounter = 0;

			// cout<<"pSpins[][]"<<pSpins[9][2]<<endl;

			// for ( int ik = 0; ik <= 10; ik++ ){
			// 	for (int jk = 0; jk <= 10; jk++) {
			// 		spins[ik][jk] = pSpins[ik][jk];
			// 	}
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
				  	for ( y = 1; y <= NY ; y++){
				  		for (z = 1; z <= NZ ; z++ ){
							energy = energy - spins[x][y][z] * (spins[x][y+1][z] + spins[x][y-1][z] + spins[x-1][y][z] + spins[x+1][y][z]+
							spins[x+1][y][z+1] +  spins[x+1][y][z-1]);
					    	magnetization = magnetization + spins[x][y][z];
				 		}
					} 
				}

				energy = energy/(N*4.0);
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
			file2<<AveMag/(N*T)<<"	"<<T<<"\n";
			file3<<Cv<<"	"<<T<<"\n";
			file4<<Xi<<"	"<<T<<"\n";
	

	}

	for (x = 1; x <= NX; x++) {
		for (y = 1; y <= NY; y++ ){
			file6<<spins[x][y]<<"	";
		}					
		file6<<"\n";
	}
	return 0;
}



