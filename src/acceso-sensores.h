// rails-sensors-access.h
#define POTENCIA_MOTOR_BARRERAS 25
#define GRADOS_BARRERAS 90

inline bool leerSensorUno(bool trenPorIzquierda){
     if (trenPorIzquierda == true){
        return SENSOR_1;
     }
     else{
        return SENSOR_2;
     }
}

inline bool leerSensorDos(bool trenPorIzquierda){
     if (trenPorIzquierda == true){
        return SENSOR_2;
     }
     else{
        return SENSOR_3;
     }
}

inline bool leerSensorTres(bool trenPorIzquierda){
     if (trenPorIzquierda == true){
        return SENSOR_3;
     }
     else{
        return SENSOR_2;
     }
}

inline bool leerSensorCuatro(bool trenPorIzquierda){
     if (trenPorIzquierda == true){
        return SENSOR_4;
     }
     else{
        return SENSOR_1;
     }
}


