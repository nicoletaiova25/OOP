#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
class Jucarie{
protected:
    string denumire;
    double dimensiune;
    string tip;
public:
    Jucarie();
    Jucarie(string denumire,double dimensiune,string tip);
    Jucarie(const Jucarie &j);
    friend istream &operator>>(istream& in,Jucarie& j);
    friend ostream &operator<<(ostream& out,const Jucarie& j);
    virtual void citire(istream& in);
    virtual void afisare(ostream& out) const;
    //setter
    void setDen(string denumire);
    void setDim(double dimensiune);
    void setTip(string tip);
    //getter
    string getDen() const;
    double getDim() const;
    string getTip() const;
    virtual ~Jucarie()=default;
    Jucarie &operator=(const Jucarie& j);

};
Jucarie& Jucarie::operator=(const Jucarie& m){
    this->denumire=denumire;
    this->dimensiune=dimensiune;
    this->tip=tip;

}
Jucarie::Jucarie(){
    this->denumire="";
    this->tip="";
    this->dimensiune=0;
}
Jucarie::Jucarie(string denumire ,double dimensiune ,string tip){
    this->denumire=denumire;
    this->tip=tip;
    this->dimensiune=dimensiune;
}
istream &operator>>(istream &in, Jucarie &j) {
    j.citire(in);
    return in;
}

ostream &operator<<(ostream &out, const Jucarie &j) {
    j.afisare(out);
    return out;
}

void Jucarie::citire(istream &in) {
    cout<<"denumirea jucariei: ";
    in>>denumire;

    cout<<"dimensiune: ";
    in>>dimensiune;

    cout<<"tip ";
    in>>tip;
}

void Jucarie::afisare(ostream &out) const {
    out<<"denumire: "<<denumire<<endl;
    out<<"dimensiune: "<<dimensiune<<endl;
    out<<"tip: "<<tip<<endl;

}
//seturi
void Jucarie::setDen(string denumire) {
    this->denumire=denumire;
}
void Jucarie::setTip(string tip) {
    this->tip=tip;
}
void Jucarie::setDim(double dimensiune) {
    this->dimensiune=dimensiune;
}
string Jucarie::getDen() const {
    return denumire;
}
string Jucarie::getTip() const {
    return tip;
}
double Jucarie::getDim() const {
    return dimensiune;
}
class Clasic:public Jucarie{
private:
    string material,culoare;
public:
    Clasic();
    Clasic(string denumire ,double dimensiune,string tip,string material,string culoare);
    Clasic(const Clasic& c);
    void citire(istream &in) override;
    void afisare(ostream &out) const override;
    //operator
    Clasic& operator=(const Clasic& c);
    //setter
    void setMaterial(string material);
    void setCuloare(string culoare);
    //getter
    string getMaterial() const;
    string getCuloare() const;
    ~Clasic() override =default;
};
Clasic& Clasic::operator=(const Clasic& c){
    if(this!=&c){
        Jucarie::operator=(c);
        this->material=material;
        this->culoare=culoare;
    }
}
Clasic::Clasic():Jucarie(){
    this->material="";
    this->culoare="";
}
Clasic::Clasic(string denumire, double dimensiune,string tip,string material,string culoare):Jucarie(denumire,dimensiune,tip){
    this->material=material;
    this->tip=tip;
}
void Clasic::citire(istream &in) {
    Jucarie::citire(in);
    cout<<"material ";
    in>>material;
    cout<<"culoare ";
    in>>culoare;

}

void Clasic::afisare(ostream &out) const {
    Jucarie::afisare(out);
    out<<"Material"<<material<<endl;
    out<<"Culaore"<<culoare<<endl;
}
void Clasic::setMaterial(string material) {
    this->material=material;
}
void Clasic::setCuloare(string culoare) {
    this->culoare=culoare;
}

