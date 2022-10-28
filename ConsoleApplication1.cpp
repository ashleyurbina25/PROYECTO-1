
#include <iostream>
#include <sstream>
#include <fstream>
//#define NOMBRE_ARCHIVO "C:\Users\ashle\OneDrive\Desktop\ArchivosProyecto1\archivo2.csv"
using namespace::std;


//----------------------------------COLA------------------------------------------
/*                Estructura de los nodos de la cola
------------------------------------------------------------------------*/
struct nodoC {
    string cancion;
    string artista;
    nodoC* siguiente;
} *primero, * ultimo;



void insertarNodoC(string cancion, string artista) {
    nodoC* nuevo = new nodoC();
   
     nuevo->cancion = cancion;
     nuevo->artista =  artista;
     nuevo->siguiente = NULL;

    if (primero == NULL) {
        primero = nuevo;
        primero->siguiente = NULL;
        ultimo = primero;
    }
    else {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimo = nuevo;
    }
    cout << endl << " Nodo Ingresado " << endl << endl;
}

void buscarNodo() {
    nodoC* actual = new nodoC();
    actual = primero;
    bool encontrado = false;
    string cancion = " ";
    string artista = " ";
    //int nodoBuscado = 0;
    cout << " Ingrese el dato de Cancion del nodo a Buscar: ";
    cin >> cancion;
    cout << " Ingrese el dato de Artista del nodo a Buscar: ";
    cin >> artista;
    if (primero != NULL) {
        while (actual != NULL && encontrado != true) {

            if (actual->cancion == cancion && actual->artista == artista) {
                cout << "\n Nodo con el dato ( " << cancion << " ) Encontrado";
                cout << "\n Nodo con el dato ( " << artista << " ) Encontrado";
                encontrado = true;
            }

            actual = actual->siguiente;
        }
        if (!encontrado) {
            cout << "\n Nodo No Encontrado";
        }
    }
    else {
        cout << endl << " La cola se encuentra Vacia " << endl << endl;
    }
}

void modificarNodo() {
    nodoC* actual = new nodoC();
    actual = primero;
    bool encontrado = false;
    string cancion = " ";
    string artista = " ";
    //int nodoBuscado = 0;
    cout << " Ingrese el dato de Cancion del nodo a Modificar: ";
    cin >> cancion;
    cout << " Ingrese el dato de Artista del nodo a Modificar: ";
    cin >> artista;
    if (primero != NULL) {
        while (actual != NULL && encontrado != true) {

            if (actual->cancion == cancion && actual->artista == artista) {
                cout << "\n Nodo con el dato ( " << cancion << " ) Encontrado";
                cout << "\n Ingrese el nuevo dato para este Nodo: ";
                cin >> actual->cancion;
                cout << "\n Nodo con el dato ( " << artista << " ) Encontrado";
                cout << "\n Ingrese el nuevo dato para este Nodo: ";
                cin >> actual->artista;
                cout << "\n Nodo Modificado\n\n";
                encontrado = true;
            }

            actual = actual->siguiente;
        }
        if (!encontrado) {
            cout << "\n Nodo No Encontrado\n\n";
        }
    }
    else {
        cout << endl << " La cola se encuentra Vacia " << endl << endl;
    }
}

// primero = 45    ultimo = 12      actual = 12   anterior = null      encontrado = false         nodoBuscado = 6              45, 6, 7 , 12

// COLA            45 -> 6 -> 7 ->  12 -> NULL      

