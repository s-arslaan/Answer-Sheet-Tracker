#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<iomanip>
#include<windows.h>
using namespace std;
void press();

int count_anskey=0, count1=0, del_s=0, del_ak=0;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);\

class ans
{
public:
	string name, student_name;
	int sets, ques, i, j,student_ans[200];
	
	struct ans_set
	{
		char ans[200];
		int countmcq=0;
	}set[50],recover;

	void get_data(int num)
	{
		system("CLS");
		cout<<"\n___________________Answer Key: "<<num<<" ________________________________\n";
		cout<<"Enter subject Name: ";
		cin>>name;
	//	getline(cin,name);
		cout<<"Enter number of sets: ";
		cin>>sets;
		fflush(stdin);
		while(!cin)
        {
            cout << "\n\t\t\t\t\t______Please Enter A Valid Number_____" << endl;
            cin.clear();
            cin.ignore();
            cout<<"Enter number of sets: ";
            cin>>sets;
        }
		cout<<"Enter number of questions in each set: ";
		cin>>ques;
		while(!cin)
        {
            cout << "\n\t\t\t\t\t______Please Enter A Valid Number_____" << endl;
            cin.clear();
            cin.ignore();
            cout<<"Enter number of questions in each set: ";
            cin>>ques;
        }
		for(j=0; j<sets; j++)
		{
			cout<<"\n\n\t\t-----Enter Correct Answers for "<<name<<" Set:"<<j+1<<" MCQs-----";
			for(i=0; i<ques; i++)
			{
				if(i%5==0)
					cout<<endl<<"\n\t\t";

				bool out = false;
				while(out == false)
				{
					cout << i+1 << ": ";
					set[j].ans[i]=getche();
					cout<<"\t";
					if( set[j].ans[i]>=65 && set[j].ans[i]<=68 )
					{
						out=true;
					}
					else
					{
						cout << "\n\t\t\t---------------------\n\t\t\tOnly A,B,C,D are acceptable\n\t\t\t---------------------\n\t\t";
					}
					//cout<<ans[i];
				}
			}
			count1+=1;
		}
		count_anskey+=1;
	}
	void put_Data(int num)
	{
			cout<<"\n\n\t\t-------------------------------------------------------------------------------\n";
			cout<<"\t\t\tSUBJECT NAME: "<<name;
			cout<<"\n\t\t\tAnswer Key #"<<num<<endl;
			for(j=0; j<sets; j++)
			{
				cout<<"\n\t\t   -------Correct Answers for "<<name<<" Set:"<<j+1<<" MCQs-------\n";
				for(i=0;i<ques;i++)
				{
					if(i%5==0)
					{
						cout<<endl<<"\t\t\t";
					}
					cout<<i+1<<": "<<set[j].ans[i]<<"\t";
				}
				set[j].countmcq=strlen(set[j].ans);
				cout<<endl;
			}
			cout<<"\t\t-------------------------------------------------------------------------------\n";
	}
	void save_Data(int num)
	{
        ofstream file("answerkey_data.txt", ios::app);
	    file<<"\n\n\t\t-------------------------------------------------------------------------------\n";
        file<<"\t\t\tSUBJECT NAME: "<<name;
        file<<"\n\t\t\tAnswer Key #"<<num<<endl;
        for(j=0; j<sets; j++)
        {
            file<<"\n\t\t   -------Correct Answers for "<<name<<" Set:"<<j+1<<" MCQs-------\n";
            for(i=0;i<ques;i++)
            {
                if(i%5==0)
                {
                    file<<endl<<"\t\t\t";
                }
                file<<i+1<<": "<<set[j].ans[i]<<"\t";
            }
        set[j].countmcq=strlen(set[j].ans);
        file<<endl;
	//	cout<<endl<<set[j].countmcq<<endl;
        }
        file<<"\t\t-------------------------------------------------------------------------------\n";
        file.close();
	}
	void ans_compare(int set_no)
	{
		int temp=0;
		system("CLS");
		cout<<"\tEnter the name of student: ";
		cin>>student_name;
	//	getline(cin,student_name);
		cout<<"\n\n\n\t\t\t\t----Enter answers entered by "<<student_name<<"-----\n";
		for(i=0;i<=set[set_no-1].countmcq-1;i++)
		{
			if(i%5==0)
				cout<<endl<<"\t\t\t";
				
			bool out = false;
			while(out == false)
			{
				cout << i+1 << ": ";
				student_ans[i]=getche();
				cout<<"\t";
				if( student_ans[i]>=65 && student_ans[i]<=68 )
				{
					out=true;
				}
				else
				{
					cout << "\n\t\t\t---------------------\n\t\t\tOnly A,B,C,D are acceptable\n\t\t\t---------------------\n\n\t\t\t";
				}
			}
			if(set[set_no-1].ans[i]==student_ans[i])
				temp+=1;
		}
		cout<<"\n\n\n\t\t\tMarks obtained by "<<student_name<<" : "<<temp<<" OUT OF "<<set[set_no-1].countmcq<<endl;

		//Writing marks in a file
		ofstream outfile;
		outfile.open("marks.txt", ios::app);
		outfile<<"\n\t\t\tMarks obtained by "<<student_name<<" : "<<temp<<" OUT OF "<<set[set_no-1].countmcq<<endl;
		outfile.close();
	}
	void delete_set(int del_set)
	{
		recover=set[del_set-1];
		for(i=del_set-1;i<=sets;i++)
		{
			set[i]=set[i+1];
		}
		cout<<"\t__Set Deleted Successfully__"<<endl;
		sets--;
		count1--;
		del_s++;
	}
	void ans_modify(int n_set)
	{
		cout<<"\n\n\t\t-----Enter Correct Answers for "<<name<<" Set:"<<n_set<<" MCQs-----";
		for(i=0; i<ques; i++)
		{
			if(i%5==0)
				cout<<endl<<"\n\t\t";

			bool out = false;
			while(out == false)
			{
				cout << i+1 << ": ";
				set[n_set-1].ans[i]=getche();
				cout<<"\t";
				if( set[n_set-1].ans[i]>=65 && set[n_set-1].ans[i]<=68 )
				{
					out=true;
				}
				else
				{
					cout << "\n\t\t\t\t---------------------\n\t\t\t\tOnly A,B,C,D are acceptable\n\t\t\t\t---------------------\n";
				}
			}
		}
	}
	void getfromfile()
	{
		string line;
  			ifstream myfile("marks.txt");
			if (myfile.is_open())
			{
				while ( getline (myfile,line) )
				{
					cout << line << '\n';
				}
				myfile.close();
			}
			else
				cout << "\n\n\t\t\t----------NO RECORDS------------\n\n";
    }
};

