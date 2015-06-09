#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class product
{
	public:
		char name[30];
		int price;
		int pid;
		int quantity;
		int cid;
		void getdata()
		{
			cout<<"Enter name: ";cin>>name;
			cout<<"Enter price: ";cin>>price;
			cout<<"Enter pid: ";cin>>pid;
			cout<<"Enter Quantity: ";cin>>quantity;
			cout<<"Enter Category ID:(1 FOR ELECTRONICS,2 FOR TOILETRY,3 FOR CLOTHS,4 FOR SHOES.";cin>>cid;
		}
		void display()
		{
			cout<<"\nName Of the product: "<<name;
			cout<<"\nPrice(MRP): "<<price;
			cout<<"\nProdut ID: "<<pid;
			cout<<"\nQuantities remaining: "<<quantity;
		    cout<<"\nCategory ID: "<<cid<<"\n\n";
		}
		void modify()
		{
				cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------------------------------------";
			cout<<"\nName Of the product: "<<name;
			cout<<"\nPrice(MRP): "<<price;
			cout<<"\nProdut ID: "<<pid;
			cout<<"\nQuantities remaining: "<<quantity;
			cout<<"\nCategory Id: "<<cid;
			cout<<"\n\nEnter new details: ";
			char name1[20]="";
			int p,pid1,q,cid1;
			cout<<"\n\nNew name:(Enter '.' to retain old one).";
			cin>>name1;
			cout<<"\n\nNew price(MRP):(Enter -1 to retain old one).";
			cin>>p;
			cout<<"\n\nNew Product Id:(Enter -1 to retain old one).";
			cin>>pid1;
			cout<<"\n\nNew Quantities Remaining:(Enter -1 to retain old one).";
			cin>>q;
			cout<<"\n\nNew Category ID:(Enter -1 to retain old one).";
			cin>>cid1;
			if(strcmp(name1,".")!=0)
			strcpy(name,name1);
			if(p!=-1)price=p;
			if(pid1!=-1)pid=pid1;
			if(q!=-1)quantity=q;
			if(cid1!=-1)cid=cid1;
			
		}
		int getpid()
		{
			return pid;
		}
		string getname()
		{
			
			return string(name);
		}
		int getp()
		{
			return price;
		}
		int getcid()
		{
			return cid;
		}
}obj,ob,s1;
class User 
{
public:
    string username;
    string password;
    string inputUsername;
    string inputPassword;
    
    // User registration
    void urd()
    {

        ofstream usersFile ("userData.txt");

        if (	!usersFile.is_open())
        {
            usersFile.open("userData.txt");
        }

            usersFile << username << " " << password << endl;

            usersFile.close();
    }

    // Initialize user registration
    void ur()
    {
        cout << "Welcome!\n-------------------------\n\nPlease register.\nEnter a new username:\n";
        cin >> username;

        cout << "\nPlease enter a new password:\n";
        cin >> password;

        urd();
    }

