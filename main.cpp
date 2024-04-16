#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <map>
#include <fstream>
#include <ostream>
using namespace std;

class Vaccin {
protected:
    double price;
    double temp;
    string numeproducator;
    vector<string> substancelist;
public:
    Vaccin(double price, double temp, const string &numeproducator, const vector<string> &substancelist);

    Vaccin();

    const string &getNumeproducator() const;

    void setNumeproducator(const string &numeproducator);

    virtual ~Vaccin();

    Vaccin(const Vaccin &vaccin);

    Vaccin &operator=(const Vaccin &var);

    friend ostream &operator<<(ostream &os, const Vaccin &vaccin);

    friend istream &operator>>(istream &is, Vaccin &vaccin);

    virtual void citire(istream &istream);

    virtual void afisare(ostream &ostream) const;

    double getPrice() const;

    void setPrice(double price);

    double getTemp() const;

    void setTemp(double temp);

    const vector<string> &getSubstancelist() const;

    void setSubstancelist(const vector<string> &substancelist);

    virtual void afisareSchemaVaccinare() = 0;
};
ostream &operator<<(ostream &os, const Vaccin &vaccin) {
    vaccin.afisare(os);
    return os;
}

istream &operator>>(istream &is, Vaccin &vaccin) {
    vaccin.citire(is);
    return is;
}

void Vaccin::citire(istream &istream) {
    substancelist.clear();
    cout << "price: ";
    istream >> price;
    cout << " temp: ";
    istream >> temp;
    cout<< " numeproducator: ";
    istream>> numeproducator;
    cout << " Cate substante? ";
    int n;
    istream >> n;
    string subst;
    istream.get();
    for (int i = 0; i < n; ++i) {
        cout << "Substanta #" << i + 1 << ": ";
        getline(istream, subst);
        substancelist.push_back(subst);
    }
}

double Vaccin::getPrice() const {
    return price;
}

void Vaccin::setPrice(double price) {
    Vaccin::price = price;
}

double Vaccin::getTemp() const {
    return temp;
}

void Vaccin::setTemp(double temp) {
    Vaccin::temp = temp;
}

const vector<string> &Vaccin::getSubstancelist() const {
    return substancelist;
}

void Vaccin::setSubstancelist(const vector<string> &substancelist) {
    Vaccin::substancelist = substancelist;
}

Vaccin::Vaccin(const Vaccin &vaccin) : price(vaccin.price), temp(vaccin.temp), numeproducator(vaccin.numeproducator),
                                       substancelist(vaccin.substancelist) {}

void Vaccin::afisare(ostream &ostream) const{
    ostream << '\n';
    ostream << "price: " << price << " temp: " << temp << " substancelist: ";
    for (auto &i: substancelist) {
        ostream << i;
        ostream << " ";
    }
    ostream << '\n';
}

Vaccin::Vaccin(double price, double temp, const string &numeproducator, const vector<string> &substancelist) : price(
        price), temp(temp), numeproducator(numeproducator), substancelist(substancelist) {}

Vaccin::Vaccin() : price(0),temp(0) {}

Vaccin &Vaccin::operator=(const Vaccin &var) {
    price=var.price;
    temp=var.temp;
    numeproducator=var.numeproducator;
    substancelist=var.substancelist;
    return *this;
}

Vaccin::~Vaccin() {
    substancelist.clear();
}

void Vaccin::afisareSchemaVaccinare() {

}

const string &Vaccin::getNumeproducator() const {
    return numeproducator;
}

void Vaccin::setNumeproducator(const string &numeproducator) {
    Vaccin::numeproducator = numeproducator;
}
class VaccinAntigripal : public Vaccin {
    vector<string> tulpiniagreate;
    bool oms;
public:
    VaccinAntigripal(double price, double temp, const string &numeproducator, const vector<string> &substancelist,
                     const vector<string> &tulpiniagreate, bool oms);

    VaccinAntigripal &operator=(const VaccinAntigripal &var);

    VaccinAntigripal();

    virtual ~VaccinAntigripal();

    VaccinAntigripal(const VaccinAntigripal &var);

    const vector<string> &getTulpiniagreate() const;

