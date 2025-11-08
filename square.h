#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"
#include <array>
#include <cmath>

template <std::floating_point T>
class Square : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 4> vertices;

    void calculateVertices(const Point<T>& center, T side) {
        T half = side / 2;
        vertices[0] = std::make_unique<Point<T>>(center.getX() - half, center.getY() - half);
        vertices[1] = std::make_unique<Point<T>>(center.getX() + half, center.getY() - half);
        vertices[2] = std::make_unique<Point<T>>(center.getX() + half, center.getY() + half);
        vertices[3] = std::make_unique<Point<T>>(center.getX() - half, center.getY() + half);
    }

public:
    Square() {
        for (auto& v : vertices) {
            v = std::make_unique<Point<T>>();
        }
    }

    Square(const Point<T>& center, T side) {
        calculateVertices(center, side);
    }

    Point<T> getGeometricCenter() const override {
        T centerX = (vertices[0]->getX() + vertices[2]->getX()) / 2;
        T centerY = (vertices[0]->getY() + vertices[2]->getY()) / 2;
        return Point<T>(centerX, centerY);
    }

    T getArea() const override {
        T side = std::sqrt(std::pow(vertices[0]->getX() - vertices[1]->getX(), 2) +
                           std::pow(vertices[0]->getY() - vertices[1]->getY(), 2));
        return side * side;
    }

    operator double() const override {
        return static_cast<double>(getArea());
    }

    void printVertices() const override {
        std::cout << "Square Vertices: ";
        for (const auto& v : vertices) {
            std::cout << *v << " ";
        }
        std::cout << std::endl;
    }

    void readVertices() override {
        std::cout << "Enter center (x y) and side length for Square: ";
        T x, y, side;
        std::cin >> x >> y >> side;
        calculateVertices(Point<T>(x, y), side);
    }

    bool operator==(const Figure<T>& other) const override {
        const Square* otherSquare = dynamic_cast<const Square*>(&other);
        if (!otherSquare) return false;

        for (size_t i = 0; i < 4; ++i) {
            if (*vertices[i] != *otherSquare->vertices[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif