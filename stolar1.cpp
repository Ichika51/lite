#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

int* bubble(int* string_2, int row) {
    int temp = 0;
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
    return string_2;
}

void printArray(int array[][5], const int row, const int column) {
    cout << "\n\nPoluchennyj massiv\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            cout << setw(4) << array[i][j];
        cout << endl;
    }
}

int minim_road(int row, int column, int array[][5] ) {
    int min_cell_right = 0;
    int min_cell_bot = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {//перебор всех ячеек
            if (i == 0 || j == 0) {
                if (i == 0)  array[i][j] = array[i][j] + array[i][j - 1];//если индекс строки 0, то двигаться только вправо по матрице
                else array[i][j] = array[i][j] + array[i - 1][j];//если индекс столбца 0, то двигаться только вниз по матрице
            }
            else {//если индекс не равен 0, то двигаться можно и вниз и вправо по матрице
                min_cell_right = array[i][j] + array[i][j - 1];
                min_cell_bot = array[i][j] + array[i - 1][j];
                if (min_cell_right < min_cell_bot)  array[i][j] = min_cell_right;
                else array[i][j] = min_cell_bot;
            }
            if (i == 0 && j == 0) array[i][j] = 9;
            min_cell_right = 0;
            min_cell_bot = 0;
        }
    }
    cout << "Массив с минимальными путями: " << endl;
    printArray(array, row, column);
    return array[row - 1][column - 1];
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    const int row = 4, column = 5;
    int array[row][column];
    ifstream f("array.txt");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            f >> array[i][j];
        }
    }
    //prinr array
    cout << "\n\nПолученный массив из файла:\n";
    printArray(array, row, column);
    //copy array
    int array1[row][column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array1[i][j] = array[i][j];
        }
    }
    ///////////////////////////////////////////sort 1 row///////////////////////////////////////////
    int* string = new int[column];
    for (int i = 0;i < column; i++) {
        string[i] = { array1[0][i] };
    }
    int temp = 0; // временная переменная для обмена элементов местами
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
        array1[0][i] = string[i];
    }
    cout << "\n\nПолученный массив после сортировки 1 строки:\n";
    printArray(array, row, column);
    delete[] string;
    ///////////////////////////////////////////sort 1 column///////////////////////////////////////////
    int* string_row = new int[row];
    for (int i = 0;i < row; i++) {
        string_row[i] = { array1[i][0] };
    }

    string_row = bubble(string_row, row);
    for (int i = 0; i < row; i++) {
        array1[i][0] = string_row[i];
    }
    cout << "\n\nПолученный массив после сортировки 1 колонки:\n";
    printArray(array, row, column);
    ///////////////////////////////////////////sort diagonal top lef to bottom right///////////////////////////////////////////
    int p = 0;
    if (column > row) p = row;
    else p = column;
    int* string_1 = new int[p];
    for (int i = 0;i < p; i++) {
        string_1[i] = { array1[i][i] };
    }
    // Сортировка массива пузырьком
    string_1 = bubble(string_1, row);
    for (int i = 0; i < p; i++) {
        array1[i][i] = string_1[i];
    }
    cout << "\n\nПолученный массив после сортировки диагонали(с левого верхнего в правый нижний угол)\n";
    printArray(array, row, column);
    ///////////////////////////////////////////sort diagonal bottom left to top right///////////////////////////////////////////
    int* string_2 = new int[p];
    for (int i = 0;i < p; i++) {
        string_2[i] = { array1[row - 1 - i][i] };
    }
    // Сортировка массива пузырьком
    string_2 = bubble(string_2, row);

    for (int i = 0; i < p; i++) {
        array1[row - 1 - i][i] = string_2[i];
    }
    cout << "\n\nПолученный массив после сортировки диагонали(с левого нижнего в правый верхний угол)\n";
    printArray(array, row, column);
    //output array
    cout << "-------------------------------" << endl;
    printArray(array, row, column);
    //min road
    cout << "Min road = ";
    int max_roads = row * column;
    cout << "Максимальное количество путей =" << max_roads << endl;
    cout << "-------------------------------" << endl;
    printArray(array, row, column);
    int min = minim_road(row,column,array);
    cout << "Минимальный путь из левого верхнего угла в нижний правый = " << min << endl;
    return 0;
}
