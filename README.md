# Rootry (formerly SoilHawk) | Automatic Irrigation System

An evolving hardware IoT project focused on providing low-cost, high-efficiency, solar-powered precision irrigation for smallholder farms in India. What began as an award-winning science exhibition prototype has evolved into a field-tested product architecture achieving significant water conservation.

**Key Achievements:**
* 🏆 **Runner-up (2nd Worldwide):** UPenn EcoVenture Global Climate Venture Competition (2024)
<img width="734" height="567" alt="Saksham Certificate_page-0001" src="https://github.com/user-attachments/assets/432f06de-876c-4dd0-b586-a977b3d437c4" />

* 🏆 **Winner:** CBSE National Science Exhibition (2019) & Regional Science Exhibition (2018-19)
* 🌟 **Government Recognition:** Recommended as *Jal Doot* by the Ministry of Jal Shakti

---

## 🚀 The Product Evolution

This project has undergone several architectural iterations, moving from a basic microcontroller logic proof-of-concept to a distributed ML concept, and finally to a robust, custom ESP32 IoT system.

### Phase 3: Rootry v2 (Current Architecture - 2024 to Present)
The current iteration focuses on productization, robustness, and real-world deployment constraints. Designed for areas with limited grid power and no smartphone access, keeping the unit cost under ₹4,000.

* **Hardware Stack:** * Custom PCB designed in **KiCad**.
  * **MCU:** ESP32-S3 (Dual-core 240MHz) replacing the legacy Arduino architecture.
  * **Connectivity:** Hybrid Dual GSM (SIM800L via UART AT commands) + WiFi interface.
  * **Power:** 10W Solar Panel + 12V SLA Battery with PWM charge controller.
* **Firmware Improvements:**
  * Replaced all legacy `delay()` calls with non-blocking loops using `millis()`.
  * Implemented **Hysteresis Band Control**: Pump turns ON below 30% moisture and OFF above 50% to prevent rapid toggling.
  * **Adaptive Temperature Compensation:** Stop thresholds dynamically raise to 60% when ambient temperatures exceed 35°C (read via DHT22).
  * **Web Dashboard:** `ESPAsyncWebServer` integration for a real-time localized dashboard.

---

### Phase 2: SoilHawk (2023 - ImpactHack Sponsor Track Winner)
A conceptual expansion into a distributed, multi-node architecture utilizing both ground-based sensing and aerial diagnostic telemetry. This phase validated the integration of machine learning for targeted agricultural interventions.

<img width="960" height="540" alt="Add your next level pages (1)" src="https://github.com/user-attachments/assets/b319c886-90ae-45dc-ad46-67b0bb56fc52" />

---

### Phase 1: The Foundation (2019 Prototype)
The genesis of the project. A standalone prototype built to demonstrate the core viability of automated soil moisture management to prevent soil degradation and conserve water. 

* **The Setup:** Arduino Uno, FC-28 Soil Moisture Sensor, DHT11 Temperature/Humidity Sensor, 16x2 LCD, 5V Relay for water pump actuation, and a basic GSM module.
* **Logic:** Basic linear logic. The system reads analog moisture thresholds. If the soil falls below `MAXDRYNESS 600`, the pump is triggered, and the GSM module dispatches an SMS alert ("Motor Start") to the farmer.
* **Validation:** Documented in a formal research paper analyzing the mathematical and environmental impact, endorsed by Dr. Sumeet Gill, Professor of Computer Science at MDU Rohtak.

<img width="512" height="391" alt="image" src="https://github.com/user-attachments/assets/a81ee0ab-c697-4eec-b29b-c04e274af115" />
