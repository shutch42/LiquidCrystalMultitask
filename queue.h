#include <inttypes.h>

const int MAX_SIZE = 160; //Enough to fill the whole screen using 2 4-bit writes each

struct node {
	uint8_t mode;
	uint8_t value;
	int additional_delay;
};

class Queue {
	public:
		Queue();
		void enqueue(node new_cmd);
		node dequeue();
		int size;
	private:
		node arr[MAX_SIZE];
		int front;
		int back;
};

