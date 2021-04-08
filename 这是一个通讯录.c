#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct CP//"CP" contact person
{
    char name[40];
    char num[12];
    struct CP *next;
};
void printPerson(struct CP *cp);
void addPerson(struct CP *cp);
void findPerson(struct CP *cp);
void changePerson(struct CP *cp);
void delPerson(struct CP *cp);
void displayContact(struct CP *cp);

void printPerson(struct CP *cp)
{
    printf("Name:%s\n",cp->name);
    printf("Phone number:%s\n",cp->num);
}
void addPerson(struct CP *cp)
{
    printf ("Please enter his/her name:");
    scanf ("%s",cp->name);
    printf ("Please enter his/her phone number:");
    scanf ("%s",cp->num);
}
void findPerson(struct CP *cp)
{
    struct CP *target;
    char search[40];
    printf("Please enter the name of the person you want to search for:");
    scanf("%s",search);
    target=cp;
    while (search!=target->name && target!=NULL)
    {
        target=target->next;
    }
    if(target==NULL)
    {
        printf("No matches.");
    }
    else
    {
        printPerson(target);
    }
}
void changePerson(struct CP *cp)
{
    struct CP *target;
    char search[40];
    printf("Please enter the name of the person you want to change its details:");
    scanf("%s",search);
    target=cp;
    while (search!=target->name && target!=NULL)
    {
        target=target->next;
    }
    if(target==NULL)
    {
        printf("No matches.");
    }
    else
    {
        printPerson(target);
    }
    printf ("Please reenter his/her name:");
    scanf ("%s",cp->name);
    printf ("Please reenter his/her phone number:");
    scanf ("%s",cp->num);
    printf("Saved.");
}
void delPerson(struct CP *cp)
{
    struct CP *current,*previous;
    char search[40];
    printf("Please enter the name of the person you want to delete:");
    scanf("%s",search);
    current=cp;
    while (search!=current->name && current!=NULL)
    {
        previous=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("No matches.");
    }
    else
    {
        if(previous==NULL)
        {
            cp=current->next;
        }
        else
        {
            previous->next=current->next;
            free(current);
        }
    }
}

int main (void)
{
    char option;
    struct CP *head,*acp/*,*previous,*current*/;
    head=NULL;
    while(1)
    {
        printf("This is your e-contact.\n");
        printf("a.Add new contact person.\n");
        printf("b.Search former contact person.\n");
        printf("c.Change former contact person.\n");
        printf("d.Delete former contact person.\n");
        printf("e.Display my e-contact.\n");
        printf("f.Exit my e-contact.\n");
        printf("Please enter an order letter to opt the function above you need: ");
        scanf("%s",&option);
        if(option=='f')
        {
            printf("You have exited your Contact.");
            break;
        } 
        if(option=='a')
        {
            acp=(struct CP *)malloc(sizeof (struct CP));
            if(acp==NULL)
            {
                printf("Failed to allocate memory");
                exit(1);
            }
            else
            {
                addPerson(acp);
            }
            if(head==NULL)
            {
                head=acp;
            }
            else
            {
                /*current=head;
                previous=NULL;
                while((current->num)!=) 再增加一个函数才进行排序吧，反正这里仅仅查询罢了*/
                acp->next=head;
            }
            printf("==================Enter finished.==================\n");
            printPerson(acp);
            free(acp);
        }
        if(option=='b')
        {
            findPerson(head);
        }
        if(option=='c')
        {
            changePerson(head);
            printf("Details changed.");
        }
        if(option=='d')
        {
            delPerson(head);
            printf("Deletion Fininshed.");
        }
        if(option=='e')
        {
            acp=head;
            while(acp!=NULL)
            {
                printf("This is your contact:\n");
                printPerson(acp);
                acp=acp->next;
            }
        }
        printf("Please press ENTER to continue...\n");
        getchar();//putchar会输入括号中的字符，getchar不需要带字符
        getchar();
    }
    return 0;
}