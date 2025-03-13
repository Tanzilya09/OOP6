#include <iostream>
using namespace std;

class SafeArray {
protected:
    int* arr;
    int size;
public:
    SafeArray(int size) : size(size) {
        arr = new int[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }

    int getValue(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return -1;
    }
};

class SafeHilo : public SafeArray {
private:
    int lowerBound, upperBound;
public:
    SafeHilo(int lower, int upper) : SafeArray(upper - lower + 1), lowerBound(lower), upperBound(upper) {}

    void setValue(int index, int value) {
        if (index >= lowerBound && index <= upperBound) {
            SafeArray::setValue(index - lowerBound, value);
        }
    }

    int getValue(int index) {
        if (index >= lowerBound && index <= upperBound) {
            return SafeArray::getValue(index - lowerBound);
        }
        return -1;
    }
};

int main() {
    setlocale(LC_ALL, ("rus"));
    SafeHilo arr(5, 10);
    arr.setValue(5, 100);
    cout << "Значение 5: " << arr.getValue(5) << endl;
    cout << "Значение 10: " << arr.getValue(10) << endl;
    return 0;
}
