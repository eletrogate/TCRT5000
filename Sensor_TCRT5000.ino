#define led 10
#define saidaSensor 7

int Time;
int lasTime;
int difference;
int IsUpdated;

void setup(){
   Time = lasTime = difference = 0;
   pinMode(led, OUTPUT); // Pino para ativar o led
   pinMode(saidaSensor, INPUT); // Pino para ler o sinal no coletor do fototransistor
   Serial.begin(9600); // Inicializa a porta serial com baud rate de 9600
}

void loop(){
  bool leituraSensor = digitalRead(saidaSensor);

  if (leituraSensor == 0){
    Time = millis();
    difference = (Time - lastTime); // Calcula o tempo em segundos
    IsUpdated++;
    digitalWrite(led, HIGH);
    calcSpeed(difference, IsUpdated);
  }else{
    IsUpdated = 0;
    digitalWrite(led, LOW);
    lastTime = Time;
  }
  delay(10);
}

void calcSpeed(unsigned long Time, int IsUpdated){
  int i;
  float vel;
  if (IsUpdated == 1){
    Serial.println("Tempo");
    Serial.println(Time);
    SpeedVector[counter++] = (Raio*2*PI/Time)*1000;
    if (counter == N){
      counter = 0;
      for (i=0; i<N; i++){
        vel =+ SpeedVector[i];
      }
      Serial.println("Velocidade(m/s) =");
      Serial.println(vel/N ,4);
    }
  }
}