#include <Servo.h>
#include <SoftwareSerial.h>
#define PINSERVOIZQ 12//pIN DEL SERVO IZQUIERDO
#define PINSERVODER 13//pIN DEL SERVO DERECHO
#define initBase 90//los servos se posicionan en 90 grados o detenido
#define TXBluetooth 3
#define RXBluetooth 2


Servo servoIzquierdo;//Declaro el servo izquierdo
Servo servoDerecho;//Declaro el servo derecho
SoftwareSerial BT(RXBluetooth,TXBluetooth);

int val;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  servoIzquierdo.attach(PINSERVOIZQ);// esta conectado al pin SERVOIZQUIERDO
  servoDerecho.attach(PINSERVODER);// esta conectado al pin SERVODERECHO

 servoIzquierdo.write (val=initBase -30);//incializa los motores dado una vuelta 
 servoDerecho.write (val=initBase -25);
  delay (2000);
 
}

int velocidad=10;

char  w,orden;
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


  //CON LA LETRA F PUEDEN DETENER CUALQUIER ORDEN 
  if(orden=='w')//avanza hacia adelante hasta que reciba otra orden 
      {
        

        servoDerecho.write(90-velocidad);//Girar en sentido horario
        servoIzquierdo.write(110);//Girar en sentido antihorario
        delay(1000);
          
   
      }else{
            servoIzquierdo.write(90);//Detenerse
            servoDerecho.write(90);//Detenerse
        }
        
        
 if(orden=='s')//retrocede hasta que reciba otra orden
      {
        servoDerecho.write(111);//Girar en sentido horario
        servoIzquierdo.write(60);//Girar en sentido antihorario
        delay(1000); }
        else{
            servoIzquierdo.write(91);//Detenerse
            servoDerecho.write(90);//Detenerse
        }



        
if(orden=='a')//gira hacia la izquierda 
      {
        servoDerecho.write(81-velocidad);//Girar en sentido horario
        servoIzquierdo.write(90);//se detiene 
        delay(1000); }
        else{
            servoIzquierdo.write(90);//Detenerse
            servoDerecho.write(90);//Detenerse
        }


if(orden=='d')//gira hacia la derecha 
      {
        servoIzquierdo.write(109);//Girar en sentido antihorario
        servoDerecho.write(90);//se deteiene 
        delay(1000); }
        else{
            servoIzquierdo.write(90);//Detenerse
            servoDerecho.write(90);//Detenerse
        }


if(orden=='q')//hace una gambeta 
      {
        servoIzquierdo.write(109);//Gira a la derecha 
        servoDerecho.write(90);
        delay(300); 
        servoDerecho.write(80-velocidad);//Gira a la izquierda 
        servoIzquierdo.write(90);
        delay(300);
        servoIzquierdo.write(109);//Gira a la derecha 
        servoDerecho.write(90);
        delay(200); 
        servoDerecho.write(80-velocidad);//Gira a la izquierda 
        servoIzquierdo.write(90);
        delay(200);
        
        
        }
        
        else{
            servoIzquierdo.write(90);//Detenerse
            servoDerecho.write(91);//Detenerse
        }        
  if(orden=='+')velocidad+=10;
}
