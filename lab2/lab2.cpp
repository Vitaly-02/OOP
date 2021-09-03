#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

#define SIZE 5

void print(int* Arr);
void printMatrix(int** matrix, int size);
//int* genRandArray(int size, int maxValue);
//int** genRandMatrix(int size, int maxValue);

//ex1
int* genRandArrayEx1(int size, int maxValue) {
    int* arr = new int[size + 1];
    if (!arr) {
        cout << "Error mem";
        return nullptr;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

int** genRandMatrixEx1(int size, int maxValue) {     //vmesto random()
    int** matr = new int* [size];
    if (!matr) {
        cout << "Error mem";
        return nullptr;
    }
    for (int i = 0; i < size; i++) {
        matr[i] = genRandArrayEx1(size, maxValue);
    }
    return matr;
 }

void printEx1(int** temp) {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(4) << temp[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int ex1() {
    srand(time(NULL));
    // initialization
    int** matrix = genRandMatrixEx1(SIZE, 300);
    cout << "matrix:";
    printEx1(matrix);

    int* massive = new int[SIZE * SIZE];

    cout << "a) по правым диагоналям, начиная с правого верхнего элемента\n";
    // ???
    for (int i = 0; i < SIZE; i++) {
        massive[i] = matrix[i][SIZE - 1 - i];
        cout << setw(4) << massive[i];
    }
    cout << "\nb) по левым диагоналям, начиная с левого верхнего элемента\n";
    // ???
    for (int i = 0; i < SIZE; i++) {
        massive[i] = matrix[i][i];
        cout << setw(4) << massive[i];
    }
    cout << "\nc) по спирали, начиная с центрального элемента\n";
    // good
    int count = 1;
    // кол-во шагов по прямой
    int i, j;
    bool direction = 0;
    // 0 нечет - вверх и влево   вверх и вправо
    // 1 чет - вниз и вправо     вниз и влево
    i = j = SIZE / 2;
    // центр 
    int index = 0;
    // index of massive
    massive[index] = matrix[i][j];
    cout << setw(4) << massive[index];
    index++;
    while (count < SIZE) {

        //if(count % SIZE == 0 && count != 0) {
        //    cout << "\n";
        //}

        if (direction) {
            for (int k = 0; k < count; k++) {
                i++;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }
            for (int k = 0; k < count; k++) {
                j--;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;

            }

        }
        else {
            for (int k = 0; k < count; k++) {
                i--;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }
            for (int k = 0; k < count; k++) {
                j++;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }

        }
        count++;
        direction = !direction;
    }
    //last 1 prohod
    count = SIZE - 1;
    for (int k = 0; k < count; k++) {
        i--;
        massive[index] = matrix[i][j];
        cout << setw(4) << massive[index];
        index++;
    }
    /*for(int k = 0; k < count; k++) {
                j++;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
    }
    for(int k = 0; k < count; k++) {
                i--;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
    }
    */
    cout << "\nd) по спирали, начиная с левого верхнего элемента\n";
    // good
    //int count = 1;
    // кол-во шагов по прямой
    //int i, j;
    //bool direction = 1; 
    // 0 нечет - вправо и вверх
    // 1 чет - влево и вниз
    direction = 1;
    i = j = 0;
    // первый эл 
    index = 0;
    // index of massive
    massive[index] = matrix[i][j];
    cout << setw(4) << massive[index];
    index++;

    //first 3 prohoda
    count = SIZE - 1;
    for (int k = 0; k < count; k++) {
        i++;
        massive[index] = matrix[i][j];
        cout << setw(4) << massive[index];
        index++;
    }
    for (int k = 0; k < count; k++) {
        j++;
        massive[index] = matrix[i][j];
        cout << setw(4) << massive[index];
        index++;
    }
    for (int k = 0; k < count; k++) {
        i--;
        massive[index] = matrix[i][j];
        cout << setw(4) << massive[index];
        index++;
    }
    count--;
    while (count > 0) {

        //if(count % SIZE == 0 && count != 0) {
        //    cout << "\n";
        //}

        if (direction) {
            for (int k = 0; k < count; k++) {
                j--;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }
            for (int k = 0; k < count; k++) {
                i++;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;

            }

        }
        else {
            for (int k = 0; k < count; k++) {
                j++;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }
            for (int k = 0; k < count; k++) {
                i--;
                massive[index] = matrix[i][j];
                cout << setw(4) << massive[index];
                index++;
            }

        }
        count--;
        direction = !direction;
    }


    // delete mem
    for (int i = 0; i < SIZE; i++) {
        delete[] matrix[i];
    }
    return 0;
}
//
//ex2 

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
    //cout << Arr[0] << ": ";
    for (int i = 0; i < Arr[0]; i++) {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int** genRandMatrix(int size, int maxValue) {
    int** matr = new int* [size];
    if (!matr) {
        cout << "Error mem";
        return nullptr;
    }
    for (int i = 0; i < size; i++) {
        matr[i] = genRandArray(rand() % 10 + 1, maxValue);

    }
    return matr;
}

void printMatrix(int** matrix, int size) {

    for (int i = 0; i < size; i++) {
        print(matrix[i]);
        //cout << "\n";
    }
}

int ex2() {
    int size = rand() % 10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    cout << "Amount of lines in matrix = " << size << "\n";
    printMatrix(matrix, size);
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    return 0;
}
//

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    while (1) {
        cout << "\nTo choose excersize enter 1 2 or 3 to exit\nYour choose: ";
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