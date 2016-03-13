#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

typedef pair<string, string> 	Name;
typedef map<string, int>		Grades;

class Student {
	public:
		void display(ostream& os) const;
		friend istream& operator>>(istream& is, Student& s);
		friend struct CmpId;
		string getId() const {
        return id_;
		}
		Name getName() const {
			return name_;
		}
		Grades getGrades() const {
			return grades_;
		}
	private:
		string		id_; // e.g "a12345678"
		Name		name_; // e.g {"ned", "flanders"}
		Grades		grades_; // e.g {{"comp1510", 90}, {...}}
};

struct CmpId{
	string sortMethod; // "asc" or "desc"
	CmpId(string sortString):sortMethod(sortString){};
	
	bool operator()(const Student& s1, const Student& s2){
			if(sortMethod == "asc"){
				return s1.id_ < s2.id_;
			}else if(sortMethod == "desc"){
				return s1.id_ > s2.id_;
			}
			return false;
	}
};

void Student::display(ostream& os) const{
	
	os << id_ << endl;
	os << name_.first << ' ' << name_.second << endl;
	
	for(auto& x: grades_){
		os << x.first << ' ' << x.second << endl;
	}
}

istream& operator>>(istream& is, Student& s){
	string		id, firstName, lastName, course;
	int			courseCount, score;
	s.grades_.clear();
	if(is >> id) {
        is >> firstName;
        is >> lastName;
        
        s.id_ = id;
        s.name_.first = firstName;
        s.name_.second = lastName;
        
        is >> courseCount;
        
        for(int i = 0; i < courseCount; i++){
            is >> course;
            is >> score;
            s.grades_.insert(make_pair(course, score));
        }
    }
	return is;
}

void print(const bool showId, const Student& s){
	if(showId){
		cout << s.getId() << endl;
	}else{
		s.display(cout);
	}
}

int main(int argc, char* argv[]) {
	
	if(argc != 2){
		return 0;
	}
	
	ifstream 			data(argv[1]);	
	const string		prompt = "Please enter your command: ";	
	vector<Student>		records;
	Student 			student;

	while(data >> student){
		records.push_back(student);
	}
		
	do{
		vector<string> 	commands;
		istringstream 	iss;
		string 			line, word;
		bool			showId = false;
		
		cerr << prompt << endl;
		if(!(getline(cin, line))){
			cerr << "invalid input" << endl;
			iss.clear();
			break;
		}
		iss.str(line);
		
		while(iss >> word){
			commands.push_back(word);
		}
		
		if(commands.size() == 0){
			cout << endl;
			continue;
		}
		
		// sort records asc or desc based on command
		if(commands[0] == "show"){
			sort(records.begin(), records.end(), CmpId("asc"));
		}else if(commands[0] == "-show"){
			sort(records.begin(), records.end(), CmpId("desc"));
		}else if(commands[0] == "showid"){
			sort(records.begin(), records.end(), CmpId("asc"));
			showId = true;
		}else if(commands[0] == "-showid"){
			sort(records.begin(), records.end(), CmpId("desc"));
			showId = true;
		}else{
			cerr << "invalid command" << endl;
			cout << endl;
			continue;
		}
		
		if(commands.size() == 1){
			for(auto& x: records){
				print(showId, x);
			}
		}else if(commands[1] == "id"){
			for(auto& x: records){
				if(x.getId() == commands[2]){
					print(showId, x);
				}
			}
		}else if(commands[1] == "name"){
			if(commands[2] == "*" && commands[3] == "*"){
				for(auto& x: records){
					print(showId, x);
				}
			}else if(commands[2] == "*"){
				for(auto& x: records){
					auto lastName = x.getName().second;
					if(lastName == commands[3]){
						print(showId, x);
					}
				}
			}else if(commands[3] == "*"){
				for(auto& x: records){
					auto firstName = x.getName().first;
					if(firstName == commands[2]){
						print(showId, x);
					}
				}
			}else{
				for(auto& x: records){
					auto firstName = x.getName().first;
					auto lastName = x.getName().second;
					if(firstName == commands[2] && lastName == commands[3]){
						print(showId, x);
					}
				}
			}
		}else if(commands[1] == "grade"){
			if(commands.size() == 4){
				for(const auto& x: records){
                    const auto g = x.getGrades();
					auto p = g.find(commands[2]);
					int score = (p != g.end()) ? p->second : -1;
                    if(score != 1){
                        int inputScore = atoi(commands[3].c_str());
                        if(inputScore == score){
                            print(showId, x);
                        }
                    }
				}
			}else{
				for(const auto& x: records){
                    const auto g = x.getGrades();
					auto p = g.find(commands[2]);
					int score = (p != g.end()) ? p->second : -1;
                    if(score != 1) {
                        int inputFloor = atoi(commands[3].c_str());
                        int inputCeiling = atoi(commands[4].c_str());
                        if(score >= inputFloor && score <= inputCeiling){
                            print(showId, x);
                        }
                    }
				}
			}
		}
		cout << endl;
	}while(1);
}

