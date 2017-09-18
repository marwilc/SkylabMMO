# Proyecto Modulo 7 SKYLAB (Mars Mining Operations)

7. SKYLAB
Integrantes: Marwil Campos, Manuel Alvarado
Se comunica con: Hangar de descarga , operaciones comerciales y módulo 9
Las naves serán descargadas una por una y en orden de llegada. Se extraerá una
materia prima a la vez y se colocará en una cinta transportadora, que las llevará al
SkyLab en
donde serán refinadas para obtener otros materiales más caros. Estos materiales son:
Promerium: puede venderse a un precio establecido de 0,25V la unidad. Para su
producción son necesarias 10 unidades de Prometium y 10 de Endurium.
Duranium: necesita 20 rocas de Endurium y 10 de Terbium. Tiene un precio
establecido de 0,30V cada unidad.
Prometid: para su producción son necesarias 20 unidades de Prometium y 10 de
Endurium, y son vendidas al precio establecido de 40V por unidad.
( Estos 3 materiales compuesto se generan de los materiales primarios).
Semprom: es el material más valioso y, por lo tanto, el más difícil de producir. Para
generar una unidad se ameritan 5 unidades de cada uno de los otros 3 materialesque son refinados en el SkyLab. El precio es 1000V por unidad.
(Este material necesita de los 3 materiales compuestos).
Desechum: Es cualquiera de los materiales (Endurium, Prometium, Terbium) en
formato pulverizado con menores prestaciones 0,10V por 100 unidades.
Hay un robot encargado de la producción de cada uno de estos materiales, los cuales
generan una unidad de su respectivo producto, cada vez que tengan la suficiente
cantidad
de materia prima. En el laboratorio se aplican pruebas de calidad las cuales consisten en
la
inspección por atributos con muestreo aleatorio. Si no cumple con las características de
calidad el lote es rechazado y pulverizado para su venta como Desechum.
(Cada vez que llega al laboratorio uno de los tres tipos de materia prima , se genera
una valor aleatorio entre 0-5 por ejemplo , siendo los valores aceptables del 2-5 , si
el valor esta entre 0-1 , esta materia prima se pulverisa y se transforma en
Desechum) esta solo seria una manera de modelarlo , el equipo puede escoger la mejor
manera
Concejo : Las estructuras para manejar las características de los materiales costosos
deberían ser registros: Ejemplo
typedef struct Prometid{
Prometium=20 unidades
Endurium=10 unidades
precio=40V por unidad.
}
Cada robot compartirá un arreglo de recursos disponibles , entonces cuando llegue el
turno de ejecución de cada uno , verifican el registro del material que van a fabricar y
comparan con los disponibles , si existen los materiales suficientes ,le restan a la cantidad
disponible de cada uno la cantidad que tomaron y suman una unidad al material que
fabricaron (*posición del arreglo que corresponda*). OJO esto es solo una manera en la
que podrían modelarlo.
( La materia prima se extrae una unidad por vez y se coloca en una cinta
transportadora, que las llevará al SkyLab. Este comportamiento deberá simularse)
(Cada cierto periodo de tiempo este modulo debera vaciar sus existencias y
enviarlas a operacion comerciantes , para ajuste de precio y venta , ESTO SE
ASUME YA QUE NO LO ESPECIFICA EL ENUNCIADO PERO EL MODULO 9 LO
NOMBRA )
Para esto se pueden emplear vectores7. SKYLAB
Integrantes: Marwil Campos, Manuel Alvarado
Se comunica con: Hangar de descarga , operaciones comerciales y módulo 9
Las naves serán descargadas una por una y en orden de llegada. Se extraerá una
materia prima a la vez y se colocará en una cinta transportadora, que las llevará al
SkyLab en
donde serán refinadas para obtener otros materiales más caros. Estos materiales son:
Promerium: puede venderse a un precio establecido de 0,25V la unidad. Para su
producción son necesarias 10 unidades de Prometium y 10 de Endurium.
Duranium: necesita 20 rocas de Endurium y 10 de Terbium. Tiene un precio
establecido de 0,30V cada unidad.
Prometid: para su producción son necesarias 20 unidades de Prometium y 10 de
Endurium, y son vendidas al precio establecido de 40V por unidad.
( Estos 3 materiales compuesto se generan de los materiales primarios).
Semprom: es el material más valioso y, por lo tanto, el más difícil de producir. Para
generar una unidad se ameritan 5 unidades de cada uno de los otros 3 materialesque son refinados en el SkyLab. El precio es 1000V por unidad.
(Este material necesita de los 3 materiales compuestos).
Desechum: Es cualquiera de los materiales (Endurium, Prometium, Terbium) en
formato pulverizado con menores prestaciones 0,10V por 100 unidades.
Hay un robot encargado de la producción de cada uno de estos materiales, los cuales
generan una unidad de su respectivo producto, cada vez que tengan la suficiente
cantidad
de materia prima. En el laboratorio se aplican pruebas de calidad las cuales consisten en
la
inspección por atributos con muestreo aleatorio. Si no cumple con las características de
calidad el lote es rechazado y pulverizado para su venta como Desechum.
(Cada vez que llega al laboratorio uno de los tres tipos de materia prima , se genera
una valor aleatorio entre 0-5 por ejemplo , siendo los valores aceptables del 2-5 , si
el valor esta entre 0-1 , esta materia prima se pulverisa y se transforma en
Desechum) esta solo seria una manera de modelarlo , el equipo puede escoger la mejor
manera
Concejo : Las estructuras para manejar las características de los materiales costosos
deberían ser registros: Ejemplo
typedef struct Prometid{
Prometium=20 unidades
Endurium=10 unidades
precio=40V por unidad.
}
Cada robot compartirá un arreglo de recursos disponibles , entonces cuando llegue el
turno de ejecución de cada uno , verifican el registro del material que van a fabricar y
comparan con los disponibles , si existen los materiales suficientes ,le restan a la cantidad
disponible de cada uno la cantidad que tomaron y suman una unidad al material que
fabricaron (*posición del arreglo que corresponda*). OJO esto es solo una manera en la
que podrían modelarlo.
( La materia prima se extrae una unidad por vez y se coloca en una cinta
transportadora, que las llevará al SkyLab. Este comportamiento deberá simularse)
(Cada cierto periodo de tiempo este modulo debera vaciar sus existencias y
enviarlas a operacion comerciantes , para ajuste de precio y venta , ESTO SE
ASUME YA QUE NO LO ESPECIFICA EL ENUNCIADO PERO EL MODULO 9 LO
NOMBRA )
Para esto se pueden emplear vectores

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
Give examples
```

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
Give the example
```

And repeat

```
until finished
```

End with an example of getting some data out of the system or using it for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone who's code was used
* Inspiration
* etc
