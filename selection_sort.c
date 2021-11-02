#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void selectionSort(int array[], int size);
void swap(int array[], int indexOne, int indexTwo);
void printArray(int array[], int size);

int main(void)
{
    int array[] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21};
    int size = sizeof(array) / sizeof(array[0]) ;

    selectionSort(array, size);

    printArray(array, size);
}

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int currentMin = array[i];
        int index = i;
        for (int j = i + 1; j < size; j++)
        {

            if (array[j] < currentMin)
            {
                currentMin = array[j];
                index = j;
            }
        }

        array[index] = array[i];
        array[i] = currentMin;
    }
}

void swap(int array[], int indexOne, int indexTwo)
{
    int temp;

    temp = array[indexOne];

    array[indexOne] = array[indexTwo];
    array[indexTwo] = temp;
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }

    printf("\n");
}