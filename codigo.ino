#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN A4       // Pino de dados do sensor DHT
#define DHTTYPE DHT22  // Tipo do sensor DHT (DHT22 neste caso)
#define LDRPIN A0      // Pino analógico para o sensor de luminosidade

#define GREEN_LED 4    // Pino do LED verde
#define YELLOW_LED 3   // Pino do LED amarelo
#define RED_LED 2      // Pino do LED vermelho
#define BUZZER_PIN A1   // Pino do Buzzer

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);

unsigned long previousMillis = 0;  // Armazena o tempo da última atualização
const long interval = 500;        // Intervalo de atualização (5 segundos)


int display_humidity = 0;
int display_temp = 0;

float humidity = 55.0;
float temperature = 16.0;
int lightIntensity = 0;

int light_sensor_max = 670;
int light_sensor_min = 6;

int mappedlightIntensity=0;

int ambiente_escuro = 20;
int ambiente_intmeia_luz = 70;


int display_status = 11;  // cursor

int error = 0;
int red_led_on = 0;
int yellow_led_on = 0;
int green_led_on = 0;

// averages
int temp_table[11];
int humid_table[11];
int light_table[11];
int readings10=0;
int readings05=0;

void setup() {

  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  byte name1x13[] = {
    B01000,
    B00100,
    B00010,
    B00010,
    B00010,
    B00010,
    B00100,
    B01000
  };

  byte name0x3[] = {
    B00010,
    B00100,
    B01000,
    B01000,
    B01000,
    B01000,
    B00100,
    B00010
  };

  byte name0x5[] = {
    B01111,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B01110
  };

  byte name0x8[] = {
    B11111,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B11111
  };

  byte name0x11[] = {
    B11100,
    B10010,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001
  };

  byte name1x5[] = {
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B11110
  };

  byte name1x8[] = {
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B11111
  };

  byte name1x11[] = {
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10001,
    B10010,
    B11100
  };

  lcd.createChar(0, name1x13);
  lcd.createChar(1, name0x3);
  lcd.createChar(2, name0x5);
  lcd.createChar(3, name0x8);
  lcd.createChar(4, name0x11);
  lcd.createChar(5, name1x5);
  lcd.createChar(6, name1x8);
  lcd.createChar(7, name1x11);



  lcd.setCursor(13, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 0);
  lcd.write(byte(1));
  lcd.setCursor(5, 0);
  lcd.write(byte(2));
  lcd.setCursor(8, 0);
  lcd.write(byte(3));
  lcd.setCursor(11, 0);
  lcd.write(byte(4));
  lcd.setCursor(5, 1);
  lcd.write(byte(5));
  lcd.setCursor(8, 1);
  lcd.write(byte(6));
  lcd.setCursor(11, 1);
  lcd.write(byte(7));

for ( int y=1; y < 100 ;y++ )
  {
  lcd.scrollDisplayLeft();
  delay(100);
}


  
  lcd.clear();
}

void loop()
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
   
    humidity = 0;
    temperature = 0;
    lightIntensity = 0;

    // Leituras dos sensores
    for (int i = 0; i < 5; i++) {
       if ( error == 1)  {
      tone(BUZZER_PIN, 262, 1000); // Plays 262Hz tone for 1s
       }



      humidity += dht.readHumidity();
      temperature += dht.readTemperature();
      lightIntensity += analogRead(LDRPIN);
      delay(1000);  // Aguarda um segundo entre as leituras
    }

    for ( int i=readings10  ;i >= 0 ; i--)
    {

    }




    display_humidity = humidity /= 5;  // Calcula a média das leituras de umidade
    display_temp = temperature /= 5;  // Calcula a média das leituras de temperatura
    lightIntensity /= 5;  // Calcula a média das leituras de luminosidade

    mappedlightIntensity=map(lightIntensity, light_sensor_min,light_sensor_max, 0,100);
    
    // Exibe os valores no display LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp:    ");
    lcd.setCursor(5, 0);
    lcd.print(display_temp);
    lcd.print((char) 223);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("Umi:    ");
    lcd.setCursor(5, 1);
    lcd.print(display_humidity);
    lcd.print("%");

     error = 0;
     yellow_led_on = 0;
     red_led_on = 0;
     green_led_on = 0;

    // Verifica as condições de temperatura
    if ( display_temp >= 10 &&  display_temp <= 15) {
      lcd.setCursor(display_status , 0);
      lcd.print("OK   ");
      yellow_led_on = 0;
    }

    if ( display_temp > 15) {  // Temperatura alta
      lcd.setCursor(display_status , 0);
      lcd.print("Alta ");
      error = 1;
      yellow_led_on = 1;
    }

    if ( display_temp < 10) {  // Temperatura baixa
      lcd.setCursor(display_status , 0);
      lcd.print("Baixa");
      error = 1;
      yellow_led_on = 1;
    }


    // Verifica as condições de umidade
    if (display_humidity >= 50 && display_humidity <= 70) {
      lcd.setCursor(display_status , 1);
      lcd.print("OK ");
     }

    if ( display_humidity > 70) {  // umidade alta
      lcd.setCursor(display_status , 1);
      lcd.print("Alta ");
      error = 1;
      red_led_on=1;
      green_led_on = 0;
    }

    if ( display_humidity < 50) {  // umidade baixa
   
        lcd.setCursor(display_status , 1);
        lcd.print("Baixa");
        error = 1;
        red_led_on=1;
        green_led_on = 0;
      }

      // Aguarda antes da próxima atualização
      delay(5000);

      lcd.clear();



      lcd.setCursor(0, 0);
      lcd.print("Ambiente");
      Serial.print("ambiente_escuro=");
      Serial.print(ambiente_escuro);
      Serial.print("\t < lightIntensity=");
      Serial.print(mappedlightIntensity);
      Serial.print(" > \tambiente_intmeia_luz=");
      Serial.println(ambiente_intmeia_luz);
      // Verifica as condições de luminosidade
      
      if (mappedlightIntensity < ambiente_escuro) {  // Ambiente escuro
        lcd.setCursor(0, 1);
        lcd.print(" a escuro luz");
        green_led_on=1;
      }

      if (mappedlightIntensity >= ambiente_escuro &&  mappedlightIntensity < ambiente_intmeia_luz ) {  // Meia luz
        lcd.setCursor(0, 1);
        lcd.print("a meia luz");
        green_led_on=0;
        yellow_led_on = 1;
      }

      if (mappedlightIntensity >= ambiente_intmeia_luz )      {  // Ambiente muito claro
        red_led_on = 1;
        lcd.setCursor(0, 1);
        lcd.print("a muito claro");
        error = 1;
        green_led_on=0;
        red_led_on=1;
      }
      digitalWrite(GREEN_LED, green_led_on);
      digitalWrite(YELLOW_LED, yellow_led_on);
      digitalWrite(RED_LED, red_led_on);

    }
      if ( error == 1)  {
      tone(BUZZER_PIN, 262, interval); // Plays 262Hz tone for interval
    }


    if (readings10 < 10) readings10++;
    if (readings05 < 5 ) readings05++;

  }
