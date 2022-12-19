#include <iostream>
#include <vector>
using namespace std;

struct Arista {
       //struct nodo *nodo;
       int valnextnod; //Valor del nodo al que conecta
       //int suma;
       int clave;
       //struct arista *sig;
};

struct Nodo {
       int nod;
       //int marca=NULL;
       struct Nodo *sig=NULL;
       std::vector<Arista *> vec;
};



class Graph{
    private:
        int numNods;
        std::vector<Nodo*> vec;
        Nodo *pri = NULL;
    public:
        Graph(){};
        bool find(int v){
            if(pri!=NULL){
                Nodo *aux = new Nodo();
                aux=pri;
                while(aux!=NULL){
                    if(aux->nod==v){
                        return true;
                    }
                    aux=aux->sig;
                }
                
            }
            return false;
        }
        void add(int nod){
            if(pri==NULL){
                Nodo *nuev = new Nodo();
                nuev->nod = nod;
                pri = nuev;
                vec.push_back(nuev);
            }else{
                if(find(nod)==true){
                    cout<<"Error, valor de nodo repetido"<<endl;
                    return;
                }
                Nodo *nuev = new Nodo();
                nuev->nod = nod;
                Nodo *aux = new Nodo();
                aux=pri;
                while(aux!=NULL){
                    if(aux->sig==NULL){
                         aux->sig=nuev;
                         vec.push_back(nuev);
                         return;
                    }
                    aux=aux->sig;
                }
            }
        }
        void addArist(int n, int n2, int v){
            if(pri==NULL){
                cout<<"Error, no existen nodos en el grafo"<<endl;
                return;
            }else{
                if(find(n)==false||find(n2==false)){
                    cout<<"Error, nodo no encontrado"<<endl;
                    return;
                }else{
                    Nodo *aux = new Nodo();
                    aux = pri;
                    Arista *nuev = new Arista();
                    Arista *nuev2 = new Arista();
                    nuev->valnextnod = n2; //valor del segundo nodo
                    nuev->clave = v; //Valor de la arista
                    nuev2->valnextnod = n; //Valor del primer nodo
                    nuev2->clave = v;
                    while(aux!=NULL){
                        if(aux->nod==n){
                            aux->vec.push_back(nuev);
                            
                        }else if(aux->nod==n2){
                            aux->vec.push_back(nuev2);
                            
                        }
                        aux=aux->sig;
                    }
                    return;
                }
            }
        }
        void ListaAdj(){
            for(int i=0; i<vec.size();i++){
                if(vec.at(i)->vec.size()==0){
                    cout << vec.at(i)->nod <<endl;
                }else{
                    cout << vec.at(i)->nod <<" -> ";
                    for(int j=0; j<vec.at(i)->vec.size();j++){
                        cout <<"("<<vec.at(i)->vec.at(j)->valnextnod<<","<< vec.at(i)->vec.at(j)->clave << ") ";
                    }
                    cout<<endl;
                }
                
            }
            
        }

        

};

int main(){
    Graph a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);
    a.add(6);
    a.add(7);
    a.addArist(1,2,8);
    a.addArist(1,3,1);
    a.addArist(2,3,5);
    a.addArist(2,4,2);
    a.addArist(3,4,7);
    a.addArist(3,5,5);
    a.addArist(5,7,3);
    a.addArist(5,6,9);
    a.ListaAdj();
    return 0;
}
