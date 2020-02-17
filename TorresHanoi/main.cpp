


#include <iostream>
#include <stdlib.h>

#include <cstdlib>


using namespace std;
int **puntero_matriz, filas, columnas, pasos = 0, complejidad = 0;

void imprimir(int **punter_matriz, int filas, int columnas, int discos) {
    cout << "\n----------------------------------------------- \n";
      complejidad++;
    for (int i = 0; i < columnas; i++) {
        complejidad++;
          complejidad++;
        for (int j = 0; j < filas; j++) {
            complejidad++;

            int esp = (discos - *(*(punter_matriz + j) + i)) / 2;
              complejidad++;
                complejidad++;
            for (int k = 0; k < esp; k++) {
                  complejidad++;
                cout << " ";
            }
                complejidad++;
            for (int k = 0; k<*(*(punter_matriz + j) + i); k++) {
                  complejidad++;
                cout << "~";
            }
                complejidad++;
            for (int k = 0; k < esp; k++) {
                  complejidad++;
                cout << " ";


            }
            cout << "\t";
        }
        cout << "\n";
    }
}

void moverDiscos(int **matriz, int filas, int columnas, int filaOrigen, int filaDestino, int discoMayor) {
    int columnaOrigen = 0, columnaDestino = 0;
  complejidad+=3;
    while (columnaOrigen < columnas && *(*(matriz + filaOrigen) + columnaOrigen) == 0) {
          complejidad++;
        columnaOrigen++;
    };
      complejidad++;
    if (columnaOrigen > columnas - 1) {
        columnaOrigen = 0;
          complejidad++;
    }
        complejidad++;
    while (columnaDestino < columnas &&*(*(matriz + filaDestino) + columnaDestino) == 0) {
        columnaDestino++;
          complejidad++;
    }
    *(*(matriz + filaDestino) + columnaDestino - 1) = *(*(matriz + filaOrigen) + columnaOrigen);
      complejidad++;
    *(*(matriz + filaOrigen) + columnaOrigen) = 0;
      complejidad++;
    pasos++;
    
    imprimir(matriz, filas, columnas, discoMayor);
    cout << " Paso: " << pasos;
}

void principal(int **matriz, int filas, int columnas, int discos, int discoMayor, int A, int B, int C) {
      complejidad++;
    if (discos == 1) {
        moverDiscos(matriz, filas, columnas, A, C, discoMayor);
    } else {
        principal(matriz, filas, columnas, discos - 1, discoMayor, A, C, B);
        moverDiscos(matriz, filas, columnas, A, C, discoMayor);
        principal(matriz, filas, columnas, discos - 1, discoMayor, B, A, C);
    }
}

int main(int argc, char** argv) {
    filas = 3;
    complejidad++;
    int discos = 1;
    complejidad++;
    cout << "Ingrese el numero de discos" << endl;
    cin>>columnas;
    complejidad++;
    puntero_matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        complejidad++;

        puntero_matriz[i] = new int[columnas];
    }
    complejidad++;
    for (int i = 0; i < filas; i++) {
        complejidad++;
        for (int j = 0; j < columnas; j++) {
            complejidad++;
            if (i == 0) {
                *(*(puntero_matriz + i) + j) = discos;
                discos += 2;
                complejidad += 3;
            } else {
                *(*(puntero_matriz + i) + j) = 0;
                complejidad++;
            }
        }
    }
    complejidad++;
    imprimir(puntero_matriz, filas, columnas, discos);
    principal(puntero_matriz, filas, columnas, columnas, discos, 0, 1, 2);
    cout << "\nComplejidad Programa Total:\n " << complejidad;
    return 0;
};

