#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct Node
{
	string name ;
	long long int phone_number;
	Node *next;
	Node *prev;
};
 class ContactBook
 {
	 Node *head;
	 string x; //storing name
	 long long int y; //storing phone_number
	 public:
	    ContactBook()
		{
			head=NULL;
			x="";
			y=0;

		}
		void CreateNode()
		{
			//for first contact
			if(head==NULL)
			{
				Node *newer=new Node;
				cout<<"Name of contact:";
				cin>>x;
				newer->name=x;

				cout<<"Phone Number:";
				cin>>y;
				newer->phone_number=y;

				newer->next=NULL;
				newer->prev=NULL;
				head=newer;

				cout<<"Contact Added"<<endl;
			}
			else
			{
				Node *newer= new Node;
				cout<<"Name of contact:";
				cin>>x;
				newer->name=x;

				cout<<"Phone Number:";
				cin>>y;
				newer->phone_number=y;

				newer->next=NULL;

				Node *temp=head;
				while (temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newer;
				newer->prev=temp;
				cout<<" Contact Added"<<endl;

			}

		}
	// function for displaying the contacts
		void Display()
		{
			Node *temp=head;
			int count=0;

			if (temp==NULL)
			{
				cout<<"No Contacts... Add some contacts"<<endl;
				cout<<"Thanks"<<endl;
			}
			else
			{
				BubbleSort();
				cout<<"  Name  "<< "     Number: \n"<<endl;
				while(temp!=NULL)
				{
					count++;
					cout<<"  "<<temp->name;
					cout<<"         "<<temp->phone_number<<endl;
					temp=temp->next;
				}
				cout<< " Total contacts: "<<count<<endl;
			}

		}

		void Search()
		{
			bool check=false;
			Node *temp=head;
			cout<<""<<endl;
			cout<<" Press 1 if you want to search by name."<<endl;
			cout<<" Press 2 if you want to search by number."<<endl;
			int command;
			cout<<"Enter the Command:";
			cin>>command;

			if (command==1 && temp!=NULL)
			{
				cout<<"  Enter the name to Search :";
				cin>>x;
				while( temp!=NULL)
				{
					if(temp->name==x)
					{
						cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						check=true;
						break;
					}
					temp=temp->next;
				}
				if(check==false)
				{
					cout<<"  Name Not Found"<<endl;
				}
			}
			else if(command==2)
			{
				cout<<" Enter the number to search :";
				cin>>y;
				while (temp!=NULL)
				{
					if(temp->phone_number==y)
					{
						cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						check=true;
						break;
					}
					temp=temp->next;
				}
				if(check==false)
				{
					cout<<"  Name Not Found"<<endl;
				}
			}

		}
		void DeleteAllContacts()
		{
			Node *temp=head;
			Node *temp2;
			if(head==NULL)
			{
				cout<<"  Contact Book is already empty"<<endl;
				cout<<""<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<"Sucessfully Deleted All Contacts"<<endl;
				cout<<""<<endl;

			}
		}
		void DeleteContactBySearch()
		{
			Node *temp=head;
			cout<<"*"<<endl;
			cout<<" Press 1 if you want to Search by name"<<endl;
			cout<<" Press 2 if you want to search by number."<<endl;
			int command;
			cout<<"Enter the Command:";
			cin>>command;

			if (command==1)
			{
				bool Dcheck=false;
				cout<<" Enter the name to Delete:  ";
				cin>>x;
				while (temp!=NULL)
				{
					if(temp->name==x)
					{
						cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						Dcheck=true;
						break;
					}
					temp=temp->next;
				}
				if(Dcheck==true)
				{
					int command;
					cout<<"Press 1 to Delete the contact:";
					cin>>command;
					if(command==1 & temp==head)
					{
						Node *temp1;
						temp1=temp;
						temp=temp->next;
						delete temp1;

						temp->prev=NULL;
						head=temp;
						cout<<" Contact Deleted Sucessfully"<<endl;
					}
					else if(command==1 & temp->next==NULL)
					{
						temp->prev->next=NULL;
						delete temp;
						cout<<" Contact Deleted Sucessfully "<<endl;
					}
					else if(command==1)
					{
						Node *temp1;
						temp1=temp;
						temp->prev->next=temp1->next;
						temp->next->prev=temp1->prev;
						delete temp1;
						cout<<" Contact Deleted Sucessfully"<<endl;

					}
					else
					{
						cout<<" You enter wrong command ... Try Again"<<endl;
					}
				}
				else if(Dcheck==false)
				{
					cout<<" Contact of this name not found."<<endl;
				}
			}
			else if(command ==2)
			{
				bool Dcheck=false;
				cout<<" Enter tha number to delete: ";
				cin>>y;
				while(temp!=NULL)
				{
					if(temp->phone_number==y)
					{
					    cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						Dcheck=true;
						break;
					}
					temp=temp->next;
				}
				if(Dcheck==true)
				{
					int command;
					cout<<"Press 1 to Delete the contact:";
					cin>>command;
					if(command==1 & temp==head)
					{
						Node *temp1;
						temp1=temp;
						temp=temp->next;
						delete temp1;

						temp->prev=NULL;
						head=temp;
						cout<<" Contact Deleted Sucessfully"<<endl;
					}
					else if(command==1 & temp->next==NULL)
					{
						temp->prev->next=NULL;
						delete temp;
						cout<<" Contact Deleted Sucessfully "<<endl;
					}
					else if(command==1)
					{
						Node *temp1;
						temp1=temp;
						temp->prev->next=temp1->next;
						temp->next->prev=temp1->prev;
						delete temp1;
						cout<<" Contact Deleted Sucessfully"<<endl;

					}
					else
					{
						cout<<" You enter wrong command ... Try Again"<<endl;
					}
				}
				else if(Dcheck==false)
				{
					cout<<" Contact of this name is not found."<<endl;
				}

			}
			else
			{
				cout<<" You enter wrong Command"<<endl;
			}

		}

		void BubbleSort()
		{
			Node *temp=head;
			Node *i,*j;
			string n;
			long long int n2;
			if (temp=NULL)
			{
				cout<<" Empty contact book "<<endl;
			}
			else
			{
				for(i=head;i->next!=NULL;i=i->next)
				{
					for(j=i->next;j!=NULL;j=j->next)
					{
						if(i->name > j->name)
						{
							//swaping of name
							n=i->name;
							i->name=j->name;
							j->name=n;

							n2=i->phone_number;
							i->phone_number=j->phone_number;
							j->phone_number=n2;
						}
					}
				}
			}
		}

		void EditContacts()
		{
			Node *temp=head;
			cout<<""<<endl;
			cout<<" Press 1 if you want to Search by name"<<endl;
			cout<<" Press 2 if you want to search by number."<<endl;
			int Ecommand;
			cout<<"Enter the Command:";
			cin>>Ecommand;

			if (Ecommand==1)
			{
				bool Echeck=false;
				cout<<" Enter the name to Edit:  ";
				cin>>x;
				while (temp!=NULL)
				{
					if(temp->name==x)
					{
						cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						Echeck=true;
						break;
					}
					temp=temp->next;
				}
				if (Echeck==true)
				{
					int command;
					cout<<" Press 1 to edit the Contact: ";
					cin>>command;
					if(command==1)
					{
						cout<<"Enter New Name:";
						cin>>x;
						cout<<"Enter new Number";
						cin>>y;

						temp->name=x;
						temp->phone_number=y;

						cout<<"Contact Edited Sucessfully"<<endl;
					}
					else
					{
						cout<<" You enter wrong command... Try Again"<<endl;
					}
				}
				else if(Echeck==false)
				{
					cout<<" Contact Not Found"<<endl;
				}

			}
			else if(Ecommand==2)
			{
				bool Echeck=false;
				cout<<" Enter the number to Edit:  ";
				cin>>y;
				while (temp!=NULL)
				{
					if(temp->phone_number==y)
					{
						cout<<""<<endl;
						cout<<"  Name : "<<temp->name<<endl;
						cout<<"  Phone Number: "<<temp->phone_number<<endl;
						cout<<""<<endl;
						Echeck=true;
						break;
					}
					temp=temp->next;
				}
				if(Echeck==true)
				{
					int command;
					cout<<"Press 1 to edit the Contact";
					cin>>command;
					if(command==1)
					{
						cout<<" Enter New Name:";
						cin>>x;
						cout<<" Enter New Number:";
						cin>>y;

						temp->name=x;
						temp->phone_number=y;

						cout<<" Contact Edited Sucessfully"<<endl;
					}
					else
					{
						cout<<" You Enter Wrong Command"<<endl;
					}
				}
				else if(Echeck==false)
				{
					cout<<"  There is no contact os this number."<<endl;
				}
			}
			else
			{
				cout<<" You Enter Wrong Command... Try Again"<<endl;
			}
		}

		void OfflineSave()
		{
			Node *temp=head;
			ofstream myfile("contactbook.txt");
			if (myfile.is_open())
			{
				while(temp!=NULL)
				{
					myfile<<temp->name<<"  "<<temp->phone_number<<endl;;
					//myfile<<temp->phone_number<<endl;
					temp=temp->next;
				}
				myfile.close();
				Structure();
			}
			else
			{
				cout<<" Thanks File is empty."<<endl;
			}

		}

		void reopenCB()
		{
			bool isEmpty;
			ifstream myfile("contactbook.txt");
			if(myfile.is_open() & myfile.peek()!=EOF)
			{
				int i=0;
				while(getline(myfile,x))
				{
					if (i%2==0)
					{
						if(head==NULL)
						{
							Node *newer=new Node;
							newer->name=x;

							newer->next=NULL;
							newer->prev=NULL;
							head=newer;

						}
						else
						{
							Node *newer =new Node;

							newer->name=x;
							newer->next=NULL;

							Node *temp=head;
							while(temp->next!=NULL)
							{
								temp=temp->next;
							}
							temp->next=newer;
							newer->prev=temp;
						}
					}
					else
					{
						Node *temp=head;
						if(temp->phone_number==0)
						{

							stringstream convert(x);
							convert>>y;
							temp->phone_number=y;
						}
						else
						{
							Node *temp=head;
							while(temp->next!=NULL)
							{
								temp=temp->next;
							}
							 stringstream convert(x);
							 convert>>y;
							 temp->phone_number=y;
						}
					}
					i++;
				}
				myfile.close();

			}
			else
			{
				cout<<" File is empty so can not open...Sorry"<<endl;
			}
		}

		void Structure()
		{
			cout<<""<<endl;;
			cout<<" 1. Add Contact"<<endl;
			cout<<" 2. Edit the contact"<<endl;
			cout<<" 3. Delete Contact"<<endl;
			cout<<" 4. Search Contact"<<endl;
			cout<<" 5. Display All Contact"<<endl;
			cout<<" 6. Delete All Contact"<<endl;
			cout<<""<<endl;

			int Scommand;
			cout<<" Enter the Command: ";
			cin>>Scommand;

			try
			{
				if(Scommand>=1 && Scommand<=6)
				{
					if(Scommand==1)
					{
						CreateNode();
						OfflineSave();
						Structure();
					}
					else if(Scommand==2)
					{
					    EditContacts();
                        OfflineSave();
						Structure();
					}
					else if(Scommand==3)
					{
					    DeleteContactBySearch();
						Structure();
					}
					else if(Scommand==4)
					{
					    Search();
						Structure();
					}
					else if(Scommand==5)
					{
					    Display();
                        OfflineSave();
						Structure();
					}
					else if(Scommand==6)
					{
					    DeleteAllContacts();
                        OfflineSave();
						Structure();
					}
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<" You Enter Wrong Command... Run the code Again" <<endl;
				Structure();
			}

		}


 } ;

 int main()
 {
	 ContactBook cb;
	 //cb.reopenCB();
	 string n;
	 cout<<" What is your name: ";
	 cin>>n;

	 cout<<""<<endl;;
	 cout<<" "<<n<<" Welcome To ContactBook   "<<endl;
	 cout<<""<<endl;;
	 cb.Structure();
	 return 0;
}