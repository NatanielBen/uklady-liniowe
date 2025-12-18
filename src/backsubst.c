#include "../include/backsubst.h"
#include <stdio.h>

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int r = mat->r;
    int c = mat->c;

	//Sprawdzenie poprawności rozmiarów macierzy
    if (r != c || r != b->r || r != x->r) {
        return 2;
    }

    //Wsteczne podstawienie
    for (int i = r - 1; i >= 0; i--) {
        
        //Sprawdzenie dzielenia przez 0
        if (mat->data[i][i] == 0.0) {
            return 1;
        }

        double sum = 0.0;

        // Obliczenie sumy dla znanych już wartości x[j]
        for (int j = i + 1; j < c; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }

        // Obliczenie wartości x[i]
        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }

    return 0;
}