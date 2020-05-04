#include "util.hpp"
#include <iostream>
#include <cmath>
#include "Network.hpp"



using namespace std;

/*void process()
{
    double m[2] = {1.0, 0.0};
    Vector<LSTM> RNN;
    RNN.resize(10);
    Vector<double> c0, h0;
    c0.resize(4);
    h0.resize(4);
    c0 = rand_normal_distribution_vector(4);
    h0 = rand_normal_distribution_vector(4);
    RNN[0]->init(2,4);
    RNN[0]->process_input(m, h0, c0);
    RNN[0]->print_state();
    std::cout << "--------------------------\n";
    for (uint idx = 1; idx < 10; ++idx){
        RNN[idx]->init(2,4);
        m[0] = 1.0 - m[0];
        m[1] = 1.0 - m[1];
        RNN[idx]->process_input(m, RNN[idx-1]->get_h(), RNN[idx-1]->get_c());
        RNN[idx]->print_state();
        std::cout << "--------------------------\n";
    }

}
*/
int main(int argc, char const *argv[])
{
    Vector<double> xin, out;
    xin.resize(2);
    out.resize(1);
    double in[2] = {0.0, 0.0};
    xin = in;
    xin.print();
    out.set_value(0, 0.0);
    Network net(2, 2, 1, 10);
    net.forward(xin, out);
    net.~Network();  
    /*
    double m[2] = {1.0, 0.0};
    LSTM lstm(2, 4);
    Vector<double> c0, h0;
    c0.resize(4);
    h0.resize(4);
    c0 = rand_normal_distribution_vector(4);
    h0 = rand_normal_distribution_vector(4);
    lstm.randInit();
    lstm.print_state();
    lstm.process_input(m, h0, c0);
    lstm.print_state();
    lstm.~LSTM();
    
    */
    return 0;
}

/*
int main(int argc, char const *argv[])
{
    Vector<double> vect;
    vect.resize(2);
    Vector<double> vect2;
    vect2.resize(4);
    vect += 2.0;
    vect2 += 3.0;
    vect.set_value(0, 1.0);
    double v[8] = {2.0, 4.0, 5.0, 6.0, 3.0, 2.0, 1.0, 3.0};
    double v2[16] = {2.0, 4.0, 5.0, 6.0, 3.0, 2.0, 1.0, 3.0, 2.0, 4.0, 5.0, 6.0, 3.0, 2.0, 1.0, 3.0};
    double v3[4] = {2.0, 4.0, 5.0, 6.0};
    Matrix<double> mtrx;
    mtrx.assign(4, 2, v);
    Matrix<double> mtrx2;
    mtrx2.assign(4, 4, v2);
    Vector<double> bv;
    bv.resize(4);
    bv += 5.0;
    std::cout << "-----------------------\n";
    vect.print();
    std::cout << "-----------------------\n";
    vect2.print();
    std::cout << "-----------------------\n";
    bv.print();
    std::cout << "-----------------------\n";
    mtrx.print();
    std::cout << "-----------------------\n";
    mtrx2.print();
    std::cout << "-----------------------\n";
    Vector<double> rvec;
    rvec.resize(4);
    rvec.print();
    std::cout << "-----------------------\n";
    //+ mtrx * vect + bv

    rvec = mtrx2 * vect2 + mtrx * vect + bv;
    std::cout << "-------------i----------\n";
    rvec.print();
    rvec.filter(sigmoid);
    std::cout << "-------------j---------\n";
    rvec.print();
    std::cout << "-----------------------\n";
    vect.print();
    std::cout << "-----------------------\n";
    vect2.print();
    std::cout << "-----------------------\n";
    bv.print();
    std::cout << "-----------------------\n";
    mtrx.print();
    std::cout << "-----------------------\n";
    mtrx2.print();
    std::cout << "-----------------------\n";
    rvec.~Vector();
    vect.~Vector();
    mtrx.~Matrix();
    return 0;
}
*/