#include "Matrix.hpp"


using namespace std;


template <typename type>
Matrix<type>::Matrix()
{
    this->h = 0;
    this->w = 0;
}


template <typename type>
void Matrix<type>::resize(int h_, int w_)
{
    this->h = h_;
    this->w = w_;
    this->data = (type *)calloc(h_ * w_, sizeof(*this->data));
}

template <typename type>
void Matrix<type>::assign(int h_, int w_, const type *values)
{
    this->h = h_;
    this->w = w_;
    int size_ = h_ * w_;
    this->data = (type *)malloc(size_ * sizeof(*this->data));
    for (int idx = 0; idx < size_; ++idx)
    {
        this->data[idx] = values[idx];
    }
}

template <typename type>
Matrix<type>::Matrix(const Matrix<type> &mtrx)
{
    this->h = mtrx.rows_size();
    this->w = mtrx.cols_size();
    int size = this->h * this->w;
    this->data = (type *)calloc(size, sizeof(*this->data));
    type *tdata = mtrx.get_data();
    for (int idx = 0; idx < size; ++idx)
    {
        this->data[idx] = tdata[idx];
    }
}
template <typename type>
Matrix<type>::Matrix(type **mtrx, int h, int w)
{
    
}

template <typename type>
Matrix<type>::~Matrix()
{
    free(this->data);
    this->data = nullptr;
    this->h = 0;
    this->w = 0;
}

template <typename type>
int Matrix<type>::length() const
{
    return (this->h * this->w);
}

template <typename type>
int Matrix<type>::rows_size() const
{
    return this->h;
}

template <typename type>
int Matrix<type>::cols_size() const
{
    return this->w;
}

template <typename type>
type *Matrix<type>::get_data() const
{
    return this->data;
}

template <typename type>
void Matrix<type>::print()
{
    for (int ih = 0; ih < this->h; ++ih)
    {
        for (int iw = 0; iw < this->w; ++iw)
            std::cout << this->data[ih * this->w + iw] << " ";
        std::cout << "\n";
    }
}