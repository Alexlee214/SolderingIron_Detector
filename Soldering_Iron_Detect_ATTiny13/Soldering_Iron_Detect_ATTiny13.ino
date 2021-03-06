const byte thermistor = A1; //pin7
const byte buzzer = 1; //pin6
const byte led = 3; //pin2

bool isOn = false;

unsigned long lastBeeped = 0;

void setup(){
  pinMode(thermistor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  checkTemp();
  
  if(isOn == true){
    onStatus();
  }
  else{
    offStatus();
  }
}

void checkTemp(){
  if(analogRead(thermistor) >= 145){
    isOn = true;
  }
  else{
    isOn = false;  
  }
}


void onStatus(){
  digitalWrite(led, HIGH);
  //beep every 6 seconds
  if(millis() - lastBeeped >= 6000){
      analogWrite(buzzer, 4);
      delay(200);
      digitalWrite(buzzer, LOW);
      lastBeeped = millis();
  }    
}

void offStatus(){
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}

