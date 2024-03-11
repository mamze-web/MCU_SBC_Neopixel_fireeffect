#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 5

// 전체적인 화염 밝기 설정
// (이 값은 색상 수준과 전력 소비에 모두 영향을 줄 수 있음)
int brightness = 128;

// Adafruit_NeoPixel 라이브러리를 사용하여 네오픽셀 객체 생성
// 파라미터 1 = 스트립 내 픽셀 수
// 파라미터 2 = 아두이노 핀 번호 (대부분의 핀이 유효함)
// 파라미터 3 = 픽셀 유형 플래그, 필요에 따라 추가:
//   NEO_KHZ800  800 KHz 비트스트림 (대부분의 NeoPixel 제품 w/WS2812 LED)
//   NEO_KHZ400  400 KHz (클래식 'v1' (v2가 아님) FLORA 픽셀, WS2811 드라이버)
//   NEO_GRB     픽셀이 GRB 비트스트림으로 연결됨 (대부분의 NeoPixel 제품)
//   NEO_RGB     픽셀이 RGB 비트스트림으로 연결됨 (v1 FLORA 픽셀, v2가 아님)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(29, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // 네오픽셀 초기화
  strip.setBrightness(brightness); // 밝기 설정
  strip.show(); // 모든 픽셀을 '끔' 상태로 초기화
}

void loop() {
  // 아래 RGB 값 중 하나를 주석 해제하여
  // 화염의 기본 색상을 설정합니다.
  // 초기 기본 색상을 기반으로 화염이 깜박입니다.

  // 기본적인 오렌지색 화염:
  int r = 226, g = 121, b = 35;

  // 보라색 화염:
  // int r = 158, g = 8, b = 148;

  // 녹색 화염:
  // int r = 74, g = 150, b = 12;

  // 초기 RGB 값을 기준으로 화염을 깜박이게 만듭니다.
  for(int i=0; i<strip.numPixels(); i++) {
    int flicker = random(0,55);
    int r1 = r - flicker;
    int g1 = g - flicker;
    int b1 = b - flicker;
    if(g1 < 0) g1 = 0;
    if(r1 < 0) r1 = 0;
    if(b1 < 0) b1 = 0;
    strip.setPixelColor(i, r1, g1, b1); // 픽셀 색상 설정
  }
  strip.show(); // 변경된 색상을 네오픽셀에 표시

  // 여기서 딜레이를 조정할 수 있습니다. 현재는 색상 전환 딜레이를 무작위화하여
  // 현실감을 더해줍니다.
  delay(random(10, 113));
}