#include <iostream>
using namespace std;

int* arrayCreate(int n) {
    int* arr = new int[n];
    int numb, i = 0;
    while (numb != 0) {
        cin >> numb;
        arr[i] = numb;
        i++;
    }
    return arr;
}

int len(int* arr) {
    int i = 0;
    while (arr[i] != 0) {
        i++;
    }
    return i;;
}

int* new_arrayCreate(int* arr, int& size) {
    int counter = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] < 5) {
            int tmp = arr[counter];
            arr[counter] = arr[i];
            arr[i] = tmp;
            counter++;
        }
    size = size - counter;
    int* newarr = new int[size];
    for (int i = 0; i < size; i++)
        newarr[i] = arr[i + counter];

    return newarr;

}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } cout << endl << size;
}


void arrayDelete(int* arr) {
    delete[] arr;
}

int main() {
    int n = 100000;
    int* arr = arrayCreate(n);
    int size = len(arr);
    int* newarr = new_arrayCreate(arr, size);
    int newsize = len(newarr);
    print(newarr, newsize);
    arrayDelete(arr);
    arrayDelete(newarr);
    return 0;
}