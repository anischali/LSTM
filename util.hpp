#ifndef UTIL_HPP
#define UTIL_HPP
#include "Vector"
#include "Matrix"

double sigmoid(double x);
Vector<double> rand_normal_distribution_vector(int size);
Matrix<double> rand_normal_distribution_matrix(int h, int w);
Vector<double> softmax(Vector<double> vect);

#endif