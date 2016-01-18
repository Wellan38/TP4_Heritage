/*************************************************************************
                           Ardoise  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <Ardoise> (fichier Ardoise.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ardoise.h"




//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ardoise::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Ardoise::ajouter(Forme* f, bool load)
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

		if (!load)
		{
			ajouterCommande(f->getSauvegarde());
		}
	}
	else
	{
		cout<<"Une forme du même nom existe déjà"<<endl;
	}
}

void Ardoise::vider()
{
	//TODO Ajouter la sauvegarde du modèle actuel dans un fichier "SauvegardePourClear.txt"

	for(int i=0;i<formes.size();i++)
	{
		delete formes[i];
	}
	formes.clear();

	commandes.insert(commandes.begin(), "CLEAR");
}
void Ardoise::supprimer(Forme* f)
{
	int i=0;
	while((f->getNom().compare(formes[i]->getNom())))
	{
		i++;
	}

	ajouterCommande("DELETE " + formes[i]->getNom() + formes[i]->getSauvegarde());

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
				cout<<"forme n°"<<i<<" "<<formes[i]->getSauvegarde()<<endl;
			}
		}
		else
		{
			cout<<"L'ardoise est vide"<<endl;
		}
}
void Ardoise::sauvegarder(string nomFichier) const
{

     ofstream fichier(nomFichier.c_str(), ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

        if(fichier)  // si l'ouverture a réussi
        {
            // instructions
        		for(int i=0;i<formes.size();i++)
        		{
        			fichier<<formes[i]->getSauvegarde()<<endl;
        		}
                fichier.close();  // on referme le fichier
        }
        else  // sinon
                cerr << "Erreur à l'ouverture !" << endl;






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
		ajouterCommande(com);

		return com;
	}
	else
	{
		return "";
	}
}

void Ardoise::ajouterCommande (string commande)
{
	commandes.insert(commandes.begin(), commande);
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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
