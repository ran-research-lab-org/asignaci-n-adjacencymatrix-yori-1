#include "Graph.hpp"

using namespace std;

int main() {
  Graph G(10);
  G.addEdge(0,9);
  G.addEdge(4, 2);

  G.print();
  cout << endl;

  cout << "Número total de aristas: " << G.numEdges() << "\n\n";

  cout << "GradoEntrada de 9: " << G.inDegree(9) << "\n";
  cout << "GradoEntrada de 2: " << G.inDegree(2) << "\n";
  cout << "GradoEntrada de 0: " << G.inDegree(0) << "\n\n";

  for (int fila = 0; fila < 10; ++fila) {
        if (G.isInfluencer(fila)) {
            cout << "El nodo \'" << fila << "\' es un influencer.\n";
        }
    }
    
}
