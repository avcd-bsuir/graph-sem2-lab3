#ifndef MAT_HPP
#define MAT_HPP

#include <vector>

#include "utils.hpp"

class Mat {
    public:
        std::vector<std::vector<double>> data;
        int m, n;

        Mat(int, int);
        Mat(int, int, std::vector<std::vector<double>>);
        ~Mat();

        double determinant();
        Mat inverse();
};

// // Comparing
// bool operator == (const Mat & first, const Mat & second);
//
// // Adding
// Mat operator + (const Mat & first, const Mat & second);
//
// // Subtracting
// Mat operator - (const Mat & first, const Mat & second);
//
// // Multiplying
// Mat operator * (const Mat & first, const Mat & second);
// Mat operator * (const double & first, const Mat & second);
// Mat operator * (const Mat & second, const float & first);
//
// // Dividing
// Mat operator / (const Mat & first, const Mat & second);

#endif
