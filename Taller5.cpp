#include "libs/List.h"

#include <iostream>
#include <math.h>

using namespace std;

void printMenu();

int main() {
    
    
    int option = 0;
    List<int> lista;


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




                cout << endl;
            }
                break;
            case 3:
            {
                cout << endl;
                cout << "Opción 3" << endl;




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
