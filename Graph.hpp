#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) { //en rango u y v
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        int contador = 0;
        for (int fila = 0; fila < numVertices; ++fila) {        
            for (int colum = 0; colum < numVertices; ++colum) { 
                if (adjMatrix[fila][colum] != 0) {contador++;}     
            }
        }
                return contador;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        int contador = 0;

        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        else {
            for (int fila = 0; fila < numVertices; ++fila) {   //recorre cada valor en la fila.origen
                if (adjMatrix[fila][u] != 0) {contador++;}     // total de cuántos apuntan -> 4
            }
        }
            return contador;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        
        int num_entradas = inDegree(u);        //número de cuántos apuntan -> 4 
        int max = 0;
        for (int fila = 0; fila < numVertices; ++fila){  //recorre los demás valores de la fila.origen, 1,2,3,
            int comparador = inDegree(fila);        
            if (comparador > max){
                max = comparador;           //almacena el gradoEntrada mayor
            }
        }
        return num_entradas == max;

    }
};

