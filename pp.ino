#include <Servo.h>
#include <SoftwareSerial.h>
#define PINSERVOIZQ 12//pIN DEL SERVO IZQUIERDO
#define PINSERVODER 13//pIN DEL SERVO DERECHO
#define TXBluetooth 3
#define RXBluetooth 2


Servo servoIzquierdo;//Declaro el servo izquierdo
Servo servoDerecho;//Declaro el servo derecho
SoftwareSerial BT(RXBluetooth,TXBluetooth);

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  servoIzquierdo.attach(PINSERVOIZQ);//Indicar que esta conectado al pin SERVOIZQUIERDO
  servoDerecho.attach(PINSERVODER);//Indicar que esta conectado al pin SERVODERECHO
}

int velocidad=10;

char  orden;
void loop() 
{
  if(BT.available()>0)
  {
    orden=BT.read();
    BT.println(orden);
  }
  if(Serial.available()>0)
  {
    orden=Serial.read();
    Serial.println(orden);
  }
  if(orden=='w')
      {
        

        servoDerecho.write(60-velocidad);//Girar en sentido horario
        servoIzquierdo.write(60);//Girar en sentido antihorario
        delay(1000);
        /*servoIzquierdo.write(90);//Detenerse
        delay(1000);
        servoIzquierdo.write(90-velocidad);//Girar en sentido horario
        delay(1000);
        
        servoIzquierdo.write(90);//Detenerse
        delay(1000); */    


        
      }else{
            servoIzquierdo.write(90);//Detenerse
            servoDerecho.write(90);//Detenerse
        }
  if(orden=='+')velocidad+=10;
}
