#include "LSTM.hpp"

void LSTM::randInit()
{
    this->W_f = rand_normal_distribution_matrix(this->in_size, this->h_size);
    this->W_g = rand_normal_distribution_matrix(this->in_size, this->h_size);
    this->W_i = rand_normal_distribution_matrix(this->in_size, this->h_size);
    this->W_o = rand_normal_distribution_matrix(this->in_size, this->h_size);

    this->U_f = rand_normal_distribution_matrix(this->h_size, this->h_size);
    this->U_g = rand_normal_distribution_matrix(this->h_size, this->h_size);
    this->U_i = rand_normal_distribution_matrix(this->h_size, this->h_size);
    this->U_o = rand_normal_distribution_matrix(this->h_size, this->h_size);
}

void LSTM::print_state()
{
    std::cout << "Forget Gate\n"; 
    this->f.print();
    std::cout << "Input Gate\n"; 
    this->i.print();
    std::cout << "Output Gate\n"; 
    this->o.print();
    std::cout << "G Gate\n"; 
    this->g.print();
    std::cout << "Cell State\n"; 
    this->c.print();
    std::cout << "Hidden State\n"; 
    this->h.print();
}
void LSTM::process_input(double *input, Vector<double> h0, Vector<double> c0)
{

}


void LSTM::process_input(Vector<double> input, Vector<double> h0, Vector<double> c0)
{
    this->x = input;
    this->f = (this->W_f * this->x + this->U_f * h0 + this->b_f).filter(sigmoid);
    this->i = (this->W_i * this->x + this->U_i * h0 + this->b_i).filter(sigmoid);
    this->o = (this->W_o * this->x + this->U_o * h0 + this->b_o).filter(sigmoid);
    this->g = (this->W_g * this->x + this->U_g * h0 + this->b_g).filter(tanh);
    this->c = (this->f * c0 + this->i * this->g);
    this->h = (this->o * this->c.get_filtered(tanh));
}



void LSTM::init(int input_size, int hidden_size)
{
    int n = this->in_size = input_size;
    int m = this->h_size = hidden_size;

    this->W_i.resize(n, m);
    this->W_f.resize(n, m);
    this->W_o.resize(n, m);
    this->W_g.resize(n, m);

    this->U_i.resize(m, m);
    this->U_f.resize(m, m);
    this->U_o.resize(m, m);
    this->U_g.resize(m, m);

    this->b_f.resize(m);
    this->b_i.resize(m);
    this->b_o.resize(m);
    this->b_g.resize(m);

    this->x.resize(n);
    this->f.resize(m);
    this->i.resize(m);
    this->o.resize(m);
    this->g.resize(m);
    this->c.resize(m);
    this->h.resize(m);

    this->randInit();
}

LSTM::~LSTM()
{
    //this->in_size = 0;
    //this->h_size = 0;

    this->W_i.~Matrix();
    this->W_f.~Matrix();
    this->W_o.~Matrix();
    this->W_g.~Matrix();

    this->U_i.~Matrix();
    this->U_f.~Matrix();
    this->U_o.~Matrix();
    this->U_g.~Matrix();

    this->b_i.~Vector();
    this->b_f.~Vector();
    this->b_o.~Vector();
    this->b_g.~Vector();

    this->x.~Vector();
    this->i.~Vector();
    this->f.~Vector();
    this->o.~Vector();
    this->g.~Vector();
    this->c.~Vector();
    this->h.~Vector();
}


Vector<double>& LSTM::get_h()
{
    return this->h;
}

Vector<double>& LSTM::get_c()
{
    return this->c;
}
