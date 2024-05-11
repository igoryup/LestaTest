# В целом все аналогично CPP варианту

SIZE = 100

# Очередь на основе массива
class QueueArray:
    def __init__(self, size=SIZE):
        self.data = [0] * size
        self.front = 0
        self.back = 0
        self.capacity = size
        self.size = 0

    def pop(self):
        if self.is_empty():
            raise Exception()
        result = self.data[self.front]
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return result

    def push(self, item):
        if self.is_full():
            raise Exception()
        self.data[self.back] = item
        self.back = (self.back + 1) % self.capacity
        self.size += 1

    def front(self):
        if self.is_empty():
            raise Exception()
        return self.data[self.front]

    def back(self):
        if self.is_empty():
            raise Exception()
        pos = self.capacity - 1 if self.back == 0 else self.back - 1
        return self.data[pos]

    def size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity


# Очередь на основе связного списка
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class QueueLinkedList:
    def __init__(self, size=SIZE):
        self.capacity = size
        self.size = 0
        self.front = None
        self.back = None

    def pop(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        result = self.front.data
        if self.size == 1:
            del self.front
            self.front = None
            self.back = None
        else:
            buf = self.front
            self.front = self.front.next
            del buf
        self.size -= 1
        return result

    def push(self, item):
        if self.is_full():
            raise Exception("Queue is full")
        new_node = Node(item)
        if self.is_empty():
            self.back = new_node
            self.front = new_node
        else:
            self.back.next = new_node
            self.back = new_node
        self.size += 1

    def front(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.front.data

    def back(self):
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.back.data

    def size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

