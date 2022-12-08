#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

// tratando os vizinhos possiveis
vector<Pos> tratando_vecotor(vector<Pos> v,int linha,int coluna, vector<string> &mat){
    vector<Pos> tratados; // vetor a ser retonado
    for(int i = 0; i < v.size(); i++){
        if(v[i].l >= 0 && v[i].l < linha && v[i].c >= 0 && v[i].c < coluna && mat[v[i].l][v[i].c] != '.' && mat[v[i].l][v[i].c] != '#' && mat[v[i].l][v[i].c] != '&'){
            tratados.push_back(v[i]);
            //cout << v[i].l << " " << v[i].c << endl;
        }
    }
    return tratados;
}

/*
marque e empilhe a posição inicio
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da fila
    se ele for o destino
        retorne

    faça uma lista com todos os vizinhos de topo que ainda não foram percorridos
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        marque
        empilhe
*/
void show_way(int nl, int nc,Pos inicio, Pos fim, vector<string> &mat){
    stack<Pos> pilha;
    vector<Pos> vizinhos;
    Pos topo;

    mat[inicio.l][inicio.c] = '.';
    pilha.push(inicio);

    while(!pilha.empty()){
        topo = pilha.top();
        if(topo.l == fim.l && topo.c == fim.c){ // condição de parada
            break;
        }else{
            vizinhos = tratando_vecotor(get_vizinhos(topo),nl,nc,mat);
            if(vizinhos.empty()){
                mat[topo.l][topo.c] = '&';
                pilha.pop();
            }else{
                Pos v = vizinhos[0];                
                mat[v.l][v.c] = '.';
                pilha.push(v);
            }
        }
        /*for(string line : mat)
            cout << line << endl;
        char c;
        cin >> c;
        cin.ignore();*/
    }
}

// limpando a matriz, retirando o '&'
void limpa_matriz(int nl, int nc, vector<string> &mat){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(mat[i][j] == '&'){
                mat[i][j] = ' ';
            }
        }
    }
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    show_way(nl, nc, inicio, fim, mat);
    limpa_matriz(nl, nc, mat);
    for(string line : mat)
        cout << line << endl;
    /*cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl;*/
}