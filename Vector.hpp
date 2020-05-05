#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cstdlib>

template <typename type>
class Vector
{
public:
    type* operator[](int idx)
    {
        return &this->data[idx];
    };

    Vector<type> &operator+=(type value)
    {
        for (int icell = 0; icell < this->size; ++icell)
            this->data[icell] += value;
        return *this;
    };

    Vector<type> &operator*=(type value)
    {
        for (int icell = 0; icell < this->size; ++icell)
            this->data[icell] *= value;
        return *this;
    };

    Vector<type> operator+(const Vector<type> &v1)
    {
        int vsize = v1.get_size();
        Vector<type> v3;
        v3.resize(vsize);
        type * vptr = v1.get_data();
        for (int ivec = 0; ivec < vsize; ++ivec)
        {
            v3.set_value(ivec, this->data[ivec] + vptr[ivec]);
        }
        return v3;
    }

    Vector<type> operator*(const Vector<type> &v1)
    {
        int vsize = v1.get_size();
        Vector<type> v3;
        v3.resize(vsize);
        type * vptr = v1.get_data();
        for (int ivec = 0; ivec < vsize; ++ivec)
        {
            v3.set_value(ivec, this->data[ivec] * vptr[ivec]);
        }
        return v3;
    }

    Vector<type>& operator=(const Vector<type> &v)
    {
        int vsize = v.get_size();
        type *vptr = v.get_data();
        for (int idx = 0; idx < vsize; ++idx)
            this->data[idx] = vptr[idx];
        return *this;
    }

    Vector<type> &operator=(type *v)
    {
        for (int idx = 0; idx < this->size; ++idx)
            this->data[idx] = v[idx];
        return *this;

    }

    Vector<type> &filter(type (*filter_func)(type v));
    Vector(Vector<type> &vec);
    Vector(type *src, int vsize);
    Vector();
    Vector<type> get_filtered(type (*filter_func)(type v));
    void resize(int size);
    int get_size() const;
    type *get_data() const;
    void set_value(int idx, type value);
    void print();
    ~Vector();


    private:
        type *data = nullptr;
        int size;
    
};


#endif