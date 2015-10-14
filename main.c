#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

void printArray(int numRows, int numCols, int dpArray[numRows][numCols])
{
    int i, j;
    for(i = 0; i < numRows; i++)
    {
        for(j = 0; j < numCols; j++)
        {
            printf("%d ", dpArray[i][j]);
        }
        printf("\n");
    }
}


void printItems(int row, int col, int size, int dpTable[][size], int itemsWeight[])
{
    if(row == 0) return;
    if(dpTable[row][col] > dpTable[row-1][col])
    {
        printItems(row - 1, col - itemsWeight[row], size, dpTable, itemsWeight);
        printf("%d ", row);
    }
    else
    {
        printItems(row - 1, col, size, dpTable, itemsWeight);
    }
}

int makeTable(int numRows, int numCols, int itemsWeight[], int itemsValue[])
{
    int dpTable[numRows][numCols];
    memset(dpTable, 0, sizeof(dpTable[0][0]) * numRows * numCols);
    int i, j;
    for(i = 1; i < numRows; i++)
    {
        for(j = 1; j < numCols; j++)
        {
            if(itemsWeight[i] > j)
            {
                dpTable[i][j] = dpTable[i-1][j];
            }
            else
            {
                dpTable[i][j] = MAX(dpTable[i-1][j], dpTable[i-1][j - itemsWeight[i]] + itemsValue[i]);
            }
        }
        //printArray(numRows, numCols, dpTable);
    }
    printArray(numRows, numCols, dpTable);
    printf("\n");
    printItems(numRows - 1, numCols - 1, numCols, dpTable, itemsWeight);

}

int main()
{
    int itemsWeight[5] = {0, 2, 3, 4, 5};
    int itemsValue[5] = {0, 5, 7, 10, 13};
    int maxWeight = 10;
    makeTable(5, maxWeight + 1, itemsWeight, itemsValue);
}
