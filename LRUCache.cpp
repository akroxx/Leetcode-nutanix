class LRUCache {
public:

    //Create a Node for DLL and implement functions :
    //1. AddToHead
    //2. RemoveNode
    //3. MoveToHead = removeNode() -> AddToHead()
    //4. PopTail

    //Create HashMap<Key, Node>

    class Node{
        public:
            int key;
            int val;
            Node *prev;
            Node *next;
            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    int size;
    int capacity;
    Node *head;
    Node *tail;

    void addNode(Node *toAdd){
        toAdd->prev = head;
        toAdd->next = head->next;

        head->next->prev = toAdd;
        head->next = toAdd;
    }

    void removeNode(Node *toRemove){
        Node *prev = toRemove->prev;
        Node *next = toRemove->next;

        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node *toMove){
        removeNode(toMove);

        addNode(toMove);
    }

    Node* popTail(){
        Node *res = tail->prev;
        removeNode(res);

        return res;
    }

    unordered_map<int, Node*> map;      // <key, node>
    
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        Node *node = map[key];

        if(node == nullptr){
            return -1;
        }
        moveToHead(node);
        return node->val;
        
    }
    
    void put(int key, int value) {

        Node *node = map[key];

        if(node == nullptr){
            Node *adder = new Node(key, value);
            addNode(adder);
            map.insert({key, adder});
            ++size;

            if(size > capacity){
                //tail is least recently used
                Node *remove = popTail();
                map.erase(remove->key);
                --size;
            }
        }else{
            node->val = value;
            moveToHead(node);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */