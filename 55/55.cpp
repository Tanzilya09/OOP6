#include <iostream>
#include <cstring>
using namespace std;

class Pstring {
protected:
    string str;
public:
    Pstring(const string& s = "") : str(s) {}
    void display() const { cout << str; }
    Pstring& operator=(const string& s) { str = s; return *this; }
};

class Pstring2 : public Pstring {
public:
    Pstring2(const string& s = "") : Pstring(s) {}

    Pstring2& left(const Pstring2& s1, size_t n) {
        str = s1.str.substr(0, n);
        return *this;
    }

    Pstring2& mid(const Pstring2& s1, size_t start, size_t n) {
        if (start >= s1.str.size()) {
            str = "";
        }
        else {
            str = s1.str.substr(start, n);
        }
        return *this;
    }

    Pstring2& right(const Pstring2& s1, size_t n) {
        size_t len = s1.str.size();
        str = s1.str.substr((n > len) ? 0 : len - n, n);
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));  
    Pstring2 s1("Привет, мир!"); 
    Pstring2 s2;
    s2.left(s1, 6);
    cout << "Левые 6 символов: ";
    s2.display(); 
    cout << endl;
    s2.mid(s1, 8, 3);
    cout << "Средние символы (8, 3): ";
    s2.display(); 
    cout << endl;
    s2.right(s1, 4);
    cout << "Правые 4 символа: ";
    s2.display(); 
    cout << endl;

    return 0;
}
