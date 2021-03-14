#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;

vector < int > v, v2;
int vector_size, number_max, Min, Max;
time_t timer1;

void countsort(vector <int> &V, int min, int max)
{
    vector <int> count(max - min + 1);

    int size = V.size();

    for(int i = 0; i < size; ++i)
    {
        ++count[V[i] - min];

        time_t timer2;
        double second;
        time(&timer2);
        second = difftime(timer2, timer1);

        if(second > 20)
        {
          cout << "Rularea programului dureaza prea mult\n";
          return;
        }
    }

    V.clear();

    for(int i = 0; i <= max - min; ++i)
        for(int j = 1; j <= count[i]; ++j)
           {
            time_t timer2;
            double second;
            time(&timer2);
            second = difftime(timer2, timer1);

            if(second > 20)
            {
             cout << "Rularea programului dureaza prea mult\n";
             return;
            }

            V.push_back(i + min);
           }
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

vector <int> generator(int size, int maxx)
{
    srand(time(0));

    vector <int> V;
    Min = maxx + 1;
    Max = -1;

    for(int i = 1; i <= size; ++i)
    {
        int x = int( (double)rand() / ((double)RAND_MAX + 1.0) * maxx );
        Min = min(Min, x);
        Max = max(Max, x);
        V.push_back(x);
    }

    return V;
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
    cin >> number_max;

    if(number_max >= 536870911) 
    {
        cout << "Valorile sunt prea mari";
        return 0;
    }

    v = generator(vector_size, number_max);
    v2 = correct_sort(v);

    time(&timer1);
    auto start = chrono::high_resolution_clock::now();

    countsort(v, Min, Max);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(ok(v, v2) == 1) cout << "Sortare corecta" << "\n" << duration.count() / 1000 << " miliseconds";
    else cout << "Sortare incorecta";

    return 0;
}