#include <iostream>
#include "LinkedList.h"
using namespace std;

void options(LinkedList *list);
void menu(LinkedList *list,int option);

int main() {

    LinkedList *list = new LinkedList();
    options(list);
}

void options(LinkedList *list){

    cout<<endl<<"------------MENU-------------"<<endl;
    cout<<endl<<"1. Insertar ELementos a la lista";
    cout<<endl<<"2. Mostrar elementos de la lista";
    cout<<endl<<"3. Buscar elemento en la lista";
    cout<<endl<<"4. ELiminar nodo de la lista";
    cout<<endl<<"5. Calcular suma promedio de numeros pares de la lista";
    cout<<endl<<"6. Calcular suma promedio de numeros impares de la lista";
    cout<<endl<<"7. Calcular numero menor de la lista";
    cout<<endl<<"8. Calcular numero mayor de la lista";
    cout<<endl<<"9. Mostrar elementos repetidos de la lista";
    cout<<endl<<"10.Eliminar nodo duplicados";
    cout<<endl<<"11.Invertir Lista";
    cout<<endl<<"12.Ordenar Lista";
    cout<<endl<<"13.Salir"<<endl;
    cout<<endl<<"Ingrese la opcion a realizar: ";
    int option;
    cin>>option;
    menu(list,option);

}

void menu(LinkedList *list,int option){
    switch (option) {
        case 1:
            int element;
            cout<<endl<<"Ingrese el valor a agregar a la lista: ";
            cin>>element;
            list->insert(element);
            options(list);
            break;
        case 2:
            list->printList();
            options(list);
            break;
        case 3:
            cout<<"Ingrese la posicion del elemento a buscar: ";
            int objetive;
            cin>>objetive;
            list->searchElement(objetive);
            options(list);
            break;
        case 4:
            cout<<"Ingrese la posicion a eliminar: ";
            int value;
            cin>>value;
            list->pop(value);
            options(list);
            break;
        case 5:
            cout<<"La suma promedio de numeros pares que se encuentran en la lista es de : "<<list->evenAverage()<<endl;
            options(list);
            break;
        case 6:
            cout<<"La suma promedio de numeros impares que se encuentran en la lista es de : "<<list->oddAverage()<<endl;
            options(list);
            break;
        case 7:
            list->lower();
            options(list);
            break;
        case 8:
            list->higher();
            options(list);
            break;
        case 9:
            list->showRepeated();
            options(list);
            break;
        case 10:
            list->deleteRepeated();
            options(list);
            break;
        case 11:
            list->reverse();
            cout<<"Lista invertida correctamente"<<endl;
            list->printList();
            options(list);
            break;
        case 12:
            list->sort();
            options(list);
            break;
        case 13:
            break;
        default:
            cout<<"Por favor ingrese una opcion correcta"<<endl;
            options(list);
            break;
    }
}

