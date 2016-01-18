/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
 void Segment::deplacer(int dx,int dy)
// Algorithme :

{
	 pointA.deplacer(dx,dy);
	 pointB.deplacer(dx,dy);
} //----- Fin de Méthode


void Segment::afficher()
{

	cout<<"S ";
	Forme::afficher();
	pointA.afficherPoint();
	pointB.afficherPoint();
	cout<<endl;


}

Segment* Segment::clone()
{
	return new Segment (*this);
}

//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & unSegment ):Forme::Forme(unSegment.nom,unSegment.sauvegarde,unSegment.type),pointA(unSegment.pointA),pointB(unSegment.pointB)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- Fin de Segment (constructeur de copie)



// Algorithme :
Segment::Segment (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,Point unPointA,Point unPointB  ): Forme(unNom,uneSauvegarde, unType),pointA(unPointA),pointB(unPointB)
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif
} //----- Fin de Segment


Segment::~Segment ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Segment>" << endl;
#endif
} //----- Fin de ~Segment


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
