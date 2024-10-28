#include <stdio.h>
#include <math.h>

//chatgpt helped

double riemann_zeta(double s, int N) {
    double sum = 0.0;

    for (int n = 1; n <= N; n++) {
        sum += 1.0 / pow(n, s);
    }

    return sum;
}

int main() {
    double s;
    int N;

    // Input
    printf("Enter the value of s (s > 1): ");
    scanf("%lf", &s);

    if (s <= 1) {
        printf("The value of s must be greater than 1.\n");
        return 1;
    }

    printf("Enter the approximation of infinity (large integer N): ");
    scanf("%d", &N);

    if (N < 1) {
        printf("N must be a positive integer.\n");
        return 1;
    }

    // Compute and display the approximation of the Riemann zeta function
    double result = riemann_zeta(s, N);
    printf("Approximation of the Riemann zeta function ζ(%.2f) with N = %d: %f\n", s, N, result);

    return 0;
}

//command to run: gcc programming-in-c/lab2/ex8.c -o ex8 -lm