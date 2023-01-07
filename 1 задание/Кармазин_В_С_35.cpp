// 35 вариант. Указатели, очередь с 1 головой, быстрая сортировка Хоару (с медианным (pivot) элементом)

#include <iostream>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;


struct element { //1+1+1
    int value;
    int index;
    element* next;
};

class QueueWithOneHead {
public:
    element* head;
    unsigned long int nop;

    QueueWithOneHead() { //+2
        head = 0;
        nop = 0;
    }

    ~QueueWithOneHead() {

    };

    void enQueue(int n) { // 2+3+1+4+(n-2)(1+2n+4)
        nop += 2;
        if (head == 0) {
            head = new element;
            head->value = n;
            head->next = 0;
            nop += 3;
        }
        else if (head->next == 0) {
            element* tmpElement = new element;
            tmpElement->value = n;
            tmpElement->next = 0;
            head->next = tmpElement;
            nop += 4;
        }
        else {
            element* currentElement = head->next;
            nop += 1;
            while (currentElement->next != 0) {
                currentElement = currentElement->next;
                nop += 2;
            }
            element* tmpElement = new element;
            tmpElement->value = n;
            tmpElement->next = 0;
            currentElement->next = tmpElement;
            nop += 4;
        }
        nop += 1;
    }

    void showQueue() { //2+3n
        element* currentElement = head;
        nop += 1;
        while (currentElement != 0) {
            cout << currentElement->value << " ";
            currentElement = currentElement->next;
            nop += 3;
        }
        cout << endl;
        nop += 1;
    }

    void indexing() { // 2+4n
        element* currentElement = head;
        int i = 0;
        nop += 2;
        while (currentElement != 0) {
            currentElement->index = i;
            currentElement = currentElement->next;
            i++;
            nop += 4;
        }
    }

    void swapElements(int first_ind, int second_ind) { //4+n(3+1+n(3+5))
        nop += 2;
        element* currentElement = head;
        nop += 1;
        while (currentElement != 0) {
            nop += 3;
            if (currentElement->index == first_ind) {
                element* tmpElement = currentElement;
                nop += 1;
                while (currentElement != 0) {
                    nop += 3;
                    if (currentElement->index == second_ind) {
                        int tmp = 0;
                        tmp = tmpElement->value;
                        tmpElement->value = currentElement->value;
                        currentElement->value = tmp;
                        nop += 5;
                        return;
                    }
                    currentElement = currentElement->next;
                }
            }
            currentElement = currentElement->next;
        }
        cout << "Элементов с такими индексами не существует";
        nop += 1;
    }

    int findElement(int ind) { //2+4n
        nop += 1;
        element* currentElement = head;
        nop += 1;
        while (currentElement != 0) {
            nop += 3;
            if (currentElement->index == ind) {
                nop += 1;
                return currentElement->value;
            }
            currentElement = currentElement->next;
        }
    }
};

class QuickSort { //n*(log(n))
public:
    unsigned int long nop;
    void hoarasort(QueueWithOneHead* Q, int first, int last) { 
        nop += 5;
        int i = first, j = last;
        int temp = 0;
        nop += 3;
        int pivot = Q->findElement((first + last) / 2);
        nop += 3;

        while (i <= j) {
            nop += 1;
            while (Q->findElement(i) < pivot) {
                i++;
                nop += 2;
            }
            while (Q->findElement(j) > pivot) {
                j--;
                nop += 2;
            }
            if (i <= j) {
                nop += 1;
                if (i < j) {
                    Q->swapElements(i, j);
                    nop += 3;
                }
                i++;
                j--;
                nop += 2;
            }
        }
        if (i < last) {
            nop += 1;
            hoarasort(Q, i, last); 
        }
        if (first < j) {
            nop += 1;
            hoarasort(Q, first, j); 
        }
    }   
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    QuickSort* Sort = new QuickSort;
    int first = 0;
    int last;
    Sort->nop = 0;
    for (int a = 300; a <= 3000; a += 300) {
        QueueWithOneHead* Queue = new QueueWithOneHead;
        Queue->nop = 0;
        for (int b = 0; b <= a; b++) {
            Queue->enQueue(a - b);
        }
        unsigned int start_time = 0;
        unsigned int end_time = 0;
        unsigned int final_time = 0;
        int last = a;
        Queue->indexing();
        cout << "n = " << a << endl;
        start_time = clock();
        Sort->hoarasort(Queue, first, last);
        end_time = clock();
        final_time = end_time - start_time;
        cout << "Время выполнения программы (mc): " << final_time << endl;
        cout << "NOP: " << Queue->nop+Sort->nop;
        cout << endl << endl;
        Queue->nop = 0;
        Sort->nop = 0;
    }

    return 0;
}
