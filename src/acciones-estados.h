bool banderaCarrilAutoCerrado = false;
bool banderaCarrilAutoPrecaucion = false;

bool barreraXAbierta;
bool barreraYAbierta;
bool barreraZAbierta;
bool estadoAlarma;
bool trenPorIzquierda;

byte estadoLuz;

inline void controlarBarrerasCarrilAutoCerrado(bool trenPorIzquierda){
       barreraYAbierta = false;
       barreraZAbierta = false;
       
       if (trenPorIzquierda == true){
          RotateMotor(OUT_BC, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
       }
       else{
            RotateMotor(OUT_AB, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
       }
}

inline void controlarBarrerasCarrilAutoPrecaucion(){
       barreraZAbierta = true;
       RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
}

inline void controlarBarrerasTrenEnMedio(bool desdeCarrilAutoPrecaucion){
       barreraZAbierta = false;
       if (desdeCarrilAutoPrecaucion)
          RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
}

inline void controlarBarrerasCarrilAutoReabierto(){
       barreraZAbierta = true;
       RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
}

inline void controlarBarrerasTrenFuera(bool trenPorIzquierda){
       barreraYAbierta = true;
       if (trenPorIzquierda == true){
          RotateMotor(OUT_C, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
       }
       else{
            RotateMotor(OUT_A, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
       }
}

task tareaAlarmaCarrilAutoCerrado(){
     while(banderaCarrilAutoCerrado){
        PlayToneEx(1245, 100, 1, FALSE);
        Wait(200);
    }
}

void reproducirAlarmaCarrilAutoCerrado(){
     banderaCarrilAutoCerrado = true;
     estadoAlarma = true;
     start tareaAlarmaCarrilAutoCerrado;
}

void detenerAlarmaCarrilAutoCerrado(){
     banderaCarrilAutoCerrado = false;
     estadoAlarma = false;
}

task tareaAlarmaCarrilAutoPrecaucion(){
     while(banderaCarrilAutoPrecaucion){
        PlayToneEx(1245, 300, 1, FALSE);
        Wait(400);
    }
}

void reproducirAlarmaCarrilAutoPrecaucion(){
     banderaCarrilAutoPrecaucion = true;
     start tareaAlarmaCarrilAutoPrecaucion;
}

void detenerAlarmaCarrilAutoPrecaucion(){
     banderaCarrilAutoPrecaucion = false;
}

void encenderLuz(){
     estadoLuz = 2;
}

void establecerLuzIntermitente(){
     estadoLuz = 1;
}

void apagarLuz(){
     estadoLuz = 0;
}

inline void imprimirStatus(){
     if (barreraXAbierta == true)
        TextOut(0,0, "Barrera X arriba");
     else
        TextOut(0,0, "Barrera X abajo ");

     if (barreraYAbierta == true)
        TextOut(0,8, "Barrera Y arriba");
     else
        TextOut(0,8, "Barrera Y abajo ");

     if (barreraZAbierta == true)
        TextOut(0,16, "Barrera Z arriba");
     else
        TextOut(0,16, "Barrera Z abajo ");


     if (estadoAlarma == true)
        TextOut(0,24, "Alarma encendida");
     else
        TextOut(0,24, "Alarma apagada  ");

     if (estadoLuz == 0)
        TextOut(0,32, "Luz apagada     ");
     else if (estadoLuz == 1)
        TextOut(0,32, "Luz intermitente");
     else
        TextOut(0,32, "Luz encendida   ");

}

inline void tareasCarrilAutoCerrado(){
       reproducirAlarmaCarrilAutoCerrado();
       controlarBarrerasCarrilAutoCerrado(trenPorIzquierda);
       encenderLuz();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Cerrado        ");
}

inline void tareasCarrilAutoPrecaucion(){
       detenerAlarmaCarrilAutoCerrado();
       reproducirAlarmaCarrilAutoPrecaucion();
       controlarBarrerasCarrilAutoPrecaucion();
       establecerLuzIntermitente();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Precaucion     ");
}

inline void tareasTrenEnMedio(bool desdeCarrilAutoPrecacucion){
       detenerAlarmaCarrilAutoPrecaucion();
       reproducirAlarmaCarrilAutoCerrado();
       controlarBarrerasTrenEnMedio(desdeCarrilAutoPrecacucion);
       encenderLuz();

       imprimirStatus();
       TextOut(0,40, "Tren En Medio              ");
}

inline void tareasCarrilAutoReabierto(){
       detenerAlarmaCarrilAutoCerrado();
       controlarBarrerasCarrilAutoReabierto();
       apagarLuz();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Reabierto      ");
}

inline void tareasTrenFuera(){
       controlarBarrerasTrenFuera(trenPorIzquierda);

       imprimirStatus();
       TextOut(0,40, "Tren Fuera!                ");
}

inline void inicializarPlataforma(){
	SetSensorTouch(IN_1);
  SetSensorTouch(IN_2);
  SetSensorTouch(IN_3);
  SetSensorTouch(IN_4);

  barreraXAbierta = true;
  barreraYAbierta = true;
  barreraZAbierta = true;
  estadoAlarma = false;

  estadoLuz = 0;
}


