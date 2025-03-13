#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}

    void operator++() { count++; }  
    void operator--() { count--; }  
    Counter operator++(int) { 
        Counter temp = *this;
        ++(*this);
        return temp;
    }
    Counter operator--(int) { 
        Counter temp = *this;
        --(*this);
        return temp;
    }

    void display() {
        cout << "Счетчик: " << count << endl;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    Counter c;
    c.display();
    c++;
    c.display();
    c--;
    c.display();
    return 0;
}
