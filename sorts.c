#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef void (*sortf)(int *, int);

void insertionSort(int array[], int size);
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void mergeSort(int array[], int size);

void swap(int array[], int indexOne, int indexTwo);
void printArray(int array[], int size);

double timer(sortf sort);

int main(void)
{
    double bubbleTime = timer(bubbleSort);
    printf("Bubble Sort:      %f\n", bubbleTime);

    double selectionTime = timer(selectionSort);
    printf("Selection Sort:   %f\n", selectionTime);

    double insertionTime = timer(insertionSort);
    printf("Insertion Sort:   %f\n", insertionTime);

    double mergeTime = timer(mergeSort);
    printf("Merge Sort:       %f\n", mergeTime);
}

double timer(sortf sort)
{
    time_t start, end;

    int array[] = {5,7,0,9,90,98,34,56,21,65,68,1,78,2,45,67,87,6,4,100,32,54,67,98,43,64,87,123,760,321,451,673,34,223,21,322,928,45,12,21};
    int size = sizeof(array) / sizeof(array[0]);

    start = clock();
    sort(array, size);
    end = clock();

    double output = ((double) (end - start)) / CLOCKS_PER_SEC;
    return output;
}

void bubbleSort(int array[], int size)
{
    bool isSorted = true;
    while(isSorted)
    {
        isSorted = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array, i, i + 1);
                isSorted = true;
            }
        }
    }
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

void insertionSort(int array[], int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 1; i < size; i++)
    {
        bool needsSorting = true;
        int index = i;
        while (needsSorting)
        {
            if(array[index] < array[index - 1] && index > 0)
            {
                swap(array, index, index - 1);
                index--;
            }
            else
            {
                needsSorting = false;
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