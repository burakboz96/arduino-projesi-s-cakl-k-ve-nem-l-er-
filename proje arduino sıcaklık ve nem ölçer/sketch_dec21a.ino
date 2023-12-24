#include <LCD5110_Graph.h>
#include <dht11.h>

LCD5110 myGLCD(8, 9, 10, 11, 12);
extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];
int DHT11_pin = 4;
dht11 DHT11_sensor;
int sicaklik;
int nem;

void setup() {
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.setContrast(70);
}

void loop() {
  int chk = DHT11_sensor.read(DHT11_pin);
  sicaklik = DHT11_sensor.temperature;
  nem = DHT11_sensor.humidity;

  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);


  myGLCD.print("Sicaklik:", 5, 5);
  myGLCD.printNumI(sicaklik, 60, 5);
  myGLCD.print("C", 74, 5);

  myGLCD.print("Nem: ", 5, 15);
  myGLCD.printNumI(nem, 38, 15);
  myGLCD.print("%", 30, 15);

  
  if (sicaklik >= 20 && sicaklik <= 40 && nem >= 20 && nem <= 60) {
    myGLCD.print("Ortam:Ideal", 3, 30);
    
  } else if (sicaklik < 20 && nem < 20) {
    myGLCD.print("Ortam:Ilık ", 3, 30);
  }
   else if (sicaklik <10 && nem < 30) {
    myGLCD.print("Uyarı!:Ortam Soğuk ", 3, 30);
  }
    else if (sicaklik > 40 && nem > 40) {
    myGLCD.print("Uyarı!:Ortam Sıcak", 3, 30);
  }
  myGLCD.update();
  delay(1000);
}
