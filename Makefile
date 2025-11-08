# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic
TARGET = lab04
TEST_TARGET = test

# Исходные файлы
SOURCES = main.cpp
HEADERS = point.h figure.h triangle.h square.h rectangle.h array.h
TEST_SOURCES = test.cpp

# Сборка основной программы
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Сборка тестовой программы
$(TEST_TARGET): $(TEST_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SOURCES)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Очистка собранных файлов
clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: run test clean help