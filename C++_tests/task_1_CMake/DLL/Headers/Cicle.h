#pragma once

#include "Curve.h"

class Cicle : public Curve {
protected:
	double r;
public:
	Cicle(double r);

	std::map<std::string, double> calc_point(double t) override;

	std::map<std::string, double> calc_derivatives(double t) override;

	std::map<std::string, double> get_param() override;

	bool operator<(Cicle right);

	~Cicle() override;
};