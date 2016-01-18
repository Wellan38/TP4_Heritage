/*************************************************************************
                           Segment  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- R�alisation de la classe <Segment> (fichier Segment.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
 void Segment::deplacer(int dx,int dy)
// Algorithme :

{
	 pointA.deplacer(dx,dy);
	 pointB.deplacer(dx,dy);
} //----- Fin de M�thode


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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
