#include <iostream>
#include <conio.h>

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
    x = width / 2;
    y = height / 2;
    // Получаем случайные координаты для фруктов
    fruitX = rand() % width;
    fruitY = rand() % height;
    // Начальный счет
    score = 0;
}

// Отрисовка карты
void Draw()
{
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
            // Заполняем внутре поля пробелами
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

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
