#include <Arduino.h>

#define AD_PIN 32

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(AD_PIN, ANALOG);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // double vol = analogReadMilliVolts(AD_PIN) * 1000;
  double adcVal = analogRead(AD_PIN) * 3300 / 4096;
  double vol = (adcVal * 5000 / 3300 + 200) / 1000;
  Serial.println(adcVal);
  // double vol = 4.1;
  Serial.printf("ADC Val: %f\n", vol);
  // 水温の計算(温度センサーの水温と電圧の関係は比例関係ではないので、〇X^6+〇x^5+〇x^4++〇x^3+〇x^2+〇xになる)
  double volt_data[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // {6乗, 5乗, ４乗, 3乗, 2乗、1乗}
  for (int i = 0; i < 6; i++)
  {
    for (int n = 0; n < (6 - i); n++)
    {
      volt_data[i] *= vol; // 最終的に {w_volt_avr^6, w_volt_avr^5, w_volt_avr^4, w_volt_avr^3, w_volt_avr^2, w_volt_avr}
    }
  }
  double w_data = (0.1067 * volt_data[0]) - (2.6257 * volt_data[1]) + (22.627 * volt_data[2]) - (93.172 * volt_data[3]) + (199.71 * volt_data[4]) - (241.82 * volt_data[5]) + 202.85; // 202.82などの数値についてはMoteCの温度センサーに付いてくる資料を見よ
  Serial.printf("thermo: %f\n\n", w_data);
  delay(500);
}