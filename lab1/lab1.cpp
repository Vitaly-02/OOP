#include <iostream>
#include <time.h>

using namespace std;

//ex1
int* genRandArray(int size, int maxValue) {
    int* arr = new int[size + 1];
    if (!arr) {
        cout << "Error mem";
        return nullptr;
    }
    arr[0] = size;
    for (int i = 1; i <= size; i++) {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int* Arr) {
    cout << Arr[0] << ": ";
    for (int i = 1; i <= Arr[0]; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int ex1() {
    int size = rand() % 10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete[] arr;
    cout << "\n";
    return 0;
}
//
//ex2
int** genRandMatrix(int size, int maxValue) {
    int** matr = new int* [size];
    if (!matr) {
        cout << "Error mem";
        return nullptr;
    }
    for (int i = 0; i < size; i++) {
        matr[i] = genRandArray(rand() % 10, maxValue);

    }
    return matr;
}

void printMatrix(int** matrix, int size) {
    int i = 0;
    for(int i = 0; i < size; i++) {
        print(matrix[i]);
        cout << "\n";
    }
}

int ex2() {
    int size = rand() % 10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    cout << size << "\n";
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    return 0;
}
//

int main() {
    srand(time(NULL));
    while(1) {
        cout << "To choose excersize enter 1 2 or 3 to exit\nYour choose: ";
        int ex = 0;
        cin >> ex;
        switch (ex) {
           case 1: {
                ex1();
               break;
            }
           case 2: {
               ex2();
              break;
           }
           case 3: {
               return 0;
                break;
           }
          default: {
              break;
          }
        }   
    }
    return 0;
}