// Sambungkan pin encoder A dan encoder B ke pin Interrupt
#define ENCOA1 2
#define ENCOB1 3

int encoderPos_1 = 0;

void setup() {
  // INPUT -> jika pin disconnect, maka secara acak akan membaca tinggi dan rendah. 
  //Jika terdapat masukan +5V or 0V, itu jelas akan membaca HIGH atau LOW.
  // INPUT_PULLUP -> Resistor 20k ohm opsional dapat dihubungkan secara internal, secara fungsional
  // setara dengan menghubungkan resistor 20k ohm antara pin dan 5v, perbedaanya adalah tidak memerlukan
  // komponen eksternal dan dapat menghidupkan/mematikannya dalam perangkat lunak selama eksekusi program
  pinMode(ENCOA1, INPUT_PULLUP);
  pinMode(ENCOB1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCOA1), readEncoderA1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCOB1), readEncoderB1, CHANGE);
  // AttachInterrupt -> ketika pin pada digitalPinToInterrupt(ENCOA1)/pin ENCOA1 mendapat tegangan 
  // maka program akan mengeksekusi fungsi readEncoderA1, dan memberhentian program pada loop
  // Fungsi CHANGE untuk memicu interupsi setiap kali pin mengubah nilai
}

void loop() {
  Serial.begin(9600);
  Serial.print("Nilai encoder: ");
  Serial.println(encoderPos_1);
  // Pembacaan harus benar, ketika diputar CW ++, ketika CCW --
  // Jika salah maka periksa kembali keluaran high low pada encoder
  delay(10);
}

void readEncoderA1() {
  int a = digitalRead(ENCOA1);
  int b = digitalRead(ENCOB1);
  if (a == HIGH) {
    if (b == LOW) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
  else {
    if (b == HIGH) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
}

void readEncoderB1() {
  int a = digitalRead(ENCOA1);
  int b = digitalRead(ENCOB1);
  if (b == HIGH) {
    if (a == HIGH) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
  else {
    if (a == LOW) {
      encoderPos_1++;
    }
    else {
      encoderPos_1--;
    }
  }
}
