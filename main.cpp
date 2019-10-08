//
// Created by Zahar on 07.09.2019.
//

#include <iostream>
#include <ctime>

using namespace std;

void arrayPrinter(long long unsigned int *array, int size) {
    cout << "Row " << size << ": ";
    for (int k = 0; k <= size; k++) {
        cout << array[k] << " ";
    }
}

int main() {
    int rows;
    cout << "Rows in Pascal Triangle: ";
    cin >> rows;

    // Start the timer
    clock_t start_time = clock();

    auto *current_row = new long long unsigned int[rows];
    auto *next_row = new long long unsigned int[rows];

    // Set initial values
    next_row[0] = 1;
    current_row[0] = 1;

    for (int i = 1; i < rows; i++) {
        next_row[i] = 0;
        current_row[i] = 0;
    }

    for (int i = 0; i <= rows; i++) {
        // Fill the N line on the previous one
        for (int j = 0; j < rows; j++) {
            next_row[j + 1] = current_row[j] + current_row[j + 1];
        }
        // Print the N line from i elements
        arrayPrinter(current_row, i);

        for (int l = 1; l < rows; l++) {
            current_row[l] = next_row[l];
        }
        cout << endl;
    }
    cout << endl;

    delete[] next_row;
    delete[] current_row;

    clock_t end_time = clock();
    cout << end_time - start_time <<  "ms" <<endl;

    return 0;
}