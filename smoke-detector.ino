git add// Identifikasi setiap sensor
int GreenLed = 5;
int RedLed = 6;
int buzzer = 7;

// Sensor MQ-2
int smokeA0 = A0;
int batasNilai = 190;

void setup() {
  Serial.begin(9600);
  pinMode(smokeA0, INPUT);  
  pinMode(buzzer, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
}

void loop() 
{
  // Nilai yang muncul di sensor MQ-2
  int analogSensor = analogRead(smokeA0); 

  // Cetak secara serial
  Serial.print("Nilai Sensor : ");
  Serial.println(analogSensor);

  // Jika nilai dari sensor lebih besar dari batas nilai maka
  if (analogSensor > batasNilai)
  {
    // Buzzer bunyi dengan nada peringatan "tit..tit..tit.."
    for (int i = 0; i < 7; i++) {
      // Bunyi buzzer dan nyalakan LED merah
      tone(buzzer, 2000); // Bunyi buzzer dengan frekuensi 1000 Hz
      digitalWrite(RedLed, HIGH);
      digitalWrite(GreenLed, LOW);
      delay(150); // Durasi bunyi dan nyala 150 ms

      // Matikan buzzer dan LED merah
      noTone(buzzer);
      digitalWrite(RedLed, LOW);
      delay(150); // Durasi diam 150 ms
    }

    // Matikan LED hijau setelah peringatan
    digitalWrite(GreenLed, LOW);
  }
  else 
  {
    // Jika dibawah dari batas nilai maka
    // Lampu LED merah mati dan LED hijau menyala
    digitalWrite(RedLed, LOW);
    digitalWrite(GreenLed, HIGH);
    delay(100);
    digitalWrite(GreenLed, LOW);
    delay(100);

    // Buzzer off
    noTone(buzzer);

    // Diulang setiap 3 detik
    delay(2500);
  }
}
