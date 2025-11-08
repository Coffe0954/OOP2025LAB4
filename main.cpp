#include <iostream>
#include <memory>
#include "point.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

void printMenu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Add figure\n";
    std::cout << "2. Show all figures\n";
    std::cout << "3. Calculate total area\n";
    std::cout << "4. Remove figure by index\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose action: ";
}

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    int choice;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\n--- ADD FIGURE ---\n";
                std::cout << "1. Triangle\n";
                std::cout << "2. Square\n";
                std::cout << "3. Rectangle\n";
                std::cout << "Choose figure type: ";
                
                int figureType;
                std::cin >> figureType;

                switch (figureType) {
                    case 1: {
                        auto triangle = std::make_shared<Triangle<double>>();
                        std::cout << "Enter 3 triangle vertices (x y):\n";
                        std::cin >> *triangle;
                        figures.add(triangle);
                        std::cout << "Triangle added!\n";
                        break;
                    }
                    case 2: {
                        auto square = std::make_shared<Square<double>>();
                        std::cout << "Enter center (x y) and side length: ";
                        std::cin >> *square;
                        figures.add(square);
                        std::cout << "Square added!\n";
                        break;
                    }
                    case 3: {
                        auto rectangle = std::make_shared<Rectangle<double>>();
                        std::cout << "Enter center (x y), width and height: ";
                        std::cin >> *rectangle;
                        figures.add(rectangle);
                        std::cout << "Rectangle added!\n";
                        break;
                    }
                    default:
                        std::cout << "Invalid choice!\n";
                }
                break;
            }

            case 2: {
                std::cout << "\nALL FIGURES\n";
                if (figures.getSize() == 0) {
                    std::cout << "Figure list is empty.\n";
                } else {
                    for (size_t i = 0; i < figures.getSize(); ++i) {
                        std::cout << "\n[" << i << "] ";
                        figures[i]->printVertices();
                        std::cout << "   Geometric center: " << figures[i]->getGeometricCenter() << "\n";
                        std::cout << "   Area: " << figures[i]->getArea() << "\n";
                    }
                }
                break;
            }

            case 3: {
                std::cout << "\nTOTAL AREA\n";
                double totalArea = 0;
                for (size_t i = 0; i < figures.getSize(); ++i) {
                    totalArea += figures[i]->getArea();
                }
                std::cout << "Total area of all figures: " << totalArea << "\n";
                break;
            }

            case 4: {
                std::cout << "\nREMOVE FIGURE\n";
                if (figures.getSize() == 0) {
                    std::cout << "Figure list is empty.\n";
                } else {
                    std::cout << "Enter figure index to remove (0-" << figures.getSize()-1 << "): ";
                    size_t index;
                    std::cin >> index;
                    if (index < figures.getSize()) {
                        figures.removeAt(index);
                        std::cout << "Figure removed successfully!\n";
                    } else {
                        std::cout << "Invalid index!\n";
                    }
                }
                break;
            }

            case 5:
                std::cout << "\n=== DO SVIDANIYA ===\n";
                break;

            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}