#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "LSTM.hpp"

class Output
{
private:
    Vector<double> z, bz;
    Matrix<double> Whz;

public:
    void init(int _hsize, int _osize)
    {
        z.resize(_osize);
        bz.resize(_hsize);
        Whz.resize(_hsize, _osize);
        bz = rand_normal_distribution_vector(_hsize);
        Whz = rand_normal_distribution_matrix(_hsize, _osize);
    };
    void process(Vector<double> &h)
    {
        z = Whz * h + bz;
        z = softmax(z);
    };

    void print_outs()
    {
        z.print();
    }

    ~Output()
    {
        z.~Vector();
        bz.~Vector();
        Whz.~Matrix();
    };
};

class Network
{
private:
    int isize_ = 0, hsize_ = 0, osize_ = 0, nunites_ = 0;
    Vector<LSTM> units;
    Output outs;

public:
    Network(int _isize, int _hsize, int _osize, int _nunites);
    void forward(Vector<double> input, Vector<double> out);

    ~Network();
};

void Network::forward(Vector<double> input, Vector<double> out)
{
    Vector<double> h0, c0;
    h0.resize(this->hsize_);
    c0.resize(this->hsize_); 
    h0 = rand_normal_distribution_vector(this->hsize_);
    c0 = rand_normal_distribution_vector(this->hsize_);
    this->units[0]->process_input(input, h0, c0);
    for (int iunit = 1; iunit < this->nunites_; ++iunit)
    {
        h0 = this->units[iunit - 1]->get_h();
        c0 = this->units[iunit - 1]->get_c();
        this->units[iunit]->process_input(input, h0, c0);
    }
    this->outs.process(this->units[this->nunites_ - 1]->get_h());
    this->outs.print_outs();
    out.print();
}

Network::Network(int _isize, int _hsize, int _osize, int _nunites)
{
    this->isize_ = _isize;
    this->hsize_ = _hsize;
    this->osize_ = _osize;
    this->nunites_ = _nunites;
    this->units.resize(_nunites);
    for (int iunit = 0; iunit < _nunites; ++iunit)
    {
        this->units[iunit]->init(_isize, _hsize);
    }
    this->outs.init(_hsize, _osize);
}

Network::~Network()
{
    for (int iunit = 0; iunit < this->nunites_; iunit++)
    {
        if (iunit == this->nunites_) break;
        printf("%d \n", iunit);
        if (units[iunit] != nullptr)
        {
            this->units[iunit]->~LSTM();
        }
    }
    this->units.~Vector();
    this->outs.~Output();
}

#endif
