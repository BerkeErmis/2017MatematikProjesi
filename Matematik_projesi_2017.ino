//Berke Ermiş 2017 Matematik Projesi
//Daire ve Daire Parçası Alan Hesaplama 

#include <Keypad.h>
#include <LCD5110_Basic.h>
#include <Servo.h>
Servo motor;
LCD5110 ekran (8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
unsigned long lastTime1 = 0;
const byte satirSayisi= 4;
const byte sutunSayisi= 4;

byte satirPinleri[satirSayisi] = {A0,A1,13,6};
byte sutunPinleri[sutunSayisi]= {5,4,3,2};
int b2="3";
int saniye=0; 
int zaman=0;
int bsmk=0;
int sil=0;
int giris=0;
int rkm=0;
int rkm1=-1;
int rkm2=-1;
int rkm3=0;
int rkm4=-1;
int rkm5=-1;
float sayi=0;
float aci=0;
float bln=360;
float son=1;
char tuslar[satirSayisi][sutunSayisi]=
{
{'1', '2', '3','4'},
{'5','6','7', '8'},
{'9', '0', 'a', 'b'},
{'*', '0', '#', 'D'}
};
Keypad tusTakimi= Keypad(makeKeymap(tuslar), satirPinleri, sutunPinleri, satirSayisi, sutunSayisi);
char basilanTus = tusTakimi.getKey();
void setup() {
  // put your setup code here, to run once:
ekran.InitLCD();
motor.attach(7);
Serial.begin(9600);
}

void loop() {
 if(bsmk==0){
motor.write(aci);
ekran.setFont(SmallFont);
ekran.print("DAIREDE",CENTER,12);
ekran.print("ALAN",CENTER,18);
ekran.print("HESAPLAMA",CENTER,24);
ekran.print("Berker",CENTER,40);
if(zaman==0){
if (millis() - lastTime1 > 1000){saniye++;lastTime1 = millis();}}
if(saniye==3){ekran.clrScr();zaman=1;bsmk=1;}}

if(bsmk==1){ekran.setFont(SmallFont);
ekran.print("r=?",CENTER,6);char basilanTus = tusTakimi.getKey();
 if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",22,18);bsmk=2;rkm3=1;}
if(basilanTus=='2'){ekran.print("2",22,18);bsmk=2;rkm3=2;}
if(basilanTus=='3'){ekran.print("3",22,18);bsmk=2;rkm3=3;}
if(basilanTus=='4'){ekran.print("4",22,18);bsmk=2;rkm3=4;}
if(basilanTus=='5'){ekran.print("5",22,18);bsmk=2;rkm3=5;}
if(basilanTus=='6'){ekran.print("6",22,18);bsmk=2;rkm3=6;}
if(basilanTus=='7'){ekran.print("7",22,18);bsmk=2;rkm3=7;}
if(basilanTus=='8'){ekran.print("8",22,18);bsmk=2;rkm3=8;}
if(basilanTus=='9'){ekran.print("9",22,18);bsmk=2;rkm3=9;}
if(basilanTus=='0'){ekran.print("0",22,18);bsmk=2;rkm3=0;}
if(basilanTus=='a'){bsmk=4;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}

delay(200);}}

if(bsmk==2){char basilanTus = tusTakimi.getKey();
  if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",36,18);bsmk=3;rkm4=1;}
if(basilanTus=='2'){ekran.print("2",36,18);bsmk=3;rkm4=2;}
if(basilanTus=='3'){ekran.print("3",36,18);bsmk=3;rkm4=3;}
if(basilanTus=='4'){ekran.print("4",36,18);bsmk=3;rkm4=4;}
if(basilanTus=='5'){ekran.print("5",36,18);bsmk=3;rkm4=5;}
if(basilanTus=='6'){ekran.print("6",36,18);bsmk=3;rkm4=6;}
if(basilanTus=='7'){ekran.print("7",36,18);bsmk=3;rkm4=7;}
if(basilanTus=='8'){ekran.print("8",36,18);bsmk=3;rkm4=8;}
if(basilanTus=='9'){ekran.print("9",36,18);bsmk=3;rkm4=9;}
if(basilanTus=='0'){ekran.print("0",36,18);bsmk=3;rkm4=0;}
if(basilanTus=='a'){bsmk=4;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}
delay(200);}}

