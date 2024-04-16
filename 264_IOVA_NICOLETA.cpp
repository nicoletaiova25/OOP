//264 IOVA NICOLETA CARMEN
//TUTORE DE LABORATOR AVASILOAIEI COMANESCU OCTAVIAN STEFAN
//VS CODE

//unele bucati de cod sunt preluate din coduri proprii sau reluate din prima clasa si modificate
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
    virtual ostream& afisare(ostream& out) const =0;
};

class VITEZAEXCEPTION:public exception{
    const char* what(){
        return "Viteza este prea mare !!!";
    }
};

class MASINA:public INTERFATA{
    protected:
    string nume, model;
    int an_productie;
    int viteza_maxima;
    int greutate;

    public:
    //constructori
    MASINA();
    //CONSTRUCTORI PARAMETRIZATI
    MASINA(string nume, string model, int an_productie, int viteza_maxima, int greutate);
    //copy constructor
    MASINA( const MASINA &m);
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream &operator>>(istream& in, MASINA& m);
    friend ostream &operator<<(ostream& out, MASINA& m);
    virtual double autonomie();
    //suprascriere operator
    MASINA &operator=(const MASINA& m);

    //setter
    void set_nume(string nume);
    void set_model(string model);
    void set_an(int an_productie);
    void set_viteza(int viteza_maxima);
    void set_greutate(int greutate);
    //getter
    string getNume() const;
    string getModel() const;
    int getAN() const;
    int getVIT() const;
    int getGREUTATE() const;

    //destructor
    ~MASINA()=default;

    ostream &afisare();
    istream &citire();
};

MASINA& MASINA::operator=(const MASINA& m){
    this->nume=nume;
    this->model=model;
    this->an_productie=an_productie;
    this->greutate=greutate;
    this->viteza_maxima=viteza_maxima;
}

MASINA::MASINA(){
    this->nume="";
    this->model="";
    this->an_productie=0;
    this->greutate=0;
    this->viteza_maxima=0;
}

MASINA::MASINA(const MASINA &m){
    this->nume=m.nume;
    this->an_productie=m.an_productie;
    this->model=m.model;
    this->greutate=m.greutate;
    this->viteza_maxima=m.viteza_maxima;
}

MASINA::MASINA(string nume, string model, int an_productie, int viteza_maxima, int greutate){
    this->nume=nume;
    this->model=model;
    this->an_productie=an_productie;
    this->greutate=greutate;
    this->viteza_maxima=viteza_maxima;
}

istream&MASINA::citire(istream& in){
    cout<<"Introduceti numele masinii"<<endl;
    in>>this->nume;
    cout<<"Introduteti modelul masinii"<<endl;
    in>>this->model;
    cout<<"Introduceti anul de productie al masinii"<<endl;
    in>>this->an_productie;
    cout<<"Introduceti greutatea masinii"<<endl;
    in>>this->greutate;
    while(this->viteza_maxima==0){
    cout<<"Introduceti viteza maxima a masinii"<<endl;
    in>>this->viteza_maxima;
    try{
        if(this->viteza_maxima>300)
            throw VITEZAEXCEPTION();
    }
    catch (exception& e){
        cout<<e.what()<<endl;
        cout<<"Introduceti o viteza valida!";
        this->viteza_maxima=0;
    }
    }

    return in;
}

ostream& MASINA::afisare(ostream& out) const{
    out<<"Numele masinii"<<this->nume;
    out<<"modelul masinii"<<this->model;
    out<<"Viteza masinii este"<< this->viteza_maxima;
    out<<"Greutatea masinii"<<this->greutate;
    out<<"Anul de productie al masinii este"<<this->an_productie;
    return out;
}

istream& operator>>(istream& in, MASINA& m){
    return m.citire(in);
}

ostream& operator<<(ostream&out, const MASINA& m){
    return m.afisare(out);
}

//setter

void MASINA::set_an(int an_productie){
    this->an_productie=an_productie;
}

void MASINA::set_nume(string nume){
    this->nume=nume;
}

void MASINA::set_greutate(int greutate){
    this->greutate=greutate;
}

void MASINA::set_model(string model){
    this->model=model;
}

void MASINA::set_viteza(int viteza_maxima){
    this->viteza_maxima=viteza_maxima;
}

//getter

string MASINA::getNume() const{
    return nume;
}

string MASINA::getModel() const{
    return model;
}

int MASINA::getAN() const{
    return an_productie;
}

int MASINA::getGREUTATE() const{
    return greutate;
}

int MASINA::getVIT() const{
    return viteza_maxima;
}

double MASINA::autonomie(){
    return 1.0;
}

class CombFosil: virtual public MASINA{
    protected:
    string tip_combustibil;
    int capacitate;

    public:
    CombFosil();
    CombFosil(string nume, string model, int an_productie, int viteza_maxima, int greutate, string tip_combustibil, int capacitate);
    CombFosil( const CombFosil& f);
    CombFosil& operator = (const CombFosil& f);
    istream& citire (istream& in);
    ostream& afisare (ostream& out) const;

    //seter
    void setTip_combustibil(string tip_combustibil);
    void set_capacitate(int capacitate);

    //getter
    string getTip_combustibil() const;
    int get_capacitate()const;

