#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class Market{
    private:
    string Name;
    int Quantity, Price;
    public:
    Market(){
        Name='\0';
        Quantity=0;
        Price=0;
    }
    void setName(string name){
        Name=name;
    }
    void setQuant(int quantity){
        Quantity=quantity;
    }
    void setPrice(int price){
        Price=price;
    }
    string getName()
    {
        return Name;
    }
    int getQuant()
    {
        return Quantity;
    }
    int getPrice()
    {
        return Price;
    }
};

void addItem(Market m){
    string name;
    int quant, price;
    cout<<"Enter name of item:";
    cin>>name;
    m.setName(name);
    cout<<"Enter Quantity:";
    cin>>quant;
    m.setQuant(quant);
    cout<<"Enter Price:";
    cin>>price;
    m.setPrice(price);
    ofstream out("D:/SuperMarket.txt", ios::app);
    if(!out){
        cout<<"File cannot open!"<<endl;
    }
    else
    {
        out<<m.getName()<<","<<m.getQuant()<<","<<m.getPrice()<<endl;
        cout<<"Item saved successfully!"<<endl;
    }
    out.close();
}
search(Market n){
	string name;
	cout<<"Enter Name of Item:";
	cin>>name;
	ifstream in("D:/SuperMarket.txt");
	if(!in){
		cout<<"File Not found:"<<endl;
	}
	else{
		string line;
		bool found=false;
		while(getline(in,line)){
			int pos=line.find(name);
			if(pos!=string::npos){
				cout<<"Item|Quant|Price"<<endl;
				cout<<line<<endl;
				found=true;
			}
		}
		if(!found){
			cout<<"Item Not Found"<<endl;
		}
	}
};
int main(){
    Market m;
    bool exit=false;
    while(!exit)
    {
      system("cls");
      cout<<"sefa bosraloy "<<endl;
      cout<<"*****************************************"<<endl;
      cout<<"1.Add Items"<<endl;
      cout<<"2.Search Items"<<endl;
      cout<<"3.Exit"<<endl;
      cout<<"Enter Choice:";
      int val;
      cin>>val;
    if(val==1){
      system("cls");
      addItem(m);
      Sleep(10000);
    }
    else if(val==2){
    	system("cls");
    	search(m);
    	Sleep(5000);
	}
	else if(val==3){
		system("cls");
		exit=true;
		cout<<"Good Luck!"<<endl;
		Sleep(3000);
	}
    }
    getch();
}
