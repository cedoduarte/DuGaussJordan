#include "DuGaussJordan.h"

DuGaussJordan::DuGaussJordan()
{
}

QVector<double> DuGaussJordan::solve(const DuMatrix &matrix, int var)
{
    DuMatrix m = matrix;
    for (int k = 0; k < var; k++) {
        for (int i = 0; i <= var; i++) {
            const double h = m[i][k];
            for (int w = 0; w <= var; w++) {
                if (i != k) {
                    m[i][w] = (m[k][k] * m[i][w]) - (h * m[k][w]);
                }
            }
        }
    }
    QVector<double> results;
    for (int i = 0; i < var; i++) {
        results << m[i][var] / m[i][i];
    }
    return results;
}