    virtual double autonomie();
    ~CombFosil()=default;
};

CombFosil& CombFosil::operator=(const CombFosil& f){
    if (this != &f) {
        MASINA::operator=(f);
        this->tip_combustibil = tip_combustibil;
        this->capacitate = capacitate;
    }
}

CombFosil::CombFosil():MASINA(){
    this->tip_combustibil="";
    this->capacitate=0;
}

CombFosil::CombFosil(string nume, string model, int an_productie,
 int viteza_maxima, int greutate, string tip_combustibil, int capacitate)
 :MASINA(nume,  model,  an_productie, viteza_maxima, greutate){
    this->tip_combustibil=tip_combustibil;
    this->capacitate=capacitate;
 }

CombFosil::CombFosil(const CombFosil &f):MASINA(f){
    this->tip_combustibil=f.tip_combustibil;
    this->capacitate=f.capacitate;
}

istream& CombFosil::citire (istream& in){
    MASINA::citire(in);
    cout<<"Introduceti tipul de combustibil al masinii"<<endl;
    in>>this->tip_combustibil;
    cout<<"Introduceti capacitatea rezervorului"<<endl;
    in>>this->capacitate;
    return in;
}

ostream& CombFosil::afisare (ostream& out) const{
    MASINA::afisare(out);
    out<<"Tipul de combustibil al masinii"<<this->tip_combustibil<<endl;
    out<<"Capacitatea rezervorului"<< this->capacitate<<endl;
    return out;
}

//setter

void CombFosil::setTip_combustibil(string tip_combustibil){
    this->tip_combustibil=tip_combustibil;
}

void CombFosil::set_capacitate(int capacitate){
    this->capacitate=capacitate;
}

//getter

string CombFosil::getTip_combustibil() const{
    return tip_combustibil;
}

int CombFosil::get_capacitate() const{
    return capacitate;
}

double CombFosil::autonomie(){
    return capacitate/sqrt(greutate);
}

class Electric: virtual public MASINA{
    protected:
    int capacitate_baterie;

    public:
    Electric()=default;
    Electric(string nume, string model, int an_productie,
     int viteza_maxima, int greutate, int capacitate_baterie);
    Electric(const Electric& e);
    Electric & operator=(const Electric& e);
    istream& citire (istream& in);
    ostream& afisare (ostream& out) const;

    //setter
    void set_capacitatebat(int capacitate_baterie);
    //getter
    int get_capacitate() const;

    double autonomie();

    ~Electric()=default;
};

Electric& Electric::operator=(const Electric &e) {
    if(this!=&e){
        MASINA::operator=(e);
        this->capacitate_baterie=capacitate_baterie;
    }
}

Electric::Electric():MASINA(){
    this->capacitate_baterie=0;
}

Electric::Electric(string nume,string model,int an_productie,
int viteza_maxima,int greutate,int capacitate_baterie)
:MASINA(nume,model,an_productie,viteza_maxima,greutate){
    this->capacitate_baterie=capacitate_baterie;
}

Electric::Electric(const Electric& e): MASINA(e){
    this->capacitate_baterie=e.capacitate_baterie;
}

istream& Electric::citire(istream& in){
    MASINA::citire(in);
    cout<<"Introduceti capacitatea bateriei masinii electrice: ";
    in>>this->capacitate_baterie;
    return in;
}
ostream& Electric::afisare(ostream& out)const{
    MASINA::afisare(out);
    cout<<"Introduceti capacitatea bateriei electrice este :";
    out<<this->capacitate_baterie;
    return out;
}

double Electric:: autonomie(){
    return capacitate_baterie/(greutate*greutate);
}

class Hibrid: public CombFosil, public Electric{
    public:
    istream& citire (istream& in);
    ostream& afisare (ostream& out) const;
    double autonomie();

    Hibrid()=default;
    ~Hibrid()=default;
    Hibrid(const Hibrid& h):CombFosil(h):Electric(h);
};

istream& Hibrid::citire(istream& in){
    cout<<"Detalii Hibrid ";
    cout<<"baterie ";
    in>>capacitate_baterie;
    return in;
}
 ostream& Hibrid::afisare(ostream& out) const{
    out<<"Capacitatea bateriei "<<capacitate_baterie;
    return out;
}

double Hibrid:: autonomie(){
    return CombFosil::autonomie() + Electric::autonomie();
}


class Tranzactie{
    private: 
    string nume;
    string data;
    vector <MASINA *> m;

    public:
    Tranzactie()=default;
    Tranzactie( string nume, string date, const vector <MASINA> m);
    Tranzactie(const Tranzactie& t);
    void citire();
    void afisare();
    void setNume(string nume);
    void setData(string data);
    string getNume() const;
    string getDate() const;
    const vector <MASINA *>  &getLista() const{
        return m;
    };
    friend class Meniu;
    void setLista(const vector<MASINA *> m){
        Tranzactie::m=m;
    };
};

Tranzactie::Tranzactie(string nume,string date,const vector<MASINA>) {
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
        if (tip == "Fosil") m.push_back(new CombFosil());
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
    vector<MASINA*> vm;
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
    if(s=="Fosil") vm.push_back(new CombFosil());
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
                t->m[i]->set_viteza((1 + procent) * t->m[i]->getVIT());
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


