// Header file for Unsorted List ADT.
#pragma once

template<class ItemType>
struct NodeType;

// Assumption: ItemType is a type for which the operators "<"
// and "==" are defined-either an appropriate built-in type or 
// a class that overloads these operators.

template<class ItemType>
class UnsortedType
{
public:

	// Class constructor
	UnsortedType();

	// Class deconstructor
	~UnsortedType();

	// Determines whether list is full.
	bool IsFull() const; // Determines whether the list is full or not.
	
	int LengthIs() const;

	void MakeEmpty();
	// Initialize list to empty state;
	// Post: List is empty.

	void RetrieveItem(ItemType& item, bool& found);
	// Retrieves list element whose key matches item's key
	// (if present).
	// Pre: Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	//		 item's key, then found = true and item is a copy
	//		 of someItem; otherwise found = false and item is
	//		 unchanged.
	//		 List is unchanged.

	void InsertItem(ItemType& item);
	// Adds item to list.
	// Pre: List is not full.
	//		item is not in list.
	// Post: item is in list.

	void DeleteItem(ItemType& item);
	// Deletes teh element whose key matches item's key.
	// Pre: Key member of item is initialized.
	//		One and only one element in list has a key matching
	//		item's key.
	// Post: No element in list has a key matching item's key.

	void ResetList();
	// Initialize current position for an iteration though the
	// list.
	// Post: Current position is prior to first element in list.

	void GetNextItem(ItemType& item);
	// Gets the next element in list.
	// Pre: Current position is defined.
	//		Element at current position is not last in list.
	//		item is a copoy of element at current position.

private:
	NodeType<ItemType> *listData;
	int length;
	NodeType<ItemType> currentPos;
};

template<class ItemType>
struct NodeType {
	ItemType info;
	NodeType* next;
};

// ----------------------- Class Constructors -------------------------------- //
template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
	length = 0;
	listData = NULL;
}

template<class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{

}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another NodeType node
// on the free store: false otherwise.
{
	NodeType<ItemType>* ptr;
	ptr = new NodeType<ItemType>;

	if (ptr == NULL)
		return true;
	else {
		delete ptr;
		return false;
	} // end if
}

template<class ItemType>
int UnsortedType<ItemType>::LengthIs() const
{	
	return length;
}
// Determines the number of elements in the list.
// Post: Function value = number of elements in list.