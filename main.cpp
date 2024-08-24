#include "wavefunction.h"
#include <fstream>
#include <iostream>

int main()
{
    int grid_size = 50;
    double planck = std::pow(6.626, -34);
    double mass = 10;
    double dx = 0.1;
    double dt = 0.01;
    int total_time = 50;

    Schrodinger wave(grid_size, planck, mass, dx, dt);
    wave.initialize_wavefunc();

    std::ofstream res_file("wave_res.txt");

    //double real_part;
    //double imag_part;

    for (int t = 0; t < total_time; ++t)
    {

        bool valid_data = true;

        for (int n = 0; n < grid_size; ++n)
        {
            double real_part = wave.get_real(n);
            double imag_part = wave.get_imag(n);

            if(std::isnan(real_part) || std::isnan(imag_part)) // fick problem med "nan" antagligen från div med 0 eller annat
            {   
                valid_data = false;
                break;

            }

            res_file << real_part << " " << imag_part << " " << "\n";
        }

       

        //res_file << "\n";
        wave.update();
    }

    res_file.close(); //stäng fil

    


    return 0;
}