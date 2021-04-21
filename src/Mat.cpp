#include "Mat.hpp"

Mat::Mat(int m, int n) : m(m), n(n) {
    this->data.resize(m);
    for (int i = 0; i < m; i++)
        this->data[i].resize(n);
}

Mat::Mat(int m, int n, std::vector<std::vector<double>> data) : m(m), n(n) {
    data.resize(m);
    for (int i = 0; i < m; i++)
        data[i].resize(n);
    this->data = data;
}

Mat::~Mat() {
}

// double Mat::determinant() {
//     void getMatrixWithoutRowAndCol(int size, int row, int col, std::vector<std::vector<double>> matrix)
//     {
//         int offsetRow = 0; //Смещение индекса строки в матрице
//         int offsetCol = 0; //Смещение индекса столбца в матрице
//         for (int i = 0; i < size - 1; i++)
//         {
//             //Пропустить row-ую строку
//             if (i == row)
//             {
//                 offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
//             }
//
//             offsetCol = 0; //Обнулить смещение столбца
//             for (int j = 0; j < m - 1; j++)
//             {
//                 //Пропустить col-ый столбец
//                 if (j == col)
//                 {
//                     offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
//                 }
//
//                 matrix[i][j] = this->data[i + offsetRow][j + offsetCol];
//             }
//         }
//     }
//     auto determinant = [&](Mat matrix) {
//         if (matrix.m != matrix.n)
//             throwError("ComputationError", "Determinant of non-square matrix can't be found");
//
//     };
//     double matrixDet
//     {
//         double m = this->data.size();
//         double n = this->data[0].size();
//         if (m != n)
//             return -6969696969;
//         else
//         {
//             int det = 0;
//             int degree = 1; // (-1)^(1+j) из формулы определителя
//             //Условие выхода из рекурсии
//             switch (m)
//             {
//             case 1:
//                 return this->data[0][0];
//                 break;
//
//             case 2:
//                 return this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0];
//                 break;
//
//             default:
//                 std::vector<std::vector<double>> matrix = data;
//                 matrix.resize(m - 1);
//                 for (int i = 0; i < m; i++)
//                     this->data[i].resize(n - 1);
//
//                 for (int j = 0; j < m; j++)
//                 {
//                     getMatrixWithoutRowAndCol(m, 0, j, matrix);
//                 }
//                 det = det + (degree * matrix[0][j] * matrixDet(matrix, m - 1));
//                 break;
//             }
//         }
//         return det;
//     }
// }


/*

    //Возвращает матрицу matrix без row-ой строки и col-того столбца, результат в newMatrix
void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col, int **newMatrix) {
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    for(int i = 0; i < size-1; i++) {
        //Пропустить row-ую строку
        if(i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }

        offsetCol = 0; //Обнулить смещение столбца
        for(int j = 0; j < size-1; j++) {
            //Пропустить col-ый столбец
            if(j == col) {
                offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
            }

            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}


    //Вычисление определителя матрицы разложение по первой строке
    int matrixDet(int **matrix, int size) {
    int det = 0;
    int degree = 1; // (-1)^(1+j) из формулы определителя

    //Условие выхода из рекурсии
    if(size == 1) {
        return matrix[0][0];
    }
    //Условие выхода из рекурсии
    else if(size == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }
    else {
        //Матрица без строки и столбца
        int **newMatrix = new int*[size-1];
        for(int i = 0; i < size-1; i++) {
            newMatrix[i] = new int[size-1];
        }

        //Раскладываем по 0-ой строке, цикл бежит по столбцам
        for(int j = 0; j < size; j++) {
            //Удалить из матрицы i-ю строку и j-ый столбец
            //Результат в newMatrix
            getMatrixWithoutRowAndCol(matrix, size, 0, j, newMatrix);

            //Рекурсивный вызов
            //По формуле: сумма по j, (-1)^(1+j) * matrix[0][j] * minor_j (это и есть сумма из формулы)
            //где minor_j - дополнительный минор элемента matrix[0][j]
            // (напомню, что минор это определитель матрицы без 0-ой строки и j-го столбца)
            det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size-1));
            //"Накручиваем" степень множителя
            degree = -degree;
        }

        //Чистим память на каждом шаге рекурсии(важно!)
        for(int i = 0; i < size-1; i++) {
            delete [] newMatrix[i];
        }
        delete [] newMatrix;
    }

    return det;
}
        */

// Mat Mat::inverse() {
// }

// /*
//  * Comparing
//  */
//
// bool operator==(const Mat &first, const Mat &second) {
//     return first.data == second.data;
// }
//
// /*
//  * Adding
//  */
//
// Mat operator +(const Mat &first, const Mat &second) {
// }
//
// Mat operator +=(Mat &first, const Mat &second) {
// }
//
// /*
//  * Subtracting
//  */
//
// Mat operator-(const Mat &first, const Mat &second) {
// }
//
// Mat operator-=(Mat &first, const Mat &second) {
// }
//
// /*
//  * Multiplying
//  */
//
// Mat operator*(const Mat &first, const Mat &second) {
// }
//
// Mat operator*=(Mat &first, const Mat &second) {
// }
//
// Mat operator*(const Mat &first, const double second) {
// }
//
// Mat operator*=(Mat &first, const double second) {
// }
//
// Mat operator*(const double second, const Mat &first) {
// }
//
// /*
//  * Dividing
//  */
//
// Mat operator/(const Mat &first, const double second) {
// }
//
// Mat operator/=(Mat &first, const double second) {
// }
