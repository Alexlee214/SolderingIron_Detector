const byte thermistor = A0;
const byte buzzer = 5;
const byte led = 2;

bool isOn = false;

unsigned long lastBeeped = 0;

void setup(){
  pinMode(thermistor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  checkTemp();
  
  if(isOn == true){
    onStatus();
  }
  else{
    offStatus();
  }
  Serial.print("isOn is : ");
  Serial.println(isOn);
}

void checkTemp(){
  Serial.println(analogRead(thermistor));
  if(analogRead(thermistor) >= 425){
    isOn = true;
  }
  else{
    isOn = false;  
  }
}


void onStatus(){
  digitalWrite(led, HIGH);
  //beep every 10 seconds
  if(millis() - lastBeeped >= 10000){
      analogWrite(buzzer, 2);
      delay(200);
      digitalWrite(buzzer, LOW);
      lastBeeped = millis();
  }    
}

void offStatus(){
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}

