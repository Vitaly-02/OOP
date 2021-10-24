/*
* TO DO:
* конструктор без параметров
* явно использовать указатель this
*/

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class list {
protected:
	list* head;
	list* next;
	int data;

public:
	list(int datA) : data(datA), next(nullptr), head(this) {}

	void set_next(list* ptr) {
		this->next = ptr;
	};

	bool is_empty() {
		return (head == nullptr);
	};

	void print() {
		list* q = head;
		while (q) {
			cout << q->data << " ";
			q = q->next;
		}
		cout << endl;
	};

	int check_sum() {
		int z = 0;
		list* q = head;
		while (q) {
			z += q->data;
			q = q->next;
		}
		return z;
	};

	int run_number(int N) {
		int count = 0;
		list* q = head;
		while (q->next) {
			if (q->data > q->next->data) {
				count += 1;
			}
			q = q->next;
		}
		return count + 1;
	};

	void pop_top() {
		list* q = this->head;
		this->head = q->next;
		q->data = 0;
		q->next = nullptr;
		//delete q;
	}

	void pop_all() {
		list* q = head;
		while (q) {
			q = q->next;
			pop_top();
		}
	}

	int get_size(list* head) {
		int size = 0;
		list* q = head;
		while (q) {
			size++;
			q = q->next;
		}
		return size;
	}

};

class stack : public list {

public:
	stack(int datA) : list(datA) {}
	stack() : list(-1) {}

	void pushtop(int D) {
		stack* q;
		q = new stack(D);
		if (head == nullptr) {
			head = q;
		}
		else {
			q->next = head;
			head = q;
		}
	}

	void fill_inc(int N) {
		for (int i = 1; i <= N; i++) {
			pushtop(i);
		}
	}

	void fill_dec(int N) {
		for (int i = N; i >= 1; i--) {
			pushtop(i);
		}
	}

	void fill_rand(int N) {
		srand(time(NULL));
		for (int i = 1; i <= N; i++)
			pushtop(rand() % 10 + 1);
	};

};

/////////
class queue : public list {
private:
	list* tail;
public:
	queue() : list(-1), tail(this) {}
	queue(int datA) : list(datA), tail(this) {}

	void pushback(int D) {
		queue* q;
		q = new queue(D);
		if (head == nullptr) {
			head = q;
			tail = q;
		}
		else {
			tail->set_next(q);
			tail = q;
		}
	};

	void fill_inc(int N) {
		for (int i = 1; i <= N; i++) {
			pushback(i);
		}
	};

	void fill_dec(int N) {
		for (int i = N; i >= 1; i--) {
			pushback(i);
		}
	};

	void fill_rand(int N) {
		srand(time(NULL));
		for (int i = 1; i <= N; i++)
			pushback(rand() % 10 + 1);
	};

};


int main() {
	queue b(1);
	stack c(1);
	int x;
	int y;
	while (true) {
		x = rand() % 4;
		switch (x) {
		case 0: {
			cout << "\nAdd rand\n";
			b.pushback(rand() % 1000);
			break;
		}
		case 1: {
			if (!b.is_empty()) {
				cout << "\nPop top\n";
				b.pop_top();
			}
			else {
				cout << "\nNothing\n";
			}
			break;
		}
		default: {
			cout << "\nNothing\n";
			break;
		}
		}
		cout << "Queue: ";
		b.print();
		y = rand() % 4;
		switch (y) {
		case 0: {
			cout << "\nAdd rand\n";
			c.pushtop(rand() % 1000);
			break;
		}
		case 1: {
			if (!b.is_empty()) {
				cout << "\nPop top\n";
				c.pop_top();
			}
			else {
				cout << "\nNothing\n";
			}
			break;
		}
		default: {
			cout << "\nNothing\n";
			break;
		}
		}
		cout << "Stack: ";
		c.print();

		system("sleep 1.5");
		system("clear");
	}

	/*
	cout << "queue goes first and stack goes second\n";
	queue a(199);
	a.fill_dec(10);
	a.pop_top();
	a.print();
	stack o(199);
	o.fill_dec(10);
	o.pop_top();
	o.print();
	//system("clear");
	*/
	return 0;
}

