#include "wavefunction.h"



Schrodinger::Schrodinger(int grid_size, double planck, double mass, double dx, double dt)
: grid_size(grid_size), planck(planck), mass(mass), dx(dx), dt(dt), psi(grid_size), potential(grid_size) 
{

}

void Schrodinger::initialize_wavefunc() //double init_value   
{
    double width = 10.0 ;
    double k0 = 2.0;

    for (int n = 0; n < grid_size; ++n)
    {
        double x = ( n - grid_size/2) * dx;

        psi[n] = std::exp(-0.5 * std::pow(x/width, 2)) * std::cos(k0*x);    
    }
}

Complex Schrodinger::approx_second_order(int n) const
{
    return (psi[n+1] - 2.0 * psi[n] + psi[n-1]) / std::pow(dx,2);
}




void Schrodinger::update()
{
    std::vector<Complex> psi_next(grid_size);

    for(int n = 1; n < grid_size; ++n)
    {   
        psi_next[n] = psi[n] + Complex(0, -1)*(planck*dt)/(2*mass) * 
        approx_second_order(n) - Complex(0, 1) * (dt/planck) * potential[n] * psi[n];       //complex(0, -1)? slarvat med minustecken???

    }

    psi = psi_next;

}



double Schrodinger::get_real(int n) const
{
    return psi[n].real();
}


double Schrodinger::get_imag(int n) const
{
    return psi[n].imag();
}