#include <iostream>            // obs�uga wej�cia i wyj�cia
#include <vector>              // obs�uga struktur danych biblioteki stl
using namespace std;           // zapis dzi�ki kt�remu kompilator nie wymaga przedrostka std

int main() {
    vector <string> wektor;    // zainicjalizowanie wektora

    // inicjalizacja zmiennych
    char instrukcja;           // przechowuje instrukcje
    char instrukcjaM;          // przechowuje podinstrukcje dodawania i ususwania
    string tekst;              // przechowuje tekst, kt�ry ma by� dodany
    string check;              // przechowuje tekst, kt�ry ma by� sprawdzony
    bool checkSet = false;     // zmienna pomocnicza
    int n;                     // przechowuje indeks elementu wektora

    // menu
    cout << "Wybierz instrukcje\n";
    cout << "m - dodawanie i usuwanie elementow,\n";
    cout << "d - pobranie wartosci skrajnych elementow,\n";
    cout << "n - pobieranie n-tego elementu struktury,\n";
    cout << "c - sprawdzenie czy element nalezy do struktury,\n";
    cout << "s - pobranie wielkosci struktury,\n";
    cout << "e - sprawdzenie, czy wektor jest niepusty\n";

    // operacje
    while (true) {                                                                           // program dzia�a w niesko�czono��
        cout << "\npodaj operacje: ";
        cin >> instrukcja;

        // instrukcje dla konkretnego wyboru
        switch (instrukcja) {

            // dodawanie lub usuwanie
        case 'm':
            cout << "\nwybierz operacje:\n";
            cout << "d - dodawanie\n";
            cout << "u - usuwanie\n";
            cout << "\npodaj instrukcje: ";
                cin >> instrukcjaM;                                                          // pobranie podinstrukcji
                cout << "\n";
                switch (instrukcjaM) {
                case 'd':
                    cout << "podaj tekst, ktory ma zostac dodany do struktury: ";
                    cin >> tekst;
                    wektor.push_back(tekst);                                                 // dodanie elementu na sam koniec struktury
                    cout << "\ndodano!\n";
                    break;
                case 'u':
                    if (!wektor.empty()) {                                                   // obs�uga b��du, je�li wektor jest pusty, wy�wietlony zostanie komunikat
                        wektor.pop_back();                                                   // usu� ostatni element struktury
                        cout << "\nusunieto!\n";
                    }
                    else cout << "\nstruktura jest pusta\n";
                default:
                    cout << "\nnieznana operacja\n";
                    break;
            }
            break;

            // pobranie skrajnej warto�ci
        case 'd':
            if (!wektor.empty()) {                                                            // obs�uga b��du
                cout << "\nwartosci skrajne struktury: " << wektor.front() << ", " << wektor.back() << "\n";
            }
            else cout << "\nstruktura jest pusta\n";
            break;

            // pobranie n-tej warto�ci
        case 'n':
            cout << "Podaj n: ";
            cin >> n;
            if (n <= wektor.size()) cout << n << " element struktury jest rowny: " << wektor[n-1];    // obs�uga b��du, je�li podany indeks jest poza rozmiarem struktury to wy�wietlony zostanie komunikat
            else cout << "struktura nie zawiera tylu elementow";
            break;

            // sprawdzenie, czy element nale�y do struktury
        case 'c':
            cout << "\npodaj ciag do sprawdzenia\n";
            cin >> check;
            for (int i = 0; i < wektor.size(); i++) {                                         // p�tla wykonuje si� o rozmiar wektora
                if (check == wektor[i]) {                                                     // je�li tekst zostanie odnaleziony, to zmienna pomocnicza zostanie ustawiona na true
                    checkSet = true;                                                          // warto�� true deklaruje, �e w wektorze jest przynajmniej jeden element pasuj�cy do szukanego ci�gu
                    break;                                                                    // funkcja, przerywa p�tle
                }
            }
            if (checkSet == true) cout << "\nelement" << check << "nalezy do struktury\n";    // je�li w wektorze znajduje si� szukany ci�g znak�w wy�wietlony zostanie ten komunikat
            else cout << "\nelement" << check << "nie zostal znaleziony w strukturze\n";      // je�li szukany ci�g nie zostanie znaleziony wy�wietlony zostanie ten komunikat
            break;

            // pobranie rozmiaru struktury
        case 's':
            cout << "\nstruktura ma rozmiar: " << wektor.size() << "\n";
            break;

            // sprawdzenie, czy struktura jest pusta
        case 'e':
            if (wektor.empty()) cout << "\nstruktura jest pusta\n";
            else cout << "\nstruktura jest niepusta\n";
            break;

            // obs�uga b��du
        default:
            cout << "\nnieznana operacja\n";
            break;
        }
    }
    return 0;
}