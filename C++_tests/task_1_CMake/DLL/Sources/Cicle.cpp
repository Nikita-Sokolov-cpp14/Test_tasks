#include "../Headers/Cicle.h"

Cicle::Cicle(double r) {
    this->r = r;
    name = "Окружность";
}

std::map<std::string, double> Cicle::calc_point(double t) {
    std::map<std::string, double> point;
    point["x"] = r * cos(t);
    point["y"] = r * sin(t);
    point["z"] = 0;

    return point;
}

std::map<std::string, double> Cicle::calc_derivatives(double t) {
    std::map<std::string, double> derivative;
    derivative["dx_dt"] = -r * sin(t);
    derivative["dy_dt"] = r * cos(t);
    derivative["dz_dt"] = 0;

    return derivative;
}

std::map<std::string, double> Cicle::get_param() {
    std::map<std::string, double> param;
    param["r"] = r;
    return param;
}

bool Cicle::operator<(Cicle right) {
    return r < right.r;
}

Cicle::~Cicle() {}