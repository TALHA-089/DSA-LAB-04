#include "Queue.cpp"

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
			cout << "\nRemoved item: " << item << endl;

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


	cout << endl << endl;
	return 0;
}
