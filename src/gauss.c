#include "../include/gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;

	for(int k = 0;k < mat->r -1;k++){
		double pivot = mat->data[k][k];
	if(pivot == 0){
		return 1;
	}
	else{

		}
		return 0;
	}



