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
### INSERTION
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

  C. AT SPECIFIC POSITION
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

### DELETION
 A. FROM FRONT
   ```bash
    Node* deleteHead(Node* head) {
  
    // Check if the list is empty
    if (head == nullptr)
        return nullptr;

    // Store the current head in a
    // temporary variable
    Node* temp = head;

    // Move the head pointer to the next node
    head = head->next;

    // Free the memory of the old head node
    delete temp;

    return head;
    }
 ```

 B. FROM END
   ```bash
    Node* removeLastNode(Node* head) {
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }

    // If the list has only one node, delete it and return nullptr
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second last node
    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    // Delete the last node
    delete secondLast->next;

    // Change next of second last
    secondLast->next = nullptr;

    return head;
    }
 ```

C. FROM SPECIFIC POSITION
 ```bash
  Node* deleteNode(Node* head, int position) {
    Node* temp = head;

    // Head is to be deleted
    if (position == 1) {
        head = temp->next;
        delete temp;
        return head;
    }

    // Traverse to the node 
    // before the one to be deleted
    Node* prev = nullptr;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the node at the position
    prev->next = temp->next;
    delete temp;

    return head;
   }
 ```

### SEARCHING
```bash
  bool searchKey(Node* head, int key) {

    // initialize curr with the head of linked list
    Node* curr = head;

    // iterate over all the nodes
    while (curr != NULL) {
        // If the current node's value is equal to key,
        // return true
        if (curr->data == key)
            return true;

        // move to the next node
        curr = curr->next;
    }

    // if there is no node with value as key, return false
    return false;
  }
```

### REVERSAL
 ```bash
 Node *reverseList(Node *head) {

    Node *curr = head, *prev = nullptr, *next;

    // Traverse all the nodes of Linked List
    while (curr != nullptr) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
  }
 ```

# 2.DOUBLY LINKED LIST
The main advantage of a doubly linked list is that it allows for efficient traversal of the list in both directions. This is because each node in the list contains a pointer to the previous node and a pointer to the next node. This allows for quick and easy insertion and deletion of nodes from the list, as well as efficient traversal of the list in both directions.

DEFINING A DOUBLY LIST:
```bash
class Node {
public:
    // To store the Value or data
    int data;

    // Pointer to point the Previous Element
    Node* prev;

    // Pointer to point the Next Element
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};
```

## 1.INSERTION
  ### A. FROM FRONT
  ```bash
  Node* insertAtFront(Node* head, int new_data) {
​
    // Create a new node
    Node* new_node = new Node(new_data);
​
    // Make next of new node as head
    new_node->next = head;
​
    // Change prev of head node to new node
    if (head != nullptr)
        head->prev = new_node;
​
    // Return the new node as the head of the doubly linked list
    return new_node;
  }
```

 ### B. FROM END
 ```bash
 Node *insertEnd(Node *head, int new_data)
  {

    // Create a new node
    Node *new_node = new Node(new_data);

    // If the linked list is empty, set the new
    // node as the head of linked list
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        // Set the next of last node to new node
        curr->next = new_node;

        // Set prev of new node to last node
        new_node->prev = curr;
    }

    // Return the head of the doubly linked list
    return head;
  }
```

 ### C. AT SPECIFIC POSITION
 ```bash
  Node* insertAtPos(Node* head, int pos, int new_data) {

    // Create a new node
    Node* new_node = new Node(new_data);

    // Insertion at the beginning
    if (pos == 1) {
        new_node->next = head;

        // If the linked list is not empty, 
        // set the prev of head to new node
        if (head != NULL)
            head->prev = new_node;

        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }

    Node* curr = head;
    // Traverse the list to find the node before the
    // insertion point
    for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
        curr = curr->next;
    }

    // If the position is out of bounds
    if (curr == NULL) {
        delete new_node;
        return head;
    }

    // Set the prev of new node to curr
    new_node->prev = curr;

    // Set the next of new node to next of curr
    new_node->next = curr->next;

    // Update the next of current node to new node
    curr->next = new_node;

    // If the new node is not the last node, 
    // update prev of next node to new node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    // Return the head of the doubly linked list
    return head;
  }
  ```
 ## 2. DELETION
 
  ### A. FROM FRONT
  ```bash
  Node *delHead(Node *head) {

    // If empty, return
    if (head == nullptr)
        return nullptr;

    // Store in temp for deletion later
    Node *temp = head;

    // Move head to the next node
    head = head->next;

    // Set prev of the new head
    if (head != nullptr)
        head->prev = nullptr;

    // Free memory and return new head
    delete temp;
    return head;
  }
 ```

 ### B.FROM END
 ```bash
  Node *delLast(Node *head) {

    // Corner cases
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    // Traverse to the last node
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    // Update the previous node's next pointer
    curr->prev->next = NULL;

      // Delete the last node
    delete curr; 

    // Return the updated head
    return head;
  }
 ```

### C.FROM SPECIFIC
```bash
 Node* delPos(Node* head, int x) {
    
    if (head == NULL)
        return head; 

    Node* curr = head;

    // traverse to the node at the given position
    for (int i = 1; curr != NULL && i < x; ++i) {
        curr = curr->next;
    }
    
    // position exceeds list length, no deletion
    if (curr == NULL)
        return head; 

    // if the node to delete is not the first node
    // update previous node's next
    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    // if the node to delete is not the last node
    // update next node's prev
    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    // if deleting the head, move head pointer to next node
    if (head == curr)
        head = curr->next;
        
    delete curr; 
    return head;
 }
```


## CIRCULAR LINKED LIST

A circular linked list is a data structure where the last node points back to the first node, forming a closed loop.
TYPES:
1.CIRCULAR SINGLY LINKED LIST: In Circular Singly Linked List, each node has just one pointer called the "next" pointer. The next pointer of the last node points back to the first node and this results in forming a circle. In this type of Linked list, we can only move through the list in one direction.
2.CIRCULAR DOUBLY LINKED LIST: In circular doubly linked list, each node has two pointers prev and next, similar to doubly linked list. The prev pointer points to the previous node and the next points to the next node. Here, in addition to the last node storing the address of the first node, the first node will also store the address of the last node.

DEFINING A NODE:
  ```bash
  class Node {
  public:
      int data;
      Node* next;
  
      // Constructor
      Node(int value) {
          data = value;
          next = nullptr;
      }
  };
 ```
 
