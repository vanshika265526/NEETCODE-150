class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addfront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        remove(node);
        addfront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return; 

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            remove(node);
            addfront(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            addfront(newNode);
            mp[key] = newNode;
        }
    }
};
