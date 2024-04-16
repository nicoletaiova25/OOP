

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <math.h>
using std::runtime_error;
using namespace std;
class INTERFATA{
public:
    virtual istream& citire(istream& in)=0;
    virtual ostream& afisare(ostream& out) const=0;
};
class VitezaException:public exception{
    const char* what(){
        return "Viteza este prea mare !!!";
    }
};
class GreutateException:public exception{
    const char* what(){
        return "Greutate invalida!!";
    }
};
//exceptii
class Masina:public INTERFATA{
protected:
    string nume,model;
    int an_productie;
    int viteza_maxima;
    int greutate;
public:
    //constructori
    //constructor initializare
    Masina();
    //constructori parametrizati
    Masina(string nume,string model,int an_productie,int viteza_maxima,int greutate);
    //copy constructor
    Masina(const Masina &m);
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream &operator>>(istream& in,Masina& m);
    friend ostream &operator<<(ostream& out,Masina& m);
    virtual double autonomie();
    //suprascriere operatori
    Masina &operator=(const Masina& m);

    //setter
    void setNume(string nume);
    void setModel(string model);
    void setAn(int an_productie);
    void setVit(int viteza_maxima);
    void setGreutate(int greutate);
    //getter
    string getNume() const;
    string getModel() const;
    int getAn() const;
    int getVit() const;
    int getGreutate() const;
    //destructor
    ~Masina();

    ostream &afisare();

    istream &citire();
};
Masina& Masina::operator=(const Masina& m){
    this->nume=nume;
    this->model=model;
    this->an_productie=an_productie;
    this->greutate=greutate;
    this->viteza_maxima=viteza_maxima;
}
Masina::Masina(){
    this->nume="";
    this->model="";
    this->an_productie=0;
    this->viteza_maxima=0;
    this->greutate=0;
}
Masina::Masina(string nume ,string model,int an_productie,int viteza_maxima,int greutate){
    this->nume=nume;
    this->model=model;
    this->greutate=greutate;
    this->viteza_maxima=viteza_maxima;
    this->an_productie=an_productie;
}
Masina::Masina( const Masina& m){
    this->nume=m.nume;
    this->model=m.model;
    this->an_productie=m.an_productie;
    this->viteza_maxima=m.viteza_maxima;
    this->greutate=m.greutate;
}
istream& Masina::citire(istream& in){
    cout<<"\nIntroduceti numele masinii"<<endl;
    in>>this->nume;
    cout<<"\n Modelul masinii "<<endl;
    in>>this->model;
    cout<<"An productie este "<<endl;
    in>>this->an_productie;
    while(this->viteza_maxima=0){
         cout<<"Introduceti viteza maxima "<<endl;
         in>>this->viteza_maxima;
         try{
         if(this->viteza_maxima>300)
             throw VitezaException();
         }
         catch(exception& e){
             cout<<e.what()<<endl;
             cout<<"Introduceti o viteza valida!!!";
             this->viteza_maxima=0;
         }
    }
    in>>this->greutate;
    while(this->greutate=0){
        cout<<"Introduceti greutate maxima "<<endl;
        in>>this->greutate;
        try{
            if(this->greutate<0)
                throw GreutateException();
        }
        catch(exception& e){
            cout<<e.what()<<endl;
            cout<<"Introduceti o greutate valida!!!";
            this->greutate=0;
        }
    }
    return in;
}
ostream&  Masina::afisare(ostream& out)const{
    out<<"Numele este "<<this->nume;
    out<<"Modelul este"<<this->model;
    out<<"Viteza este "<<this->viteza_maxima;
    out<<"Greutatea este"<<this->greutate;
    out<<"Anul de prod este"<<this->an_productie;
    return out;
}
istream& operator>>(istream& in,Masina& m){
    return m.citire(in);
}
ostream& operator<<(ostream& out,const Masina& m){
    return m.afisare(out);
}
//seturi
void Masina::setNume(string nume) {
   this->nume=nume;
}
void Masina::setModel(string model) {
    this->model=model;
}
void Masina::setAn(int an_productie) {
    this->an_productie=an_productie;
}
void Masina::setGreutate(int greutate) {
    this->greutate=greutate;
}
void Masina::setVit(int viteza_maxima) {
    this->viteza_maxima=viteza_maxima;
}
string Masina::getNume() const {
    return nume;
}
string Masina::getModel() const {
    return model;
}
int Masina::getAn() const {
    return an_productie;
}
int Masina::getVit() const {
    return viteza_maxima;
}
int Masina::getGreutate() const {
    return greutate;
}
double Masina::autonomie() {
    return 1.0;
}


class Fosil : virtual public Masina{
protected:
    string tip_combustibil;
    int capacitate;
public:
    Fosil();
    Fosil(string nume, string model, int an_productie, int viteza_maxima, int greutate, string tip_combustibil, int capacitate);
    Fosil( const Fosil& f);
    Fosil& operator = (const Fosil& f);
    istream& citire (istream& in);
    ostream& afisare (ostream& out) const;

