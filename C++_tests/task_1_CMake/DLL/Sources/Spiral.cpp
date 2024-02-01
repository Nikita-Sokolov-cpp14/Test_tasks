#include "../Headers/Spiral.h"

Spiral::Spiral(double r, double h) : Cicle(r) {
    this->h = h;
    name = "Спираль";
}

std::map<std::string, double> Spiral::calc_point(double t) {
    std::map<std::string, double> point = Cicle::calc_point(t);
    point["z"] = t * h / (2 * PI);

    return point;
}

std::map<std::string, double> Spiral::calc_derivatives(double t) {
    std::map<std::string, double> derivative = Cicle::calc_derivatives(t);
    derivative["dz_dt"] = h / (2 * PI);

    return derivative;
}

std::map<std::string, double> Spiral::get_param() {
    std::map<std::string, double> param;
    param["r"] = r;
    param["h"] = h;
    return param;
}

Spiral::~Spiral() {}