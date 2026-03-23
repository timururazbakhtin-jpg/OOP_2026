#include <iostream>
#include <cmath>

class Rectangle {
public:
    class Point {
    private:
        double x;
        double y;

    public:
        Point() : x(0.0), y(0.0) {}

        Point(double startX, double startY) : x(startX), y(startY) {}

        Point(const Point& other) : x(other.x), y(other.y) {}

        double getX() const { return x; }
        double getY() const { return y; }

        void setX(double newX) { x = newX; }
        void setY(double newY) { y = newY; }

        void Read() {
            std::cin >> x >> y;
        }

        void Print() const {
            std::cout << "(" << x << ", " << y << ")";
        }
    };

private:
    double x;      
    double y;
    double length;
    double width;

public:

    Rectangle() : x(0.0), y(0.0), length(1.0), width(1.0) {}

    Rectangle(double startX, double startY, double len, double wid) {
        x = startX;
        y = startY;

        if (len >= 0.0 && wid >= 0.0) {
            length = len;
            width = wid;
        } else {
            length = 1.0;
            width = 1.0;
        }
    }

    Rectangle(const Rectangle& other)
        : x(other.x), y(other.y),
          length(other.length), width(other.width) {}

    Rectangle(Rectangle&& other) noexcept
        : x(other.x), y(other.y),
          length(other.length), width(other.width) {

        other.x = 0.0;
        other.y = 0.0;
        other.length = 0.0;
        other.width = 0.0;
    }

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            length = other.length;
            width = other.width;
        }
        return *this;
    }

    Rectangle& operator=(Rectangle&& other) noexcept {
        if (this != &other) {
            x = other.x;
            y = other.y;
            length = other.length;
            width = other.width;

            other.x = 0.0;
            other.y = 0.0;
            other.length = 0.0;
            other.width = 0.0;
        }
        return *this;
    }

    ~Rectangle() = default;

    double getX() const { return x; }
    double getY() const { return y; }
    double getLength() const { return length; }
    double getWidth() const { return width; }

    void setX(double newX) { x = newX; } 
    void setY(double newY) { y = newY; }

    void setLength(double newLen) {
        if (newLen >= 0.0) {
            length = newLen;
        }
    }

    void setWidth(double newWid) {
        if (newWid >= 0.0) {
            width = newWid;
        }
    }

    bool IsEqual(const Rectangle& other) const {
        const double EPS = 1e-9;

        return (std::abs(x - other.x) < EPS &&
                std::abs(y - other.y) < EPS &&
                std::abs(length - other.length) < EPS &&
                std::abs(width - other.width) < EPS);
    }

    double Area() const {
        return length * width;
    }

    double Perimeter() const {
        return 2.0 * (length + width);
    }

    bool ContainsPoint(const Point& pt) const {
        return (pt.getX() >= x && pt.getX() <= (x + length) &&
                pt.getY() >= y && pt.getY() <= (y + width));
    }

    void Read() {
        std::cin >> x >> y;

        double len, wid;
        std::cin >> len >> wid;

        if (len >= 0.0 && wid >= 0.0) {
            length = len;
            width = wid;
        }
    }

    void Print() const {
        std::cout << "Coordinates: (" << x << ", " << y
                  << "), Length: " << length
                  << ", Width: " << width;
    }
};

int main() {
    std::cout << "--- Rectangle demo ---\n\n";

    Rectangle r1;
    Rectangle r2(1.0, 1.0, 5.0, 4.0);
    Rectangle r3(r2);

    std::cout << "r1: ";
    r1.Print();
    std::cout << "\nr2: ";
    r2.Print();
    std::cout << "\nr3: ";
    r3.Print();
    std::cout << "\n\n";

    std::cout << "Area r2: " << r2.Area() << "\n";
    std::cout << "Perimeter r2: " << r2.Perimeter() << "\n\n";

    if (r2.IsEqual(r3)) {
        std::cout << "r2 == r3\n";
    } else {
        std::cout << "r2 != r3\n";
    }

    std::cout << "\n";

    Rectangle::Point p1(3.0, 3.0);
    Rectangle::Point p2(10.0, 10.0);

    std::cout << "Point ";
    p1.Print();
    std::cout << (r2.ContainsPoint(p1) ? " inside\n" : " outside\n");

    std::cout << "Point ";
    p2.Print();
    std::cout << (r2.ContainsPoint(p2) ? " inside\n" : " outside\n");

    std::cout << "\n";

    r1.setLength(-5.0);
    r1.setWidth(10.0);

    std::cout << "r1 after invalid set:\n";
    r1.Print();

    std::cout << "\n";

    return 0;
}