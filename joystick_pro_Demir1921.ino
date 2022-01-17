#define joyX A0
#define joyY A1
int xValue=0;
int yValue=0;
int button=2;
int button_state=0;
const int SW_pin = 2;

int led1=13;
int led2=8;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(button,OUTPUT);
 pinMode(SW_pin, INPUT);
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

  int switch_status = digitalRead(SW_pin);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  
 if (switch_status == 0){
  digitalWrite (12, HIGH);
 }
 else {
  digitalWrite (12, LOW);
 }
 if (xValue==507&& yValue==1023){
 Serial.println("DO");
   tone(12, 262); 
   digitalWrite(led1,HIGH);
delay(1000);
digitalWrite(led1,LOW);
}
if (xValue<511 && yValue==0){
 Serial.println("RE");
   tone(12, 294); 
   digitalWrite(led2,HIGH);
delay(1000);
digitalWrite(led2,LOW);
}
}
