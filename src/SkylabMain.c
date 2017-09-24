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
  sem_init(&calPromerium, 0, 0);
  sem_init(&calDuranium, 0, 0);
  sem_init(&calPrometid, 0, 0);
  sem_init(&calDesechum, 0, 0);
  sem_init(&calSemprom, 0, 0);
  
  pthread_t semPromerium, semDuranium, semPrometid,semSemprom, semTransporte;
  pthread_t calcularPromerium, calcularDuranium, calcularPrometid, calcularSemprom, calcularDesechum;

	struct Parametros_Nec All_W;
	All_W.Tipos_MP = MAX_P;

	
  pthread_create(&semTransporte,NULL, transporteHaciaElLaboratorio,NULL);
  pthread_create(&semPromerium, NULL, productorPromerium, NULL);
  pthread_create(&semDuranium, NULL, productorDuranium, NULL);
  pthread_create(&semPrometid, NULL, productorPrometid, NULL);
  pthread_create(&semSemprom, NULL, productorSemprom, NULL);
  pthread_create(&calcularPromerium, NULL,calcular_Promerium,&All_W);
  pthread_create(&calcularDuranium, NULL,calcular_Duranium,&All_W);			
  pthread_create(&calcularPrometid, NULL,calcular_Prometid,&All_W);
  pthread_create(&calcularSemprom, NULL,calcular_Semprom,&All_W);
  pthread_create(&calcularDesechum, NULL,calcular_Desechum,&All_W);

  pthread_join(semTransporte,NULL );
  pthread_join(semPromerium, NULL);
  pthread_join(semDuranium, NULL);
  pthread_join(semPrometid, NULL);
  pthread_join(semSemprom, NULL);
  pthread_join(calcularPromerium, NULL);
  pthread_join(calcularDuranium, NULL);
  pthread_join(calcularPrometid, NULL);
  pthread_join(calcularSemprom, NULL);
  pthread_join(calcularDesechum, NULL);
  pthread_exit(NULL);

  return 0;
}
