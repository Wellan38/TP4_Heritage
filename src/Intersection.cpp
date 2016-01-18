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

//------------------------------------------------------ Include personnel
#include "Intersection.h"



//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type PolygoneConvexe::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


Intersection* Intersection::clone()
{
	return new Intersection (*this);
}
void Intersection::afficher()
{
	/*Forme::afficher();
	for(unsigned int i=0;i<formes.size();i++)
	{
		formes[i]->afficher();
	}*/
	cout<<"OI "<<this->nom;
		for(unsigned int i=0;i<formes.size();i++)
			{
				cout<<" "<<formes[i]->getNom();
			}
		cout<<endl;
}

void Intersection::deplacer(int dx,int dy)
{
	for(unsigned int i=0;i<formes.size();i++)
	{
		formes[i]->deplacer(dx,dy);
	}
}




//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection ):Forme::Forme(unIntersection.nom,unIntersection.sauvegarde,unIntersection.type),formes(unIntersection.formes)
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
    cout << "Appel au constructeur de <Union>" << endl;
#endif
} //----- Fin de Union


Intersection::~Intersection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- Fin de ~Intersection

