#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <locale.h>   

#define M_PI 3.14159265358979323846

int main() {
    setlocale(LC_ALL, "RUS");
    // Точные значения из задания
    double x = 17.421;
    double y = 10.365e-3;  // 0.010365
    double z = 0.828e5;    // 82800

    // Вычисляем по частям с контролем точности
    double cube_root = cbrt(x);                    // ∛17.421
    double inner_expr = y + cube_root - 1;         // 0.010365 + ∛17.421 - 1
    double fourth_root = pow(inner_expr, 0.25);    // ⁴√(...)

    // Для больших z нормализуем угол
    double z_norm = fmod(z, 2 * M_PI);
    double sin_z = sin(z_norm);
    double tan_z = tan(z_norm);
    double trig_part = sin_z * sin_z + tan_z;      // sin²z + tgz

    double denominator = fabs(x - y) * trig_part;
    double result = fourth_root / denominator;

    printf("Результат: %.5f\n", result);
    printf("Ожидаемый: 0.33056\n");

    return 0;
}