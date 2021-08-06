#define LINKEDLIST_H
#ifdef LINKEDLIST_H
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
    class Node;

public:
    LinkedList<T>() noexcept
    {
        head = nullptr;
    }

    class Iterator;

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    void push_back(T data);

    void erase (int index);

    void print();

    class Iterator
    {
    public:
        Iterator() noexcept : current(head) {}

        Iterator(const Node *pNode) noexcept : current(pNode) {}

        Iterator &operator=(Node *pNode)
        {
            this->current = pNode;
            return *this;
        }

        Iterator &operator++()
        {
            if (current)
                current = current->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator crawler = *this;
            ++*this;
            return crawler;
        }

        bool operator!=(const Iterator &crawler)
        {
            return current != crawler.current;
        }

        int operator*()
        {
            return current->data;
        }

    private:
        const Node *current;
    };

private:
    class Node
    {
        T data;
        Node *next;
        friend class LinkedList;
    };

    Node *GetNode(T data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

    Node *&getHead()
    {
        return head;
    }

    static Node *head;
    int lenght;
};

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::head = nullptr;

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node *aux = GetNode(data);
    if (!getHead())
        getHead() = aux;
    else
    {
        Node *crawler = getHead();
        while (crawler->next)
            crawler = crawler->next;
        crawler->next = aux;
    }
    lenght++;
}

template <typename T>
void LinkedList<T>::erase(int index)
{
    if (index < 1)
    {
        return;
    }
    else if (index == 1 && head != NULL)
    {
        Node *nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
    }
    else
    {
        Node *aux = head;
        for (int i = 1; i < index - 1; i++)
        {
            if (aux != NULL)
            {
                aux = aux->next;
            }
        }

        if (aux != NULL && aux->next != NULL)
        {
            Node *nodeToDelete = aux->next;
            aux->next = aux->next->next;
            free(nodeToDelete);
        }
        else
        {
            return;
        }
    }
}

template <typename T>
void LinkedList<T>::print()
{
    Node *crawler = getHead();

    while (crawler)
    {
        cout << crawler->data << " ";
        crawler = crawler->next;
    }
    cout << endl;
}

#endif
