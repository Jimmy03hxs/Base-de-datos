#include "MySQLConexion.h"
#include "EloquentORM.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Crear la conexión a la base de datos
    MySQLConexion conn("root", "admin1234", "CONTROL_PERSONAL");

    // Verificar si la conexión fue exitosa
    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    }
    else {
        cout << "¡Conexión exitosa!" << endl;
    }

    // Definir las columnas que se quieren obtener de la tabla 'personas'
    vector<string> columnas = { "NOMBRE", "EDAD", "GENERO" };

    // Crear una instancia del ORM para la tabla 'personas'
    EloquentORM personal(conn, "personal", columnas);

    // Obtener todos los registros
    auto lista = personal.getAll();

    // Mostrar los registros en consola
    for (auto& reg : lista) {
        cout << "ID: " << reg["ID"]
             << ", Nombre: " << reg["NOMBRE"]
             << ", Edad: " << reg["EDAD"]
             << ", Género: " << reg["GENERO"] << endl;
    }
    system("pause");
    return 0;
}
