//
// Created by srestrep74 on 28/09/22.
//

#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList(){
    this->head = NULL;
}

void LinkedList::insert(int value){
    Node *new_node = new Node(value);

    if(head == NULL){
        head = new_node;
        cout<<"------ELemento insertado-----"<<endl;
    }else{
        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next= new_node;
        cout<<"-----Elemento insertado-------";
    }
}

void LinkedList::printList(){
    Node *aux = head;
    cout<<"LISTA: ";
    while(aux!=NULL){
        cout<<aux->value<<"->";
        aux = aux->next;
    }
    cout<<"NULL"<<endl;
}

void LinkedList::searchElement(int posicion){
    int length = len();
    if(length < posicion){
        cout<<"EL nodo no se encuentra en la lista"<<endl;
    }else{
        int count = 0;
        Node *aux = head;
        while(aux!=NULL){
            count++;
            if(count == posicion){
                cout<<"EL valor en la posicion "<<posicion<<" es "<<aux->value<<endl;
                break;
            }
            aux = aux->next;
        }
    }
}

int LinkedList::len(){
    int length = 0;
    Node *temp = head;
    while(temp!= NULL){
        length++;
        temp = temp->next;
    }

    return length;
}

void LinkedList::pop(int posicion){
    int length = len();
    if(length<posicion){
        cout<<"EL nodo no se encuentra en la lista"<<endl;
    }else if(posicion ==1){
        Node *aux1 = head;
        Node *aux2 = head->next;
        head = aux2;
        delete aux1;
        cout<<"Nodo eliminado correctamente";
    }else{
            Node *aux1 = head;
            Node *aux2 = head->next;
            int count = 1;
            while(aux1!=NULL && aux2!=NULL){
                count++;
                if(count==posicion){
                    aux1->next = aux2->next;
                    delete aux2;
                    cout<<"Nodo eliminado correctamente";
                    break;
                }
                aux1 = aux2;
                aux2 = aux1->next;
            }
    }
}

int LinkedList::evenAverage() {

    if(isEmpty()==false){
        int length = len();
        int sum = 0;
        Node *aux = head;
        while(aux!=NULL){
            if(aux->value%2==0){
                sum += aux->value;
            }

            aux = aux->next;
        }

        return sum/length;
    }else{
        return 0;
    }
}

int LinkedList::oddAverage() {

    if(isEmpty()==false){
        int length = len();
        int sum = 0;
        Node *aux = head;
        while(aux!=NULL){
            if(aux->value%2==1){
                sum += aux->value;
            }

            aux = aux->next;
        }

        return sum/length;
    }else{
        return 0;
    }
}

bool LinkedList::isEmpty() {
    bool empty = false;
    if(head==NULL){
        empty = true;
    }
    return empty;
}

void LinkedList::lower(){
    if(isEmpty()==false){
        Node* aux = head;
        int lower = head->value;
        while(aux!=NULL){
            if(aux->next!= NULL && (aux->next->value < lower)){
                lower = aux->next->value;
            }

            aux = aux->next;
        }
        cout<<"El elemento menor de la lista es : "<<lower<<endl;
    }

}

void LinkedList::higher() {
    if(isEmpty()==false){
        Node* aux = head;
        int higher = head->value;
        while(aux!=NULL){
            if(aux->next!= NULL && (aux->next->value > higher)){
                higher = aux->next->value;
            }

            aux = aux->next;
        }
        cout<<"El elemento mayor de la lista es de : "<<higher<<endl;
    }
}

void LinkedList::showRepeated(){
    string repetidos = "";
    if(isEmpty()==false){
        Node *aux1 = head;
        Node *aux2 = head->next;
        while(aux1!=NULL && aux2!=NULL){

            while(aux2!=NULL){
                if(aux1->value==aux2->value){
                    if(repetidos.find(to_string(aux1->value))){
                        repetidos.append(to_string(aux1->value));
                    }

                }
                aux2 = aux2->next;
            }
            aux1 = aux1->next;
            aux2 = aux1->next;
        }
    }

    cout<<"Los elementos repetidos de la lista son "<<repetidos;
}

void LinkedList::deleteRepeated() {
    Node *current = head;
    Node *next = NULL;
    Node *aux3 = NULL;
    if(isEmpty()==false){
        while(current!=NULL){
            aux3 = current;
            next = current->next;
            while(next!=NULL){
                if(current->value==next->value){
                    aux3->next = next->next;
                }else{
                    aux3 = next;
                }
                next = next->next;
            }
            current = current->next;
        }
        cout<<"Elementos repetidos eliminados"<<endl;
    }
}

void LinkedList::reverse(){
    Node *previous = NULL;
    Node *current = head;
    Node *next = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}



void LinkedList::sort(){
    Node *new_head = mergeSort(head);
    Node *aux = new_head;
    cout<<"LISTA ORDENADA: ";
    while(aux){
        cout<<"->"<<aux->value;
        aux = aux->next;
    }
}

Node* LinkedList::mergeSort(Node *head){
    if(head->next == NULL){
        return head;
    }
    Node *mid = getMid(head);
    Node *start_right = mid->next;
    mid->next = NULL;
    Node *left = mergeSort(head);
    Node *right = mergeSort(start_right);
    Node *new_head = merge(left,right);
    return new_head;

}

Node *LinkedList:: merge(Node *left, Node *right){
    Node *aux = new Node();
    Node *current = aux;

    while(left && right){
        if(left->value <= right->value){
            current->next = left;
            left = left->next;
            current = current->next;
        }else if(right->value < left->value){
            current->next = right;
            right = right->next;
            current = current->next;
        }
    }

    while (left != NULL)
    {
        current->next = left;
        left = left->next;
        current = current->next;
    }

    while (right != NULL)
    {
        current->next = right;
        right = right->next;
        current = current->next;
    }

    return aux->next;
}


Node* LinkedList::getMid(Node *head){
    Node *aux1 = head;
    Node *aux2 = head->next;
    while(aux2 && aux2->next){
        aux1 = aux1->next;
        aux2 = aux2->next->next;
    }

    return aux1;
}







