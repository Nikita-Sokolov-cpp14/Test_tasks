#include "../Headers/print_derivatives.h"
#include <iostream>

void print_derivatives(Curve* curve, double t) {
	std::map <std::string, double> dderivative = curve->calc_derivatives(t);
	std::cout << "dx/dt = " << dderivative["dx_dt"];
	std::cout << "; dy/dt = " << dderivative["dy_dt"];
	std::cout << "; dz/dt = " << dderivative["dz_dt"] << std::endl;
	std::cout << std::endl;
}