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
    LinearFunction() : a(0), b(0) {}
    LinearFunction(double a_val, double b_val) : a(a_val), b(b_val) {}
    LinearFunction(const LinearFunction& other) : a(other.a), b(other.b) {}

    double calculate(double x) const override {
        return a * x + b;
    }
};

// Похідний клас 2: Квадратична функція f(x) = a*x^2 + b*x + c
class QuadraticFunction : public ParametricFunction {
private:
    double a, b, c;
public:
    QuadraticFunction() : a(0), b(0), c(0) {}
    QuadraticFunction(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}
    QuadraticFunction(const QuadraticFunction& other) : a(other.a), b(other.b), c(other.c) {}

    double calculate(double x) const override {
        return a * x * x + b * x + c;
    }
};

// Похідний клас 3: Гармонічна функція f(x) = A * sin(omega * x + phi)
class HarmonicFunction : public ParametricFunction {
private:
    double A, omega, phi;
public:
    HarmonicFunction() : A(0), omega(0), phi(0) {}
    HarmonicFunction(double A_val, double w_val, double phi_val) : A(A_val), omega(w_val), phi(phi_val) {}
    HarmonicFunction(const HarmonicFunction& other) : A(other.A), omega(other.omega), phi(other.phi) {}

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

    double calculateSum(double x) const {
        double sum = 0.0;
        for (const ParametricFunction* func : functions) {
            sum += func->calculate(x); 
        }
        return sum;
    }
};

int main() {
    std::cout << "--- Demonstration of class functionality ---\n";
    FunctionContainer container;
    ParametricFunction* lin_func = new LinearFunction(2.0, 3.0); 
    ParametricFunction* quad_func = new QuadraticFunction(1.0, -2.0, 1.0); 
    ParametricFunction* harm_func = new HarmonicFunction(5.0, 1.0, 0.0); 

    container.addFunction(lin_func);
    container.addFunction(quad_func);
    container.addFunction(harm_func);

    double x = 3.14159 / 2; // Approximately pi/2

    std::cout << "Argument x = " << x << "\n\n";

    std::cout << "Value of the linear function: " << lin_func->calculate(x) << "\n";
    std::cout << "Value of the quadratic function: " << quad_func->calculate(x) << "\n";
    std::cout << "Value of the harmonic function: " << harm_func->calculate(x) << "\n\n";

    double total_sum = container.calculateSum(x);
    std::cout << "Sum of the values of all functions in the container: " << total_sum << "\n";

    return 0; 
}