#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <windows.h>
#include <algorithm>

#include "Headers/Cicle.h"
#include "Headers/Curve.h"
#include "Headers/Ellips.h"
#include "Headers/Spiral.h"
#include "Headers/print_derivatives.h"
#include "Headers/print_point.h"

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