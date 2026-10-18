#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
float area_trapezoid(float a, float b, float h);
void info_trapezoid();
void draw_trapezoid(int a, int b, int h);

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice;
    float a, b, h;
    printf("Введите нижнее основание трапеции (a): ");
    scanf("%f", &a);
    printf("Введите верхнее основание трапеции (b): ");
    scanf("%f", &b);
    printf("Введите высоту трапеции (h): ");
    scanf("%f", &h);

    printf("\nВыберите операцию:\n");
    printf("1) Рассчитать площадь\n");
    printf("2) Вывести определение фигуры\n");
    printf("3) Нарисовать фигуру\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Площадь трапеции = %.2f\n", area_trapezoid(a, b, h));
        break;
    case 2:
        info_trapezoid();
        break;
    case 3:
        draw_trapezoid((int)a, (int)b, (int)h);
        break;
    default:
        printf("Неверный выбор!\n");
    }

    return 0;
}
float area_trapezoid(float a, float b, float h)
{
    return ((a + b) / 2.0f) * h;
}
void info_trapezoid()
{
    printf("Равнобедренная трапеция — это трапеция, у которой боковые стороны равны.\n");
}
void draw_trapezoid(int a, int b, int h)
{
    int spaces = (a - b) / 2;
    for (int j = 0; j < spaces; j++) printf(" ");
    for (int j = 0; j < b; j++) printf("*");
    printf("\n");
    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j < spaces - i; j++)
            printf(" ");
        printf("*");
        for (int j = 0; j < b + 2 * i - 2; j++)
            printf(" ");
        printf("*\n");
    }
    for (int i = 0; i < a; i++)
        printf("*");
    printf("\n");
}
