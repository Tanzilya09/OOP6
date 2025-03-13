#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string position;

public:
    Employee(string n = "", string p = "") : name(n), position(p) {}

    virtual void getdata() {
        cout << "Введите имя сотрудника: ";
        getline(cin, name);
        cout << "Введите должность сотрудника: ";
        getline(cin, position);
    }

    virtual void putdata() const {
        cout << "Имя: " << name << endl;
        cout << "Позиция: " << position << endl;
    }
};

class Employee2 : public Employee {
protected:
    double compensation;
    enum Period { Hourly, Weekly, Monthly } paymentPeriod;

public:
    Employee2(string n = "", string p = "", double comp = 0.0, Period period = Monthly)
        : Employee(n, p), compensation(comp), paymentPeriod(period) {}

    void getdata() override {
        Employee::getdata();
        cout << "Введите компенсацию: ";
        cin >> compensation;
        cout << "Введите период оплаты (1 для почасовой, 2 для еженедельной, 3 для ежемесячной): ";
        int period;
        cin >> period;
        paymentPeriod = static_cast<Period>(period - 1);
    }

    void putdata() const override {
        Employee::putdata();
        cout << "Компенсация: " << compensation << endl;
        cout << "Период оплаты: ";
        switch (paymentPeriod) {
        case Hourly: cout << "Ежечасно"; break;
        case Weekly: cout << "Еженедельно"; break;
        case Monthly: cout << "Ежемесячно"; break;
        }
        cout << endl;
    }
};

class Executive : public Employee2 {
private:
    double annualBonus;
    int stockShares;

public:
    Executive(string n = "", string p = "", double comp = 0.0, Period period = Monthly, double bonus = 0.0, int shares = 0)
        : Employee2(n, p, comp, period), annualBonus(bonus), stockShares(shares) {}

    void getdata() override {
        Employee2::getdata();
        cout << "Введите годовой бонус: ";
        cin >> annualBonus;
        cout << "Введите количество акций: ";
        cin >> stockShares;
    }

    void putdata() const override {
        Employee2::putdata();
        cout << "Годовой бонус: " << annualBonus << endl;
        cout << "Акции: " << stockShares << endl;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    Executive exec;

    cout << "Введите исполнительные данные:" << endl;
    exec.getdata();

    cout << "\nИсполнительные данные:" << endl;
    exec.putdata();

    return 0;
}