if (bsmk==3){char basilanTus = tusTakimi.getKey();
  if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",50,18);rkm5=1;}
if(basilanTus=='2'){ekran.print("2",50,18);rkm5=2;}
if(basilanTus=='3'){ekran.print("3",50,18);rkm5=3;}
if(basilanTus=='4'){ekran.print("4",50,18);rkm5=4;}
if(basilanTus=='5'){ekran.print("5",50,18);rkm5=5;}
if(basilanTus=='6'){ekran.print("6",50,18);rkm5=6;}
if(basilanTus=='7'){ekran.print("7",50,18);rkm5=7;}
if(basilanTus=='8'){ekran.print("8",50,18);rkm5=8;}
if(basilanTus=='9'){ekran.print("9",50,18);rkm5=9;}
if(basilanTus=='0'){ekran.print("0",50,18);rkm5=0;}
if(basilanTus=='a'){bsmk=4;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}
delay(200);
}}
if(bsmk==4){ekran.setFont(SmallFont);
ekran.print("x=?",CENTER,6);char basilanTus = tusTakimi.getKey();
 if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",22,18);bsmk=5;rkm=1;}
if(basilanTus=='2'){ekran.print("2",22,18);bsmk=5;rkm=2;}
if(basilanTus=='3'){ekran.print("3",22,18);bsmk=5;rkm=3;}
if(basilanTus=='4'){ekran.print("4",22,18);bsmk=5;rkm=4;}
if(basilanTus=='5'){ekran.print("5",22,18);bsmk=5;rkm=5;}
if(basilanTus=='6'){ekran.print("6",22,18);bsmk=5;rkm=6;}
if(basilanTus=='7'){ekran.print("7",22,18);bsmk=5;rkm=7;}
if(basilanTus=='8'){ekran.print("8",22,18);bsmk=5;rkm=8;}
if(basilanTus=='9'){ekran.print("9",22,18);bsmk=5;rkm=9;}
if(basilanTus=='0'){ekran.print("0",22,18);bsmk=5;rkm=0;}
if(basilanTus=='a'){bsmk=7;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}
delay(200);}}

if(bsmk==5){char basilanTus = tusTakimi.getKey();
 if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",36,18);bsmk=6;rkm1=1;}
if(basilanTus=='2'){ekran.print("2",36,18);bsmk=6;rkm1=2;}
if(basilanTus=='3'){ekran.print("3",36,18);bsmk=6;rkm1=3;}
if(basilanTus=='4'){ekran.print("4",36,18);bsmk=6;rkm1=4;}
if(basilanTus=='5'){ekran.print("5",36,18);bsmk=6;rkm1=5;}
if(basilanTus=='6'){ekran.print("6",36,18);bsmk=6;rkm1=6;}
if(basilanTus=='7'){ekran.print("7",36,18);bsmk=6;rkm1=7;}
if(basilanTus=='8'){ekran.print("8",36,18);bsmk=6;rkm1=8;}
if(basilanTus=='9'){ekran.print("9",36,18);bsmk=6;rkm1=9;}
if(basilanTus=='0'){ekran.print("0",36,18);bsmk=6;rkm1=0;}
if(basilanTus=='a'){bsmk=7;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}
delay(200);}}

if (bsmk==6){char basilanTus = tusTakimi.getKey();
if(rkm==1&&rkm1<9){
  if (basilanTus){ekran.setFont(BigNumbers);
  if(basilanTus=='1'){ekran.print("1",50,18);rkm2=1;}
if(basilanTus=='2'){ekran.print("2",50,18);rkm2=2;}
if(basilanTus=='3'){ekran.print("3",50,18);rkm2=3;}
if(basilanTus=='4'){ekran.print("4",50,18);rkm2=4;}
if(basilanTus=='5'){ekran.print("5",50,18);rkm2=5;}
if(basilanTus=='6'){ekran.print("6",50,18);rkm2=6;}
if(basilanTus=='7'){ekran.print("7",50,18);rkm2=7;}
if(basilanTus=='8'){ekran.print("8",50,18);rkm2=8;}
if(basilanTus=='9'){ekran.print("9",50,18);rkm2=9;}
if(basilanTus=='0'){ekran.print("0",50,18);rkm2=0;}
if(basilanTus=='a'){bsmk=7;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}
delay(200);}}if(basilanTus=='a'){bsmk=7;ekran.clrScr();}
if(basilanTus=='b'){software_Reset();}}


if(bsmk==7){
if(rkm4==-1){sayi=rkm3;}
if(rkm5==-1&&rkm4==1){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==2){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==3){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==4){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==5){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==6){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==7){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==8){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==9){sayi=rkm3*10+rkm4;}
if(rkm5==-1&&rkm4==0){sayi=rkm3*10+rkm4;}
if(rkm5==1){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==2){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==3){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==4){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==5){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==6){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==7){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==8){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==9){sayi=rkm3*100+rkm4*10+rkm5;}
if(rkm5==0){sayi=rkm3*100+rkm4*10+rkm5;}

if(rkm1==-1){aci=rkm;}
if(rkm2==-1&&rkm1==1){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==2){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==3){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==4){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==5){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==6){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==7){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==8){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==9){aci=rkm*10+rkm1;}
if(rkm2==-1&&rkm1==0){aci=rkm*10+rkm1;}
if(rkm2==1){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==2){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==3){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==4){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==5){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==6){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==7){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==8){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==9){aci=rkm*100+rkm1*10+rkm2;}
if(rkm2==0){aci=rkm*100+rkm1*10+rkm2;}
son=sayi*sayi*aci/bln;
motor.write(aci);delay(250);
ekran.setFont(SmallFont);
ekran.print("Alan=",CENTER,12);
ekran.setFont(MediumNumbers);
ekran.printNumF(son,3,CENTER,18);
ekran.print("Pi",CENTER,40);

char basilanTus = tusTakimi.getKey();
if(basilanTus=='a'){bsmk=0;aci=0;sayi=0;rkm=0;rkm1=-1;rkm2=-1;
rkm3=0;rkm4=-1;rkm5=-1;
motor.write(aci);delay(500);}
if(basilanTus=='b'){software_Reset();}
}
}


void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
asm volatile ("  jmp 0");  
}  

