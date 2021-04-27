#include <string>
#include <exception>

class solver{
public:
    static int solveSimple(int first, int second, char operation){
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
        throw logic_error("wrong operation");
    }

private:
    template <typename T>
    static T plus(T first, T second){
        return first + second;
    }

    template <typename T>
    static T minus(T first, T second){
        return first - second;
    }

    template <typename T>
    static T multiply(T first, T second){
        return first * second;
    }

    template <typename T>
    static T divide(T first, T second){
        return first / second;
    }
};



