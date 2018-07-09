const int echoPin = 2;
const int trigPin = 1;
// defines variables
double distance1,d1,duration;
int x;
double d2 = 4;
void setup() {
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT); 
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
//Serial.begin(9600); // Starts the serial communication


}
void reset(){d2=3;}
void getd1()
{
        digitalWrite(trigPin, LOW); // Clears the trigPin
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
        // Calculating the distance
        distance1 = duration*340/2000000;
        if(distance1 < 3 && distance1 > 0)   //Filter
        {d1=distance1;
        }

      if(d1 < d2)
       {
      d2=d1;
      }   
}


void redLight()
{
        digitalWrite(7,HIGH);
        digitalWrite(8,LOW);          //red light on
        digitalWrite(6,LOW);
        //Serial.println("redlight");

  
   
  }

void yellowLight()
{
        digitalWrite(7,LOW);
        digitalWrite(8,HIGH);          //green light on
        digitalWrite(6,LOW);
        //Serial.println("yellowlight");
  
  
  }
void greenLight()
{
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);          //green light on
        digitalWrite(6,HIGH);
        //Serial.println("greenlight");

  
  }

void loop() {
  getd1();
 
  
      while(d2 < 3 && d2 > 1.57) //3.5,2
      {
      greenLight();
         x+=1;
         delay(500);
          //if no change for 3 mins shut off all outputs
        if(x > 100)
      {
        while (d1 < 3 && d1 > 1.57)
      {
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);         
        digitalWrite(7,LOW);
        digitalWrite(5,LOW);

        getd1();
        
        x=0;
      }
        d2=3;
      }
        
     
        getd1(); 
     if(d1> 1.80){
      reset();}
  }
  
 while(d2 < 1.57 && d2 > .09)
  { //1.5,07
  
  yellowLight();
  
    x+=1;
    delay(500);
         
          //if no change for 3 mins shut off all outputs
          
        if(x>100)
        {while (d1 > .09 && d1 < 1.57)
        {
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);         
        digitalWrite(7,LOW);
        digitalWrite(5,LOW);
        
        getd1();
        
        x=0;
        }
        d2= 1.57;
        }
          
   
    
     getd1();
     if(d1> 1.80){
      reset();}  
  }
 
  while(d2 < .08 && d2 > 0.00){//.06,0.00
    
    redLight();
    x+=1;
    delay(500);
        
          //if no change for 3 mins shut off all outputs
        if(x>100){
          while (d1 < .08 && d1 > 0.00 && d1<1.80)
        
        {
        digitalWrite(8,LOW);
        digitalWrite(6,LOW);         
        digitalWrite(7,LOW);
        digitalWrite(5,LOW);

        getd1();
        
        x=0;
        }
        d2=  3;
        }
      
   
    getd1();
     if(d1> 1.80){
      reset();}   
  }
 
     
}



