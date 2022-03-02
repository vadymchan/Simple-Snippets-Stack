#include <iostream>
using namespace std;

//Stack(made by Simple Snippets)


class Stack
{
private:
	int top;
	int arr[5]; //!!! dynamic memory
public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0; //!!!assign to default number not in thi way
		}
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if (top == 4)//!!!it's hardcode
			return true;
		return false;
	}

	void push(int value)
	{
		if (isFull())
		{
			cout << "Stack overflow" << endl;
		}
		else
		{
			top++;
			arr[top] = value;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			int temp = arr[top];
			arr[top] = 0;
			top--;
			return temp;
		}
	}

	int count()
	{
		return (top + 1);
	}

	int peek(int index)
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			return arr[index];
		}
	}

	void change(int index, int value) //!!! Sounds quite dummy)
	//e.g. if we have only one element in stack and we assign value to index
	//that a lot higher than top element, it'll crush the stack logic
	{
		arr[index] = value;
		cout << "Value changed at the location at the location " << index << endl;
	}

	void display()//from top to bottom
	{
		for (int i = 4; i >= 0; i--)
		{
			cout << i << "->" << arr[i] << endl;
		}
	}
};

int main()
{
	Stack stack;
	int option, value, index;

	do
	{
		cout << "What operation do you want to perform? Select option number. Enter 0 to exit\n"
			<< "1. push(value)\n"
			<< "2. pop()\n"
			<< "3. isEmpty()\n"
			<< "4. isFull()\n"
			<< "5. peek(index)\n"
			<< "6. count()\n"
			<< "7. change(index, value)\n"
			<< "8. display()\n"
			<< "9. Clear Screen\n";

		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Enter item to push in stack: ";
			cin >> value;
			stack.push(value);
			cout << endl;
			break;
		case 2:
			cout << "Popped Function called - Popped value: " << stack.pop() << endl;
			break;
		case 3:
			if (stack.isEmpty())
				cout << "Stack is empty\n";
			else
				cout << "Stack is not empty\n";
			break;
		case 4:
			if (stack.isFull())
				cout << "Stack is full\n";
			else
				cout << "Stack is not full\n";
			break;
		case 5:
			cout << "Enter the index of the item you want to peek: ";
			cin >> index;
			cout << "\nPeek funktion called - Value at index " << index << " is: " << stack.peek(index) << endl;
			break;
		case 6:
			cout << "Count Function Called - Numbers of the Items in Stack are: " << stack.count() << endl;
			break;
		case 7:
			cout << "Enter the index of the you want to change: ";
			cin >> index;
			cout << "\nEnter the value of item you want to change: ";
			cin >> value;
			stack.change(index, value);
			break;
		case 8:
			cout << "Display Function Called - \n";
			stack.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			break;
		}

	} while (option != 0);

	return 0;
}

