 #include<iostream>
 #include<conio.h>

 using namespace std;

void teacherData();
void studentData();
void classRecord();
void grade()


 int main(){
    int number;
    cout<<"Welcome to the LMS "<<endl;
    cout<<"enter 1 for teacherData "<<endl;
    cout<<"Enter 2 for the StudentData "<<endl;
    cout<<"Enter 3 for the Class Data"<<endl;
    cout<<"Enter 4 for the grade of class"<<endl;
    cin>>number;
    while (true)
    {
        if(number==1){
            teacherData()
        }
        else if(number==2){
            studentData()
        }
        else if (number==3)
        {
            classRecord()
        }
        else if(number==4){
            grade()
        }
        else{
            cout<<"invalid Number";
            break;
        }
    }
    

 }