#include "util.hpp"
#include <iostream>
#include <cmath>
#include "Network.hpp"
#include "LSTM.hpp"
#include "Matrix.hpp"

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
    double Wg[2] = {0.45, 0.25};
    double Wi[2] = {0.95,0.8};
    double Wf[2] = {0.7, 0.45};
    double Wo[2] = {0.9,0.4};
    double Ug[1] = {0.15};
    double Ui[1] = {0.8};
    double Uf[1] = {0.1};
    double Uo[1] = {0.25};

    double bg[1] = {0.2};
    double bi[1] = {0.65};
    double bf[1] = {0.15};
    double bo[1] = {0.1};
    
    double x0[2] = {1.0,2.0};
    double x1[2] = {0.5,3.0};
    double tmp[1] = {0.0}; 

    Vector<double> h0(tmp, 1);
    Vector<double> c0(tmp, 1);
    

    LSTM cell;
    cell.init(2,1);
    cell.b_f = bf;
    cell.b_g = bg;
    cell.b_i = bi;
    cell.b_o = bo;


    cell.W_i.set(Wf);
    cell.W_g.set(Wg);
    cell.W_i.set(Wi);
    cell.W_o.set(Wo);

    cell.U_i.set(Uf);
    cell.U_g.set(Ug);
    cell.U_i.set(Ui);
    cell.U_o.set(Uo);
    Vector<double>xp(x0, 1);
    cell.process_input(xp, h0, c0);

    cell.print_state();

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