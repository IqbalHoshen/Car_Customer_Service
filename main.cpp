#include <iostream>
using namespace std;

struct Queue {
   int SSN;
   struct Queue *next;
};
struct Queue* front = NULL;
struct Queue* rear = NULL;
struct Queue* temp;

void enQueue() {
   int Num;
   
   cout<<"\n**Entry customer’s SSN : "<<endl;
   cout<<"  =>";
   cin>>Num;
cout<<"\t\t\tSSN-> "<<Num<<" "<<"has been accepted"<<endl;
   if (rear == NULL) {
      rear = new Queue();
      rear->next = NULL;
      rear->SSN = Num;
      front = rear;
   } 
   else {
      temp=new Queue();
      rear->next = temp;
      temp->SSN = Num;
      temp->next = NULL;
      rear = temp;
   }
}

void dQueue() {

   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else if (temp->next != NULL) {
      temp = temp->next;
      cout<<"\n \t\tRemove customer’s SSN number  : "<<front->SSN<<" "<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"\n \t\tRemove customer’s SSN number  : "<<front->SSN<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void Display() {
  int i=1;
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"\t\t\t---There are no customers in the list---"<<endl;
      return;
   }
   cout<<"\t\tThe SSN number of available customer in the system "<<endl;

   while (temp != NULL) {
      cout<<i<<") "<<"SSN-> "<<temp->SSN<<endl;
      temp = temp->next;
      i++;
   }
   cout<<endl;
}
int main() {
   int ch;
   cout<<"--------------------------------------"<<endl;
   cout<<"1) Entry Customer SSN: "<<endl;
   cout<<"2) Service "<<endl;
   cout<<"3) Display available Customer "<<endl;
   cout<<"4) Exit"<<endl;
   cout<<"--------------------------------------"<<endl;
    while(1){
      cout<<"\n----------------------"<<endl;
      cout<<"Enter your choice : "<<endl;
      cout<<"----------------------"<<endl;
      cin>>ch;
      
      if (ch==1)
      {
       enQueue();
      }
      else if (ch==2)
      {
        dQueue();
      }
      else if(ch==3) 
      {
          Display();
        }
         else if(ch==4) 
         {
          cout<<"\t\t\t\t\t\t\tExit"<<endl;
          exit(0);
         }
         else{ cout<<"Invalid choice"<<endl;
         }
      
    }
   return 0;
}