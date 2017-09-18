/**
* Athor: Marwil Campos
* Email: marwilcampos@gmail.com
* En este archivo fuente esta la estructura del skylab
* atributos y registros con sus cabeceras de funciones
*/
#ifndef SKYLAB_H
#define SKYLAB_H
#define PRECIO_PROMERIUN 0.25 // precio cada unidad de Promerium
#define PRECIO_DURANIUM 0.30 // precio cada unidad de Duranium
#define PRECIO_PROMETID 40 // precio cada unidad de prometid
#define PRECIO_SEMPROM 1000 // precio de cada unidad de Semprom
#define PRECIO_DESECHUM 0.10 // precio cada 100 unidades de Desechum
/**
* Estructura de los materiales
*/
typedef struct {
  int cantidadPrometium;
  int cantidadEndurium;
  int unidades;
}Promerium;
typedef struct {
  int cantidadEndurium;
  int cantidadTerbium;
  int unidades;
}Duranium;
typedef struct {
  int cantidadTerbium;
  int cantidadPrometium;
  int cantidadEndurium;
  int unidades;
}Desechum;

typedef struct {
  int cantidadPrometium;
  int cantidadEndurium;
  int unidades;
}Prometid;

typedef struct {
  int cantidadPromerium;
  int cantidadDuranium;
  int cantidadPrometid;
  int unidades;
}Semprom;
#endif
