#include <iostream>
#include <sstream>

using namespace std;

template<class Type>
class Queue{
    
    private:
    int front;
    int rear;
    int maxSize;
    Type *queue;
    
    public:

    Queue(int maxSize){
        front = -1;
        rear = -1;
        this->maxSize = maxSize;
        queue = new Type[maxSize];
    }

    ~Queue(){
        delete [] queue;
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return (front == (rear + 1) % maxSize);
    }

    void Insert(Type item){
        if(isFull()){
            cout << "\nQueue Overflow!\n";
            return;
        }else{
            if(front == -1 && rear == -1){
                front++;
                rear++;
                queue[rear] = item;
            }else{
                rear = (rear + 1) % maxSize;
                queue[rear] = item;
            }
        }
    }

    void Remove(Type &item){
        if(isEmpty()){
            cout << "\nQueue Underflow!\n";
            return;
        }else{
            if(front == rear){
                item = queue[front];
                front = -1;
                rear = -1;
            }else{
                item = queue[front];
                front = (front + 1) % maxSize;
            }
        }
    }

};

void Menu() {
	cout << "\n------------- Main Menu ------------\n";
	cout << "\n1.Insert";
	cout << "\n2.Remove";
	cout << "\n3.Remove All Elements using FIFO";
	cout << "\n4.Exit";
	cout << "\n\nEnter your Choice: ";
}

int main() {

	int maxSize;
	string Size;
	bool isValidSize;
	do {
		cout << "\nEnter max Size for the Queue: ";
		getline(cin, Size);
		stringstream(Size) >> maxSize;

		if (maxSize >= 1) {
			isValidSize = true;
		}
		else {
			cout << "\nInvalid Size";
			cout << "\nTry Again\n";
			isValidSize = false;
		}

	} while (!isValidSize);

	Queue<int>* queue = new Queue<int>(maxSize);

	while (true) {
		Menu();
		int choice;
		string Choice;
		getline(cin, Choice);
		stringstream(Choice) >> choice;

		if (choice == 4) {
			cout << "\nGoodBye!\n";
			break;
		}
		else if (choice == 1) {
			int item;
			string ITEM;
			cout << "\nEnter a Number: ";
			getline(cin, ITEM);
			stringstream(ITEM) >> item;
			queue->Insert(item);
		}
		else if (choice == 2) {
			int item;
			queue->Remove(item);
		}
		else if (choice == 3) {
			cout << "\nOutput: " << endl;
			while (!queue->isEmpty()) {
				int item;
				queue->Remove(item);
				cout << item << " ";
			}
		}
		else {
			cout << "\nInvalid Input\n";
			cout << "\nTry Again\n";
		}
	}


	cout << endl;
	return 0;
}
