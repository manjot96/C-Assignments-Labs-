#include "a1.h"

/*A struct that is used by sort algorithm to sort Student ID's based up the boolean that is passed in(either ascending or desending)*/
struct cmpID {
    bool flag;
    cmpID(const bool& x) : flag(x) {}
    bool operator()(Student& lhs, Student& rhs) const {
        if(flag)
            return lhs.getId() > rhs.getId();
            
        return lhs.getId() < rhs.getId();
    }
};
/*Whenever input is recieved from the user, the first word and the student record is 
passed into this function to verify that the first word is valid and based on that it sorts a student record.*/
size_t sortShow(const string& s, vector<Student>& record) {
    bool flag;
    int returnValue = 1;
    
    if(s == "show")
        flag    = false;
    else if(s == "-show")
        flag    = true;
    else if(s == "showid") {
        flag    = false;
        returnValue = 2;
    } else if(s == "-showid") {
        flag    = true;
        returnValue = 2;
    } else
        return 0;
    
    sort(record.begin(), record.end(), cmpID(flag));    
    return returnValue;
}
/*Prints either the ID or the entire student record based on the first paramter of the input.*/
inline void output(const string& s, const Student& x) {
    if(s != "showid" && s != "-showid")
        x.display(cout);
    else
        cout << x.getId() << endl;
}
/*Handles the output whenever the user enters just show or showid by itself*/
void handleShow(const vector<Student>& record, const vector<string>& commands) {
	for(auto& x : record)
        output(commands[0], x);
}
/*Handles the output whenever the user enters showid*/
void handleShowID(const vector<Student>& record, const vector<string>& commands) {
	for(auto& x: record)
        if(x.getId() == commands[2])
            output(commands[0], x);
}
/*Handles the output whenever the user enters show name*/
void handleShowName(const vector<Student>& record, const vector<string>& commands) {
    if(commands[2] == "*" && commands[3] == "*")
        for(auto& x: record)
            output(commands[0], x);
    else if(commands[2] == "*")
        for(auto& x: record) {
            auto name = x.getName();
            if(name.second == commands[3])
                output(commands[0], x);
        }
    else if(commands[3] == "*")
        for(auto& x: record) {
            auto name = x.getName();
            if(name.first == commands[2])
                output(commands[0], x);
        }
    else
        for(auto& x: record) {
            auto name = x.getName();
            if(name.first == commands[2] && name.second == commands[3])
                output(commands[0], x);
        }
}
/*Handles the output whenever the user enters show grade */
void handleShowGrade(const vector<Student>& record, const vector<string>& commands, const size_t& size) {
	if(size == 4) {
		for(auto& x: record)
		    for(auto& g : x.getGrades())
		        if(g.first == commands[2] && g.second == atoi(commands[3].c_str()))
		            output(commands[0], x);
    } else if(size == 5) {
		for(auto& x: record)
		    for(auto& g : x.getGrades())
		        if(g.first == commands[2])
		            if(atoi(commands[3].c_str()) <= g.second && atoi(commands[4].c_str()) >= g.second)
		                output(commands[0], x);
    }
}

int main(int argc, char** argv) {
    if(argc < 2)
        return 1;
        
    ifstream        data(argv[1]);
    vector<Student> record;
    vector<string>  commands;
    Student         s;
    string          input, word;
    size_t          size;
    istringstream   ss;
    const string    prompt = "Please input your command: ";
    
    //Reading in all the students from a file
    while(data >> s)
        record.push_back(s);

    while(1) {
        if(commands.size() != 0)
            commands.clear();
        if(ss.fail())
            ss.clear();
        
        cerr << prompt << endl;
        
        if(!getline(cin, input)) {
            cin.clear();
            break;
        }
        ss.str(input);
        //Scan all the words from the input(recieved from cin)
        while(ss >> word)
            commands.push_back(word);
        
        size = commands.size();
        if(size > 0 && size <= 5) {
            if(sortShow(commands[0], record) != 0) { //sortShow returns 0 when it gets a invalid input
                if(size == 1)
                    handleShow(record, commands);
                else if(commands[1] == "id")
                    handleShowID(record, commands);
                else if(commands[1] == "name")
                    handleShowName(record, commands);
                else if(commands[1] == "grade")
                    handleShowGrade(record, commands, size);
            }
        }
        cout << endl;
    }
}
