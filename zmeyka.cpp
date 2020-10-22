﻿#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
// Ширина поля
const int width = 20;
// Высота поля
const int height = 20;
// Координаты змейки
int x, y;
// Координаты фрукта
int fruitX, fruitY;
// Счет
int score;
// Перечисления для хранения движения
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

eDirection dir;

// Первоночальные настройки
void Setup()
{
    gameOver = false;
    // Начальное положение змейки (стоим на месте)
    dir = STOP;
    // Первоночально устанавливаем змейку по середине поля
    x = width / 2 - 1;
    y = height / 2 - 1;
    // Получаем случайные координаты для фруктов
    fruitX = rand() % width;
    fruitY = rand() % height;
    // Начальный счет
    score = 0;
}

// Отрисовка карты
void Draw()
{
    Sleep(300);
    // Очистка экрана
    system("cls");
    // Нарисуем верхнюю границу поля
    for (int i = 0; i < width; i++)
        cout << "#";
    // Выводим конец строки (переход на новую строку)
    cout << endl;

    // Нарисуем левую границу
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
                cout << "#";
            if (i == y && j == x)
                // Выводим змейку
                cout << "0";
            else if (i == fruitY && j == fruitX)
                // Выводим фрукт
                cout << "F";
            else
                // Заполняем внутри поля пробелами
                cout << " ";
        }
        cout << endl;
    }

    // Нарисуем нижнюю границу поля
    for (int i = 0; i < width; i++)
        cout << "#";
    // Выводим конец строки
    cout << endl;
}

// Обработка нажатий клавиатуры
void Input()
{
}

// Основная логика
void Logic()
{
}

// Отключение видимости курсора
void Blinking(int off = 99)
{
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    cci.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int main()
{
    Setup();
    Blinking();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
