#include
using namespace std;

struct drzewo { // Definicja struktury pojedynczego wÍz≥a drzewa
    int liczba;
    drzewo* lewy;
    drzewo* prawy;
};

drzewo* dodaj(drzewo* d, int w) { // funkcja globalna dodawania do drzewa
    if(d == nullptr)
    {
        drzewo* nowy = new drzewo;
        nowy->liczba = w;
        nowy->lewy = nullptr;
        nowy->prawy = nullptr;
        return nowy;
    }

    if(w < d->liczba){ // jesli dodawana wartosc jest mniejsza to w lewo
        d->lewy = dodaj(d->lewy, w);
    } else if (w >= d->liczba) { // jesli wieksza lub rowna to w prawo
        d->prawy = dodaj(d->prawy, w);
    }

    return d; // ZwrÛÊ zaktualizowany wskaünik na wÍze≥
}

void wyswietl(drzewo* d)
{
    if(d == nullptr) return; // Warunek stopu ñ jeúli wÍze≥ nie istnieje, zakoÒcz funkcjÍ

    wyswietl(d->prawy);       // Najpierw odwiedü prawy poddrzewo (kolejnoúÊ malejπca)
    cout << d->liczba << " "; // Wypisz wartoúÊ bieøπcego wÍz≥a
    wyswietl(d->lewy);        // Na koniec odwiedü lewe poddrzewo
}

int main() {
    cout << "Elementy drzewa: ";
    drzewo* d = nullptr; // Inicjalizacja pustego wskaünika na korzeÒ drzewa

    // Dodawanie kolejnych liczb do drzewa binarnego
    d = dodaj(d, 10);
    d = dodaj(d, 5);
    d = dodaj(d, 15);
    d = dodaj(d, 3);
    d = dodaj(d, 7);
    d = dodaj(d, 9);
    d = dodaj(d, 2);
    d = dodaj(d, 2);
    d = dodaj(d, 4);

    wyswietl(d); // Wywo≥anie funkcji wypisujπcej elementy

    cout << endl;

    return 0;
}
