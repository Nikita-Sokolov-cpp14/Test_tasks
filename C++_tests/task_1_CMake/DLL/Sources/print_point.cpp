#include "../Headers/print_point.h"
#include <iostream>

void print_point(Curve* curve, double t) {
	std::map <std::string, double> point = curve->calc_point(t);
	std::cout << curve->get_name() << ":" << std::endl;
	std::cout << "x = " << point["x"] << "; y = " << point["y"] << "; z = " << point["z"] << std::endl;
}