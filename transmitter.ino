#include <DHT.h>

// ---------------------- SENSOR SETUP ----------------------
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------------------- COMPONENT PINS ---------------------
#define BUZZER 8
#define LED_PIN 7
#define GAS_PIN A0

// ---------------------- THRESHOLDS -------------------------
float tempThreshold = 50.0; 
int coThreshold = 200;


// ---------------------- SETUP ------------------------------
void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(BUZZER, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(GAS_PIN, INPUT);

  Serial.println("🔥 Fire Detection System Initialized");
  delay(1500);
}

// ---------------------- MAIN LOOP --------------------------
void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int co = analogRead(GAS_PIN);

  Serial.println("\n-------- LIVE SENSOR STATUS --------");
  Serial.print("🌡 Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  Serial.print("💧 Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  Serial.print("☁ CO Level: ");
  Serial.println(co);

  bool fire = false;

  if ((t >= tempThreshold) || (co >= coThreshold)) {
    fire = true;
  }

  if (fire) {
    Serial.println("🔥🔥🔥 FIRE DETECTED! 🔥🔥🔥");
    Serial.println("📡 Signal sent to nearest HUB!");
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("✅ Environment Normal");
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println("------------------------------------");
  delay(2000);
}
