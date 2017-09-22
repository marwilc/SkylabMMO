/*
* Author: Marwil Campos, Manuel Alvarado
* Email: marwilcampos@gmail.com, chusets@gmail.com
* En este Archivo esta implementado el metodo principal de nuestro
* modulo 7 que sera todo el codigo fuente de la emulacion
* del skylab
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include "Skylab.h"
#define MAX 3 // tipos de material primario
#define MAX_P 5 // tipos de material valioso

// en la posicion 0 del vector estara guardado el material Prometium
// en la posicion 1 del vector estara guardado el material Endurium
// en la posicion 2 del vector estara guardado el material Terbium
int materiaPrimaLab[MAX] = {0,0,0};
int materiaPrimaHangar[MAX] = {1000,1000,1000};
/**
* en la posicion 0 del vector materialProducido estara guardado el Promerium
* en la posicion 1 del vector estara guardado el Duranium
* en la posicion 2 del vector estara guardado el Ṕrometid
* en la posicion 3 del vector estara guardado el SemProm
* en la posicion 4 del vector estara guardado el Desechum
*/
int materialProducido[MAX_P] = {0,0,0,0,0};
/*
* semaforos semPromerium
* semaforos semDuranium
* semaforos semPrometid
* semaforos semSemprom
*/
sem_t semPromerium, semDuranium, semPrometid,semSemprom, semTransporte;
void delayerloop(void);
void cintaTransportadora(void);

/* genera un ramdom para el desechum*/

int generar_dato(void){ return rand()%6;}
/**
* este hilo se encarga de simular el transporte de materiales al laboratorio
*/
void* transporteHaciaElLaboratorio(void *transporte){
  int contador = MAX;
  sem_wait(&semTransporte);
  printf("%s\n","Transportando materiales al Skylab: " );
  for (int i = 0; i < contador; i++) {
    /* se simula el proceso de cinta transportadora tres veces
    * para cada material
    */

    cintaTransportadora();
    int n = generar_dato();
    materiaPrimaLab[i] = materiaPrimaHangar[i];
    materiaPrimaHangar[i] = 0;
      if(n >= 2 && n <= 5 ){
        if(i==0){
            printf("%s\n", "Transporte de Prometium completado");
        }
        if(i==1){
            printf("%s\n", "Transporte de Endurium completado");
        }
        if(i==2){
            printf("%s\n", "Transporte de Terbium completado");
        }
      }else{
        printf("%s\n", "Material no cumple con los estandares de calidad se convertira en Desechum");
        materialProducido[4]=materialProducido[4]+materiaPrimaLab[i];
        materiaPrimaLab[i] = 0;
    }
  }
  sem_post(&semPromerium);
}

/*
* hilo encargado de producir el material promerium
*/
void* productorPromerium(void *promerium){
  /**
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */
  while(true){
    sem_wait(&semPromerium);
    if(materiaPrimaLab[0]>=10 && materiaPrimaLab[1]>=10){
      materialProducido[0]++;
      materiaPrimaLab[0] -= 10;
      materiaPrimaLab[1] -= 10;
      printf("%s%d\n", "Promerium: ", materialProducido[0]);
      printf("%s%d\n", "materia prima prometium: ", materiaPrimaLab[0]);
      printf("%s%d\n", "materia prima Endurium: ", materiaPrimaLab[1]);
      printf("%s%d\n", "materia prima Terbium: ", materiaPrimaLab[2]);
    }
    sem_post(&semDuranium);
  }
}
/*
* hilo encargado de producir el material Duranium
*/
void* productorDuranium(void *duranium){
  /**semPrometid
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */
  while(true){
    sem_wait(&semDuranium);
    if(materiaPrimaLab[1]>=20 && materiaPrimaLab[2]>=10){
      materialProducido[1]++;
      materiaPrimaLab[1] -= 20;
      materiaPrimaLab[2] -= 10;
      printf("%s%d\n", "Duranium: ", materialProducido[1]);
      printf("%s%d\n", "materia prima prometium: ", materiaPrimaLab[0]);
      printf("%s%d\n", "materia prima Endurium: ", materiaPrimaLab[1]);
      printf("%s%d\n", "materia prima Terbium: ", materiaPrimaLab[2]);
    }
    sem_post(&semPrometid);
  }

}

