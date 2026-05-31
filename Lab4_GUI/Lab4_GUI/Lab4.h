#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

class ParametricFunction {
public:
    ParametricFunction() {}
    virtual ~ParametricFunction() {}

    virtual double calculate(double x) const = 0;

    virtual std::string getInfo() const = 0;
};

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

    std::string getInfo() const override {
        std::ostringstream oss;
        oss << "Linear functuion: f(x) = " << a << "*x + " << b;
        return oss.str();
    }
};

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

    std::string getInfo() const override {
        std::ostringstream oss;
        oss << "Quadratic function: f(x) = " << a << "*x^2 + " << b << "*x + " << c;
        return oss.str();
    }
};

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

    std::string getInfo() const override {
        std::ostringstream oss;
        oss << "Harmonic function: f(x) = " << A << " * sin(" << omega << "*x + " << phi << ")";
        return oss.str();
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

    std::vector<std::string> getAllFunctionsInfo() const {
        std::vector<std::string> infoList;
        for (const ParametricFunction* func : functions) {
            infoList.push_back(func->getInfo());
        }
        return infoList;
    }

    void clear() {
        for (ParametricFunction* func : functions) {
            delete func;
        }
        functions.clear();
    }
};