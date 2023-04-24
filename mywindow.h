// Plik naglowkowy klasy MyWindow
// Obiekt tej klasy to glowne okno naszej aplikacji
// Szkielet tego pliku jest tworzony przez QtCreator
// Mozemy do niego dodac deklaracje wlasnych pol i metod

#ifndef MYWINDOW_H
#define MYWINDOW_H

// Dolaczamy plik naglowkowy klasy QMainWindow,
// Klasa QMainWindow posiada swoj wlasny layout.
// latwo mozna do niej dodac pasek menu, widzety dokujace,
// pasek narzedzi i pasek statusu. Na srodku okna
// wyswietlanego przez QMainWindow znajduje sie obszar,
// ktory mozna wypelnic roznymi widgetami.
#include <QMainWindow>
#include <stack>
// QPainter to klasa umozliwiajaca niskopoziomowe rysowanie
// na elementach GUI
#include <QPainter>

// QImage to klasa pozwalajaca na niezalezna od sprzetu reprezentacje obrazu.
// Pozwala na bezposredni dostep do poszczegolnych pikseli,
// Bedziemy jej uzywali do tworzenia i przechowywania
// naszych rysunkow
#include <QImage>

// QMouseEvent to klasa obslugujaca zdarzenia zwiazane z myszka
// klikniecia, ruch myszka itp.
#include <QMouseEvent>
#include <algorithm>
#include <vector>
typedef struct point{
    int x;
    int y;
} point;
namespace Ui {
    class MyWindow;
}

// MyWindow jest podklasa klasy QMainWindow.
class MyWindow : public QMainWindow
{
    // Q_OBJECT jest to makro, ktore musi sie znajdowac
    // we wszystkich klasach definiujacych wlasne sygnaly i sloty
    // W naszej klasie nie jest ono potrzebne,
    // ale QtCreator dodaje je automatycznie do kazdej klasy.
    Q_OBJECT

public:
    // Typowa deklaracja konstruktora w Qt.
    // Parametr "parent" okresla rodzica komponenetu.
    // W przypadku naszej klasy parametr ten wskazuje na null
    // co oznacza, ze komponenet nie ma rodzica, jest to
    // komponenet najwyzszego poziomu
    explicit MyWindow(QWidget *parent = 0);

    // Deklaracja destruktora
    ~MyWindow();

private:
    // QtCreator pozwala na tworzenie GUI za pomoca graficznego kreatora.
    // Skladniki interfejsu i ich wlasciwosci zapisane sa wowczas
    // w pliku XML "nazwa_klasy.ui"
    // Do poszczegolnych elementow GUI odwolujemy sie za pomoca zmiennej "ui"
    Ui::MyWindow *ui;

    // Pole przechowujace obrazek
    QImage *img;
    QImage *img2;

    // Pola przechowujace szerokosc i wysokosc rysunku
    // oraz wspolrzedne jego lewego gornego naroznika
    int szer;
    int wys;
    int poczX;
    int poczY;
    int startX,startY;
    int start2X,start2Y;
    int ileKrzyw=0;
    int figura=0; //0-olowek 1-kreska 2-kolo 3-elpisa 4-krzywa 5-dodaj punkt 6-usun punkt 7-modyfikuj punkt
    //8-krzywa2 9-dodaj 10-usun 11-modyfikuj
    bool isPressed=false;
    bool isPressed2=false;
    float gestosc=1; //do gestosci kropek w elipsie
    bool czyPierwszy=1; //do okreslenia czy jest to pierwszy x i y zeby okreslic finX i finY w krzywej
    std::vector <point> Krzywe;
    std::vector <point> Krzywe2;
    int ileP=0;
    // Deklaracje funkcji
    void schowek();
    void z_powrotem();
    void czysc();
    void czysc2();
    void kreska(int finX,int finY);
    void kreska2(int finX,int finY,int startX, int startY);
    void kolo(int finX,int finY);
    void elipsa(int finX,int finY, float step);
    void krzywa(int a);
    void K();
    void K2();
    void modyfikuj2(point p);
    void usunPunkt2(point p);
    int szukaj2(point p);
    point najblizszy2(point p);
    void kubelek(int x, int y);
    void wstawPiksel(int x,int y);
    void wstaw8(int x,int y);
    bool czyTlo(int x,int y);
    bool czyNalezy(point p);
    void usunPunkt(point p);
    point najblizszy(point p);
    int szukaj(point p);
    void modyfikuj(point p);
    // Deklaracje slotow, czyli funkcji wywolywanych
    // po wystapieniu zdarzen zwiazanych z GUI
    // np. klikniecie na przycisk, ruch myszka
private slots:
    void on_cleanButton_clicked();
    void on_exitButton_clicked();
    void on_kreskaButton_clicked();
    void on_elipsaButton_clicked();
    void on_olowekButton_clicked();
    void on_koloButton_clicked();
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void on_suwak_valueChanged(int value);
    void on_cleanButton_2_clicked();
    void on_krzywa_clicked();
    void on_kubelek_clicked();
    void on_dodaj_clicked();
    void on_usun_clicked();
    void on_modyfikuj_clicked();
    void on_krzywa_2_clicked();
    void on_dodaj_2_clicked();
    void on_usun_2_clicked();
    void on_modyfikuj_2_clicked();
};

#endif // MYWINDOW_H
