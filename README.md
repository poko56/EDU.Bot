# 🤖 EDU.BOT: The Adaptive Modular Robotic System

<div align="center">

**หุ่นยนต์เพื่อการศึกษาแบบโมดูลาร์ที่ปรับเปลี่ยนรูปแบบได้ สำหรับนักเรียนมัธยมศึกษาตอนปลาย**

[![Hardware: Open Source](https://img.shields.io/badge/Hardware-Open%20Source-blue.svg?style=for-the-badge)]()
[![Build: 3D Printed](https://img.shields.io/badge/Build-3D%20Printed%20(FDM)-orange.svg?style=for-the-badge)]()
[![Platform: Arduino/ESP32](https://img.shields.io/badge/Platform-Arduino%20%7C%20ESP32-green.svg?style=for-the-badge)]()
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)]()

</div>

---

## 📖 เกี่ยวกับโครงงาน (About the Project)

[cite_start]**EDU.BOT** คือ แพลตฟอร์มหุ่นยนต์เพื่อการศึกษาที่ออกแบบภายใต้แนวคิด **"ระบบเปิด (Open Design)"** และ **"โครงสร้างแบบโมดูลาร์ (Modular Design)"** [cite: 47] [cite_start]โครงงานนี้สร้างขึ้นมาเพื่อเป็นสื่อการเรียนรู้ทางด้านวิศวกรรมและการเขียนโปรแกรมควบคุม โดยมุ่งเน้นที่การพัฒนาฮาร์ดแวร์ โครงสร้างทางกล และระบบอิเล็กทรอนิกส์พื้นฐาน [cite: 65]

> [cite_start]🎯 **เป้าหมายหลัก:** เพื่อใช้เป็นสื่อการเรียนรู้และต่อยอดกิจกรรมด้าน STEM ที่มีความยืดหยุ่นสูง ช่วยให้ผู้เรียนทำความเข้าใจโครงสร้างเชิงกลและประยุกต์ใช้นวัตกรรมได้โดยไม่ถูกจำกัดด้วยรูปแบบที่ตายตัว [cite: 45]
> 
> [cite_start]🧑‍🎓 **กลุ่มเป้าหมาย:** นักเรียนระดับชั้นมัธยมศึกษาตอนปลาย [cite: 45]

---

## 🥊 ทำไมต้อง EDU.BOT? (Market Comparison)

[cite_start]EDU.BOT ถูกพัฒนาขึ้นเพื่ออุดช่องโหว่ (Pain Points) ของชุดหุ่นยนต์ในท้องตลาด โดยเป็นจุดกึ่งกลางที่สมบูรณ์แบบระหว่าง **"คุณภาพ"** และ **"ราคา"**[cite: 46]:

| คุณสมบัติ | ❌ หุ่นยนต์สำเร็จรูป (แบรนด์ดัง) | ❌ ชุดคิทอะคริลิก (ราคาประหยัด) | ✅ **EDU.BOT (โครงงานของเรา)** |
| :--- | :--- | :--- | :--- |
| **ระบบนิเวศ** | [cite_start]เป็นระบบปิด (Closed Ecosystem) ใช้ได้แค่เซ็นเซอร์แบรนด์ตัวเอง [cite: 49] | จำกัดเฉพาะบอร์ดที่เจาะรูมาเผื่อ | [cite_start]🌟 **ระบบเปิด (Open Design)** รองรับบอร์ดและเซ็นเซอร์อิสระ [cite: 47] |
| **โครงสร้าง** | แข็งแรงมาก | [cite_start]เปราะบาง แตกหักง่าย [cite: 49] | [cite_start]🌟 **ผลิตจาก 3D Print (PLA/PETG)** แข็งแรงและพิมพ์อะไหล่เองได้ [cite: 61] |
| **การติดตั้งอุปกรณ์**| ยึดตามบล็อกของแบรนด์เท่านั้น | [cite_start]รูเจาะตายตัว (Fixed Mounting) ปรับเปลี่ยนไม่ได้ [cite: 49] | [cite_start]🌟 **ระบบร่องสไลด์ (Slot) และตาราง (Grid)** ปรับระยะได้อิสระ [cite: 63] |
| **ราคา/การเข้าถึง** | [cite_start]ราคาสูงมาก [cite: 46] | ราคาถูก | [cite_start]🌟 **ต้นทุนต่ำ (Low-Cost) แต่ยืดหยุ่นสูงเทียบเท่าแบรนด์ดัง**  |

---

## ✨ ขีดความสามารถและฟีเจอร์เด่น (Key Features)

- [cite_start]🧩 **Modular Platform:** โครงสร้างหลัก (Main Body) และส่วนขยาย (Extension Modules) สามารถถอดประกอบและสลับสับเปลี่ยนได้อย่างอิสระ [cite: 59]
- [cite_start]📏 **Universal Mounting System:** รองรับการติดตั้งเซ็นเซอร์หลายชนิด (เช่น Ultrasonic, Line Tracking) ด้วยระบบ Slot และ Grid ระยะมาตรฐาน ทำให้จูนตำแหน่งได้ละเอียดระดับมิลลิเมตร [cite: 63]
- [cite_start]🏎️ **4WD Ready:** รองรับการติดตั้งมอเตอร์ไฟฟ้ากระแสตรง (DC Motor) พร้อมชุดเกียร์ได้สูงสุด 4 ตัว โดยออกแบบแท่นยึดมอเตอร์แยกชิ้น เพื่อง่ายต่อการซ่อมบำรุง [cite: 62, 73]
- [cite_start]🧠 **Hardware Flexibility:** มีพื้นที่ออกแบบเฉพาะให้รองรับบอร์ดไมโครคอนโทรลเลอร์มาตรฐาน เช่น Arduino หรือ ESP32 [cite: 64]
- [cite_start]🔋 **Power Management:** รองรับแบตเตอรี่ Li-ion 18650 จำนวน 2 ก้อน (7.4V - 8.4V) ทำงานแบบ Centralized Control ผ่านวงจรแปลงไฟ (Buck Converter/LDO) [cite: 64, 74]

---

## ⚙️ หลักการทำงานของระบบ (System Architecture)

[cite_start]ระบบของ **EDU.BOT** ทำงานตามวงจรการควบคุม (Control Loop) ดังนี้[cite: 75]:

1. 📡 **Input (รับค่า):** อ่านค่าสภาพแวดล้อมจากเซ็นเซอร์ที่ติดตั้งบนส่วนขยาย (Extension Module)
2. 🧮 **Process (ประมวลผล):** ไมโครคอนโทรลเลอร์คำนวณตามอัลกอริทึม (เช่น PID Control สำหรับเดินตามเส้น หรือ Logic เปรียบเทียบสำหรับหลบหลีกสิ่งกีดขวาง)
3. ⚙️ **Output (สั่งการ):** ส่งสัญญาณ PWM ไปควบคุมความเร็วและทิศทางของมอเตอร์ DC ทั้ง 4 ตัวให้เคลื่อนที่ตามที่ตั้งโปรแกรมไว้

---

## 📂 โครงสร้าง Repository (Directory Structure)

```text
EDU.BOT/
├── 📁 Hardware_3D/       # ไฟล์โมเดล 3 มิติ (STL/STEP) สำหรับ 3D Printer (FDM)
├── 📁 Software/          # Source code ตัวอย่าง (C/C++ สำหรับ Arduino/ESP32)
├── 📁 Docs/              # คู่มือการประกอบ (Assembly Guide), วงจรสายไฟ (Wiring Diagram)
└── 📄 README.md          # รายละเอียดของโครงงาน
