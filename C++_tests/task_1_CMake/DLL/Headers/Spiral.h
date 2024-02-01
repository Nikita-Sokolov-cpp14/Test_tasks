#pragma once

#include "Cicle.h"

class Spiral : public Cicle {
protected:
	double h;
public:
	Spiral(double r, double h);

	std::map<std::string, double> calc_point(double t) override;

	std::map<std::string, double> calc_derivatives(double t) override;

	std::map<std::string, double> get_param() override;

	~Spiral() override;
};