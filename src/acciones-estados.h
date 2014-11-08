#include "acceso-actuadores.h"

void imprimirStatus(){
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


     if (estadoAlarmaCarrilAutoCerrado == true)
        TextOut(0,24, "Alarma CAC encendida");
     else
        TextOut(0,24, "Alarma CAC apagada  ");

     if (estadoLuz == 0)
        TextOut(0,32, "Luz apagada     ");
     else if (estadoLuz == 1)
        TextOut(0,32, "Luz intermitente");
     else
        TextOut(0,32, "Luz encendida   ");
}

void tareasCarrilAutoCerrado(){
       reproducirAlarmaCarrilAutoCerrado();
       controlarBarrerasCarrilAutoCerrado(trenPorIzquierda);
       encenderLuz();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Cerrado        ");
}

void tareasCarrilAutoPrecaucion(){
       detenerAlarmaCarrilAutoCerrado();
       reproducirAlarmaCarrilAutoPrecaucion();
       controlarBarrerasCarrilAutoPrecaucion();
       establecerLuzIntermitente();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Precaucion     ");
}

void tareasTrenEnMedio(const bool &desdeCarrilAutoPrecacucion){
       detenerAlarmaCarrilAutoPrecaucion();
       reproducirAlarmaCarrilAutoCerrado();
       controlarBarrerasTrenEnMedio(desdeCarrilAutoPrecacucion);
       encenderLuz();

       imprimirStatus();
       TextOut(0,40, "Tren En Medio              ");
}

void tareasCarrilAutoReabierto(){
       detenerAlarmaCarrilAutoCerrado();
       controlarBarrerasCarrilAutoReabierto();
       apagarLuz();

       imprimirStatus();
       TextOut(0,40, "Carril Auto Reabierto      ");
}

void tareasTrenFuera(){
       controlarBarrerasTrenFuera(trenPorIzquierda);

       imprimirStatus();
       TextOut(0,40, "Tren Fuera!                ");
}

void inicializarPlataforma(){
	SetSensorTouch(IN_1);
  SetSensorTouch(IN_2);
  SetSensorTouch(IN_3);
  SetSensorTouch(IN_4);

  barreraXAbierta = true;
  barreraYAbierta = true;
  barreraZAbierta = true;
  estadoAlarmaCarrilAutoCerrado = false;
  estadoLuz = 0;
}
