#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        this->key=k;
        this->val=v;
        this->prev=this->next=nullptr;
    }
};

class HashNode{
    public:
    int key;
    Node* node;
    HashNode* next;

    HashNode(int k,Node* temp){
     this->key=k;
     this->node=temp;
     this->next=nullptr;
    }

};

class LRUCache{
    private:
    int capacity;
    int size;

    Node* tail;
    Node* head;

    int Hash_size;
    HashNode** table;

    int hash(int key){
        return key%Hash_size;
    }

    void addTofront(Node* node){
     node->next=head->next;
     node->prev=head;
     head->next->prev=node;
     head->next=node;
    }


    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void moveTofront(Node* node){
        removeNode(node);
        addTofront(node);
    }

    Node* getfromHash(int key){
        int index=hash(key);
        HashNode* curr=table[index];
        while(curr){
            if(curr->key == key) return curr->node;
            
            curr=curr->next;
        }
    return nullptr;
    }

    void putinHash(int key,Node* node){
        int idx=hash(key);
        HashNode* h=new HashNode(key,node);

        h->next=table[idx];
        table[idx]=h;
    }

    void removefromHash(int key){
        int idx=hash(idx);
        HashNode* curr=table[idx];
        HashNode* prev=nullptr;

        while(curr){
            if(curr->key==key) {
                if(prev) prev->next=curr->next;
                else table[idx]->next=curr->next;

                delete curr;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
    }

    public:
     
    LRUCache(int cap){
        this->capacity=cap;
        this->size=0;

        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;

        Hash_size=1007;
        table=new HashNode*[Hash_size];

        for(int i=0;i<Hash_size;i++) table[i]=nullptr;
    }

    int get(int key){
        Node* node=getfromHash(key);

        if(!node) return -1;

        moveTofront(node);
        return node->val;
    }

    void put(int key,int val){
        Node* node=getfromHash(key);

        if(node){
            node->val=val;
            moveTofront(node);
        }else{
            if(size==capacity){
                Node* temp=tail->prev;
                removeNode(temp);
                removefromHash(temp->key);

                delete temp;
                size--;
            }

            Node* newnode=new Node(key,val);
            addTofront(newnode);
            putinHash(key,newnode);
            size++;
        }
    }

    void display(){
        Node* curr=head->next;
        while(curr!=tail){
            cout << "(" << curr->key << "," << curr->val << ") ";
            curr = curr->next;
        }
        cout<<endl;
    }

};

