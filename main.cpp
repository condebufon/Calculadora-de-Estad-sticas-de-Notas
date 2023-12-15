#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>
#include <cstdlib>

using namespace std;
//textbackground(1);
//Descripción: Crear una calculadora que permite a los estudiantes calcular estadísticas simples a partir de sus notas en diferentes asignaturas.
//*Modulación:
//Módulo de entrada de nombre del estudiantes
//Módulo de entrada de notas.
//Módulo de cálculo de estadísticas.
//Módulo de presentación de resultados.
//Agregar funcionalidades como la clasificación de notas y retroalimentación sobre el desempeño del estudiante.
//__________________________________________________
// Módulo de entrada de nombre del estudiante

// Módulo de entrada de nombre del estudiante
string NombreEstudiante() 
{
    string nombre;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    return nombre;
}
//__________________________________________________
// Módulo de entrada de notas
vector<double> obtenerNotas() 
{  
    vector<double> notas;
    bool seguirIngresando = true;

    while (seguirIngresando) {
        double nota;
        cout << "Ingrese la nota: ";
        cin >> nota;
        notas.push_back(nota);

        char opcion;
        cout << "¿Desea ingresar otra nota? (s/n): ";
        cin >> opcion;

        if (opcion == 'n' || opcion == 'N') {
            seguirIngresando = false;
        }
    }
    return notas;
}
//__________________________________________________
// modulo de calculo de estadisticas
double calcularPromedio(const vector<double>& notas) 
{
    double suma = 0;
    for (double nota : notas) 
    {
        suma += nota;
    }
    return suma / notas.size();
}

//__________________________________________________
// Módulo de presentación de resultados
void mostrarResultados(const string& nombreEstudiante, const vector<double>& notas) 
{
  cout << "\n-------- Resultados --------\n";
  
  cout << "Estudiante: " << nombreEstudiante << endl;
  cout << "Notas:" << endl;
  for (int i = 0; i < notas.size(); i++) 
  {
      cout << "Asignatura " << i + 1 << ": " << notas[i] << endl;
  }

  double promedio = calcularPromedio(notas);
  cout << "Promedio: " << promedio << endl;
  // Clasificación de notas y retroalimentación
  if (promedio >= 4.5) {
      cout << "Clasificación: Excelente" << endl;
  } else if (promedio >= 4.0) {
      cout << "Clasificación: Bueno" << endl;
  } else if (promedio >= 3.5) {
      cout << "Clasificación: Regular" << endl;
  } else {
      cout << "Clasificación: Necesita mejorar" << endl;
  }

  cout << endl;
}

int main() {
  string nombreEstudiante = NombreEstudiante();
  vector<double> notas = obtenerNotas();
  mostrarResultados(nombreEstudiante, notas);

  return 0;
}


  