    void setTulpiniagreate(const vector<string> &tulpiniagreate);

    bool isOms() const;

    void setOms(bool oms);

    void citire(istream &istream) override;

    void afisare(ostream &ostream) const override;

    void afisareSchemaVaccinare() override;
};
VaccinAntigripal::VaccinAntigripal() : Vaccin(), oms(0) {}

const vector<string> &VaccinAntigripal::getTulpiniagreate() const {
    return tulpiniagreate;
}

void VaccinAntigripal::setTulpiniagreate(const vector<string> &tulpiniagreate) {
    VaccinAntigripal::tulpiniagreate = tulpiniagreate;
}

bool VaccinAntigripal::isOms() const {
    return oms;
}

void VaccinAntigripal::setOms(bool oms) {
    VaccinAntigripal::oms = oms;
}

VaccinAntigripal::VaccinAntigripal(const VaccinAntigripal &var) : Vaccin(var), tulpiniagreate(var.tulpiniagreate),
                                                                  oms(var.oms) {}

VaccinAntigripal::VaccinAntigripal(double price, double temp, const string &numeproducator,
                                   const vector<string> &substancelist, const vector<string> &tulpiniagreate, bool oms)
        : Vaccin(price, temp, numeproducator, substancelist), tulpiniagreate(tulpiniagreate), oms(oms) {}

VaccinAntigripal &VaccinAntigripal::operator=(const VaccinAntigripal &var) {
    Vaccin::operator=(var);
    tulpiniagreate = var.tulpiniagreate;
    oms = var.oms;
    return *this;
}

VaccinAntigripal::~VaccinAntigripal() {
    tulpiniagreate.clear();
}

void VaccinAntigripal::citire(istream &istream) {
    Vaccin::citire(istream);
    cout << " Agreat de OMS?: ";
    istream >> oms;
    cout << " Cate tulpini? ";
    int n;
    istream >> n;
    string subst;
    istream.get();
    for (int i = 0; i < n; ++i) {
        cout << "Tulpina #" << i + 1 << ": ";
        getline(istream, subst);
        tulpiniagreate.push_back(subst);
    }
}

void VaccinAntigripal::afisare(ostream &ostream) const {
    Vaccin::afisare(ostream);
    ostream << " Agreat de OMS?: " << oms << '\n';
    ostream << " Tulpinile ";
    for (auto &i: tulpiniagreate) {
        ostream << i << " ";
    }
    ostream << '\n';
}

void VaccinAntigripal::afisareSchemaVaccinare() {
    cout << "Se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti o doza de 0.3 ml, repetandu-se din 2 in 2 ani\n";
}
class VaccinAntihepatic : public Vaccin {
    enum Tulpina {
        A, B, C
    } tipTulpina;
    enum ModVaccinare {
        intramuscular, subcutanat, intradermic
    } modVaccinare;
public:
    VaccinAntihepatic(double price, double temp, const string &numeproducator, const vector<string> &substancelist,
                      Tulpina tipTulpina, ModVaccinare modVaccinare);

    VaccinAntihepatic();

    VaccinAntihepatic(const VaccinAntihepatic &var);

    virtual ~VaccinAntihepatic();

    VaccinAntihepatic &operator=(const VaccinAntihepatic &var);

    void citire(istream &istream) override;

    void afisare(ostream &ostream) const override;

    void afisareSchemaVaccinare() override;

    Tulpina getTipTulpina() const;

    void setTipTulpina(Tulpina tipTulpina);

    ModVaccinare getModVaccinare() const;

    void setModVaccinare(ModVaccinare modVaccinare);
};
VaccinAntihepatic::VaccinAntihepatic(double price, double temp, const string &numeproducator,
                                     const vector<string> &substancelist, VaccinAntihepatic::Tulpina tipTulpina,
                                     VaccinAntihepatic::ModVaccinare modVaccinare) : Vaccin(price, temp, numeproducator,
                                                                                            substancelist),
                                                                                     tipTulpina(tipTulpina),
                                                                                     modVaccinare(modVaccinare) {}

