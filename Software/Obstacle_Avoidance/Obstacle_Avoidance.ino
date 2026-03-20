/*
  EDU.BOT - Obstacle Avoidance Test
  หุ่นยนต์เดินหน้าอัตโนมัติ และจะหยุดพร้อมถอยหลัง/เลี้ยวเมื่อเจอสิ่งกีดขวาง
*/

// กำหนดขา Ultrasonic Sensor (HC-SR04)
const int trigPin = 12;
const int echoPin = 13;

// (นำการประกาศขามอเตอร์จากโค้ดที่ 1 มาใส่ตรงนี้)
const int motorLeftDir1 = 5;  const int motorLeftDir2 = 6;  const int motorLeftSpeed = 9;
const int motorRightDir1 = 7; const int motorRightDir2 = 8; const int motorRightSpeed = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // (นำการตั้งค่า pinMode มอเตอร์จากโค้ดที่ 1 มาใส่ตรงนี้)
  pinMode(motorLeftDir1, OUTPUT); pinMode(motorLeftDir2, OUTPUT); pinMode(motorLeftSpeed, OUTPUT);
  pinMode(motorRightDir1, OUTPUT); pinMode(motorRightDir2, OUTPUT); pinMode(motorRightSpeed, OUTPUT);
  
  analogWrite(motorLeftSpeed, 130);  // ปรับความเร็วให้พอดี
  analogWrite(motorRightSpeed, 130);
  
  Serial.begin(115200);
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ตรรกะการหลบหลีก (Process)
  if (distance > 0 && distance < 20) { 
    // ถ้าเจอสิ่งกีดขวางในระยะ 20 ซม.
    stopBot();
    delay(500);
    moveBackward();
    delay(500);  // ถอยหลังนิดหน่อย
    turnRight(); // หันขวาเพื่อเปลี่ยนทิศ
    delay(600);
  } else {
    // ทางสะดวก เดินหน้าต่อไป
    moveForward();
  }
  
  delay(50); // หน่วงเวลาเล็กน้อยเพื่อให้เซ็นเซอร์ทำงานเสถียร
}

// --- ฟังก์ชันอ่านค่าระยะทางจากเซ็นเซอร์ Ultrasonic ---
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000); // กำหนด Timeout กันค้าง
  if (duration == 0) return 999; // ถ้าหาไม่เจอให้ส่งค่าไกลๆ กลับไป
  
  long distanceCm = duration * 0.034 / 2; // คำนวณเป็นเซนติเมตร
  return distanceCm;
}

// (นำฟังก์ชัน moveForward, moveBackward, turnRight, stopBot จากโค้ดที่ 1 มาใส่ตรงนี้)
void moveForward() { digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, HIGH); digitalWrite(motorRightDir2, LOW); }
void moveBackward() { digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, HIGH); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH); }
void turnRight() { digitalWrite(motorLeftDir1, HIGH); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, HIGH); }
void stopBot() { digitalWrite(motorLeftDir1, LOW); digitalWrite(motorLeftDir2, LOW); digitalWrite(motorRightDir1, LOW); digitalWrite(motorRightDir2, LOW); }
