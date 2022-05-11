#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

void printArray(int* array[][4], const int row, const int column) {
    cout << "\n\nPoluchennyj massiv\n";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
}

int main() {
    const int row = 4, column = 5;
    int array[row][column];
    ifstream f("array.txt");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            f >> array[i][j];
        }
    }
    //prinr array
    cout << "\n\nPoluchennyj massiv\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    ///////////////////////////////////////////sort 1 row///////////////////////////////////////////
    int* string = new int[column];
    for (int i = 0;i < column; i++) {
        string[i]={array[0][i]};
    }
    int temp=0; // временная переменная для обмена элементов местами
     // Сортировка массива пузырьком
    for (int i = 0; i < column - 1; i++) {
        for (int j = 0; j < column - i - 1; j++) {
            if (string[j] > string[j + 1]) {
                // меняем элементы местами
                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < column; i++) {
        array[0][i] = string[i];
    }
    cout << "\n\nPoluchennyj massiv posle sortirovki 1 row\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    delete[] string;
    ///////////////////////////////////////////sort 1 column///////////////////////////////////////////
    int* string_row = new int[row];
    for (int i = 0;i < row; i++) {
        string_row[i] = { array[i][0] };
    }
     // Сортировка массива пузырьком
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (string_row[j] > string_row[j + 1]) {
                // меняем элементы местами
                temp = string_row[j];
                string_row[j] = string_row[j + 1];
                string_row[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        array[i][0] = string_row[i];
    }
    cout << "\n\nPoluchennyj massiv posle sortirovki 1 column\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    ///////////////////////////////////////////sort diagonal top lef to bottom right///////////////////////////////////////////
    int p = 0;
    if (column > row) p = row;
    else p = column;
    int* string_1 = new int[p];
    for (int i = 0;i < p; i++) {
        string_1[i] = { array[i][i] };
    }
    // Сортировка массива пузырьком
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (string_1[j] > string_1[j + 1]) {
                // меняем элементы местами
                temp = string_1[j];
                string_1[j] = string_1[j + 1];
                string_1[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        array[i][i] = string_1[i];
    }
    cout << "\n\nPoluchennyj massiv posle sortirovki 1 diagonal\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < p; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    ///////////////////////////////////////////sort diagonal bottom right to top left///////////////////////////////////////////
    int* string_2 = new int[p];
    for (int i = 0;i < p; i++) {
        string_2[i] = { array[row-i][row-i] };
    }
    // Сортировка массива пузырьком
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            if (string_2[j] > string_2[j + 1]) {
                // меняем элементы местами
                temp = string_2[j];
                string_2[j] = string_2[j + 1];
                string_2[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < p;i++) {
        cout << "sort: " << string_2[i] << endl;
    }
    for (int i = 0; i < p; i++) {
        array[row-i][row-i] = string_2[i];
    }
    cout << "\n\nPoluchennyj massiv posle sortirovki 2 diagonal\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < p; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
    
    return 0;
}