void eliminarNodo() {
    nodoC* actual = new nodoC();
    actual = primero;
    nodoC* anterior = new nodoC();
    anterior = NULL;
    bool encontrado = false;
    string cancion = " ";
    string artista = " ";
    //int nodoBuscado = 0;
    cout << " Ingrese el dato de Cancion del nodo a Modificar: ";
    cin >> cancion;
    cout << " Ingrese el dato de Artista del nodo a Modificar: ";
    cin >> artista;
    if (primero != NULL) {

        while (actual != NULL && encontrado != true) {

            if (actual->cancion == cancion) {
                if (actual->artista == artista)
                {
                    cout << "\n Nodo con el dato ( " << cancion << " ) Encontrado";
                    cout << "\n Nodo con el dato ( " << artista << " ) Encontrado";

                    if (actual == primero) {
                        primero = primero->siguiente;
                    }
                    else if (actual == ultimo) {
                        anterior->siguiente = NULL;
                        ultimo = anterior;
                    }
                    else {
                        anterior->siguiente = actual->siguiente;
                    }

                    cout << "\n Nodo Eliminado\n\n";

                    encontrado = true;

                }
              
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        if (!encontrado) {
            cout << "\n Nodo No Encontrado\n\n";
        }
    }
    else {
        cout << endl << " La cola se encuentra Vacia " << endl << endl;
    }
}

void desplegarCola() {
    nodoC* actual = new nodoC();
    actual = primero;
    if (primero != NULL) {
        while (actual != NULL) {
            cout << "( " << string(actual->artista) << " - " << string(actual->cancion) << ")" << endl;
            actual = actual->siguiente;
        }
    }
    else {
        cout << endl << " La cola se encuentra Vacia " << endl << endl;
    }
}






//---------------------------------------------------------------------------------





//----------------------------------PILA------------------------------------------

struct nodo {
    string cancion;
    string artista;
    struct nodo* sgte;
};

typedef nodo* ptrPila;   // creando nodo tipo puntero( tipo de dato )

/*                        Apilar elemento
------------------------------------------------------------------------*/
void push(ptrPila& p, string valor, string valor2)
{
    ptrPila aux;
    aux = new(struct nodo);  // apuntamos al nuevo nodo creado
    aux->artista = valor;
    aux->cancion = valor2;

    aux->sgte = p;
    p = aux;
}

/*                Desapilar elemento(devuelve elemento)
------------------------------------------------------------------------*/
 
string pop(ptrPila& p)
{
   // int num;
    string cancion;
    string artista;
    ptrPila aux;

    aux = p;
   // num = aux->nro;   // asignamos el primer vamor de la pila
    cancion = aux->cancion;
    artista = aux->artista;

    p = aux->sgte;
    delete(aux);

    return cancion, artista;
}



/*                     Muestra elementos de la pila
------------------------------------------------------------------------*/


string mostrar_pila_primero77777(ptrPila p)
{
    string txt = "";
    ptrPila aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        txt +=  "( " + aux->artista + " - " + aux->cancion + ")\n";
        aux = aux->sgte;
    }
    return txt;
}


void mostrar_pila_primero(ptrPila p)
{
    ptrPila aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        cout << "( " << aux->artista << " - " << aux->cancion << ")" << endl;
        aux = aux->sgte;
    }
}



void mostrar_pila(ptrPila p)
{
    ptrPila aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        cout << "( " << aux->artista << " - " << aux->cancion << ")" << endl;
        aux = aux->sgte;
    }
}


void mostrar_pila_cancion(ptrPila p)
{
    ptrPila aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        cout  << aux->cancion << endl;
        aux = aux->sgte;
    }
}

void mostrar_pila_artista(ptrPila p)
{
    ptrPila aux;
    aux = p;     // apunta al inicio de la lista

    while (aux != NULL)
    {
        cout << aux->artista << endl;
        aux = aux->sgte;
    }
}

/*                Eliminar todos los elementos de la pila
------------------------------------------------------------------------*/
void destruir_pila(ptrPila& p)
{
    ptrPila aux;

    while (p != NULL)
    {
        aux = p;
        p = aux->sgte;
        delete(aux);
    }
}


