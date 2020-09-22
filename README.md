# Linked_list_with_pointers
Dynamically sized list of c-strings.

---------------------------------------------------------------------
**Task:**
Implement a dynamically sized list of c-strings.
 
**Requirements:**
1) Only stdlib.h and string.h headers can be used in file where the list is implemented.
2) No new or delete operators. Only malloc, realloc and free functions.
3) Do not use classes or structures. Only pointers can be used.
4) You can use ANY code convention you like
5) User should be able to:
    - add/remove string
    - get the number of items in the list
    - get the index position of the first exact match of specified string
 
**Will be a plus:**
User is able to remove duplicates, replace the text in items, sort list.

---------------------------------------------------------------------

**Implementation:**

![](https://i.stack.imgur.com/7ItuZ.jpg)

Created a list of a char**-nodes, that contain value [data] and a pointer to the next item in the list [next].

    char** node = (char**)malloc(2 * sizeof(char*));
    node[data] = (char*)malloc(sizeof(char) * size);
    memcpy(node[data], str, sizeof(char) * size);
    node[next] = NULL;

In accordance with this "data structure", I've implemented functions, which allow the user to add/remove the string, get the number of items in the list, get the index position of the first exact match of a specified string, remove duplicates, replace the text in items and sort list.



