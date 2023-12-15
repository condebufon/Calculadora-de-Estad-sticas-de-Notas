#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>
#include <cstdlib>

using namespace std;

//Descripción: Crear una calculadora que permite a los estudiantes calcular estadísticas simples a partir de sus notas en diferentes asignaturas.
//*Modulación:
//Módulo de entrada de nombre del estudiantes
//Módulo de entrada de notas.
//Módulo de cálculo de estadísticas.
//Módulo de presentación de resultados.
//Agregar funcionalidades como la clasificación de notas y retroalimentación sobre el desempeño del estudiante.
//__________________________________________________
// Módulo de entrada de nombre del estudiante

string EscribirnombreEstudiante() 
{
    string anombre;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> anombre;
    return anombre;
}
//__________________________________________________
// Módulo de entrada de nombre de la materia
string obtenerNombreMateria() 
{
    string nombre;
    cout << "Ingrese el nombre de la materia: ";
    cin >> nombre;
    return nombre;
}
//__________________________________________________
// Módulo de entrada de notas
vector<double> obtenerNotas() 
{  
    vector<double> notas;
    bool seguirIngresando = true;

    while (seguirIngresando) 
    {
        double nota;
        cout << "Ingrese la nota: ";
        cin >> nota;
        notas.push_back(nota);

        char opcion;
        cout << "¿Desea ingresar otra nota? (s/n): ";
        cin >> opcion;

        if (opcion == 'n' || opcion == 'N') 
        {
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
void mostrarResultados(const string& nombreEstudiante, string& nombremateria, const vector<double>& notas) 
{
  cout << "\n-------- Resultados --------\n";
  
  cout << "Estudiante: " << nombreEstudiante << endl;
  cout << "materia: " << nombremateria << endl;
  cout << "Notas:" << endl;
  for (int i = 0; i < notas.size(); i++) 
  {
      cout << "Asignatura " << i + 1 << ": " << notas[i] << endl;
  }

  double promedio = calcularPromedio(notas);
  cout << "Promedio: " << promedio << endl;
  // Clasificación de notas y retroalimentación
  if (promedio >= 4.5) 
  {
      cout << "Clasificación: Excelente" << endl;
  } else if (promedio >= 4.0) 
  {
      cout << "Clasificación: Bueno" << endl;
  } else if (promedio >= 3.5) 
  {
      cout << "Clasificación: Regular" << endl;
  } else 
  {
      cout << "Clasificación: Necesita mejorar" << endl;
  }

  cout << endl;
}

int main() 
{
  string NombreMateria;
  string nombreEstudiante;
  vector<double> notas;
  bool salir = false;

  while (!salir) {
      cout << "***** Menú ******" << endl;
      cout << "1. Ingresar nombre del estudiante" << endl;
      cout << "2. Ingresar nombre de la materia" << endl;
      cout << "3. Ingresar notas en la materia" << endl;
      cout << "4. Salir" << endl;
      cout << "Ingrese una opción: ";

      int opcion;
      cin >> opcion;

      switch (opcion) {
          case 1:
              nombreEstudiante = EscribirnombreEstudiante();
              break;
          case 2:
              NombreMateria = obtenerNombreMateria();
              break;
          case 3:
              notas = obtenerNotas();
              break;
          case 4:
              salir = true;
              break;
          default:
              cout << "Opción inválida. Intente nuevamente." << endl;
              break;
      }

      if (!nombreEstudiante.empty() && !NombreMateria.empty() && !notas.empty()) 
      {
          mostrarResultados(nombreEstudiante, NombreMateria, notas);
          NombreMateria.clear();
          notas.clear();
      }
  }

  return 0;
}
