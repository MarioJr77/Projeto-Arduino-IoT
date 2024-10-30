// C code
//
int ledVermelho = 8;
int buzzer = 7;
int motorVentilador = 6;
int pinTmp = A0;
float valorTmp = 0.0;
float tempFinal = 0.0;

void setup()
{
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motorVentilador, OUTPUT);
  pinMode(pinTmp, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valorTmp = analogRead(pinTmp);
  tempFinal = map(((valorTmp - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(tempFinal);
  
  if(tempFinal >= 30){
    digitalWrite(motorVentilador, HIGH);
  } else {
  	digitalWrite(motorVentilador, LOW);
  }
  
  if(tempFinal > 50){
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzer, HIGH);
  } else {
  	digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, LOW);
  }    
  
  delay(500); 
} 