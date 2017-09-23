/*
* Author: Marwil Campos, Manuel Alvarado
* Email: marwilcampos@gmail.com, chusets@gmail.com
* En este Archivo esta implementado el metodo principal de nuestro
* modulo 7 que sera todo el codigo fuente de la emulacion
* del skylab
*/

#include "Skylab.h"

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
