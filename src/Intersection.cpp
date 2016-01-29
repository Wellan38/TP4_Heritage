/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <Intersection> (fichier Intersection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Intersection.h"



//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type PolygoneConvexe::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Intersection::changerNom()
{
	string tempo;

	for(int i=0;i<formes.size();i++)
	{

		tempo=formes[i]->getNom();
		formes[i]->setNom(nom+"_"+tempo);

	}
}


void Intersection::sauver(string nomfic)
{
	ofstream fichier(nomfic.c_str(), ios::out | ios::app);

	 if(fichier)  // si l'ouverture a réussi

	 {
		 // instructions
		 for(int i=0;i<formes.size();i++)
		 {
			 formes[i]->sauver(nomfic);
		 }
			 fichier<<"OI "<<nom;

		 for(int i=0;i<formes.size();i++)
		 {
			fichier<<" "<<formes[i]->getNom();
		 }

		 fichier<<endl;
		 fichier<<"DELETE";
		 for(int i=0;i<formes.size();i++)
		 {
			fichier<<" "<<formes[i]->getNom();
		 }

		fichier<<endl;
			 fichier.close();  // on referme le fichier
	 }
	 else  // sinon
			 cerr << "Erreur à l'ouverture !" << endl;
}
Intersection* Intersection::clone()
{
	return new Intersection (*this);
}
void Intersection::afficher()
{

	cout<<formes.size()<<endl;
	cout<<"OI "<<this->nom;
		for(unsigned int i=0;i<formes.size();i++)
			{
				cout<<" "<<formes[i]->getNom();
			}
		cout<<endl;
		for(unsigned int i=0;i<formes.size();i++)
				{
					formes[i]->afficher();
				}
}

void Intersection::deplacer(int dx,int dy)
{
	for(unsigned int i=0;i<formes.size();i++)
	{
		formes[i]->deplacer(dx,dy);
	}
}

bool Intersection::contient(int x, int y)
{
	if (formes.size() == 0)
	{
		return false;
	}

	for (vector<Forme*>::iterator it = formes.begin(); it != formes.end(); it++)
	{
		if (!((*it)->contient(x, y)))
		{
			return false;
		}
	}

	return true;
}


//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection ):Forme::Forme(unIntersection.nom,unIntersection.sauvegarde,unIntersection.type)
// Algorithme :
//
{
	for(int i=0;i<unIntersection.formes.size();i++)
			{
				formes.push_back(unIntersection.formes[i]->clone());
			}
#ifdef MAP
    cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- Fin de Intersection (constructeur de copie)


Intersection::Intersection ( const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Forme*> lesFormes): Forme(unNom,uneSauvegarde, unType)
// Algorithme :
//
{
	for(int i=0;i<lesFormes.size();i++)
		{
			formes.push_back(lesFormes[i]->clone());
		}
#ifdef MAP
    cout << "Appel au constructeur de <Intersection>" << endl;
#endif
} //----- Fin de Intersection


Intersection::~Intersection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- Fin de ~Intersection

