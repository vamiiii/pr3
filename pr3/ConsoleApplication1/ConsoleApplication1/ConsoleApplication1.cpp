#include <iostream>

struct Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail= newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head=tail = newNode; 
        }
        else {
            tail->next = newNode; 
            newNode->prev = tail;
            tail = newNode; 
        }
    }

    void pop_front() {
        if (!head) {
            std::cout << "Список пуст.";
            return;
        }
        Node* newNode = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete newNode;
    }

    void pop_back() {
        if (!tail) {
            std::cout << "Список пуст.";
            return;
        }
        Node* newNode = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr; 
        }
        else {
            head = nullptr; 
        }
        delete newNode;
    }

    void display(){
        Node* newNode = head;
        while (newNode)
        {
            std::cout << newNode->data<<" ";
            newNode = newNode->next;
        }
        std::cout << "\n";
        delete (newNode);
    }

    void sort() {
        if (head == nullptr)
        {
            std::cout << "Список пуст\n";
            return;
        }
        else
        {
            bool metka;
            do
            {
                metka = false;
                Node* newNode = head;
                while (newNode->next)
                {
                    if (newNode->data > newNode->next->data)
                    {
                        int a = newNode->data;
                        newNode->data = newNode->next->data;
                        newNode->next->data = a;
                        metka = true;
                    }
                    newNode = newNode->next;
                }
            } while (metka);
        }
    }

    void remove_duplicates() {
        Node* newNode = head;
        if (head == nullptr)
        {
            std::cout << "Список пуст\n";
            return;
        }
        else
        {
            while (newNode)
            {
                Node* remove = newNode->next;
                while (remove)
                {
                    if (newNode->data == remove->data)
                    {
                        Node* temp = remove;
                        remove->prev->next = remove->next;
                        if (remove->next)
                        {
                            remove->next->prev = remove->prev;
                        }
                        else
                        {
                            tail = remove->prev;
                        }
                        remove = remove->next;
                        delete temp;
                    }
                    else
                    {
                        remove = remove->next;
                    }
                }
                newNode = newNode->next;
            }
        }
        delete (newNode);
    }
};



int main()
{
    setlocale(0, "rus");
    DoublyLinkedList r;
    int value;
    int knop;
    do {
        std::cout << "1. Добавить элемент в начало\n";
        std::cout << "2. Добавить элемент в конец\n";
        std::cout << "3. Удалить элемент с начала\n";
        std::cout << "4. Удалить элемент с конца\n";
        std::cout << "5. Отобразить список\n";
        std::cout << "6. Сортировать список\n";
        std::cout << "7. Удалить дубликаты\n";
        std::cout << "8. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> knop;

        switch (knop) {
        case 1:
            std::cout << "Введите значение: ";
            std::cin >> value;
            {
                r.push_front(value);
            }
            break;
        case 2:
            std::cout << "Введите значение: ";
            std::cin >> value;
            {
                r.push_back(value);
            }
            break;
        case 3:
            r.pop_front();
            break;
        case 4:
            r.pop_back();
            break;
        case 5:
            r.display();
            break;
        case 6:
            r.sort();
            break;
        case 7:
            r.remove_duplicates();
            break;
        case 8:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор, попробуйте еще раз.\n";
        }

    } while (knop != 8);
    return 0;
}
