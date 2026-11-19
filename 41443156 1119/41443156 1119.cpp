#include <iostream>
#include <stdexcept>
using namespace std;
template<class T>
class Chain;
template<class T>
class ChainNode {
	friend class Chain<T>;
public:
	ChainNode() {

	}
	ChainNode(const T& data) {
		this->data = data;
	}
	ChainNode(const T& data, ChainNode<T>* link) {
		this->data = data;
		this->link = link;
	}
private:
	T data;
	ChainNode<T>* link;
};
template<class T>
class Chain {
public:
	~Chain();
		Chain(int stackCapacity = 10) {
			header = new ChainNode<T>();
			header->link = header;
		}
		void Push(const T& item) {
			ChainNode <T>* newNode = new ChainNode<T>(item, header->link);
			header->link = newNode;
		}
		void Pop() {
			if (IsEmpty()) {
				cout << "Stack is empty" << endl;
				return;
			}
			ChainNode <T>* deleteNode =header->link ;
			header->link = deleteNode->link;
			delete deleteNode;

		}
		T& Top() {
			if (IsEmpty()) {
				throw runtime_error("Stack is empty");
			}
			return header->link->data;
		}
		bool IsEmpty() {
			return header->link == header;
		}
		void Display() {
			if (IsEmpty()) {
				cout << "List is empty." << endl;
				return;
			}
			ChainNode<T>* current=header->link;
			while (current != header) {
				cout << current->data << (current->link ? "->" : "");
				current = current->link;
			}
			cout << "NULL"<<endl;
		}
private:
	ChainNode<T>* header;
};
template<class T>
Chain<T>::~Chain(){
	while (!IsEmpty()) {
		Pop();
	}
	delete header;
}
int main() {
	Chain<int> myList;
	int n,a;
	n = -1;
	while (n != 0) {
		cout << "====Stack Menu====" << endl;
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3.Top" << endl;
		cout << "4.IsEmpty" << endl;
		cout << "5.Display" << endl;
		cout << "0.Exit" << endl;
		cout << "Choice:";
		cin >> n;
		if (n == 1) {
			cout << "Enter value:";
			cin >> a;
			myList.Push(a);
		}
		else if (n == 2) {
			myList.Pop();
		}
		else if (n == 3) {
			cout << "Top:" << myList.Top();
		}
		else if (n == 4) {
			cout << (myList.IsEmpty() ? "Stack is empty" : "Stack is not empty");
		}
		else if (n == 5) {
			myList.Display();
		}
		else if (n == 0) {
			break;
		}
		cout << endl;
	}
	return 0;
}