#include <iostream>
using namespace std;

struct drzewo {
    int liczba;
    drzewo* lewy;
    drzewo* prawy;
};

drzewo* dodaj(drzewo* d, int w) {
    if(d == nullptr)
    {
        drzewo* nowy = new drzewo;
        nowy->liczba = w;
        nowy->lewy = nullptr;
        nowy->prawy = nullptr;
        return nowy;
    }

    if(w < d->liczba){
        d->lewy = dodaj(d->lewy, w);
    } else if (w >= d->liczba) {
        d->prawy = dodaj(d->prawy, w);
    }

    return d;
}

void wyswietl(drzewo* d)
{
    if(d == nullptr) return;

    wyswietl(d->prawy);
    cout << d->liczba << " ";
    wyswietl(d->lewy);
}

int main() {
    cout << "Elementy drzewa: ";
    drzewo* d = nullptr;

    d = dodaj(d, 10);
    d = dodaj(d, 5);
    d = dodaj(d, 15);
    d = dodaj(d, 3);
    d = dodaj(d, 7);
    d = dodaj(d, 9);
    d = dodaj(d, 2);
    d = dodaj(d, 2);
    d = dodaj(d, 4);


    wyswietl(d);

    cout << endl;

    return 0;
}
