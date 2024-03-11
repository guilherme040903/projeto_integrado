//link tinkercad https://www.tinkercad.com/things/2zQaOQsdDPz-protipoveicular

// Sensor de presença

int echo_pin = 6,
	trig_pin = 7,
	distancia,
	tempo;

// motores
int	motor_1 = 2,
	motor_2 = 5,
	motor_3 = 3,
	motor_4 = 4;


void setup(){
	pinMode(trig_pin, OUTPUT);
	pinMode(echo_pin, INPUT);

  	pinMode(motor_1 ,OUTPUT);
  	pinMode(motor_2 ,OUTPUT);
  	pinMode(motor_3 ,OUTPUT);
  	pinMode(motor_4 ,OUTPUT);
	
  	Serial.begin(9600);
}

void loop(){
//	fazendo a leitura de distância
	
	digitalWrite(trig_pin,LOW);
 	delayMicroseconds(2);
  
  	digitalWrite(trig_pin, HIGH);
  	delayMicroseconds(10); 
  	digitalWrite(trig_pin,LOW);
  
	tempo = pulseIn(echo_pin, HIGH);

//	calculando a distância
	distancia = tempo/58.2;
  
  	Serial.println(distancia);
  	
//	ativando os motores caso seja necessário
	if(distancia < 50){
		digitalWrite(motor_1, LOW);
  		digitalWrite(motor_2, LOW);
		digitalWrite(motor_3, LOW);
  		digitalWrite(motor_4, LOW);

  	} else if (distancia >= 50) {
		digitalWrite(motor_1, HIGH);
  		digitalWrite(motor_2, HIGH);
		digitalWrite(motor_3, HIGH);
  		digitalWrite(motor_4, HIGH);
      
    	}
  	
	delay(1000);
}
