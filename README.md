# Ajedrez en C++

Este proyecto implementa un juego de ajedrez en C++, con las siguientes características principales:

## Archivos del Proyecto

- `chessboard.cpp`: Contiene la implementación de la clase `Chessboard`, que representa el tablero de ajedrez y proporciona funciones para cargar el tablero desde un archivo, obtener el color y tipo de pieza en una posición dada, obtener movimientos válidos para una pieza dada y realizar un movimiento de pieza.
- `chessposition.cpp`: Implementa la clase `ChessPosition`, que representa una posición en el tablero de ajedrez y proporciona funciones para convertir entre coordenadas de tablero y notación algebraica.

## Funcionalidades Principales

- **Carga de Tablero desde Archivo**: La función `LoadBoardFromFile` en `Chessboard.cpp` permite cargar el estado del tablero desde un archivo de texto.
- **Obtención de Movimientos Válidos**: La función `GetValidMoves` en `Chessboard.cpp` devuelve una lista de movimientos válidos para una pieza en una posición dada.
- **Realización de Movimientos**: La función `MovePiece` en `Chessboard.cpp` permite realizar un movimiento de una pieza en el tablero.

## Coordenadas y Notación

El sistema de coordenadas utilizado en el tablero es el estándar de ajedrez, donde las columnas se identifican con letras de 'a' a 'h' y las filas se numeran del 1 al 8.

## Uso del Proyecto

Para utilizar el proyecto, se pueden incluir los archivos `chessboard.cpp` y `chessposition.cpp` en un proyecto de C++ y utilizar las clases y funciones proporcionadas para interactuar con el tablero de ajedrez.

## Notas Adicionales

Este README proporciona una descripción general del proyecto y sus funcionalidades principales. Se pueden agregar más archivos y funcionalidades según sea necesario para completar el juego de ajedrez.

