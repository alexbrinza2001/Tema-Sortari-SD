#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;

vector < int > v, v2;
int vector_size, max_value, over;
time_t timer1;

void Interclasare(vector < int > &V, int st, int mij, int dr)
{
    vector <int> A;
    int i = st, j = mij + 1;

    while(i <= mij && j <= dr)
        if(V[i] < V[j])
        {
            A.push_back(V[i]);
            i++;
        }
        else
        {
            A.push_back(V[j]);
            j++;
        }

    while(i <= mij)
    {
        A.push_back(V[i]);
        i++;
    }

    while(j <= dr)
    {
        A.push_back(V[j]);
        j++;
    }

    for(int index = st; index <= dr; ++index)
        V[index] = A[index - st];

    A.clear();
}

void insertion(vector < int > &V, int st, int dr)
{
    int index1, index2;
    
    for(index1 = st; index1 <= dr; ++index1)
    {
        index2 = index1;
        
        while(index2 > st && V[index2] < V[index2 - 1])
        {
            swap(V[index2], V[index2 - 1]);
            --index2;
        }
    }
}


void timsort(vector < int > &V, int st, int dr)
{
    if(st >= dr) return;
    if(over == 1) return;

    time_t timer2;
    double second;
    time(&timer2);
    second = difftime(timer2, timer1);

    if(second > 20)
    {
        cout << "Rularea programului dureaza prea mult\n";
        over = 1;
        return;
    }
    
    int mij = (st + dr) / 2;
    
    if( (mij - st + 1) <= 64) insertion(V, st, mij);
    else timsort(V, st, mij);
    
    if( (dr - mij) <= 64) insertion(V, mij + 1, dr);
    else timsort(V, mij + 1, dr);
    
    Interclasare(V, st, mij, dr);
}

vector <int> generator(int size, int max)
{
    srand(time(0));

    vector <int> V;

    for(int i = 1; i <= size; ++i)
    {
        int x = int( (double)rand() / ((double)RAND_MAX + 1.0) * max );
        V.push_back(x);
    }

    return V;
}

vector <int> correct_sort(vector <int> V)
{
    sort(V.begin(), V.end());

    return V;
}

bool ok(vector <int> V1, vector <int> V2)
{
    if(V1.size() != V2.size()) return 0;

    for(int i = 0; i < V1.size(); ++i)
        if(V1[i] != V2[i])
            return 0;

    return 1;
}

int main() 
{
	cout << "Scrieti marimea vectorului:";
    cin >> vector_size;

    if(vector_size >= 536870911) 
    {
        cout << "Prea multe valori";
        return 0;
    }

    cout << "Scrieti valoarea maxima a elementelor din vector:";
    cin >> max_value;

    v = generator(vector_size, max_value);
    v2 = correct_sort(v);

    time(&timer1);
    auto start = chrono::high_resolution_clock::now();

    timsort(v, 0, vector_size - 1);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(ok(v, v2) == 1) cout << "Sortare corecta" << "\n" << duration.count() / 1000 << " miliseconds";
    else cout << "Sortare incorecta";
    return 0;
}