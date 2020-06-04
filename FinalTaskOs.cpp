#include <iostream>
using namespace std;

//function prototype
void display();

int main()
{
    string choice;
    bool end = false , error = false ;
    int converted = 0;
    cout<<"<<WELCOME TO PROCESS MANAGER PROGRAM>>"<<endl;
    while(converted != -1){
        while (!error){
            try {
                display();
                cin>>choice;
                const char *select = choice.c_str();
                converted = stoi(select);
                error = true;
            }
            catch (invalid_argument e) {
                cout << "INVALED INPUT " << endl
                     << "Please Try Again : "<<endl;
            }
        }

        //1 list all running process
        if(converted == 1){
            system("ps -ef");}

        //2 process specified by user name
        else if(converted == 2){
            cout<<"Please Enter our User Name"<<endl;
            string user1;
            cin >> user1;
            string command = "ps -u" +user1+" -f";
            if ( system( command.c_str() ) )
               {cout << "PLEASE ENTER A VALID USER NAME" << endl<<endl;}
            }

        //3 all process ID
        else if(converted == 3){
            system("ps -e -o pid");
        } 

        //4 to run a process in the foreground
      else if(converted == 4){
          cout << "WARNNING: This will pause the process you have in your foreground!" << endl;
          cout << "Enter the name of the process/job you want to run:" << endl;
          string s;
          cin >> s;
          const char *final = s.c_str();
          system(final);
        }

        //5 run a process in the background
      else if(converted == 5){
          string s,name;
          cout << "Enter the name of the process/job you want to run:" << endl;
          cin >> name;
          s = name + " &";
          const char *final = s.c_str();
          system(final);
        }


		//6 to kill the process Immediately by The name of that process SIGKILL and won't perform any clean up
  else if(converted==6){
	  string pid;
	  string s;
	  string p;
	  cout<<"Enter the process ID you want to send the signal to:"<<endl;
	  cin>> pid;
	  s = "kill -9 "+ pid;
	//cout<<s<<endl;
	  system(s.c_str());
  }

  //7 To interrupt a specific process by hot key control c SIGINT
   else if(converted == 7){
	  string name;
	  string s;
	  cout<<"Enter the process ID you want to send the signal to:"<<endl;
	  cin>> name;
	  s= "killall " + name;
	  const char *final =s.c_str();
	  system(final);
  }



        //9 MANUAL PAGE
       else if (converted == 8) {
            system("man Task");
        }
	else	
	{
	  cout<<"Enter a Valid input"<<endl;
	}

        error = false;
    }
    return 0;
}

void display()
{
    cout<< "Choose your option:" << endl
        << "1- List All Process Running on System." << endl
        << "2- List All Process Specified By UserName." << endl
        << "3- List All Process ID." << endl
        << "4- Run a process in the foreground." << endl
        << "5- Run a process in the background." << endl
        << "6- Send a Kill a process using process id." << endl
        << "7- send a Kill signal a process using process Name." << endl
        << "8- Manual Page." << endl
	<<"Enter you choice "<<endl;
}
