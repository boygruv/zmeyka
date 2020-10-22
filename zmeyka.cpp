#include <iostream>
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
// Массивы для координат хвоста
int tailX[100], tailY[100];
// Кол-во элементов хвоста
int nTail;
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
            {
                // Рисуем хвост
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        print = true;
                        cout << "o";
                    }
                }
                if (!print)
                    // Заполняем пустые поля пробелами
                    cout << " ";
            }
        }
        cout << endl;
    }

    // Нарисуем нижнюю границу поля
    for (int i = 0; i < width; i++)
        cout << "#";
    // Выводим конец строки
    cout << endl;
    // Вывод счета
    cout << "Score: " << score << endl;
}

// Обработка нажатий клавиатуры
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// Основная логика
void Logic()
{
    // Переменные для хвоста
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Изменение координат змейки
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // При столкновении со стенкой заканчиваем игру
    //if (x > width || x < 0 || y > height || y < 0)
    //  gameOver = true;

    // Переход на другую стену поля по X
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;

    // Переход на другую стену поля по Y
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    // Проверка не съели ли мы свой хвост
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    // Поедание фрукта и выставление очков
    if (x == fruitX && y == fruitY)
    {
        // Увеличим значение очков
        score += 10;
        // Выведем новый фрукт
        fruitX = rand() % width;
        fruitY = rand() % height;
        // Увеличим длинну хвоста
        nTail++;
    }
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
