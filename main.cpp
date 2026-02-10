#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void writeNumbers(const int &num);
vector<int> readNumbers();
float getAverage();

void print(const vector<int> &ref);

int main()
{
    //writeNumbers(100);
    vector<int> numbers = readNumbers();
    print(numbers);
    getAverage();
    return 0;
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