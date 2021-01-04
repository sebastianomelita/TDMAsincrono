// definizione dei pin di ciascun segmento TX
#define NSTEP  10000
#define TBASE  125

unsigned long tbase = TBASE;
unsigned long prec = 0;
byte btn1 = 2;
byte btn2 = 3;
byte btn3 = 4;
byte btn4 = 5;
unsigned long step=0;
byte slots[4];
byte x = 0b00000000;

void setup()
{
  Serial.begin(19200);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);  
  pinMode(btn4, INPUT);
}
 
void loop()
{
	if((millis()-prec) > tbase) //schedulatore con funzione di antirimbalzo (legge ogni 50 mSec)
	{
		prec = millis(); 
		step = (step + 1) % NSTEP;
			
		//legge valore attuale dell'ingresso
		slots[0] = digitalRead(btn1);
		slots[1] = digitalRead(btn2);
		slots[2] = digitalRead(btn3);		
		slots[3] = digitalRead(btn4);
		bitWrite(x, 0, slots[0]);  
		bitWrite(x, 1, slots[1]);  
		bitWrite(x, 2, slots[2]);  
		bitWrite(x, 3, slots[3]); 
        bitWrite(x, 4, 0);  
		bitWrite(x, 5, 0);  
		bitWrite(x, 6, 0);  
		bitWrite(x, 7, 0); 		
		Serial.write(x);
	}
}



