#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include<conio.h>

using namespace std;


//starting the project

// 14 classes ban chuki




//-------------Done--------------
//Runtime polymorphism using base class pointers
//Authentication done
//Task Assingment
//Min 3 level of inheritance (We just have to assign special tasks to users)
//Activity Logs (AUDIT LOGOING)
//Info
//Messages System                                                              ----->Review Statment once again 
//Tasks can be assigned priority levels: High, Medium, Low.
//Encryption Key for Decrypting Private Messages, Intended Users functionality



//-------------In Progress------------
//Time To Live
//ADD USER (HIRE NEW Subordinates)
//Employee Performance (points) System
// GUI-style dashboard using ASCII art and box formatting



//-------------To Do------------
//Task Deligation
//Global Notification System
//Special Tasks for each position to justify hierarchical levels
//still have to think about the unique ID system



//------------Bouns------------
//Digital signatures for task approvals (hash of username + timestamp)
//Cycle detection in task delegation chains
//Encrypted binary log file.

//------------------------------------------------------------------------------------------------------



//check for the overloaded setsent_to(); //commented out, causing runtime error

//added new data member points in paidworkers class int points and bool login


//User files i.e. executive.txt, data writing format : ID|Name|Position|Password|Salary|points

//Policy Engine now Inherits Activity Logs

//------------------------------------------------------------------------------------------------------

void mainMenu();


class task {
    string task_name;
    string task_description;
    string task_status;
    string task_assigned_by;
    string task_assigned_to;
    string task_assigned_to_position;
    string task_priority;
    string task_assigned_time;  
    time_t TTL_time;
    public:
    task(){
        task_name="";
        task_description="";
        task_status="";
        task_assigned_by="";
        task_assigned_to="";
        task_assigned_to_position="";
        task_priority="";
        TTL_time=0;
    }
    task(string name,string description,string status,string assigned_by,string assigned_to,int TTL){
        task_name=name;
        task_description=description;
        task_status=status;
        task_assigned_by=assigned_by;
        task_assigned_to=assigned_to;
        TTL_time=TTL;
    }
    void setAssignedTime(const string &t) {
        task_assigned_time = t;
    }
    string getAssignedTime() const {
        return task_assigned_time;
    }
    void setTaskName(string name){
        task_name=name;
    }
    void setTaskAssignedToPosition(string position){
        task_assigned_to_position=position;
    }
    void setTaskDescription(string description){
        task_description=description;
    }
    void setTaskStatus(string status){
        task_status=status;
    }
    void setTaskPriority(string priority){
        task_priority=priority;
    }
    void setTaskAssignedBy(string assigned_by){
        task_assigned_by=assigned_by;
    }
    void setTaskAssignedTo(string assigned_to){
        task_assigned_to=assigned_to;
    }
    void setTTLTime(time_t TTL){
        TTL_time=TTL;
    }
    string getTaskName(){
        return task_name;
    }
    string getTaskDescription(){
        return task_description;
    }
    string getTaskStatus(){
        return task_status;
    }
    string getTaskAssignedToPosition(){
        return task_assigned_to_position;
    }
    string getTaskAssignedBy(){
        return task_assigned_by;
    }
    string getTaskPriority(){
        return task_priority;

    }
    string getTaskAssignedTo(){
        return task_assigned_to;
    }
    time_t getTTLTime(){
        return TTL_time;
    }
    string getTaskAssignedTime(){
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &TTL_time);
        return string(buffer);
    }
    //operator overloading for printing the task details
    friend ostream& operator <<(ostream& out, task& t)
    {
        out << "Task Name: " << t.task_name << endl
            << "Task Description: " << t.task_description << endl
            << "Task Status: " << t.task_status << endl
            << "Task Assigned By: " << t.task_assigned_by << endl
            << "Task Assigned To: " << t.task_assigned_to << endl
            << "Task Assigned To Position: " << t.task_assigned_to_position << endl
            << "Task Priority: " << t.task_priority << endl
            << "TTL Time: " << ctime(&t.TTL_time) << endl;
        return out;
    }
    ~task(){}
    
};


class PaidWorkers{
    protected:
        int ID;
        string name;
        string position;
        string password;
        float salary;
        bool new_messages;
        int points; //Employee points added New Data member
        bool login; //Login as data member to check on the run time in main menus if the user is logged in or not

    public:
        virtual void print() = 0;//making this an abstarct class we donot need an object of this class
        void setID(int id){
            ID = id;
        }
        void setName(string n){
            name = n;
        }
        void setPosition(string p){
            position = p;
        }
        void setPassword(string p){
            password = p;
        }
        void setSalary(float s){
            salary = s;
        }
        void setNewMessages(bool n){
            new_messages = n;
        }
        int getID(){
            return ID;
        }
        string getName(){
            return name;
        }
        string getPassword(){
            return password;
        }
        string getPosition(){
            return position;
        }
        float getSalary(){
            return salary;
        }
        bool getNewMessages(){
            return new_messages;
        }
        void setPoints(int p){
            points = p;
        }
        int getPoints(){
            return points;
        }
        void setLogin(bool l){
            login = l;
        }
        bool getLogin(){
            return login;
        }
        virtual ~PaidWorkers(){}
};


