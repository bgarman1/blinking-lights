
 
 int ledPin = 11;   //define varaible
  
  int input1 = 0;  // input for heat resistor

  int value = 0;  // the varable to store the read value

  int loopflag = 0; // change from on to off

  
void setup() 
{

  Serial.begin(9600); 

  pinMode(ledPin,OUTPUT); // led light useing pin 11


}


void loop()    //main               // put your main code here, to run repeatedly:
{
value = analogRead(input1);

Serial.println(value);

if( value == 0 )

        {      
              
                    if(loopflag == 0)
                   {
                      
                        for(int dim = 55; dim > 0; dim-- )
                                      {
                                        analogWrite(ledPin, dim);
                                        delay(30);
                                      }
                        for(int dim = 0; dim < 55; dim++ )
                                      {
                                        analogWrite(ledPin, dim);
                                        delay(30);
                                      }
                      
                      
                        loopflag = 1;
                   }             
                  
                   else if(loopflag == 1)
                   {
                    Serial.print("qw");
                    digitalWrite(ledPin, LOW);
                    delay(500);
                    loopflag = 0;
                   }
       
        
        }   

    }

                   

   