void ordenarListaArtista(ptrPila& p)
{
    ptrPila aux, siguiente;
    string t;

    aux = p;

    while (aux->sgte != NULL)
    {
        siguiente = aux->sgte;

        while (siguiente != NULL)
        {
            if (aux->artista > siguiente->artista)
            {
                t = siguiente->artista;
                siguiente->artista = aux->artista;
                aux->artista = t;
            }
            siguiente = siguiente->sgte;
        }
        aux = aux->sgte;
       
        siguiente = aux->sgte;
        //cout << aux->cancion << endl;
    }

    cout << "\n\n\tLista ordenada Ascendentemente..." << endl;
}

void ordenarListaArtista2(ptrPila& p)
{
    ptrPila aux, siguiente;
    string t;

    aux = p;

    while (aux->sgte != NULL)
    {
        siguiente = aux->sgte;

        while (siguiente != NULL)
        {
            if (aux->artista < siguiente->artista)
            {
                t = siguiente->artista;
                siguiente->artista = aux->artista;
                aux->artista = t;
            }
            siguiente = siguiente->sgte;
        }
        aux = aux->sgte;

        siguiente = aux->sgte;
        //cout << aux->cancion << endl;
    }

    cout << "\n\n\tLista ordenada Ascendentemente..." << endl;
}


void reportarListaArtista(ptrPila& p)
{


    while (p != NULL)
    {
       cout <<  p->artista<< endl;
       p =  p->sgte;
    }

}





void ordenarListaCancion(ptrPila& p)
{
    ptrPila aux, siguiente;
    string t;

    aux = p;

    while (aux->sgte != NULL)
    {
        siguiente = aux->sgte;

        while (siguiente != NULL)
        {
            if (aux->cancion > aux->cancion)
            {
                t = siguiente->cancion;
                siguiente->cancion= aux->cancion;
                aux->cancion  = t;
            }
            siguiente = siguiente->sgte;
        }
        aux = aux->sgte;
        siguiente = aux->sgte;

    }

    cout << "\n\n\tLista ordenada Ascendentemente..." << endl;
}


void reportarListaCancion(ptrPila& p)
{

    while (p != NULL)
    {
        cout <<  p->cancion  << endl;
        p = p->sgte;
    }

}




void escribirFrases(string p) {
    ofstream archivo;
    string nombreArchivo = "Playlist actual.txt", frase = p;
    char rpt;

    //cout << "Digite el nombre del archivo: ";
  //  getline(cin, nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::out); //Creamos el archivo

    if (archivo.fail()) { //Si a ocurrido algun error
        cout << "No se pudo abrir el archivo";
        exit(1);
    }


        fflush(stdin);
       // cout << "Digite una frase: ";
       // getline(frase);S
        archivo << frase << endl;



    archivo.close(); //Cerramos el archivo
}




ptrPila p = NULL;  // creando pila


//---------------------------------------------------------------------------------


void menu()
{
    cout << "\n\t PROYECTO PRACTICO NO. 01 - MUSIC FESTIVAL \n\n";
    cout << " 1. LEER ARCHIVOS DE ENTRADA              " << endl;
    cout << " 2. APILAR                                " << endl;
    cout << " 3. DESAPILAR                             " << endl;
    cout << " 4. MOSTRAR PILA                          " << endl;
    cout << " 5. DESTRUIR PILA                         " << endl;
    cout << " 6. ORDENAR ASCENDENETEMENTE POR CANCION  " << endl;
    cout << " 7. ORDENAR ASCENDENETEMENTE POR ARTISTA " << endl;
    cout << " 8. ORDENAR DESCENDENTEMENTE POR CANCION  " << endl;
    cout << " 9. ORDENAR DESCENDENTEMENTE POR ARTISTA " << endl;
    cout << " 10. ENCOLAR                               " << endl;
    cout << " 11. AGREGAR CANCIONES A COLA              " << endl;
    cout << " 12. REPRODUCIR AHORA                      " << endl;
    cout << " 13. MOSTRAR COLA                          " << endl;
    cout << " 14. VACIAR COLA                          " << endl;
    cout << " 15. SALIR                                " << endl;
    cout << "\n INGRESE OPCION: ";
}




