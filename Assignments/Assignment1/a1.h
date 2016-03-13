#ifndef A1_H

#define A1_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

typedef pair<string, string> Name;
typedef map<string, int>     Grades;

/*Student class that has holds information like what's the id #, name, courses, and grades as its privates; 
Has additional functions to display the student to public without allowing access to the privates*/
class Student {
public:
    void display(ostream& os) const {
        os << id_ << endl;
        os << name_.first << ' ' << name_.second << endl;
        for(auto& x: grades_)
            os << x.first << ' ' << x.second << endl;
    }
    
    friend istream& operator>>(istream& is, Student& student);
    
    inline string getId() const {
        return id_;
    }
    inline Name getName() const {
        return name_;
    }
    inline Grades getGrades() const {
        return grades_;
    }
private:
    string  id_;
    Name    name_;
    Grades  grades_;
};
/*Overloading the istream operator so we can read in students from a file easily; 
This function is also a friend so we can access the privates of the Student easily*/
istream& operator>>(istream& is, Student& student) {
    student.grades_.clear();
    if(is >> student.id_) {
        string  courseID;
        size_t  totalCourses, score; 
        is >> student.name_.first >> student.name_.second >> totalCourses;
        for(size_t i = 0; i < totalCourses; i++) {
            is >> courseID >> score;
            student.grades_.insert(make_pair(courseID, score));
        }
    }
    return is;
}
#endif