    // User login function
    int login()
    {
        cout << "\nPlease enter your username:\n";
        cin >> inputUsername;

        cout << "\nPlease enter your password:\n";
        cin >> inputPassword;

        string userAndPass = inputUsername + " " + inputPassword; // Search pattern
        int offset; 
        string line;
        ifstream usersFile;
        usersFile.open ("userData.txt");

         bool found = false;
       
	   
	   if(usersFile.is_open()) 
	   {
          while(getline(usersFile,line) && !found) 
		  {
              if (line.compare(userAndPass) == 0) 
			  { //match strings exactly!
                  found = true; // found is true => break loop
              }
          }
	      usersFile.close(); //close the file before recursivly opening it again later
	      if(found) 
		  {
		  	  
		   cout << "\n\nWelcome "<< inputUsername;
		   ifstream filin;
		   filin.open("pro.txt");
		   if(filin.good())
		   {
		   	filin.close();
		   fstream filin;
		   filin.open("pro.txt",ios::in|ios::out|ios::app);
		   	int t=0;
		   		cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------------------------------------";
		   	cout<<"\n\nThe product list is already here.\n\nChoose from the options.";
		   	cout<<"\n\n1.SEE THE LIST.\n\n2.ADD MORE.\n\n3.MODIFY ITEM.\n\n4.DELETE ITEM.\n\nCHOICE: ";
		   	int ch2;
		   	cin>>ch2;
		   	if(ch2==1)
			{
		    while(!filin.eof())
		    {
		   	filin.read((char *)&obj,sizeof(obj));
		   	if(filin.eof())break;
		   	obj.display();
		    }	
		    cout<<"\n\nPress ENTER to go back to the main menu!!";
		    filin.close();
		    getch();
		    return 5;
	        }
	        else if(ch2==2)
			{
				int flag=1;
		   while(flag==1)
		   {
		   	flag==0;
		   	cout<<"\nPlease enter the details of the new product(It will be added in the stack).";
		   	obj.getdata();
		   	filin.write((char*)& obj,sizeof(obj));
		   	cout<<"\n\nDo you want to enter more products.";
			   cout<<"\n1.Yes\n2.No.";
			   int cho;
			   cout<<"\nChoice: ";cin>>cho;
			   if(cho==1)
			   {
			   	flag=1;
			   }
			   else
			   return 5;
			}
			cout<<"\n\nPress y if you want to see the list else press any key.";
			char ch;
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
			   filin.seekg(0);
			   cout<<"\nData are:";
			   while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	obj.display();
               }
           }
			   filin.close();
	        }
	        else if(ch2==3)
	        {
	        filin.close();
	        fstream filin;
	        filin.open("pro.txt",ios::in|ios::out|ios::ate);
	        	cout<<"Please enter the PRODUCT ID of the product.";
	        	int pd;
	        	cin>>pd;
	        	char fo='f';long pos;
	        	filin.seekg(0);
	        	while(!filin.eof())
	        	{
	        		pos=filin.tellg();
	        		filin.read((char *)&ob,sizeof(ob));
	        		if(ob.getpid()==pd)
	        		{
	        			ob.modify();
	        			filin.seekg(pos);
	        			filin.write((char *)&ob,sizeof(ob));
	        			fo='t';
	        			break;
	        		}
	        	}
	        
				
				cout<<"\nThe list contains: ";
				filin.seekg(0);
				while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	obj.display();
               }
               filin.close();
               cout<<"\n\nChoose from the options:\n\n1.MAIN MENU\n\n2.EXIT. ";
               int ch4;
               cin>>ch4;
               if(ch4==1)
               return 5;
               else
               {
               exit(0);
           }
	        	}
	        	else if(ch2==4)
	        	{
	        		filin.close();
	        		ifstream filin("pro.txt");
	        		ofstream filo("temp.txt");
	        		int pdd;char found='f',confirm='n';
	        		cout<<"\n\nPlease enter the product ID which you want to delete.";
	        		cin>>pdd;
	        		filin.seekg(0);
	        		while(!filin.eof())
	        		{
	        			filin.read((char *)&s1,sizeof(s1));
	        			if(filin.eof())break;
	        			if(s1.getpid()==pdd)
	        			{
	        				s1.display();
	        				found='t';
	        				cout<<"\nAre you sure,you want to delete this record?(y/n)..";
	        				cin>>confirm;
	        				if(confirm=='n')
	        				filo.write((char *)&s1,sizeof(s1));
	        			}
	        			else
	        			filo.write((char *)&s1,sizeof(s1));
	        		}
	        		if(found=='f')
	        		cout<<"Record not found!!\n";
	        		filin.close();
	        		filo.close();
	        		remove("pro.txt");
	        		rename("temp.txt","pro.txt");
	        		filin.open("pro.txt");
	        		cout<<"\nNow the file contains";
	        		filin.seekg(0);
	        		while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	obj.display();
               }
               filin.close();
               cout<<"\n\nChoose from the options:\n\n1.MAIN MENU\n\n2.EXIT. ";
               int ch4;
               cin>>ch4;
               if(ch4==1)
               return 5;
               else
               exit(0);
	        	}
		   }
		   else
		   {
		   	filin.close();
		   	 fstream filin;
		   filin.open("pro.txt",ios::in|ios::out|ios::app);
		   	int flag=1;
		   	cout<<"\nSir there are no products in out store.\n";
		   while(flag==1)
		   {
		   	flag==0;
		   	
		   	cout<<"\nPlease enter the details of the product.";
		   	obj.getdata();
		   	filin.write((char*)& obj,sizeof(obj));
		   	cout<<"\n\nDo you want to enter more products.";
			   cout<<"\n1.Yes\n2.No.";
			   int cho;
			   cout<<"\nChoice: ";cin>>cho;
			   if(cho==1)
			   {
			   	flag=1;
			   }
			   else
			   flag=0;
			}
			   filin.seekg(0);
			   cout<<"\n\nPress y if you want to see the list else press any key.";
			char ch;
			cin>>ch;
			if(ch=='y'||ch=='Y')
			{
			   cout<<"\nData are:";
			   while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	obj.display();
               }
           }
			   filin.close();
		   }
		 
		   }
	      
	      else 
		  {
	     	cout << "\nUsername and/or password incorrect!\n\n\n\n";
	    	cout<<"Would You like to go to the main menu or you want to try again the USERNAME and PASSWORD.";
	     	cout<<"\n1.Main menu.\n2.Try again.";
	    	int fg;
	    	cout<<"\nCHOICE: ";
	    	cin>>fg;
	    	if(fg==1)
	    	{
	    		return 5;
	    	}
	    	else if(fg==2)
	    	{
	    	login();
	        }
	      }
       }
        
        
		else
            cout << "Unable to open userData.txt file." << endl;
    }

};