string Clasic::getMaterial() const {
    return material;
}
string Clasic::getCuloare() const {
    return culoare;
}
class Educativ: virtual public Jucarie{
protected:
    string abilitate;
public:
    Educativ();
    Educativ(string denumire ,double dimensiune,string tip,string abilitate);
    Educativ( const Educativ& e);
    void citire(istream &in) override;
    void afisare(ostream &out) const override;
    //operator
    Educativ& operator=(const Educativ& e);
    //setter
    void setAbil(string abilitate);
    //getter
    string getAbil() const;
    ~Educativ() override =default;
};
Educativ& Educativ::operator=(const Educativ& e){
    if(this!=&e){
        Jucarie::operator=(e);
        this->abilitate=abilitate;
    }
}
Educativ::Educativ():Jucarie(){
    this->abilitate="";
}
Educativ::Educativ(string denumire, double dimensiune,string tip,string abilitate):Jucarie(denumire,dimensiune,tip){
    this->abilitate=abilitate;
}
void Educativ::citire(istream &in) {
    Jucarie::citire(in);
    cout<<"abilitate ";
    in>>abilitate;

}

void Educativ::afisare(ostream &out) const{
    Jucarie::afisare(out);
    out<<"Material"<<abilitate<<endl;
}
void Educativ::setAbil(string abilitate) {
    this->abilitate=abilitate;
}

string Educativ::getAbil() const {
    return abilitate;
}
class Electronic:virtual public Jucarie{
protected:
    int nr_baterii;
public:
    Electronic();
    Electronic(string denumire ,double dimensiune,string tip,int nr_baterii);
    Electronic( const Electronic& el);
    void citire(istream &in) override;
    void afisare(ostream &out) const override;
    //operator
    Electronic& operator=(const Electronic& el);
    //setter
    void setBat(int nr_baterii);
    //getter
    int getBat() const;
    ~Electronic() override =default;
};
Electronic& Electronic::operator=(const Electronic& el){
    if(this!=&el){
        Jucarie::operator=(el);
        this->nr_baterii=nr_baterii;
    }
}
Electronic::Electronic():Jucarie(){
    this->nr_baterii=0;
}
Electronic::Electronic(string denumire, double dimensiune,string tip,int nr_baterii):Jucarie(denumire,dimensiune,tip){
    this->nr_baterii=nr_baterii;
}
void Electronic::citire(istream &in) {
    Jucarie::citire(in);
    cout<<"Numarul baterii este  ";
    in>>nr_baterii;

}

void Electronic::afisare(ostream &out)const {
    Jucarie::afisare(out);
    out<<"Baterii"<<nr_baterii<<endl;
}
void Electronic::setBat(int nr_baterii) {
    this->nr_baterii=nr_baterii;
}
int Electronic::getBat() const {
    return nr_baterii;
}
class Moderne:public Educativ,public Electronic{
private:
    string brand,model;
public:
    Moderne();
    Moderne(string denumire,double dimensiune,string tip,string abilitate,int nr_baterii,string brand,string model);
    Moderne(const Moderne& m);
    ~Moderne() override=default;
    void citire(istream &in) override;
    void afisare(ostream &out) const override;
    //operator
    Moderne& operator=(const Moderne& m);
    //setter
    void setBrand(string brand);
    void setModel(string model);
    //getter
    string getBrand() const;
    string getModel() const;

};
Moderne& Moderne::operator=(const Moderne& m){
    if(this!=&m){
        Educativ::operator=(m);
       this->brand=m.brand;
       this->model=m.model;
    }
}
Moderne::Moderne(){
    this->brand="";
    this->model="";
}
Moderne::Moderne(string denumire, double dimensiune,string tip,string abilitate,int nr_baterii,string brand,string model):Jucarie(denumire,dimensiune,tip),Educativ(denumire,dimensiune,tip,abilitate ),Electronic(denumire,dimensiune,tip,nr_baterii){
    this->model=model;
    this->brand=brand;
    this->nr_baterii=1;
    this->abilitate="generala";
}
void Moderne::citire(istream &in) {
    cout<<"denumirea jucariei: ";
    in>>denumire;

    cout<<"dimensiune: ";
    in>>dimensiune;

    cout<<"tip ";
    in>>tip;

    cout<<"brand";
    in>>brand;

    cout<<"model";
    in>>model;

}

