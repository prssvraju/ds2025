        int count=0;
        struct node *temp;
        temp=head;
        printf("test-1");
        while(temp->next!=head);
        {
                printf("test-2");
                count=count+1;
                temp=temp->next;
        }
        return count;