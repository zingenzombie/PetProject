//
// Created by Chase Hap on 6/3/22.
//

#ifndef PETPROJECT_LINKEDLIST_H
#define PETPROJECT_LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
public:
    class Node;

    LinkedList(){
        head = nullptr;
        tail = nullptr;

        numNodes = 0;
    }

    LinkedList(const LinkedList<T>& List){
        T tmp = List.head->data;
        this->AddHead(tmp);
        Node* tmpOld = List.head;
        for(unsigned int i = 0; i < List.NodeCount(); i++){
            tmpOld = tmpOld->Next();
            if(tmpOld != nullptr) {
                tmp = tmpOld->data;
                this->AddTail(tmp);
            }
        }
        delete tmpOld;
    }

    void Clear(){
        Node* start = head;
        Node* tmp;
        for(unsigned int i = 0; i < numNodes; i++){
            tmp = start->Next();
            delete start;
            start = tmp;
        }
        this->head = nullptr;
        this->tail = nullptr;
        numNodes = 0;
    }

    LinkedList<T>& operator=(const LinkedList<T>& rhs){
        Clear();
        LinkedList<T>* tmp = new LinkedList(rhs);
        for(unsigned int i = 0; i < rhs.NodeCount(); i++)
            this->AddTail(tmp->GetNode(i)->data);
        delete tmp;
        return *this;
    }

    T& operator[](unsigned int index){
        return this->GetNode(index)->data;
    }

    unsigned int NodeCount() const {
        return numNodes;
    }

    void AddHead(const T& data) {
        Node* tmp = head;
        head = new Node(nullptr, tmp, data);
        if (tail == nullptr)
            tail = head;
        if(tmp != nullptr)
            tmp->UpdateBefore(head);
        numNodes++;
    }

    void AddTail(const T& data) {
        Node* tmp = tail;
        tail = new Node(tmp, nullptr, data);
        if (head == nullptr)
            head = tail;
        if(tmp != nullptr)
            tmp->UpdateAfter(tail);
        numNodes++;
    }

    void PrintForward() {
        Node* tmp = head;
        while(true){
            if(tmp != nullptr){
                cout << tmp->data << endl;
                tmp = tmp->Next();
            }
            else
                break;
        }
    }

    void PrintReverse() {
        Node* tmp = tail;
        while(true){
            if(tmp != nullptr){
                cout << tmp->data << endl;
                tmp = tmp->Prev();
            }
            else
                break;
        }
    }

    const Node* GetNode(unsigned int index) const {
        if(index > numNodes - 1)
            throw out_of_range("oof");
        Node* tmp = tail;
        for(int i = 0; i < index; i++)
            tmp = tmp->Prev();
        return tmp;
    }

    Node* GetNode(unsigned int index) {
        if(index > numNodes - 1)
            throw out_of_range("oof");
        Node* tmp = head;
        for(unsigned int i = 0; i < index; i++)
            tmp = tmp->Next();
        return tmp;
    }

    void PrintForwardRecursive(Node* start) {
        if (start != nullptr) {
            cout << start->data << endl;
            PrintForwardRecursive(start->Next());
        }
    }

    void PrintReverseRecursive(Node* start) {
        if (start != nullptr) {
            cout << start->data << endl;
            PrintReverseRecursive(start->Prev());
        }
    }

    const Node* Find(const T& data) const {
        Node* tmp = head;
        for(int i = 0; i < numNodes; i++){
            if(data == tmp->data)
                return tmp;
            else
                tmp = tmp->Next();
        }
        return nullptr;
    }

    Node* Find(const T& data) {
        Node* tmp = head;
        for(unsigned int i = 0; i < numNodes; i++){
            if(data == tmp->data)
                return tmp;
            else
                tmp = tmp->Next();
        }
        return nullptr;
    }

    void FindAll(vector<Node*>& outData, const T& value) const {
        Node* tmp = head;
        for(unsigned int i = 0; i < numNodes; i++) {
            if(tmp->data == value)
                outData.push_back(tmp);
            //if(i + 1 < numNodes)
                tmp = tmp->Next();
        }
    }

    void AddNodesHead(const T* data, unsigned int count) {
        for(unsigned int i = 0; i < count; i++)
            AddHead(data[count - i - 1]);
    }

    void AddNodesTail(const T* data, unsigned int count) {
        for(unsigned int i = 0; i < count; i++)
            AddTail(data[i]);
    }

    Node* copy(const Node* old){
        Node* tmp = new Node(nullptr, nullptr, old->data);
        return tmp;
    }

    void InsertBefore(Node* node, const T& data){
        Node* tmpB = new Node(node->Prev(), node, data);
        if(node->Prev() == nullptr)
            head = tmpB;
        else {
            node->Prev()->UpdateAfter(tmpB);
            //node->UpdateBefore(tmpB);
        }
        node->UpdateBefore(tmpB);
        numNodes++;
    }

    void InsertAfter(Node* node, const T& data) {
        Node *tmpA = new Node(node, node->Next(), data);
        if (node->Next() == nullptr)
            tail = tmpA;
        else {
            node->Next()->UpdateBefore(tmpA);
            node->UpdateAfter(tmpA);
        }
        numNodes++;
    }

    void InsertAt(const T& data, unsigned int index){
        if(index < numNodes - 1)
            InsertBefore(GetNode(index), data);
        else
            AddTail(data);
    }

    const Node* Head() const{
        return head;
    }

    Node* Head(){
        return head;
    }

    const Node* Tail() const{
        return tail;
    }

    Node* Tail(){
        return tail;
    }

    bool operator==(const LinkedList<T>& rhs){
        if(this->numNodes != rhs.numNodes)
            return false;
        LinkedList<T> a = LinkedList(*this);
        LinkedList<T> b = LinkedList(rhs);
        Node* aNode = a.head;
        Node* bNode = b.head;
        for(unsigned int i = 0; i < numNodes; i++){
            if(aNode->data != bNode->data)
                return false;
            aNode = aNode->Next();
            bNode = bNode->Next();
        }
        return true;
    }

    bool RemoveHead(){
        if(head == nullptr)
            return false;
        Node* tmp = head->Next();
        if(head == tail)
            tail = nullptr;
        delete head;
        head = tmp;
        if(head != nullptr)
            head->UpdateBefore(nullptr);
        numNodes--;
        return true;
    }

    bool RemoveTail(){
        if(tail == nullptr)
            return false;
        Node* tmp = tail->Prev();
        if(head == tail)
            head = nullptr;
        delete tail;
        tail = tmp;
        if(tail != nullptr)
            tail->UpdateAfter(nullptr);
        numNodes--;
        return true;
    }

    unsigned int Remove(const T& data){
        unsigned int tmp = 0;
        for(unsigned int i = 0; i < numNodes; i++){
            Node* tmpNode = GetNode(i);
            if(tmpNode->data == data) {
                RemoveAt(i);
                tmp++;
            }
        }
        return tmp;
    }

    bool RemoveAt(unsigned int index){
        if(index > numNodes - 1)
            return false;
        else if(index == 0)
            RemoveHead();
        else if(index == numNodes - 1)
            RemoveTail();
        else{
            Node* tmp = GetNode(index);
            Node* before = tmp->Prev();
            Node* after = tmp->Next();
            before->UpdateAfter(after);
            after->UpdateBefore(before);
            delete tmp;
        }
        numNodes--;
        return true;
    }



    class Node {
    public:
        Node() {
            cout << "Caution a node has been generated with a blank constructor!!!" << endl;
        }

        Node(Node *before, Node *after, T data) {
            this->data = data;
            this->prev = before;
            this->next = after;
        }

        Node *Prev() {
            return prev;
        }

        Node *Next() {
                return next;
        }

        void UpdateBefore(Node* before) {
            this->prev = before;
        }

        void UpdateAfter(Node* after) {
            this->next = after;
        }

        T data;
        Node* prev;
        Node* next;
    private:
    };

    ~LinkedList() {
        Node* tmpA = tail;
        for(unsigned int i = 0; i < numNodes; i++){
            Node* tmpB = tmpA->Prev();
            delete tmpA;
            tmpA = tmpB;
        }
    }

private:

    Node* head = nullptr;
    Node* tail = nullptr;
    unsigned int numNodes = 0;

public:
};


#endif //PROJECT01_LINKEDLIST_H
