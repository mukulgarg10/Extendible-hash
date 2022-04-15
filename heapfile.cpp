#include <bits/stdc++.h>
using namespace std;
int t;
int np=0;
struct page{
     vector<int>pk;
     vector<int>sz;
     page *previous;
     page *next;
     int count;
     int free;
  
     page(int k)
     {
        this->free=t;
        this->previous=nullptr;
        this->next=nullptr;
        np++;
     }
     page(int k,page *m)
     {
        this->free=k;
        this->previous=m;
        this->next=nullptr;
        np++;
     }
};
page *root=nullptr;

void insert(int k,int size)
{    
     if(root==nullptr)
     {   
         root=new page(t);
     }
     page* curr=root;
     while(curr->free<(size+4))
     {
         if(!(curr->next))
         {   page* temp=curr;
             curr=new page(t,temp);
             temp->next=curr;
         }
         else
         {
            curr=curr->next;
         }
     }
     curr->free-=(size+4);
     (curr->sz).push_back(size);
     (curr->pk).push_back(k);

     return ;
}

void search(int k)
{   
    page* curr=root;
    bool flag=true;
    int j=0;
    while(curr)
    {   j++;
         for(int i=0;i<((curr->pk).size());i++)
         {  
            if((curr->pk)[i]==k)
            {
                cout<<(j-1)<<" "<<i;
                cout<<endl;
                flag=false;
                break;
            }
         }
         if(flag)
         {
              curr=curr->next;
         }
         else
         break;
    }
    if(flag)
    {
       cout<<-1<<" "<<-1;
       cout<<endl;
    }
}
void status()
{
     page *curr=root;
     cout<<np<<" ";
     if(root==nullptr)
     {
        cout<<0;
     }
     while(curr)
     {
          cout<<curr->pk.size()<<" ";
          curr=curr->next;
     }
     cout<<endl;
}

int main()
{
   cin >>t;
   t=t-16;
   int choice;
   while (1)
   {
      cin >> choice;
      if (choice == 1)
      {
         int key,size;
         cin >> size;
         cin>>key;
         insert(key,size);
      }
      else if (choice == 3)
      {
         int k;
         cin>>k;
         search(k);
      }
      else if(choice==2)
      {
         status();
      }
      else
      break;
   }
}