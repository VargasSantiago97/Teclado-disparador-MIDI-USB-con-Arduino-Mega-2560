//LIBRERIAS:
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MIDI.h>


//Parametros de LCD
const int rs = 41, en = 42, d4 = 43, d5 = 44, d6 = 45, d7 = 46;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



//Potenciometros 
int potPin1 = A0;
int potPin2 = A1;
int potPin3 = A2;
int potPin4 = A3;
int potPin5 = A4;
int potPin6 = A5;
int potPin7 = A6;
int potPin8 = A7;
int potPin9 = A8;
int potPin10 = A9;
int potPin11 = A10;
int potPin12 = A11;
int potPin13 = A12;
int potPin14 = A13;
int potPin15 = A14;
int potPin16 = A15;



//Valores de potenciometros
int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;
int potVal4 = 0;
int potVal5 = 0;
int potVal6 = 0;
int potVal7 = 0;
int potVal8 = 0;
int potVal9 = 0;
int potVal10 = 0;
int potVal11 = 0;
int potVal12 = 0;
int potVal13 = 0;
int potVal14 = 0;
int potVal15 = 0;
int potVal16 = 0;




const int numBotones=14;

int valorLeido1[numBotones];    
int valorAnterior1[numBotones]; 

int valorLeido2[numBotones];    
int valorAnterior2[numBotones]; 

int valorLeido3[numBotones];    
int valorAnterior3[numBotones]; 

int valorLeido4[numBotones];    
int valorAnterior4[numBotones]; 

int valorLeido5[numBotones];    
int valorAnterior5[numBotones]; 

int valorLeido6[numBotones];    
int valorAnterior6[numBotones]; 





//Otras variables
int a = 0;
int b = 1;
int h = 1;

int SaltoDePulsador = 2;



//Comandos
int menu = 40;
int up = 47;
int down = 48;


int VolumenDeNotasOctava1;
int VolumenDeNotasOctava2;
int VolumenDeNotasOctava3;
int VolumenDeNotasOctava4;
int VolumenDeNotasOctava5;
int VolumenDeNotasOctava6;

int Canal1;
int Canal2;
int Canal3;
int Canal4;
int Canal5;
int Canal6;


//Para EEPROM
byte VolumenDeNotas;
byte VolumenDeNotas1;
byte VolumenDeNotas2;
byte VolumenDeNotas3;
byte VolumenDeNotas4;
byte VolumenDeNotas5;
byte VolumenDeNotas6;

byte Canal;
byte CanalOctava1;
byte CanalOctava2;
byte CanalOctava3;
byte CanalOctava4;
byte CanalOctava5;
byte CanalOctava6;



MIDI_CREATE_DEFAULT_INSTANCE();





void setup() {
  
  lcd.begin(16, 2);
  MIDI.begin();



  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);

  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  pinMode(39, INPUT);

  pinMode(menu, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);



  VolumenDeNotas = EEPROM.read(1000);
  
  Canal = EEPROM.read(1001);

  

  VolumenDeNotasOctava1 = EEPROM.read(0);
  VolumenDeNotasOctava2 = EEPROM.read(100);
  VolumenDeNotasOctava3 = EEPROM.read(200);
  VolumenDeNotasOctava4 = EEPROM.read(300);
  VolumenDeNotasOctava5 = EEPROM.read(400);
  VolumenDeNotasOctava6 = EEPROM.read(500); 

  Canal1 = EEPROM.read(1);
  Canal2 = EEPROM.read(101);
  Canal3 = EEPROM.read(201);
  Canal4 = EEPROM.read(301);
  Canal5 = EEPROM.read(401);
  Canal6 = EEPROM.read(501);
 
}

