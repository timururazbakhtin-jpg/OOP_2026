#include <iostream>
#include <vector>
#include <cmath>

class ParametricFunction {
public:
    ParametricFunction() {}
    virtual ~ParametricFunction() {}
    virtual double calculate(double x) const = 0;
};

// Похідний клас 1: Лінійна функція f(x) = a*x + b
class LinearFunction : public ParametricFunction {
private:
    double a, b;
public:
    // Конструктори
    LinearFunction() : a(0), b(0) {}
    LinearFunction(double a_val, double b_val) : a(a_val), b(b_val) {}
    LinearFunction(const LinearFunction& other) : a(other.a), b(other.b) {}

    // Перевизначення віртуальної функції
    double calculate(double x) const override {
        return a * x + b;
    }
};

// Похідний клас 2: Квадратична функція f(x) = a*x^2 + b*x + c
class QuadraticFunction : public ParametricFunction {
private:
    double a, b, c;
public:
    // Конструктори
    QuadraticFunction() : a(0), b(0), c(0) {}
    QuadraticFunction(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}
    QuadraticFunction(const QuadraticFunction& other) : a(other.a), b(other.b), c(other.c) {}

    // Перевизначення віртуальної функції
    double calculate(double x) const override {
        return a * x * x + b * x + c;
    }
};

// Похідний клас 3: Гармонічна функція f(x) = A * sin(omega * x + phi)
class HarmonicFunction : public ParametricFunction {
private:
    double A, omega, phi;
public:
    // Конструктори
    HarmonicFunction() : A(0), omega(0), phi(0) {}
    HarmonicFunction(double A_val, double w_val, double phi_val) : A(A_val), omega(w_val), phi(phi_val) {}
    HarmonicFunction(const HarmonicFunction& other) : A(other.A), omega(other.omega), phi(other.phi) {}

    // Перевизначення віртуальної функції
    double calculate(double x) const override {
        return A * std::sin(omega * x + phi);
    }
};

class FunctionContainer {
private:
    std::vector<ParametricFunction*> functions;
public:
    FunctionContainer() {}

    ~FunctionContainer() {
        for (ParametricFunction* func : functions) {
            delete func;
        }
    }

    void addFunction(ParametricFunction* func) {
        functions.push_back(func);
    }

    // Обчислення суми значень всіх функцій для аргументу x з використанням механізм поліморфізму
    double calculateSum(double x) const {
        double sum = 0.0;
        for (const ParametricFunction* func : functions) {
            sum += func->calculate(x); 
        }
        return sum;
    }
};

int main() {
    std::cout << "--- Демонстрація роботи класів ---\n";
    FunctionContainer container;
    // Лінійна: f(x) = 2x + 3
    ParametricFunction* lin_func = new LinearFunction(2.0, 3.0); 
    
    // Квадратична: f(x) = 1x^2 - 2x + 1
    ParametricFunction* quad_func = new QuadraticFunction(1.0, -2.0, 1.0); 
    
    // Гармонічна: f(x) = 5 * sin(1*x + 0)
    ParametricFunction* harm_func = new HarmonicFunction(5.0, 1.0, 0.0); 

    // Додаємо об'єкти до контейнера
    container.addFunction(lin_func);
    container.addFunction(quad_func);
    container.addFunction(harm_func);

    // Задаємо аргумент
    double x = 3.14159 / 2; // Приблизно pi/2

    std::cout << "Аргумент x = " << x << "\n\n";

    std::cout << "Значення лінійної функції: " << lin_func->calculate(x) << "\n";
    std::cout << "Значення квадратичної функції: " << quad_func->calculate(x) << "\n";
    std::cout << "Значення гармонічної функції: " << harm_func->calculate(x) << "\n\n";

    double total_sum = container.calculateSum(x);
    std::cout << "Сума значень усіх функцій у контейнері: " << total_sum << "\n";

    return 0; 
}
