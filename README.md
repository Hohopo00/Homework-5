# Homework-5



## Условие задачи
Написать программу для решения математической задачи. 

## 1. Алгоритм и блок-схема

### Алгоритм
1. **Начало**
2. Задать константы:
   - `double x` — Первое число
   - `double y` — Второе число
   - `double z` — Третье число
3. Вычисление выражения по частям
4. Вывод результатов первого хода.
5. **Конец**

##Блок-схема
<img width="2364" height="3044" alt="image" src="https://github.com/user-attachments/assets/6fa4e973-aee4-452a-a84e-6a6de5e2b36d" />


## 2. Реализация программы

```
﻿#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <locale.h>   

#define M_PI 3.14159265358979323846

int main() {
    setlocale(LC_ALL, "RUS");
    // Точные значения из задания
    double x, y, z;
    printf("Введите значение х: ");
    scanf("%lf", &x);
    printf("Введите значение y: ");
    scanf("%lf", &y);
    printf("Введите значение z: ");
    scanf("%lf", &z);
    printf("\nВведенные значения:\n");
    printf("x=%.3f\n", x);
    printf("y=%.3f\n", y);
    printf("z=%.3f\n", z);
    // Вычисляем по частям с контролем точности
    double cube_root = cbrt(x);
    double inner_expr = y + cube_root - 1;
    double fourth_root = pow(inner_expr, 0.25);

    // Для больших z нормализуем угол
    double z_norm = fmod(z, 2 * M_PI);
    double sin_z = sin(z_norm);
    double tan_z = tan(z_norm);
    double trig_part = sin_z * sin_z + tan_z; // sin²z + tgz

    double denominator = fabs(x - y) * trig_part;
    double result = fourth_root / denominator;

    printf("Результат: %.5f\n", result);

    return 0;
}

```

## 3. Результаты работы программы

```
Результат: 0,29427
```

## 4. Информация о разработчике

Прохорова Виктория, бТИИ-251
