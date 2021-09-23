#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct node {
	node* next;
	int data;

	node(int datA) : data(datA), next(nullptr) {}
};


class list {
protected:
	list* head;
	//list* tail;
	list* next;
	int data;

public:
	list(int datA) : data(datA), next(nullptr), head(this) {}

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
		list* q = head;
		head = q->next;
		q->data = NULL;
		q->next = nullptr;
		delete q;
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
	queue() : list(-1), tail(nullptr) {}
	queue(int datA) : list(datA), tail(nullptr) {}

	void pushback(int D) {
		queue* q;
		//queue q;
		q = new queue(D);
		if (head == nullptr) {
			head = q;
			tail = q;
		}
		else {
			//todo tail->next = q;
			tail->next = q;
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
    std::cout << "Hello World!\n";
	queue a(199);
	a.fill_dec(10);
	a.print();
	cout << sizeof(a) << endl;
	stack o(199);
	o.fill_dec(10);
	o.print();
	cout << endl << sizeof(o);
	
}
