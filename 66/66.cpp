#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void getdata() {
        cout << "Введите день: ";
        cin >> day;
        cout << "Введите месяц: ";
        cin >> month;
        cout << "Введите год: ";
        cin >> year;
    }

    void putdata() const {
        cout << "Дата выпуска: " << day << "/" << month << "/" << year << endl;
    }
};

class Publication {
protected:
    string title;
    float price;

public:
    Publication(string t = "", float p = 0.0) : title(t), price(p) {}

    virtual void getdata() {
        cout << "Введите заголовок: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Заголовок: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pages;

public:
    Book(string t = "", float p = 0.0, int pg = 0) : Publication(t, p), pages(pg) {}

    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Страницы: " << pages << endl;
    }
};

class Type : public Publication {
private:
    float length;

public:
    Type(string t = "", float p = 0.0, float len = 0.0) : Publication(t, p), length(len) {}

    void getdata() override {
        Publication::getdata();
        cout << "Введите продолжительность аудиокниги (в минутах): ";
        cin >> length;
    }

    void putdata() const override {
        Publication::putdata();
        cout << "Длительность: " << length << " минуты" << endl;
    }
};

class Publication2 : public Publication {
private:
    Date releaseDate;

public:
    Publication2(string t = "", float p = 0.0) : Publication(t, p) {}

    void getdata() override {
        Publication::getdata();
        releaseDate.getdata();
    }

    void putdata() const override {
        Publication::putdata();
        releaseDate.putdata();
    }
};

class Book2 : public Publication2 {
private:
    int pages;

public:
    Book2(string t = "", float p = 0.0, int pg = 0) : Publication2(t, p), pages(pg) {}

    void getdata() override {
        Publication2::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Publication2::putdata();
        cout << "Страницы: " << pages << endl;
    }
};

class Type2 : public Publication2 {
private:
    float length;

public:
    Type2(string t = "", float p = 0.0, float len = 0.0) : Publication2(t, p), length(len) {}

    void getdata() override {
        Publication2::getdata();
        cout << "Введите продолжительность аудиокниги (в минутах): ";
        cin >> length;
    }

    void putdata() const override {
        Publication2::putdata();
        cout << "Длительность: " << length << " минуты" << endl;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    Book2 book;
    Type2 audioBook;

    cout << "Введите данные книги:" << endl;
    book.getdata();
    cout << "\nВведите данные аудиокниги:" << endl;
    audioBook.getdata();

    cout << "\nПодробности книги:" << endl;
    book.putdata();
    cout << "\nПодробности об аудиокниге:" << endl;
    audioBook.putdata();

    return 0;
}

