#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
void writeNumbers(const int &num);
vector<int> readNumbers();
float getAverage();
void print(const vector<int> &ref);

struct Student
{
    string name;
    int finalExam;
    int CAGrade;

    float getFinalGrade()
    {
        return finalExam*.6 + CAGrade *.4;
    }
};

vector<Student> getStudents();
void print(const vector<Student> &studs);
int main()
{
    //writeNumbers(100);
  //  vector<int> numbers = readNumbers();
   // print(numbers);
    vector<Student> studs = getStudents();
    print(studs);

    //getAverage();
    return 0;
}
void print(const vector<Student> &studs)
{
  cout << left << setw(20)<<"Name" << setw(5) << "FA"<<setw(5)<<"CA"<<setw(5)
    <<"Overall"<<endl;
  for (Student s: studs)
  {
      cout << setw(20)<<s.name << setw(5) << s.finalExam
      <<setw(5)<<s.CAGrade<<setw(5)<<s.getFinalGrade()<<endl;
  }
}
vector<Student> getStudents()
{
    string dummy;
    vector<Student> studs;
    ifstream in("students.txt");
    if (in)
    {
        while (!in.eof())
        {

            string name;
            int ca, fe;
            getline(in, name);
            in >> fe >> ca;
            getline(in, dummy);
            Student s ;
            s.name = name;
            s.finalExam = fe;
            s.CAGrade = ca;
            studs.push_back(s);

        }
    }
    else
    {
        cout << "error opening file"<<endl;
    }
    return studs;
}
void print(const vector<int> &ref)
{
    cout << "[";
    for (int i = 0; i < ref.size();i++)
    {
        if (i!=0)
        {
            cout <<", ";
        }
        cout << ref[i];
    }
    cout << "]"<<endl;
}
vector<int> readNumbers()
{
    vector<int> numbers;
    ifstream in("nums.txt");
    if (in)
    {
        int num;
        while (!in.eof())
        {
            in >>num;
            numbers.push_back(num);
        }
        in.close();
    }
    return numbers;
}
float getAverage()
{
    float total = 0;
    int count = 0;
    vector<int> numbers;
    ifstream in("nums.txt");
    if (in)
    {
        string val;
        int num;

        while (!in.eof())
        {
            getline(in, val);
            if (val!="\n" && val!="")
            {
                num = stoi(val);
                total+=num;
                count++;

            }
        }
        cout << "Count: " << count << "; Average: " << (total/count)
        <<"Total:"<<total<< endl;
        in.close();
    }
    return (total/count) ;
}
void writeNumbers(const int &num)
{
    ofstream out("nums.txt");
    if (out)
    {
        for (int i = 0; i < num; i++)
        {
            out << (rand()%101)<<endl;
        }
        out.close();
    }
    else
    {
        cout << "Error opening file"<<endl;
    }
}