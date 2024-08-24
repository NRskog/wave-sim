#ifndef wavefunction_h
#define wavefunction_h


#include <vector>
#include <complex>
#include <cmath> 

using Complex = std::complex<double>;



class Schrodinger {
public:
    Schrodinger(int grid_size, double planck, double mass, double dx, double dt);

    void initialize_wavefunc(); //double init_value
    Complex approx_second_order(int n) const;
    void update();
    


    std::vector<Complex> psi;           //sparar vågfunktionens tidigare värden
    std::vector<double> potential;       //sparar potentialens tidigare värden

    double get_real(int n) const;
    double get_imag(int n) const;

private:
    int grid_size;
    double planck;
    double mass;
    double dx;
    double dt;


};



#endif