void loop() {

  while(a==0)
  {




lcd.setCursor(6,0);
lcd.print("HOLA");







    
    a = digitalRead(menu);
  }


  
  while(a==1)
  {
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("Menu");
    delay(2000);
    b = 1;
    

    while(b==1)
    {
      //VOLUMEN
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Volumen de notas");
      h = 1;
      delay(50);
      while(h==1)
      {
        if (digitalRead(menu)==1)
        {
          b=2;
          h=0;
        }
        
        if (digitalRead(up)==1)
        {
          VolumenDeNotas = VolumenDeNotas + 1;
          EEPROM.write(0, VolumenDeNotas);
          EEPROM.write(100, VolumenDeNotas);
          EEPROM.write(200, VolumenDeNotas);
          EEPROM.write(300, VolumenDeNotas);
          EEPROM.write(400, VolumenDeNotas);
          EEPROM.write(500, VolumenDeNotas);
          EEPROM.write(1000, VolumenDeNotas);
          delay(10);
        }
        
        if (digitalRead(down)==1)
        {
          VolumenDeNotas = VolumenDeNotas - 1;
          EEPROM.write(0, VolumenDeNotas);
          EEPROM.write(100, VolumenDeNotas);
          EEPROM.write(200, VolumenDeNotas);
          EEPROM.write(300, VolumenDeNotas);
          EEPROM.write(400, VolumenDeNotas);
          EEPROM.write(500, VolumenDeNotas);
          EEPROM.write(1000, VolumenDeNotas);
          delay(10);
        }
        Mostrar_Abajo(VolumenDeNotas);
      }
    }
    while(b==2)
    {
      //CANAL
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("Canal");
      h = 1;
      delay(100);
      while(h==1)
      {
        if (digitalRead(menu)==1)
        {
          b=3;
          h=0;
        }
        
        if (digitalRead(up)==1)
        {
          Canal = Canal + 1;
          EEPROM.write(1, Canal);
          EEPROM.write(101, Canal);
          EEPROM.write(201, Canal);
          EEPROM.write(301, Canal);
          EEPROM.write(401, Canal);
          EEPROM.write(501, Canal);
          EEPROM.write(1001, Canal);
          delay(400);
        }
        
        if (digitalRead(down)==1)
        {
          Canal = Canal - 1;
          EEPROM.write(1, Canal);
          EEPROM.write(101, Canal);
          EEPROM.write(201, Canal);
          EEPROM.write(301, Canal);
          EEPROM.write(401, Canal);
          EEPROM.write(501, Canal);
          EEPROM.write(1001, Canal);
          delay(400);
        }
        Mostrar_Abajo(Canal);
      }
      
    }

    while(b==3)
    {
      //OCTAVAS
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Octavas");
      h = 1;
      delay(100);
      while(h==1)
      {
        if (digitalRead(menu)==1)
        {
          b=4;
          h=0;
        }
        
        if (digitalRead(up)==1)
        {
          
        }
        
        if (digitalRead(down)==1)
        {
          
        }
        Mostrar_Abajo(Canal);
      }
      
    }


    while(b==4)
    {
      //PITCH
      lcd.clear();
      lcd.setCursor(6 ,0);
      lcd.print("Pitch");
      h = 1;
      delay(100);
      while(h==1)
      {
        if (digitalRead(menu)==1)
        {
          b=0;
          h=0;
        }
        
        if (digitalRead(up)==1)
        {
          
        }
        
        if (digitalRead(down)==1)
        {
          
        }
        Mostrar_Abajo(Canal);
      }
      
    }
    







    
  }

}























void Mostrar_Abajo(int escribir)
{
  if(escribir < 10)
  {
    lcd.setCursor(7,1);
    lcd.print("00");
    lcd.setCursor(9,1);
    lcd.print(escribir);
  }
  if(escribir>9 && escribir<100)
  {
    lcd.setCursor(7,1);
    lcd.print("0");
    lcd.setCursor(8,1);
    lcd.print(escribir);
  }
  if(escribir>99 && escribir<256)
  {
    lcd.setCursor(7,1);
    lcd.print(escribir);
  }
}






















