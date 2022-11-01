#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servoDriver= Adafruit_PWMServoDriver(); 
int initialPose[]={90+40,90+40-3,90-40-8,90-5-40,90+3,90-2,90+3,90+5};
int ar[8];
void setup() {
    initCrawl();
    Serial.begin(9600);
}
void initCrawl(){
    servoDriver.begin();
    servoDriver.setOscillatorFrequency(27000000);
    servoDriver.setPWMFreq(50);
    for(int i=0;i<8;i++){
        servoDriver.setPWM(i,0,map(initialPose[i],0,180,130,500));
    }
    balance();
    setShoulderAngle();
    delay(2000);
}
void loop() {
    crawl();
}
void setPose(int a[],int rate){
    //rate=rate/2;
    int max=maxOf(a);
    for(int i=0;i<=max;i++){
          for(int j=0;j<12;j++){
              if(initialPose[j]-a[j]<0){ 
                  servoDriver.setPWM(j,0,map(++initialPose[j],0,180,130,500));
              }
              if(initialPose[j]-a[j]>0){
                  servoDriver.setPWM(j,0,map(--initialPose[j],0,180,130,500));
              }
              Serial.println(initialPose[j]);
          }
          delay(rate);
      }
  
}
int maxOf(int a[]){
    int max=-1,angle;
    for(int i=0;i<12;i++){
        angle=initialPose[i]-a[i];
        if(angle<0){
            angle=angle*-1;
        }
        if(max<=a){
            max=a;
        }
    }
    return max;
}
void crawl()
{
    ar[6]=(90+3)-15;
    ar[5]=initialPose[5]+10;
    ar[2]=(90-40-8)-10;
    setPose(ar,50);
    ar[6]=(90+3);
    ar[5]=initialPose[5];
    balance();
    setPose(ar,50);
    balance();
    delay(50);
    ar[5]=(90-2)+20;
    ar[6]=initialPose[6]-25;
    ar[1]=(90+40-3)+10;
    setPose(ar,50);
    balance();
    ar[5]=(90-2)-5;
    ar[6]=initialPose[6];
    setPose(ar,50);
    balance();
    delay(50);    
    ar[4]=(90+3)+15;
    ar[7]=initialPose[7]-10;
    ar[0]=(90+40)+10;
    setPose(ar,50);
    balance();
    ar[7]=initialPose[7];
    ar[4]=(90+3);
    setPose(ar,50);
    balance();
    delay(50);    
    ar[7]=(90+5)-15;
    ar[4]=initialPose[4]+15;
    ar[3]=(90-40-5)-10;
    setPose(ar,50);
    balance();
    ar[7]=(90+5);
    ar[4]=initialPose[4];
    setPose(ar,50);
    balance();
    delay(50);    
}
void balance(){
  for(int j=0;j<4;j++){
      if(j==0||j==1){
        ar[j]+=2;
        ar[j+4]+=2;
      }
      else{
        ar[j]-=2;
        ar[j+4]-=2;
      }
  }
}
void setShoulderAngle(){
    servoDriver.setPWM(8,0,map(100,0,180,130,500));
    servoDriver.setPWM(9,0,map(90,0,180,130,500));
    servoDriver.setPWM(10,0,map(85,0,180,130,500));
    servoDriver.setPWM(11,0,map(90,0,180,130,500));
}