void Moderne::afisare(ostream &out)const {
    Educativ::afisare(out);
    out<<"Baterii"<<nr_baterii<<endl;
    out<<"Brand"<<brand<<"\n";
    out<<"Model"<<model<<"\n";
}
void Moderne::setBrand(string brand) {
    this->brand=brand;
}
void Moderne::setModel(string model){
    this->model=model;
}
string Moderne::getModel() const {
    return model;
}
string Moderne::getBrand() const {
    return brand;
}
enum class Copil_tip{
    cuminte,
    neascultator
};
class Copil{
protected:
    static int static_IDCopil;
    int idCopil{};
    int chestiiExtra;
    string nume;
    string prenume;
    string adresa;
    unsigned int varsta{};
    unsigned int nr_fapte_bune{};
    vector<shared_ptr<Jucarie>> jucarii;
    Copil_tip tp;
public:
    Copil()=default;
    virtual ~Copil()=default;
    Copil(string nume,string prenume,string adresa,unsigned int varsta,unsigned int numar_fapte_bune,vector<shared_ptr<Jucarie>> &jucarii);
    Copil(const Copil&)=default;
    Copil &operator=(const Copil&)=default;
    friend istream& operator>>(istream& in,Copil& copil);
    friend ostream& operator<<(ostream& out,const Copil& copil);
    virtual void citire(istream& in);
    virtual void afisare(ostream& out) const;
    bool searchName(string &);
    int getVarsta(){return varsta;}
    int getFapte(){return nr_fapte_bune;}
};
int Copil::static_IDCopil=0;