class Junior: public PaidWorkers{
    public:
    Junior(){
        ID=0;
        name="";
        position="Junior";
        password="";
        salary=1000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Junior(int id,string n,string pass){
        ID=id;
        name=n;
        position="Junior";
        password=pass;
        salary=1000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};


class Employee: public Junior{
    public:
    Employee(){
        ID=0;
        name="";
        position="Employee";
        password="";
        salary=2000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Employee(int id,string n,string pass){
        ID=id;
        name=n;
        position="Employee";
        password=pass;
        salary=2000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Manager: public Employee{
    public:
    Manager(){
        ID=0;
        name="";
        position="Manager";
        password="";
        salary=3000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Manager(int id,string n,string pass){
        ID=id;
        name=n;
        position="Manager";
        password=pass;
        salary=3000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Director: public Manager{
    public:
    Director(){
        ID=0;
        name="";
        position="Director";
        password="";
        salary=4000.0;
        new_messages=0;
        points=0;
        login=false;
    }
    Director(int id,string n,string pass){
        ID=id;
        name=n;
        position="Director";
        password=pass;
        salary=4000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }

};


class Executive: public Director {
    public:
    Executive(){
        ID=0;
        name="";
        position="Executive";
        password="";
        salary=5000.0;
        new_messages=0;
        points=0;
        login=false;

    }
    Executive(int id,string n,string pass){
        ID=id;
        name=n;
        position="Executive";
        password=pass;
        salary=5000.0;
        new_messages=0;
        points=0;
        login=false;
    }

    virtual void print() override{
        cout<<"Name : "<<name<<endl
            <<"ID : "<<ID<<endl
            <<"Position : "<<position<<endl;
    }
};


class ActivityLog{
    protected:
        int countLogs;
        int* threatLevel;
        string outlog;
        string* logs;
    public:
        ActivityLog(){
            countLogs = 0;
            threatLevel = NULL;
            logs = NULL;
            outlog = "";
        }
        ActivityLog(string l) : outlog(l){}

        string getCurrentTime() const {         //just to get the newtime without getting the new line character at the end od the current time
            time_t now = time(0);                 //current time stamp to now in long long int form
            string newtime = ctime(&now);        //current timestamp to string
            if (!newtime.empty() && newtime.back() == '\n') //if string is not empty and the last char is '\n'
                newtime.pop_back();                         //then remove that charachter
            return newtime;                                 //return newtime
        }
        void writeLogs()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                countLogs = 0;
            }
            ifstream in;
            in.open("./Activitylogs.txt", ios::in);
            if (!in)
            {
                cout<<endl<<endl
                    <<"Error Counting singin Logs!"<<endl<<endl;
                return;
            }
            string line;
            while(in>>line)
            {
                countLogs++;
            }
            in.close();

            logs = new string [countLogs];
            threatLevel = new int [countLogs]();
            int i = 0;
            in.open("./Activitylogs.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            while(getline(in, line, '|'))
            {
                logs[i] = line;
                in>>threatLevel[i];
                in.ignore(1);   //|
                i++;
            }
            in.close();
            return;
        }

        void generateAudit()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                delete [] threatLevel;
                countLogs = 0;
            }
            string line;
            fstream read;
            read.open("./ActivityLog.txt", ios::in);
            if(!read)
            {
                cout<<endl<<endl
                    <<"Error Counting singin Logs!"<<endl<<endl;
                return;
            }
            while (read>>line)
            {
                countLogs++;
            }
            read.close();

            logs = new string [countLogs];
            threatLevel = new int [countLogs]();

            read.open("./ActivityLog.txt", ios::in);
            if(!read)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            int i = 0;
            while(getline(read, logs[i], '|'))
            {
                read>>threatLevel[i];
                read.ignore(1);
                i++;
            }
            read.close();

            string out = "------------------- High Threat Report (Failed Login Attempts): -------------------\n\n";
            int count = 0;
            for(int i = 0; i < countLogs; i++)
            {

                if(threatLevel[i] == 3)
                {
                    out += logs[i] + to_string(threatLevel[i]) + "\n";
                    count++;
                }
            }
            if(count == 0)
            {
                out += "No Failed Login Attempts!\n\n";
            }
            count = 0;

            out += "-----------------------------------------------------------------------\n\n";

            out += "--------------------- Low Threat Report (Frequent Tasks Assigned): -------------------\n\n";
            for(int i = 0; i < countLogs; i++)
            {
                if(threatLevel[i] == 2)
                {
                    out += logs[i] + to_string(threatLevel[i]) + "\n";
                    count++;
                }
            }
            if(count == 0)
            {
                out += "No Frequent Tasks Assinged!\n\n";
            }

            count = 0;
            out += "-----------------------------------------------------------------------\n\n";
            cout<< out;
        }
        void readAllLogs()
        {
            if(countLogs != 0)
            {
                delete [] logs;
                delete [] threatLevel;
                countLogs = 0;
            }
            string line;
            fstream read;
            read.open("./ActivityLog.txt", ios::in);
            if(!read)
            {
                cout<<endl<<endl
                    <<"Error Counting singin Logs!"<<endl<<endl;
                return;
            }
            while (read>>line)
            {
                countLogs++;
            }
            read.close();

            logs = new string [countLogs];
            threatLevel = new int [countLogs]();

            read.open("./ActivityLog.txt", ios::in);
            if(!read)
            {
                cout<<endl<<endl
                    <<"Error Reading singin Logs!"<<endl<<endl;
                return;
            }
            int i = 0;
            while(getline(read, logs[i], '|'))
            {
                read>>threatLevel[i];
                read.ignore(1);
                i++;
            }
            read.close();

            string out = "";
            int count = 0;
            for(int i = 0; i < countLogs; i++)
            {
                out += logs[i] + to_string(threatLevel[i]) + "\n";
                count++;
            }
            if(count == 0)
            {
                out += "No LOGS Available!\n\n";
            }
            count = 0;
            cout<< out;
            return;
        }
        friend ostream& operator<<(ostream& out, ActivityLog& write);
};


ostream& operator<<(ostream& out, ActivityLog& write)
{
    out << write.outlog;
    write.outlog = "";
    return out;
}


class Messages{
    protected:
        string message;
        string sender;
        string receiver;
        string type;
        bool isRead;
    public:
        Messages(string m, string s, string r){
            message = m;
            sender = s;
            receiver = r;
            isRead = false;
        }
        void setMessage(string m){
            message = m;
        }
        void setSender(string s){
            sender = s;
        }
        void setReceiver(string r){
            receiver = r;
        }
        void setIsRead(bool r){
            isRead = r;
        }
        string getMessage(){
            return message;
        }
        string getSender(){
            return sender;
        }
        string getReceiver(){
            return receiver;
        }
        bool getIsRead(){
            return isRead;
        }
        ~Messages(){
            
        }
};
class INFO:public Messages{

    string senders_position;

    public:
        INFO(string m, string s, string sp, string r):Messages(m,s,r){
            senders_position = sp;
            message = m;
            sender = s;
            receiver = r;
            type = "INFO";
            isRead = false;
        }
        string getSendersPosition(){
            return senders_position;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }
        ~INFO(){}
};


class PRIVATE : public Messages {
private:
    string encrypted_message;
    string decrypted_message;
    int    sent_to;  
    

    // simple Caesar‐shift helper (shift can be positive or negative)
    char caesarShift(char c, int shift) 
    {
        if (isupper(c))
            return char((c - 'A' + shift + 260) % 26 + 'A');
        if (islower(c))
            return char((c - 'a' + shift + 260) % 26 + 'a');
        return c;
    }

    // encrypt using last TWO digits of sent_to
    void encryptMessage() {
        int key = sent_to % 100;         // now 0..99  
        int s  = key % 26;               // reduce to 0..25
        encrypted_message.clear();
        for (char c : message)
            encrypted_message += caesarShift(c, +s);
    }

public:

    PRIVATE(const string& m, const string& s, const string& r, int id)
      : Messages(m, s, r)
    {
        message = m;
        sender  = s;
        receiver = r;
        sent_to = id;
        encryptMessage();               // encrypt on construction                
        type   = "PRIVATE";
        isRead = false;
    }


    // setting the recipient ID also re-encrypts
    void setSentTo(int id) {
        sent_to = id;
        encryptMessage();
    }

    int getSentTo() const {
        return sent_to;
    }

    // write to file as before
    void saveToFile(const string& filename = "private_messages.txt") {
        ofstream out(filename, ios::app);
        if (!out) {
            cerr << "Error opening " << filename << "\n";
            return;
        }
        // sender|receiver|sent_to|encrypted_message
        out << sender << '|'
            << receiver << '|'
            << sent_to << '|'
            << encrypted_message << "\n";
    }

   

    void markAsRead() {
        isRead = true;
    }
    ~PRIVATE(){}
};
void printInBox(const string &msg) {
    const string RESET = "\033[0m";
    const string BLUE  = "\033[31m";
    // build the horizontal line of length msg.size() + 2 spaces padding
    string horiz(msg.size() + 2, '=');

    // top border
    cout << BLUE <<"     ┌" << horiz << "┐" << RESET << "\n";

    // middle with the message
    cout << BLUE << "     │ " << RESET
         << msg
         << BLUE << " │" << RESET << "\n";

    // bottom border
    cout << BLUE << "     └" << horiz << "┘" << RESET << "\n";
}

char caesarShift(char c, int shift) {
    if (isupper(c))
        return char((c - 'A' + shift + 260) % 26 + 'A');
    if (islower(c))
        return char((c - 'a' + shift + 260) % 26 + 'a');
    return c;
}


void decryptInteractive(string message, int sent_to) {
    #define RED "\033[31m";
    #define GREEN "\033[32m";
    #define YELLOW "\033[93m";
    const std::string RESET = "\033[0m";
    int entered_id;
    cout << "\033[31m" 
    << "              Decrypting message...\n" << endl;
    cout 
    << "            \nEnter the decryption key : ";
    cin  >> entered_id;
    
    int expected = sent_to % 100;
    if (entered_id != expected) {
        cout << "Incorrect key—cannot decrypt.\n";
        return;
    }

    int s = entered_id % 26;
    string decrypted_message;
    for (char c : message){
        decrypted_message += caesarShift(c, -s);
    }

    printInBox(decrypted_message);

}


class ALERT:public Messages{
    public:
        ALERT(string m, string s, string r):Messages(m,s,r){
            message = m;
            sender = s;
            receiver = r;
            type = "ALERT";
            isRead = false;
        }
        void printMessage(){
            cout<<"Message: "<<message<<endl
                <<"Sender: "<<sender<<endl
                <<"Receiver: "<<receiver<<endl;
        }
        void markAsRead(){
            isRead = true;
        }
        ~ALERT(){}
};
void printMenu(const string& title, const string options[], int numOptions) {
    const string RESET = "\033[0m";
    const string BLUE  = "\033[34m";

    const int boxWidth = 60;
    const string margin = "          "; 
    
    cout << BLUE;
    
    cout << margin << "╔" << string(boxWidth, '=') << "╗\n";
    
    int titleLen = title.length();
    int leftPad = (boxWidth - titleLen) / 2;
    int rightPad = boxWidth - titleLen - leftPad;
    cout << margin << "║" 
         << string(leftPad, ' ') << title << string(rightPad, ' ') 
         << "║\n";
    
    cout << margin << "╠" << string(boxWidth, '=') << "╣\n";
    
    for(int i = 0; i < numOptions; i++) {
        cout << margin << "║  " << left << setw(boxWidth-2) 
             << options[i] << "║\n";
    }
    
    cout << margin << "╚" << string(boxWidth, '=') << "╝" << RESET << endl;
}
class PolicyEngine : public ActivityLog{
    private:

    //data members
    int n_users;
    PaidWorkers* pw;
    int accessLevel;
    string position;

    // private member fucntions
    
    bool isTaskExpired(task* t){
        if(!t)
        {
            return false;
        }
        time_t now = time(0);
        return now > t->getTTLTime();
    }

    task* readTask(ifstream& in, PaidWorkers* user){        //TTL BY RECURRSION
           string line;
           if(!getline(in, line))
           {
                return nullptr;
           }
           
           string name, description, status, assigned_by, assigned_to;
           time_t ttl;
           
    }
    PaidWorkers* escalateWorker(PaidWorkers* p) {//helper function for recursion
    
        int    id   = p->getID();
        string name = p->getName();
        string pass = p->getPassword();

        string pos = p->getPosition();
        if (pos == "Junior")    return new Employee(id, name, pass);
        if (pos == "Employee")  return new Manager(id, name, pass);
        if (pos == "Manager")   return new Director(id, name, pass);
        if (pos == "Director")  return new Executive(id, name, pass);
        // if already at "Executive" or unknown, no further escalation
        return nullptr;
    }
    
    
    
    public:
    PolicyEngine(PaidWorkers* p)
    {
        pw = p;
        if(pw->getPosition() == "Junior"){
            accessLevel = 1;
        }
        else if(pw->getPosition() == "Employee"){
            accessLevel = 2;
        }
        else if(pw->getPosition() == "Manager"){
            accessLevel = 3;
        }
        else if(pw->getPosition() == "Director"){
            accessLevel = 4;
        }
        else if(pw->getPosition() == "Executive"){
            accessLevel = 5;
        }
        else{
            cout<<"Invalid Position"<<endl;
        }
    }

    int getAccessLevel(){
        return accessLevel;
    }
    string getPosition(){
        return position;
    }

    bool Assign_Task(PaidWorkers* p)
    {
       PolicyEngine pe(p);
       if(pe.accessLevel <= accessLevel){
            #define BLUE "\033[34m"
            #define YELLOW "\033[93m"
            #define GREEN "\033[32m"
            #define RED "\033[31m"
            cout<<GREEN<<"\n        You have permission to assign task to "<<p->getPosition()<<"\033[0m"<<endl;
            task* t = new task;
            cout<<YELLOW<<"\n       Enter Task Name: "<<"\033[0m";
            string name;
            getline(cin, name);
            t->setTaskName(name);

            cout<<YELLOW<<"\n       Enter Task Description: "<<"\033[0m";
            string description;
            getline(cin, description);
            t->setTaskDescription(description);

            t->setTaskStatus("Assigned");
            t->setTaskAssignedBy(pw->getName());
            t->setTaskAssignedTo(p->getName());
            t->setTaskAssignedToPosition(p->getPosition());
            string option[3] = {"High", "Medium", "Low"};
            printMenu("Task Priority",option, 3);
            cout<<YELLOW<<"\n       Enter Task Priority: "<<"\033[0m";
            int priority;
            cin>>priority;
            if(priority == 1){
                t->setTaskPriority("High");
            }
            else if(priority == 2){
                t->setTaskPriority("Medium");
            }
            else if(priority == 3){
                t->setTaskPriority("Low");
            }
            else{
                cout<<"Invalid Priority"<<endl;
                return false;
            }
            
            cout<<YELLOW<<"\n       Enter Task Assigned Time: "<<"\033[0m";
            time_t TTL;
            int assingedDays = 0;
            // I will  start working here for the TTL Assingment ( EXPIREIE DATE )
            cin>>TTL;
            t->setTTLTime(TTL);

            //writing the task to the file
            ofstream out("Task.dat",ios::app);
            if(!out){
                cout<<"Error opening file"<<endl;
                return false;
            }
            //outing time also to the file
            time_t currentTime = time(0); // Get current time
            char* dateTime = ctime(&currentTime); // Convert to string
            out<<t->getTaskName()<<"|"<<t->getTaskDescription()<<"|"<<t->getTaskStatus()<<"|"<<t->getTaskAssignedBy()<<"|"<<pw->getPosition()<<"|"<<t->getTaskAssignedTo()<<"|"<<t->getTaskAssignedToPosition()<<"|"<<t->getTaskPriority()<<"|"<<TTL<<"|"<< dateTime;

            cout<<YELLOW<<"\n       Enter Task Expire Time (in days): "<<"\033[0m";
            cin>>assingedDays;
            time_t deadline = time(0) + (assingedDays * 24 * 60 * 60);
            t->setTTLTime(deadline);
            out.open("Task.dat",ios::app);
            out << t->getTaskName() << "|"
                << t->getTaskDescription() << "|"
                << t->getTaskStatus() << "|"
                << t->getTaskAssignedBy() << "|"
                << t->getTaskAssignedTo() << "|"
                << t->getTTLTime() << endl;
            out.close();

            ActivityLog logging( "Task: " + t->getTaskName() + " assigned to " + p->getName() + " by " + pw->getName());
            out.open("ActivityLog.txt",ios::app);
            out << logging << endl;
            out.close();

            cout<<"Task Assigned Successfully"<<endl;

            cout<<BLUE<<"\n\n===========Task Details============ "<<endl;
            cout<<*t;
            cout<<"===================================="<<"\033[34m"<<endl;
            return true;
        }
        else
        {
            cout<<RED<<"\n         You do not have permission to assign task to the following workers"<<"\033[31m"<<endl;
            return false;
        }
        return false;
    }


    void viewTask(PaidWorkers* p)
    {
        #define BLUE "\033[34m"
        #define YELLOW "\033[93m"
        #define GREEN "\033[32m"
        #define RED "\033[31m"
        ifstream in;
        in.open("Task.dat");
        task* userTask = readTask(in, p);
        in.close();
        
        if(userTask)
        {
            cout<<BLUE<<"\n\n===========Task Details============ "<<endl;
            cout<<userTask;
            cout<<"===================================="<<"\033[34m"<<endl;
            delete userTask;
        }
        else
        {
            cout<<RED<<"         No Task Assigned!"<<"\033[31m"<<endl<<endl;
        }

    }

    //making a global function to send information to all the workers
    void sendGlobalAlert(){
        if(accessLevel < 4){
            cout<<"You do not have permission to send global alert"<<endl;
            return;
        }
        cout<<"\n\n===========Global Alert============ "<<endl;
        cout<<"\n Enter the Alert: ";
        string alert_message;
        getline(cin, alert_message);
        //0|Director|Servers to be down Till 9pm|readername1readername2
        //message id|Sender position|Message|readers names
        //extracting the id from the file to assign 1+ id 
        ifstream in;
        in.open("GlobalNoti.txt");
        if(!in){
            cout<<"Error opening file"<<endl;
            return;
        }
        int id;
        int new_id=0;
        string Sender_pos, message, reader_names;
        while(in>>id)
        {
            in.ignore(1);
            getline(in, Sender_pos, '|');
            getline(in, message, '|');
            getline(in, reader_names, '\n');
            new_id++;
        }

        in.close();
        //writing the alert message to the file
        ofstream out("GlobalNoti.txt",ios::app);
        if(!out){
            cout<<"Error opening file"<<endl;
            return;
        }
        
        out<<endl<<new_id<<"|"<<pw->getPosition()<<"|"<<alert_message<<"|";

        out.close();


        cout<<"Notification Sent Successfully!"<<endl;

    

    }

    bool can_send_info(PaidWorkers *p)
    {
        #define BLUE "\033[34m"
        #define YELLOW "\033[93m"
        #define GREEN "\033[32m"
        #define RED "\033[31m"
        PolicyEngine pe(p);
        if(pe.accessLevel < accessLevel){
             cout<< YELLOW <<"\nYou have permission to send information to "<<p->getPosition()<<"\033[0m"<<endl;
             cout<< YELLOW <<"\nEnter the Information: "<<"\033[0m";

            
                string info_message;
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, info_message);
             INFO* info=new INFO(info_message,pw->getName(),pw->getPosition(),p->getPosition());
             //writing the info message to the file
                ofstream out("Info.txt",ios::app);
                if(!out){
                    cout<<"Error opening file"<<endl;
                    return false;
                }
                //outing time also to the file
                time_t currentTime = time(0); // Get current time
                char* dateTime = ctime(&currentTime); // Convert to string
                out<<info->getSender()<<"|"<<info->getSendersPosition()<<"|"<<info->getReceiver()<<"|"<<info->getMessage()<<"|"<<info->getIsRead()<<"|"<< dateTime<< endl;    
                out.close();
                cout<< GREEN << "Information sent successfully!" << "\033[32m" << endl;
             return true;
         }
         else{
             cout<<RED<<"You do not have permission to send information to the following workers"<<"\033[31m"<<endl;
             return false;
         }
        
    }

    //to delegate task the task should be delegated to same or higher level of hierarchy
    // ———————————— recursive delegation check ————————————
    bool can_delegate_task(PaidWorkers* new_p, PaidWorkers* previous_p) {
        // wrap each in a PolicyEngine to get levels
        PolicyEngine peNew(new_p);
        PolicyEngine pePrev(previous_p);

        // Base case: new_p has equal or higher access than previous_p
        if (peNew.getAccessLevel() >= pePrev.getAccessLevel()) {
            cout << "Allowed to delegate to " << new_p->getPosition() << "\n";
            return true;
        }

        // Otherwise, try the next-higher position
        PaidWorkers* escalated = escalateWorker(new_p);
        if (!escalated) {
            // we’ve reached the top and still can’t delegate
            cout << "Cannot delegate: reached top of hierarchy at "
                 << new_p->getPosition() << "\n";
            return false;
        }

        // recursive attempt with the escalated worker
        bool ok = can_delegate_task(escalated, previous_p);
        delete escalated;  // clean up
        return ok;
        
    }
        

    bool can_send_alert(PaidWorkers *p){
        #define BLUE "\033[34m"
        #define YELLOW "\033[93m"
        #define RED "\033[31m"
        #define GREEN "\033[32m"
        PolicyEngine pe(p);
        if(pe.accessLevel <= accessLevel){
                cout<< YELLOW <<"\nYou have permission to send alert to "<<p->getPosition()<<"\033[0m"<<endl;

                cout<< YELLOW <<"\nEnter the Alert: "<<"\033[0m";
                string alert_message;
                getline(cin, alert_message);
             ALERT* alert=new ALERT(alert_message,pw->getName(),p->getName());
             //writing the info message to the file
                ofstream out("Alert.txt",ios::app);
                if(!out){
                    cout<<"Error opening file"<<endl;
                    return false;
                }
                //outing time also to the file
                time_t currentTime = time(0); // Get current time
                char* dateTime = ctime(&currentTime); // Convert to string
                out<<alert->getSender()<<"|"<<pw->getPosition()<<"|"<<alert->getReceiver()<<"|"<<alert->getMessage()<<"|"<<alert->getIsRead()<<"|"<< dateTime;    
                out.close();
                cout<< GREEN << "Alert sent successfully!" << "\033[32m" << endl;
             return true;
         }
         else{
            cout<<RED<<"You do not have permission to send alert to the following workers"<<"\033[31m"<<endl;

             return false;
         }
    }
};


class Authentication : public ActivityLog{
    protected:
        //these data members are only for reading user.txt, so the class paidworkers get isolated from authentication function
        //user.txt is only read and write by authentication class and noting else
        int usercount;
        int attempts;
        PaidWorkers* users;
        int OTP;
        long long otptime;
        
        public:
        Authentication(){
            usercount = 0;
            users = NULL;
            OTP = 0;
            attempts = 1;
            otptime = 0;
        }
        
        string hashedPassword(string& password)
        {
            string hashed;
            for(int i = 0; i < password.length(); i++)
            {
                char original = password[i];
                int convert = (original * (i + 1) + 31) % 94 + 33;      //keep it under the range of printable charachters
                if(convert == 124)
                {
                    convert = 125; //when hashing fall on | it will assign charchter next to | which is {
                }

                hashed += static_cast<char>(convert); //type cast the int type assci value to the actual charachter and add to the string 
            }
            return hashed;
        }


        void readuser(string pos)
        {
            if(usercount != 0)
            {
                delete [] users;
                usercount = 0;
            }
            
            ifstream in;
            int id = 0;
            int points = 0;
            double salary = 0;
            string position;
            string name;
            string password;
            string filename = "./" + pos + ".txt";

            if(pos == "Executive")
            {
                attempts++;
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Executive [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Director")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Director [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Manager")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Manager [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Employee")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Employee [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else if(pos == "Junior")
            {
                string line;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                    mainMenu();
                }
                while(getline(in, line, '\n'))
                {
                    usercount++;
                }
                in.close();
                users = new Junior [usercount];
                int i = 0;
                in.open(filename, ios::in);
                if(!in)
                {
                    cout<<endl<<endl
                        <<"Error Reading Users!"<<endl<<endl;
                    mainMenu();
                }
                while (in>>id)
                {
                    //1234|moiz|Executive|1234|1000|23
                    in.ignore(1);
                    getline(in, name, '|');
                    getline(in, position, '|');
                    getline(in, password, '|');
                    in>>salary;
                    in.ignore(1);
                    in>>points;
                    in.ignore(1);
                    
                    //initializing data member array of paidworkers
                    users[i].setID(id);
                    users[i].setName(name);
                    users[i].setPassword(password);
                    users[i].setSalary(salary);
                    users[i].setPosition(position);
                    i++;
                }
                in.close();
            }
            else
            {
                cout<<endl<<endl
                    <<"Invalid Position!"<<endl<<endl;
                mainMenu();
            }
        }
        
        
        int userExists(string name, string pos)
        
        {
            readuser(pos);
            for(int i = 0; i < usercount; i++)
            {
                if(users[i].getName() == name)
                {
                    return i;
                }
            }           
            return -1;
        }
        
        
        
        bool OTP_TIME()
        {
            ifstream in("./OTP.txt");
            int inOTP;
            long long inTime;   //  to store the int form of current time
            in >> inOTP;
            in.ignore(1);
            in >> inTime;
            in.close();

            // if more than 15 seconds have passed, expire it
            return (difftime(time(0), inTime) <= 30.0);   //using a difftime() function from the predefined ctime library
        }
        
        
        void otpGenerator()
        {
            srand(time(0));
            OTP = 100000 + rand() % 900000;
            otptime = time(0);

            ofstream out;
            out.open("./OTP.txt", ios::out);
            if(!out)
            {
                cout<<endl<<endl
                    <<"Error opening OTP file"<<endl<<endl;
                mainMenu();
            }

            out<< OTP << "|" << otptime << endl;
            out.close();
        }
        string getPassword() {
            string password;
            char ch;

            while (true) {
                ch = _getch();  // get character without echoing

                if (ch == 13) { // Enter key
                    cout << endl;
                    break;
                }
                else if (ch == 8) { // Backspace
                    if (!password.empty()) {
                        password.pop_back();
                        cout << "\b \b"; // erase * from console
                    }
                }
                else {
                    password += ch;
                    cout << '*';
                }
            }

            return password;
        }


        PaidWorkers& login(string pos)  //string to check position
        {
            bool islogin = false;
            attempts = 1;
            string iname, ipassword;    //input name and input password
            cout<<YELLOW<<"\n       Enter Username: "<<"\033[0m";
            cin>>iname;
            int index = userExists(iname, pos);
            if(index != -1)
            {
                while(1)
                {
                    if(attempts > 3)
                    {
                        ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Failed (Too many attempts)! " +  " |3\n");
                        fstream writelog;
                        writelog.open("./ActivityLog.txt", ios::app);
                        writelog << logging;
                        writelog.close();
                        cout<<endl<<endl;
                        cout<<"Too Many Attempts Please Try Again Later!"<<endl<<endl;
                        users[index].setLogin(false);
                        return users[index];
                    }
                    cout<<RED<<"\n       Enter Password: "<<"\033[0m";
                    ipassword=getPassword();
                    ipassword = hashedPassword(ipassword);
                    if(users[index].getPassword() == ipassword)
                    {
                        otpGenerator();
                        int otp = 0;
                        cout<<YELLOW<<"\n       Enter OTP: "<<"\033[0m";
                        cin>>otp;
                        if(!OTP_TIME())
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Failed Login Attempt (OTP EXPIRED)! " +  " |0\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<RED<<"\n       OTP Expired!"<<endl<<endl;
                            cout<<RED<<"\n       Please Try Again!"<<endl<<"\033[31m"<<endl;
                            users[index].setLogin(false);
                            remove("./OTP.txt");
                            break;
                        }
                        if(otp == OTP)
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Successfully! " +  " |0\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<GREEN<<"\n       Logged in Successfully!"<<endl<<endl;
                            users[index].setLogin(true);
                            remove("./OTP.txt");
                            break;
                        }
                        else
                        {
                            ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Failed Login Attempt (Wrong OTP)! " +  " |1\n");
                            fstream writelog;
                            writelog.open("./ActivityLog.txt", ios::app);
                            writelog << logging;
                            writelog.close();
                            cout<<endl<<endl;
                            cout<<RED<<"\n       Invalid OTP!"<<endl<<endl;
                            cout<<RED<<"\n       Please Try Again!"<<endl<<"\033[31m"<<endl;
                            users[index].setLogin(false);
                            remove("./OTP.txt");
                            break;
                        }
                    }
                    else
                    {
                        ActivityLog logging(getCurrentTime() + ", " + users[index].getName() + " Logged in Failed! (incorrect pass) " +  " |1\n");
                        fstream writelog;
                        writelog.open("./ActivityLog.txt", ios::app);
                        writelog << logging;
                        writelog.close();
                        cout<<endl<<endl;
                        cout<<RED<<"\n       Invalid Password!"<<endl<<endl;
                        cout<<RED<<"\n       Please Try Again!"<<endl<<"\033[31m"<<endl;
                        attempts++;
                    }
                }
            }
            else
            {
                cout<<endl<<endl;
                cout<<RED<<"\n       Invalid Username!"<<endl<<endl;
                cout<<RED<<"\n       Please Try Again!"<<endl<<"\033[31m"<<endl;
                mainMenu();
            }

            // PaidWorkers* usertoreturn;
            // if(pos == "Executive")
            // {
            //     usertoreturn = new Executive(users[index]);
            // }
            // else if(pos == "Director")
            // {
            //     usertoreturn = new Director(users[index]);
            // }
            // else if(pos == "Manager")
            // {
            //     usertoreturn = new Manager(users[index]);
            // }
            // else if(pos == "Employee")
            // {
            //     usertoreturn = new Employee(users[index]);
            // }
            // else if(pos == "Junior")
            // {
            //     usertoreturn = &users[index];
            // } 
            return users[index];
        }
        
        
        void addUser(string pos)  //string to check position
        {
            string username, password;
            cout<<"Enter Username: ";
            cin>>username;
            
            int index = userExists(username, pos);
            if(index != -1)
            {
                cout<<endl<<endl;
                cout<<"Username already exists!"<<endl<<endl;
                cout<<"Please try again with a different username!"<<endl<<endl;
                return;
            }
            
            cout<<"Enter Password: ";
            cin>>password;
            
            string hashedPass = hashedPassword(password);
            
            int userID = generateUserID();
            string id = to_string(userID);
            
            string filename = "./" + pos + ".txt";
            fstream writeUser;
            writeUser.open(filename, ios::app);
            // Format: ID|name|position|password|salary|points
            writeUser << id << "|" << username << "|" << pos << "|" << hashedPass << "|" << 1000 << "|" << 20 << endl;
            writeUser.close();
            
            ActivityLog logging(getCurrentTime() + ", " + username +"  " + pos + " added new user: " + username + " |0\n");
            fstream writelog;
            writelog.open("./ActivityLog.txt", ios::app);
            writelog << logging;
            writelog.close();
            
            cout<<endl<<endl;
            cout<<"User added successfully!"<<endl<<endl;
            
        }
        
        int generateUserID()
        {
            int id = 1000 + (rand() % 9000);
            bool idExists = false;
            do{
                idExists = false;
                for(int i = 0; i < usercount; i++)
                {
                    if(users[i].getID() == id)
                    {
                        idExists = true;
                        id = 1000 + (rand() % 9000);
                        break;
                    }
                }
            }while(idExists);
            return id;
        }
        ~Authentication()
        {
            if(users != NULL)
            {
                delete[] users;
                users = NULL;
            }
        }
};

void ExecutiveMenu(PaidWorkers* user);
void DirectorMenu(PaidWorkers* user);
void ManagerMenu(PaidWorkers* user);
void EmployeeMenu(PaidWorkers* user);
void JuniorMenu(PaidWorkers* user);

void show_Message_menu(PaidWorkers * pw);
void readingInfoFile(PaidWorkers*);
#define BLUE "\033[34m"
#define RESET "\033[0m"



void commanmenu( PaidWorkers* pw)
{
   SetConsoleOutputCP(CP_UTF8);

    // Enable ANSI escape codes on Windows
    system("");

    int choice;
    string menuTitle = "Welcome To "+ pw->getPosition() + " Menu";
    string options[] = {
       "Press 1 to see messages",
        "Press 2 to View My Tasks",
        "Press 3 to Assign New Task",
        "Press 4 to Delegate Task",
        "Press 5 to Exit"
    };
    
}




//-----------------------------------Code Execution start from here--------------------------------



#include <iostream>
#include <fstream>
#include <cstdio>   // for remove, rename
#include <string>
using namespace std;

void ReadingGlobalNoti(PaidWorkers* pw)    
{
    // 1) Open temp file for output (truncate so it starts empty)
    ofstream outTmp("GlobalNoti_tmp.txt");
    if (!outTmp) {
        cout << "\n\nError opening temp file\n\n";
        mainMenu();
    }

    // 2) Open original for reading
    ifstream in("GlobalNoti.txt");
    if (!in) {
        cout << "\n\nError opening GlobalNoti.txt\n\n";
        mainMenu();
    }

    int    id;
    string Sender_pos, message, reader_names;
    while (in >> id) {
        in.ignore(1);                            // skip the '|'
        getline(in, Sender_pos, '|');           // read sender position
        getline(in, message,    '|');           // read message
        getline(in, reader_names);              // read comma-sep seen list

        // 3) If user hasn't seen it yet, show it and append their name
        bool alreadySeen = (reader_names.find(pw->getName()) != string::npos);
        if (!alreadySeen) {
            cout << "\nNotification: " << message << "\n"
                 << "Sender Position: " << Sender_pos << "\n";
            if (!reader_names.empty())
                reader_names += ",";
            reader_names += pw->getName();
        }

        // 4) Write out either the updated or original record
        outTmp << id << "|" 
               << Sender_pos << "|" 
               << message    << "|" 
               << reader_names 
               << "\n";
    }

    in.close();
    outTmp.close();

    // 5) Replace old file with updated temp
    remove("GlobalNoti.txt");
    rename("GlobalNoti_tmp.txt", "GlobalNoti.txt");
}


int main()
{
    mainMenu();
    


}


void mainMenu()
{
    SetConsoleOutputCP(CP_UTF8);

    // Enable ANSI escape codes on Windows
    system("");

    int choice;
    string menuTitle = "Welcome To OFFICE PORTAL";
    string options[] = {
        "Press 1 to Login as Executive",
        "Press 2 to Login as Director",
        "Press 3 to Login as Manager",
        "Press 4 to Login as Employee",
        "Press 5 to Login as Junior",
        "Press 6 to Exit"
    };
    const int numOptions = 6;
    
    printMenu(menuTitle, options, numOptions);
    cout << BLUE << "\n          Enter your choice (1-5): " << RESET;
        cin >> choice;
    switch(choice)
    {
        case 1:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Executive");
            cout<<"insidemain"<<endl;
            if(pw->getLogin() == true)
            {
                ExecutiveMenu(pw);
            }
            else
            {
                mainMenu();
            }
            break;
        }
        case 2:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Director");
            if(pw->getLogin() == true)
            {
                DirectorMenu(pw);
            }
            break;
        }
        case 3:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Manager");
            if(pw->getLogin() == true)
            {
                ManagerMenu(pw);
            }
            break;
        }
        case 4:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Employee");
            if(pw->getLogin() == true)
            {
                EmployeeMenu(pw);
            }
            break;
        }
        case 5:
        {
            Authentication auth;
            PaidWorkers* pw = &auth.login("Junior");
            if(pw->getLogin() == true)
            {
                JuniorMenu(pw);
            }
            break;
        }
        case 6:
        {
            cout<<endl
                <<"Have a Good Day!"<<endl<<endl<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            mainMenu();
        }
    }
}


void readingInfoFile(PaidWorkers* pw)
{
    ifstream in("Info.txt");
    if (!in) {
        cout << "Error opening Info.txt\n";
        mainMenu();
        return;
    }

    // temp variables
    string sender,
           sendersPosition,
           receiver,
           message,
           isRead,
           dateTime;

    bool foundAny = false;

    // keep looping as long as we can read ALL six parts
    while (   getline(in, sender,        '|')
           && getline(in, sendersPosition,'|')
           && getline(in, receiver,       '|')
           && getline(in, message,        '|')
           && getline(in, isRead,         '|')
           && getline(in, dateTime)  // up to EOL
          )
    {
        // strip any stray '\r' (if your file has Windows CRLF)
        if (!receiver.empty() && receiver.back() == '\r')
            receiver.pop_back();

        if (receiver == pw->getPosition()) {
            foundAny = true;
            string option[5] = {"Sender: " + sender,
                "Position: " + sendersPosition,
                "Message: " + message,
                "Date & Time: " + dateTime};
            printMenu("INFO MESSAGE", option, 4);

        }
    }

    if (!foundAny) {
        cout <<RED<< "\nNo messages found for " << pw->getName() << RESET<<"\n";
        show_Message_menu(pw);
    }
}


void viewMyTasks(PaidWorkers* pw) {
    SetConsoleOutputCP(CP_UTF8);
    // Enable ANSI escape codes on Windows
    system("");
    cout<<YELLOW<<"\n\n          Welcome to your Task Menu" << RESET << endl;

    // --- First pass: count how many tasks are assigned to this user ---
    ifstream in("Task.dat");
    if (!in) {
        cerr << "Error opening Task.dat" << endl;
        return;
    }

    int total = 0;
    string task_name, task_description, task_status;
    string task_assigned_by, task_assigned_by_position;
    string task_assigned_to, task_assigned_to_pos;
    string task_priority, task_assigned_time;
    int task_ttl_time;

    while (getline(in, task_name, '|')) {
        getline(in, task_description,           '|');
        getline(in, task_status,                '|');
        getline(in, task_assigned_by,           '|');
        getline(in, task_assigned_by_position,  '|');
        getline(in, task_assigned_to,           '|');
        getline(in, task_assigned_to_pos,       '|');
        getline(in, task_priority,              '|');
        in >> task_ttl_time;
        in.ignore(1);
        getline(in, task_assigned_time);

        if (task_assigned_to == pw->getName()) {
            total++;
        }
    }
    in.close();

    if (total == 0) {
        cout << GREEN << "\n          No tasks assigned to you " << RESET << "\n";
        return;
    }

    // --- Allocate array for just your tasks ---
    task* arr = new task[total];
    int idx = 0;

    // --- Second pass: load your tasks into arr ---
    in.open("Task.dat");
    while (idx < total && getline(in, task_name, '|')) {
        getline(in, task_description,           '|');
        getline(in, task_status,                '|');
        getline(in, task_assigned_by,           '|');
        getline(in, task_assigned_by_position,  '|');
        getline(in, task_assigned_to,           '|');
        getline(in, task_assigned_to_pos,       '|');
        getline(in, task_priority,              '|');
        in >> task_ttl_time;
        in.ignore(1);
        getline(in, task_assigned_time);

        if (task_assigned_to == pw->getName()) {
            arr[idx].setTaskName(task_name);
            arr[idx].setTaskDescription(task_description);
            arr[idx].setTaskStatus(task_status);
            arr[idx].setTaskAssignedBy(task_assigned_by);
            arr[idx].setTaskAssignedTo(task_assigned_to);
            arr[idx].setTaskAssignedToPosition(task_assigned_to_pos);
            arr[idx].setTaskPriority(task_priority);
            arr[idx].setTTLTime(task_ttl_time);
            arr[idx].setAssignedTime(task_assigned_time);
            idx++;
        }
    }
    in.close();

    // --- Bubble‐sort arr by priority High>Medium>Low ---
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            int rj  = (arr[j].getTaskPriority() == "High"   ? 3
                      : arr[j].getTaskPriority() == "Medium" ? 2
                                                              : 1);
            int rj1 = (arr[j+1].getTaskPriority() == "High"   ? 3
                       : arr[j+1].getTaskPriority() == "Medium" ? 2
                                                               : 1);
            if (rj < rj1) {
                task tmp = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    // --- Display sorted tasks and allow status change ---
    cout << BLUE << "\n          Your Tasks: " << RESET << endl;
    for (int i = 0; i < total; i++) {
        const int numOptions = 9;
        string options[numOptions] = {
            "Task Name: " + arr[i].getTaskName(),
            "Task Description: " + arr[i].getTaskDescription(),
            "Task Status: " + arr[i].getTaskStatus(),
            "Task Assigned By: " + arr[i].getTaskAssignedBy(),
            "Task Assigned To: " + arr[i].getTaskAssignedTo(),
            "Task Assigned To Position: " + arr[i].getTaskAssignedToPosition(),
            "Task Priority: " + arr[i].getTaskPriority(),
            "Task Assigned Time: " + arr[i].getAssignedTime(),
            "Task Total Time: " + to_string(arr[i].getTTLTime())
        };
        printMenu(" TASK DETAILS ", options, numOptions);

        string statusOpts[] = {
            "Press 1 for In Progress",
            "Press 2 for Completed",
            "Press 3 for Incompetent"
        };
        const int numStatus = 3;
        printMenu(" TASK STATUS ", statusOpts, numStatus);
        cout << BLUE << "\n          Enter your choice (1-3): " << RESET;
        int status;
        cin >> status;

        if (status == 1) {
            arr[i].setTaskStatus("In Progress");
            cout << BLUE << "\n          KEEP IT UP !!! " << RESET;
        }
        else if (status == 2) {
            arr[i].setTaskStatus("Completed");
            cout << BLUE << "\n          WELL DONE !!! " << RESET;
        }
        else if (status == 3) {
            arr[i].setTaskStatus("Incompetent");
            cout << BLUE << "\n          ALERT GENERATED !!! " << RESET;
            string message = pw->getName()
                           + " isn't competent enough to complete ("
                           + arr[i].getTaskName() + ") task";
            ALERT alert(message, pw->getName(), arr[i].getTaskAssignedBy());
            ofstream alertOut("Alert.txt", ios::app);
            if (alertOut) {
                time_t now = std::time(nullptr);
                char* dateTime = std::ctime(&now);
                alertOut << alert.getSender() << "|"
                         << pw->getPosition()    << "|"
                         << alert.getReceiver()  << "|"
                         << alert.getMessage()   << "|"
                         << alert.getIsRead()    << "|"
                         << dateTime;
            }
        }
        else {
            cout << RED << "\n          Invalid Option " << RESET;
            continue;
        }

        cout << GREEN << "\n          Task Status Updated Successfully " << RESET << "\n\n";
    }

    // --- Final pass: rewrite Task.dat with updated statuses ---
    ifstream in3("Task.dat");
    ofstream out3("Tasktemp.dat");
    if (!in3 || !out3) {
        cerr << "Error opening files for rewrite" << endl;
        delete[] arr;
        return;
    }

    int writeIdx = 0;
    while (getline(in3, task_name, '|')) {
        getline(in3, task_description,          '|');
        getline(in3, task_status,               '|');
        getline(in3, task_assigned_by,          '|');
        getline(in3, task_assigned_by_position, '|');
        getline(in3, task_assigned_to,          '|');
        getline(in3, task_assigned_to_pos,      '|');
        getline(in3, task_priority,             '|');
        in3 >> task_ttl_time;
        in3.ignore(1);
        getline(in3, task_assigned_time);

        if (task_assigned_to == pw->getName()) {
            task_status = arr[writeIdx].getTaskStatus();
            writeIdx++;
        }

        out3 << task_name                << "|"
             << task_description         << "|"
             << task_status              << "|"
             << task_assigned_by         << "|"
             << task_assigned_by_position<< "|"
             << task_assigned_to         << "|"
             << task_assigned_to_pos     << "|"
             << task_priority            << "|"
             << task_ttl_time            << "|"
             << task_assigned_time       << "\n";
    }
    in3.close();
    out3.close();

    remove("Task.dat");
    rename("Tasktemp.dat", "Task.dat");

    delete[] arr;
}



void assignTask(PaidWorkers* pw) {
    PolicyEngine pe(pw);
    cout << YELLOW << "\n\n          Assign Task Menu" << RESET << endl;

    string menuTitle = "Assign Task";
    string options[] = {
        "Press 1 to Assign Task to Junior",
        "Press 2 to Assign Task to Employee",
        "Press 3 to Assign Task to Manager",
        "Press 4 to Assign Task to Director",
        "Press 5 to Assign Task to Executive"
    };
    const int numOptions = 5;
    printMenu(menuTitle, options, numOptions);
    cout << BLUE << "\n          Enter your choice (1-5): " << RESET;
    int choice2;
    cin >> choice2;

    

    PaidWorkers* p = nullptr;
    switch (choice2) {
      case 1:
        cout << YELLOW << "\n          Progressing to Assign task to Junior" << RESET << endl;
        p = new Junior;
        break;
      case 2:
        cout << YELLOW << "\n          Progressing to Assign task to Employee" << RESET << endl;
        p = new Employee;
        break;
      case 3:
        cout << YELLOW<<  "\n          Progressing to Assign task to Manager" << RESET << endl;
        p = new Manager;
        break;
      case 4:
        cout << YELLOW << "\n          Progressing to Assign task to Director" << RESET << endl;
        p = new Director;
        break;
      case 5:
        cout << YELLOW << "\n          Progressing to Assign task to Executive" << RESET << endl;
        p = new Executive;
        break;
      default:
        cout << RED << "\n          Invalid Option " << RESET << endl;
        delete p;                // safeguard
        return;                  // back to caller menu
    }

    // Prompt for the specific user name
    cout <<BLUE<< "\n          Enter the name of the user to assign task to: ";
    cin.ignore();
    string name;
    getline(cin, name);

    // Open the appropriate role file
    ifstream in(p->getPosition() + ".txt");
    if (!in) {
        cerr << "Error opening " << p->getPosition() << ".txt\n";
        delete p;
        return;
    }

    // Parse lines like: 1254|mannan|Manager|qF{T|1000|15
    bool found = false;
    while (!found && in.good()) {
        int    id, salary, points;
        string file_name, position, password;
        in >> id;            in.ignore(1);
        getline(in, file_name, '|');
        getline(in, position,  '|');
        getline(in, password,  '|');
        in >> salary;        in.ignore(1);
        in >> points;        in.ignore(1);

        if (file_name == name) {
            found = true;
            p->setID(id);
            p->setPosition(position);
            p->setName(file_name);
            p->setPassword(password);
            p->setSalary(salary);
        }
    }
    in.close();

    if (!found) {
        cout<<RED<< "\n          User not found in " << p->getPosition() << ".txt\n" << RESET;
        delete p;
        return;
    }

    cout<<GREEN<< "\n          User found: " << p->getName() << RESET << endl;
    if (pe.Assign_Task(p)) {
        cout<<GREEN<< "\n          Task Assigned Successfully " << RESET << endl;
    } else {
        cout << "Task Assignment Failed!\n\n";
    }

    delete p;
}

void delegateIncompetentTasks(PaidWorkers* pw) {
    cout << "Checking for Incompetent Tasks" << endl;

    ifstream in("Task.dat");
    ofstream out("Tasktemp.dat");
    if (!in) {
        cerr << "\n\nError opening Task.dat\n\n";
        return;
    }

    bool foundAny = false;
    string task_name, task_description, task_status;
    string task_assigned_by, task_assigned_by_position;
    string task_assigned_to, task_assigned_to_pos;
    string task_priority, task_assigned_time;
    int    task_ttl_time;

    while (getline(in, task_name, '|')) {
        getline(in, task_description,   '|');
        getline(in, task_status,        '|');
        getline(in, task_assigned_by,   '|');
        getline(in, task_assigned_by_position, '|');
        getline(in, task_assigned_to,   '|');
        getline(in, task_assigned_to_pos, '|');
        getline(in, task_priority,      '|');
        in >> task_ttl_time;
        in.ignore(1);
        getline(in, task_assigned_time);

        // If it's your “Incompetent” task, offer to re-delegate it
        if (!foundAny
            && task_assigned_by == pw->getName()
            && task_status    == "Incompetent")
        {
            foundAny = true;

            // Build a PaidWorkers* for the old assignee
            PaidWorkers* prev_p = nullptr;
            if      (task_assigned_to_pos == "Junior")    prev_p = new Junior;
            else if (task_assigned_to_pos == "Employee")  prev_p = new Employee;
            else if (task_assigned_to_pos == "Manager")   prev_p = new Manager;
            else if (task_assigned_to_pos == "Director")  prev_p = new Director;
            else if (task_assigned_to_pos == "Executive") prev_p = new Executive;
            else {
                cerr << "Unknown previous role: " << task_assigned_to_pos << "\n";
            }

            // Show task details
            const int numOptions = 10;
            string options[numOptions] = {
                "Task Name: "               + task_name,
                "Task Description: "        + task_description,
                "Task Status: "             + task_status,
                "Task Assigned By: "        + task_assigned_by,
                "Task By Position: "        + task_assigned_by_position,
                "Task Assigned To: "        + task_assigned_to,
                "Task To Position: "        + task_assigned_to_pos,
                "Task Priority: "           + task_priority,
                "Task Assigned Time: "      + task_assigned_time,
                "Task Total Time: "         + to_string(task_ttl_time)
            };
            printMenu(" TASK DETAILS ", options, numOptions);

            // Choose new role
            cout << "\nEnter the position to delegate to:\n"
                 << " 1) Junior\n"
                 << " 2) Employee\n"
                 << " 3) Manager\n"
                 << " 4) Director\n"
                 << " 5) Executive\n"
                 << "Option: ";
            int choice; cin >> choice;

            PaidWorkers* new_p = nullptr;
            switch (choice) {
              case 1: cout<<"Assigning to Junior\n";   new_p = new Junior;   break;
              case 2: cout<<"Assigning to Employee\n"; new_p = new Employee; break;
              case 3: cout<<"Assigning to Manager\n";  new_p = new Manager;  break;
              case 4: cout<<"Assigning to Director\n"; new_p = new Director; break;
              case 5: cout<<"Assigning to Executive\n";new_p = new Executive;break;
              default:
                cout<<"Invalid Option\n\n";
                delete prev_p;
                out << task_name << '|' << task_description << '|' 
                    << task_status << '|' << task_assigned_by << '|' 
                    << task_assigned_by_position << '|' << task_assigned_to 
                    << '|' << task_assigned_to_pos << '|' << task_priority 
                    << '|' << task_ttl_time << '|' << task_assigned_time 
                    << "\n";
                continue;
            }

            // Policy check
            PolicyEngine policy(pw);
            if (!policy.can_delegate_task(new_p, prev_p)) {
                cout << "You are not allowed to delegate this task!\n\n";
                delete prev_p;
                delete new_p;
                out << task_name << '|' << task_description << '|' 
                    << task_status << '|' << task_assigned_by << '|' 
                    << task_assigned_by_position << '|' << task_assigned_to 
                    << '|' << task_assigned_to_pos << '|' << task_priority 
                    << '|' << task_ttl_time << '|' << task_assigned_time 
                    << "\n";
                continue;
            }

            // Prompt for actual user name
            cin.ignore(1,'\n');
            cout << "Enter the user name to assign to: ";
            string uname; getline(cin, uname);

            // Look up that user in new_p->getPosition() + ".txt"
            ifstream userF(new_p->getPosition() + ".txt");
            bool userFound = false;
            while (!userFound && userF.good()) {
                int   id, salary, points;
                string file_name, pos, pwd;
                userF >> id; userF.ignore(1);
                getline(userF, file_name, '|');
                getline(userF, pos,       '|');
                getline(userF, pwd,       '|');
                userF >> salary; userF.ignore(1);
                userF >> points; userF.ignore(1);

                if (file_name == uname) {
                    userFound = true;
                    new_p->setID(id);
                    new_p->setPosition(pos);
                    new_p->setName(file_name);
                    new_p->setPassword(pwd);
                    new_p->setSalary(salary);
                }
            }
            userF.close();

            if (!userFound) {
                cout << "\nUser not found\n\n";
                delete prev_p;
                delete new_p;
                out << task_name << '|' << task_description << '|' 
                    << task_status << '|' << task_assigned_by << '|' 
                    << task_assigned_by_position << '|' << task_assigned_to 
                    << '|' << task_assigned_to_pos << '|' << task_priority 
                    << '|' << task_ttl_time << '|' << task_assigned_time 
                    << "\n";
                continue;
            }

            // Perform the delegation
            if (policy.Assign_Task(new_p)) {
                task_assigned_to     = new_p->getName();
                task_assigned_to_pos = new_p->getPosition();
                task_status          = "Assigned";
                cout << "Task delegated successfully to " 
                     << task_assigned_to << "!\n\n";
            } else {
                cout << "Task delegation failed!\n\n";
            }

            // Write updated record
            out << task_name << '|' << task_description << '|' 
                << task_status << '|' << task_assigned_by << '|' 
                << task_assigned_by_position << '|' << task_assigned_to 
                << '|' << task_assigned_to_pos << '|' << task_priority 
                << '|' << task_ttl_time << '|' << task_assigned_time 
                << "\n";

            delete prev_p;
            delete new_p;
        }
        else {
            // Not eligible → copy unchanged
            out << task_name << '|' << task_description << '|' 
                << task_status << '|' << task_assigned_by << '|' 
                << task_assigned_by_position << '|' << task_assigned_to 
                << '|' << task_assigned_to_pos << '|' << task_priority 
                << '|' << task_ttl_time << '|' << task_assigned_time 
                << "\n";
        }
    }

    in.close();
    out.close();
    remove("Task.dat");
    rename("Tasktemp.dat", "Task.dat");

    if (!foundAny) {
        cout << "\n\nNo Incompetent tasks—all tasks are being worked on!\n\n";
    }
}


void show_Message_menu(PaidWorkers * pw)
{
    SetConsoleOutputCP(CP_UTF8);
    #define BLUE "\033[34m"
        #define YELLOW "\033[93m"
        #define GREEN "\033[32m"
        #define RED "\033[31m"

    string menuTitle = "Welcome To Message Menu";
    string options[] = {
        "Press 1 to send INFO",
        "Press 2 to send a private message",
        "Press 3 to send an Alert",
        "Press 4 to view Info",
        "Press 5 to view private Message",
        "Press 6 to view alerts",
        "Press 7 to Exit"
    };
    const int numOptions = 7;
    printMenu(menuTitle, options, numOptions);
    cout << BLUE << "\n          Enter your choice (1-7): " << RESET;
    int choice1;
    cin >> choice1;
    switch(choice1)
    {
        case 1:
        {
            PolicyEngine pe(pw);
            string option[5] = {"Press 1 for Junior",
                "Press 2 for Employee",
                "Press 3 for Manager",
                "Press 4 for Director",
                "Press 5 for Executive"};
             printMenu("Sending INFO", option, 5);
            int choice2;
            cout<< BLUE << "\n          Enter your choice (1-5): " << RESET;
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<< BLUE << "\n          Sending message to Junior" << RESET << endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<< BLUE << "\n          Sending message to Employee" << RESET << endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<< BLUE << "\n          Sending message to Manager" << RESET << endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<< BLUE << "\n          Sending message to Director" << RESET << endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<< BLUE << "\n          Sending message to Executive" << RESET << endl;
                p = new Executive;
            }
            else
            {
                cout<< RED << "\n          Invalid Option" << RESET << endl<<endl<<endl;
                show_Message_menu(pw);
            }

            if(pe.can_send_info(p) == true)
            {
                cout<< GREEN << "\n          Message Sent Successfully!" << RESET << endl;
            }
            else
            {
                cout<< RED << "\n          Message Sending Failed!" << RESET << endl;
            }
            
            break;
        }
        case 2:
        {
            #define BLUE "\033[34m"
        #define YELLOW "\033[93m"
        #define GREEN "\033[32m"
        #define RED "\033[31m"
            //sending private message
            cout<<GREEN<<"Sending private message"<<RESET<<endl;

            string option[5] = {"Press 1 for Junior",
                "Press 2 for Employee",
                "Press 3 for Manager",
                "Press 4 for Director",
                "Press 5 for Executive"};
            printMenu("Sending Private Message", option, 5);
            int choice2;
            cout<<YELLOW<<"Press your option to continue: "<<RESET;
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                
                cout<<YELLOW<<"Sending message to Junior"<<RESET<<endl;
                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<YELLOW<<"Sending message to Employee"<<RESET<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<YELLOW<<"Sending message to Manager"<<RESET<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<YELLOW<<"Sending message to Director"<<RESET<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<YELLOW<<"Sending message to Executive"<<RESET<<endl;
                p = new Executive;
            }
            else
            {
                cout<<RED<<"Invalid Option"<<RESET<<endl<<endl<<endl;
                show_Message_menu(pw);
            }
            cout<<YELLOW<<"Enter the name of the person you want to send message to: "<<RESET<<endl;
            string name;
            cin.ignore(); // clear the newline character from the input buffer
            getline(cin, name); // read the entire line including spaces
            //opening the file to check if the person exists or not
            //finding the person in the file
            ifstream in;
            in.open("./"+p->getPosition()+".txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            
            //1254|mannan|Manager|qF{T|1000|15

            int id, salary, points;
            string file_name, position, password;

            bool found = false;
            while ( in>>id)
            {
                //1234|moiz|Executive|1234|1000|23
                in.ignore(1);
                getline(in, file_name, '|');
                getline(in, position, '|');
                getline(in, password, '|');
                in>>salary;
                in.ignore(1);
                in>>points;
                in.ignore(1);

                if(file_name == name)
                {
                    found = true;
                    p->setID(id);
                    p->setPosition(position);
                    p->setName(file_name);
                    p->setPassword(password);
                    p->setSalary(salary);
                    break;
                }
            }
            in.close();
            if(found == false)
            {
                cout<< RED << "\n\nUser not found\n\n" << RESET;
                show_Message_menu(pw);
                break;
            }


            cout<<YELLOW<<"Enter the message you want to send: "<<RESET<<endl;
            string message;; // clear the newline character from the input buffer
            getline(cin, message); // read the entire line including spaces
            //PRIVATE(const string& m, const string& s, const string& r, int id)
            cout<<YELLOW<<"MESSAGE : "<<message<<RESET<<endl;
            PRIVATE *pmsg = new PRIVATE(message, pw->getName(), p->getName(), p->getID());
            pmsg->saveToFile();  // ADD THIS LINE
            cout<<GREEN<<"Message Sent Successfully!"<<RESET<<endl;
            delete pmsg;  // Clean up
            break;
        }
        case 3:
        {
            string option[5] = {"Press 1 for Junior",
                "Press 2 for Employee",
                "Press 3 for Manager",
                "Press 4 for Director",
                "Press 5 for Executive"};
            printMenu("Sending Alert", option, 5);
             cout<<YELLOW<<"Sending alert"<<RESET<<endl;

            int choice2;
            cout<<YELLOW<<"Press your option to continue: "<<RESET;
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<YELLOW<<"Sending message to Junior"<<RESET<<endl;

                p = new Junior;

            }
            else if(choice2 == 2)
            {
                cout<<YELLOW<<"Sending message to Employee"<<RESET<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<YELLOW<<"Sending message to Manager"<<RESET<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<YELLOW<<"Sending message to Director"<<RESET<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<YELLOW<<"Sending message to Executive"<<RESET<<endl;
                p = new Executive;
            }
            else
            {
                cout<<RED<<"Invalid Option"<<RESET<<endl<<endl<<endl;
                show_Message_menu(pw);
            }
            cout<<YELLOW<<"Enter the name of the person you want to send message to: "<<RESET<<endl;
            string name;
            cin.ignore(); // clear the newline character from the input buffer
            getline(cin, name); // read the entire line including spaces
            //opening the file to check if the person exists or not
            //finding the person in the file
            ifstream in;
            in.open("./"+p->getPosition()+".txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            
            //1254|mannan|Manager|qF{T|1000|15

            int id, salary, points;
            string file_name, position, password;

            bool found = false;
            while ( in>>id)
            {
                //1234|moiz|Executive|1234|1000|23
                in.ignore(1);
                getline(in, file_name, '|');
                getline(in, position, '|');
                getline(in, password, '|');
                in>>salary;
                in.ignore(1);
                in>>points;
                in.ignore(1);

                if(file_name == name)
                {
                    found = true;
                    p->setID(id);
                    p->setPosition(position);
                    p->setName(file_name);
                    p->setPassword(password);
                    p->setSalary(salary);
                    break;
                }
            }
            in.close();
            if(found == false)
            {
                cout<< RED << "\n\nUser not found\n\n" << RESET;
                break;
            }


            PolicyEngine pe(pw);
            if(pe.can_send_alert(p) == true)
            {
                cout<< GREEN << "\n          Message Sent Successfully!" << RESET << endl;

            }
            else
            {
                cout<< RED << "\n          Message Sending Failed!" << RESET << endl;
                show_Message_menu(pw);
            }


        }
        case 4:
        {
            //viewing info messages
            cout<<YELLOW<<"Viewing info messages"<<RESET<<endl;
            readingInfoFile(pw);

            break;
        }
        case 5:
        {
            #define BLUE "\033[34m"
            #define YELLOW "\033[93m"
            #define GREEN "\033[32m"
            #define RED "\033[31m"

            
            //viewing private messages
            cout<<YELLOW<<"Viewing private messages"<<RESET<<endl;
            ifstream in;
            in.open("private_messages.txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            

            //Sannan|mannan|1254|gu fcffa

            string sender, receiver, message;
            int id;


            bool found = false;
            while (getline(in, sender, '|'))
            {
                getline(in, receiver, '|');
                in>>id;
                in.ignore(1);
                getline(in, message, '\n');
                if(receiver == pw->getName())
                {
                    //decoding the message
                    found = true;
                    string options[3] = {"Sender: " + sender,
                        "Receiver: " + receiver,
                        "Encrypted Message: " + message,};
                        cout<<"DEBUG :" <<id<<endl;
                    printMenu("PRIVATE MESSAGE", options, 3);
                        decryptInteractive(message, id);
                }
            }
            in.close();

            if(found == false)
            {
                cout << "\n\nNo messages found for " << pw->getName() << "\n";
                show_Message_menu(pw);
            }
               


            break;
        }
        case 6:
        {
            //viewing alerts
            cout<<YELLOW<<"Viewing alerts"<<RESET<<endl;

            // 1) Open original for reading, temp for writing
            ifstream  in ("Alert.txt", ios::in);
            ofstream  out("Alert.tmp", ios::out);
            if (!in || !out)
            {
                cout << "\nError opening file\n\n";
                // make sure to clean up if necessary
                return;
            }

        string sender, sendersPosition, receiver, message, isRead, dateTime;
        bool   foundAny = false;

// 2) Read each record
            while (   getline(in, sender,        '|')
            && getline(in, sendersPosition,'|')
            && getline(in, receiver,       '|')
            && getline(in, message,        '|')
            && getline(in, isRead,         '|')
            && getline(in, dateTime))           // up to end-of-line
            {
                
            if (!dateTime.empty() && dateTime.back() == '\r')
            {
                dateTime.pop_back();
            }

    // 3) If this alert is for me, display it and mark it read
            if (receiver == pw->getName() && isRead == "0")
            {
                string options[4] = {"Sender: " + sender,
                    "Position: " + sendersPosition,
                    "Message: " + message,
                    "Date & Time: " + dateTime};
                printMenu("ALERT", options, 4);


                isRead = "1";
            }
            

            // 4) Write the (possibly updated) record to temp
            out << sender          << '|'
            << sendersPosition << '|'
            << receiver        << '|'
            << message         << '|'
            << isRead          << '|'
            << dateTime        << "\n";
        }

        in.close();
        out.close();

        // 5) Replace original with temp
        if (remove("Alert.txt") != 0)
        {
            cout << "Error deleting original alerts file\n";
        }
        else if (rename("Alert.tmp", "Alert.txt") != 0)
        {
            cout << "Error renaming temp file\n";
        }

        if (!foundAny)
        {
            cout<< RED << "\n\n        No alerts found for " << pw->getName() << "\n" << RESET;
        }

            break;
        }
        default:
        {
            cout<<RED<<"Invalid Option"<<RESET<<endl<<endl<<endl;
            show_Message_menu(pw);
        }
    }
}

void ExecutiveMenu(PaidWorkers* pw)
{
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                          #===========================================#"<<endl
    <<"                              #          Executive Menu                   #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View Messages         #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Assign New Task       #"<<endl
    <<"                              #          Press 3 to Add New               #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {   
            show_Message_menu(pw);
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {
            PolicyEngine pe(pw);
            cout<<"Enter the position of the person you want to assign task to"<<endl
                <<"Press 1 for Junior"<<endl
                <<"Press 2 for Employee"<<endl
                <<"Press 3 for Manager"<<endl
                <<"Press 4 for Director"<<endl
                <<"Press 5 for Executive"<<endl;
            int choice2;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            PaidWorkers* p = NULL;
            if(choice2 == 1)
            {
                cout<<"Progressing to Assign task to Junior"<<endl;
                p = new Junior;
            }
            else if(choice2 == 2)
            {
                cout<<"Progressing to Assign task to Employee"<<endl;
                p = new Employee;
            }
            else if(choice2 == 3)
            {
                cout<<"Progressing to Assign task to Manager"<<endl;
                p = new Manager;
            }
            else if(choice2 == 4)
            {
                cout<<"Progressing to Assign task to Director"<<endl;
                p = new Director;
            }
            else if(choice2 == 5)
            {
                cout<<"Progressing to Assign task to Executive"<<endl;
                p = new Executive;
            }
            else
            {
                cout<<"Invalid Option"<<endl<<endl<<endl;
                ExecutiveMenu(pw);
            }

            cout<<"Enter the name of the person you want to assign task to"<<endl;
            string name;
            cin.ignore();
            getline(cin, name);

            //checking if the user exists or not
                        ifstream in;
            in.open("./"+p->getPosition()+".txt", ios::in);
            if(!in)
            {
                cout<<endl<<endl
                    <<"Error opening file"<<endl<<endl;
                mainMenu();
            }
            
            //1254|mannan|Manager|qF{T|1000|15

            int id, salary, points;
            string file_name, position, password;

            bool found = false;
            while ( in>>id)
            {
                //1234|moiz|Executive|1234|1000|23
                in.ignore(1);
                getline(in, file_name, '|');
                getline(in, position, '|');
                getline(in, password, '|');
                in>>salary;
                in.ignore(1);
                in>>points;
                in.ignore(1);

                if(file_name == name)
                {
                    found = true;
                    p->setID(id);
                    p->setPosition(position);
                    p->setName(file_name);
                    p->setPassword(password);
                    p->setSalary(salary);
                    break;
                }
            }
            in.close();
            if(found == false)
            {
                cout << "\n\nUser not found\n\n";
                ExecutiveMenu(pw);
                break;
            }
            cout<<"User found"<<endl;
            PolicyEngine pe1(pw);
            if(pe1.Assign_Task(p) == true)
            {
                cout<<"Task Assigned Successfully!"<<endl;
            }
            else
            {
                cout<<"Task Assignment Failed!"<<endl;
            }
            cout<<endl<<endl;
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ExecutiveMenu(pw);
        }
    }
}


void DirectorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice;
    string menuTitle = "DIRRECTORS MENU";
    string options[] = {
        "Press 1 to see messages",
        "Press 2 to View My Tasks",
        "Press 3 to Assign New Task",
        "Press 4 to Delegate Task",
        "Press 5 to Generate Audit Report",
        "Press 6 to View ALL Logs",
        "Press 7 to Exit"
    };
    const int numOptions = 7;
    
    printMenu(menuTitle, options, numOptions);
    cout << BLUE << "\n          Enter your choice (1-7): " << RESET;
        cin >> choice;


    switch(choice)
    {
        case 1:
        {
            show_Message_menu(pw);
            break;
        }
        case 2:
        {
            viewMyTasks(pw);
            break;
        }
        case 3:
        {
            assignTask(pw);
            break;
        }
        case 4:
        {
            delegateIncompetentTasks(pw);
            break;
        }
        case 5:
        {   
            cout<<"Incase 5"<<endl;
            pe.generateAudit();
            break;
        }
        case 6:
        {
            pe.readAllLogs();
            break;
        }
        case 7: 
        {
            mainMenu();
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            DirectorMenu(pw);
        }
    }

}


void ManagerMenu(PaidWorkers* pw){
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Manager Menu                     #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to ADD NEW Employee      #"<<endl
    <<"                              #          Press 5 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            cout<<"Press 1 for Hiring New Employee"<<endl;
            cout<<"Press 2 for Hiring New Junior"<<endl;
            cout<<"Press 3 to Go Back"<<endl;
            int choice2 = 0;
            cout<<"Press your option to continue: ";
            cin>>choice2;
            switch(choice2)
            {
                case 1:
                {
                    Authentication auth;
                    auth.addUser("Employee");
                    break;
                }
                case 2:
                {
                    Authentication auth;
                    auth.addUser("Junior");
                    break;
                }
                case 3:
                {
                    ManagerMenu(pw);
                    break;
                }
                default:
                {
                    cout<<"Invalid Option"<<endl<<endl<<endl;
                    ManagerMenu(pw);
                }
            }
            
            break;
        }
        case 5:
        {
            mainMenu();
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            ManagerMenu(pw);
        }
    }
}


void EmployeeMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Employee Menu                    #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to open Message menu     #"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            show_Message_menu(pw);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            EmployeeMenu(pw);
        }
    }
}


void JuniorMenu(PaidWorkers* pw)
{
    PolicyEngine pe(pw);
    int choice1 = 0;
    cout<<endl<<endl<<endl;
    cout<<"                              #===========================================#"<<endl
    <<"                              #          Junior Menu                      #"<<endl
    <<"                              #===========================================#"<<endl
    <<"                              #          Press 1 to View All Tasks        #"<<endl
    <<"                              #          Press 2 to View My Tasks         #"<<endl
    <<"                              #          Press 3 to Add New Task          #"<<endl
    <<"                              #          Press 4 to Exit                  #"<<endl
    <<"                              #===========================================#"<<endl<<endl<<endl;

    cout<<"Press your option to continue: ";
    cin>>choice1;
    switch(choice1)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"Invalid Option"<<endl<<endl<<endl;
            JuniorMenu(pw);
        }
    }
}

