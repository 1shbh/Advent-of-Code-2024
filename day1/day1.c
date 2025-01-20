#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int size);


int main(){

    FILE *fhandle = fopen("input.txt", "r");

    if (fhandle == NULL) {
        perror("Error opening file");
        return 1;
    }

    int *arr1 = malloc(10 * sizeof(int));
    int *arr2 = malloc(10 * sizeof(int));
    int number;
    int capacity = 10;
    int ind1 = 0;
    int ind2 = 0;
    int flag = 0;


    while (fscanf(fhandle, "%d", &number)!=EOF) {
        if (ind1 == capacity) {
            capacity += 10;
            arr1 = realloc(arr1, capacity * sizeof(int));
            arr2 = realloc(arr2, capacity * sizeof(int));
            if (arr1==NULL || arr2 ==NULL){
                perror("Memory allocation failed");
                fclose(fhandle);
                return 1;
            }
        }
        if (flag == 0) {
            arr1[ind1++] = number;
            flag = 1;
        }
        else {
            arr2[ind2++] = number;
            flag = 0;
        }
    }

    bubblesort(arr1, ind1);
    bubblesort(arr2, ind2);

    int sum = 0;
    int diff;

    for (int i = 0; i < ind1; i++){
        diff = (arr1[i] > arr2[i]) ? (arr1[i]-arr2[i]) : (arr2[i]-arr1[i]); 
        sum += diff;
    }

    printf("%d \n", sum);

    free(arr1);
    free(arr2);



    return 0;
}

void bubblesort(int arr[], int size) {
    int temp;
    for (int i = 0 ; i < size -1 ; i++){
        for (int j = 0; j < size - 1 - i ; j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}