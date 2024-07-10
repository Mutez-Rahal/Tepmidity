#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define WIFI_SSID "Iot Wifi" // WiFi Adı
#define WIFI_PASSWORD "iotwifi2024" // WiFi Şifresi

#define FIREBASE_HOST "dht-iot-e0d62-default-rtdb.europe-west1.firebasedatabase.app" // Proje ID
#define FIREBASE_AUTH "ustog18HPHLDzrYe6bj1iG637SBOQPB3WHoRLp4F" // Gizli anahtar

#define DHTTYPE DHT11
#define DHTPIN 2 // D4
DHT dht(DHTPIN, DHTTYPE); // DHT sensörünü oluşturma

void setup() {
  Serial.begin(115200);  
  // İnternete bağlanmak
  connectToWiFi();
  // Firebase bağlantısını başlatma
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  // DHT sensörünü başlatma
  dht.begin();
}

void loop() {
  // Nem ve sıcaklık değerlerini okuma
  float nem = dht.readHumidity();
  float sicaklik = dht.readTemperature();

  // Nem ve sıcaklık değerlerini Serial monitöra yazdırma
  printSensorData(nem, sicaklik);

  // verileri firebase'e gönderme
  sendDataToFirebase(nem, sicaklik);
}

// WiFi'ye bağlanma metodu
void connectToWiFi() {
  // Belirtilen WiFi ağına bağlamak
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("");
  Serial.println("İnternete bağlanılıyor....");
  // WiFi bağlantısının tamamlanmasını beklemek
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("bağlandı!!!");
}

// Nem ve sıcaklık verilerini serial monitöre yazma
void printSensorData(float nem, float sicaklik) {
  Serial.print("Nem: ");
  Serial.print(nem);
  Serial.println(" %");
  Serial.print("Sıcaklık: ");
  Serial.print(sicaklik);
  Serial.println(" C°");
}

// Nem ve sıcaklık verilerini Firebase'e gönderme
void sendDataToFirebase(float nem, float sicaklik) {
  // Alınan nem ve sıcaklık değerlerinin geçerli olup olmadığını kontrol etmek
  if (isnan(nem) || isnan(sicaklik)) { // isnan = is Not a Number
    Serial.println("DHT sensöründen okuma işlemi başarısız!");
    delay(1000);
    return;
  }
  // Firebase'e   gönderilecek veriler
  Firebase.setFloat("/Nem", nem);
  Firebase.setFloat("/Sicaklik", sicaklik);
  // Son yapılan Firebase işleminin başarılı olup olmadığını kontrol eder
  if (Firebase.failed()) {
    Serial.println("Hata: "+ Firebase.error());
    Serial.println("Verileri Firebase'e gönderme işlemi başarısız!");
  } else {
    Serial.println("Veriler Firebase'e gönderilmiştir!");
  }
  Serial.println("------------------------------------------");
  delay(3000);
}
