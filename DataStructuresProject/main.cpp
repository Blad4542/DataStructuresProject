#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void insertData(){
}
void deleteData(){
}
void modifyPrices(){
}
void maintenance(){
    cout << "              Mantenimiento de Datos" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Insertar Datos\n" << "2.Borrar Datos\n" << "3.Modificar precios\n" << "4.Volver atras\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        insertData();
    }
    else if(option == "2"){
        system("cls");
        deleteData();
    }
    else if(option == "3"){
        system("cls");
        modifyPrices();
    }
    else if(option == "4"){
        system("cls");
        //menu();
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return maintenance();
    }
}
void consultation(){ // tengo dudas sobre como hacerlo
}
void reports(){ // dudas sobre como hacerlo
}

void menu(){
   cout << "              Bienvenido al sistema de la Agencia de Viajes Bananero" << endl;
    cout << endl;
    cout << "Lista de opciones: \n\n";
    cout << "1.Mantenimiento de Datos\n";
    cout << "2.Consultas\n";
    cout << "3.Reportes\n";
    cout << "4.Salir\n\n";
    cout << endl;
    cout << "Ingrese el numero de la opcion que desea: ";
    string option;
    cin >> option;
    if(option == "1"){
        system("cls");
        maintenance();
    }
    else if(option == "2"){
        system("cls");
        consultation();
    }
    else if(option == "3"){
        system("cls");
        reports();
        return;
    }
    else if(option == "4"){
        system("cls");
        return;
    }
    else{
        system("cls");
        cout << option;
        cout << "\nOpcion no valida, por favor introduzca nuevamente la opcion deseada\n\n";
        return menu();
    }

}
int main()
{
    menu();
    return 0;
}
