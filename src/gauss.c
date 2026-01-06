#include "../include/gauss.h"
#include <math.h> // Potrzebne do fabs()

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int eliminate(Matrix *mat, Matrix *b){
	int n = mat->r;

	if(n != mat->c || n != b->r || b->c != 1){
		return 2; 
	}

	for(int k = 0; k < n - 1; k++){
		
		int max_row = k;
		double max_val = fabs(mat->data[k][k]);

		for(int i = k + 1; i < n; i++) {
			if(fabs(mat->data[i][k]) > max_val){
				max_val = fabs(mat->data[i][k]);
				max_row = i;
					}
			}
		if(max_row != k){
				double *temp = mat->data[k];
				mat->data[k] = mat->data[max_row];
				mat->data[max_row] = temp;

				double *temp_b = b->data[k];
				b->data[k] = b->data[max_row];
				b->data[max_row] = temp_b;
		}

		if(fabs(mat->data[k][k]) == 0){
			return 1; 
		}


		double pivot = mat->data[k][k];

		for(int i = k + 1; i < n; i++){
				double wspolczynnik = mat->data[i][k] / pivot;

				for(int j = k; j < n; j++){
						mat->data[i][j] -= wspolczynnik * mat->data[k][j];
				}
				b->data[i][0] -= wspolczynnik * b->data[k][0];
		}
	}
	return 0;
}