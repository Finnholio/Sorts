#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void mergeSort(int array[], int size);
void swap(int array[], int indexOne, int indexTwo);
void printArray(int array[], int size);

int main(void)
{
    int array[] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21

 };
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, size);

    printArray(array, size);
}

void mergeSort(int array[], int size)
{
    if (size == 2)
    {
        if (array[0] > array[1])
        {
            swap(array, 0, 1);
        }
    }
    else if (size != 1)
    {
        int half = size / 2;

        int array1[half];
        int array2[size - half];

        for (int i = 0; i < half; i++)
        {
            array1[i] = array[i];
        }

        for (int i = half; i < size; i++)
        {
            array2[i-half] = array[i];
        }

        mergeSort(array1, half);
        mergeSort(array2, size - half);

        int x = 0;
        int y = 0;

        for (int i = 0; i < size; i++)
        {
            if (array1[x] < array2[y] && x < half)
            {
                array[i] = array1[x];
                x++;
            }
            else if (y < size - half)
            {
                array[i] = array2[y];
                y++;
            }
        }
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