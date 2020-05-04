#include "util.hpp"
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>


double sigmoid(double x)
{
    return (1.0 / (1.0 + exp(-x)));
}

double get_norm(int *vect, int vsize)
{
    double norm = 0.0;
    for (int ivec = 0; ivec < vsize; ++ivec)
    {
        norm += (vect[ivec] * vect[ivec]);
    }
    return sqrt(norm);
}

Vector<double> normalize(int *vect, int vsize)
{
    Vector<double> nvec;
    nvec.resize(vsize);
    double norm = get_norm(vect, vsize);
    for (int ivec = 0; ivec < vsize; ++ivec)
    {
        nvec.set_value(ivec, vect[ivec] / norm);
    }
    return nvec;
}

Vector<double> rand_normal_distribution_vector(int size)
{
    srand(time(nullptr));
    std::default_random_engine generator;
    std::normal_distribution<double> distribution((double)size / 2.0, 2.0);
    const int nrolls = rand() % 10000; // number of experiments
    
    int *p = (int *) calloc(size, sizeof *p);

    for (int i = 0; i < nrolls; ++i)
    {
        double number = distribution(generator);
        if ((number >= 0.0) && (number < (double ) size))
            ++p[int(number)];
    }

    Vector<double> vect;
    vect.resize(size); 
    vect = normalize(p, size);
    free(p);
    return vect;
}


Matrix<double> rand_normal_distribution_matrix(int h, int w)
{
    int size = h*w;
    Vector <double> vect;
    vect.resize(size);
    vect = rand_normal_distribution_vector(size);
    double *m = vect.get_data();
    Matrix<double> mtrx;
    mtrx.assign(h, w, m);
    return mtrx;
}


double sum_exp(Vector<double> vect)
{
    double _sum = 0.0;
    int _size = vect.get_size();
    double *_vptr = vect.get_data();
    for (int iv = 0; iv < _size; ++iv)
    {
        _sum += (exp(_vptr[iv]));
    }    
    return _sum;
}


Vector<double> softmax(Vector<double> vect)
{
    double _se = sum_exp(vect);
    int _size = vect.get_size();
    double *_vptr = vect.get_data();
    Vector<double> _rvec;
    _rvec.resize(_size);
    for (int iv = 0; iv < _size; ++iv)
    {
        _rvec.set_value(iv, exp(_vptr[iv] / (double) _se));
    }
    return _rvec;
}