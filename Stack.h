#ifndef STACK_H
#define STACK_H

#include "EStackEmpty.h"

//класс стэк
template <class T> class Stack
{
public:
    void push(const T &value);  //метод, помещающий объект в стек
    const T pop();  //метод, извлекающий объект из стека
    int getSize(); //получение размерности стека
    void clear(); //очистка стека
    ~Stack();//деструктор

private:
    //стуктура, описывающая элемент стека
    struct Node
    {
        const T value_; //хранимое значение элемета стека
        Node* prev = nullptr; //указатель на предыдущий элемент стека
    };

    Node* top = nullptr; //указатель на вершину стека
    int size = 0; //размерность стека
};

template <class T> void Stack<T>::push(const T &value)
{
    Node* new_node = new Node {value, top}; //создаем узел, предыдущий ему узел - нынешняя вершина
    top = new_node; //вершиной теперь является новый узел
    size ++; //увеличиваем размерность
}

template <class T> const T Stack<T>::pop()
{
    //обрабатываем исключение, связанное с извлечением из пустого стэка
    if (top == nullptr){
        throw EStackEmpty();
    }

    const T value = top->value_; //извлекаем значение с вершины
    Node* temp = top;   //создаем временный указатель на вершину
    top = top->prev; //смещаем указатель на вершину
    delete temp; //удаляем старую вершину
    size--; //уменьшаем размерность
    return value;   //возвращаем извлеченное значение
}

template <class T> int Stack<T>::getSize()
{
    return size;
}

template <class T> void Stack<T>::clear()
{

    while (top !=nullptr){  // пока стэк не станет пуст
        Node* temp = top;
        top = top->prev;    //смещаем указатель вершины вниз
        delete temp;    //удаляем старую вершину
    }

}

template <class T> Stack<T>::~Stack<T>()
{
    clear();
};

#endif // STACK_H
