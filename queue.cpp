#include "queue.h"

Queue::Queue() {
	front = 0;
	back = 0;
	size = 0;
}

void Queue::enqueue(node new_cmd) {
	if(size != MAX_SIZE) {
		arr[back] = new_cmd;
		back = (back + 1) % MAX_SIZE;
		size += 1;
	}
}

node Queue::dequeue() {
	node front_val = arr[front];
	front = (front + 1) % MAX_SIZE;
	size -= 1;
	return front_val;
}
