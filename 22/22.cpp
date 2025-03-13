#include <iostream>
#include <string>
using namespace std;

enum PayPeriod { HOURLY, WEEKLY, MONTHLY };

class Employee {
protected:
    string name;
    double salary;
public:
    virtual void getdata() {
        cout << "Введите имя сотрудника: ";
        getline(cin, name);
        cout << "Введите зарплату: ";
        cin >> salary;
        cin.ignore();
    }

    virtual void putdata() {
        cout << "Имя: " << name << ", Зарплата: " << salary << endl;
    }
};

class Employee2 : public Employee {
protected:
    double compensation;
    PayPeriod period;
public:
    void getdata() override {
        Employee::getdata();
        cout << "Введите компенсацию: ";
        cin >> compensation;
        cout << "Введите период оплаты (0 для почасовой, 1 для еженедельной, 2 для ежемесячной): ";
        int periodChoice;
        cin >> periodChoice;
        period = static_cast<PayPeriod>(periodChoice);
        cin.ignore();
    }

    void putdata() override {
        Employee::putdata();
        cout << "Компенсация: " << compensation << ", Период оплаты: " << (period == HOURLY ? "Ежечасно" : period == WEEKLY ? "Еженедельно" : "Ежемесячно") << endl;
    }
};

int main() {
    setlocale(LC_ALL, ("rus")); 
    Employee2 employee;
    employee.getdata();
    employee.putdata();
    return 0;
}
