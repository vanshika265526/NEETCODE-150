# Linked List
# 1.SINGLY LINKED LIST
DEFINITION:  A singly linked list is a fundamental data structure, it consists of nodes where each node contains a data field and a reference to the next node in the linked list

DEFINING A NODE
```bash
// Definition of a Node in a singly linked list
class Node {
  
public:
    // Data part of the node
    int data;

    // Pointer to the next node in the list
    Node* next;

    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
```
CREATING A NODE AFTER DEFINING
```bash
Node* head = new Node(10);
head->next = new Node(20);
```
PRINTING THE LIST
```bash
Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
```

## COMMON OPERATIONS IN SINGLY LINKED LIST
1. INSERTION
   A. AT FRONT
   ```bash
   Node* insertAtFront(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
    }
   ```
   B. AT END
   ```bash
   Node* insertAtEnd(Node* head, int x) {
  
    // Create a new node
    Node* newNode = new Node(x);

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == nullptr) {
        return newNode;
    }

    // Store the head reference in a temporary variable
    Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next pointer of the last node 
    // to point to the new node
    last->next = newNode;

    // Return the head of the list
    return head;
    }
   ```

   3. AT SPECIFIC POSITION
   ```bash
   Node *insertPos(Node *head, int pos, int val) {

    if (pos < 1)
        return head;

    // head will change if pos=1
    if (pos == 1) {
        Node *newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node *curr = head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    // If position is greater than the 
    // number of nodes
    if (curr == nullptr)
        return head;

    Node *newNode = new Node(val);

    // update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
    }
   ```
