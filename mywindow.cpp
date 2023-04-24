// Dolaczamy plik naglowkowy naszej klasy MyWindow
#include "mywindow.h"

// Dolaczamy plik naglowkowy zawierajacy definicje GUI
// Plik ten jest generowany automatycznie
// z pliku XML "mywindow.ui"
#include "ui_mywindow.h"

// Definicja konstruktora, wywolujemy najpierw
// konstruktor klasy nadrzednej, nastepnie tworzymy
// obiekt klasy Ui_MyWindow reprezentujacy GUI
MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    // Wywolujemy funkcje tworzaca elementy GUI
    // Jej definicja znajduje sie w pliku "ui_mywindow.h"
    ui->setupUi(this);

    // Pobieramy wymiary i wspolrzedne lewego gornego naroznika ramki
    // i ustawiamy wartosci odpowiednich pol
    // Uwaga: ramke "rysujFrame" wykorzystujemy tylko do
    // wygodnego ustaiwenia tych wymiarow. Rysunek bedziemy wyswietlac
    // bezposrednio w glownym oknie aplikacji.
    szer = ui->rysujFrame->width();
    wys = ui->rysujFrame->height();
    poczX = ui->rysujFrame->x();
    poczY = ui->rysujFrame->y();

    // Tworzymy obiekt klasy QImage, o odpowiedniej szerokosci
    // i wysokosci. Ustawiamy format bitmapy na 32 bitowe RGB
    // (0xffRRGGBB).
    img = new QImage(szer,wys,QImage::Format_RGB32);
    img2 = new QImage(szer,wys,QImage::Format_RGB32);

}

// Definicja destruktora
MyWindow::~MyWindow()
{
    delete ui;
}

// Funkcja (slot) wywolywana po nacisnieciu przycisku "Wyjscie" (exitButton)
// Uwaga: polaczenie tej funkcji z sygnalem "clicked"
// emitowanym przez przycisk jest realizowane
// za pomoca funkcji QMetaObject::connectSlotsByName(MyWindow)
// znajdujacej sie w automatycznie generowanym pliku "ui_mywindow.h"
// Nie musimy wiec sami wywolywac funkcji "connect"
void MyWindow::on_exitButton_clicked()
{
    // qApp to globalny wskaznik do obiektu reprezentujacego aplikacje
    // quit() to funkcja (slot) powodujaca zakonczenie aplikacji z kodem 0 (brak bledu)
    qApp->quit();
}


// Funkcja "odmalowujaca" komponent
void MyWindow::paintEvent(QPaintEvent*)
{
    // Obiekt klasy QPainter pozwala nam rysowac na komponentach
    QPainter p(this);

    // Rysuje obrazek "img" w punkcie (poczX,poczY)
    // (tu bedzie lewy gorny naroznik)
    p.drawImage(0,0,*img);
}


// Funkcja (slot) wywolywana po nacisnieciu przycisku "Czysc" (cleanButton)
void MyWindow::on_cleanButton_clicked()
{
    czysc();
    update();
}
void MyWindow::on_olowekButton_clicked()
{
    figura=0;
}
void MyWindow::on_kreskaButton_clicked()
{
    figura=1;
}
void MyWindow::on_koloButton_clicked()
{
    figura=2;
}
void MyWindow::on_elipsaButton_clicked()
{
    figura=3;
}

void MyWindow::on_suwak_valueChanged(int value)
{
    gestosc=value;
}
void MyWindow::on_krzywa_clicked()
{
    figura=4;
}
void MyWindow::on_dodaj_clicked()
{
    figura=5;
}
void MyWindow::on_usun_clicked()
{
    figura=6;
}
void MyWindow::on_modyfikuj_clicked()
{
    figura=7;
}

void MyWindow::on_krzywa_2_clicked()
{
    figura=8;
}

void MyWindow::on_dodaj_2_clicked()
{
    figura=9;
}


void MyWindow::on_usun_2_clicked()
{
    figura=10;
}


void MyWindow::on_modyfikuj_2_clicked()
{
    figura=11;
}


