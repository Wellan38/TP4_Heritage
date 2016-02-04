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

		/*if (!load)
		{
			ajouterCommande(f->getSauvegarde());
		}*/
	}
	else
	{
		cout<<"# Une forme du m�me nom existe d�j�"<<endl;
	}

}

void Ardoise::vider()
{


	while (!formes.empty())
	{
		delete formes[0];

		formes.erase(formes.begin());
	}

	commandes.insert(commandes.begin(), "CLEAR");
}

void Ardoise::supprimer(Forme* f)
{
	int i=0;
	while(f->getNom().compare(formes[i]->getNom()) != 0)
	{
		i++;
	}

	//ajouterCommande("DELETE " + formes[i]->getNom() + " " + formes[i]->getSauvegarde());

	//delete formes[i]; 02/02
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
		cout<<"# L'ardoise est vide"<<endl;
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
			cout<<"# L'ardoise est vide"<<endl;
		}
}
void Ardoise::sauvegarder(string nomFichier) const
{

	for(int i=0;i<formes.size();i++)
	{
		formes[i]->sauver(nomFichier);
	}






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
			//cout << "# Forme trouvee" << endl;
			return formes[i];
		}

		else
		{
			//cout << "# Forme non trouvee" << endl;
			return NULL;
		}
	}
	else
	{
		//cout << "Liste vide" << endl;
		return NULL;
	}
}

std::string Ardoise::undo()
{
	if (!commandes.empty())
	{
		std::string com = *commandes.begin();
		commandes.erase(commandes.begin());
		commandesAnnulees= com;

		return com;
	}
	else
	{
		return "";
	}
}

std::string Ardoise::redo()
{
	if (commandesAnnulees.compare("")!=0)
	{
		std::string com = commandesAnnulees;
		commandesAnnulees="";
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
//----------02/02-------------------
void Ardoise::ajouterCommandeAnnulee (string commande)
{
	commandesAnnulees=commande;
}
//-----------------------------------
void Ardoise::afficherCommandes()
{
	for (vector<string>::iterator it = commandes.begin(); it != commandes.end(); it++)
	{
		cout << *it << endl;
	}
}

void Ardoise::afficherCommandesAnnulees()
{

		cout << this->commandesAnnulees << endl;

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
	commandesAnnulees="";
#ifdef MAP
    cout << "Appel au constructeur de <Ardoise>" << endl;
#endif
} //----- Fin de Ardoise


Ardoise::~Ardoise ( )
// Algorithme :
//
{
	while (!formes.empty())
	{
		formes.erase(formes.begin());
	}

#ifdef MAP
    cout << "Appel au destructeur de <Ardoise>" << endl;
#endif
} //----- Fin de ~Ardoise

const std::vector<Forme*>& Ardoise::getFormes() const {
	return formes;
}

void Ardoise::setFormes(const std::vector<Forme*>& formes) {
	this->formes = formes;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
