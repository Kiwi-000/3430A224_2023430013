#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

//crear nodo
Node* createNode(int data){
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;

}

//Insertar 
Node* insert(Node* root, int data){
    if (root == NULL){
        root = createNode(data);
    }
    else if (data <= root -> data){
        root -> left = insert(root -> left, data);
    }
    else{
        root -> right = insert(root -> right, data);
    }
    return root;
}

//buscar
bool search(Node* root, int data){
    if(root == NULL){
        return false;
    }
    else if (root -> data == data){
        return true;
    }
    else if ( data <= root -> data){
        return search(root -> left, data);
    }
    else{
        return search(root -> right, data);
    }
}

//eliminar
Node* deleteNode(Node* root, int key){
    if (root == NULL) {
    return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

//modificar elemento buscado
void modify(Node* root, int oldData, int newData) {
    if (search(root, oldData)) {
        root = deleteNode(root, oldData);
        root = insert(root, newData);
        cout << "Nodo modificado correctamente.";
    } else {
        cout << "Elemento no encontrado.";
    }
}

// genera el archivo dot
void generarDot(Node* root, ofstream& file) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        file << "    " << root->data << " -> " << root->left->data << ";" << endl;
        generarDot(root->left, file);
    }

    if (root->right != NULL) {
        file << "    " << root->data << " -> " << root->right->data << ";" << endl;
        generarDot(root->right, file);
    }
}

//crear archivo dot
void crearDot(Node* root){
    ofstream file("grafo.txt");
    file << "digraph G {"<< endl;
    if (root != NULL) {
        generarDot(root, file);
    }
    file << "}"<< endl;
    file.close();
    cout << "Archivo DOT generado correctamente."<< endl;
}

//imprimir Preorden
void printPreorder(Node* root) {
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}


//imprimir Inorder
void printInorder(Node* root) {
    if (root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


//Imprimir Posorden
void printPostorder(Node* root) {
    if (root == NULL){
         return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}


int main(){
    Node* root = NULL;
    int option;
    int data;
    int oldData;
    int newData;

    do {
        cout << "_______________________" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Eliminar elemento" << endl;
        cout << "4. Modificar elemento" << endl;
        cout << "5. Imprimir Preorden" << endl;
        cout << "6. Imprimir Inorden" << endl;
        cout << "7. Imprimir Posorden" << endl;
        cout << "8. Generar grafo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Ingrese el valor a insertar: ";
                cin >> data;
                root = insert(root, data);
                cout << "Elemento insertado." << endl;
                break;
            case 2:
                cout << "Ingrese el valor a buscar: ";
                cin >> data;
                if (search(root, data)) {
                    cout << "Elemento encontrado." << endl;
                } else {
                    cout << "Elemento no encontrado." << endl;
                }
                break;
            case 3:
                cout << "Ingrese el valor a eliminar: ";
                cin >> data;
                root = deleteNode(root, data);
                cout << "Elemento eliminado." << endl;
                break;
            case 4:
                cout << "Ingrese el valor a modificar: ";
                cin >> oldData;
                cout << "Ingrese el nuevo valor: ";
                cin >> newData;
                modify(root, oldData, newData);
                break;
            case 5:
                cout << "Preorden: ";
                printPreorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Inorden: ";
                printInorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Posorden: ";
                printPostorder(root);
                cout << endl;
                break;
            case 8:
                crearDot(root);
                system("dot -Tpng -ografo.png grafo.txt");
                system("explorer grafo.png");
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

            
    } while (option != 0);

    return 0;
}