void press()
{
    char askmenu;
    cout<<"\n\n\n\t\tPress any key for entering MENU... ";
    askmenu=getch();
}
void color(int col){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}
void fontsize(int a, int b){  
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
	GetCurrentConsoleFontEx(console, 0, lpConsoleCurrentFontEx);  
	lpConsoleCurrentFontEx->dwFontSize.X = a;  
	lpConsoleCurrentFontEx->dwFontSize.Y = b;  
	SetCurrentConsoleFontEx(console, 0, lpConsoleCurrentFontEx);  
}
int main()
{
	int n,i,j,askmenu, check_anskey, check_set, del_anskey, del_set;
	ans ob[50], recover;
	char ch, temp;
	bool out=false;

	while(out==false)
    {
        system("CLS");color(4);fontsize(30,30);
        cout<<"\n\n\n\n\t\t\t\t\t    ANSWER SHEET TRACKER -- Choice Menu"<<endl;color(14);fontsize(20,20);
        cout<<"\t\t\t\t-----------------------------------------------------------------\n\t\t\t\t|\t\t\t\t\t\t\t\t|";color(10);
        cout<<"\n\t\t\t\t|\t1. Enter New Answer Key(s)\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t2. Diplay Answer Key(s)\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t3. Correct Marksheet\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t4. Display Marks of Student(s)\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t5. Delete an Answer Key\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t6. Delete an Answer Set\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t7. Recover the Last Deleted Answer Key\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t8. Modify Answer(s)\t\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\t9. Fetch Answer Keys stored in file\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";
        cout<<"\n\t\t\t\t|\tPress Esc To Exit the program\t\t\t\t|"<<endl<<"\t\t\t\t|\t\t\t\t\t\t\t\t|";color(14);
        cout<<"\n\t\t\t\t-----------------------------------------------------------------\n";
        cout<<"\n\n\t\t\t\t\tEnter your choice number (1-9): ";
        ch=getche();
        fflush(stdin);

        switch(ch)
        {
            case '1':
                cout<<"\n\t\t\t\t\tEnter Number of answer keys you will insert: ";
                cin>>n;
				fflush(stdin);
                while(!cin)
                {
          			cout << "\n\t\t\t\t\t______Please Enter A Valid Number_____" << endl;
                    cin.clear();
                    cin.ignore();
                    cout<<"\n\t\t\t\t\tEnter Number of answer keys you will insert: ";
                    cin>>n;
                }
                for(i=0;i<n;i++)
                {
                    ob[count_anskey].get_data(count_anskey+1);
                }
                break;

            case '2':
                system("CLS");
                for(i=0;i<count_anskey;i++)
                {
                    ob[i].put_Data(i+1);
                }
                cout<<"\n\t\t\tTotal answer keys: "<<count_anskey<<endl;
                if(count_anskey>0)
	            {
	                cout<<"\n\t\tDo you want to save it in a file? (y/n): ";
	                temp=getche();
	                if(temp=='y' || temp=='Y')
	                {
	                    ofstream file("answerkey_data.txt", ios::app);
	                    time_t now = time(0);       //Current date and time of system
	                    tm *ltm = localtime(&now);  //sets values in structure of tm for pointer *ltm
	
	                    file <<endl << ltm->tm_mday << "/" << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\t" << std::setw(2) << ltm->tm_hour << ":" << std::setw(2) << ltm->tm_min << ":" << std::setw(2) << ltm->tm_sec << endl;
	                    for(i=0;i<count_anskey;i++)
	                    {
	                        ob[i].save_Data(i+1);
	                    }
	                //   ofstream file("answerkey_data.txt", ios::app);
	                    file<<"\n-----------------------------------------------------------------------------------------------------------------------------\n";
	                    file.close();
	                    cout<<"\n\n\t\t____Data Saved Successfully to \"answerkey_data.txt\"_____"<<endl;
	                }
            	}
                press();
                break;

            case '3':
                system("CLS");
                for(i=0;i<count_anskey;i++)
                {
                    ob[i].put_Data(i+1);
                }
                if(count_anskey==0)
                    cout<<"\n\n\t\t\t-------First Enter an answer key for comparison---------\n\n";
                else
                {
                    ask_anskey:
                    cout<<"\n\t\t\tEnter the Ans key Number you want to compare with: ";
                    cin>>check_anskey;
                    while(!cin)
                    {
                        cout << "\t\t\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the Ans key Number you want to compare with: ";
                        cin>>check_anskey;
                    }
                    if(check_anskey>count_anskey || check_anskey< 1)
                    {
                        cout<<"\n\t\t---Enter correct answer key number----";goto ask_anskey;
                    }

                    ask_set:
                    cout<<"\n\t\t\tEnter the set number: ";
                    cin>>check_set;
                    while(!cin)
                    {
                        cout << "\t\t\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the set number: ";
                        cin>>check_set;
                    }
                    if(check_set>ob[check_anskey-1].sets || check_set<1)
                    {
                        cout<<"\n\t\t---Enter correct set number----";goto ask_set;
                    }
                    ob[check_anskey-1].ans_compare(check_set);
                }
                press();
                break;

            case '4':
                system("CLS");
                ob[2].getfromfile();
                press();
                break;

            case '5':
                system("CLS");
                for(i=0;i<count_anskey;i++)
                {
                    ob[i].put_Data(i+1);
                }
                if(count_anskey==0)
                    cout<<"\n\n\t\t\t-------No Answer keys found---------\n\n";
                else
                {
                    ask_Danskey:
                    cout<<"\n\t\t\tEnter the Anskey Number for deletion: ";
                    cin>>del_anskey;
                    while(!cin)
                    {
                        cout << "\n\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the Anskey Number for deletion: ";
                        cin>>del_anskey;
                    }
                    if(del_anskey>count_anskey || del_anskey<1){
                        cout<<"\n\t\t---Enter correct answer key number----";goto ask_Danskey;
                    }
                    else
                    {
                        system("CLS");
                        ob[del_anskey-1].put_Data(del_anskey);
                        cout<<"\t\tAre you sure you want to delete the above Answer Key? (y/n): ";
                        temp=getche();
                        if(temp=='y' || temp=='Y')
                        {
                            recover=ob[del_anskey-1];
                            for(i=del_anskey-1;i<=count_anskey;i++)
                            {
                                ob[i]=ob[i+1];
                            }
                            cout<<"\n\t\t__Answer Key Deleted Successfully__"<<endl;
                            count_anskey--;
                            del_ak++;
                        }
                    }
                }
                press();
                break;

            case '6':
                system("CLS");
                for(i=0;i<count_anskey;i++)
                {
                    ob[i].put_Data(i+1);
                }
                if(count_anskey==0)
                    cout<<"\n\n\t\t\t-------No Answer keys found---------\n\n";
                else
                {
                    ask_del_anskey:
                    cout<<"\n\t\t\tEnter the Anskey Number for deletion: ";
                    cin>>del_anskey;
                    while(!cin)
                    {
                        cout << "\n\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the Anskey Number for deletion: ";
                        cin>>del_anskey;
                    }
                    if(del_anskey>count_anskey || del_anskey<1)
                    {
                        cout<<"\n\t\t---Enter correct answer key number----";goto ask_del_anskey;
                    }
                    ask_del_set:
                    cout<<"\n\t\t\tEnter the Set Number you want to delete: ";
                    cin>>del_set;
                    while(!cin)
                    {
                        cout << "\n\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the Set Number you want to delete: ";
                        cin>>del_set;
                    }
                    if(del_set>ob[del_anskey-1].sets || del_set<1)
                    {
                        cout<<"\n\t\t---Enter correct set number----";goto ask_del_set;
                    }
                    ob[del_anskey-1].delete_set(del_set);
                }
                press();
                break;

            case '7':
                if(del_ak==0)
				cout<<"\n\t\t_____No deleted Answer Key found____";
                else
                {
                    ob[count_anskey]=recover;
                    cout<<"\n\t\t_____Deleted Answer Key Recovered Successfully______";
                    count_anskey++;
                    del_ak--;
                }
                cout<<"\n\n\t\t";
                system("pause");
                break;

            case '8':
                system("CLS");
                for(i=0;i<count_anskey;i++)
                {
                    ob[i].put_Data(i+1);
                }
                if(count_anskey==0)
                    cout<<"\n\n\t\t\t-------First Enter an answer key for comparison---------\n\n";
                else
                {
                    ask_Manskey:
                    cout<<"\n\t\t\tEnter the Anskey Number you want to modify: ";
                    cin>>check_anskey;
                    while(!cin)
                    {
                        cout << "\n\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the Anskey Number you want to modify: ";
                        cin>>check_anskey;
                    }
                    if(check_anskey>count_anskey || check_anskey<1)
                    {
                        cout<<"\n\t\t---Enter correct answer key number----";goto ask_Manskey;
                    }
                    ask_Mset:
                    cout<<"\n\t\t\tEnter the set number for modification: ";
                    cin>>check_set;
                    while(!cin)
                    {
                        cout << "\n\t\t\tEnter A Valid Number" << endl;
                        cin.clear();
                        cin.ignore();
                        cout<<"\n\t\t\tEnter the set number for modification: ";
                        cin>>check_set;
                    }
                    if(check_set>ob[check_anskey-1].sets || check_set<1)
                    {
                        cout<<"\n\t\t---Enter correct set number----";goto ask_Mset;
                    }
                    ob[check_anskey-1].ans_modify(check_set);
                }
                press();
                break;

            case 27:
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
                cout<<"\n\n\t\t\t\t\t\t\t    THANK YOU\n\n";
                cout<<"\t\t\t\t\t\t\t---------------------\n\n\n\n\n\n\n\n\n\n";
                return 0;
                break;

            default:
                cout<<"\n\t\t\t\t\t-------------Invalid Choice!------------\n\n\t\t\t\t\t";
                system("pause");
                break;

            case '9':
                system("CLS");
                string line;
                ifstream ofile("answerkey_data.txt");
                if (ofile.is_open())
                {
                    while ( getline (ofile,line) )
                    {
                        cout << line << '\n';
                    }
                    ofile.close();
                }
                else
                {
                    cout << "\n\n\t\t\t----------NO RECORDS------------\n\n";
                }
                press();
                break;

        }//switch ends
    }//while loop ends
}
