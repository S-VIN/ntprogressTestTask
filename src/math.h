#include <string>
#include <exception>

class Solver{
public:
    static double solveSimple(double first, double second, char operation){
        switch (operation) {
            case '+':
                return plus(first, second);
            case '-':
                return minus(first, second);
            case '/':
                return divide(first, second);
            case '*':
                return multiply(first, second);
        }
        throw std::logic_error("wrong operation");
    }

private:
    static double plus(double first, double second){
        return first + second;
    }

    static double minus(double first, double second){
        return first - second;
    }

    static double multiply(double first, double second){
        return first * second;
    }

    static double divide(double first, double second){
        return first / second;
    }
};



