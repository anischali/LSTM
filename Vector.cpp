#include "Vector.hpp"
#include <iostream>


template <typename type>
Vector<type> &Vector<type>::filter(type (*filter_func)(type v))
{
    for (int ivec = 0; ivec < this->size; ++ivec)
    {
        this->data[ivec] = filter_func(this->data[ivec]);
    }
    return *this;
}

template <typename type>
Vector<type> Vector<type>::get_filtered(type (*filter_func)(type v))
{
    Vector<type> vec(*this);
    vec.filter(filter_func);
    return vec;
}

template <typename type>
Vector<type>::Vector()
{
    this->size = 0;
}

template <typename type>
void Vector<type>::resize(int size)
{
    this->size = size;
    this->data = (type *)calloc(size, sizeof(type));
}

template <typename type>
Vector<type>::Vector(type *src, int vsize)
{
    this->size = vsize;
    this->data = (type *) calloc(vsize, sizeof(type));
    for (int iv = 0; iv < vsize; ++iv)
    {
        this->data[iv] = src[iv];
    }
}

template <typename type>
Vector<type>::Vector(Vector<type> &vec)
{
    this->size = vec.get_size();
    this->data = (type *)malloc(this->size * sizeof(type));
    type *dptr = vec.get_data();
    for (int icell = 0; icell < this->size; ++icell)
        this->data[icell] = dptr[icell];
}
template <typename type>
void Vector<type>::set_value(int idx, type value)
{
    this->data[idx] = value;
}

template <typename type>
int Vector<type>::get_size() const
{
    return this->size;
}

template <typename type>
type *Vector<type>::get_data() const
{
    return this->data;
}

template <typename type>
Vector<type>::~Vector()
{
    free(this->data);
    this->size = 0;
    this->data = nullptr;
}

template <typename type>
void Vector<type>::print()
{
    for (int icell = 0; icell < this->size; ++icell)
    {
        std::cout << this->data[icell] << " ";
    }
    std::cout << "\n";
}
