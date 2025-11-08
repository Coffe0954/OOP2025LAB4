#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <array>
#include <cmath>

template <std::floating_point T>
class Rectangle : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 4> vertices;

    void calculateVertices(const Point<T>& center, T width, T height) {
        T halfW = width / 2;
        T halfH = height / 2;
        vertices[0] = std::make_unique<Point<T>>(center.getX() - halfW, center.getY() - halfH);
        vertices[1] = std::make_unique<Point<T>>(center.getX() + halfW, center.getY() - halfH);
        vertices[2] = std::make_unique<Point<T>>(center.getX() + halfW, center.getY() + halfH);
        vertices[3] = std::make_unique<Point<T>>(center.getX() - halfW, center.getY() + halfH);
    }

public:
    Rectangle() {
        for (auto& v : vertices) {
            v = std::make_unique<Point<T>>();
        }
    }

    Rectangle(const Point<T>& center, T width, T height) {
        calculateVertices(center, width, height);
    }

    Point<T> getGeometricCenter() const override {
        T centerX = (vertices[0]->getX() + vertices[2]->getX()) / 2;
        T centerY = (vertices[0]->getY() + vertices[2]->getY()) / 2;
        return Point<T>(centerX, centerY);
    }

    T getArea() const override {
        T width = std::sqrt(std::pow(vertices[0]->getX() - vertices[1]->getX(), 2) +
                            std::pow(vertices[0]->getY() - vertices[1]->getY(), 2));
        T height = std::sqrt(std::pow(vertices[1]->getX() - vertices[2]->getX(), 2) +
                             std::pow(vertices[1]->getY() - vertices[2]->getY(), 2));
        return width * height;
    }

    operator double() const override {
        return static_cast<double>(getArea());
    }

    void printVertices() const override {
        std::cout << "Rectangle Vertices: ";
        for (const auto& v : vertices) {
            std::cout << *v << " ";
        }
        std::cout << std::endl;
    }

    void readVertices() override {
        std::cout << "Enter center (x y), width and height for Rectangle: ";
        T x, y, width, height;
        std::cin >> x >> y >> width >> height;
        calculateVertices(Point<T>(x, y), width, height);
    }

    bool operator==(const Figure<T>& other) const override {
        const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
        if (!otherRect) return false;

        for (size_t i = 0; i < 4; ++i) {
            if (*vertices[i] != *otherRect->vertices[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif