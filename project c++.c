#include<iostream>
#include<cstdio>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include<string>
using namespace std;
// Start
int contact_count = 0;
int message_count = 0;
int message_sent = 0;
int note_count=0;

class Contacts
{
public:
    string name[100];
    string No[100];
} contact;

class Message : public Contacts
{
public:
    string name[100];
    string number[100];
    string text[100];
} message,sent,saved;

class Notes
{
public:
    string title[100];
    string body[100];
    string date[100];
    string place[100];
} note;


class claculator
{
public:
    int add(int x,int y)
    {
        int ans=x+y;
        return ans;
    }
    int sub(int x,int y)
    {
        int ans=x-y;
        return ans;
    }
    int multi(int x,int y)
    {
        int ans=x*y;
        return ans;
    }
    int divi(float x,float y)
    {
        float ans=x/y;
        return ans;
    }
    int area(float x,float y)
    {
        float area= .5*x*y;
        return area;
    }

} calc;
int initialize_messages()
{
    message.name[0] = "Adif";
    message.number[0] = "19203040";
    message.text[0] = "Hello everyone!!";
    message.name[1] = "Puja";
    message.number[1] = "19203033";
    message.text[1] = "This is a Message";
    message.name[2] = "Senthia";
    message.number[2] = "19203046";
    message.text[2] = "How you doin?";
     message.name[3] = "Puja";
    message.number[3] = "19203033";
    message.text[3] = "This is a Message";
     message.name[4] = "Puja";
    message.number[4] = "19203033";
    message.text[4] = "This is a Message";
    message_count = 5;
}
int initialize_contacts()
{
    contact.name[0] = "Adif";
    contact.No[0] = "19203040";
    contact.name[1] = "Puja";
    contact.No[1] = "19203033";
    contact.name[2] = "Senthia";
    contact.No[2] = "19203046";
    contact_count = 3;
}

int initialize_notes()
{
    note.title [0]= "Note 1";
    note.body[0] = "This is note 1";
    note.place[0] = "Dhaka";
    note.date[0] = "12-3-2020";

    note.title[1] = "Note 2";
    note.body[1] = "This is another note";
    note.place[1] = "Bagerhat";
    note.date[1] = "23-4-2020";

    note_count = 2;

}

int message_menu()
{

    for(;;)
    {
        system("cls");
        int input;
        cout << "View Messages \t\t Enter 1" << endl;
        cout << "Send Messages \t\t Enter 2" << endl;
        cout << "Search Messages \t Enter 3" << endl;
        cout << "Delete Messages \t Enter 4" << endl;
        cout << "View Saved Messages \t Enter 5" << endl;
        cout << "Go Back \t\t Enter 0" << endl;
        cin >> input;
        if (input == 1) //View Message
        {
            cout << "Messages in Inbox: " << endl;
            for(int i=0; i<message_count; i++)
            {
                cout<< message.name[i]<<endl;
                cout<< message.number[i]<<endl;
                cout<< message.text[i]<<endl << endl;
            }
            cout << "Messages in Sent: " << endl;
            for(int i=0; i<message_sent; i++)
            {
                cout<< sent.name[i]<<endl;
                cout<< sent.number[i]<<endl;
                cout<< sent.text[i]<<endl << endl;
            }
            getch();
        }
        else if (input == 2) //Send Message
        {
            string cname, cnum;
            int ch = 0;
            cout <<"--------- Send Message -------------" <<endl << endl;
            cout << "Enter Contact Name:" ;
            cin >> cname;
            cout << "Enter Contact number: " ;
            cin >> cnum;
            for(int i=0; i<contact_count; i++)
            {
                if(cname == message.name[i] && cnum == message.number[i])
                {
                    sent.name[message_sent] = cname;
                    sent.number[message_sent] = cnum;
                    cout <<"Enter Message: " << endl;
                    getchar();
                    getline(cin, sent.text[message_sent]) ;
                    message_sent++ ;
                    ch = 1;
                    break;
                }
            }
            if (ch == 0)
            {

                cout << "This contact does not exist!" ;
                getch();
            }
        }
        else if (input == 3)
        {
            string c;
            int count = 1;
            cout <<"--------- Search Message -------------" <<endl << endl;
            cout <<"Enter contact name: " << endl;
            cin >> c;
            for(int i=0; i<message_count; i++)
            {
                if (c == message.name[i])
                {
                    cout <<endl << message.name[i] << endl;
                    cout << message.number[i] << endl<<endl;
                    for(int i=0; i<message_count; i++)
                    {
                        if (c == message.name[i])
                        {
                            cout <<"Message " <<count <<": " << message.text[i] << endl;
                            count++;
                        }
                    }
                    getch();
                    break;
                }
            }
        }
        else if (input == 4)
        {
            cout << "This option is incomplete!!";
            getch();
        }
        else if (input == 5)
        {
            cout << "This option is incomplete!!";
            getch();
        }
        else
        {
            break;
        }
    }
}

int contact_menu()
{
    for(;;)
    {
        system("cls");
        int input;
        cout << "View Contacts \t Enter 1" << endl;
        cout << "Search Contacts \t Enter 2" << endl;
        cout << "Delete Contacts \t Enter 3" << endl;
        cout << "Edit Contact \t Enter 4" << endl;
        cout << "Go Back \t\t Enter 0" << endl;
        cin >> input;
        if (input == 1) //View Contacts
        {
            cout << "--------- View Contacts -------------" <<endl << endl;
            for(int i=0; i<contact_count; i++)
            {
                cout<< contact.name[i]<<endl;
                cout<< contact.No[i]<<endl;
            }
            getch();
        }
        else if (input == 2)
        {
            string c;
            cout <<"--------- Search Contact -------------" <<endl << endl;
            cout <<"Enter contact name: " << endl;
            cin >> c;
            for(int i=0; i<contact_count; i++)
            {
                if (c == contact.name[i])
                {
                    cout <<endl << contact.name[i] << endl;
                    cout << contact.No[i] << endl<<endl;
                    getch();
                    break;
                }
            }
        }
        else if (input == 3)
        {
            cout << "This option is incomplete!!";
            getch();
        }
        else if (input == 4)
        {
            string cname, cnum;
            int  opt;
            int ch = 0;
            cout <<"--------- Edit Contact -------------" <<endl << endl;
            cout << "Enter Contact Name:" ;
            cin >> cname;
            cout << "Enter Contact number: " ;
            cin >> cnum;
            for(int i=0; i<contact_count; i++)
            {
                if(cname == contact.name[i] && cnum == contact.No[i])
                {
                    cout << "Edit Name (1) or Edit Number (2) " << endl;
                    cin >> opt;

                    if (opt == 1)
                    {
                        cout << "Enter new name for this contact:" << endl;
                        cin >> contact.name[i];
                        ch = 1;
                        break;
                    }
                    else if (opt == 2)
                    {
                        cout << "Enter new number for this contact:" << endl;
                        cin >> contact.No[i];
                        ch = 1;
                        break;
                    }
                }
            }
            if (ch == 0)
            {

                cout << "This contact does not exist!" ;
                getch();
            }
        }
            else
            {
                break;
            }
    }
}

int notes_menu()
{
    int c;
    for(; ;)
    {
        system("cls");
        cout << "\n\n\t\tmain menu " << endl;
        cout << "\n\n\t\tAdd note \t[1]" << endl;
        cout << "\n\n\t\t View note \t[2]" << endl;
        cout << "\n\n\t\t Edit note\t[3]" << endl;
        cout << "\n\t\t Go Back\t[0]" << endl;

        cout << "\n\n\tEnter your choice :";
        cin >> c;
        if(c==1)
        {
            getchar();
            cout<<"Enter Title : ";
            getline(cin, note.title[note_count]);
            cout<<"Add note : \n";
            getline(cin, note.body[note_count]);
            cout<<"Enter Date : ";
            getline(cin,note.date[note_count]);
            cout<<"enter place : ";
            getline(cin, note.place[note_count]);


            note_count++;

        }
        else if (c == 2)
        {
            for(int i=0; i< note_count; i++)
            {
                cout << note.title[i] << endl;
                cout << note.body[i] << endl;
                cout<<note.date[i] << endl;
                cout<< note.place[i] << endl <<endl;
            }
            getch();
        }
        else if (c == 3)
        {
            string n;
            int opt, ch = 0;
            cout <<"--------- Edit Notes -------------" <<endl << endl;
            cout << "Enter Note Title:" ;
            cin >> n;
            for(int i=0; i< note_count; i++)
            {
                if(n == note.title[i])
                {
                    cout << "Title : " << note.title[i] << endl;
                    cout << "Body : " << note.body[i] << endl;
                    cout << "Date : " << note.date[i] << endl;
                    cout << "Place : " << note.place[i] << endl;

                    cout << "Edit Title (1) \n Edit Body (2) \n Edit Date (3) \n Edit Place (4)" << endl;
                    cin >> opt;

                    if (opt == 1)
                    {
                        cout << "Enter new title for this note:" << endl;
                        getchar();
                        getline(cin, note.title[i]);
                        ch = 1;
                        break;
                    }
                    else if (opt == 2)
                    {
                        cout << "Enter new body for this note:" << endl;
                        getchar();
                        getline(cin, note.body[i]);
                        ch = 1;
                        break;
                    }
                    else if (opt == 3)
                    {
                        cout << "Enter new date for this note:" << endl;
                        getchar();
                        getline(cin, note.date[i]);
                        ch = 1;
                        break;
                    }
                    else if (opt == 4)
                    {
                        cout << "Enter new place for this note:" << endl;
                        getchar();
                        getline(cin, note.place[i]);
                        ch = 1;
                        break;
                    }
                }
                if (ch == 0)
                {

                    cout << "This contact does not exist!" ;
                }
            }
        }
                else
                {
                    break;
                }
    }
}

