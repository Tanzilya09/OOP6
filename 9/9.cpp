#include <iostream>
#include <iomanip>
using namespace std;

class Sterling {
protected:
    int funt;
    int pence;

public:
    Sterling(int p = 0, int pe = 0) : funt(p), pence(pe) {
        normalize();
    }

    void getInput() {
        cout << "Введите фунты: ";
        cin >> funt;
        cout << "Введите пенсы: ";
        cin >> pence;
        normalize();
    }

    void normalize() {
        if (pence >= 100) {
            funt += pence / 100;
            pence %= 100;
        }
        else if (pence < 0) { 
            funt -= (-pence) / 100 + 1;
            pence = 100 - (-pence) % 100;
        }
    }

    void display() const {
        cout << "£" << funt << "." << setw(2) << setfill('0') << pence;
    }

    Sterling operator+(const Sterling& other) const {
        int totalPence = (funt * 100 + pence) + (other.funt * 100 + other.pence);
        return Sterling(totalPence / 100, totalPence % 100);
    }

    Sterling operator-(const Sterling& other) const {
        int totalPence1 = funt * 100 + pence;
        int totalPence2 = other.funt * 100 + other.pence;
        int result = totalPence1 - totalPence2;
        return Sterling(result / 100, result % 100);
    }

    Sterling operator*(int multiplier) const {
        int totalPence = (funt * 100 + pence) * multiplier;
        return Sterling(totalPence / 100, totalPence % 100);
    }

    Sterling operator/(int divisor) const {
        int totalPence = (funt * 100 + pence) / divisor;
        return Sterling(totalPence / 100, totalPence % 100);
    }
};

class Sterfrac : public Sterling {
private:
    int eighths;

public:
    Sterfrac(int p = 0, int pe = 0, int e = 0) : Sterling(p, pe), eighths(e) {
        normalize();
    }

    void getInput() {
        Sterling::getInput();
        cout << "Введите восьмые части пенни: ";
        cin >> eighths;
        normalize();
    }

    void normalize() {
        if (eighths >= 8) {
            pence += eighths / 8;
            eighths %= 8;
        }
        else if (eighths < 0) { 
            pence -= (-eighths) / 8 + 1;
            eighths = 8 - (-eighths) % 8;
        }
        Sterling::normalize();
    }

    void display() const {
        Sterling::display();
        if (eighths > 0) {
            cout << " - " << eighths << "/8";
        }
    }

    Sterfrac operator+(const Sterfrac& other) const {
        int totalEighths = (funt * 100 + pence) * 8 + eighths;
        totalEighths += (other.funt * 100 + other.pence) * 8 + other.eighths;
        return Sterfrac(totalEighths / (8 * 100), (totalEighths / 8) % 100, totalEighths % 8);
    }

    Sterfrac operator-(const Sterfrac& other) const {
        int totalEighths1 = (funt * 100 + pence) * 8 + eighths;
        int totalEighths2 = (other.funt * 100 + other.pence) * 8 + other.eighths;
        int result = totalEighths1 - totalEighths2;
        return Sterfrac(result / (8 * 100), (result / 8) % 100, result % 8);
    }

    Sterfrac operator*(int multiplier) const {
        int totalEighths = ((funt * 100 + pence) * 8 + eighths) * multiplier;
        return Sterfrac(totalEighths / (8 * 100), (totalEighths / 8) % 100, totalEighths % 8);
    }

    Sterfrac operator/(int divisor) const {
        int totalEighths = ((funt * 100 + pence) * 8 + eighths) / divisor;
        return Sterfrac(totalEighths / (8 * 100), (totalEighths / 8) % 100, totalEighths % 8);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Sterfrac sf1, sf2;

    cout << "Введите первую сумму в фунтах стерлингов:" << endl;
    sf1.getInput();
    cout << "Введите вторую сумму в фунтах стерлингов:" << endl;
    sf2.getInput();

    cout << "\nПервая сумма в фунтах стерлингов: ";
    sf1.display();
    cout << endl;

    cout << "Вторая сумма в фунтах стерлингов: ";
    sf2.display();
    cout << endl;

    Sterfrac resultAdd = sf1 + sf2;
    cout << "\nРезультат сложения: ";
    resultAdd.display();
    cout << endl;

    Sterfrac resultSub = sf1 - sf2;
    cout << "\nРезультат вычитания: ";
    resultSub.display();
    cout << endl;

    int multiplier = 2;
    Sterfrac resultMul = sf1 * multiplier;
    cout << "\nУмножение на " << multiplier << " результат: ";
    resultMul.display();
    cout << endl;

    int divisor = 3;
    Sterfrac resultDiv = sf1 / divisor;
    cout << "\nДеление на " << divisor << " результат: ";
    resultDiv.display();
    cout << endl;

    return 0;
}

