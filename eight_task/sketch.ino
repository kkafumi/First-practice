#include <Adafruit_NeoPixel.h>

#define PIN 3         // пин, к которому подключена лента
#define NUMPIXELS 64  // количество светодиодов

#define N 0x000000  // Черный/светодиод выключен
#define B 0x673923  // Цвет кожи
#define G 0x00FFA0  // Цвет радужки(мятно-зелёный)
#define W 0xFFFFFF  // Белый
#define R 0xFF0000  // Красный

const uint32_t HEIGHT = 8;  // высота матрицы
const uint32_t WIDTH = 8;   // ширина матрицы

const uint32_t eye_open[HEIGHT][WIDTH] = {{N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N}, {N, B, B, W, W, B, B, N},
                                          {B, B, W, G, G, W, B, B}, {B, B, W, G, G, W, B, B}, {N, B, B, W, W, B, B, N},
                                          {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}};

const uint32_t eye_semi_closed[HEIGHT][WIDTH] = {
    {N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N}, {N, B, B, B, B, B, B, N}, {B, B, B, B, B, B, B, B},
    {B, B, W, G, G, W, B, B}, {N, B, B, W, W, B, B, N}, {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}};

const uint32_t eye_closed[HEIGHT][WIDTH] = {{N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N},
                                            {N, B, B, B, B, B, B, N}, {B, B, B, B, B, B, B, B},
                                            {B, B, B, B, B, B, B, B}, {N, B, B, B, B, B, B, N},
                                            {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}}

const uint32_t hi[HEIGHT][WIDTH] = {{N, N, N, N, N, N, N, N}, {N, W, N, W, N, W, N, N}, {N, W, N, W, N, W, N, N},
                                    {N, W, N, W, N, N, N, N}, {N, W, N, W, N, W, N, N}, {N, W, N, W, N, W, N, N},
                                    {N, W, N, W, N, W, N, N}, {N, N, N, N, N, N, N, N}};

Adafruit_NeoPixel matrix(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  // создаём контроллер для матрицы

int GetPixelIndex(int x, int y) {  // перевод координат x,y в индекс светодиода
  if (y % 2 == 0) {                // чётные - слева направо. нечётные - справо налево
    return y * WIDTH + x;
  }
  return y * WIDTH + (WIDTH - 1 - x);
}

void SetPixelColorByXY(int x, int y, uint32_t color) {  // установить цвет пикселя по координатам
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {    // проверка, что запрос в границах массива
    matrix.setPixelColor(GetPixelIndex(x, y), color);
  }
}

void DrawFrame(const uint32_t frame[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x) {
      SetPixelColorByXY(x, y, frame[y][x]);
    }
  }
  matrix.show();
}

void EyeAnimation(unsigned long duration) {
  unsigned long StartTime = millis();  // время старта анимации
  while (millis() - StartTime < duration) {
    DrawFrame(eye_open);
    delay(2000);
    DrawFrame(eye_semi_closed);
    delay(200);
    DrawFrame(eye_closed);
    delay(300);
    DrawFrame(eye_semi_closed);
    delay(200);
  }
}

void RunningColumn(int speed, uint32_t color, const uint32_t frame[HEIGHT][WIDTH]) {
  for (int x = 0; x < WIDTH; ++x) {
    if (x == 0) {
      matrix.clear();
    } else {
      for (int y = 0; y < HEIGHT; ++y) {
        SetPixelColorByXY(x - 1, y, frame[y][x - 1]);
      }
    }
    for (int y = 0; y < HEIGHT; ++y) {
      if (frame[y][x] != N) {
        SetPixelByXY(x, y, color);
      }
    }
    matrix.show();
    delay(speed);
  }
}

void setup() {
  matrix.begin();             // инициализируем матрицу
  matrix.setBrightness(255);  // указываем яркость светодиодов (максимум 255)
}

void loop() {
  EyeAnimation(10000);
  delay(300);
  RunningColumn(200, B, hi);
  delay(300);
}
