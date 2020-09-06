
#include <exception>
#include <iostream>

struct node
{
	int value;
	node* next;
};

struct stack
{
	node* first;
};

void push_back(stack* m_stack, int value);
void pop_back(stack* m_stack);
int top(stack* m_stack);
int min(stack* m_stack);
void remove_odd(stack* m_stack);
void init(stack* m_stack);
void deinit(stack* m_stack);

int main()
{
	stack a;

	init(&a);

	push_back(&a, 13);
	push_back(&a, 4);
	push_back(&a, -43);
	push_back(&a, 12);

	pop_back(&a);

	std::cout << min(&a) << std::endl;

	remove_odd(&a);

	std::cout << min(&a) << std::endl;
	deinit(&a);

	return 0;
}

void push_back(stack* m_stack, int value)
{
	if (m_stack == nullptr)
		throw std::exception{};
	if (m_stack->first == nullptr)
	{
		m_stack->first = new node;
		m_stack->first->next = nullptr;
		m_stack->first->value = value;
		return;
	}

	node* ptr = m_stack->first;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	ptr->next = new node;
	ptr->next->next = nullptr;
	ptr->next->value = value;
}

void pop_back(stack* m_stack)
{
	if (m_stack == nullptr)
		throw std::exception{};
	if (m_stack->first == nullptr)
		return;
	if (m_stack->first->next == nullptr)
	{
		delete m_stack->first;
		m_stack->first = nullptr;
		return;
	}
	node* ptr;
	ptr = m_stack->first;
	while (ptr->next->next != nullptr)
	{
		ptr = ptr->next;

	}
	delete ptr->next;
	ptr->next = nullptr;
}

int top(stack* m_stack)
{
	if (m_stack == nullptr)
		throw std::exception{};
	if (m_stack->first == nullptr)
		throw std::exception{};
	node* ptr = m_stack->first;
	while (ptr->next != nullptr)
	{
		ptr = ptr->next;
	}
	return ptr->value;
}

int min(stack* m_stack)
{
	if (m_stack == nullptr)
		throw std::exception{};
	if (m_stack->first == nullptr)
		throw std::exception{};
	node* ptr = m_stack->first;
	int min = ptr->value;
	ptr = ptr->next;
	while (ptr != nullptr)
	{
		if (min > ptr->value)
		{
			min = ptr->value;
		}
		ptr = ptr->next;
	}
	return min;
}
void remove_odd(stack* m_stack)
{
	if (m_stack == nullptr)
		throw std::exception{};
	if (m_stack->first == nullptr)
		throw std::exception{};
	while (m_stack->first->value % 2)
	{
		node* buf = m_stack->first->next;
		delete m_stack->first;
		m_stack->first = buf;
		if (!buf)
		{
			return;
		}
	}
	node* ptr = m_stack->first;
	
	while (ptr->next != nullptr)
	{
		if (ptr->next->value % 2)
		{
			node* buf = ptr->next->next;
			delete ptr->next;
			ptr->next = buf;
			continue;
		}
		ptr = ptr->next;
	}

}

void init(stack* m_stack)
{
	m_stack->first = nullptr;
}

void deinit(stack* m_stack)
{
	if (!m_stack)
	{
		throw std::exception{};
	}
	while (m_stack->first != nullptr)
	{
		pop_back(m_stack);
	}

}

