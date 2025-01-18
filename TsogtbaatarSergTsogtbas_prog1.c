#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int scan_n();
void scan_segments(double *R, double *ha, double *hb);
int validation(double R, double ha, double hb);
void calculation(double R, double ha, double hb, double *area, double *volume);
void averages(double total_area, double total_volume, int n);

int main() {
    int n;
    double R, ha, hb;
    double total_surface_area, volume;
    double total_area_sum;
    double total_volume_sum;

    n = scan_n(); // get n

    // get data about n number of segments
    for (int i = 1; i <= n; i++) {
        printf("Obtaining data for spherical segment number %d \n", i);

        // scan and validate inputs
        do { 
            scan_segments(&R, &ha, &hb);
        } while (!validation(R, ha, hb));

        // calculate total surface area and volume
        calculation(R, ha, hb, &total_surface_area, &volume); 
        total_area_sum += total_surface_area;
        total_volume_sum += volume;
    }

    // calculate average surface area and average volume
    averages(total_area_sum, total_volume_sum, n); 

    return 0;
}

int scan_n() {
    int n;

    do {
        printf("How many spherical segments you want to evaluate [2-10]? ");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    return n;
}

void scan_segments(double *R, double *ha, double *hb) {
    printf("What is the radius of the sphere (R)? ");
    scanf("%lf", R);

    printf("What is the height of the top area of the spherical segment (ha)? ");
    scanf("%lf", ha);

    printf("What is the height of the bottom area of the spherical segment (hb)? ");
    scanf("%lf", hb);

    printf("Entered data: R = %.2f ha = %.2f hb = %.2f \n", *R, *ha, *hb);
}

int validation(double R, double ha, double hb) {

    if (R < ha) {
        printf("Invalid input: R = %.2f ha = %.2f. R must be greater than or equal to ha.\n", R, ha);
        return 0;
    }

    if (R < hb) {
        printf("Invalid input: R = %.2f hb = %.2f. R must be greater than or equal to hb.\n", R, hb);
        return 0;
    }

    if (R <= 0 ) {
        printf("Invalid input: Radius must be a positive real value.\n");
        return 0;
    }

    if (ha <= 0 || hb <= 0) {
        printf("Invalid input: Segment heights must be positive real values.\n");
        return 0;
    }

    if (ha < hb) {
        printf("Invalid input: ha = %.2f hb = %.2f. ha must be greater than or equal to hb.\n", ha, hb);
        return 0;
    }

    return 1;
}

void calculation(double R, double ha, double hb, double *total_surface_area, double *volume) {
    double a = sqrt(R * R - ha * ha);
    double b = sqrt(R * R - hb * hb);
    double h = ha - hb;

    double top_surface_area = PI * (a * a);
    double bottom_surface_area = PI * (b * b);
    double lateral_surface_area = 2 * PI * R * h;

    *total_surface_area = top_surface_area + bottom_surface_area + lateral_surface_area;
    *volume = PI * h * ((3 * a * a) + (3 * b * b) + (h * h)) / 6;

    printf("Total Surface Area = %.2f Volume = %.2f. \n", *total_surface_area, *volume);
}

void averages(double total_area, double total_volume, int n) {
    double avg_surface_area = total_area / n;
    double avg_volume = total_volume / n;

    printf("Total average results: \n");
    printf("Average Surface Area = %.2f Average Volume = %.2f \n", avg_surface_area, avg_volume);
}
