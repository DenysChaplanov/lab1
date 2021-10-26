#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct MyLinkedList
{
    int data;
    struct MyLinkedList * prev;
    struct MyLinkedList *next;
};

struct MyLinkedList *init(int a);
void printList(struct MyLinkedList *head);
struct MyLinkedList *insertEnd(struct MyLinkedList *head, int a);
struct MyLinkedList *insertCenter(struct MyLinkedList *head, int a);
int sizeOfLinkedList(struct MyLinkedList *head);
int getValueOf(struct MyLinkedList *head, int index);
void setValue(struct MyLinkedList *head, int index, int val);
struct MyLinkedList *removeElement(struct MyLinkedList *head, int index);

int main(){
    struct MyLinkedList *head = NULL;
    int IsCreated = 0;
    int ch = 0;
    int num = 0, ind = 0;
    while (1){
        printf("\n0. Exit\n1. Add element to the end\n2. Insert to the center\n"
               "3. Amount of elements\n4. Remove by index\n5. Set new value\n"
               "6. Get element by index\n7. Print Linked List\n\n");
        scanf("%d",&ch);
        switch (ch) {
            case 0:
                exit(0);
            case 1:
                if(IsCreated == 0){
                    printf("\nEnter a number: ");
                    scanf("%d",&num);
                    head = init(num);
                    IsCreated = 1;
                } else{
                    printf("\nEnter a number: ");
                    scanf("%d",&num);
                    insertEnd(head,num);
                }
                break;
            case 2:
                if(IsCreated == 0){
                    printf("\nEnter a number: ");
                    scanf("%d",&num);
                    head = init(num);
                    IsCreated = 1;
                } else{
                    printf("\nEnter a number: ");
                    scanf("%d",&num);
                    insertCenter(head,num);
                }
                break;
            case 3:
                printf("\nAmount of elements: %d", sizeOfLinkedList(head));
                break;
            case 4:
                if(IsCreated == 0){
                    printf("\nLinked List has not created yet\n");
                } else{
                    printf("\nEnter index: ");
                    scanf("%d",&ind);
                    removeElement(head,ind);
                }
                break;
            case 5:
                if(IsCreated == 0){
                    printf("\nLinked List has not created yet\n");
                } else{
                    printf("\nEnter the index: ");
                    scanf("%d",&ind);
                    printf("\nEnter the number: ");
                    scanf("%d",&num);
                    setValue(head,ind,num);
                }
                break;
            case 6:
                if(IsCreated == 0){
                    printf("\nLinked List has not created yet\n");
                } else{
                    printf("\nEnter index: ");
                    scanf("%d",&ind);
                    printf("\nThe value of element: %d",getValueOf(head,ind));
                }
                break;
            case 7:
                printList(head);
                break;
            default:
                printf("Unknown operation");
                break;
        }
    }
    return 0;
}

int sizeOfLinkedList(struct MyLinkedList *head){
    int count = 0;
    while (head!=NULL){
        head = head->next;
        count++;
    }
    return count;
}

int getValueOf(struct MyLinkedList *head, int index){
    struct MyLinkedList *temp = head;
    if(index>=0 && index < sizeOfLinkedList(head)){
        int step = 0;
        while (temp!=NULL){
            if(step == index){
                return temp->data;
            }
            step++;
            temp = temp->next;
        }
    } else{
        printf("Incorrect index");
        return -1;
    }
}


void setValue(struct MyLinkedList *head, int index, int val){
    struct MyLinkedList *temp = head;
    if(index>=0 && index < sizeOfLinkedList(head)){
        int step = 0;
        while (temp!=NULL){
            if(step == index){
                temp->data = val;
                break;
            }
            step++;
            temp = temp->next;
        }
    } else{
        printf("Incorrect index");
    }
}

struct MyLinkedList *init(int a){
    struct MyLinkedList *lst = malloc(sizeof (struct MyLinkedList));
    lst->prev = NULL;
    lst->next = NULL;
    lst->data = a;
    return lst;
}

struct MyLinkedList *insertEnd(struct MyLinkedList *head, int a){
    struct MyLinkedList *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    struct MyLinkedList *nod = malloc(sizeof (struct MyLinkedList));
    nod->data = a;
    nod->next = NULL;
    nod->prev = temp;
    temp->next = nod;
    return temp;
}

struct MyLinkedList *removeElement(struct MyLinkedList *head, int index){
    if(index>0 && index < sizeOfLinkedList(head)){
        struct MyLinkedList *temp = head;
        int step = 0;
        while (temp!=NULL){
            if(step == index){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                return temp;
            }
            step++;
            temp = temp->next;
        }
    } else{
        printf("Incorrect index!");
        return head;
    }
}

struct MyLinkedList *insertCenter(struct MyLinkedList *head, int a){
    struct MyLinkedList *temp = head;
    int index = sizeOfLinkedList(head) / 2;
    int step = 0;
    while(temp->next!=NULL){
        if(step == index){
            struct MyLinkedList *nod = malloc(sizeof (struct MyLinkedList));
            nod->data = a;
            nod->next = temp->next;
            nod->prev = temp;
            temp->next = nod;
            return temp;
            break;
        }
        step++;
        temp = temp->next;
    }
}

void printList(struct MyLinkedList *head){
    while (head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}