/*
* hilo encargado de producir el material Prometid
*/
void* productorPrometid(void *prometid){
  /**semSemprom
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */

  while(true){
    sem_wait(&semPrometid);
    if(materiaPrimaLab[0]>=20 && materiaPrimaLab[1]>=10){
      materialProducido[2]++;
      materiaPrimaLab[0] -= 20;
      materiaPrimaLab[1] -= 10;
      printf("%s%d\n", "Prometid: ", materialProducido[2]);
      printf("%s%d\n", "materia prima prometium: ", materiaPrimaLab[0]);
      printf("%s%d\n", "materia prima Endurium: ", materiaPrimaLab[1]);
      printf("%s%d\n", "materia prima Terbium: ", materiaPrimaLab[2]);
    }
    sem_post(&semSemprom);

  }
}
/*
* hilo encargado de producir el material semprom
*/
void* productorSemprom(void *semprom){
  /**
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */

  while(true){
    sem_wait(&semSemprom);
    if(materialProducido[0]>=5 && materialProducido[1]>=5
      && materialProducido[2]>=5){
      materialProducido[3]++;
      materialProducido[0] -= 5;
      materialProducido[1] -= 5;
      materialProducido[2] -= 5;
      printf("%s%d\n", "Semprom: ", materialProducido[3]);
      printf("%s%d\n", "material Promerium : ", materialProducido[0]);
      printf("%s%d\n", "material Endurium: ", materialProducido[1]);
      printf("%s%d\n", "material Prometid: ", materialProducido[2]);
    }
    sem_post(&semTransporte);
    sem_post(&semPromerium);
  }
}

int main(int argc, char const *argv[]) {

  printf("%s\n"," Welcome to Skylab");
  /**
  * inicializacion de los semaforos
  */
  srand(time(NULL));
  sem_init(&semTransporte, 0, 1);
  sem_init(&semPromerium, 0, 0);
  sem_init(&semDuranium, 0, 0);
  sem_init(&semPrometid, 0, 0);
  sem_init(&semSemprom, 0, 0);

  pthread_t semPromerium, semDuranium, semPrometid,semSemprom, semTransporte;

  pthread_create(&semTransporte,NULL, transporteHaciaElLaboratorio,NULL);
  pthread_create(&semPromerium, NULL, productorPromerium, NULL);
  pthread_create(&semDuranium, NULL, productorDuranium, NULL);
  pthread_create(&semPrometid, NULL, productorPrometid, NULL);
  pthread_create(&semSemprom, NULL, productorSemprom, NULL);

  pthread_join(semTransporte,NULL );
  pthread_join(semPromerium, NULL);
  pthread_join(semDuranium, NULL);
  pthread_join(semPrometid, NULL);
  pthread_join(semSemprom, NULL);
  pthread_exit(NULL);

  return 0;
}

/**
* esta funcion simula la cinta transportadora
*/
void cintaTransportadora(void)
{
 //Declarar nuestro contador de bucle de cadena,
 //nuestra cadena, y la longitud de la cadena:
 ///
  int n;
  char s[]="..................................";
  int slen=sizeof(s);


 //Mostrar cada carácter con un retardo.
  for(n=0;n<slen;n++)
  {
   //Retardar:
   ///
    delayerloop();

   //Poner un carácter en 'stdout' (salida estándar o consola
   //de texto en este caso):
   ///
    putchar(s[n]);


   //Forzar escribir el carácter ya. Si esto no se usa, el
   //carácter no se mostrará de manera inmediata:
   ///
    fflush(stdout);
  }
}

//Esta función se vale de un bucle con un contador
//expresado con números hexadecimales para provocar un
//pequeño retraso, sin usar ninguna librería.
//
//Esto es muy simple y portable en teoría, pero el tiempo
//que se tardará en cuestión dependerá de la velocidad
//de cada CPU en el que se corra, que puede ser más o menos
//lento.
///
void delayerloop(void)
{
 //Esto se puede cambiar al valor que deseemos
 ///
  register long x=0x8FFFFFF;


 //Efectuar la temporización:
 ///
  while(x--);
}
