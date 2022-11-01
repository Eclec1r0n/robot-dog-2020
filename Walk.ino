#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servoDriver= Adafruit_PWMServoDriver(); 
int initialPose[]={90+40,90+40,90-40,90-40,90-0,90-0,90,90,105,90,85,90};
int stablePose[]={90+40,90-3+40,90-40-8,(90-5)-40,(90+3),(90-2),(90+3),(90+5),100,90,80,90};
int ar[12];
void setup() {
    initWalk();
    Serial.begin(9600);
}
void initWalk(){
    servoDriver.begin();
    servoDriver.setOscillatorFrequency(27000000);
    servoDriver.setPWMFreq(50);
    for(int i=0;i<12;i++){
        servoDriver.setPWM(i,0,map(initialPose[i],0,180,130,500));
    }
    setPose(stablePose,50);
    delay(50);
}

void loop() {
    walk();
}
void setPose(int a[],int rate)
{
    rate=rate/2;
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

void walk(){
    ar[5]=stablePose[5]-10;
    ar[6]=stablePose[6]-30;
    ar[8]=stablePose[8]-15;
    ar[11]=stablePose[11]+15;
    ar[9]=stablePose[9]+15;
    ar[4]=stablePose[4]-5;
    ar[7]=stablePose[7]+10;
    setPose(ar,50);
    delay(2000);
    ar[2]=stablePose[2]+10;
    ar[6]=stablePose[6]-17;
    setPose(ar,50);
    delay(2000);
    ar[7]=stablePose[7];
    ar[0]=stablePose[0]+5;
    ar[1]=stablePose[1]+5;
    ar[3]=stablePose[3]-5;
    setPose(ar,50);
    delay(2000);
    ar[11]=stablePose[11];
    ar[9]=stablePose[9];
    ar[5]=stablePose[5];
    ar[6]=stablePose[6];
    setPose(ar,50);
    delay(2000);
    ar[8]=stablePose[8]+20;
    ar[11]=stablePose[11]-20;
    ar[10]=stablePose[10]+15;
    ar[6]=stablePose[6];
    setPose(ar,50);
    delay(2000);
    ar[5]=stablePose[5]+30;
    setPose(ar,50);
    delay(2000);
    ar[0]=stablePose[0]+10;
    ar[2]=stablePose[2]+5;
    ar[3]=stablePose[3]-10;
    setPose(ar,50);
    delay(2000);
    ar[5]=stablePose[5];
    ar[1]=stablePose[1]-10;
    setPose(ar,50);
    delay(2000);
    ar[8]=stablePose[8];
    ar[5]=stablePose[5]-5;
    ar[11]=stablePose[11]-5;
    ar[9]=stablePose[9];
    ar[6]=stablePose[6];
    setPose(ar,50);
    delay(2000);
    ar[4]=stablePose[4]+30;
    setPose(ar,50);
    delay(2000);
    ar[0]=stablePose[0]-10;
    ar[4]=stablePose[4]+15;
    setPose(ar,50);
    delay(2000);
    ar[8]=stablePose[8]-15;
    ar[11]=stablePose[11]+15;
    ar[9]=stablePose[9]+15;
    ar[7]=stablePose[7]-30;
    setPose(ar,50);
    delay(2000);
}
