
#include<fstream>
#include<iostream>
using namespace std;
int V[100];
int n;
int value;
ifstream in("date.in");
ofstream out("date.out");


int read_data()
{
in >> value;
in >> n;
for(int i = 1; i<=n;i++)
{
    in >> V[i];
}
}
int pre_sort()
{
    for(int i = 1; i<=n;i++)
    {
        for(int j = i+1; j<=n;j++)
        {
            if(V[i] < V[j]) {
                swap(V[i], V[j]);
            }
        }
    }

}
int greedy()
{
    int i = 1;
    while(value > 0)
    {
        if(value / V[i] >= 1)
        {
            float cat;
            cat = value/V[i];
            cat = (int)cat;
            value = value - (cat * V[i]);
            out << "S-au folosit: " << cat << " de " << V[i] << endl;
        }
        else
        {
            i++;
            if(i>n)
            {
                break;
            }
        }


    }


}




int main()
{
read_data();
pre_sort();
greedy();
}

