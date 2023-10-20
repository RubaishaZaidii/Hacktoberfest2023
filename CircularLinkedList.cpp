#include<iostream>
using namespace std;
template<typename T>
 struct DNode
 {
    T info;
    DNode <T> *next;
    DNode <T> *prev;
    DNode()
    {
        next=NULL;
        prev=NULL;
    }
    DNode(T val)
    {
        info=val;
        next=NULL;
        prev=NULL;
    }

 };
 template<typename T>
 class CDLL{
    DNode<T> * head;;
    public:
  CDLL()
    {
        head=nullptr;
    }
    void print()
    {
        
        if(!head)
        {
            return;
        }
        DNode<T>*x=head;
        do
        {
            cout<<x->info<<" ";
            x=x->next;
        } while (x!=head);
        
    }
    void insertAtHead(T val)
    {
         DNode<T>*p=new DNode<T>(val);;
        if(!head)
        {
            head=p;
            head->next=head->prev=head;
            return;
        }
        p->next=head;
        head->prev=head->prev;
        head->prev->next=p;
        head=p;
    }
    void innsertAtTail(T val)
    {
      DNode<T>*p=new DNode<T>(val);
         if(!head)
        {
            head=p;
            head->next=head->prev=head;
            return;
        }
        p->next=head;
        p->prev=head->prev;
        head->prev->next=p;
        head->prev=p;
    }
    void removeAfter(T key)
    {
        if(!head)
        {
            return;
        }
        DNode<T>*p=new DNode<T>(key);
        do
        {
           if(p->info==key)
           {
             if(head==head->prev)
            {
                delete head;
                head=nullptr;
                return;
            }
             DNode<T>*x=p->next;
             p->next=x->next;
             x->next->prev=p;
             delete x;
             if(x==head)
             {
                head=p->next;
                return;
             }
           }
            p=p->next;
        } while (p!=head); 
    }
    int countNodes()
    {
        DNode <T> *temp=head;
        int count=0;
        do
        {
            count++;
            temp=temp->next;
        }while(temp->next!=head);

        return count;
    }
    void exchange1stAndLastNode()
    {
         DNode<T> * p=head;
        while (p->next->next != head)// 5 1 2 3 4 ---> 4 1 2 3 5

        p = p->next;
 
    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;
    }
    void splitCircularList()
    {
      int len=countNodes(),i=0;
       CDLL<int> L1;
       CDLL<int> L2;
       DNode<T>* t=head;
       do
       {
         i++;
         L1.innsertAtTail(t->info);
         t=t->next;
         
       } while (i!=len/2+1);
       L1.print();
       cout<<endl;
       i--;
       cout<<"Second is "<<endl;
        do
       {
         L2.innsertAtTail(t->info);
         t=t->next;
         i++;
       } while (i!=len);
       L2.print();
       
    }
};
int main()
{
    CDLL<int> l;
    l.innsertAtTail(4);
    l.innsertAtTail(5);                            
    l.innsertAtTail(76);
    l.innsertAtTail(12);
    l.innsertAtTail(89);
    l.innsertAtTail(554);
    l.innsertAtTail(-86);
      l.innsertAtTail(-8);
   
    
    
    cout<<"\n";
   l.splitCircularList();

    return 0;
}