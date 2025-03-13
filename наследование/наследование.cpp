#include <iostream>
#include <string>
using namespace std;

enum DiskType { CD, DVD };

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите заголовок: ";
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
        cin.ignore();
    }

    void putdata() {
        cout << "Заголовок: " << title << ", цена: " << price << endl;
    }
};

class Disk : public Publication {
private:
    DiskType type;
public:
    void getdata() {
        Publication::getdata();
        char diskType;
        cout << "Введите тип диска (c для CD, d для DVD): ";
        cin >> diskType;
        cin.ignore();
        type = (diskType == 'c') ? CD : DVD;
    }

    void putdata() {
        Publication::putdata();
        cout << "Тип диска: " << (type == CD ? "CD" : "DVD") << endl;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    Disk disk;
    disk.getdata();
    disk.putdata();

    return 0;
}

