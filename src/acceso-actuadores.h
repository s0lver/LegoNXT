bool banderaCarrilAutoCerrado = false;
bool banderaCarrilAutoPrecaucion = false;

bool barreraXAbierta;
bool barreraYAbierta;
bool barreraZAbierta;
bool estadoAlarma;
bool trenPorIzquierda;

byte estadoLuz;

void controlarBarrerasCarrilAutoCerrado(bool trenPorIzquierda){
       barreraYAbierta = false;
       barreraZAbierta = false;

       if (trenPorIzquierda == true){
          RotateMotor(OUT_BC, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
       }
       else{
            RotateMotor(OUT_AB, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
       }
}

void controlarBarrerasCarrilAutoPrecaucion(){
       barreraZAbierta = true;
       RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
}

void controlarBarrerasTrenEnMedio(bool desdeCarrilAutoPrecaucion){
       barreraZAbierta = false;
       if (desdeCarrilAutoPrecaucion)
          RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS * (-1));
}

void controlarBarrerasCarrilAutoReabierto(){
       barreraZAbierta = true;
       RotateMotor(OUT_B, POTENCIA_MOTOR_BARRERAS, GRADOS_BARRERAS);
}

void controlarBarrerasTrenFuera(bool trenPorIzquierda){
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
