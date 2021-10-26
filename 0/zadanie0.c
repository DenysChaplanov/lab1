#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct PointStruct {
    int xPoint;
    int yPoint;
    int zPoint;
    int weight;
} PointStruct;

PointStruct* createPoint();

int findMinimumWeightPoint();
int distance(PointStruct *a, PointStruct *b);

void printPoints();
void deletePointNearbyIndex(int index);


PointStruct array = NULL;
int amount = 15;

int main () {
    srand(time(NULL));
    int i;
    array = (PointStruct) malloc (amount * sizeof(PointStruct));

    for (i = 0; i < amount; i++) {
        array[i] = createPoint();
    }

    while (amount > 1) {
        printPoints();
        deletePointNearbyIndex(findMinimumWeightPoint());
    }
    printPoints();
    return 0;
}

PointStruct* createPoint() {
    PointStruct* poin = (PointStruct*) malloc (sizeof(PointStruct));
    poin->xPoint = rand() % 100 - 50;
    poin->yPoint = rand() % 100 - 50;
    poin->zPoint = rand() % 100 - 50;
    poin->weight = rand()%100;
    return poin;
}
int findMinimumWeightPoint() {
    int index = 0, i;
    double temp = array[0]->weight;

    for (i = 1; i < amount; i++) {
        if (array[i]->weight < temp) {
            temp = array[i]->weight;
            index = i;
        }
    }

    return index;
}

void printPoints() {
    int i;
    printf("\n");
    for (i = 0; i < amount; i++) {
        printf("\n%d.\tx: %d\ty: %d\tz: %d\tweight: %d", i+1, array[i]->xPoint, array[i]->yPoint, array[i]->zPoint, array[i]->weight);
    }
    printf("\n");
}

void deletePointNearbyIndex(int index) {
    PointStruct *temp = array[index];
    int i, mark = 0, tmp;
    int res = distance(temp, array[0]);

    for (i = 1; i < amount; i++) {
        tmp = distance(temp, array[i]);
        if (tmp <= res && i != index) {
            res = tmp;
            mark = i;
        }
    }
    array[mark]->weight += temp->weight;
    for (i = index; i < amount - 1; i++) {
        array[i] = array[i + 1];
    }
    amount--;
    array = (PointStruct**) realloc (array, amount * sizeof(PointStruct));
}

int distance(PointStruct *a, PointStruct *b) {
    return sqrt(pow(a->xPoint - b->xPoint, 2) + pow(a->yPoint - b->yPoint, 2) + pow(a->zPoint - b->zPoint, 2));
}