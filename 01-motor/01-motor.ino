// -- Masukan pada Pin PWM
#define R_PWM 4
#define L_PWM 5

void setup() {
  // inisialisasikan pin PWM sebagai OUTPUT
  Serial.begin(9600);
  pinMode (R_PWM, OUTPUT);
  pinMode (L_PWM, OUTPUT);
}

void loop() {
  // mengatur keluaran motor dalam bentum PWM max 255 = Voltage maximum
  analogWrite (R_PWM, 120);
  analogWrite (L_PWM, 0);
  delay(3000);
  analogWrite (R_PWM, 0);
  analogWrite (L_PWM, 0);
  delay(3000);
  // Motor akan bergerak ke arah R_PWM dan akan selama 3 detik kemudian berhenti dalam 3 detik
  // Selanjutnya motor akan bergerak ke arah L_PWM 
  analogWrite (R_PWM, 0);
  analogWrite (L_PWM, 120);
  delay(3000);
  analogWrite (R_PWM, 0);
  analogWrite (L_PWM, 0);
  delay(3000);
  // Perlu dicatat bahwa pin R_PWM Maupun L_PWM tidak boleh dipakai secara bersamaan, misal:
  // analogWrite (R_PWM, 120);
  // analogWrite (L_PWM, 120);
}
