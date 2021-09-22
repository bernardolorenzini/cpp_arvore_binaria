#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

/**
Node* criaNode(int k){

    Node* node = new Node();
    node->data = k;
    node->left = NULL;
    node->right = NULL;
    return node;
}


class bTree
{
    public:

        bTree(){
            raiz = NULL;
        }

        bool vazia(){
            return(raiz==NULL);
        }


        void inserir(int k);
        Node *procura(int k);
        void destroi_tree();

        void mostraArvore();
        void printTree(Node*);

    private:
        void destroi_tree(Node *folha);
        void inserir(int k, Node *folha);
        Node *procura(int k, Node *folha);

        Node *raiz;

};

void bTree::mostraArvore() {
    printTree(raiz);
}

void bTree::inserir(int k) {

    Node *n = new Node;
    Node *pai;
    n->data = k;
    n->right = NULL;
    n->left = NULL;
    pai = NULL;

    if (vazia())
        raiz = n;
    else{
        Node *aux;
        aux = raiz;
        while(aux != NULL){
            pai = aux;
            if(k > aux->left->data)
                aux = aux->right;
            else
                aux = aux->left;
        }
        if(k > pai->data)
            pai->left = n;
        else
            pai->right = n;
    }
}



void bTree::printTree(Node *node){
    if(node != NULL){
        printTree(node->left);
        cout<<" " << node->data << " ";
        printTree(node->right);
    }
}
**/

class Tree
{
    private:
        Node * root;


    public:
        Tree(){
            root = NULL;
        }

        void inserir(int k);
        void ordenado_();
        void ordenado(Node* n);
        int folhas_();
        int folhas(Node *atual);
};

int Tree::folhas(Node *atual){
    if(atual == NULL) return 0;
    if(atual->right == NULL && atual->left == NULL) return 1;
    return folhas(atual->left) + folhas(atual->right);
}

int Tree::folhas_() {
    return folhas(root);
}


void Tree::inserir(int k) {
    Node* novo = new Node();
    novo->data = k;
    novo->right = NULL;
    novo->left = NULL;

    if(root == NULL)
        root = novo;
    else{
        Node * atual = root;
        Node * pai;

        while(true){
            pai = atual;
            if( k <= atual->data){
                atual = atual->left;
                if(atual == NULL){
                    pai->left = novo;
                    return;
                }
            }
            else{
                atual = atual->right;
                if(atual == NULL){
                    pai->right = novo;
                    return;
                }
            }
        }

    }
}

void Tree::ordenado_() {
    ordenado(root);
}

void Tree::ordenado(Node *n) {
    if (n != NULL) {
        ordenado(n->left);
        cout << n->data << " ";
        ordenado(n->right);
    }
}

int main() {

    Tree b;
    b.inserir(20);
    b.inserir(10);
    b.inserir(5);
    b.inserir(15);
    b.inserir(40);
    /** b.inserir(45); **/
    b.inserir(30);

    b.ordenado_();
    cout<<endl;
    cout<<b.folhas_();

}
