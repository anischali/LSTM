#ifndef LSTM_HPP
#define LSTM_HPP
#include <cmath>
#include "Vector"
#include "Matrix"
#include "util.hpp"



class LSTM
{
private:
    int in_size = 0, h_size = 0;
    Vector<double> f, i, o, g, c, h,
                   b_i, b_f, b_o, b_g;
    Matrix<double> W_i, W_f, W_o, W_g,
        U_i, U_f, U_o, U_g;

public:
    void init(int input_size, int hidden_size);
    ~LSTM();
    void process_input(double *input, Vector<double> h0, Vector<double> c0);
    void process_input(Vector<double> input, Vector<double> h0, Vector<double> c0);
    void print_state();
    void set_dimesions(int input_size, int hidden_size);
    void randInit();
    Vector<double>& get_h();
    Vector<double>& get_c();
};

#include "LSTM.cpp"

#endif