#define pinVRx A2
#define pinVRy A1
#define pinSW 2

#define LED1 3
#define LED2 4

#define LEDVERDE 5
#define LEDVERMELHO 6
#define BEEP 7
int res = 0;
int cores = 0;
void setup() {
  pinMode(pinVRx, INPUT);
  pinMode(pinVRy, INPUT);
  pinMode(pinSW, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDVERMELHO, OUTPUT);
  pinMode(BEEP, OUTPUT);
  
  Serial.begin(9600);

  rando();
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorVRx = analogRead(pinVRx);
  int valorVRy = analogRead(pinVRy);
  bool statusSW = digitalRead(pinSW);

  if(valorVRx >= 500){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    res = 1;
  }else if(valorVRx <= 400){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    res = 2;
  }else if(!statusSW){
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, HIGH);
    res = 3;
  }else{
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }
  
  if(res == cores){
    digitalWrite(BEEP, HIGH);
    delay(255);
    digitalWrite(BEEP, LOW);
    rando();
  }
}

void rando(){
  int aleatorio = random(1,4);
  if(aleatorio == 1){
    digitalWrite(LEDVERDE,HIGH);
    digitalWrite(LEDVERMELHO, LOW);
    cores = 1;
  }else if(aleatorio == 2){
    digitalWrite(LEDVERMELHO, HIGH);
    digitalWrite(LEDVERDE, LOW);
    cores = 2;
  }else{
    digitalWrite(LEDVERMELHO, HIGH);
    digitalWrite(LEDVERDE, HIGH);
    cores = 3;
  }

  Serial.println(aleatorio);
}
