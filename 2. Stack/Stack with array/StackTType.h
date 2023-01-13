// The class definition for StackType using templates 
class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};
const int MAX_ITEMS = 10;

template<class ItemType>		
class StackType
{
public:

    StackType();
    // Class constructor.
    bool IsFull() const;
    // Function: Determines whether the stack is full.
    bool IsEmpty() const;
    // Function: Determines whether the stack is empty.
    void Push(ItemType item);
    // Function: Adds newItem to the top of the stack.
    void Pop();
    // Function: Removes top item from the stack.
    ItemType Top();
    // Function: Returns a copy of top item on the stack.
           
private:
    int top;
    ItemType  items[MAX_ITEMS];	
};

template<class ItemType>
StackType<ItemType>::StackType()
{
    top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
    return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
    return (top == MAX_ITEMS - 1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
    if (IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
    if (IsEmpty())
        throw EmptyStack();
    top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
    if (IsEmpty())
        throw EmptyStack();
    return items[top];
}
