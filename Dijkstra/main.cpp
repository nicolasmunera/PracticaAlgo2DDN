//
//  main.cpp
//  Dijkstra
//
//  Created by Nicolás Múnera on 14/05/13.
//  Copyright (c) 2013 Nicolás Múnera. All rights reserved.
//

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
const int MAXN = 100005;
const int INF = 1 << 30;
vector <edge> g[MAXN];

int d[MAXN];
int p[MAXN];

void dijkstra(int s, int n){

    for (int i = 0; i <= n; ++i){
        d[i] = INF;
        p[i] = -1;
    }
    
    priority_queue < dist_node, vector <dist_node>,
    greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
        if (dist > d[cur]) continue;
        for (int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if (d[cur] + w_extra < d[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                q.push(dist_node(d[next], next));
            } }
    }
    for(int i = 0; i < 7 ; i++){
        cout << d[i] << endl;
    }
}

vector <int> encontrarCaminoMasCorto(int nodoFinal){
    vector<int> camino;
    int cur = nodoFinal;
    while(cur != -1){
        camino.push_back(cur);
        cur = p[cur];
    }
    reverse(camino.begin(), camino.end());
    for(int i = 0; i < 8; i++){
        
        cout << camino[i] << endl;
        if(i==nodoFinal){
            break;
        }
    }
    return camino;
}

int main(){
    int nodos , rutas, inicial, final;
    cin>> nodos >> rutas >> inicial >> final;
    
    for (int i = 0; i < rutas; ++i){
        int nodoInicial, nodoFinal, pesoNodo;
        cin >> nodoInicial >> nodoFinal >> pesoNodo;
        g[nodoInicial].push_back(edge(nodoFinal, pesoNodo));
    }
  
    
    for (int u = 0; u < nodos; ++u){
        for (int i = 0; i < g[u].size(); ++i){
            int v = g[u][i].first;
            int w = g[u][i].second;
            printf("Edge from %d to %d with weight %d\n", u, v, w);
        }
    }
    cout << "--Dijkstra--- \n" ;
    dijkstra(inicial, final);
    
    cout << "--Camino Corto--- \n" ;
    encontrarCaminoMasCorto(final);
    
    cout << "----- perigay\n" ;
    return 0;
}



