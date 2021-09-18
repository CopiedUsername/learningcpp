#include <iostream>
#include <string>

using namespace std;

struct node {
    string value;
    node *next;


};

class LinkedList{
public:
    node *head, *tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void add(string s){
        node *newNode = new node;
        newNode->value = s;
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
};

int main() {
    LinkedList linkedList = *new LinkedList();
    linkedList.add("FIRST");
    linkedList.add("SECOND");
    linkedList.add("THIRD");
    linkedList.add("FOURTH");
    cout << "First value is " << linkedList.head->value << endl;
    cout << "Second value is " << linkedList.head->next->value << endl;
    cout << "Last value is " << linkedList.tail->value << endl;
}
