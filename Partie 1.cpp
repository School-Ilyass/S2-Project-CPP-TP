#include <iostream>
#include <string>
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

int main()
{

    Document D1(20.00, "Doc1", 0000);
    Document D2(20.00, "Doc1", 0001);

    D1.afficher();
    D2.afficher();

    D1 == D2;
    cout << D2;

    return 0;
}