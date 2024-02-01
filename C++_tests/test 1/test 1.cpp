#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <windows.h>
#include <algorithm>

#define PI 3.14159


class Curve {
protected:
	std::string name;
public:
	virtual std::map<std::string, double> calc_derivatives(double t) = 0;
	virtual std::map<std::string, double> calc_point(double t) = 0; 
	virtual std::map<std::string, double> get_param() = 0;

	std::string get_name() {
		return name;
	}

	virtual ~Curve() {}
};

class Cicle : public Curve {
protected:
	double r;
public:
	Cicle(double r) {
		this->r = r;
		name = "Окружность";
	}

	std::map<std::string, double> calc_point(double t) override {
		std::map<std::string, double> point;
		point["x"] = r * cos(t);
		point["y"] = r * sin(t);
		point["z"] = 0;

		return point;
	}

	std::map<std::string, double> calc_derivatives(double t) override {
		std::map<std::string, double> derivative;
		derivative["dx_dt"] = -r * sin(t);
		derivative["dy_dt"] = r * cos(t);
		derivative["dz_dt"] = 0;

		return derivative;
	}

	std::map<std::string, double> get_param() override {
		std::map<std::string, double> param;
		param["r"] = r;
		return param;
	}

	bool operator<(Cicle right) {
		return r < right.r;
	}

	~Cicle() override {}
};

class Ellips : public Curve {
protected:
	double a;
	double b;

public:
	Ellips(double a, double b) {
		this->a = a;
		this->b = b;
		name = "Эллипс";
	}

	std::map<std::string, double> calc_point(double t) override {
		std::map<std::string, double> point;
		point["x"] = a * cos(t);
		point["y"] = b * sin(t);
		point["z"] = 0;

		return point;
	}

	std::map<std::string, double> calc_derivatives(double t) override {
		std::map<std::string, double> derivative;
		derivative["dx_dt"] = -a * sin(t);
		derivative["dy_dt"] = b * cos(t);
		derivative["dz_dt"] = 0;

		return derivative;
	}

	std::map<std::string, double> get_param() override {
		std::map<std::string, double> param;
		param["a"] = a;
		param["b"] = b;
		return param;
	}

	~Ellips() override {}
};

class Spiral : public Cicle {
protected:
	double h;
public:
	Spiral(double r, double h) : Cicle(r) {
		this->h = h;
		name = "Спираль";
	}

	std::map<std::string, double> calc_point(double t) override {
		std::map<std::string, double> point = Cicle::calc_point(t);
		point["z"] = t * h / (2 * PI);

		return point;
	}

	std::map<std::string, double> calc_derivatives(double t) override {
		std::map<std::string, double> derivative = Cicle::calc_derivatives(t);
		derivative["dz_dt"] = h / (2 * PI);

		return derivative;
	}

	std::map<std::string, double> get_param() override {
		std::map<std::string, double> param;
		param["r"] = r;
		param["h"] = h;
		return param;
	}

	~Spiral() override {}
};

void print_point(Curve* curve, double t) {
	std::map <std::string, double> point = curve->calc_point(t);
	std::cout << curve->get_name() << ":" << std::endl;
	std::cout << "x = " << point["x"] << "; y = " << point["y"] << "; z = " << point["z"] << std::endl;
}

void print_derivatives(Curve* curve, double t) {
	std::map <std::string, double> dderivative = curve->calc_derivatives(t);
	std::cout << "dx/dt = " << dderivative["dx_dt"];
	std::cout << "; dy/dt = " << dderivative["dy_dt"];
	std::cout << "; dz/dt = " << dderivative["dz_dt"] << std::endl;
	std::cout << std::endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int N = 20;
	int rand_number;

	std::vector<Curve*> curves(N);
	
	//Задание 2. заполнение вектора случайными кривыми
	//P.S. Без явного выделения памяти не обошлось, к сожалению
	for (int i = 0; i < N; ++i) {
		rand_number = rand() % 3;
		switch (rand_number) {
			case 0: curves[i] = new Cicle(rand() % 100); break;
			case 1: curves[i] = new Ellips(rand() % 100, rand() % 100); break;
			case 2: curves[i] = new Spiral(rand() % 100, rand() % 20); break;
		}
	}

	//Задание 3. Вывод координат и производных всех кривых для t = PI / 4
	for (auto& c : curves) {
		print_point(c, PI / 4);
		print_derivatives(c, PI / 4);
	}

	//Задание 4. Заполнение 2 контейнера только окружностями из 1-го
	std::vector<Cicle> cicles_only;
	for (auto& c : curves) {
		if (c->get_name() == "Окружность") {
			cicles_only.push_back(Cicle(c->get_param()["r"]));
			std::cout << &cicles_only.back() << " не равно " << c << std::endl; //проверка на неклонирование
		}
	}

	//Задание 5. Сортировка
	std::sort(cicles_only.begin(), cicles_only.end());
	for (auto& c : cicles_only) {
		std::cout << c.get_param()["r"] << std::endl;
	}

	//Задание 6. Общая сумма радиусов
	double sum_r = 0;
	for (auto& c : cicles_only) {
		sum_r += c.get_param()["r"];
	}
	std::cout << "Сумма радиусов = " << sum_r << std::endl;

	//очистка
	for (auto& c : curves) {
		delete c;
	}

	return 0;
}