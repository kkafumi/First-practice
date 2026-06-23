#include <Adafruit_NeoPixel.h>

#define PIN 3         // пин, к которому подключена лента
#define NUMPIXELS 64  // количество светодиодов
#define HEIGHT 8      // высота матрицы
#define WIDTH 8       // ширина матрицы

#define N 0x000000  // Черный/светодиод выключен
#define B 0xFFF5DF  // Цвет кожи
#define G 0x00FFA0  // Цвет радужки(мятно-зелёный)
#define W 0xFFFFFF  // Белый

const uint32_t eye_open[8][8] = {{N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N}, {N, B, B, W, W, B, B, N},
                                 {B, B, W, G, G, W, B, B}, {B, B, W, G, G, W, B, B}, {N, B, B, W, W, B, B, N},
                                 {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}}

const uint32_t eye_semi_closed[8][8] = {{N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N}, {N, B, B, B, B, B, B, N},
                                        {B, B, B, B, B, B, B, B}, {B, B, W, G, G, W, B, B}, {N, B, B, W, W, B, B, N},
                                        {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}}

const uint32_t eye_closed[8][8] = {{N, N, N, N, N, N, N, N}, {N, N, B, B, B, B, N, N}, {N, B, B, B, B, B, B, N},
                                   {B, B, B, B, B, B, B, B}, {B, B, B, B, B, B, B, B}, {N, B, B, B, B, B, B, N},
                                   {N, N, B, B, B, B, N, N}, {N, N, N, N, N, N, N, N}}

Adafruit_NeoPixel matrix(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  // создаём контроллер для матрицы

void setup() {
  matrix.begin();            // инициализируем матрицу
  matrix.setBrightness(75);  // указываем яркость светодиодов (максимум 255)
}

int GetPixelIndex(int x, int y) {  // перевод координат x,y в индекс светодиода
  if (y % 2 == 0) {                // чётные - слева направо. нечётные - справо налево
    return y * WIDTH + x;
  }
  return y * WIDTH + (WIDTH - 1 - x);
}

void SetPixelColorByXY(int x, int y, uint32_t color) {  // установить цвет пикселя по координатам
  if (x >= 0 && x < WIDTH & y >= 0 && y < HEIGHT) {     // проверка, что запрос в границах массива
    matrix.setPixelColor(GetPixelIndex(x, y), color)
  }
}

void DrawFrame(const uint32_t frame) {
  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x) {
      SetPixelColorByXY(x, y, frame[y][x]);
    }
  }
  matrix.show();
}

void EyeAnimation() {
  DrawFrame(eye_open);
  delay(2000);
  DrawFrame(eye_semi_closed);
  delay(200);
  DrawFrame(eye_closed);
  delay(300);
  DrawFrame(eye_semi_closed);
  delay(200)
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
