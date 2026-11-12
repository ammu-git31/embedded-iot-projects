
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

#define VOLTAGE_PIN 34
#define CURRENT_PIN 35

#define LED_PIN 18
#define BUZZER_PIN 19

float voltage, current, power;
int batteryPercent;

bool warning = false;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin(21, 22);

  if (!display.begin(
      SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("EV BATTERY SYSTEM");
  display.display();

  delay(1500);
}

void loop() {

  int voltageRaw = analogRead(VOLTAGE_PIN);
  int currentRaw = analogRead(CURRENT_PIN);

  // Simulation values
  voltage = 40.0 +
      (voltageRaw / 4095.0) * 14.6;

  current = (currentRaw / 4095.0) * 30.0;

  power = voltage * current;

  batteryPercent = constrain(
      (int)((voltage - 40.0) / 14.6 * 100),
      0, 100
  );

  // Safety alerts
  warning = (voltage < 44.0 || current > 20.0);

  if (warning) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("EV BATTERY MONITOR");

  display.setCursor(0, 13);
  display.print("Voltage: ");
  display.print(voltage, 1);
  display.println(" V");

  display.setCursor(0, 25);
  display.print("Current: ");
  display.print(current, 1);
  display.println(" A");

  display.setCursor(0, 37);
  display.print("Power: ");
  display.print(power, 1);
  display.println(" W");

  display.setCursor(0, 49);
  display.print("Battery: ");
  display.print(batteryPercent);
  display.println("%");

  if (warning) {
    display.setCursor(75, 49);
    display.print("ALERT!");
  }

  display.display();

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V | Current: ");
  Serial.print(current);
  Serial.print(" A | Power: ");
  Serial.print(power);
  Serial.println(" W");

  delay(500);
}
