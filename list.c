#include <list.h>

#define data 0
#define next 1

/*Prints list*/
void StringListPrint(char** list) {

    if (list == NULL) {
        printf("List is empty!");
        return;
    }

    char** temp = list;
    printf("List members:\n");
    while (temp != NULL) {
        printf("%s\n", (temp[data]));
        temp = temp[next];
    }
    printf("\n");
}
/* Destroy list and set pointer to NULL. */
void StringListDestroy(char*** list) {

    if (list == NULL) return;

    char** prev = *list;
    char** curr = (char**)prev[next];

    /*iterate over list and delite curr prev element*/
    while (curr != NULL) {
        free(prev[data]);
        free(prev);
        prev = (char**)curr;
        curr = (char**)curr[next];
    }

    free(prev[data]);
    free(prev);

    *list = NULL;
}
/* Inserts value at the end of the list. */
void StringListAdd(char*** list, const char* str) {

    if (str == NULL) return;

    const size_t size = strlen(str) + 1;

    //create new node
    char** node = (char**)malloc(2 * sizeof(char*));
    node[data] = (char*)malloc(sizeof(char) * size);
    memcpy(node[data], str, sizeof(char) * size);
    node[next] = NULL;

    //add new node to list
    if (*list == NULL) {
        // first node to be added
        *list = node;
    }
    else {
        char** temp = *list;
        // search the last node in the list
        while (temp[next] != NULL) {
            temp = (char*)temp[next];
        }
        temp[next] = (char**)node;
    }
}
/* Removes all occurrences of str in the list. */
void StringListRemove(char*** list, const char* str) {

    if (str == NULL) return;

    char** curr = *list;
    char** temp = NULL;
    char** prev = NULL;

    //iterate to the node before the node we wish to delete
    while (curr != NULL) {
        if (!strcmp(curr[data], str)) {
            if (prev != NULL){
                //Save the node we wish to delete in a temporary pointer
                temp = curr;
                //Set the previous node's next pointer to point to the node after the node we wish to delete
                prev[next] = curr[next];
                break;
            }
            else
                *list = curr[next];
        }
        prev = curr;
        curr = (char*)curr[next];
    }
    //Delete the node using the temporary pointer
    free(temp[data]);
    free(temp);
}
/* Returns the number of items in the list. */
int StringListSize(char** list) {

    int size = 0;
    while (list != NULL) {
        list = (char**)list[next];
        size++;
    }
    return size;
}
/* Returns the index position of the first occurrence of str in the list. */
int StringListIndexOf(char*** list, const char* str) {

    if (str == NULL) return -1;

    char** curr = *list;
    int possition = 0;

    while (curr != NULL) {
        if (!strcmp(curr[data], str)) {
            return possition;
        }
        possition++;
        curr = (char*)curr[next];
    }
    return -1;
}
/* Removes duplicate entries from the list. */
void StringListRemoveDuplicates(char*** list) {

    if (list == NULL)
        return;

    char** prev = NULL
        , ** curr = NULL
        , ** curr2 = NULL;

    curr = *list;

    while (curr != NULL) {
        prev = curr;
        curr2 = curr[next];
        while (curr2 != NULL) {
            if (!strcmp(curr[data], curr2[data])) {
                prev[next] = curr2[next];
                free(curr2[data]);
                free(curr2);
                curr2 = prev;
            }
            prev = curr2;
            curr2 = curr2[next];
        }
        curr = curr[next];
    }

}
/* Replaces every occurrence of the before, in each of the string lists's strings, with after. */
void StringListReplaceInStrings(char*** list, const char* before, const char* after) {

    if (before == NULL || after == NULL) return;
    char** curr = *list;

    while (curr != NULL) {
        if (!strcmp(curr[data], before)) {
            char* tmp = (char*)malloc(sizeof(char) * (strlen(after) + 1));
            strcpy(tmp, after);
            free(curr[data]);
            curr[data] = tmp;
        }
        curr = (char*)curr[next];
    }
}
/* Sorts the list of strings in ascending order */
void StringListSort(char*** list) {

    char **str1 = NULL
        ,**str2 = NULL;
    str1 = *list;

    while (str1 != NULL){
        str2 = str1[next];
        /* Compare the picked element with rest of the elements */
        while (str2 != NULL){
            /* If duplicate then delete it */
            if (0 < strcmp(str1[data], str2[data])){
                char** temp = str1[data];
                str1[data] = str2[data];
                str2[data] = temp;

            }
            else
                str2 = str2[next];
        }
        str1 = str1[next];
    }
}
