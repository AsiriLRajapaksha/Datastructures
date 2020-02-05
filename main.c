#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char name[20];
    int age;
    int contact_no;
    struct node* link;
}Node;
struct node* root = NULL;
int i = 0;


int main()
{
    printf("************************Contact Information**************************\n");
    while(1){
        printf("\n1. Add Contact");
        printf("\n2. Update Contact");
        printf("\n3. Display Contact");
        printf("\n4. Delete Contact");
        printf("\n5. Exit");
        printf("\n Enter Your choice : ");
        scanf("%d",&i);

        switch(i){
            case 1: Append();
            break;
            case 2: Update();
            break;
            case 3: Display();
            break;
            case 4: Delete();
            break;
            case 5: exit(1);
            break;
            default: printf("\nYour Choice is incorrect !!\n");
        }
    }

    return 0;


}

void Append(Node *temp){
    temp = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter name: ");
    scanf("%s" , &temp->name);
    printf("\nEnter Age : ");
    scanf("%d", &temp->age);
    printf("\nEnter Contact Number: ");
    scanf("%d", &temp->contact_no);
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }else{
        struct node* p = root;

        while(p->link != NULL){
            p = p->link;
        }

        p->link = temp;
    }
}
void Display(Node *p){
    p = root;

    if(root == NULL ){
        printf("\n\n List is Empty....");
    }else{
        while(p != NULL){

            printf("\nName :%s" , p->name );
            printf("\nAge :%d" , p->age );
            printf("\nName :%d" , p->contact_no );
            printf("\n");

            p = p->link;
        }
    }
}
void Update(Node *p){
    char name[20];
    printf("\nEnter Name : ");
    scanf("%s",&name);

    p = root;

    while( p->link != NULL){
        p = p->link;

        if( strcmp(name,p->name) == 0){

        printf("\nEnter New Name :");
        scanf("%s" , &p->name);

        printf("\nEnter Age :");
        scanf("%d" , &p->age);

        printf("\nEnter Contact Number : ");
        scanf("%d" , &p->contact_no);

        printf("\n");

        p->link = NULL;
        }
    }

}

void Delete(Node *p ,Node *q){
    char s[20];
    printf("\nEnter name: ");
    scanf("%s",&s);

    p = root;
    while(strcmp(s,p->name) != 0){
        q = p;
        p = p->link;
    }
    q->link = p -> link;
    printf("\nSuccessfully deleted!!!!\n\n");
}