int calculator_menu()
{
    system("cls");
    cout << "Welcome to Calculator Menu" << endl << endl;
    int option,x,y;
    cout<< "please select option -"<< endl;
    cout<< "1.Add\n";
    cout<<"2.Subtraction\n";
    cout<<"3. Multiply\n";
    cout<<"4. divide\n";
    cout<<"5. area\n";
    cout<< "Select Option:  " << endl;
    cin>> option;
    if(option==1)
    {
        cout<< "*Addition*"<<endl;
        cout<< "please enter first number"<< endl;
        cin>> x;
        cout<<"please enter 2nd number"<< endl;
        cin>> y;
        cout<< x <<"+"<<y<< "=";
        cout<<calc.add(x,y);
        getch();

    }
    else if(option==2)
    {
        cout<< "*subtraction*"<<endl;
        cout<< "please enter first number"<< endl;
        cin>> x;
        cout<<"please enter 2nd number"<< endl;
        cin>> y;
        cout<< x <<"-"<<y<< "=";
        cout<<calc.sub(x,y);
        getch();

    }
    else if(option==3)
    {
        cout<< "*multiplication*"<<endl;
        cout<< "please enter first number"<< endl;
        cin>> x;
        cout<<"please enter 2nd number"<< endl;
        cin>> y;
        cout<< x <<"*"<<y<< "=";
        cout<<calc.multi(x,y);
        getch();

    }
    else if(option==4)
    {
        cout<< "*Division*"<<endl;
        cout<< "please enter first number"<< endl;
        cin>> x;
        cout<<"please enter 2nd number"<< endl;
        cin>> y;
        cout<< x <<"/"<<y<< "=";
        cout<<calc.divi(x,y);
        getch();

    }
    else if(option==5)
    {
        cout<< "This option is incomplete!! ";
        getch();

    }
    else
    {
        cout<< "invalid input.....!";

    }

}
int Main_Menu()
{
    initialize_contacts();
    initialize_messages();
    initialize_notes();
    for(;;)
    {
        system("cls");
        int input;
        cout << endl <<"---------- Main Menu ------------" << endl << endl << endl;
        cout << "Messages \t Enter 1" << endl;
        cout << "Contacts \t Enter 2" << endl;
        cout << "Notes \t\t Enter 3" << endl;
        cout << "Calculator \t Enter 4" << endl;
        cout << "About Us \t Enter 5" << endl;
        cin >> input;
        if (input == 1)
        {
            message_menu();
        }
        else if (input == 2)
        {
            contact_menu();
        }
        else if(input == 3)
        {
            notes_menu();
        }
        else if(input == 4)
        {
            calculator_menu();
        }
        else if (input == 5)
        {
            cout << "\n\tAbout us:\n";
            cout << "\n\t Course Name: Programming C++ \n Course Number: CSC 283 / CSC 284";
            cout << "\n\tSheikh Md Adif Hasan    ID-19203040\n\t";
            cout << "\n\tShraboni Saha Puja   ID-19203033\n\t";
            cout << "\n\tSabrina Mahjabin Senthia  ID-19203046\n\t";
            getch();
        }
    }
}

int login()
{
    string password = "123ABC";
    string enter_pass;

    cout << "Enter Password: " ;
    cin >> enter_pass;
    if( enter_pass == password)
    {
        Main_Menu();
    }
    else
    {
        cout << "Wrong Password!!" << endl;
        login();
    }

}
int main()
{
    login();
}