// Main program
int main() 
{
	int mainm=1,ch,pricev[50],iv=0;
	string namev[50];
	while(mainm==1)
	{
		mainm=0;
	cout<<"\n\nWelcome to ONKART.(An initiative by the founders Shubham and Pranavi)";
	cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n\nPlease select one of the choices: ";
	cout<<"\n\n1.Manager.\n\n2.Customer.\n\n3.Exit";
		cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\nCHOICE: ";
	cin>>ch;
	if(ch==1)
	{
    User user1;
    ifstream usersFile("userData.txt");
    if (usersFile.good())
    {
    		cout<<"\n-------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------------------------------------";
        cout << "\n\nWelcome SIR!! Please enter Username and password for verification.\n\n";
        	
    }
    else 
	{
        user1.ur();
    }
    if(usersFile.is_open())
    {
    int k=user1.login();
            if(k==5)
            mainm=1;
    }
    }
    else if(ch==2)
    {
    	int fifla=1;
    	while(fifla==1)
    	{
    	cout<<"\n------------------------------------------------------------------------------";
    	cout<<"\n                             WELCOME TO ONKART.";
    	cout<<"\n------------------------------------------------------------------------------";
        cout<<"\nPlease tell us what do you want to do: ";
        cout<<"\n\n1.SEE THE CATEGORIES TO BUY FROM.";
        	cout<<"\n\n2.SORT THE PRODUCT.";
        	cout<<"\n\n3.CHECKOUT.";
        	int co;
        	cout<<"\n\nCHOICE: ";
        	cin>>co;
        	if(co==1)
        	{
        	 ifstream filin;
		     filin.open("pro.txt");
		      if(filin.good())
		      {
		   	   filin.close();
		   	   int fla=1;
		       
		   	   while(fla==1)
		       {
		       fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
		       
			   cout<<"\n\nPlease choose from the categories.";
		       cout<<"\n\n1.ELECTRONICS.\n\n2.TOILETRY.\n\n3.CLOTHES.\n\n4.SHOES.\n\nCHOICE: ";
		       int cat;
		       cin>>cat;
		       
		       while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	if(obj.getcid()==cat)
			   	obj.display();
              }
              cout<<"\n\nDo you want to add any product in your cart??\n\n1.Yes\n\n2.No\n\nChoice: ";
              int ch6;
              cin>>ch6;
              if(ch6==1)
              {
              	int flag5=1;
              	while(flag5==1)
              	{
				  filin.close();
				      fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
              	cout<<"\n\nPlease enter the product ID>";
              	int pad;
              	cin>>pad;
              	
              	while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	if(obj.getpid()==pad)
			   	{
			   		namev[iv]=obj.getname();
			   		pricev[iv]=obj.getp();
			   		++iv;
			   	}
			   	
              }
              cout<<"\n\nDo you want to add another product(1/0)";
              int addan;
              cin>>addan;
              if(addan==1)
			  flag5=1;
              if(addan==0)
			  flag5=0;
              }
              fla=0;	
          }
          else if(ch6==2)
          {
               cout<<"\n\nDo you want to see from another category??\n\n1.Yes\n\n2.No\n\nCHOICE: ";
               int ch5;
               cin>>ch5;
               if(ch5==1)
               {
			   fla=1;
		       }
               else
			   { 
			   fla=0;
		       }
		   }
		       filin.close();
		       }
		       
	          }
	          else
	          {
		    cout<<"\n\nSorry!!! There are no products in our store.";
		    cout<<"\n\nVery Very sorry for inconvienenece.";
		    cout<<"\n\nWe are exiting.";
		    filin.close();
		    exit(0);
	          }
        	}
        	else if(co==2)
        	{
        		int arr[50],io;
        		 ifstream filin;
		     filin.open("pro.txt");
		      if(filin.good())
		      {
		   	   filin.close();
		   	   int flat=1;
		       
		   	   while(flat==1)
		       {
		       	io=0;
		       fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
		       
			   cout<<"\n\nPlease choose from the categories.";
		       cout<<"\n\n1.ELECTRONICS.\n\n2.TOILETRY.\n\n3.CLOTHES.\n\n4.SHOES.\n\nCHOICE: ";
		       int cat;
		       cin>>cat;
		       
		       while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	if(obj.getcid()==cat)
			   	{
			   	arr[io]=obj.getp();
			   	++io;
			   }
              }
              int t=0;
               for(int i=0;i<io;i++)
			   {// Number of passes (n-1)
                  for(int j=i+1;j<io;j++)
				  { // Iterations during each pass
                      if(arr[i]>arr[j]) // Comparison during iteration
                      {
                           t=arr[i];    // Swapping
                           arr[i]=arr[j];
                           arr[j]=t;
                      }
                  }
                  }
                  for(int k=0;k<io;k++)
                  cout<<arr[k]<<",";
                      cout<<"\nIn which way you would like to sort the list of this category: ";
                      cout<<"\n\n1.Insing order of price.";
                      cout<<"\n\n2.Decreasing order of price.";
                      int ch7;
                      cin>>ch7;
                      if(ch7==1)
                      {
                      	filin.close();
                      	
					  for(int i=0;i<io;i++)
              {
              	fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
              	while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	int pp=obj.getp();
			   	if(pp==arr[i])
			   	{
			   	obj.display();
			   }
              }
              filin.close();
              }
              fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
          }
          else if(ch7==2)
          {
          	
                      	filin.close();
                      	
          	int io1=io-1;
          	
          	for(int i=io1;i>=0;i--)
              {
              fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
              	while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	if(obj.getp()==arr[i])
			   	{
			   	obj.display();
			   }
              }
              filin.close();
              }
              fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
          }
          
          cout<<"\n\nDo you want to add any product in your cart??\n\n1.Yes\n\n2.No\n\nChoice: ";
              int ch16;
              cin>>ch16;
              if(ch16==1)
              {
              	int flag15=1;
              	while(flag15==1)
              	{
              		filin.close();
				      fstream filin;
		       filin.open("pro.txt",ios::in|ios::out|ios::app);
              	cout<<"\n\nPlease enter the product ID>";
              	int pad;
              	cin>>pad;
              	while(!filin.eof())
			   {
			   	filin.read((char *)& obj,sizeof(obj));
			   	if(filin.eof())break;
			   	if(obj.getpid()==pad)
			   	{
			   		namev[iv]=obj.getname();
			   		pricev[iv]=obj.getp();
			   		++iv;
			   	}
			   	
              }
              cout<<"\n\nDo you want to add another product(1/0)";
              int adan;
              cin>>adan;
              if(adan==1)
              {
			  flag15=1;
		}
              else if(adan==0)
			  {
			  flag15=0;
		}
              }
              	flat=0;
          }
          else if(ch16==2)
          {
               cout<<"\n\nDo you want to see from another category??\n\n1.Yes\n\n2.No\n\nCHOICE: ";
               int ch5;
               cin>>ch5;
               if(ch5==1)
               {
			   flat=1;
		       }
               else
			   { 
			   flat=0;
		       }
		   }
		   filin.close();
	
}
      }
      else
	          {
		    cout<<"\n\nSorry!!! There are no products in our store.";
		    cout<<"\n\nVery Very sorry for inconvienenece.";
		    cout<<"\n\nWe are exiting.";
		    filin.close();
		    exit(0);
	          }
	          
        	}
        	if(co==3)
        	{
        		cout<<"\nYour cart contains :";
        		for(int i=0;i<iv;i++)
        		{
        			cout<<"\nItem name: "<<namev[i];
        			cout<<"\nPrice: "<<pricev[i]<<"\n";
        		}
        		int sum=0;
        		for(int i=0;i<iv;i++)
        		sum=sum+pricev[i];
        		cout<<"\nYour totall price is : "<<sum;
        		cout<<"\n\nThank you for visiting our store please do visit us again.";
        		getch();
        		exit(0);
        	}
        }
	}
    else if(ch==3)
    {
    	cout<<"\nThanks for using our serivices. VISIT AGAIN.";
    	getch();
    	exit(0);
    }
    }
    getch();
}

