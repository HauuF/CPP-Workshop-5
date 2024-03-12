#include "libs/List.h"

#include <iostream>
#include <math.h>

using namespace std;

bool comparar(int* puntero1, int* puntero2, List<int>& lista){
    int Address1, Address2;
    for(int i = 0; i < lista.size; i++){
        if(lista.getAddressOf(i) == puntero1){
            Address1 = i;
        }
        if(lista.getAddressOf(i) == puntero2){
            Address2 = i;
        }
    }
    return lista.get(Address1) < lista.get(Address2);
}

void ordenarListaPunteros(List<int*>& listpointer, List<int>& lista) {
    for (int i = 0; i < listpointer.size - 1; i++) {
        for (int j = 0; j < listpointer.size - i - 1; j++) {
            int* Address1 = listpointer.get(j);
            int* Address2 = listpointer.get(j + 1);
            if (!comparar(Address1, Address2, lista)) {
                listpointer.set(j, Address2);
                listpointer.set(j + 1, Address1);
            }
        }
    }
}

void printMenu();

int main() {
    
    int option = 0;
    List<int> lista;
    List<int*> listpointer;

    do {
        printMenu();

        cout << "Ingrese una opción: ";
        cin >> option;

       switch (option)
        {
            case 1:
            {
                cout << endl;
                cout << "Opción 1" << endl;
                int limite;
                srand(time(0));
                cout << "Inserte la cantidad de números de la lista (del 1 al 200): " << endl;
                cin >> limite;
                if(limite <= 200){
                    for(int i = 0; i < limite; i++){
                        int random = 0;
                        random = rand() % 200 + 1;
                        lista.add(random);
                    }
                }
                else{
                    cout << "Valor no válido." << endl;
                }
            cout << "Lista creada." << endl;
            cout << endl;
            }
                break;
            case 2:
            {
                cout << endl;
                cout << "Opción 2" << endl;
                for(int i = 0; i < lista.size; i++){
                    int* listapuntador = lista.getAddressOf(i);
                    listpointer.add(listapuntador);
                }
                cout << "Lista de apuntadores creada." << endl;
                cout << endl;
            }
                break;
            case 3:
            {
                cout << endl;
                cout << "Opción 3" << endl;
                ordenarListaPunteros(listpointer, lista);
                cout << "Lista de apuntadores ordenada." << endl;
                cout << endl;
            }
                break;
            case 4:
            {
                cout << endl;
                cout << "Opción 4" << endl;
                for(int i = 0; i < lista.size; i++){
                    cout << "Miembro #"<<i + 1<<": "<<lista.get(i)<<" "<< endl;
                }
                cout << endl;
            }
                break;
            case 5:
            {
                cout << "Opción 5" << endl;
                for(int i = 0; i <  listpointer.size; i++){
                    cout << "Miembro #"<< i + 1 <<": "<< *listpointer.get(i) <<" "<< endl;
                }
                cout << endl;
            }
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        } 

    } while (option != 0);
    listpointer.clear();
    lista.clear();
    return 0;
}

void printMenu() {
    cout << "1. Generar lista con número aleatorios" << endl;
    cout << "2. Generar lista de apuntadores a la primera lista" << endl;
    cout << "3. Ordenar lista de apuntadores" << endl;
    cout << "4. Imprimir lista original" << endl;
    cout << "5. Imprimir lista de apuntadores" << endl;
    cout << "0. Salir" << endl;
}