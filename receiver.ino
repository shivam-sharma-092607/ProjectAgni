#define LED_PIN 4
#define BUZZER_PIN 5

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("📡 Received Fire Aleart!");
  delay(900);
}

void loop() {
  Serial.println();
  Serial.println("🚨 FIRE ALERT SIGNAL RECEIVED FROM SECTOR 47!");
  Serial.println("🚨 High CO levels detected in SECTOR 47!");
  Serial.println("🚨 High Temperature detected in SECTOR 47!");

  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(2000);

  Serial.println("✅ Alert acknowledged by Sector 47 Hub");
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  delay(2000);
}