Copil::Copil(string nume,string prenume,string adresa,unsigned int varsta ,unsigned int numar_fapte_bune,vector<shared_ptr<Jucarie>> &jucarii){

    idCopil = ++static_IDCopil;
    this->nume=nume;
    this->prenume=prenume;
    this->adresa=adresa;
    this->varsta=varsta;
    this->nr_fapte_bune=nr_fapte_bune;
    this->jucarii=jucarii;
}
void Copil::citire(istream& in) {
    cout << "Nume :";
    in >> nume;
    cout << "Prenume";
    in >> prenume;
    cout << "Adresa";
    in >> adresa;
    cout << "Varsta";
    in >> varsta;
    cout<<"Cum a fost copilul?\n 1.Cuminte\n2.Neascultator"<<endl;
    unsigned int option;
    cin >> option;
        switch(option){
            case 1:{
                tp=Copil_tip::cuminte;
                break;
            }
            case 2:{
                tp=Copil_tip::neascultator;
                break;
            }
            default:
            {
                throw "Nu avem copii";
                break;
            }
        }
        cout<<"Care este nr de fapte bune?"<<endl;
        in>>nr_fapte_bune;
        while(tp==Copil_tip::cuminte&& nr_fapte_bune<10){
            cout<<"TREbuie 10 fp bune"<<endl;
            cout<<"Deci care sunt faptele bune"<<endl;
            in>>nr_fapte_bune;
        }
        if(tp==Copil_tip::cuminte)
            //dulciuri
            in>>chestiiExtra;
        else
            //nr carbuni
            in>>chestiiExtra;
    for (int i = 0; i < nr_fapte_bune/10; i++) {
        shared_ptr<Jucarie> tipJuc;
        unsigned int opt;
        cout << "ce tip de jucarie doriti sa selectati?(1-clasica,2-educativa,3-electronica,4-moderna):";
        cin>>opt;
        switch (opt) {
            case 1: {
                tipJuc = make_shared<Clasic>();
                break;
            }
            case 2: {
                tipJuc = make_shared<Educativ>();
                break;
            }
            case 3: {
                tipJuc = make_shared<Electronic>();
                break;
            }
            case 4: {
                tipJuc = make_shared<Moderne>();
                break;
            }
            default: {
                cout << "Optiunea invalida";
                break;
            }
                try {
                    tipJuc->citire(cin);
                } catch (runtime_error &e) {
                    cout << "Eroare " << e.what() << "\n";
                }
        }
        jucarii.push_back(tipJuc);
    }
}
void Copil::afisare(ostream& out) const{
    out<<"Nume si prenume"<<nume<<""<<prenume<<"\n";
    out<<"Adresa"<<adresa<<"\n";
    out<<"Varsta"<<varsta<<"\n";
    out<<"Numar fapte bune"<<nr_fapte_bune<<"\n";
    if(tp==Copil_tip::cuminte)
        out<<"Copil cuminte si primeste "<<chestiiExtra<<"dulciuri"<<endl;
    else
        out<<"Copilul a fost naspa si are "<<chestiiExtra<<"carbuni"<<endl;
    out<<"Jucarii:\n";
    for(auto &jucarie:jucarii){
        jucarie->afisare(out);
    }
}
istream &operator>>(istream &in,Copil &copil){
    copil.citire(in);
    return in;
}
ostream &operator<<(ostream &out,Copil &copil){
    copil.afisare(out);
    return out;
}
bool Copil::searchName(std::string &_nume){
    if(nume.find(_nume)||prenume.find(_nume))
        return true;
    return false;
}
class Interfata{
    vector<shared_ptr<Copil>> copii;
public:
    Interfata(){};
    void start();
    int comparareVarsta(shared_ptr<Copil> &a,shared_ptr<Copil> &b);
    int comparareFapte(shared_ptr<Copil> &a,shared_ptr<Copil> &b);
};
void Interfata::start(){
    int i=1;
    while(i) {
        try {
            cout
                    << "ACTIUNI\n 1.ADAUGARE COPII\n 2.CAUTATI COPIL DUPA NUME SI DATE\n 3.ORDONARE COPII FAPTE \n4.AFISARE COPII\n5.ORDONARE VARSTA"
                    << endl;
            cin >> i;
            switch (i)
            {
                case 1:
                {
                    int j;
                    shared_ptr<Copil> aux;
                    cout << "Nr copii adaugat";
                    cin >> j;
                    for (int k = 0; k < j; k++) {
                        aux = make_shared<Copil>();
                        cin >> *aux;
                        copii.push_back(aux);
                    }
                    break;
                }
                case 2: {
                    string aux;
                    cin >> aux;
                    for (auto copil: copii) {
                        if (copil->searchName(aux))
                            cout << *copil;
                    }
                    break;
                }
                case 3: {
                    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil> &lhs, const shared_ptr<Copil> &rhs) {
                        return lhs->getFapte() < rhs->getFapte();
                    });
                    break;
                }
                case 4: {
                    for (auto copil: copii) {
                        cout << *copil;
                    }
                    break;

                }
                case 5: {
                    sort(copii.begin(), copii.end(), [](const shared_ptr<Copil> &lhs, const shared_ptr<Copil> &rhs) {
                        return lhs->getVarsta() < rhs->getVarsta();
                    });
                    break;
                }
                default: {
                    break;
                }
            }
            }
            catch(...){
                cout<<"EROARE"<<endl;
            }
        }
    };
int Interfata::comparareVarsta(shared_ptr<Copil> &a, shared_ptr<Copil> &b) {
    return a->getVarsta()>b->getVarsta();
}
int Interfata::comparareFapte(shared_ptr<Copil> &a, shared_ptr<Copil> &b) {
    return a->getFapte()>b->getFapte();
}
int main(){
    cout<<"Hello world";
    Interfata x;
    x.start();
    return 0;
}

