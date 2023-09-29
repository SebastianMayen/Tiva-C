//agregra librerias 

#include <SPI.h> //Incluir Librería de comunicación SPI
#include <SD.h> //Incluir librería para la memoria microSD

// Declaración de variables
int opcionUsuario; // Variable que almacena la opción elegida por el usuario
char entradaSerial; // Variable que almacena el carácter leído desde el puerto serial
int imagen; //bandera para cheuqear la imagen que se selecciono 
String newimagen;

File myFile; //Se define myFile como tipo archivo


// Función para mostrar un menú al usuario a través de la comunicación serial.
void mostrarMenu() {
    // Imprime las opciones de imágenes disponibles.
    Serial.println("Seleccione 1 para Imagen 1"); 
    Serial.println("Seleccione 2 para Imagen 2");
    Serial.println("Seleccione 3 para Imagen 3");
    Serial.println("Seleccione 4 para ver la nueva Imagen Creada");

    Serial.println("Seleccione 5 para crear Imagen");

 
}

// Función que se ejecuta una vez al inicio del programa
void setup() {
  Serial.begin(115200); // Inicializar la comunicación serial a una velocidad de 9600 baudios
  mostrarMenu(); // Muestra el menú al usuario por primera vez
  SPI.setModule(0); //Utilizar el SPI Module 0


  Serial.print("Initializing SD card..."); //Indicar que se está inicializando la memoria
  pinMode(PA_3, OUTPUT); //poner el pin CS como output, es el slave selet

  if (!SD.begin(PA_3))
   {
       Serial.println("initialization failed!");
       return;
   }
   Serial.println("initialization done.");
  
}

// Función que se ejecuta en bucle continuamente
void loop() {
  if (Serial.available()) { // Esperar hasta que haya datos disponibles en el buffer serial
    entradaSerial = Serial.read(); // Leer un carácter desde el puerto serial

// Comprobar qué opción ha introducido el usuario
  if (entradaSerial == '1'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 1.");
    imagen = 1;// bandera de l aimagen 1
  }
  else if (entradaSerial == '2'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 2.");
    imagen = 2; //bandera de la image 2 
  }
  else if (entradaSerial == '3'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen 3.");
    imagen = 3; //bandera de la imagen 3
  }

  else if (entradaSerial == '4'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado la Imagen Creada.");
    imagen = 4; //bandera de la imagen 3
  }
  
else if (entradaSerial == '5'){ 
    Serial.println(); // Agregar un salto de línea
    Serial.println("Has seleccionado ver la nueva Imagen Creada.");
    imagen = 5; //bandera de la imagen 5
}

// Si el usuario introduce una opción no válida.
  else {
    Serial.println(); // Agregar un salto de línea
    Serial.println("Opcion no valida");
    imagen = 0; // re reincia la bandera 
    mostrarMenu(); // Mostrar el menú nuevamente después de indicar que la opción no es válida.
    
  }

  }
  imagenes();// funcion que abre las imagenes 
}



//funcion para abrir las imagenes

void imagenes(){

  //////////////////////////////////////////imagen 1//////////////////////////////////////////////////
  if (imagen == 1){// si la imagen que se selcciona es 1
    myFile = SD.open("imagen1.txt"); // abrir el archivo con el nombre 
   
    if (myFile)
    {
        Serial.println("imagen1.txt:");

        // leer el archivo hasta que no se enceuntre nada mas 
        while (myFile.available())//leer el archivo complto 
        {
            Serial.write(myFile.read());// mostarr que se esta leyendo 
        }
        //cerrar el archivo 
        myFile.close();
      Serial.println('\n'); //salto de linea 

    }
    else
    {
        // si el archivo no logro abrirse se muestra el mensaje siguiente
        Serial.println("Error al abrir imagen.txt");
    }

  }


  //////////////////////////////////////////imagen 2//////////////////////////////////////////////////
  if (imagen == 2){// si la imagen que se selcciona es 1
    myFile = SD.open("imagen2.txt"); // abrir el archivo con el nombre 
   
    if (myFile)
    {
        Serial.println("imagen2.txt:");

        // leer el archivo hasta que no se enceuntre nada mas 
        while (myFile.available())//leer el archivo complto 
        {
            Serial.write(myFile.read());// mostarr que se esta leyendo 
        }
        //cerrar el archivo 
        myFile.close();
      Serial.println('\n'); //salto de linea 

    }
    else
    {
        // si el archivo no logro abrirse se muestra el mensaje siguiente
        Serial.println("Error al abrir imagen.txt");
    }

  }

  //////////////////////////////////////////imagen 3//////////////////////////////////////////////////
  if (imagen == 3){// si la imagen que se selcciona es 1
    myFile = SD.open("imagen3.txt"); // abrir el archivo con el nombre 
   
    if (myFile)
    {
        Serial.println("imagen3.txt:");

        // leer el archivo hasta que no se enceuntre nada mas 
        while (myFile.available())//leer el archivo complto 
        {
            Serial.write(myFile.read());// mostarr que se esta leyendo 
        }
        //cerrar el archivo 
        myFile.close();
      Serial.println('\n'); //salto de linea 

    }
    else
    {
        // si el archivo no logro abrirse se muestra el mensaje siguiente
        Serial.println("Error al abrir imagen.txt");
    }

  }

  //////////////////////////////////////////imagen 3//////////////////////////////////////////////////
  if (imagen == 4){// si la imagen que se selcciona es 1
    myFile = SD.open("IMAGEN4.txt"); // abrir el archivo con el nombre 
   
    if (myFile)
    {
        Serial.println("IMAGEN4.txt:");

        // leer el archivo hasta que no se enceuntre nada mas 
        while (myFile.available())//leer el archivo complto 
        {
            Serial.write(myFile.read());// mostarr que se esta leyendo 
        }
        //cerrar el archivo 
        myFile.close();
      Serial.println('\n'); //salto de linea 

    }
    else
    {
        // si el archivo no logro abrirse se muestra el mensaje siguiente
        Serial.println("Error al abrir imagen.txt");
    }

  }

///////////////////////////////crear imagen////////////////////////////////
// Si el usuario seleccionó la opción 5 del menú
    if (imagen == 5) {

    myFile = SD.open("imagen4.txt", FILE_WRITE); // Abrir el archivo en modo escritura
    if (myFile) { //Si sí hay un archivo llamado así ejecutar
        Serial.println("Dibuje la imagen a crear...");
        Serial.println("Presione S para salir al haber terminado.");
        char c;
        while (true) {
            if (Serial.available()) {
                c = Serial.read(); //Leer un carácter del puerto serie
                if (c == 'S') {
                    break; //Salir del bucle si el carácter es '7'
                }
                newimagen += c; //Agregar el carácter a la cadena newimagen
            }
        }
        myFile.println(newimagen);
        // close the file:
        myFile.close(); //Cerrar el archivo
        Serial.println("Contenido guardado en IMAGEN4.txt.");
        Serial.print('\n'); //Imprimir un enter
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening image.txt"); //Si no hay archivo con ese nombre, hay error
    }
/// Escribir en la imagen 
    }

    imagen = 0;
}
