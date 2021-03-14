#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;

vector < int > v, v2;
int vector_size, base, over, max_value;
time_t timer1;

void countsort(vector < int > &V, int b, int exponent)
{
    int size = V.size();
    vector < int > count(b, 0), new_sort(size, 0);

    for(int i = 0; i < size; ++i)
        ++count[(V[i] / exponent) % b];

    for(int i = 1; i < b; ++i)
        count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; --i)
    {
        new_sort[count[(V[i] / exponent) % b] - 1] = V[i];
        --count[(V[i] / exponent) % b];
    }

    for(int i = 0; i < size; ++i)
        v[i] = new_sort[i];
    new_sort.clear();
}

void radixsort(vector < int > &V, int size, int b)
{
    int maxim = -1;

    for(int i = 0; i < size; ++i)
        maxim = max(V[i], maxim);
    
    int max_digits = int(log(maxim) / log(base)) + 1;
    int pow = 1;

    for(int i = 1; i <= max_digits; ++i)
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

        countsort(V, b, pow);
        pow *= b;
    }
}

vector <int> generator(int size, int max)
{
    srand(time(0));

    vector <int> V;

    for(int i = 1; i <= size; ++i)
    {
        int x = int( (double)rand() / ((double)RAND_MAX + 1.0) * max);
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

    cout << "Scrieti valoarea maxima a elementelor din vector:";
    cin >> max_value;

    cout << "Scrieti baza in care se va face sortarea:";
    cin >> base;

    v = generator(vector_size, max_value);
    v2 = correct_sort(v);

    time(&timer1);
    auto start = chrono::high_resolution_clock::now();

    radixsort(v, vector_size, base);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    if(ok(v, v2) == 1) cout << "Sortare corecta" << "\n" << duration.count() / 1000 << " miliseconds";
    else cout << "Sortare incorecta";

    return 0;
}