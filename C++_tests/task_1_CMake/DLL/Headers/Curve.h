#pragma once

#include <string>
#include <map>

#define PI 3.14159

class Curve {
protected:
	std::string name;
public:
	virtual std::map<std::string, double> calc_derivatives(double t) = 0;
	virtual std::map<std::string, double> calc_point(double t) = 0; 
	virtual std::map<std::string, double> get_param() = 0;

	std::string get_name();
	virtual ~Curve();
};