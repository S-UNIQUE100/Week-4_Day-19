const int LDR_PIN = A0;
const int LED_PIN = 13;
const int ON_BELOW = 300;   // dark: turn ON
const int OFF_ABOVE = 400;  // bright: turn OFF

bool ledOn = false;
unsigned long lastPrint = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR_PIN);

  if (!ledOn && light < ON_BELOW) ledOn = true;
  else if (ledOn && light > OFF_ABOVE) ledOn = false;

  digitalWrite(LED_PIN, ledOn ? HIGH : LOW);

  if (millis() - lastPrint >= 1000) {
    lastPrint = millis();
    Serial.print("LDR: ");
    Serial.print(light);
    Serial.print(" | LED: ");
    Serial.println(ledOn ? "ON" : "OFF");
  }
}
