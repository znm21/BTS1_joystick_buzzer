#define joyX A0
#define joyY A1
int xValue=0;
int yValue=0;
int button=2;
int button_state=0;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(button,OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly  

  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  //print the values with to plot or vie
 Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
  delay(300);

 if (xValue<514&& yValue<1023){
 Serial.println("DO");
   tone(12, 262); 
}
if (xValue==514 && yValue<0){
 Serial.println("RE");
   tone(12, 294); 
   
}
if (xValue==1023 && yValue==514){
 Serial.println("MI");
    tone(12, 330);

}
if (xValue==0 && yValue==514){
 Serial.println("FA");
   tone(12, 349);
   
}
if (xValue==1023 && yValue<513){
 Serial.println("SOL");
   tone(12, 392);
}
if (xValue==0 && yValue==0){
 Serial.println("La");
   tone(12, 440);
}
}
