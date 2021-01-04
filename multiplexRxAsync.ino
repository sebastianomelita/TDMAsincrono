// definizione dei pin di ciascun segmento RX
#define NSTEP  1000
#define TBASE  250

unsigned long tbase = TBASE;
unsigned long prec = 0;
byte led1 = 10;
byte led2 = 11;
byte led3 = 12;
byte led4 = 13;
unsigned long step=0;
byte slots[4];
byte x;

void setup()
{
  Serial.begin(19200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}
 
void loop()
{
	if(Serial.available()) {
		/* legge l'ultimo byte in arrivo */
		x = Serial.read();
		slots[0] = bitRead(x, 0);
		slots[1] = bitRead(x, 1);
		slots[2] = bitRead(x, 2);	
		slots[3] = bitRead(x, 3);
		digitalWrite(led1, slots[0]);
		digitalWrite(led2, slots[1]);
		digitalWrite(led3, slots[2]);
		digitalWrite(led4, slots[3]);
		//Serial.println(slots[0]);
		//Serial.println(slots[1]);
		//Serial.println(slots[2]);
		//Serial.println(slots[3]);
		//Serial.println("---------------------------------------------");
	}
}



