template<typename T>
struct Node {
    T value = T();
    Node* previous = nullptr;
    Node* next = nullptr;
};

template<typename T>
class DoubleLinkedList {
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        
	Node<T>* front();
	Node<T>* back();

        void push_back(T value);
        void pop_back();
    private:
        Node<T>* root;
	void insert(T value, Node<T>* previous, Node<T>* next);
};
