#include "LinkedList.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LinkedListInt

LinkedListInt::LinkedListInt() : count(0), head(nullptr), tail(nullptr)
{
}

LinkedListInt::LinkedListInt(std::initializer_list<int> init) : LinkedListInt()
{
	for (const auto n : init) {
		push_back(n);
	}
}

LinkedListInt::Node::~Node()
{
	this->next = nullptr;
}

LinkedListInt::~LinkedListInt()
{
	clear();
}

std::size_t LinkedListInt::size() const
{
	return count;
}

bool LinkedListInt::empty() const
{
	return (count == 0);
}

void LinkedListInt::clear()
{
	while (count > 0) {
		pop_front();
	}
}


int& LinkedListInt::front() const
{
	if (this->head == nullptr)
	{
		throw std::out_of_range("В ЛОС нет элементов");
	}
	return head->value;
}

int& LinkedListInt::back() const
{
	if (this->tail == nullptr)
	{
		throw std::out_of_range("В ЛОС нет элементов");
	}
	return tail->value;
}

void LinkedListInt::insert(int pos, int value)
{
	if (pos > this->count) throw std::out_of_range("Позиция превышает размер ЛОС");
	else if (pos < 0) throw std::out_of_range("Позиция меньше 0");
	else if (pos == this->count) this->push_back(value);
	else if (pos == 0) this->push_front(value);
	else
	{
		auto temp = new Node{ value, nullptr };
		auto insertAfter = this->head;
		int iterator = 0;
		while (iterator < pos - 1)
		{
			insertAfter = insertAfter->next;
			iterator++;
		}
		temp->next = insertAfter->next;
		insertAfter->next = temp;
		this->count++;
	}
}


void LinkedListInt::push_back(int value)
{
	if (this->tail == nullptr)
	{
		auto temp = new Node{ value, nullptr };
		this->head = this->tail = temp;
	}
	else 
	{
		auto last = this->tail;
		auto temp = new Node{ value, nullptr };
		last->next = temp;
		this->tail = temp;
	}
	this->count++;
}

void LinkedListInt::push_front(int value)
{
	auto temp = new Node{ value, nullptr };
	if (this->head == nullptr)
	{
		this->head = this->tail = temp;
	}
	else
	{
		temp->next = this->head;
		this->head = temp;
	}
	this->count++;
}

int LinkedListInt::pop_front()
{
	if (this->head == nullptr) throw std::out_of_range("Нельзя удалять из пустого списка");
	const int n = head->value;
	Node* const node = head;
	if (head == tail) { tail = nullptr; }
	head = head->next;
	delete node;
	this->count--;
	return n;
}

int LinkedListInt::pop_back()
{
	if (this->head == nullptr) throw std::out_of_range("Нельзя удалять из пустого списка");
	const int n = tail->value;
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else 
	{
		auto temp = this->tail;
		auto preveous = this->head;
		while (preveous->next != temp)
		{
			preveous = preveous->next;
		}
		preveous->next = nullptr;
		this->tail = preveous;
		delete temp;
	}
	this->count--;
	return n;
}


int LinkedListInt::erase_after(int pos)
{
	if (pos >= this->count) throw std::out_of_range("Нельзя удалить элемент за пределами ЛОС");
	if (pos < 0) throw std::out_of_range("Позиция меньше 0");
	auto itemPrevDel = this->head;
	int i = 0;
	while (i < pos)
	{
		itemPrevDel = itemPrevDel->next;
		i++;
	}
	auto itemToDel = itemPrevDel->next;
	itemPrevDel->next = itemPrevDel->next->next;
	delete itemToDel;
	this->count--;
}

int LinkedListInt::erase(int pos)
{
	if (pos > this->count) throw std::out_of_range("Нельзя удалить элемент за пределами ЛОС");
	if (pos < 0) throw std::out_of_range("Позиция меньше 0");
	else if (pos == 0) pop_front();
	else if (pos == this->count) pop_back();
	else {
		auto itemPrevDel = this->head;
		int i = 0;
		while (i != pos - 1)
		{
			itemPrevDel = itemPrevDel->next;
			i++;
		}
		auto itemNextDel = itemPrevDel->next->next;
		auto itemToDel = itemPrevDel->next;
		itemPrevDel->next = itemNextDel;
		delete itemToDel;
		this->count--;
	}
}

std::string LinkedListInt::to_string(const std::string& splitter) const
{
	std::string result = "";
	auto element = this->head;
	while (element != NULL)
	{
		result += std::to_string(element->value);
		element = element->next;
		if (element) result += splitter;
	}
	return result;
}

std::istream& operator>>(std::istream& stream, LinkedListInt& list)
{
	int n;
	stream >> n;
	list.push_back(n);
	return stream;
}
