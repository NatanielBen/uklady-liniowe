#include "../include/gauss.h"
#include "../include/backsubst.h"
#include "../include/mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	if(res == 1){
		fprintf(stderr,"Blad Macierz osobliwa-dzielenie przez 0.\n");
		freeMatrix(A);
		freeMatrix(b);
		return 1;
	}
	else if(res == 2){
		fprintf(stderr,"Blad nieprawidlowych rozmiarow macierzy.\n");
		freeMatrix(A);
		freeMatrix(b);
		return 2;
	}
	x = createMatrix(b->r, 1);

	if (x != NULL) {
		res = backsubst(x,A,b);
	if (res == 1) {
    printf(stderr, "blad dzielenie przez 0)\n");
    } 
  else if (res == 2) {
    fprintf(stderr, "blad nieprawidlowe rozmiary macierzy\n");
    } 
  else {
    printToScreen(x);
    }
        
    freeMatrix(x);
    } else {
        fprintf(stderr,"błąd nie mogłem utworzyć wektora wynikowego x.\n");
    }
	
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
