#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *previous;

};


typedef struct node *  NODE;
NODE createNode(){

    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->next = NULL;
    temp->previous = NULL;
    temp ->data = 0;
    return temp;
}

NODE insert(NODE head, int value){
    NODE x = createNode();
    x->data = value;
        if(head ==NULL){
            head = x;
            return head;
        }else{
        x->next = head;
        x->previous=NULL;


            head->previous = x;


        head = x;

        }

}
NODE deleteBySpecificValue(NODE head, int valueToBeDeleted)
{
    NODE temp = head;
    while(temp->next!=NULL)
    {
        if(temp->data==valueToBeDeleted)
            break;
    temp = temp->next;
    }
    if(temp->data!=valueToBeDeleted){
        temp = NULL;
    }
    if(head==NULL || temp ==NULL){
        printf("Nothing for be deleted");
        return head;
    }

    if(temp->previous==NULL){
        temp = head;
        head = head->next;
        head->previous==NULL;
        free(temp);
        return head;
    }else if(temp->next==NULL)
    {
        (temp->previous)->next=NULL;
        temp->previous=NULL;
        free(temp);
        return head;
    }else
    {
        (temp->previous)->next = temp->next;
        (temp->next)->previous=temp->previous;
        free(temp);
        return head;
    }


}
void displayLinkedList(NODE head){
    NODE x = head;
    if(head==NULL){
        printf("Nothing to display");
    }
    while(x!=NULL){
        printf("%d\t", x->data);
        x=x->next;
        }
}
int main()
{
    int choice,data, valueToBeDeleted;
    NODE head = NULL;
    do{
        printf("\nEnter 1 for entering node\n");
        printf("Enter 2 to delete node having a specific value\n");
        printf("Enter 3 Display this linked list\n");
        printf("Enter 4 to Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to be inserted in the node\n");

                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                printf("Enter value of node that has to be deleted\n");
                scanf("%d", &valueToBeDeleted);
                deleteBySpecificValue(head, valueToBeDeleted);
                break;
            case 3:
                 displayLinkedList(head);
                break;
            default:
                printf("Invalid choice. Press 4 to exit");

        }
    }while(choice!=4);

    return 0;
}
