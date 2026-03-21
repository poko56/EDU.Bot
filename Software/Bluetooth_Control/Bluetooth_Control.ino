/*
  EDU.BOT - Bluetooth / Serial Control
  บังคับหุ่นยนต์ผ่านแอปมือถือ (ส่งตัวอักษร F, B, L, R, S)
  *ถ้าใช้ Arduino Uno + HC-05 ให้ต่อ RX-TX สลับกัน
*/

// กำหนดขาควบคุมมอเตอร์ (เหมือนเดิม)
const int motorLeftDir1 = 5;  const int motorLeftDir2 = 6;  const int motorLeftSpeed = 9;
const int motorRightDir1 = 7; const int motorRightDir2 = 8; const int motorRightSpeed = 10;

char command; // ตัวแปรสำหรับเก็บคำสั่งที่รับมา

void setup() {
  pinMode(motorLeftDir1, OUTPUT); pinMode(motorLeftDir2, OUTPUT); pinMode(motorLeftSpeed, OUTPUT);
  pinMode(motorRightDir1, OUTPUT); pinMode(motorRightDir2, OUTPUT); pinMode(motorRightSpeed, OUTPUT);
  
  analogWrite(motorLeftSpeed, 180);  // ตั้งความเร็วคงที่
  analogWrite(motorRightSpeed, 180);
  
  Serial.begin(9600); // ความเร็วมาตรฐานของโมดูล Bluetooth ทั่วไป
  Serial.println("EDU.BOT Bluetooth Ready! Waiting for commands...");
}

void loop() {
  // ตรวจสอบว่ามีข้อมูลส่งเข้ามาทาง Bluetooth/Serial หรือไม่
  if (Serial.available() > 0) {
    command = Serial.read(); // อ่านค่าตัวอักษร 1 ตัว
    Serial.print("Received: ");
    Serial.println(command);

    // ทำงานตามคำสั่งที่ได้รับ
    switch (command) {
      case 'F': // Forward
        moveForward();
        break;
      case 'B': // Backward
        moveBackward();
        break;
      case 'L': // Left
        turnLeft();
        break;
      case 'R': // Right
        turnRight();
        break;
      case 'S': // Stop
        stopBot();
        break;
    }
  }
}

// --- ฟังก์ชันควบคุมทิศทาง ---
void moveForward() { digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW); }
void moveBackward() { digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, HIGH); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH); }
void turnLeft() { digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, HIGH); digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW); }
void turnRight() { digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH); }
void stopBot() { digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, LOW); }
