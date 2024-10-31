#include <iostream>
#include <deque>
#include <queue>
#include <string>

using namespace std;

// Clase Cola Doble Entrada
class ColaDobleEntrada {
private:
    deque<string> elementos;

public:
    void ingresar_izquierda(const string& elemento) {
        elementos.push_front(elemento);
    }

    void ingresar_derecha(const string& elemento) {
        elementos.push_back(elemento);
    }

    string sacar() {
        if (!elementos.empty()) {
            string elemento = elementos.front();
            elementos.pop_front();
            return elemento;
        }
        return "Cola vacía";
    }

    int cantidad() const {
        return elementos.size();
    }

    // Método para mostrar todos los elementos de la cola sin sacarlos
    void mostrar() const {
        cout << "Contenido de la Cola Doble Entrada: ";
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
};

// Clase Cola con Prioridades
class ColaConPrioridades {
private:
    priority_queue<pair<int, string>> elementos;

public:
    void ingresar(const string& elemento, int prioridad) {
        elementos.push(make_pair(-prioridad, elemento));  // Usamos prioridad negativa para invertir el orden
    }

    string sacar() {
        if (!elementos.empty()) {
            string elemento = elementos.top().second;
            elementos.pop();
            return elemento;
        }
        return "Cola vacía";
    }

    int cantidad() const {
        return elementos.size();
    }

    // Método para mostrar todos los elementos de la cola sin sacarlos
    void mostrar() {
        cout << "Contenido de la Cola con Prioridades: ";
        // Creamos una copia para poder recorrer los elementos sin modificar la cola original
        priority_queue<pair<int, string>> copia = elementos;
        while (!copia.empty()) {
            cout << copia.top().second << "(Prioridad: " << -copia.top().first << ") ";
            copia.pop();
        }
        cout << endl;
    }
};

// Función principal con menú interactivo
int main() 
{
      system("chcp 65001");

    // Configurar el entorno para mostrar caracteres especiales
    setlocale(LC_ALL, "es_ES.UTF-8");
    ColaDobleEntrada cola_doble;
    ColaConPrioridades cola_prioridades;
    int opcion;

    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Ingresar en Cola Doble Entrada (Izquierda)\n";
        cout << "2. Ingresar en Cola Doble Entrada (Derecha)\n";
        cout << "3. Sacar de Cola Doble Entrada\n";
        cout << "4. Ver cantidad en Cola Doble Entrada\n";
        cout << "5. Mostrar elementos de Cola Doble Entrada\n";
        cout << "6. Ingresar en Cola con Prioridades\n";
        cout << "7. Sacar de Cola con Prioridades\n";
        cout << "8. Ver cantidad en Cola con Prioridades\n";
        cout << "9. Mostrar elementos de Cola con Prioridades\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        string elemento;
        int prioridad;

        switch (opcion) {
            case 1:
                cout << "Ingrese el elemento para Cola Doble Entrada (Izquierda): ";
                cin.ignore();
                getline(cin, elemento);
                cola_doble.ingresar_izquierda(elemento);
                break;
            case 2:
                cout << "Ingrese el elemento para Cola Doble Entrada (Derecha): ";
                cin.ignore();
                getline(cin, elemento);
                cola_doble.ingresar_derecha(elemento);
                break;
            case 3:
                cout << "Elemento sacado de Cola Doble Entrada: " << cola_doble.sacar() << endl;
                break;
            case 4:
                cout << "Cantidad en Cola Doble Entrada: " << cola_doble.cantidad() << endl;
                break;
            case 5:
                cola_doble.mostrar();
                break;
            case 6:
                cout << "Ingrese el elemento para Cola con Prioridades: ";
                cin.ignore();
                getline(cin, elemento);
                cout << "Ingrese la prioridad (menor número = mayor prioridad): ";
                cin >> prioridad;
                cola_prioridades.ingresar(elemento, prioridad);
                break;
            case 7:
                cout << "Elemento sacado de Cola con Prioridades: " << cola_prioridades.sacar() << endl;
                break;
            case 8:
                cout << "Cantidad en Cola con Prioridades: " << cola_prioridades.cantidad() << endl;
                break;
            case 9:
                cola_prioridades.mostrar();
                break;
            case 10:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 10);

    return 0;
}
