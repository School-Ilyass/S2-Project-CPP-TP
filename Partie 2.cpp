#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cpt = 1;

class Document
{
private:
    int id;
    float prix;
    string titre;
    int code;

public:
    Document(float prix, string titre, int code)
    {
        id = cpt;
        cpt++;
        this->prix = prix;
        this->titre = titre;
        this->code = code;
    }

    int getCode() { return code; }
    float getPrix() { return prix; }

    void afficher()
    {
        cout << id;
    }

    void reduirePrix(float pourcentage)
    {
        this->prix = prix - prix * pourcentage;
    }

    void operator==(Document &obj)
    {
        if (obj.getCode() == code)
        {
            cout << obj.getCode() << " Et " << code << " sont egaux !!" << endl;
        }
        else
        {
            cout << obj.getCode() << " Et " << code << " sont pas egaux !!" << endl;
        }
    }

    void operator<(Document &obj)
    {
        if (obj.getPrix() == prix)
        {
            cout << "Prix inferieur " << endl;
        }
        else
        {
            cout << "Prix Superieur " << endl;
        }
    }

    friend ostream &operator<<(ostream &out, const Document &obj);
};
ostream &operator<<(ostream &out, const Document &obj)
{
    out << "ID : " << obj.id << " ; Titre : " << obj.titre << " ; Code : " << obj.code << endl;
    return out;
}

class Auteur
{
private:
    string nom;

public:

    Auteur(string nom)
    {
        this->nom = nom;
    }

    string getNom() { return nom; }

    void afficher()
    {
        cout << nom << endl;
    }

    void operator==(Auteur &obj){
        if (obj.getNom() == nom)
        {
            cout << obj.getNom() << " et " << nom << " sont egaux !!" << endl;
        }
        else
        {
            cout << obj.getNom() << " et " << nom << " sont pas egaux !!" << endl;
        }
    }

    void operator<(Auteur &obj)
    {
        if (obj.getNom() == nom)
        {
            cout << "Nom inferieur" << endl;
        }
        else
        {
            cout << "Nom superieur" << endl;
        }
    }

    friend ostream &operator<<(ostream &out, const Auteur &obj);
};

ostream &operator<<(ostream &out, const Auteur &obj)
{
    out << "Nom : " << obj.nom;
    return out;
}

class Dictionnaire
{
private:
    string nom;
    string langue;
    int nbTome;

public:
    Dictionnaire(string nom, string langue, int nbTome)
    {
        this->nom = nom;
        this->langue = langue;
        this->nbTome = nbTome;
    }
};

class Livre
{
private:
    string nom;
    string langue;

public:
    Livre(string nom, string langue)
    {
        this->nom = nom;
        this->langue = langue;
    }



    friend ostream &operator<<(ostream &out, const Livre &obj);
};

ostream &operator<<(ostream &out, const Livre &obj)
{
    out << "Nom : " << obj.nom << " ; Langue : " << obj.langue  << endl;
    return out;
}


class Bibliotheque
{
private:
    string nom;
    vector<Dictionnaire> dictionnaires;
    vector<Livre> livres;

public:
    Bibliotheque(string nom)
    {
        this->nom = nom;
    }

    void Insert(const Dictionnaire &obj)
    {
        dictionnaires.push_back(obj);
    }

    void Insert(const Livre &obj)
    {
        livres.push_back(obj);
    }
};

int main()
{
    Auteur a1("John Doe");
    Auteur a2("Jane Smith");

    a1.afficher();
    a2.afficher();

    a1 == a2;
    a1 < a2;

    Dictionnaire dict("Le Dictionnaire", "Français", 2);
    Livre livre("Le Livre", "Anglais");

    Bibliotheque biblio("Ma Bibliotheque");
    biblio.Insert(dict);
    biblio.Insert(livre);

    return 0;
}