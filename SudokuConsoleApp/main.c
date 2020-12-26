/**
 * Sudoku Grid Console Appication
 * Written by: Christian Tapnio - 991359879
 * Date written: 2020-09-23
 * C program that checks the validity of a Sudoku solution
 * User must input two rows of numbers ranging from 1 to 9, spaced/tabbed separated
 */
#include <stdio.h>
#include "A1Functions.h"


int main() {
    int validGrid[][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                          {6, 7, 2, 1, 9, 5, 3, 4, 8},
                          {1, 9, 8, 3, 4, 2, 5, 6, 7},
                          {8, 5, 9, 7, 6, 1, 4, 2, 3},
                          {4, 2, 6, 8, 5, 3, 7, 9, 1},
                          {7, 1, 3, 9, 2, 4, 8, 5, 6},
                          {9, 6, 1, 5, 3, 7, 2, 8, 4},
                          {2, 8, 7, 4, 1, 9, 6, 3, 5},
                          {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    int arr[][9] = {0};
    //test case for given grid
    displayGrid(validGrid);
    gridValidity(checkGrid(validGrid));

    //test case for user defined grid
    userFillRow(arr);
    fillRemainingRows(arr);
    displayGrid(arr);
    gridValidity(checkGrid(arr));


    return 0;
}//end of main function
