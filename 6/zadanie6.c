#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <locale.h>

int **CreateMatrix(int n,int m);
int printMatrix(int n, int m, int **arr);
int **MatrixSum(int **arrA, int **arrB, int nA, int mA, int nB, int mB);
int **MatrixDifference(int **arrA, int **arrB, int nA, int mA, int nB, int mB);
int **MatrixMultiplication(int **arrA, int nA, int mA);
int **TwoMatrixMultiplication(int **arrA, int **arrB, int nA, int mA, int nB, int mB);
int **ResizeMatrix(int **arrA, int nA, int mA, int n, int m);
int saveMatrix(int** A,char* fileName, int rows, int cols);
int** loadMatrix(char* fileName);

int main(){
    srand(time(0));
    int nA,mA,nB,mB;
    int **arrA, **arrB, **arrC;
    int ch, chos, temp, i, j;
    while (1){
        printf("\n1.Create matrix\n2.Remove matrix\n3.Set value to element\n"
               "4.Get value by index\n5.Print matrix\n6.Save matrix\n"
               "7.Matrix arithmetic\n8.Resize matrix\n9.Save matrix\n"
               "10.Read matrix from file\n");
        scanf("%d",&ch);
        switch (ch) {
            case 0:
                exit(0);
            case 1:
                printf("Matrix A. Enter amount of rows: ");
                scanf("%d",&nA);
                printf("Matrix A. Enter amount of columns: ");
                scanf("%d",&mA);
                arrA = CreateMatrix(nA,mA);
                printf("Matrix B. Enter amount of rows: ");
                scanf("%d",&nB);
                printf("Matrix B. Enter amount of columns: ");
                scanf("%d",&mB);
                arrB = CreateMatrix(nB,mB);
                break;
            case 2:
                free(arrA);
                free(arrB);
                break;
            case 3:
                printf("Which matrix? 1 - A, 2 - B");
                scanf("%d",&chos);
                printf("Enter value: ");
                scanf("%d",&temp);
                printf("Enter row-number: ");
                scanf("%d",&i);
                printf("Enter column-number: ");
                scanf("%d",&j);
                if(chos == 1){
                    arrA[i][j] = temp;
                } else{
                    arrB[i][j] = temp;
                }
                break;
            case 4:
                printf("Which matrix? 1 - A, 2 - B");
                scanf("%d",&chos);
                printf("Enter row-number: ");
                scanf("%d",&i);
                printf("Enter column-number: ");
                scanf("%d",&j);
                if(chos == 1){
                    printf("\n%d\n",arrA[i][j]);
                } else{
                    printf("\n%d\n",arrB[i][j]);
                }
                break;
            case 5:
                printf("Which matrix? 1 - A, 2 - B");
                scanf("%d",&chos);
                if(chos == 1){
                    printMatrix(nA,nB,arrA);
                } else{
                    printMatrix(mA,mB,arrB);
                }
                break;
            case 7:
                printf("\nChoose an operation: \n1.Sum\n2.Difference\n"
                       "3. Multiplication by number\n4. Matrix multiplication");
                scanf("%d",&chos);
                if(chos == 1){
                    arrC = MatrixSum(arrA,arrB,nA,mA,nB,mB);
                } else if(chos == 2){
                    arrC = MatrixDifference(arrA,arrB,nA,mA,nB,mB);
                } else if(chos == 3){
                    arrA = MatrixMultiplication(arrA,nA,mA);
                } else{
                    arrC = TwoMatrixMultiplication(arrA,arrB,nA,mA,nB,mB);
                }
                break;
            case 8:
                printf("Enter new amount of rows: ");
                scanf("%d",&i);
                printf("Enter new amount of columns: ");
                scanf("%d",&j);
                arrA = ResizeMatrix(arrA,nA,mA,i,j);
                nA = i;
                mA = j;
                break;
            case 9:
                saveMatrix(arrA,"matrixA.txt",nA,mA);
                break;
            case 10:
                arrA = loadMatrix("matrixA.txt");
                break;
        }
    }
    return 0;
}