    //seter
    void setTip_combustibil(string tip_combustibil);
    void set_capacitate(int capacitate);

    //getter
    string getTip_combustibil() const;
    int get_capacitate()const;

    virtual double Autonomie();
};

Fosil& Fosil::operator=(const Fosil& f) {
    if (this != &f) {
        Masina::operator=(f);
        this->tip_combustibil = tip_combustibil;
        this->capacitate = capacitate;
    }
}


Fosil::Fosil():Masina(){
    this->tip_combustibil="";
    this->capacitate=0;
}

Fosil::Fosil(string nume, string model, int an_productie, int viteza_maxima, int greutate, string tip_combustibil, int capacitate) :Masina( nume,  model,  an_productie, viteza_maxima, greutate){
    this->tip_combustibil=tip_combustibil;
    this->capacitate=capacitate;
}

Fosil::Fosil(const Fosil& f):Masina(f){
    this->tip_combustibil=f.tip_combustibil;
    this->capacitate=f.capacitate;
}

istream& Fosil::citire (istream& in){
    Masina::citire(in);
    cout<<"Introduceti tipul de combustibil ";
    in>>this->tip_combustibil;
    cout<<"Introduceti capacitatea ";
    in>>this->capacitate;
    return in;
}

ostream& Fosil::afisare(ostream& out) const{
    Masina::afisare(out);
    out<<"Tipul de combustibil "<< this->tip_combustibil<<endl;
    out<<"Capacitatea rezervorului "<< this->capacitate<<endl;
    return out;
}

//setter
void Fosil::setTip_combustibil(string tip_combustibil){
    this->tip_combustibil=tip_combustibil;
}

void Fosil::set_capacitate(int capacitate) {
    this->capacitate=capacitate;
}

string Fosil::getTip_combustibil() const{
    return tip_combustibil;
}

int Fosil::get_capacitate() const {
    return capacitate;
}

double Fosil::Autonomie(){
    return capacitate/sqrt(greutate);
}
class Electric : virtual public Masina{
protected :
    int capacitatea_bateriei;
public:
    Electric();
    Electric(string nume,string model,int an_productie,int viteza_maxima,int greutate,int capacitatea_bateriei);
    Electric(const Electric& e);
    Electric & operator=(const Electric& e);
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    void setCap(int capacitatea_bateriei);
    int getCap() const;
    double Autonomie();
};

Electric& Electric::operator=(const Electric &e) {
    if(this!=&e){
        Masina::operator=(e);
        this->capacitatea_bateriei=capacitatea_bateriei;
    }
}
Electric::Electric():Masina(){
    this->capacitatea_bateriei=0;
}
Electric::Electric(string nume,string model,int an_productie,int viteza_maxima,int greutate,int capacitatea_bateriei):Masina(nume,model,an_productie,viteza_maxima,greutate){
    this->capacitatea_bateriei=capacitatea_bateriei;
}
Electric::Electric(const Electric& e):Masina(e){
    this->capacitatea_bateriei=e.capacitatea_bateriei;
}
istream& Electric::citire(istream& in){
    Masina::citire(in);
    cout<<"Dati capacitatea bateriei masinii electrice: ";
    in>>this->capacitatea_bateriei;
    return in;
}
ostream& Electric::afisare(ostream& out)const{
    Masina::afisare(out);
    cout<<"Capacitatea bateriei electrice este :";
    out<<this->capacitatea_bateriei;
    return out;
}
double Electric::Autonomie(){
    return capacitatea_bateriei/(greutate*greutate);
}

class Hibrid: public Fosil, public Electric{
public:
    istream& citire(istream & in);
    ostream& afisare(ostream& out)const;
    double Autonomie();

};

istream& Hibrid::citire(istream& in){
    cout<<"Detalii Hibrid ";
    cout<<"baterie ";
    in>>capacitatea_bateriei;
    //Fosil::citire();
    return in;
}
 ostream& Hibrid::afisare(ostream& out) const{
    out<<"Capacitatea bateriei "<<capacitatea_bateriei;
    return out;
}

