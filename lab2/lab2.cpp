﻿#include <iostream>
#include <time.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

#define SIZE 6
//ex1
void random(int** temp) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            temp[i][j] = rand() % 255;
        }

    }

}

void print(int** temp) {
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
    int** matrix = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }

    cout << "matrix:";
    random(matrix);
    print(matrix);

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
    // 0 нечет - вверх и влево
    // 1 чет - вниз и вправо
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
                j++;
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
                j--;
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
        i++;
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
            //ex2();
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