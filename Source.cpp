#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack <int> stack_list;
int GetSize() 
{
	int size;
	cout << "Введите длину стека:\t";
	while (!(cin >> size) || (cin.peek() != '\n') || size < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число:\t";
	}
	return size;
}
int Get_int() 
{
	int number;
	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите корректное число:\t";
	}
	return number;
}
void Create_stack(int size) 
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i << "-й элемент стека:\t";
		tmp = Get_int();
		stack_list.push(tmp);
	}
}
void Print_stack() 
{
	int i = stack_list.size() - 1;
	vector <int> array_of_stack;
	while (!stack_list.empty()) 
	{
		cout << i << "-й элемент стека:\t" << stack_list.top() << endl;
		array_of_stack.push_back(stack_list.top());
		stack_list.pop();
		i--;
	}
	for (int j = array_of_stack.size() - 1; j >= 0; j--) 
	{
		stack_list.push(array_of_stack[j]);
	}
}
bool Delete_element() 
{
	bool check = false;
	vector<int> array_of_stack;
	while (!stack_list.empty()) 
	{
		array_of_stack.push_back(stack_list.top());
		stack_list.pop();
	}
	int size = array_of_stack.size();
	int i = 0;
	while (array_of_stack.size() == size && i < array_of_stack.size()) 
	{
		if (array_of_stack[i] % 2 == 0) 
		{
			array_of_stack.erase(array_of_stack.begin() + i);
			check = true;
		}
		i++;
	}
	for (int k = array_of_stack.size() - 1; k >= 0; k--) 
	{
		stack_list.push(array_of_stack[k]);
	}
	return check;
}
int main() 
{
	setlocale(LC_ALL, "ru");
	int size = GetSize();
	Create_stack(size);
	Print_stack();
	cout << "=========================================" << endl;
	if (Delete_element())
	{
		Print_stack();
		cout << "=========================================" << endl;
	}
	else 
	{
		cout << "Четных элементов в стеке нет!" << endl;
	}
}