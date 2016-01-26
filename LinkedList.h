using namespace std;

template<class T>
struct node{
    node *next; // pointer to next node
    T *value; // pointer to element
};

// -----------------------------------

template<class T>
class list{
public:
    node<T> *head; // pointer to first element
    int size; // size of list
    
    list(){  // constructor
        size = 0;
        head = new node<T>();
    }
    
    bool checkIndex(int index);
    void addAtIndex(T* obj, int index);
    void removeAtIndex(int index);
    void printList();
};

template<class T>
bool list<T>::checkIndex(int index){
    if(index > size)
        return true;
    else
        return false;
};

/* special cases:
 insert at beginning
 insert at end
 if empty
 if index > size
 */
template<class T>
void list<T>::addAtIndex(T* obj, int index){
    if(checkIndex(index)) return; // check if index is valid
    node<T> *insertNode = new node<T>(); // create node to insert
    if(index == 0 && size == 0){ // if empty
        head->next = insertNode;
        head->next->value = obj;
        size++;
        return;
    }
    else if(index == 0){ // insert at beginning
        insertNode->value = obj;
        insertNode->next = head->next;
        head->next = insertNode;
        size++;
        return;
    }
    else if(index == size){ // insert at end
        node<T> *temp = head->next;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = insertNode;
        temp->next->value = obj;
        size++;
        return;
    }
    // else: normal case
    int indexCount = 0;
    node<T> *temp = head->next;
    while(indexCount < index-1){
        temp = temp->next;
        indexCount++;
    }
    insertNode->value = obj;
    insertNode->next = temp->next;
    temp->next = insertNode;
    size++;
}

/* specail cases:
 delete the only element
 delete the first element
 delete the last element
 */
template<class T>
void list<T>::removeAtIndex(int index){
    if(checkIndex(index)) return; // check if index is valid
    node<T> *deleteNode = head->next;
    if(index == 0 && size == 1){ // delete the only element in list
        delete deleteNode;
    }
    else if(index == 0){ // delete the first element
        head->next = head->next->next;
        delete deleteNode;
    }
    else if(index == size-1){ // delete last element
        while (deleteNode->next != NULL) {
            deleteNode = deleteNode->next;
        }
        delete deleteNode;
    }
    // else: normal case
    int indexCount = 0;
    while (indexCount < index-1) {
        deleteNode = deleteNode->next;
        indexCount++;
    }
    node<T>* beforeNode = deleteNode;
    deleteNode = deleteNode->next;
    beforeNode->next = beforeNode->next->next;
    delete deleteNode;
}

template<class T>
void list<T>::printList()
{
    node<T>* temp = head->next;
    while(temp != NULL){
        cout<<(*(temp->value))<<" ";
        temp = temp->next;
    }
}
