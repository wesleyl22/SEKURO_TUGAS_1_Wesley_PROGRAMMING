#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int x[n];
    for(int i=0;i<n; i++) {
        cin >> x[i];
    }

    int id[n];
    for(int i=0;i<n; i++) {
    cin >> id[i];
    }

    vector<pair<int,int>> paket(n);

    for(int i=0;i<n; i++) {
        paket[i] = {x[i], id[i]};
    }

    sort(paket.begin(), paket.end());

    map<int, bool> kategori;
    int paketmaksimal = 0;

    for (int i = 0; i < n; i++) {
        int kateg = paket[i].second;

        if (!kategori[kateg]) {
            kategori[kateg] = true;
            paketmaksimal++;
        }
    }

    cout << paketmaksimal << endl;
}