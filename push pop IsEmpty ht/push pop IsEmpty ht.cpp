#include <iostream>
using namespace std;

class Stack
{
private:
    int* data;
    int size;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        data = new int[size];
        top = -1;
    }

    ~Stack() 
    {
        if (data != nullptr)
        delete[] data;
    }

    void Push(int value)
    {
        if (top < size - 1) 
        {
            data[top++] = value;
        }
    }

    int Pop()
    {
        if (top >= 0)
        {
            return data[top--];
        }
        throw "Stack is empty!";
    }

    int Peek() 
    {
        if (top >= 0) 
        {
            return data[top];
        }
        throw "Stack is empty!";
    }

    bool Contains(int value)
    {
        for (int i = 0; i <= top; i++) 
        {
            if (data[i] == value) 
            {
                return true;
            }
        }
        return false;
    }

    void Print()
    {
        for (int i = 0; i <= top; i++) 
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == size - 1;
    }
};

int main() {
    Stack s(5);

    s.Push(10);
    s.Push(20);
    s.Push(30);

    s.Print();

    s.Pop();

    s.Print(); 


    if (s.IsEmpty()) {
        cout << "Stack is empty \n";
    }
    else {
        cout << "Stack is not empty \n";
    }

    if (s.IsFull()) {
        cout << "Stack is full \n";
    }
    else {
        cout << "Stack is not full \n";
    }

    cout << "Peek: " << s.Peek();

    return 0;
}