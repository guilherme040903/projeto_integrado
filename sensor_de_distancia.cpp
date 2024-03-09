// Link do projeto no tinkercad https://www.tinkercad.com/things/2zQaOQsdDPz-sensordedistancia

int echo_pin = 6,
	trig_pin = 7,
	distancia = 0,
	tempo = 0;

void setup(){
	pinMode(trig_pin, OUTPUT);
	pinMode(echo_pin, INPUT);
  	Serial.begin(9600);
}

void loop(){
  	digitalWrite(trig_pin,LOW);
 	 delayMicroseconds(2);
  
  	digitalWrite(trig_pin, HIGH);
  	delayMicroseconds(10); 
  	digitalWrite(trig_pin,LOW);
  
	tempo = pulseIn(echo_pin, HIGH);
  	distancia = tempo/58.2;

	Serial.print("Distancia medida: ");
	Serial.print(distancia);
	Serial.println("cm");
  
  delay(1000);
}
