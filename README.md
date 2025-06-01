# color-library-cpp
C++ Color Library Implementation
# C++ Color Library

Проект реализует библиотеку для работы с цветами в C++ в соответствии с требованиями задания.

## Особенности
- Поддержка RGB/RGBA цветов
- Создание цветов по имени (16 предопределенных цветов)
- Преобразование в различные форматы: RGB, RGBA, HEX
- Смешивание цветов через оператор /
- Получение значений в виде кортежей

## Компиляция
```bash
g++ -std=c++17 color.cpp main.cpp -o color_demo
```
## Основные возможности
1. Создание цветов
 ```bash
   // Из RGB-значений (непрозрачный)
Color red(255, 0, 0);

// Из RGBA-значений (с прозрачностью)
Color transparentGreen(0, 255, 0, 128);

// По имени цвета (16 предопределенных цветов)
Color blue("blue");
```
2. Доступ к компонентам цвета
```bash
// Получение значений
int r = color.getRed();
int a = color.getAlpha();

// Изменение значений
color.setGreen(150);
color.setAlpha(200);
```
3. Преобразование в строковые форматы
```bash
std::string rgb = color.toRGB();    // "rgb(255,0,0)"
std::string rgba = color.toRGBA(); // "rgba(0,150,255,200)"
std::string hex = color.toHEX();   // "#ff0000" или "#ff0000c8"
```
4. Работа с кортежами
```bash
auto [r, g, b] = color.getRGB();
auto [r, g, b, a] = color.getRGBA();
```
5. Смешивание цветов
```bash
Color mixed = color1 / color2;
```
6. Вывод цвета в поток
```bash
std::cout << color; // Выводит в формате rgba(...)
```
## Примеры использования
Пример 1: Создание и модификация цвета
```bash
Color c("teal");  // Бирюзовый (0,128,128)
c.setRed(50);     // Изменяем красный компонент
c.setAlpha(180);  // Устанавливаем прозрачность

std::cout << c.toHEX(); // #328080b4
```
Пример 2: Смешивание цветов
```bash
Color yellow("yellow"); // (255,255,0)
Color navy("navy");     // (0,0,128)
Color mixed = yellow / navy;

std::cout << "Mixed color: " << mixed.toRGB();
// rgb(127,127,64)
```
Пример 3: Получение компонентов
```bash
Color purple("purple"); // (128,0,128)
auto [r, g, b] = purple.getRGB();

std::cout << "Purple components: " 
          << r << ", " << g << ", " << b;
// 128, 0, 128
```
