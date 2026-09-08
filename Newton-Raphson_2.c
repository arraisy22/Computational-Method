#include <stdio.h>
#include <math.h>
#include <windows.h>

float fx(float x){
    return x*x*x - 6*x*x + 8*x + 0.8;
}

float f_prime(float x){
    return 3*x*x - 12*x + 8;
}

float x_g = 2.0;
float x_b = 0.0;
float x_a = 10.0;

int main(){

    int i = 1;

    while(x_a > 0.00001){

        printf("Iterasi %d\n", i);
        printf("f(x_g) = %f\n", fx(x_g));
        printf("f'(x_g) = %f\n", f_prime(x_g));

        // simpan x lama
        x_b = x_g;

        // Newton-Raphson
        x_g = x_g - fx(x_g)/f_prime(x_g);

        // hitung error
        x_a = fabs(x_g - x_b);

        printf("x_b = %f\n", x_b);
        printf("x_g = %f\n", x_g);
        printf("error = %f\n\n", x_a);

        i++;

        Sleep(100);
    }

    printf("Akar = %f\n", x_g);

    return 0;
}