/*
* Author: Marwil Campos
* Email: marwilcampos@gmail.com
* En este Archivo esta implementado el metodo principal de nuestro
* modulo 7 que sera todo el codigo fuente de la emulacion
* del skylab.
jsjsksjd
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
int materiaPrima[MAX] = {100,100,100};
int materialProducido[MAX_P] = {0,0,0,0,0};
/*
* semaforos semPromerium
* semaforos semDuranium
* semaforos semPrometid
*/
sem_t semPromerium, semDuranium, semPrometid;

void* productorPromerium(void *promerium){
  /**
  * el while verifica si hay elemntos suficientes  sem_post(&semDuranium);
  * para producir el material valioso
  */
  while(true){
    sem_wait(&semPromerium);
    if(materiaPrima[0]>=10 && materiaPrima[1]>=10){
    materialProducido[0]++;
    materiaPrima[0] -= 10;
    materiaPrima[1] -= 10;
    printf("%s%d\n", "Promerium: ", materialProducido[0]);
    printf("%s%d\n", "materia prima prometium: ", materiaPrima[0]);
    printf("%s%d\n", "materia prima Endurium: ", materiaPrima[1]);
    printf("%s%d\n", "materia prima Terbium: ", materiaPrima[2]);
    }
    sem_post(&semDuranium);
  }

}
void* productorDuranium(void *duranium){
  /**semPrometid
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */
  while(true){
    sem_wait(&semDuranium);
    if(materiaPrima[1]>=20 && materiaPrima[2]>=10){
    materialProducido[1]++;
    materiaPrima[1] -= 20;
    materiaPrima[2] -= 10;
    printf("%s%d\n", "Duranium: ", materialProducido[1]);
    printf("%s%d\n", "materia prima prometium: ", materiaPrima[0]);
    printf("%s%d\n", "materia prima Endurium: ", materiaPrima[1]);
    printf("%s%d\n", "materia prima Terbium: ", materiaPrima[2]);
      }
      sem_post(&semPrometid);
  }

}
void* productorPrometid(void *prometid){
  /**
  * el while verifica si hay elemntos suficientes
  * para producir el material valioso
  */

  while(true){
    sem_wait(&semPrometid);
    if(materiaPrima[0]>=20 && materiaPrima[1]>=10){
    materialProducido[2]++;
    materiaPrima[0] -= 20;
    materiaPrima[1] -= 10;
    printf("%s%d\n", "Prometid: ", materialProducido[2]);
    printf("%s%d\n", "materia prima prometium: ", materiaPrima[0]);
    printf("%s%d\n", "materia prima Endurium: ", materiaPrima[1]);
    printf("%s%d\n", "materia prima Terbium: ", materiaPrima[2]);
      }
    sem_post(&semPromerium);

  }




}
int main(int argc, char const *argv[]) {

  printf("%s\n"," Welcome to Skylab");
  sem_init(&semPromerium, 0, 1);
  sem_init(&semDuranium, 0, 0);
  sem_init(&semPrometid, 0, 0);
  printf("%s%d\n", "materia prima prometium: ", materiaPrima[0]);
  printf("%s%d\n", "materia prima Endurium: ", materiaPrima[1]);
  printf("%s%d\n", "materia prima Terbium: ", materiaPrima[2]);
  pthread_t semPromerium, semDuranium, semPrometid;

  pthread_create(&semPromerium, NULL, productorPromerium, NULL);
  pthread_create(&semDuranium, NULL, productorDuranium, NULL);
  pthread_create(&semPrometid, NULL, productorPrometid, NULL);

  pthread_join(semPromerium, NULL);
  pthread_join(semDuranium, NULL);
  pthread_join(semPrometid, NULL);

  pthread_exit(NULL);

  return 0;
}
