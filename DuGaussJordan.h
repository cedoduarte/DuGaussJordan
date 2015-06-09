#ifndef DUGAUSSJORDAN_H
#define DUGAUSSJORDAN_H

#include <QVector>

using DuMatrix = QVector<QVector<double>>;

class DuGaussJordan
{
public:
    DuGaussJordan();
    QVector<double> solve(const DuMatrix &matrix, int var);
};

#endif // DUGAUSSJORDAN_H
