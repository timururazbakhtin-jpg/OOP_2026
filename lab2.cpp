#include <iostream>
#include <utility>

class Counter {
private:
    double min_val;
    double max_val;
    double current_val;
    double step;

    void validate_and_correct() {
        if (min_val > max_val) {
            std::swap(min_val, max_val);
        }
        if (step <= 0) {
            step = 1.0; 
        }
        if (current_val < min_val) current_val = min_val;
        if (current_val > max_val) current_val = max_val;
    }

public:
    Counter() : min_val(0.0), max_val(10.0), current_val(0.0), step(1.0) {}

    Counter(double min, double max, double current, double st) 
        : min_val(min), max_val(max), current_val(current), step(st) {
        validate_and_correct();
    }

    Counter(const Counter& other) 
        : min_val(other.min_val), max_val(other.max_val), 
          current_val(other.current_val), step(other.step) {}

    Counter& operator=(const Counter& other) {
        if (this != &other) {
            min_val = other.min_val;
            max_val = other.max_val;
            current_val = other.current_val;
            step = other.step;
        }
        return *this;
    }

    double operator()() const {
        return current_val;
    }

    void operator()(double min, double max, double current, double st) {
        min_val = min;
        max_val = max;
        current_val = current;
        step = st;
        validate_and_correct();
    }

    explicit operator double() const {
        return current_val;
    }

    Counter operator+(double val) const {
        Counter temp(*this);
        temp.current_val += val;
        temp.validate_and_correct();
        return temp;
    }

    Counter operator-(double val) const {
        Counter temp(*this);
        temp.current_val -= val;
        temp.validate_and_correct();
        return temp;
    }

    Counter& operator++() {
        current_val += step;
        validate_and_correct();
        return *this;
    }

    Counter operator++(int) {
        Counter temp(*this);
        ++(*this);
        return temp;
    }

    Counter& operator--() {
        current_val -= step;
        validate_and_correct();
        return *this;
    }

    Counter operator--(int) {
        Counter temp(*this);
        --(*this);
        return temp;
    }

    bool operator==(const Counter& other) const {
        return (current_val == other.current_val && 
                min_val == other.min_val && 
                max_val == other.max_val && 
                step == other.step);
    }

    bool operator!=(const Counter& other) const {
        return !(*this == other);
    }

    bool operator<(const Counter& other) const {
        return current_val < other.current_val;
    }

    bool operator>(const Counter& other) const {
        return current_val > other.current_val;
    }

    bool operator<=(const Counter& other) const {
        return current_val <= other.current_val;
    }

    bool operator>=(const Counter& other) const {
        return current_val >= other.current_val;
    }

    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        os << "[Counter: current=" << c.current_val 
           << " | min=" << c.min_val << ", max=" << c.max_val 
           << ", step=" << c.step << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Counter& c) {
        double min, max, cur, st;
        if (is >> min >> max >> cur >> st) {
            c(min, max, cur, st);
        }
        return is;
    }
};

int main() {
    std::cout << "--- Демонстрація конструкторів ---\n";
    Counter c1;
    Counter c2(0.0, 100.0, 50.0, 10.0);
    Counter c3 = c2;

    std::cout << "c1 (default): " << c1 << "\n";
    std::cout << "c2 (params):  " << c2 << "\n";
    std::cout << "c3 (copy):    " << c3 << "\n\n";

    std::cout << "--- Перевірка валідації в конструкторі ---\n";
    Counter c_invalid(100.0, 0.0, 150.0, -5.0);
    std::cout << "c_invalid (виправлено): " << c_invalid << "\n\n";

    std::cout << "--- Демонстрація арифметики та інкрементів ---\n";
    std::cout << "Початкове c2: " << c2 << "\n";
    c2 = c2 + 25.5;
    std::cout << "Після c2 + 25.5: " << c2 << "\n";
    c2 = c2 - 90.0;
    std::cout << "Після c2 - 90.0 (захист min): " << c2 << "\n";

    ++c2;
    std::cout << "Після префіксного ++: " << c2 << "\n";
    Counter c4 = c2++;
    std::cout << "Після постфіксного ++ (c4 містить старе значення):\n";
    std::cout << "c2: " << c2 << "\n";
    std::cout << "c4: " << c4 << "\n\n";

    std::cout << "--- Демонстрація доступу () та перетворення типу ---\n";
    std::cout << "Значення c2 через c2(): " << c2() << "\n";
    double val = static_cast<double>(c2);
    std::cout << "Значення c2 через (double)c2: " << val << "\n\n";

    std::cout << "--- Переініціалізація через () ---\n";
    c2(0.0, 10.0, 5.0, 1.0);
    std::cout << "Після c2(0.0, 10.0, 5.0, 1.0): " << c2 << "\n\n";

    std::cout << "--- Порівняння ---\n";
    Counter c5(0.0, 10.0, 6.0, 1.0);
    std::cout << "c2 == c5: " << (c2 == c5 ? "true" : "false") << "\n";
    std::cout << "c2 < c5:  " << (c2 < c5 ? "true" : "false") << "\n\n";

    std::cout << "--- Введення з консолі ---\n";
    Counter c_input;
    std::cout << "Введіть min, max, поточне значення та крок (через пробіл): ";
    std::cin >> c_input;
    std::cout << "Ви ввели: " << c_input << "\n";

    return 0;
}