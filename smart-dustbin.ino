#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
#include <Servo.h>

// --- Waste Level Monitoring Setup ---
#define trigPin 7
#define echoPin 6
#define buzzer 4
const int maxTankDepth = 22.5;
const int buzzerThreshold = 95;
const int openLevelThreshold = 80;

LiquidCrystal_I2C lcd(0x27, 16, 2);
NewPing sonar(trigPin, echoPin, maxTankDepth);

// --- Servo Proximity Detection Setup ---
#define TRIGGER_PIN  9
#define ECHO_PIN     10
#define SERVO_PIN    2
#define MAX_DISTANCE 20

// --- Push Button Pin ---
#define BUTTON_PIN 5

// --- LED Indicator Pin ---
#define LED_PIN 3

Servo servo;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Smart Dustbin");
  lcd.setCursor(0, 1);
  lcd.print("Waste Measurement");
  delay(2000);

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button setup with internal pull-up
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  servo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  // --- Waste Level Calculation ---
  int tankDistance = sonar.ping_cm();
  int wasteLevel = map(tankDistance, 0, maxTankDepth, 100, 0);
  wasteLevel = constrain(wasteLevel, 0, 100);

  Serial.print("Tank Distance: ");
  Serial.print(tankDistance);
  Serial.print(" cm, Waste Level: ");
  Serial.print(wasteLevel);
  Serial.println(" %");

  // --- Display Waste Level ---
  lcd.clear();
  if (wasteLevel >= openLevelThreshold) {
    // Display locked warning
    lcd.setCursor(0, 0);
    lcd.print("Locked Waste Full");
    lcd.setCursor(0, 1);
    lcd.print("Please clean 1st");
  } else {
    // Normal display
    lcd.setCursor(0, 0);
    lcd.print("Waste Level: ");
    lcd.print(wasteLevel);
    lcd.print("%");

    lcd.setCursor(0, 1);
    int bars = map(wasteLevel, 0, 100, 0, 16);
    for (int i = 0; i < bars; i++) {
      lcd.print("|");
    }
  }

  // --- Buzzer & LED Control ---
  digitalWrite(buzzer, (wasteLevel >= buzzerThreshold) ? HIGH : LOW);
  digitalWrite(LED_PIN, (wasteLevel >= openLevelThreshold) ? HIGH : LOW);

  // --- Proximity Sensor ---
  long duration, proximity;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  proximity = (duration / 2) / 29.1;

  Serial.print("Proximity Distance: ");
  Serial.print(proximity);
  Serial.println(" cm");

  // --- Lid Control Logic ---

  if (digitalRead(BUTTON_PIN) == LOW) {
    // Button always opens the lid, regardless of level
    Serial.println("Button Pressed: Lid Open");
    servo.write(90);
    delay(60000); // 1 minute
    servo.write(0);
  } else if (wasteLevel < openLevelThreshold && proximity <= MAX_DISTANCE) {
    // Sensor only works if level < 80%
    servo.write(90);
    delay(1000);
    servo.write(0);
  } else {
    // Otherwise, keep closed
    servo.write(0);
  }

  delay(1000);
}
