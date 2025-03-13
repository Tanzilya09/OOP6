#include <iostream>
#include <stack>
using namespace std;

struct Pair {
    int x, y;

    Pair(int x = 0, int y = 0) : x(x), y(y) {}

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

template <typename T>                                    
class Stack {
protected:
    stack<T> s;

public:
    void push(const T& element) {
        s.push(element);
    }

    T pop() {
        if (s.empty()) {
            throw out_of_range("Стек пуст");
        }
        T temp = s.top();
        s.pop();
        return temp;
    }

    bool isEmpty() const {
        return s.empty();
    }

    void display() const {
        stack<T> temp = s;
        while (!temp.empty()) {
            temp.top().display();
            cout << endl;
            temp.pop();
        }
    }
};

class PairStack : public Stack<Pair> {
public:
    void push(const Pair& p) {
        Stack<Pair>::push(p); 
    }

    Pair pop() {
        return Stack<Pair>::pop(); 
    }

    void display() const {
        Stack<Pair>::display(); 
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    PairStack pairStack;

    pairStack.push(Pair(1, 2));
    pairStack.push(Pair(3, 4));
    pairStack.push(Pair(5, 6));

    cout << "Содержимое PairStack: " << endl;
    pairStack.display();
    cout << "\nИзвлечено из PairStack: ";
    Pair p = pairStack.pop();
    p.display();
    cout << endl;
    cout << "\nСодержимое PairStack после pop:" << endl;
    pairStack.display();

    return 0;
}

