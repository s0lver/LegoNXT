bool banderaCarrilAutoCerrado = false;
bool banderaCarrilAutoPrecaucion = false;

bool estadoBarreraX;
bool estadoBarreraY;
bool estadoBarreraZ;
bool estadoAlarma;
bool trenPorIzquierda;

byte estadoLuz;


task tareaAlarmaCarrilAutoCerrado(){
     while(banderaCarrilAutoCerrado){
        PlayToneEx(1245, 100, 1, FALSE);
        Wait(200);
    }
}

void reproducirAlarmaCarrilAutoCerrado(){
     banderaCarrilAutoCerrado = true;
     start tareaAlarmaCarrilAutoCerrado;
}

void detenerAlarmaCarrilAutoCerrado(){
     banderaCarrilAutoCerrado = false;
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

inline void imprimirStatus(){
     if (estadoBarreraX == true)
        TextOut(0,0, "Barrera X arriba");
     else
        TextOut(0,0, "Barrera X abajo ");

     if (estadoBarreraY == true)
        TextOut(0,8, "Barrera Y arriba");
     else
        TextOut(0,8, "Barrera Y abajo ");

     if (estadoBarreraZ == true)
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

task tmpUno(){
         bajarBarreraFin(trenPorIzquierda);
}

task tmpDos(){
     bajarBarreraAuto();
}

inline void tareasCarrilAutoCerrado(){
     estadoBarreraY = false;
     bajarBarreraFin(trenPorIzquierda);

     estadoBarreraZ = false;
     bajarBarreraAuto();

     estadoAlarma = true;
     reproducirAlarmaCarrilAutoCerrado();

     estadoLuz = 2;

     imprimirStatus();
     TextOut(0,40, "Carril Auto Cerrado        ");
}

inline void tareasCarrilAutoPrecaucion(){
     reproducirAlarmaCarrilAutoPrecaucion();
     
     estadoBarreraZ = true;
     subirBarreraAuto();
     
     estadoLuz = 1;

     estadoAlarma = false;
     detenerAlarmaCarrilAutoCerrado();

     imprimirStatus();
     TextOut(0,40, "Carril Auto Precaucion     ");
}

inline void tareasTrenEnMedio(){
     estadoBarreraZ = false;
     bajarBarreraAuto();
     
     estadoAlarma = true;
     detenerAlarmaCarrilAutoCerrado();
     reproducirAlarmaCarrilAutoCerrado();
     
     estadoLuz = 2;

     imprimirStatus();
     TextOut(0,40, "Tren En Medio              ");
}

inline void tareasCarrilAutoReabierto(){
     estadoBarreraZ = true;
     subirBarreraAuto();
     
     estadoLuz = 0;

     estadoAlarma = false;
     detenerAlarmaCarrilAutoCerrado();

     imprimirStatus();
     TextOut(0,40, "Carril Auto Reabierto      ");
}

inline void tareasTrenFuera(){
     estadoBarreraY = true;
     subirBarreraFin(trenPorIzquierda);

     imprimirStatus();
     TextOut(0,40, "Tren Fuera!                ");
}

inline void inicializarPlataforma(){
	SetSensorTouch(IN_1);
  SetSensorTouch(IN_2);
  SetSensorTouch(IN_3);
  SetSensorTouch(IN_4);

  estadoBarreraX = true;
  estadoBarreraY = true;
  estadoBarreraZ = true;
  estadoAlarma = false;

  estadoLuz = 0;
}
