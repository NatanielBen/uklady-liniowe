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
				for(int i = k+1;i<n;i++){
			double wspolczynnik = mat->data[i][k] / pivot;

			for(int j = k;j<n;j++){
				mat->data[i][j] -= wspolczynnik *mat->data[k][j];
			}
			b->data[i][0] -= wspolczynnik * b->data[k][0];
		}
	}
		}
		return 0;
	}



