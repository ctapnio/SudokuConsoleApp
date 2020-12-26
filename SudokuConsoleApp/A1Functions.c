/**
 * Assignment#1 - Sudoku Grid Program
 * Written by: Christian Tapnio - 991359879
 * Date written: 2020-09-23
 * Source File
 */
#include "A1Functions.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void displayGrid(int arr[9][9]) {
    puts("---------------Sudoku Grid---------------");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d\t", arr[i][j]);
        }
        puts("");
    }
}//end of displayGrid function

void userFillRow(int arr[][9]) {
    for (int col = 0; col < 2; col++) {//start of for-loop1
        char buff[BUFFER_SIZE];
        int cnt = 0;

        printf("Enter col %d of your Sudoku grid,\nUse Space/Tab/Return"
               "key to enter the next values\nand press 'Return' after"
               "entering nine integers.\nRemember, to make a valid col "
               "of Sudoku grid,\nall integers should be distinct and range"
               "from 1 to 9\n", col + 1);

        //Data validation
        while (cnt != 9) {//start of while-loop1
            fgets(buff, sizeof(buff), stdin);
            cnt = sscanf(buff, "%d%d%d%d%d%d%d%d%d", &arr[col][0], &arr[col][1], &arr[col][2],
                         &arr[col][3], &arr[col][4], &arr[col][5], &arr[col][6], &arr[col][7],
                         &arr[col][8]);
            if (cnt != 9) {//input count check
                puts("Enter exactly nine INTEGERS separated by Space/Tab followed "
                     "by Enter key to end\nUse Space/TabReturn key to enter the next "
                     "values\nand press 'Return' after entering nine integers.\nRemember,"
                     " to make a valid col of Sudoku grid, all integers should be distinct"
                     " and range from 1 to 9\n");
                cnt = 0;
                continue;
            }
            for (int row = 0; row < SIZE; row++) {//start of for-loop2 checking if numbers in row are repeated
                for (int dex = 0; dex < row; dex++) {//start of for-loop3
                    if (arr[col][row] == arr[col][dex]) {
                        puts("Enter nine distinct integers, No duplicated please!\nUse "
                             "Space/TabReturn key to enter the next values\nand press 'Return'"
                             " after entering nine integers.\nRemember, to make a valid col of"
                             " Sudoku grid,\nall integers should be distinct and range from 1 to 9\n");
                        cnt = 0;
                    }
                }//end of for-loop3
                if (arr[col][row] < 1 || arr[col][row] > 9) {//out of range check
                    puts("One of more entries are outside the range of 1 to 9!\nUse "
                         "Space/Tab/Return key to enter the next values\nand press 'Return' after"
                         " entering nine integers.\nRemember, to make a valid col of Sudoku grid,"
                         "\nall integers should be distinct and range from 1 to 9\n");
                    cnt = 0;
                }
            }//end of for-loop2
        }//end of while-loop1
    }//end of for-loop1
}//end of userFillRow function

void fillRemainingRows(int arr[][SIZE]) {
    srand(time(NULL));
    for (int row = 2; row < 9; row++)//row = 0 <-- testing
        for (int col = 0; col < 9; col++) {
            arr[row][col] = rand() % (RANGE + 1) + OFFSET;
            for (int dex = 0; dex < col; dex++){
                if (arr[row][col] == arr[row][dex]){
                    col--;
                }
            }
        }
}

int checkGrid(int arr[][9]) {
    //checking if values are repeated in the row
    for (int col = 0; col < 2; col++) {
        for (int row = 0; row < SIZE; row++) {
            for (int dex = 0; dex < row; dex++) {
                if (arr[col][row] == arr[col][dex]) {
                    return 0;
                }
            }
        }
    }
    //checking if values are repeated in the column
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            for (int dex = 1; dex < col; dex++) {
                if (arr[col][row] == arr[dex][row]) {
                    return 0;
                }
            }
        }
    }
    //checking if values are repeated in the block
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            int colBlock = (int) (col / 3) * 3;
            int rowBlock = (int) (row / 3) * 3;
            for (int dex = colBlock; dex < colBlock + 3; dex++) {
                for (int i = rowBlock; i < rowBlock + 3; i++) {
                    if ((col != dex || row != i) && (arr[col][row] == arr[dex][i])) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void gridValidity(int valid) {
    if (valid == 1) {
        puts("Grid is valid");
    } else {
        puts("Grid is invalid");
    }
}