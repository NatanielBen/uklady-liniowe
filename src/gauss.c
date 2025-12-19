#include "../include/gauss.h"

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
	
	double max = mat->data[0][0]; 
	int max_row = 0;

	int i = 0; 
	while(i < n) {
		if(mat->data[i][0] > max){
				max = mat->data[i][0];
				max_row = i;
		}
		i++; 
	}

	if(max_row != 0){
		int j = 0; 
		while(j < n) {
				double temp = mat->data[0][j];
				mat->data[0][j] = mat->data[max_row][j];
				mat->data[max_row][j] = temp;
				j++; 
		}
		
		double temp_b = b->data[0][0];
		b->data[0][0] = b->data[max_row][0];
		b->data[max_row][0] = temp_b;
	}

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



