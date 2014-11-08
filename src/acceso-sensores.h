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

inline void girarBarrera(int idMotores, int grados){
       RotateMotor(idMotores, POTENCIA_MOTOR_BARRERAS, grados);
}

inline void subirBarreraInicio(bool trenPorIzquierda){
       if (trenPorIzquierda){
          girarBarrera(OUT_A, GRADOS_BARRERAS);
       }
       else{
            girarBarrera(OUT_C, GRADOS_BARRERAS);
       }
}

inline void bajarBarreraInicio(bool trenPorIzquierda){
       if (trenPorIzquierda){
          girarBarrera(OUT_A, GRADOS_BARRERAS * (-1));
       }
       else{
            girarBarrera(OUT_C, GRADOS_BARRERAS * (-1));
       }
}

inline void subirBarreraFin(bool trenPorIzquierda){
       if (trenPorIzquierda){
          girarBarrera(OUT_C, GRADOS_BARRERAS);
       }
       else{
            girarBarrera(OUT_A, GRADOS_BARRERAS);
       }
}

inline void bajarBarreraFin(bool trenPorIzquierda){
       if (trenPorIzquierda){
          girarBarrera(OUT_C, GRADOS_BARRERAS * (-1));
       }
       else{
            girarBarrera(OUT_A, GRADOS_BARRERAS * (-1));
       }
}

inline void subirBarreraAuto(){
       girarBarrera(OUT_B, GRADOS_BARRERAS);
}

inline void bajarBarreraAuto(){
       girarBarrera(OUT_B, GRADOS_BARRERAS * (-1));
}
