/*
* Author: Marwil Campos
* Email: marwilcampos@gmail.com
* En este Archivo esta implementado el metodo principal de nuestro
* modulo 7 que sera todo el codigo fuente de la emulacion
* del skylab.
chuse
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "Skylab.h"
#define MAX 3

// en la posicion 0 del vector estara guardado el material Prometium
// en la posicion 1 del vector estara guardado el material Endurium
// en la posicion 2 del vector estara guardado el material Terbium
int materiaPrima[MAX];
/*
* semaforos semPromerium
* semaforos semDuranium
* semaforos semPrometid
*/
sem_t semPromerium, semDuranium, semPrometid;
semaphore mutex = 1;
semaphore fillCount = 0;
semaphore emptyCount = BUFFER_SIZE;

procedure producer() {
    while (true) {
        item = produceItem();
        down(emptyCount);
            down(mutex);
                putItemIntoBuffer(item);
            up(mutex);
        up(fillCount);
    }
}

procedure consumer() {
    while (true) {
        down(fillCount);
            down(mutex);
                item = removeItemFromBuffer();
            up(mutex);
        up(emptyCount);
        consumeItem(item);
    }
}
int main(int argc, char const *argv[]) {

  Promerium promerium;
  promerium.cantidadPrometium = 100;
  promerium.cantidadEndurium = 100;
  promerium.unidades = 10;
  printf("%s\n"," Welcome to Skylab");
  printf("%d\n", promerium.unidades);


  return 0;
}
