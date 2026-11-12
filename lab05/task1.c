#include <stdio.h>
#include <math.h>

// Прототип: вхід через const-покажчики, вихід через out-параметри
int solve_quadratic(const double *a, const double *b, const double *c,
                    double *x1, double *x2, int *root_count);

int main(void) {
    double a, b, c;
    double x1 = 0.0, x2 = 0.0;
    int root_count = 0;

    printf("Enter coefficients a, b, c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Error: coefficients must be numbers.\n");
        return 1;
    }

    int status = solve_quadratic(&a, &b, &c, &x1, &x2, &root_count);
    if (status != 0) {
        printf("Error: invalid input (NULL pointer or a = 0).\n");
        return 1;
    }

    printf("Real roots: %d\n", root_count);
    if (root_count == 1) {
        printf("x1 = x2 = %.4f\n", x1);
    } else if (root_count == 2) {
        printf("x1 = %.4f\nx2 = %.4f\n", x1, x2);
    }

    return 0;
}

// Повертає 0 при успіху, 1 при NULL або a = 0
int solve_quadratic(const double *a, const double *b, const double *c,
                    double *x1, double *x2, int *root_count) {
    const double EPS = 1e-12;

    if (a == NULL || b == NULL || c == NULL
        || x1 == NULL || x2 == NULL || root_count == NULL) {
        return 1;
    }
    if (fabs(*a) < EPS) {
        return 1;  // рівняння не квадратне
    }

    double discriminant = (*b) * (*b) - 4.0 * (*a) * (*c);

    if (discriminant < -EPS) {
        *root_count = 0;
    } else if (fabs(discriminant) <= EPS) {
        *x1 = -(*b) / (2.0 * (*a));
        *x2 = *x1;
        *root_count = 1;
    } else {
        double root = sqrt(discriminant);
        *x1 = (-(*b) + root) / (2.0 * (*a));
        *x2 = (-(*b) - root) / (2.0 * (*a));
        *root_count = 2;
    }

    return 0;
}