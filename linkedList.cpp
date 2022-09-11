#include<iostream>
//Create Node
template<typename data_type>
struct Node
{
	data_type data;
	Node * next;
	Node(data_type data) { this->data = data; next = nullptr; }
};
//Create LinkedList
template<typename data_type>
struct linked_list
{
private:
	//First node
	Node<data_type> * head;
	//Last node
	Node<data_type> * tail;
	//Node's count
	unsigned int count;
	//Check index
	bool check_position(int index)
	{
		if (index >= 0 && index <= count){return true;}
		else { std::cout << "Index is incorrect\n"; return false; }
	}
public:
	//Empty list
	linked_list() { head = tail = nullptr; count = 0; }
	//Push back node
	void add_node(data_type data)
	{
		try
		{
			Node<data_type>*temp = new Node<data_type>(data);
			if (head == nullptr)
			{
				head = tail = temp;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
			count++;
		}
		catch (std::bad_alloc exp)
		{
			std::cout << "Memory is full !!!\n";
			std::cout << exp.what();
		}
	}
	//Get node using index
	Node<data_type>* get_node(int index)
	{
		if (check_position(index))
		{
			Node<data_type>* temp = head;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp;
		}
		else {  return nullptr; }
	}
	//Insert node using index
	void insert_node(data_type any_data, int index)
	{
		if (check_position(index))
		{
			Node<data_type>*sample = get_node(index);
			if (sample == nullptr)
			{
				add_node(any_data);
				count++;
			}
			else
			{
				try
				{
					Node<data_type>*temp = new Node<data_type>(any_data);
					if (index == 0)
					{
						temp->next = head;
						head = temp;
					}
					else
					{
						sample = get_node(index - 1);
						temp->next = sample->next;
						sample->next = temp;
					}
					count++;
				}
				catch (std::bad_alloc exp)
				{
					std::cout << "Memory is full !!!\n";
					std::cout << exp.what();
				}
			}
			
		}
		else { return; }
	}
	//Delete node using index
	void delete_node(int index)
	{
		if (check_position(index) && count == 0){ return; }
		if (index == 0)
		{
			Node<data_type> * temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node<data_type> * temp = get_node(index-1);
			Node<data_type> * remove = temp->next;
			temp->next = remove->next;
			delete remove;
		}
		count--;
	}
	//Show list data
	void print_list()
	{
		Node<data_type>*temp = head;
		while (temp != nullptr)
		{
			std::cout << "Node data: " << temp->data << std::endl;
			temp = temp->next;
		}
	}
};

int main()
{
	//Create list
	linked_list<int> list;
	//Add node's
	list.add_node(4);
	list.add_node(5);
	//Insert node
	list.insert_node(6, 3);
	//Print list
	list.print_list();
	std::cout << "\n\n\n\n";
	//Delete Node
	list.delete_node(2);
	//Print list
	list.print_list();


	return 0;
}