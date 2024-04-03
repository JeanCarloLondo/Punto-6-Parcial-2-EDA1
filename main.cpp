#include <Windows.h>

#include <iostream>
#include "Nodo.h"
#include "Menu.h"
#include "Cola.h"

using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"

int main()
{
    SetConsoleOutputCP(CP_UTF8); // para ver las tildes en el terminal

    Cola cola;

    int opcion;
    do
    {
        mostrarMenu();
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            string nombre;
            int membresia;
            int pelicula;
            int hora;

            cout << "Ingrese el nombre de la persona: (Minúscula) ";
            cin >> nombre;

            boolean r1 = true;
            while (r1 == true)
            {
                cout << "¿Es VIP? (1: Sí / 0: No): ";
                cin >> membresia;

                // Validar si la membresía es 0 o 1
                if (membresia != 0 && membresia != 1)
                {
                    cout << "Por los clavos de cristo. Debe ingresar 0 para No o 1 para Sí." << endl;
                    r1 = true;
                }
                else
                {
                    r1 = false;
                    break;
                }
            }

            boolean r2 = true;
            while (r2 == true)
            {
                cout << "Que pelicula desea ver?" << endl;

                std::cout << "(1) - La cucaracha mágica" << endl;
                std::cout << "(2) - Lentos Y Calmados 45" << endl;
                std::cout << "(3) - Pelicula de moda generica" << endl;
                std::cout << "(4) - La increible historia de EdiEdi" << endl;
                cin >> pelicula;

                // Validar si la opción de película está dentro del rango válido
                if (pelicula < 1 || pelicula > 4)
                {
                    cout << "Hagame el favor. Debe ingresar un número entre 1 y 4." << endl;
                    r2 = true;
                }
                else
                {
                    r2 = false;
                    break;
                }
            }

            boolean r3 = true;
            while (r3 == true)
            {

                cout << "Selecciona la hora de función" << endl;

                std::cout << "(1) - 11:30" << endl;
                std::cout << "(2) - 13:00" << endl;
                std::cout << "(3) - 15:45" << endl;
                std::cout << "(4) - 17:20" << endl;
                std::cout << "(5) - 19:00" << endl;
                std::cout << "(6) - 21:30" << endl;
                std::cout << "(7) - 00:00" << endl;

                cin >> hora;
                if (hora < 1 || hora > 7)
                {
                    cout << "Opción inválida. Debe ingresar un número entre 1 y 7." << endl;
                    r3 = true;
                }
                else
                {
                    r3 = false;
                    break;
                }
            }

            if (membresia == 0)
            { // NO ES VIP, SE AGREGA AL FINAL DE LA LISTA
                cout << RED << "Prioridad baja, asignando turno de baja prioridad" << endl;
                Nodo *persona_atendida = new Nodo(new Cine(nombre, membresia, pelicula, hora));
                cola.Add_cola(persona_atendida);
            }
            else if (membresia == 1)
            { // ES VIP, SE AGREGA AL PRINCIPIO DE LA LISTA
                cout << RED << "Prioridad alta, asignando turno de alta prioridad" << endl;
                Nodo *persona_atendida = new Nodo(new Cine(nombre, membresia, pelicula, hora));
                cola.Add_cab(persona_atendida);
            }

            break;
        }
        case 2:
        {
            Nodo *persona = cola.obtenerPrimero();

            cout << "La siguiente persona en ser atendida es: " + persona->getData()->nombre << endl;
            cout << " ->  ¿Deseas atender a " << persona->getData()->nombre << " ahora mismo?  (1)-SI  (2)-NO " << endl;
            int elec;
            cin >> elec;

            if (elec == 1)
            {
                cout << persona->getData()->nombre << " ha sido atendido." << endl;
                cola.Ret_cab();
            }
            else if (elec == 2)
            {
                cout << "No se ha atendido a nadie." << endl;
            }
            else
            {
                cout << "Por favor seleccione una opción válida." << endl;
            }

            break;
        }

        case 3:
        {
            string nombre;
            cout << "Ingrese el nombre de la persona que desea retirar de la cola: ";
            cin >> nombre;
            cola.Ret_nombre(nombre);
            cout << RED << nombre + " fue eliminado con éxito" << endl;
            break;
        }
        case 4:
        {

            cola.Listar();
            break;
        }

        case 5:
        {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        default:
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcion != 5);
}