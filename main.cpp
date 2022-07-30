#include <iostream>

using namespace std;


//structura pentru vectorul cu comenzi
struct Comanda{

int comanda_id;
int client_id;
int status;
int zi_lansare;
};

//structura pentru tabelul de dispersie
struct Nod{

int comanda_id=0;
int client_id=0;
int status=-1;
int zi_lansare=0;
Nod* urm= nullptr;

};


//prim[] reprezinta capetele fiecarei cheie posibila din tabelul de dispersie
Nod * prim[30]={NULL};
//temp[] il folosim pentru a contrui listele in tabel pentru a evita coliziunile
Nod * temp[30]={NULL};





void adaugare_comenzi(Comanda comenzi[], int nr)
{
for(int i=0; i<nr; i++)
{
comenzi[i].comanda_id = i+1;
cout<<"Introduceti id-ul clientului: "<<endl;
cin>>comenzi[i].client_id;
cout<<"Introduceti statusul comenzii: (1)inregistrata, (2)in depozitul curierului, (3)lvirata"<<endl;
cin>>comenzi[i].status;
cout<<"Introduceti ziua: "<<endl;
cout<<"Ex: 1"<<endl;
cin>>comenzi[i].zi_lansare;
}


}
void afisare(Comanda comenzi[], int nr)
{
for(int i=0; i<nr; i++)
{
cout<<endl<<"====Detalii Comanda===="<<endl;
cout<<"Comanda id: "<<comenzi[i].comanda_id<<endl;
cout<<"Client id: "<<comenzi[i].client_id<<endl;



if(comenzi[i].status == 1)
{
cout<<"Statusul comenzii: inregistrata "<<endl;
}
else if(comenzi[i].status == 2)
{
cout<<"Statusul comenzii: in depozitul curierului "<<endl;
}
else if(comenzi[i].status == 3)
{
cout<<"Statusul comenzii: livrata "<<endl;
}
}
}



void tabel_dispersie(Comanda functie[], int nr)
{

for(int i=0;i<nr;i++)
{
if(prim[(functie[i].status+10)%7]==NULL)
{
    Nod*el=new Nod;
    el->client_id=functie[i].client_id;
    el->comanda_id=functie[i].comanda_id;
    el->status=functie[i].status;
    el->zi_lansare=functie[i].zi_lansare;
    el->urm=NULL;
    prim[(functie[i].status+10)%7]=el;
    temp[(functie[i].status+10)%7]=el;
}else
{
    Nod*el=new Nod;
    el->client_id=functie[i].client_id;
    el->comanda_id=functie[i].comanda_id;
    el->status=functie[i].status;
    el->zi_lansare=functie[i].zi_lansare;
    el->urm=NULL;
    temp[(functie[i].status+10)%7]->urm=el;
    temp[(functie[i].status+10)%7]=el;

}
}
}


void cautare()
{
int nr;
cout<<endl<<"Introduceti statusul comenzii pe care doriti sa-l cautati:\n[1-inregistrat, 2-in deopozitul curierului, 3-livrat]"<<endl;
cin>>nr;
Nod *key = prim[(nr + 10) % 7];
while(key != NULL)
{
cout<<endl<<"====Detalii Comanda===="<<endl;
cout<<"Comanda id: "<<key->comanda_id<<endl;
cout<<"Client id: "<<key->client_id<<endl;

if(key->status == 1)
{
cout<<"Statusul comenzii: inregistrata "<<endl;
}
else if(key->status == 2)
{
cout<<"Statusul comenzii: in depozitul curierului "<<endl;
}
else if(key->status == 3)
{
cout<<"Statusul comenzii: livrata "<<endl;
}
cout<<endl;
key = key->urm;
}


}



int main()
{
Comanda comenzi[30];
int nr;
cout<<"Cate comenzi doresti sa adaugi?"<<endl;
cin>>nr;
adaugare_comenzi(comenzi, nr);
afisare(comenzi, nr);
tabel_dispersie(comenzi, nr);
cout<<endl;
cautare();
//system("CLS");








return 0;
}