int **ResizeMatrix(int **arrA, int nA, int mA, int n, int m){
    int **arrC = CreateMatrix(n,m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arrC[i][j] = arrA[i][j];
        }
    }
    return arrC;
}


int saveMatrix(int** A,char* fileName, int rows, int cols) {
    int i, j;
    FILE* fp = NULL;
    if (A == NULL) {
        return 0;
    }
    if (!(fp = fopen(fileName, "w"))) {
        printf("ERROR!\n");
        getchar();
        return 0;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(fp, "%d ", A[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 1;
}

int** loadMatrix(char* fileName) {
    FILE* fp = NULL;
    char arr[8];
    int t = 0, i = 0, j = 0;

    if (!(fp = fopen(fileName, "r"))) {
        printf("ERROR!\n");
        getchar();
        return 0;
    }

    int row = 0, col = 0;
    fscanf(fp, "%d %d\n", &row, &col);

    int** A = CreateMatrix(row, col);

    while (!feof(fp)) {
        fscanf(fp, "%c", &arr[t]);
        t++;
        if (arr[t - 1] == (' ')) {
            A[i][j] = atoi(arr);
            t = 0;
            j++;
        }
        if (arr[t - 1] == ('\n')) {
            i++;
            t = 0;
            j = 0;
        }
    }

    fclose(fp);

    return A;
}

int **TwoMatrixMultiplication(int **arrA, int **arrB, int nA, int mA, int nB, int mB){
    if(mA == nB) {

        int **arrC = CreateMatrix(nA, mB);
        for (int i = 0; i < nA; ++i) {
            for (int j = 0; j < mB; ++j) {
                arrC[i][j] = 0;
                for (int k = 0; k < mA; ++k) {
                    arrC[i][j] += arrA[i][k] + arrB[k][j];
                }
            }
        }
        printMatrix(nA, mB, arrC);
        return arrC;
    } else{
        printf("Incorrect matrix");
        return NULL;
    }
}


int **MatrixMultiplication(int **arrA, int nA, int mA){
    int **arrC = CreateMatrix(nA,mA);
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    for (int i = 0; i < nA; ++i) {
        for (int j = 0; j < mA; ++j) {
            arrC[i][j] = num*arrA[i][j];
        }
    }
    printMatrix(nA,mA,arrC);
    return arrC;
}

int **MatrixSum(int **arrA, int **arrB, int nA, int mA, int nB, int mB){
    int **arrC = CreateMatrix(nA,mA);
    if(nA == nB && mA == mB){
        for(int i =0;i<nA;i++){
            for (int j = 0; j < mA; j++) {
                arrC[i][j] = arrA[i][j] + arrB[i][j];
            }
        }
        printMatrix(nA,mA,arrC);
        return arrC;
    } else{
        printf("Cannot sum them. Incorrect sizes\n");
        return NULL;
    }
}

int **MatrixDifference(int **arrA, int **arrB, int nA, int mA, int nB, int mB){
    int **arrC = CreateMatrix(nA,mA);
    if(nA == nB && mA == mB){
        for(int i =0;i<nA;i++){
            for (int j = 0; j < mA; j++) {
                arrC[i][j] = arrA[i][j] - arrB[i][j];
            }
        }
        printMatrix(nA,mA,arrC);
        return arrC;
    } else{
        printf("Cannot sum them. Incorrect sizes\n");
        return NULL;
    }
}


int **CreateMatrix(int n,int m){

    int **arr = (int **) malloc(n*sizeof (int *));
    for(int i = 0;i<n;i++){
        arr[i] = (int*) malloc(m*sizeof (int ));
    }
    for (int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            arr[i][j] = rand()%20;
        }
    }
    return arr;
}

int printMatrix(int n, int m, int **arr){
    printf("\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

