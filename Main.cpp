#include<iostream>
#include<sstream>
using namespace std;

template<class Type>
class Queue {
private:
	int maxSize;
	int front;
	int rear;
	Type* queue;

public:

	Queue(int maxSize) {
		front = -1;
		rear = -1;
		this->maxSize = maxSize;
		queue = new Type[maxSize];
	}

	~Queue() {
		delete[] queue;
	}

	bool isFull() {
		return (rear == maxSize - 1);
	}

	bool isEmpty() {
		return (front == -1 && rear == -1);
	}

	void insert(Type item) {
		if (isFull()) {
			cout << "\nQueue Overflow!\n";
			return;
		}
		else {
			if (front == -1 && rear == -1) {
				front++;
				rear++;
				queue[rear] = item;
				cout << "\n" << item << " inserted Successfully\n";
			}
			else {
				rear++;
				queue[rear] = item;
				cout << "\n" << item << " inserted Successfully\n";
			}
		}
	}

	void remove(Type& item) {
		if (isEmpty()) {
			cout << "\nQueue Underflow!\n";
			return;
		}
		else {
			if (front == 0 && rear == 0) {
				item = queue[front];
				front--;
				rear--;
				cout << "\n" << item << " removed Successfully\n";
			}
			else {
				item = queue[front];
				for (int i = 0; i < rear; i++) {
					queue[i] = queue[i + 1];
				}
				rear--;
				cout << "\n" << item << " removed Successfully\n";
			}
		}
	}
};

void Menu() {
	cout << "\n------------- Main Menu ------------\n";
	cout << "\n1.Insert";
	cout << "\n2.Remove";
	cout << "\n3.Get All Elements using FIFO";
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
			queue->insert(item);
		}
		else if (choice == 2) {
			int item;
			queue->remove(item);
		}
		else if (choice == 3) {
			while (!queue->isEmpty()) {
				int item;
				queue->remove(item);
			}
		}
		else {
			cout << "\nInvalid Input\n";
			cout << "\nTry Again\n";
		}
	}


	cout << endl;
	system("Pause");
	return 0;
}
