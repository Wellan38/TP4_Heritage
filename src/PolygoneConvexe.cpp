/*************************************************************************
                           PolygoneConvexe  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <PolygoneConvexe> (fichier PolygoneConvexe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PolygoneConvexe.h"



//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type PolygoneConvexe::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void PolygoneConvexe::afficher()
{
	cout<<"PC ";
	Forme::afficher();
	for(unsigned int i=0;i<points.size();i++)
	{
		points[i].afficherPoint();
	}
	cout<<endl;
}

void PolygoneConvexe::deplacer(int dx,int dy)
{
	for(unsigned int i=0;i<points.size();i++)
	{
		points[i].deplacer(dx,dy);
	}
}
PolygoneConvexe* PolygoneConvexe::clone()
{

	    return new PolygoneConvexe (*this);

}

bool PolygoneConvexe::contient(int x, int y)
{
	return true;
}


//-------------------------------------------- Constructeurs - destructeur
PolygoneConvexe::PolygoneConvexe ( const PolygoneConvexe & unPolygoneConvexe ):Forme::Forme(unPolygoneConvexe.nom,unPolygoneConvexe.sauvegarde,unPolygoneConvexe.type),points(unPolygoneConvexe.points)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de PolygoneConvexe (constructeur de copie)


PolygoneConvexe::PolygoneConvexe ( const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Point> lesPoints): Forme(unNom,uneSauvegarde, unType)
// Algorithme :
//
{
	points=lesPoints;
#ifdef MAP
    cout << "Appel au constructeur de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de PolygoneConvexe


PolygoneConvexe::~PolygoneConvexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de ~PolygoneConvexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