VaccinAntihepatic::VaccinAntihepatic() : Vaccin(),tipTulpina(),modVaccinare() {}

VaccinAntihepatic::VaccinAntihepatic(const VaccinAntihepatic &var) : Vaccin(var), tipTulpina(var.tipTulpina),
                                                                     modVaccinare(var.modVaccinare) {
}

VaccinAntihepatic &VaccinAntihepatic::operator=(const VaccinAntihepatic &var) {
    Vaccin::operator=(var);
    tipTulpina = var.tipTulpina;
    modVaccinare = var.modVaccinare;
    return *this;
}

VaccinAntihepatic::~VaccinAntihepatic() {

}

void VaccinAntihepatic::citire(istream &istream) {
    Vaccin::citire(istream);
    cout << " tipTulpina (A,B,C): ";
    char str;
    istream >> str;
    if (str == 'A')
        tipTulpina = Tulpina::A;
    if (str == 'B')
        tipTulpina = Tulpina::B;
    if (str == 'C')
        tipTulpina = Tulpina::C;
    cout << '\n';
    cout << " modVaccinare (intramuscular, subcutanat, intradermic): ";
    string str1;
    istream >> str1;
    if (str1 == "intramuscular")
        modVaccinare = ModVaccinare::intramuscular;
    if (str1 == "subcutanat")
        modVaccinare = ModVaccinare::subcutanat;
    if (str1 == "intradermic")
        modVaccinare = ModVaccinare::intradermic;
    cout << '\n';

}

void VaccinAntihepatic::afisare(ostream &ostream) const {
    Vaccin::afisare(ostream);
    ostream << " tiptulpina: ";
    switch (tipTulpina) {
        case 0: {
            cout << 'A';
            break;
        }
        case 1: {
            cout << 'B';
            break;
        }
        case 2: {
            cout << 'C';
            break;
        }
        default: {
            cout << '7';
            break;
        }
    }
    ostream << '\n';
    ostream << " modVaccinare: ";
    switch (modVaccinare) {
        case 0: {
            cout << "intramuscular";
            break;
        }
        case 1: {
            cout << "subcutanat";
            break;
        }
        case 2: {
            cout << "intradermic";
            break;
        }
        default: {
            cout << '7';
            break;
        }
    }
    ostream << '\n';
}

void VaccinAntihepatic::afisareSchemaVaccinare() {
    if (tipTulpina == Tulpina::A || tipTulpina == Tulpina::B)
        cout<< "La copii cu varsta mai mica de 1 an se adminstreaza 2 injectari la un interval de o luna, a treia injectare dupa 6 luni de la prima administrare, la adulti conform schemei de imunizare recomandata de medic\n";
    else
        cout << "Doar la recomandarea medicului\n";
}

VaccinAntihepatic::Tulpina VaccinAntihepatic::getTipTulpina() const {
    return tipTulpina;
}

void VaccinAntihepatic::setTipTulpina(VaccinAntihepatic::Tulpina tipTulpina) {
    VaccinAntihepatic::tipTulpina = tipTulpina;
}

VaccinAntihepatic::ModVaccinare VaccinAntihepatic::getModVaccinare() const {
    return modVaccinare;
}

void VaccinAntihepatic::setModVaccinare(VaccinAntihepatic::ModVaccinare modVaccinare) {
    VaccinAntihepatic::modVaccinare = modVaccinare;
}
class VaccinAntiSarsCov2 : public Vaccin{
    vector<string> adversereactions;
    double eficienta;
    vector<string> medicamente;
public:
    VaccinAntiSarsCov2(double price, double temp, const string &numeproducator, const vector<string> &substancelist,
                       const vector<string> &adversereactions, double eficienta, const vector<string> &medicamente);

    VaccinAntiSarsCov2();

    const vector<string> &getAdversereactions() const;

    void setAdversereactions(const vector<string> &adversereactions);

    double getEficienta() const;

    void setEficienta(double eficienta);

    const vector<string> &getMedicamente() const;

    void setMedicamente(const vector<string> &medicamente);

    VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &var);

    virtual ~VaccinAntiSarsCov2();

    VaccinAntiSarsCov2 &operator=(const VaccinAntiSarsCov2 &var);

    void citire(istream &istream) override;

    void afisare(ostream &ostream) const override;

    void afisareSchemaVaccinare() override;
};
VaccinAntiSarsCov2::VaccinAntiSarsCov2(double price, double temp, const string &numeproducator,
                                       const vector<string> &substancelist, const vector<string> &adversereactions,
                                       double eficienta, const vector<string> &medicamente) : Vaccin(price, temp,
                                                                                                     numeproducator,
                                                                                                     substancelist),
                                                                                              adversereactions(
                                                                                                      adversereactions),
                                                                                              eficienta(eficienta),
                                                                                              medicamente(
                                                                                                      medicamente) {}

VaccinAntiSarsCov2::VaccinAntiSarsCov2() : eficienta(0){}

VaccinAntiSarsCov2::VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &var) : Vaccin(var), adversereactions(var.adversereactions), eficienta(var.eficienta), medicamente(var.medicamente){}

VaccinAntiSarsCov2::~VaccinAntiSarsCov2() {
    adversereactions.clear();
    medicamente.clear();
}

VaccinAntiSarsCov2 &VaccinAntiSarsCov2::operator=(const VaccinAntiSarsCov2 &var) {
    Vaccin::operator=(var);
    adversereactions=var.adversereactions;
    eficienta=var.eficienta;
    medicamente=var.medicamente;
    return *this;
}

void VaccinAntiSarsCov2::citire(istream &istream) {
    Vaccin::citire(istream);
    cout << " eficienta: ";
    istream >> eficienta;
    cout << " Cate reactii adverse? ";
    int n;
    istream >> n;
    string subst;
    istream.get();
    for (int i = 0; i < n; ++i) {
        cout << "Reactia adversa #" << i + 1 << ": ";
        getline(istream, subst);
        adversereactions.push_back(subst);
    }

    cout<<'\n';
    cout << " Cate medicamente? ";
    istream >> n;
    istream.get();
    for (int i = 0; i < n; ++i) {
        cout << "Medicamentul #" << i + 1 << ": ";
        getline(istream, subst);
        medicamente.push_back(subst);
    }
    cout<<'\n';

}

void VaccinAntiSarsCov2::afisare(ostream &ostream) const {
    Vaccin::afisare(ostream);
    ostream << " eficienta: " << eficienta <<'\n';
    ostream << " Adversereactions ";
    for (auto &i: adversereactions) {
        ostream << i << " ";
    }
    ostream << '\n';
    ostream << " Medicamente ";
    for (auto &i: medicamente) {
        ostream << i << " ";
    }
    ostream << '\n';
}

const vector<string> &VaccinAntiSarsCov2::getAdversereactions() const {
    return adversereactions;
}

void VaccinAntiSarsCov2::setAdversereactions(const vector<string> &adversereactions) {
    VaccinAntiSarsCov2::adversereactions = adversereactions;
}

double VaccinAntiSarsCov2::getEficienta() const {
    return eficienta;
}

void VaccinAntiSarsCov2::setEficienta(double eficienta) {
    VaccinAntiSarsCov2::eficienta = eficienta;
}

const vector<string> &VaccinAntiSarsCov2::getMedicamente() const {
    return medicamente;
}

void VaccinAntiSarsCov2::setMedicamente(const vector<string> &medicamente) {
    VaccinAntiSarsCov2::medicamente = medicamente;
}

void VaccinAntiSarsCov2::afisareSchemaVaccinare() {
    cout << "Se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 zile\n";
}
unsigned int Comanda::idstatic=0;
class Comanda {
    static unsigned int idstatic;
    unsigned int id;
    string date;
    string numeClient;
    map<Vaccin*, int> vac;
public:
    Comanda();

    Comanda(const string &date, const string &numeClient, const map<Vaccin *, int> &vac);

    Comanda(const string &date, const string &numeClient, string tipvaccin, int cantitate);

    static unsigned int getIdstatic();

    static void setIdstatic(unsigned int idstatic);

    unsigned int getId() const;

    const string &getDate() const;

    void setDate(const string &date);

    const string &getNumeClient() const;

