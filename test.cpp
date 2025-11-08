#include <iostream>
#include <cassert>
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

void testPoint() {
    Point<double> p1(1.0, 2.0);
    assert(p1.getX() == 1.0);
    assert(p1.getY() == 2.0);
    std::cout << "Point test passed!\n";
}

void testTriangle() {
    Triangle<double> t(Point<double>(0,0), Point<double>(1,0), Point<double>(0,1));
    assert(t.getArea() > 0.49 && t.getArea() < 0.51); // ~0.5
    std::cout << "Triangle test passed! Area: " << t.getArea() << "\n";
}

void testSquare() {
    Square<double> s(Point<double>(0,0), 2.0);
    assert(s.getArea() == 4.0);
    std::cout << "Square test passed! Area: " << s.getArea() << "\n";
}

void testRectangle() {
    Rectangle<double> r(Point<double>(0,0), 3.0, 2.0);
    assert(r.getArea() == 6.0);
    std::cout << "Rectangle test passed! Area: " << r.getArea() << "\n";
}

void testArray() {
    Array<std::shared_ptr<Figure<double>>> arr;
    arr.add(std::make_shared<Square<double>>(Point<double>(0,0), 1.0));
    arr.add(std::make_shared<Rectangle<double>>(Point<double>(0,0), 2.0, 3.0));
    
    assert(arr.getSize() == 2);
    arr.removeAt(0);
    assert(arr.getSize() == 1);
    std::cout << "Array test passed!\n";
}

int main() {
    testPoint();
    testTriangle();
    testSquare();
    testRectangle();
    testArray();
    
    std::cout << "All tests passed!\n";
    return 0;
}