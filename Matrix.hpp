#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstdlib>
#include <iostream>
#include "Vector.hpp"

template <typename type>

class Matrix
{
private:
    type *data = nullptr;
    int h = 0, w = 0;

public:
    type operator[](int i)
    {
        return this->data[i];
    };

    void operator+=(Matrix<type> m)
    {
        int size = this->h * this->w;
        type *ptr = m.get_data();
        for (int idx = 0; idx < h; ++idx)
        {
            this->data[idx] += ptr[idx];
        }
    };

    void operator+=(type value)
    {
        int size = this->h * this->w;
        for (int idx = 0; idx < h; ++idx)
        {
            this->data[idx] += value;
        }
    };

    void operator*=(type value)
    {
        int size = this->h * this->w;
        for (int idx = 0; idx < h; ++idx)
        {
            this->data[idx] *= value;
        }
    };

    void operator*=(Matrix<type> m)
    {
        int size = this->h * this->w;
        type *ptr = m.get_data();
        for (int idx = 0; idx < h; ++idx)
        {
            this->data[idx] *= ptr[idx];
        }
    };


    Vector<type> operator*(const Vector<type> &v)
    {
        int svec = v.get_size();
        int H = this->h, W = this->w;
        type *vptr = v.get_data();
        type *mptr = this->data;
        Vector<type> rvec;
        rvec.resize(H);
        if (H != svec)
        {
            perror("The width of the matrix is diffirent from the size of the vector");
        }
        double r = 0.0;
        for (int ih = 0; ih < H; ++ih)
        {
            r = 0.0;
            for (int iw = 0; iw < svec; ++iw)
                r += (vptr[iw] * mptr[ih * W + iw]);
            rvec.set_value(ih, r);
        }
        return rvec;
    }

    Matrix<type>& operator=(const Matrix<type> &m)
    {
        int msize = m.length();
        type *mptr = m.get_data();
        for (int idx = 0; idx < msize; ++idx)
            this->data[idx] = mptr[idx];
        return *this;
    }

    Matrix(const Matrix<type> &mtrx);
    Matrix(type **mtrx, int h, int w);
    Matrix();
    void resize(int h, int w);
    void assign(int h, int w, const type *values);
    int length() const;
    int rows_size() const;
    int cols_size() const;
    type *get_data() const;
    void print();
    ~Matrix();
};


#endif