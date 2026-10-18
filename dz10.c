#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
float area(float a, float b, float h) { return ((a + b) / 2.0f) * h; }
void draw(int a, int b, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h - i; j++) printf(" "); 
        for (int j = 0; j < b + i * 2; j++) printf(" "); 
        printf("*\n");                             
    }
    for (int i = 0; i < a; i++) printf("*");        
    printf("\n");
}
void compare(float a1, float b1, float h1, float a2, float b2, float h2) {
    float s1 = area(a1, b1, h1), s2 = area(a2, b2, h2);
    printf("Площадь 1: %.2f, Площадь 2: %.2f. ", s1, s2);
    if (s1 > s2) printf("Первая больше.\n");
    else if (s2 > s1) printf("Вторая больше.\n");
    else printf("Они равны.\n");
}
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    float a, b, h;
    do {
        printf("\n1-Площадь, 2-Определение, 3-Рисунок, 4-Сравнить, 0-Выход\n> ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Введите a, b, h: "); scanf("%f %f %f", &a, &b, &h);
            printf("Площадь: %.2f\n", area(a, b, h));
        }
        else if (choice == 2) {
            printf("Равнобедренная трапеция — четырехугольник с равными боковыми сторонами.\n");
        }
        else if (choice == 3) {
            int a_i, b_i, h_i;
            printf("Введите целые a, b, h: "); scanf("%d %d %d", &a_i, &b_i, &h_i);
            draw(a_i, b_i, h_i);
        }
        else if (choice == 4) {
            float a2, b2, h2;
            printf("Трапеция 1 (a b h): "); scanf("%f %f %f", &a, &b, &h);
            printf("Трапеция 2 (a b h): "); scanf("%f %f %f", &a2, &b2, &h2);
            compare(a, b, h, a2, b2, h2);
        }
    } while (choice != 0);

    return 0;
}