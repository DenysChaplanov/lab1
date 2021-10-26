#include <stdio.h>
#include <stdlib.h>


int* createNewArray(int size);
int* addElement(int position, int* array);
int* setValueToTheElement(int* array, int size);
int* recreateArray(int* a, int size);
void printArray(int* arr, int size);
int* insertElement(int index, int value, int size, int* array);
int* removeElement(int index, int size, int* array);
int getElement(int* a, int size, int ind);

int main() {
    int* a;
    int size = 0;
    int ch = 0;
    while (1) {
        printf("\n0. Exit\n"
            "1. Add element\n"
            "2. Insert element\n"
            "3. Amount of elements\n"
            "4. Remove element by index\n"
            "5. Set new value\n"
            "6. Get value\n"
            "7. Print array\n");
        scanf("%d", &ch);
        switch (ch) {
        case 0:
            exit(0);
        case 1:
        {
            if (size == 0) {
                a = createNewArray(1);
                size++;
                a = addElement(size - 1, a);
            }
            else {
                size++;
                a = recreateArray(a, size);
                a = addElement(size - 1, a);
            }
            break;
        }
        case 2:
        {
            printf("Enter index: \n");
            int ind = 0, value = 0;
            scanf("%d", &ind);
            printf("Enter value: \n");
            scanf("%d", &value);
            a = insertElement(ind, value, size, a);
            size += 1;
            break;
        }
        case 3:
        {
            printf("Size of list: %d\n", size);
            break;
        }
        case 4:
        {
            int ind = 0;
            printf("Enter index: \n");
            scanf("%d", &ind);
            a = removeElement(ind, size, a);
            size -= 1;
            break;
        }
        case 5:
        {
            a = setValueToTheElement(a, size);
            break;
        }
        case 6:
        {
            printf("\nEnter element's index: ");
            int index = 0;
            scanf("%d", &index);
            if (getElement(a, size, index) != -1) {
                printf("Value: %d", getElement(a, size, index));
            }
            else {
                printf("Incorrect value\n");
            }
            break;
        }
        case 7:
        {
            printArray(a, size);
            break;
        }
        default:
        {
            printf("Unknown operation");
            break;
        }
        }
    }
    return 0;
}

int* insertElement(int index, int value, int size, int* array) {
    if (index >= 0 && index < size) {

        int* newarr = (int*)malloc((size + 1) * sizeof(int));
        for (int i = 0; i < index; i++) {
            newarr[i] = array[i];
        }
        newarr[index] = value;
        for (int i = index + 1; i < size + 1; i++) {
            newarr[i] = array[i - 1];
        }
        printArray(newarr, size + 1);
        free(array);
        return newarr;
    }
    else {
        printf("Incorrect index");
        return array;
    }
}

int* removeElement(int index, int size, int* array) {
    if (index >= 0 && index < size) {
        int* newarr = (int*)malloc((size - 1) * sizeof(int));
        for (int i = 0; i < index; i++) {
            newarr[i] = array[i];
        }
        for (int i = index; i < size - 1; i++) {
            newarr[i] = array[i + 1];
        }
        free(array);
        return newarr;
    }
    else {
        printf("Incorrect index");
        return array;
    }
}

int getElement(int* a, int size, int ind) {
    if (ind < size && ind >= 0) {
        return a[ind];
    }
    else {
        return -1;
    }
}

int* createNewArray(int size) {
    int* a = (int*)malloc(size * sizeof(int));
    return a;
}

int* recreateArray(int* a, int size) {
    int* newArray = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        newArray[i] = a[i];
    }
    free(a);
    return newArray;
}

int* addElement(int position, int* array) {
    int number = 0;
    printf("Enter value of the element: ");
    scanf("%d", &number);
    array[position] = number;
    return array;
}

void printArray(int* arr, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int* setValueToTheElement(int* array, int size) {
    printf("Enter index: ");
    int index;
    scanf("%d", &index);
    if (index >= 0 && index < size) {
        printf("Enter new value: ");
        int value;
        scanf("%d", &value);
        array[index] = value;
    }
    else {
        printf("Incorrect index");
    }
    return array;
}

