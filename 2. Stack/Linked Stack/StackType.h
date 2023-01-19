// Linked Stack ADT

typedef int ItemType;
struct NodeType;

class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


class StackType
{
public:

  StackType();
  // Class constructor.
  ~StackType();
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
  NodeType* topPtr;
};

struct NodeType
{
  ItemType info;
  NodeType* next;
};

