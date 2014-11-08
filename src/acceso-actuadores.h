bool estadoAlarmaCarrilAutoPrecaucion;
bool estadoAlarmaCarrilAutoCerrado;

bool barreraXAbierta;
bool barreraYAbierta;
bool barreraZAbierta;
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
     while(estadoAlarmaCarrilAutoCerrado){
        PlayToneEx(1245, 100, 1, FALSE);
        Wait(200);
    }
}

void reproducirAlarmaCarrilAutoCerrado(){
     estadoAlarmaCarrilAutoCerrado = true;
     start tareaAlarmaCarrilAutoCerrado;
}

void detenerAlarmaCarrilAutoCerrado(){
     estadoAlarmaCarrilAutoCerrado = false;
}

task tareaAlarmaCarrilAutoPrecaucion(){
     while(estadoAlarmaCarrilAutoPrecaucion){
        PlayToneEx(1245, 300, 1, FALSE);
        Wait(400);
    }
}

void reproducirAlarmaCarrilAutoPrecaucion(){
     estadoAlarmaCarrilAutoPrecaucion = true;
     start tareaAlarmaCarrilAutoPrecaucion;
}

void detenerAlarmaCarrilAutoPrecaucion(){
     estadoAlarmaCarrilAutoPrecaucion = false;
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