    void setNumeClient(const string &numeClient);

    const map<Vaccin *, int> &getVac() const;

    void setVac(const map<Vaccin *, int> &vac);

    Comanda(const Comanda &var);

    virtual ~Comanda();

    friend ostream &operator<<(ostream &os, const Comanda &comanda);

    friend istream &operator>>(istream &is, Comanda &comanda);

    double valtot ()const;
};
Comanda::Comanda(const string &date, const string &numeClient, const map<Vaccin *, int> &vac)
        : id(++idstatic),
          date(date),
          numeClient(
                  numeClient) {
    for (auto &i: vac) {
        if (dynamic_cast<VaccinAntigripal *>(i.first)) {
            VaccinAntigripal *cop = new VaccinAntigripal(*dynamic_cast<VaccinAntigripal *>(i.first));
            (this->vac).insert(pair<VaccinAntigripal *, int>(cop, i.second));
        }
        if (dynamic_cast<VaccinAntihepatic *>(i.first)) {
            VaccinAntihepatic *cop = new VaccinAntihepatic(*dynamic_cast<VaccinAntihepatic *>(i.first));
            (this->vac).insert(pair<VaccinAntihepatic *, int>(cop, i.second));
        }
        if (dynamic_cast<VaccinAntiSarsCov2 *>(i.first)) {
            VaccinAntiSarsCov2 *cop = new VaccinAntiSarsCov2(*dynamic_cast<VaccinAntiSarsCov2 *>(i.first));
            (this->vac).insert(pair<VaccinAntiSarsCov2 *, int>(cop, i.second));
        }
    }
}

Comanda::Comanda() : id(++idstatic), date(""), numeClient("") {}



Comanda::Comanda(const string &date, const string &numeClient, string tipvaccin, int cantitate) : id(++idstatic),
                                                                                                  date(date),
                                                                                                  numeClient(
                                                                                                          numeClient) {
    try {
        if (tipvaccin == "Antigripal") {
            VaccinAntigripal *cop = new VaccinAntigripal();
            vac.insert(pair<VaccinAntigripal *, int>(cop, cantitate));
        } else if (tipvaccin == "Antihepatic") {
            VaccinAntihepatic *cop = new VaccinAntihepatic();
            vac.insert(pair<VaccinAntihepatic *, int>(cop, cantitate));
        } else if (tipvaccin == "AntiSarsCov2") {
            VaccinAntiSarsCov2 *cop = new VaccinAntiSarsCov2();
            vac.insert(pair<VaccinAntiSarsCov2 *, int>(cop, cantitate));
        } else throw tipvaccin;
    }
    catch (string t) {
        cout << "Vaccin gresit! Vaccinul selectat a fost: " << t << '\n';
    }
}

Comanda::Comanda(const Comanda &var) : id(var.id), date(var.date), numeClient(var.numeClient) {
    for (auto &i: var.vac) {
        if (dynamic_cast<VaccinAntigripal *>(i.first)) {
            VaccinAntigripal *cop = new VaccinAntigripal(*dynamic_cast<VaccinAntigripal *>(i.first));
            (this->vac).insert(pair<VaccinAntigripal *, int>(cop, i.second));
        }
        if (dynamic_cast<VaccinAntihepatic *>(i.first)) {
            VaccinAntihepatic *cop = new VaccinAntihepatic(*dynamic_cast<VaccinAntihepatic *>(i.first));
            (this->vac).insert(pair<VaccinAntihepatic *, int>(cop, i.second));
        }
        if (dynamic_cast<VaccinAntiSarsCov2 *>(i.first)) {
            VaccinAntiSarsCov2 *cop = new VaccinAntiSarsCov2(*dynamic_cast<VaccinAntiSarsCov2 *>(i.first));
            (this->vac).insert(pair<VaccinAntiSarsCov2 *, int>(cop, i.second));
        }
    }
}

Comanda::~Comanda() {
    for (auto &i: vac) {
        delete (i.first);
    }
}

