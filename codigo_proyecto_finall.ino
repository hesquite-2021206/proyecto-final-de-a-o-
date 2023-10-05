/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: TALLER ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS I
 * Nombre: henry esquite
 * CARNE: 2021206
 * Proyecto: Proyecto Final 
 * 
 */

#define pinV A0
#define pinI A3

//VaResistenciaiables
String entrada;
float Sensibilidad = 0.185;
float vol = 0;
float med = 0;
float corriente = 0;
float amperaje = 0;  //Potencia
int Resistencia;   //Resistenciaesistencia

//Funciones
void mediciones(int x); //Funcion de medicion y envio de datos

void setup() {
  Serial.begin(9600);
  pinMode(pinV, INPUT);
  pinMode(pinI, INPUT);
}

void loop() {
 if(Serial.available() > 0){
  entrada = Serial.readStringUntil("\n");
 }
 if(entrada == String("1")){
  mediciones(1);
  }
 if(entrada == String("2")){
  mediciones(2);
  }
 if(entrada == String("3")){
  mediciones(3);
  }
 if(entrada == String("4")){
  mediciones(4);
  }
}
void mediciones(int x){
 vol =  (float)25*analogRead(pinV)/1023;
 delay(100);
 med =  (pinI)*(5.0/1023.0);
 corriente = abs((2.5 - med)/Sensibilidad);
 delay(100);
  switch(x){
  case 1:
  amperaje = vol * corriente;
  Serial.println(amperaje,3);
  break;

  case 2:
  Serial.println(vol);
  break;

  case 3:
  Serial.println(corriente);
  break;

  case 4:
  Resistencia = vol / corriente;
  Serial.println(Resistencia);
  break;
}
}
