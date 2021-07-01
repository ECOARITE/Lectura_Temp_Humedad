#include <LiquidCrystal.h>
#include <DHT.h>
#include<DHT_U.h>

int sensor = 9;
int Temperatura;
int Humedad;
DHT dht(sensor, DHT11);
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  dht.begin();
  lcd.begin(16,2);
}

void loop() {
 Temperatura = dht.readTemperature(); 
 Humedad = dht.readHumidity();

 if(isnan(Temperatura) || isnan(Humedad)){
  lcd.setCursor(0,0);
  lcd.print("Revisar conexion");
  lcd.setCursor(0,1);
  lcd.print("Revisar conexion");
 }
 else{
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(Temperatura);
  lcd.print("C ");

  lcd.setCursor(0,1);
  lcd.print(" Humedad: ");
  lcd.print(Humedad);
  lcd.println("% ");
 }
 delay(2000);
}
