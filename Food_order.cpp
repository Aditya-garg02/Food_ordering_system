#include<iostream>
#include<iomanip>
using namespace std;
class Product{
    int id;
    int price;
    string name;
    public:
    Product(){}
    Product(int i,string n, int p){
        id=i;
        name=n;
        price=p;
    }
    int getid(){return id;}
    int getprice(){return price;}
    string getname(){return name;}
    void display(){
        cout<<left<< setw(5)<< id<<setw(20)<<name<<"    Rs."<<price<<endl;
    }
};
class Cart{
    int quant;
    Product prod;
    public:
    Cart(){
        quant=0;
    }
    Cart(Product &p, int q){
        prod=p;
        quant=q;
    }
    double calculatetotal(){return quant*prod.getprice();}
    string get_name(){return prod.getname();}
    int get_id(){return prod.getid();}
    int get_price(){return prod.getprice();}
    void displaycart(){
        cout<<left<<setw(5)<<prod.getid()<<setw(25)<<prod.getname()<<setw(8)<<quant<<"Rs."<<calculatetotal()<<endl;
    }
};
class Order{
    double total=0;
    int count;
    Cart ct[100];
    public:
    Order(){
        total=0;
        count=0;
    }
    void addtocart(Product &p,int q){
        ct[count]=Cart(p,q);
        count++;
        total+=p.getprice()*q;
        cout<<"Product Added Successfully.\n";
    }
    void removefromcart(int id){
        for(int i=0;i<count;i++){
            if(ct[i].get_id()==id){
                total-=ct[i].calculatetotal();
                for(int j=i;j<count;j++){
                    ct[j]=ct[j+1];
                }
                count--;
                cout<<"Product Removed Successfully..\n";
                return;
            }
        }
    }
    void displaycart(){
        if(count==0){
            cout<<"Cart is Empty..\n";
            return;
        }
        cout<<"\nID\tName\tqty\tprice\n";
        for(int i=0;i<count;i++){
            ct[i].displaycart();
        }
        cout<<"Total Amount: Rs."<<total<<endl;
    }
        void checkout()
    {
        if (count == 0)
        {
            cout << "Cart is Empty!\n";
            return;
        }
        cout<<"\n-------------------Itemised Bill---------------------\n";
        cout<<left<<setw(5)<<"ID"
        <<setw(25)<<"Name"
        <<setw(8)<<"Qty"
        <<setw(10)<<"Unit Price"
        <<"  Subtotal"<<endl;
        for(int i=0;i<count;i++){
            cout<<left<<setw(5)<<ct[i].get_id()
            <<setw(25)<<ct[i].get_name()
            <<setw(8)<<ct[i].calculatetotal()/ct[i].get_price()
            <<setw(10)<<ct[i].get_price()
            <<"  Rs."<<ct[i].calculatetotal()<<endl;

        }
        cout<<"\n----------------------------------------------------\n";
        cout << "\nGrand Total: " << total << endl;
         cout<<"\n----------------------------------------------------\n";
         int time=0;
         for(int i=0;i<count;i++){
            if(ct[i].get_id()==1 || ct[i].get_id()==3 || ct[i].get_id()==5){
                time+=5*ct[i].calculatetotal()/ct[i].get_price();
            }
            else{
                time+=10*ct[i].calculatetotal()/ct[i].get_price();
            }
         }
         cout<<"Your Order Will Be Ready In "<<time<<" Minutes.\n";
                 count = 0;
        total = 0;
    }
};
int main(){
    int rest,choice,quantity,id;
    string name;
    Order c;
    Product* r1[5]; // gautom o dine menu
    r1[0]=new Product(1,"pizza",200);
    r1[1]=new Product(2,"malai Chaap",300);
    r1[2]=new Product(3,"pasta",280);
    r1[3]=new Product(4,"hakka Noodles",210);
    r1[4]=new Product(5,"burger",140);
     
    Product* r2[5]; // pyramid
    r2[0]=new Product(1,"paneer pizza",400);
    r2[1]=new Product(2,"sizzler",500);
    r2[2]=new Product(3,"italian sauce pasta",480);
    r2[3]=new Product(4,"chicken kabab",310);
    r2[4]=new Product(5,"dosa",240);

    Product* r3[5]; // indian chimnee
    r3[0]=new Product(1,"chineese platter",400);
    r3[1]=new Product(2,"chaap platter",450);
    r3[2]=new Product(3,"naan and dal makhni",190);
    r3[3]=new Product(4,"paneer fried rice",210);
    r3[4]=new Product(5,"chhole bhature.",140);

    Product* r4[5]; // cafegrills
    r4[0]=new Product(1,"pizza",220);
    r4[1]=new Product(2,"white sauce pasta",180);
    r4[2]=new Product(3,"mushroom duplex",200);
    r4[3]=new Product(4,"paneer tikka",210);
    r4[4]=new Product(5,"paneer roll",150);

    Product* r5[5]; // checkmate
    r5[0]=new Product(1,"veg burger",60);
    r5[1]=new Product(2,"maharaja burger",140);
    r5[2]=new Product(3,"paneer wrap",180);
    r5[3]=new Product(4,"cheese burst pizza",210);
    r5[4]=new Product(5,"paneer tikka",240);

    cout<<"\n==========Restaurants==========\n";
    cout<<"1. Gautom 'O' Dine.\n";
    cout<<"2. Pyramid.\n";
    cout<<"3. Indian Chimnee.\n";
    cout<<"4. Cafe Grills.\n";
    cout<<"5. Checkmate.\n";
    cout<<"Enter Your choice for Restuarant(0-5): ";
    cin>>rest;
    switch(rest){
        case 1: do{
            cout<<"\n=====Gautom 'O' Dine.=====\n";
            cout<<"1.View Menu.\n";
            cout<<"2.Add To Cart.\n";
            cout<<"3.Remove From Cart.\n";
            cout<<"4.View Cart.\n";
            cout<<"5.Checkout.\n";
            cout<<"6.Exit.\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:
                cout<<"\n-----------------Menu-----------------\n";
                cout<<left<<setw(5)<<"ID"<<setw(25)<<"Name"<<"Price"<<endl;
                for(int i=0;i<5;i++){
                    r1[i]->display();
                }
                break;
                case 2:
                cout<<"Enter ID of product: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                for(int i=0;i<5;i++){
                    if(r1[i]->getid()==id){
                        c.addtocart(*r1[i],quantity);
                    }
                }
                break;
                case 3:
                cout<<"Enter ID to remove: ";
                cin>>id;
                c.removefromcart(id);
                break;
                case 4:c.displaycart();
                break;
                case 5:
                c.checkout();
                cout << "Thanks For Your Ordering from Gautom 'O' Dine.\n";
                break;
                case 6:
                cout<<"Exiting..";
                break;
            }
        }while(choice!=6); break;
        case 2:  do{
            cout<<"\n=====Pyramid.=====\n";
            cout<<"1.View Menu.\n";
            cout<<"2.Add To Cart.\n";
            cout<<"3.Remove From Cart.\n";
            cout<<"4.View Cart.\n";
            cout<<"5.Checkout.\n";
            cout<<"6.Exit.\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:          
                     cout<<"\n-----------------Menu-----------------\n";
                cout<<left<<setw(5)<<"ID"<<setw(25)<<"Name"<<"Price"<<endl;
                for(int i=0;i<5;i++){
                    r2[i]->display();
                }
                break;
                case 2:           
                     cout<<"Enter ID of product: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                for(int i=0;i<5;i++){
                    if(r2[i]->getid()==id){
                        c.addtocart(*r2[i],quantity);
                    }
                }
                break;
                case 3:               
                 cout<<"Enter ID to remove: ";
                cin>>id;
                c.removefromcart(id);
                break;
                case 4:
                c.displaycart();
                break;
                case 5:
                c.checkout();
                cout << "Thanks For Your Ordering from Pyramid.\n";
                break;
                case 6:
                cout<<"Exiting...\n";
                break;
            }
        }while(choice!=6); break;
        case 3:  do{
            cout<<"\n=====Indian Chimnee.=====\n";
            cout<<"1.View Menu.\n";
            cout<<"2.Add To Cart.\n";
            cout<<"3.Remove From Cart.\n";
            cout<<"4.View Cart.\n";
            cout<<"5.Checkout.\n";
            cout<<"6.Exit.\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:               
                 cout<<"\n-----------------Menu-----------------\n";
                cout<<left<<setw(5)<<"ID"<<setw(25)<<"Name"<<"Price"<<endl;
                for(int i=0;i<5;i++){
                    r3[i]->display();
                }
                break;
                case 2: cout<<"Enter ID of product: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                for(int i=0;i<5;i++){
                    if(r3[i]->getid()==id){
                        c.addtocart(*r3[i],quantity);
                    }
                } 
                break;
                case 3:    
                cout<<"Enter product name to remove: ";
                cin>>id;
                c.removefromcart(id);
                break;
                case 4:
                c.displaycart();
                break;
                case 5:
                c.checkout();
                cout << "Thanks For Your Ordering from Indian Chimnee.\n";
                break;
                case 6:
                cout<<"Exiting...\n";
                break;
            }
        }while(choice!=6); break;
        case 4:  do{
            cout<<"\n=====Cafe Grills.=====\n";
            cout<<"1.View Menu.\n";
            cout<<"2.Add To Cart.\n";
            cout<<"3.Remove From Cart.\n";
            cout<<"4.View Cart.\n";
            cout<<"5.Checkout.\n";
            cout<<"6.Exit.\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:            
                    cout<<"\n-----------------Menu-----------------\n";
                cout<<left<<setw(5)<<"ID"<<setw(25)<<"Name"<<"Price"<<endl;
                for(int i=0;i<5;i++){
                    r4[i]->display();
                }
                break;
                case 2:   
                 cout<<"Enter ID of product: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                for(int i=0;i<5;i++){
                    if(r4[i]->getid()==id){
                        c.addtocart(*r4[i],quantity);
                    }
                }
                break;
                case 3:cout<<"Enter product name to remove: ";
                cin>>id;
                c.removefromcart(id);
                break;
                case 4:
                c.displaycart();
                break;
                case 5:
                c.checkout();
                cout << "Thanks For Your Ordering from Cafegrills.\n";
                break;
                case 6:
                cout<<"Exiting...\n";
                break;
            }
        }while(choice!=6); break;
        case 5:  do{
            cout<<"\n=====Checkmate.=====\n";
            cout<<"1.View Menu.\n";
            cout<<"2.Add To Cart.\n";
            cout<<"3.Remove From Cart.\n";
            cout<<"4.View Cart.\n";
            cout<<"5.Checkout.\n";
            cout<<"6.Exit.\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
                case 1:  
                 cout<<"\n-----------------Menu-----------------\n";
                cout<<left<<setw(5)<<"ID"<<setw(25)<<"Name"<<"Price"<<endl;
                for(int i=0;i<5;i++){
                    r5[i]->display();
                }
                break;
                case 2:
                cout<<"Enter ID of product: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                for(int i=0;i<5;i++){
                    if(r5[i]->getid()==id){
                        c.addtocart(*r5[i],quantity);
                    }
                }
                break;
                case 3:
                cout<<"Enter product name to remove: ";
                cin>>id;
                c.removefromcart(id);break;
                case 4:
                c.displaycart();
                break;
                case 5:
                c.checkout();
                cout << "Thanks For Your Ordering from Checkmate.\n";
                break;
                case 6:
                cout<<"Exiting...\n";
                break;
            }
        }while(choice!=6); break;
        default: 
        cout<<"invalid choice.\n";
    }
    return 0;
}