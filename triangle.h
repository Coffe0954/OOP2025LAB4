#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <array>
#include <cmath>

template <std::floating_point T>
class Triangle : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 3> vertices;

public:
    Triangle() {
        for (auto& v : vertices) {
            v = std::make_unique<Point<T>>();
        }
    }

    Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
        vertices[0] = std::make_unique<Point<T>>(a);
        vertices[1] = std::make_unique<Point<T>>(b);
        vertices[2] = std::make_unique<Point<T>>(c);
    }

    Point<T> getGeometricCenter() const override {
        T centerX = (vertices[0]->getX() + vertices[1]->getX() + vertices[2]->getX()) / 3;
        T centerY = (vertices[0]->getY() + vertices[1]->getY() + vertices[2]->getY()) / 3;
        return Point<T>(centerX, centerY);
    }

    T getArea() const override {
        T x1 = vertices[0]->getX(), y1 = vertices[0]->getY();
        T x2 = vertices[1]->getX(), y2 = vertices[1]->getY();
        T x3 = vertices[2]->getX(), y3 = vertices[2]->getY();
        return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2);
    }

    operator double() const override {
        return static_cast<double>(getArea());
    }

    void printVertices() const override {
        std::cout << "Triangle Vertices: ";
        for (const auto& v : vertices) {
            std::cout << *v << " ";
        }
        std::cout << std::endl;
    }

    void readVertices() override {
        std::cout << "Enter 3 vertices (x y) for Triangle:\n";
        for (auto& v : vertices) {
            T x, y;
            std::cin >> x >> y;
            v = std::make_unique<Point<T>>(x, y);
        }
    }

    bool operator==(const Figure<T>& other) const override {
        const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
        if (!otherTriangle) return false;

        for (size_t i = 0; i < 3; ++i) {
            if (*vertices[i] != *otherTriangle->vertices[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif