#include<iostream>
using namespace std;
struct Patient {
    int ID;
    char name[50];
    int amount;
    struct DocInfo{
        char DocName[50];
        char Spec[50];
    } doc;
};
void displayPatient(Patient& p){
    cout<<"==============================="<<endl;
    cout<<"  ID         : "<<p.ID<<endl;
    cout<<"  Name       : "<<p.name<<endl;
    cout<<"  Bill (Rs)  : "<<p.amount<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"  Doctor     : "<<p.doc.DocName<<endl;
    cout<<"  Specialization : "<<p.doc.Spec<<endl;
    cout<<"==============================="<<endl;
}
Patient* searchP(Patient* p, int id, int size){
    for(int i=0; i<size; i++){
        if((p+i)->ID == id){
            cout<<"-------------------------------"<<endl;
            cout<<"   Enter New Doctor Details    "<<endl;
            cout<<"-------------------------------"<<endl;
            cout<<"  Doctor Name      : "; cin>> (p+i)->doc.DocName;
            cout<<"  Specialization   : "; cin>> (p+i)->doc.Spec;
            cout<<"-------------------------------"<<endl;
            return (p+i);
        }
    }
    cout<<"==============================="<<endl;
    cout<<"      Patient Not Found!       "<<endl;
    cout<<"==============================="<<endl;
    return NULL;
}
int main(){
    cout<<"======================================="<<endl;
    cout<<"   Welcome to Sental Hospital System   "<<endl;
    cout<<"======================================="<<endl<<endl;
    int n;
    cout<<"  Enter Number of Patients : "; cin>>n;
    Patient* p = new Patient[n];
    for(int i=0; i<n; i++){
        cout<<endl<<"==============================="<<endl;
        cout<<"       Patient "<<i+1<<" Details        "<<endl;
        cout<<"==============================="<<endl;
        cout<<"  Patient ID       : "; cin>>(p+i)->ID;
        cout<<"  Patient Name     : "; cin>>(p+i)->name;
        cout<<"  Bill Amount (Rs) : "; cin>>(p+i)->amount;
        cout<<"-------------------------------"<<endl;
        cout<<"     Doctor Information        "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"  Doctor Name      : "; cin>>(p+i)->doc.DocName;
        cout<<"  Specialization   : "; cin>>(p+i)->doc.Spec;
        cout<<"==============================="<<endl;
    }
    int choice;
    do{
        cout<<endl<<"======================================="<<endl;
        cout<<"              MENU                     "<<endl;
        cout<<"======================================="<<endl;
        cout<<"1. Display All Patients"<<endl;
        cout<<"2. Update Doctor Info"<<endl;
        cout<<"3. Search Patient"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice == 1){
            for(int i=0; i<n; i++){
                displayPatient(p[i]);
            }
        }
        else if(choice == 2){
            int id;
            cout<<"Enter Patient ID: ";
            cin>>id;
            Patient* updP = searchP(p, id, n);
            if(updP != NULL){
                cout<<"Updated Record:"<<endl;
                displayPatient(*updP);
            }
        }
        else if(choice == 3){
            int id;
            cout<<"Enter Patient ID: ";
            cin>>id;
            bool found = false;
            for(int i=0; i<n; i++){
                if((p+i)->ID == id){
                    displayPatient(p[i]);
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Patient Not Found!"<<endl;
            }
        }
    }
    while(choice != 4);
    delete[] p;
    return 0;
}
