/*
  EDU.BOT - Basic Line Tracking Test
  หุ่นยนต์เดินตามเส้นสีดำ (ใช้เซ็นเซอร์ IR 2 ตัว ซ้าย-ขวา)
  ตรรกะ: 
  - เจอเส้นดำค่าจะเป็น HIGH (1) 
  - เจอพื้นขาวค่าจะเป็น LOW (0)
*/

// กำหนดขาเซ็นเซอร์เดินตามเส้น
const int sensorLeft = 2;  // เซ็นเซอร์ตัวซ้าย
const int sensorRight = 3; // เซ็นเซอร์ตัวขวา

// กำหนดขาควบคุมมอเตอร์ (เหมือนเดิม)
const int motorLeftDir1 = 5;  const int motorLeftDir2 = 6;  const int motorLeftSpeed = 9;
const int motorRightDir1 = 7; const int motorRightDir2 = 8; const int motorRightSpeed = 10;

// กำหนดความเร็ว (หุ่นยนต์เดินตามเส้นไม่ควรวิ่งเร็วเกินไป เพื่อให้เซ็นเซอร์อ่านทัน)
const int baseSpeed = 120; 
const int turnSpeed = 150; 

void setup() {
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);
  
  pinMode(motorLeftDir1, OUTPUT); pinMode(motorLeftDir2, OUTPUT); pinMode(motorLeftSpeed, OUTPUT);
  pinMode(motorRightDir1, OUTPUT); pinMode(motorRightDir2, OUTPUT); pinMode(motorRightSpeed, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("EDU.BOT Line Tracking Ready!");
}

void loop() {
  // อ่านค่าจากเซ็นเซอร์
  int leftValue = digitalRead(sensorLeft);
  int rightValue = digitalRead(sensorRight);

  // เงื่อนไขการตัดสินใจ (Logic Process)
  if (leftValue == LOW && rightValue == LOW) {
    // เซ็นเซอร์ทั้งสองอยู่บนพื้นขาว -> เดินหน้าตรง
    moveForward(baseSpeed);
  } 
  else if (leftValue == HIGH && rightValue == LOW) {
    // เซ็นเซอร์ซ้ายเจอเส้นดำ (หุ่นเริ่มเอียงขวา) -> เลี้ยวซ้ายเพื่อกลับเข้าเส้น
    turnLeft(turnSpeed);
  } 
  else if (leftValue == LOW && rightValue == HIGH) {
    // เซ็นเซอร์ขวาเจอเส้นดำ (หุ่นเริ่มเอียงซ้าย) -> เลี้ยวขวาเพื่อกลับเข้าเส้น
    turnRight(turnSpeed);
  } 
  else if (leftValue == HIGH && rightValue == HIGH) {
    // เจอเส้นดำทั้งสองฝั่ง (อาจจะเป็นทางแยก หรือเส้นหยุด) -> หยุด
    stopBot();
  }
}

// --- ฟังก์ชันควบคุมมอเตอร์แบบปรับความเร็วได้ ---
void moveForward(int speed) {
  analogWrite(motorLeftSpeed, speed); analogWrite(motorRightSpeed, speed);
  digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW);
  digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW);
}

void turnLeft(int speed) {
  analogWrite(motorLeftSpeed, speed); analogWrite(motorRightSpeed, speed);
  digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, HIGH); // ล้อซ้ายถอย
  digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW); // ล้อขวาเดินหน้า
}

void turnRight(int speed) {
  analogWrite(motorLeftSpeed, speed); analogWrite(motorRightSpeed, speed);
  digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW); // ล้อซ้ายเดินหน้า
  digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH); // ล้อขวาถอย
}

void stopBot() {
  digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, LOW);
  digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, LOW);
}
