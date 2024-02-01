#include "../Headers/Ellips.h"

Ellips::Ellips(double a, double b) {
    this->a = a;
    this->b = b;
    name = "Эллипс";
}

std::map<std::string, double> Ellips::calc_point(double t) {
    std::map<std::string, double> point;
    point["x"] = a * cos(t);
    point["y"] = b * sin(t);
    point["z"] = 0;

    return point;
}

std::map<std::string, double> Ellips::calc_derivatives(double t) {
    std::map<std::string, double> derivative;
    derivative["dx_dt"] = -a * sin(t);
    derivative["dy_dt"] = b * cos(t);
    derivative["dz_dt"] = 0;

    return derivative;
}

std::map<std::string, double> Ellips::get_param() {
    std::map<std::string, double> param;
    param["a"] = a;
    param["b"] = b;
    return param;
}

Ellips::~Ellips() {}