double Hibrid::Autonomie(){
    return Fosil::Autonomie()+Electric::Autonomie();
}
class Tranzactie{
private:
    string nume;
    string data;
    vector <Masina *> m;
public:
    Tranzactie()=default;
    Tranzactie(string nume,string date,const vector <Masina> m);
    Tranzactie(const Tranzactie& t);
    void citire();
    void afisare();
    void setNume(string nume);
    void setData(string data);
    string getNume() const;
    string getDate() const;
    const vector <Masina *>  &getLista() const{
        return m;
    };
    friend class Meniu;
    void setLista(const vector<Masina *> m){
        Tranzactie::m=m;
    };
};
Tranzactie::Tranzactie(string nume,string date,const vector<Masina>) {
    this->nume=nume;
    this->data=data;
    this->m=m;
}
Tranzactie::Tranzactie(const Tranzactie& t){
    this->nume=t.nume;
    this->data=t.nume;
    this->m=t.m;
}
void Tranzactie::citire() {
    cout << "Numele clientului este ";
    cin >> nume;
    cout << "Data clientului este ";
    cin >> data;
    int x = 1;
    while (x != 0) {
        string tip;
        cout << "Ce tip de masini doriti?????? ";
        cin >> tip;
        if (tip == "Fosil") m.push_back(new Fosil());
        else if (tip == "Electric") m.push_back(new Electric());
        else m.push_back(new Hibrid());
        cout << "Doriti sa cititi caracteristicile altei masini 1-Da , 0-NU";
        cin >> x;
    }
}
void Tranzactie::afisare(){
    cout<<"In data de"<<data<<" "<<nume<<"a cumparat masinile :\n";
    for(auto p=m.begin();p!=m.end();p++)
        (**p).afisare();
    for(auto q=m.rbegin();q!=m.rend();q++)
        (*q)->afisare();
}
void Tranzactie::setNume(string nume) {
    this->nume=nume;
}
void Tranzactie::setData(string data) {
    this->data=data;
}
string Tranzactie::getNume() const {
    return nume;
}
string Tranzactie::getDate() const {
    return data;
}
class Meniu{
    vector<Masina*> vm;
    vector<Tranzactie> vt;
public:
    void adauga_masina(string);
    void adauga_tranzactia();
    string cel_mai_vandut_model();
    string autonomia_mare();
    string creste_viteza(string , double);
    void afisare_tranzactii();
    void afis_meniu();
};
void Meniu::adauga_masina(string s){
    if(s=="Fosil") vm.push_back(new Fosil());
    else
        if(s=="Electric") vm.push_back(new Electric());
        else vm.push_back(new Hibrid());
    (*vm.back()).citire();
}
void Meniu::adauga_tranzactia() {
    Tranzactie t;
    t.citire();
    vt.push_back(t);
}
string Meniu::cel_mai_vandut_model() {
    vector<string> vs;
    for(auto t=vt.begin();t!=vt.end();t++)
        for(int i=0;i<t->m.size();i++)
            vs.push_back(t->m[i]->getModel());
    int nrmax=0;
    string smax="";
    for(int i=0;i<vs.size();i++)
    {
        int x=count(vs.begin(),vs.end(),vs[i]);
        if(x>nrmax)
        {
            nrmax=x;
            smax=vs[i];
        }
    }
    return smax;
}
string Meniu::autonomia_mare() {
    double max=0;
    string smax="";
    for(auto t=vt.begin();t!=vt.end();t++)
        for(int i=0;i<t->m.size();i++)
            if(t->m[i]->autonomie()>max){
                smax=t->m[i]->getModel();
                max=t->m[i]->autonomie();
            }
    return smax;
}
string Meniu::creste_viteza(string s, double procent) {
    for (auto t = vt.begin(); t != vt.end(); t++) {
        for (int i = 0; i<t->m.size(); i++)
            if (s == t->m[i]->getModel())
                t->m[i]->setVit((1 + procent) * t->m[i]->getVit());
    }
}
void Meniu::afisare_tranzactii() {
    for(auto p=vt.begin();p!=vt.end();p++)
        (*p).afisare();

}

void Meniu::afis_meniu(){
    cout<<"1. Adauga un nou model de masina citind de la tastatura topul masinii\n";
    cout<<"2. Adauga o tranzactie\n";
    cout<<"3.Afiseaza cel mai vandut model\n";
    cout<<"4.Afiseaza modelul cu autonomia cea mai mare \n";
    cout<<"5.Aduce o optimizare a unui anumit model crescandu-i viteza maxima cu un procent\n";
    cout<<"6.Afisarea tuturor tranzactiilor\n";

    int x;
    cout<<"Ce optiunea vreti sa alegeti?";
    cin>>x;
    while(x>=1 && x<=6){
        switch(x)
        {
            case 1:
            {
                string s;
                cout<<"Ce tip de masina doriti sa cititi ?";
                cin>>s;
                adauga_masina(s);
                break;
            }
            case 2:{
                adauga_tranzactia();
                break;
            }
            case 3:{
                cout<<"\nCel mai vandut model este "<<cel_mai_vandut_model()<<"\n";
                break;
            }
            case 4:{
                cout<<"\nModelul cu autonomia cea mai amre este "<<autonomia_mare()<<"\n";
                break;
            }
            case 5:{
                string s;
                cout<<"\nCe model de masini doriti sa optimizati?";
                cin>>s;
                double procent;
                cin>>procent;
                creste_viteza(s,procent);
                break;
            }
            case 6:{
                afisare_tranzactii();
                break;
            }
        }
        cout<<"1. Adauga un nou model de masina citind de la tastatura tipul masinii si apoi campurile specifice ei\n";
        cout<<"2. Adauga o tranzactie\n";
        cout<<"3. Afiseaza cel mai vandut model\n";
        cout<<"4. Afiseaza modelul cu autonomia cea mai mare\n";
        cout<<"5. Aduce o optimizare a unui anumit model crescandu-i viteza maxima cu un anumit procent\n";
        cout<<"6. Afisarea tuturor tranzactiilor\n";

        cout<<"Alta optiune?  ";
        cin>>x;
    }
}
