#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double factorial(double x) {
    double sum = 1;
    int i = 1;
    for (i = 1; i <= x; i++) {
        sum *= i;
    }
    return sum;
}

double S_sin(double x, double eps) {
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while (abs(current) > eps) {
        degree = 2 * i + 1;
        current = pow(-1, i) * pow(x, degree) / factorial(degree);
        sum += current;
        i++;
    }
    return sum;
}

double C_cos(double x, double eps) {
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while (abs(current) > eps) {
        degree = 2 * i;
        current = pow(-1, i) * pow(x, degree) / factorial(degree);
        sum += current;
        i++;
    }
    return sum;
}



double Distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}


double curve_function(double x, double eps) {
    return pow(S_sin(x, eps), 2) / (1 + pow(C_cos(x, eps), 3));
}

int main() {

    double EPS = 0.00001;
    int i;


    int from, to, count;
    double a, b;
    printf("Enter from: ");
    scanf("%lf", &a);
    printf("Enter to: ");
    scanf("%lf", &b);
    printf("Enter parts: ");
    scanf("%d", &count);


    double result = 0.0; 
    double cur_y, cur_x = a, next_y, next_x;

    double step = (double)((b - a) / count);

    cur_y = curve_function(cur_x, EPS);
   
    for (i = 0; i < count; i++, cur_x += step) {
        next_x = cur_x + step;
        next_y = curve_function(next_x, EPS);
        result += Distance(cur_x, cur_y, next_x, next_y);
        cur_y = next_y;
    }

    printf("\nLength of curve : %lf\n", result);

    return 0;
}