ostream &operator<<(ostream &os, const Comanda &comanda) {
    os << "id: " << comanda.id << " date: " << comanda.date << " numeClient: " << comanda.numeClient << " Vaccinuri ";
    for (auto &i: comanda.vac) {
        os << *(i.first) << " Cantitate:" << i.second << '\n';
    }
    return os;
}

istream &operator>>(istream &is, Comanda &comanda) {
    cout << " date: ";
    is >> comanda.date;
    cout << " numeClient: ";
    is >> comanda.numeClient;
    cout << " Cate vaccinuri? ";
    int n;
    is >> n;
    string subst;
    int cant;
    is.get();
    for (int i = 0; i < n; ++i) {
        cout << "Vaccinul #" << i + 1 << ":\n";
        cout << " Tipul vaccinului: ";
        is >> subst;
        try {
            if (subst == "Antigripal") {
                VaccinAntigripal *cop = new VaccinAntigripal();
                is >> *cop;
                cout<<"Cantitatea: ";
                is >> cant;
                is.get();
                comanda.vac.insert(pair<VaccinAntigripal *, int>(cop, cant));
            } else if (subst == "Antihepatic") {
                VaccinAntihepatic *cop = new VaccinAntihepatic();
                is >> *cop;
                cout<<"Cantitatea: ";
                is >> cant;
                is.get();
                comanda.vac.insert(pair<VaccinAntihepatic *, int>(cop, cant));
            } else if (subst == "AntiSarsCov2") {
                VaccinAntiSarsCov2 *cop = new VaccinAntiSarsCov2();
                is >> *cop;
                cout<<"Cantitatea: ";
                is >> cant;
                is.get();
                comanda.vac.insert(pair<VaccinAntiSarsCov2 *, int>(cop, cant));
            } else throw subst;
        }
        catch (string t) {
            cout << "Vaccin gresit! Vaccinul selectat a fost: " << t << '\n';
        }
    }
//    is.get();
    return is;
}

unsigned int Comanda::getIdstatic() {
    return idstatic;
}

void Comanda::setIdstatic(unsigned int idstatic) {
    Comanda::idstatic = idstatic;
}

unsigned int Comanda::getId() const {
    return id;
}

const string &Comanda::getDate() const {
    return date;
}

void Comanda::setDate(const string &date) {
    Comanda::date = date;
}

const string &Comanda::getNumeClient() const {
    return numeClient;
}

void Comanda::setNumeClient(const string &numeClient) {
    Comanda::numeClient = numeClient;
}

const map<Vaccin *, int> &Comanda::getVac() const {
    return vac;
}

void Comanda::setVac(const map<Vaccin *, int> &vac) {
    Comanda::vac = vac;
}

double Comanda::valtot() const{
    double su=0;
    for (auto &i:vac) {
        su+=(i.first->getPrice())*i.second;
    }
    return su;
}
class ListaComenzi {
    vector<Comanda> comenzi;
public:
    ListaComenzi(const vector<Comanda> &comenzi);

    ListaComenzi();

    const vector<Comanda> &getComenzi() const;

    void setComenzi(const vector<Comanda> &comenzi);

    virtual ~ListaComenzi();

    ListaComenzi& operator+(Comanda &com);

    Comanda& operator[](int in);
};
ListaComenzi::ListaComenzi(const vector<Comanda> &comenzi) : comenzi(comenzi) {}

ListaComenzi::ListaComenzi() {}

const vector<Comanda> &ListaComenzi::getComenzi() const {
    return comenzi;
}

void ListaComenzi::setComenzi(const vector<Comanda> &comenzi) {
    ListaComenzi::comenzi = comenzi;
}

ListaComenzi::~ListaComenzi() {
    comenzi.clear();
}

ListaComenzi &ListaComenzi::operator+(Comanda &com1) {
    this->comenzi.push_back(com1);
    return *this;
}

Comanda &ListaComenzi::operator[](int in) {
    return comenzi[in];
}
class Meniu {
    vector<Vaccin*> catalogvacin;
    ListaComenzi comenzi;
    Meniu();
public:
    static Meniu& getInstance();
    void afisaremeniu();

    void adaugvaccin();

    void afisezvaccinuri();

    void afisezproducatori();

    void adaugcomanda();

    void afisezcomenzi();