int main()
{

    //struct cola q;

    ifstream archivo("C:\\Users\\ashle\\OneDrive\\Desktop\\ArchivosProyecto1\\archivo1.csv");
    string linea;
    char delimitador = ',';

    string x90, y;
    string cancion = "";
    string artista = " ";
    string xd = "";

    string cancion2, artista2;
    string cancion3, artista3;




    int dato;  // numero a encolar
    int op;    // opcion del menu
    int x;    // numero que devuelve la funcon pop

    system("color 0b");

    do
    {
        menu();  cin >> op;

        switch (op)
        {
        case 1:

            cout << endl << endl;

            // Leemos la primer línea para descartarla, pues es el encabezado
            getline(archivo, linea);
            // Leemos todas las líneas
            while (getline(archivo, linea))
            {

                stringstream stream(linea); // Convertir la cadena a un stream
           



                // Extraer todos los valores de esa fila
                getline(stream, cancion, delimitador);
                getline(stream, artista, delimitador);

                while (artista == " ") {
                    artista = "desconocido";

                }


                cout << "=============================" << endl;
                cout << "Cancion: " << cancion << endl;
                cout << "Artista: " << artista << endl;

                push(p, cancion, artista);
                insertarNodoC(cancion, artista);


                // cout << "\n\n MOSTRANDO COLA\n\n";
                // muestraCola(q);

               //  cout << "\n NUMERO A APILAR: "; cin >> dato;
            

                // cout << "\n\n MOSTRANDO PILA\n\n";
                 //if (p != NULL)
                   //  mostrar_pila(p);
                 //else
                   //  cout << "\n\n\tPila vacia..!" << endl;
                // cout << "\n\n\t\tcancion " << cancion << " - " << artista << " apilado...\n\n";

            }

            break;


        case 2:
         



            break;


        case 3:

            break;


        case 4:
            cout << "\n\n MOSTRANDO PILA\n\n";
            if (p != NULL)
                mostrar_pila(p);
            else
                cout << "\n\n\tPila vacia..!" << endl;

         
            xd = mostrar_pila_primero77777(p);

            break;


        case 5:

            break;


        case 6:

            ordenarListaCancion(p);
            reportarListaCancion(p);

            break;


        case 7:
            ordenarListaArtista(p);
            reportarListaArtista(p);
           // reportarListaCancion(p);

            break;


        case 8:

            break;


        case 9:

            break;


        case 10:

            //opcion 1 de colas 
          


            break;


        case 11:
            cout << "\n\n INGRESE SU NUEVA CANCION Y ARTISTA \n\n";


            cout << "\n\n INGRESE SU NOMBRE CANCION \n\n";
            cin >> cancion2;
            cout << "\n\n INGRESE SU NOMBRE ARTISTA \n\n";
            cin >> artista2;
            insertarNodoC(cancion2, artista2);

            cout << "\n\n NUEVA COLA  \n\n";
            cout << "\n\n MOSTRANDO COLA\n\n";
            desplegarCola();

            break;

        case 12:

            eliminarNodo();

            desplegarCola();

            break;

        case 13:

            cout << "\n\n MOSTRANDO COLA\n\n";
            desplegarCola();

            break;

        case 14:
           

            break;


        }

        cout << endl << endl;
        system("pause");  system("cls");

    } while (op != 15);






    ///cout << "\n\n PRIMERO DE PILA \n\n";
   // mostrar_pila_primero(p);



    //cout << "xdxdxdxdxdxdxdxd" << endl;
    //cout << xd << endl;

    //no

   





    //y = desencolarElemento(q, cancion3, artista3);
    //cout << "\n\n\t\tCancion " << y << " desencolado...\n\n";

    //muestraCola(q);






    //escribirFrases(xd);

    archivo.close();


    

}