void MyWindow::czysc()
{
    // Wskaznik za pomoca, ktorego bedziemy modyfikowac obraz
    unsigned char *ptr;
    unsigned char *ptr2;

    // Funkcja "bits()" zwraca wskaznik do pierwszego piksela danych
    ptr2 = img2->bits();
    ptr = img->bits();
    int i,j;

    // Przechodzimy po wszystkich wierszach obrazu
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr2[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr2[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr2[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    ileP=0;
    Krzywe.clear();
    Krzywe2.clear();
}
void MyWindow::czysc2() //czysci bez usuniecia wektora Krzywe
{
    // Wskaznik za pomoca, ktorego bedziemy modyfikowac obraz
    unsigned char *ptr;
    unsigned char *ptr2;

    // Funkcja "bits()" zwraca wskaznik do pierwszego piksela danych
    ptr2 = img2->bits();
    ptr = img->bits();
    int i,j;

    // Przechodzimy po wszystkich wierszach obrazu
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    for(i=0; i<wys; i++)
    {
        // Przechodzimy po pikselach danego wiersza
        // W kazdym wierszu jest "szer" pikseli (tzn. 4 * "szer" bajtow)
        for(j=0; j<szer; j++)
        {
            ptr2[szer*4*i + 4*j]=0; // Skladowa BLUE
            ptr2[szer*4*i + 4*j + 1] = 0; // Skladowa GREEN
            ptr2[szer*4*i + 4*j + 2] = 0; // Skladowa RED
        }
    }
    ileP=0;
}
void MyWindow::wstawPiksel(int x,int y)
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((x>=0)&&(y>=0)&&(x<szer)&&(y<wys))
    {
        ptr[szer*4*y + 4*x] = 255; // Składowa BLUE
        ptr[szer*4*y + 4*x + 1] = 255; // Składowa GREEN
        ptr[szer*4*y + 4*x + 2] = 255; // Składowa RED
    }

}
void MyWindow::schowek()
{
    unsigned char *ptr2 = img2->bits();
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();

    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr2[szer*4*y + 4*x] = ptr[szer*4*y + 4*x]; // Składowa BLUE
            ptr2[szer*4*y + 4*x + 1] = ptr[szer*4*y + 4*x + 1]; // Składowa GREEN
            ptr2[szer*4*y + 4*x + 2] = ptr[szer*4*y + 4*x + 2]; // Składowa RED
        }
    }

}
void MyWindow::z_powrotem()
{
    unsigned char *ptr2 = img2->bits();
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    for(int y=0;y<wys;++y)
    {
        for(int x=0;x<szer;++x)
        {
            ptr[szer*4*y + 4*x] = ptr2[szer*4*y + 4*x]; // Składowa BLUE
            ptr[szer*4*y + 4*x + 1] = ptr2[szer*4*y + 4*x + 1]; // Składowa GREEN
            ptr[szer*4*y + 4*x + 2] = ptr2[szer*4*y + 4*x + 2]; // Składowa RED
        }
    }
}
void MyWindow::kreska(int finX,int finY)
{
    float a=1,b=0;
    int x,y;
    if(startX==finX)//pionowa
    {
        x=startX;
        if(startY<=finY)
        {
            for(int y=startY;y<=finY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
        else
        {
            for(int y=finY;y<=startY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
    }
    else
    {
        a=float(finY-startY)/float(finX-startX);
        b=startY-a*startX;
        if(abs(a)<=1)
        {
            y=startY;
            if(startX>finX)
            {
                for(int x=finX;x<=startX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }
            else
            {
                for(int x=startX;x<=finX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }

        }
        else
        {
            if(startY<=finY)
            {
                for(int y=startY;y<=finY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
            else
            {
                for(int y=finY;y<=startY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
        }
    }
    update();
}
void MyWindow::kreska2(int finX,int finY,int sX, int sY)
{
    float a=1,b=0;
    int x,y;
    if(sX==finX)//pionowa
    {
        x=sX;
        if(sY<=finY)
        {
            for(int y=sY;y<=finY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
        else
        {
            for(int y=finY;y<=sY;++y)
            {
                wstawPiksel((int)floor(x+0.5),y);
            }
        }
    }
    else
    {
        a=float(finY-sY)/float(finX-sX);
        b=sY-a*sX;
        if(abs(a)<=1)
        {
            y=sY;
            if(sX>finX)
            {
                for(int x=finX;x<=sX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }
            else
            {
                for(int x=sX;x<=finX;++x)
                {
                    y=a*x+b;
                    wstawPiksel(x,(int)floor(y+0.5));
                }
            }

        }
        else
        {
            if(sY<=finY)
            {
                for(int y=sY;y<=finY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
            else
            {
                for(int y=finY;y<=sY;++y)
                {
                    x=(y-b)/a;
                    wstawPiksel((int)floor(x+0.5),y);
                }
            }
        }
    }
    update();
}
void MyWindow::wstaw8(int x, int y)
{
    wstawPiksel(x + startX, (int)floor(y+0.5) +startY);
    wstawPiksel(x + startX, -(int)floor(y+0.5) +startY);
    wstawPiksel(-x + startX, (int)floor(y+0.5) +startY);
    wstawPiksel(-x + startX, -(int)floor(y+0.5) +startY);
    wstawPiksel((int)floor(y+0.5)+ startX, x +startY);
    wstawPiksel(-(int)floor(y+0.5)+ startX, x +startY);
    wstawPiksel((int)floor(y+0.5)+ startX, -x +startY);
    wstawPiksel(-(int)floor(y+0.5)+ startX, -x +startY);
}
void MyWindow::kolo(int finX,int finY)
{
    float R=std::sqrt(std::pow(finX-startX,2)+std::pow(finY-startY,2));
    float a=(R/std::sqrt(2));
    for(float x=0;x<=a;++x)
    {
        float y=std::sqrt(std::pow(R,2)-std::pow(x,2));
        wstaw8(x,y);
    }
}
void MyWindow::elipsa(int finX, int finY,float step)
{
    float a = std::abs(finX - startX) ;
    float b = std::abs(finY - startY) ;
    step*=(2*M_PI); //0.1-min 0.01-maxymalna liczba kropek -tak bedzie na suwaku
    float t=0;
    float pastX=a * cos(t)+startX;
    float pastY=b * sin(t)+startY;
    float pomX=pastX;
    float pomY=pastY;
    for (t = step; t<=2*M_PI; t+=step) {
        float y = b * sin(t);
        float x = a * cos(t);
        kreska2(startX + x,startY+y,pastX,pastY);
        pastX=x+startX;
        pastY=y+startY;
    }
    kreska2(pomX,pomY,pastX,pastY);
    update();
}
bool MyWindow::czyTlo(int x,int y)
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((x>=0)&&(y>=0)&&(x<szer)&&(y<wys))
    {
        if((ptr[szer*4*y + 4*x] == 0) && (ptr[szer*4*y + 4*x + 1] == 0) && (ptr[szer*4*y + 4*x + 2] == 0))
        {
            return true;
        }
        else return false;
    }
}
bool MyWindow::czyNalezy(point p)//czy nalezy do obrazka
{
    unsigned char *ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if ((p.x>=0)&&(p.y>=0)&&(p.x<szer)&&(p.y<wys))
    {
        return true;
    }
    else return false;
}
void MyWindow::kubelek(int x,int y)
{
    point p1,p2,p3;
    p1.x=x;
    p1.y=y;
    std::stack<point> S;
    S.push(p1);
    while(!S.empty())
    {
        p2=S.top();
        S.pop();
        if(czyTlo(p2.x,p2.y))
        {
            wstawPiksel(p2.x,p2.y);

            p3.x=p2.x+1;
            p3.y=p2.y;
            if(czyNalezy(p3))
            {
                S.push(p3);
            }

            p3.x=p2.x;
            p3.y=p2.y+1;
            if(czyNalezy(p3))
            {
                S.push(p3);
            }

            p3.x=p2.x-1;
            p3.y=p2.y;
            if(czyNalezy(p3))
            {
                S.push(p3);
            }

            p3.x=p2.x;
            p3.y=p2.y-1;
            if(czyNalezy(p3))
            {
                S.push(p3);
            }
        }
    }
    update();
}
void MyWindow::K() //rysuje wszystkie krzywe
{
    for(int j=0;j<Krzywe.size();++j)
    {
        wstawPiksel(Krzywe[j].x,Krzywe[j].y);
    }
    int num=2000;
    if(Krzywe.size()>=4)
    {
        for (int j = 0; j <= num; j++)
        {
            float t = (float)j / (float)num;
            float x = pow(1-t, 3) * Krzywe[0].x + 3 * t * pow(1-t, 2) * Krzywe[1].x
                      + 3 * pow(t, 2) * (1-t) * Krzywe[2].x + pow(t, 3) * Krzywe[3].x;
            float y = pow(1-t, 3) * Krzywe[0].y + 3 * t * pow(1-t, 2) * Krzywe[1].y
                      + 3 * pow(t, 2) * (1-t) * Krzywe[2].y + pow(t, 3) * Krzywe[3].y;
            wstawPiksel((int)x, (int)y);
        }
    }
    if(Krzywe.size()>=5)
    {
        for(int i=1;i<1+(Krzywe.size()-4)/3;++i)
        {
            for (int j = 0; j <= num; j++) {
                float t = (float)j / (float)num;
                float x = pow(1-t, 3) * Krzywe[i*3].x + 3 * t * pow(1-t, 2) * Krzywe[i*3+1].x
                          + 3 * pow(t, 2) * (1-t) * Krzywe[i*3+2].x + pow(t, 3) * Krzywe[i*3+3].x;
                float y = pow(1-t, 3) * Krzywe[i*3].y + 3 * t * pow(1-t, 2) * Krzywe[i*3+1].y
                          + 3 * pow(t, 2) * (1-t) * Krzywe[i*3+2].y + pow(t, 3) * Krzywe[i*3+3].y;
                wstawPiksel((int)x, (int)y);
            }
        }
    }
}
point MyWindow::najblizszy(point p)
{
    point pom;
    point para;
    pom.x=Krzywe[0].x;
    pom.y=Krzywe[0].y;
    float naj=sqrt(pow(pom.x-p.x,2)+pow(pom.y-p.y,2));
    for(int i=1;i<Krzywe.size();++i)
    {
        pom.x=Krzywe[i].x;
        pom.y=Krzywe[i].y;
        float odl=sqrt(pow(pom.x-p.x,2)+pow(pom.y-p.y,2));
        if(odl<naj)
        {
            para.x=pom.x;
            para.y=pom.y;
            naj=odl;
        }
    }
    return para;
}
int MyWindow::szukaj(point p)// zwraca idneks w vektorze Krzywe punktu
{
    for(int i=0;i<Krzywe.size();++i)
    {
        if(Krzywe[i].x==p.x && Krzywe[i].y==p.y)
        {
            return i;
        }
    }
}
void MyWindow::usunPunkt(point p)
{
    Krzywe.erase(Krzywe.begin()+szukaj(p));
    czysc2();
    K();
    K2();
    update();
}
void MyWindow::modyfikuj(point p)
{
    int indeks;
    point pom;
    pom.x=startX;
    pom.y=startY;
    pom=najblizszy(pom);
    indeks=szukaj(pom);//szukam indeksu punktu do zmodyfikowania (juz nalezionego najblizszego
    Krzywe[indeks].x=p.x;
    Krzywe[indeks].y=p.y; //zamieniam na ten punkt koncowy
    czysc2();
    K();
    K2();
    update();
}
void MyWindow::K2() //rysuje wszystkie krzywe2
{
    for(int j=0;j<Krzywe2.size();++j)
    {
        wstawPiksel(Krzywe2[j].x,Krzywe2[j].y);
    }
    int num=2000;
    if(Krzywe2.size()>=4)
    {
        for(int i=0;i<Krzywe2.size()-3;++i)
        {
            for (int j = 0; j <= num; j++) {
                float t = (float)j / (float)num;
                float x = (((-pow(t, 3))  + 3 * pow(t, 2) + (-3)*t +1 )* Krzywe2[i].x)/6
                          + ((3 * pow(t, 3) - 6*pow(t,2)+ 4 ) * Krzywe2[i+1].x)/6
                          + (((-3)*pow(t, 3) + 3*pow(t,2) + 3*t + 1)* Krzywe2[i+2].x)/6
                          + (pow(t,3)* Krzywe2[i+3].x)/6;
                float y = (((-pow(t, 3))  + 3 * pow(t, 2) + (-3)*t +1 )* Krzywe2[i].y)/6
                        + ((3 * pow(t, 3) - 6*pow(t,2)+ 4 ) * Krzywe2[i+1].y)/6
                        + (((-3)*pow(t, 3) + 3*pow(t,2) + 3*t + 1)* Krzywe2[i+2].y)/6
                        + pow(t,3)/6* Krzywe2[i+3].y;
                wstawPiksel((int)x, (int)y);
            }
        }
    }

}

point MyWindow::najblizszy2(point p)
{
    point pom;
    point para;
    pom.x=Krzywe2[0].x;
    pom.y=Krzywe2[0].y;
    float naj=sqrt(pow(pom.x-p.x,2)+pow(pom.y-p.y,2));
    for(int i=1;i<Krzywe2.size();++i)
    {
        pom.x=Krzywe2[i].x;
        pom.y=Krzywe2[i].y;
        float odl=sqrt(pow(pom.x-p.x,2)+pow(pom.y-p.y,2));
        if(odl<naj)
        {
            para.x=pom.x;
            para.y=pom.y;
            naj=odl;
        }
    }
    return para;
}
int MyWindow::szukaj2(point p)// zwraca idneks w vektorze Krzywe punktu
{
    for(int i=0;i<Krzywe2.size();++i)
    {
        if(Krzywe2[i].x==p.x && Krzywe2[i].y==p.y)
        {
            return i;
        }
    }
}
void MyWindow::usunPunkt2(point p)
{
    Krzywe2.erase(Krzywe2.begin()+szukaj2(p));
    czysc2();
    K2();
    K();
    update();
}
void MyWindow::modyfikuj2(point p)
{
    int indeks;
    point pom;
    pom.x=startX;
    pom.y=startY;
    pom=najblizszy2(pom);
    indeks=szukaj2(pom);//szukam indeksu punktu do zmodyfikowania (juz nalezionego najblizszego
    Krzywe2[indeks].x=p.x;
    Krzywe2[indeks].y=p.y; //zamieniam na ten punkt koncowy
    czysc2();
    K2();
    K();
    update();
}
void MyWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        startX=x;
        startY=y;
        isPressed=true;
        if(figura==4 || figura==5)
        {
            point A;
            A.x=x;
            A.y=y;
            Krzywe.push_back(A);
            K();
            K2();
        }
        else if(figura==6 && !Krzywe.empty()) //usuwanie
        {
            point p;
            p.x=x;
            p.y=y;
            p=najblizszy(p);
            usunPunkt(p);
        }
        else if(figura==7 && !Krzywe.empty() ) //modyfikacja
        {
            point start;
            start.x=x;
            start.y=y;
            point pom;
            pom = najblizszy(start);
            start2X=pom.x;
            start2Y=pom.y;
        }
        else if(figura==8 || figura==9)
        {
            point A;
            A.x=x;
            A.y=y;
            Krzywe2.push_back(A);
            K2();
            K();
        }
        else if(figura==10 && !Krzywe2.empty()) //usuwanie
        {
            point p;
            p.x=x;
            p.y=y;
            p=najblizszy2(p);
            usunPunkt2(p);
        }
        else if(figura==11 && !Krzywe2.empty() ) //modyfikacja
        {
            point start;
            start.x=x;
            start.y=y;
            point pom;
            pom = najblizszy2(start);
            start2X=pom.x;
            start2Y=pom.y;
        }
    }
    else if(event->button() == Qt::RightButton )
    {
        kubelek(x,y);
    }
    update();
}

void MyWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if((event->buttons() == Qt::LeftButton) && isPressed)
    {
        z_powrotem();
        if(figura==1)
        {
            kreska(x,y);
        }
        else if(figura==2)
        {
            kolo(x,y);
        }
        else if(figura==0)
        {
            wstawPiksel(x,y);
            schowek();
        }
        else if(figura==3)
        {
            elipsa(x,y,gestosc/1000);
        }
        else if(figura==7 && isPressed && !Krzywe.empty())
        {
            point p;
            p.x=x;
            p.y=y;
            modyfikuj(p);
        }
        else if(figura==11 && isPressed && !Krzywe2.empty())
        {
            point p;
            p.x=x;
            p.y=y;
            modyfikuj2(p);
        }
        update();
    }
}

void MyWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(event->button() == Qt::LeftButton)
    {
        isPressed=false;
    }
    schowek();
    update();
}






















