/*************************************************************************
                           Ardoise  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- R�alisation de la classe <Ardoise> (fichier Ardoise.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ardoise.h"




//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Ardoise::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Ardoise::ajouter(Forme* f)
{


	bool unique=true;
	for(int i=0;i<formes.size();i++)
	{
		if(!((f->getNom()).compare(formes[i]->getNom())))
		{
			unique=false;
			break;
		}
	}
	if(unique)
	{
		formes.push_back(f);
	}
	else
	{
		cout<<"Une forme du m�me nom existe d�j�"<<endl;
	}
}

void Ardoise::vider()
{
	for(int i=0;i<formes.size();i++)
	{
		delete formes[i];
	}
	formes.clear();
}
void Ardoise::supprimer(Forme* f)
{
	int i=0;
	while((f->getNom().compare(formes[i]->getNom())))
	{
		i++;
	}
	delete formes[i];
	formes.erase(formes.begin()+i);
}

void Ardoise::afficher() const//---------------------------------------------------------
{
	if(!formes.empty())
	{
		for(int i=0;i<formes.size();i++)
		{
			formes[i]->afficher();
		}
	}
	else
	{
		cout<<"L'ardoise est vide"<<endl;
	}

}
void Ardoise::enumerer() const
{
	if(!formes.empty())
		{
			for(int i=0;i<formes.size();i++)
			{
				cout<<"forme n�"<<i<<" "<<formes[i]->getSauvegarde()<<endl;
			}
		}
		else
		{
			cout<<"L'ardoise est vide"<<endl;
		}
}
void Ardoise::sauvegarder(string nomFichier) const
{

     ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);  //d�claration du flux et ouverture du fichier

        if(fichier)  // si l'ouverture a r�ussi
        {
            // instructions
        		for(int i=0;i<formes.size();i++)
        		{
        			fichier<<formes[i]->getSauvegarde()<<endl;
        		}
                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur � l'ouverture !" << endl;






}

Forme* Ardoise::rechercheParNom(const string& nom)
{
	if(!formes.empty())
	{
		int i=0;
		while((i<formes.size())&&(nom.compare(formes[i]->getNom())!=0))
		{
			i++;
		}
		if(i<formes.size())
		{
		   return formes[i];
		}

		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

std::string Ardoise::undo()
{
	if (!commandes.empty())
	{
		std::string com = *commandes.begin();
		commandes.erase(commandes.begin());
		commandesAnnulees.insert(commandesAnnulees.begin(), com);

		return com;
	}
	else
	{
		return "";
	}
}

std::string Ardoise::redo()
{
	if (!commandesAnnulees.empty())
	{
		std::string com = *commandesAnnulees.begin();
		commandesAnnulees.erase(commandesAnnulees.begin());
		commandes.insert(commandes.begin(), com);

		return com;
	}
	else
	{
		return "";
	}
}

//-------------------------------------------- Constructeurs - destructeur
Ardoise::Ardoise ( const Ardoise & unArdoise )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ardoise>" << endl;
#endif
} //----- Fin de Ardoise (constructeur de copie)


Ardoise::Ardoise ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ardoise>" << endl;
#endif
} //----- Fin de Ardoise


Ardoise::~Ardoise ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ardoise>" << endl;
#endif
} //----- Fin de ~Ardoise


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
