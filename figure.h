#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <memory>
#include <iostream>

template <std::floating_point T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual Point<T> getGeometricCenter() const = 0;
    virtual T getArea() const = 0;
    virtual operator double() const = 0;

    virtual void printVertices() const = 0;
    virtual void readVertices() = 0;

    virtual bool operator==(const Figure& other) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        os << "Center: " << fig.getGeometricCenter() << " | Area: " << fig.getArea();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.readVertices();
        return is;
    }
};

#endif