#include <stdio.h>
#include <math.h>

int scan_n();
void scan_segments(double *R, double *ha, double *hb);
int validation(double R, double ha, double hb);

void main() {
    int n;
    double R, ha, hb;

    n = scan_n(); // get n

    do {
        scan_segments(&R, &ha, &hb);
    } while (!validation(R, ha, hb));
    
}

int scan_n() {
    int n;
    printf("How many spherical segments you want to evaluate [2-10]? ");
    scanf("%d", &n);

    if (n < 2 || n > 10) {
        printf("Please enter a number between 2 and 10.\n");
    } else {
        return n;
    }
}

void scan_segments(double *R, double *ha, double *hb) {
    printf("What is the radius of the spehere (R)?");
    scanf("%lf", R);

    printf("What is the height of the top area of the spherical segment (ha)? ");
    scanf("%lf", ha);

    printf("What is the height of the bottom area of the spherical segment (hb)? ");
    scanf("%lf", hb);

    printf("Entered data: R = %.2f ha = %.2f hb = %.2f \n", *R, *ha, *hb);
}

int validation(double R, double ha, double hb) {
    if (R <= 0 || ha <= 0 || hb <= 0) {
        printf("Invalid input: segment heights and radius must be positive real values\n");
        return 0;
    }

    if (R < ha || R < hb) {
        printf("Invalid input: ha and hb must never be bigger than the value of R\n");
        return 0;
    }

    if (ha < hb) {
        printf("Invalid input: ha should always be bigger than or equal to hb\n");
        return 0;
    }

    return 1;
}