# Flow

## Complexidades

- Dinic = **O((V^2)\*E)**
- Edmonds-Karp = **O(V\*(E^2))**
- FastKuhn = aproxi. **O(sqrt(V)\*E)**

## Pontos interessantes

- O valor do **Min-Cut** é o mesmo do **Max-Flow**.
- Em um problema de **edge-disjoint paths**, isso é, o maior número de caminhos entre dois vértices tais que cada aresta do grafo apareça em no máximo um caminho, será o max-flow do grafo tal que cada aresta tenha capacidade 1. 
- Já em um problema de **node-disjoint paths** (onde cada nó só pode aparecer em até um caminho), é preciso usar uma *safadeza*: duplica a quantidade de nós, fazendo com que todos os indegrees sejam em um Vin e todos outs de um Vout, e exista um caminho Vin -> Vout. A resposta será o Max-flow disso.
- Toda vez que um nó tiver capacidade, dá pra fazer essa safadeza de duplicar ele no grafo e criar um aresta com a capacidade desse nó.
- Pra pegar o **Min-Cut**, dá pra fazer dois conjuntos de nó: partindo do source faz uma dfs apenas com as arestas que não estão esgotadas. Todos os nós possíveis ficam em um conjunto e o restante no outro. Cada aresta que existe entre nós de cada um dos conjuntos está no **Min-Cut**.

## Hall's theorem
Em problemas de matching, esse teorema vai dizer se é possível ter um *perfect matching* e 'explicar' caso não dê: Assumindo X a reunião de todos os conjuntos de nós à esquerda e os conjuntos de vizinhos na direita como f(X), só haverá um *perfect matching* se para cada x pertencente a X, |x| <= |f(x)|.

## Kõnig's theorem

Para grafos bipartidos, o teorema nós oferece o **minimum node cover** (a quantidade mínima de nós tal que cada aresta seja coberta por pelo menos um nó). A resposta será o Max-Flow (ou matching).
Um corolário legal disso é que os nós que não estão no minimum cover, são um **maximum independent set**. 

## Path cover

Em grafos acíclicos e diretos, dá pra pensar o problema de **minimum path cover** como um problema de Max-Flow replicando do lado esquerdo e direito os nós do grafo.

### Minimum node-disjoint path cover
Replica os nós na direita e esquerda e só terá uma aresta da esquerda para a direita se houver essa aresta nó grafo original. Então o tamanho do minimum node-disjoint path cover será a quantidade de nós - o matching do grafo que construímos.

### General path cover
É uma versão mais simples do problema acima, onde cada nó pode participar de mais de um caminho. Daí a ideia é bem semelhante, mas haverá um nó da esquerda para direita toda vez que houver um caminho entre os dois nós em questão no grafo original. A reposta é do mesmo jeito. 

### Dilworth's theorem
Um **antichain** é um conjunto de nós tal que não há nenhuma aresta entre quaisquer dois nós desse conjunto. Segundo o teorema, o tamanho desse conjunto é o mesmo do **general path cover**.