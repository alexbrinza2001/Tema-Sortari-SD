#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
using namespace std;

int max_value, vector_size, over;
vector <int> v, v2;
time_t timer1;

int pivot(vector <int> &V, int st, int dr, int tip)
{
    int p;

    if(tip == 1) //tipul 1 reprezinta alegerea ultimului element ca pivot
    {
        p = dr;
    }

    if(tip == 2) //tipul 2 reprezinta alegerea unui element random ca pivot
    {
        srand(time(0));

        p = st + rand() % (dr - st + 1);
        swap(V[p], V[dr]);
        p = dr;
    }

    if(tip == 3) //tipul 3 reprezinta alegerea medianei din 3 ca pivot
    {
        srand(time(0));

        int v1 = st + rand() % (dr - st + 1);
        int v2 = st + rand() % (dr - st + 1);
        int v3 = st + rand() % (dr - st + 1);

        if(V[v1] <= V[v2])
            if(V[v3] <= V[v1]) p = v1;
            else if(V[v3] >= V[v2]) p = v2;
                 else p = v3;
        else
            if(V[v3] <= V[v2]) p = v2;
            else if(V[v3] >= V[v1]) p = v1;
                 else p = v3;
        
        swap(V[p], V[dr]);
        p = dr;
    }

    int i = st - 1;
    p = V[p];
        
    for(int j = st; j < dr; ++j)
        if(V[j] < p)
        {
            ++i;
            swap(V[i], V[j]);
        }

    swap(V[i + 1], V[dr]);

    return i + 1;
}

void qs(vector <int> &V, int st, int dr)
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

    int p = pivot(V, st, dr, 1);
    qs(V, st, p - 1);
    qs(V, p + 1, dr);
}

void quicksort(vector <int> &V)
{
    qs(V, 0, V.size() - 1);
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

    return  V;
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

    cout << "Scrieti valoarea maxima a numerelor din vector:";
    cin >> max_value;

    v = generator(vector_size, max_value);
    v2 = correct_sort(v);

    time(&timer1);
    auto start = chrono::high_resolution_clock::now();

    quicksort(v);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(ok(v, v2) == 1) cout << "Sortare corecta" << "\n" << duration.count() / 1000 << " miliseconds";
    else cout << "Sortare incorecta";
    return 0;
}