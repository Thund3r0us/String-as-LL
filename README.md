# String as LL

An alternate method of storing a string is to store each letter of the string in a single node of a linked list,
with the first node of the list storing the first letter of the string. Using this method of storage, no null
character is needed since the next field of the node storing the last letter of the string would simply be a
null pointer.
