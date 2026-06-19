# IoT Basic Experiment

서원대학교 2학년 1학기 **IoT기초실험** 실습 자료를 정리한 저장소입니다.  
Arduino 센서 예제, Wi-Fi/Bluetooth 실습, App Inventor 자료, 기말 프로젝트를 함께 관리합니다.

---

## ✨ 핵심 내용

| 분류 | 내용 |
| --- | --- |
| 보드 | Arduino 계열 실습 |
| 센서 | 조도, 불꽃, 가스, 마이크, 빗물, 초음파, 온습도 등 |
| 통신 | Wi-Fi, Bluetooth LE, App Inventor 연동 |
| 프로젝트 | 스마트 주차장, 스마트 조명, 침입자 감지 알림 |

---

## 📂 저장소 구조

| 경로 | 설명 |
| --- | --- |
| `3led/`, `blinker/`, `lcd/` | 기본 출력과 LCD 실습 |
| `CDSSensor*/`, `flame*/`, `gas/`, `rain*/`, `mic*/` | 센서별 입력 실습 |
| `wifi/`, `weather_wifi/`, `corona_wifi/`, `fine_dust/` | Wi-Fi 기반 데이터 수집 실습 |
| `bluetooth_test/`, `블루투스 LE */` | Bluetooth LE와 App Inventor 연동 |
| `app inventor 예제/` | `.aia` 예제 프로젝트 |
| `기말 프로젝트/SmartCarPark` | 스마트 주차장 프로젝트 서브모듈 |

---

## 🔗 연결 프로젝트

| 경로 | 연결 저장소 | 설명 |
| --- | --- | --- |
| `기말 프로젝트/SmartCarPark` | [`hy040504/IoTProject-SmartCarPark`](https://github.com/hy040504/IoTProject-SmartCarPark) | Arduino Uno 3대와 Node.js 서버를 사용하는 스마트 주차장 |
| `블루투스 LE 스맡 조명제어/appinventor-mcp` | [`rhyumiranda/appinventor-mcp`](https://github.com/rhyumiranda/appinventor-mcp) | App Inventor MCP 도구 |
| `블루투스 LE 침입자 감지 알림/appinventor-mcp` | [`rhyumiranda/appinventor-mcp`](https://github.com/rhyumiranda/appinventor-mcp) | App Inventor MCP 도구 |

---

## 🧪 주요 실습

| 실습 | 설명 |
| --- | --- |
| LED / LCD | 기본 출력 제어와 I2C LCD 표시 |
| 센서 입력 | 조도, 불꽃, 가스, 빗물, 마이크 센서 값 읽기 |
| Wi-Fi 예제 | 날씨, 미세먼지, 코로나 등 네트워크 기반 데이터 연동 |
| Bluetooth LE | 스마트 조명, 온습도 기록, 침입자 감지 알림 |
| 기말 프로젝트 | 센서, 차단기, LCD, Node.js 서버를 통합한 스마트 주차장 |

---

## ▶️ 실행 방법

각 실습 폴더의 `.ino` 파일을 Arduino IDE에서 열고 보드와 포트를 선택한 뒤 업로드합니다.

```text
Arduino IDE -> File -> Open -> 실습폴더/*.ino
```

App Inventor 자료는 `.aia` 파일을 MIT App Inventor에서 가져와 실행합니다.
