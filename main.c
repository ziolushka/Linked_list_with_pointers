#include <list.h>

#define data 0
#define next 1

int main()
{
    char** head = NULL;

    StringListAdd(&head, NULL);
    StringListAdd(&head, "555");
    StringListAdd(&head, "333");
    StringListAdd(&head, "222");
    StringListAdd(&head, "555");
    StringListAdd(&head, "444");
    StringListAdd(&head, "444");
    StringListPrint(head);

    printf("Remove element %s\n","222");
    StringListRemove(&head, "222");
    StringListPrint(head);

    printf("List size: %d\n",StringListSize(head));

    printf("Index of \"%s\" element is %d \n","333", StringListIndexOf(&head, "333"));

    printf("Replace strings \"%s\" with \"%s\"\n","444", "aaa");
    StringListReplaceInStrings(&head,"444", "aaa");
    StringListPrint(head);

    printf("Remove duplicates \n");
    StringListRemoveDuplicates(&head);
    StringListPrint(head);

    printf("Sort list \n");
    StringListSort(&head);
    StringListPrint(head);

    printf("Destroy list \n");
    StringListDestroy(&head);
    StringListPrint(head);

    return 0;
}
