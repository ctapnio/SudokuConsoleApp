/**
 * Assignment#1 - Sudoku Grid Program
 * Written by: Christian Tapnio - 991359879
 * Date written: 2020-09-23
 * Header File
 */

#ifndef CHRISTIANTAPNIOASSIGN1_A1FUNCTIONS_H
#define CHRISTIANTAPNIOASSIGN1_A1FUNCTIONS_H


#define SIZE 9
#define BUFFER_SIZE 120
#define RANGE 8
#define OFFSET 1

void displayGrid(int arr[][9]);
void userFillRow(int arr[][9]);
void fillRemainingRows(int arr[][9]);
int checkGrid(int arr[][9]);
void gridValidity(int valid);


#endif //CHRISTIANTAPNIOASSIGN1_A1FUNCTIONS_H
