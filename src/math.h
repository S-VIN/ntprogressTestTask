#include <string>
#include <exception>

class Solver{
public:
    static float solveSimple(float first, float second, char operation){
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
    static float plus(float first, float second){
        return first + second;
    }

    static float minus(float first, float second){
        return first - second;
    }

    static float multiply(float first, float second){
        return first * second;
    }

    static float divide(float first, float second){
        return first / second;
    }
};



