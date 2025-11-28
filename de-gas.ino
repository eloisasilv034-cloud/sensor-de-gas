const int pinGas = A0;       // Pino do sensor de gás
const int pinBuzzer = 8;     // Pino do buzzer
const int pinLed = 7;        // Pino do LED

const int limiteGas = 100;   // Valor limite do gás
const int tempoPiscar = 500; // Tempo de piscar (ms)

void setup() {
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorGas = analogRead(pinGas);     // Lê valor do sensor
  Serial.print("Valor do sensor de gás: ");
  Serial.println(valorGas);

  if (valorGas > limiteGas) {
    // Liga LED e buzzer
    digitalWrite(pinLed, HIGH);
    tone(pinBuzzer, 1000);  // Frequência de 1000 Hz
    delay(tempoPiscar);

    // Desliga LED e buzzer
    digitalWrite(pinLed, LOW);
    noTone(pinBuzzer);
    delay(tempoPiscar);

  } else {
    // Mantém desligado
    digitalWrite(pinLed, LOW);
    noTone(pinBuzzer);
  }
}
