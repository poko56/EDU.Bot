/*
  EDU.BOT - Basic Motor Control Test
  ทดสอบการเคลื่อนที่พื้นฐาน เดินหน้า ถอยหลัง เลี้ยวซ้าย เลี้ยวขวา
*/

// กำหนดขาควบคุมมอเตอร์ (ปรับเปลี่ยนให้ตรงกับบอร์ดและ Motor Driver ที่ใช้)
// มอเตอร์ฝั่งซ้าย (ต่อขนานกัน 2 ตัว)
const int motorLeftDir1 = 5;  
const int motorLeftDir2 = 6;  
const int motorLeftSpeed = 9; // ขา PWM ควบคุมความเร็ว

// มอเตอร์ฝั่งขวา (ต่อขนานกัน 2 ตัว)
const int motorRightDir1 = 7; 
const int motorRightDir2 = 8; 
const int motorRightSpeed = 10; // ขา PWM ควบคุมความเร็ว

void setup() {
  // ตั้งค่าขาควบคุมทั้งหมดเป็น OUTPUT
  pinMode(motorLeftDir1, OUTPUT);
  pinMode(motorLeftDir2, OUTPUT);
  pinMode(motorLeftSpeed, OUTPUT);
  
  pinMode(motorRightDir1, OUTPUT);
  pinMode(motorRightDir2, OUTPUT);
  pinMode(motorRightSpeed, OUTPUT);

  // ตั้งความเร็วเริ่มต้นที่ 150 (จาก 0-255)
  analogWrite(motorLeftSpeed, 150);
  analogWrite(motorRightSpeed, 150);
  
  Serial.begin(115200);
  Serial.println("EDU.BOT Motor Test Ready!");
}

void loop() {
  Serial.println("Moving Forward");
  moveForward();
  delay(2000); // เดินหน้า 2 วินาที

  Serial.println("Stopping");
  stopBot();
  delay(1000); // หยุด 1 วินาที

  Serial.println("Moving Backward");
  moveBackward();
  delay(2000); // ถอยหลัง 2 วินาที

  Serial.println("Turning Right");
  turnRight();
  delay(1000); // หมุนขวา 1 วินาที

  Serial.println("Stopping");
  stopBot();
  delay(3000); // พัก 3 วินาทีก่อนเริ่มรอบใหม่
}

// --- ฟังก์ชันควบคุมทิศทาง ---
void moveForward() {
  digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW);
  digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW);
}

void moveBackward() {
  digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, HIGH);
  digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH);
}

void turnRight() { // ล้อซ้ายเดินหน้า ล้อขวาถอยหลัง
  digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW);
  digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH);
}

void stopBot() {
  digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, LOW);
  digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, LOW);
}