    void afisezcomenziZi();

    void afisezschema();

    void exportfisier();
};
Meniu::Meniu() {}

Meniu &Meniu::getInstance() {
    static Meniu instance;
    return instance;
}

void Meniu::afisaremeniu() {
    while (true) {
        cout << "1. Adaugarea unui vaccin nou" << endl;
        cout << "2. Afisarea tuturor vaccinurilor detinute" << endl;
        cout << "3. Numele producatorilor pentru toate vaccinurile" << endl;
        cout << "4. Adaugarea unei comenzi" << endl;
        cout << "5. Afisarea tuturor comenzilor" << endl;
        cout << "6. Afisarea tuturor comenzilor dintr-o anumita zi" << endl;
        cout << "7. Afisarea schemei de vaccinare pentru un anumit tip de vaccin" << endl;
        cout << "8. Exportul comenzilor in fisier" << endl;
        cout << "9. Iesire" << endl;
        cout << "Introduce optiunea: ";
        int optiune;
        cin >> optiune;
        switch (optiune) {
            case 1:
                adaugvaccin();
                break;
            case 2:
                afisezvaccinuri();
                break;
            case 3:
                afisezproducatori();
                break;
            case 4:
                adaugcomanda();
                break;
            case 5:
                afisezcomenzi();
                break;
            case 6:
                afisezcomenziZi();
                break;
            case 7:
                afisezschema();
                break;
            case 8:
                exportfisier();
                break;
            case 9:
                return;
            default:
                cout << "Optiune inexistenta\n";
        }
    }
}

void Meniu::adaugvaccin() {
    cout << "Introduceti tip vaccin (Antigripal,Antihepatic,AntiSarsCov2):";
    string st;
    cin >> st;
    try {
        if (st == "Antigripal") {
            VaccinAntigripal *v = new VaccinAntigripal;
            cin >> *v;
            catalogvacin.push_back(v);
        } else if (st == "Antihepatic") {
            VaccinAntihepatic *v = new VaccinAntihepatic;
            cin >> *v;
            catalogvacin.push_back(v);
        } else if (st == "AntiSarsCov2") {
            VaccinAntiSarsCov2 *v = new VaccinAntiSarsCov2;
            cin >> *v;
            catalogvacin.push_back(v);
        } else throw st;
    }
    catch (string s) {
        cout << "Vaccin inexistent! Vaccinul introdus a fost: " << s;
    }
}

void Meniu::afisezvaccinuri() {
    short j = 0;
    for (auto &i: catalogvacin) {
        cout << "Vaccinul # " << ++j << '\n';
        cout << *i << '\n';
    }
}

void Meniu::afisezproducatori() {
    short j = 0;
    for (auto &i: catalogvacin) {
        cout << "Producatorul # " << ++j << '\n';
        cout << i->getNumeproducator() << '\n';
    }
}

void Meniu::adaugcomanda() {
    Comanda com;
    cin >> com;
    comenzi = comenzi + com;
}

void Meniu::afisezcomenzi() {
    short j = 0;
    for (auto &i: comenzi.getComenzi()) {
        cout << "Comanda # " << ++j << '\n';
        cout << i << '\n';
    }
}

void Meniu::afisezcomenziZi() {
    cout << " Introduceti data in acelasi format ca la adaugare:\n";
    string st;
    int su = 0;
    cin >> st;
    for (auto &i: comenzi.getComenzi()) {
        if (st == i.getDate())
            su += i.valtot();
    }
    cout << "Valoarea comenzilor din ziua " << st << " este: " << su << '\n';
}

void Meniu::afisezschema() {
    cout << "Introduceti indice vaccin:";
    short ind;
    cin >> ind;
    try {
        if (ind < 0||ind>=catalogvacin.size()) throw ind;
    }
    catch (short i ) {
        cout << "Indice gresit! Acesta a fost: " << i << '\n';
    }
    catalogvacin[ind]->afisareSchemaVaccinare();
}

void Meniu::exportfisier() {
    ofstream fo("export.txt");
    for (auto &i: comenzi.getComenzi()) {
        fo << i << '\n';
    }
    fo.close();
}






