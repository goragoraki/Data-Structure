#pragma once
#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 

class UnsortedType 
{
public:
  UnsortedType();
  // Constructor
  bool IsFull() const;
  // Function:  Determines whether list is full.

  int LengthIs() const;
  // Function: Determines the number of elements in list.

  void RetrieveItem(ItemType& item, bool& found);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).

  void InsertItem(ItemType item);
  // Function: Adds item to list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.

  void GetNextItem(ItemType& item);
  // Function: Gets the next element in list..

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};
