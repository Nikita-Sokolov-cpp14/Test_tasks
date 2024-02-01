#pragma once

#include "Curve.h"

class Ellips : public Curve {
protected:
	double a;
	double b;

public:
	Ellips(double a, double b);

	std::map<std::string, double> calc_point(double t) override;

	std::map<std::string, double> calc_derivatives(double t) override;

	std::map<std::string, double> get_param() override;

	~Ellips() override;
};