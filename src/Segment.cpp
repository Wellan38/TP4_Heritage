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
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
 void Segment::sauver(string nomfic)
{
	  ofstream fichier(nomfic.c_str(), ios::out | ios::app);

	         if(fichier)  // si l'ouverture a réussi
	         {
	             // instructions
	         		 fichier<<"S "<<nom<<" "<<pointA.getX()<<" "<<pointA.getY()<<" "<<pointB.getX()<<" "<<pointB.getY()<<endl;
	                 fichier.close();  // on referme le fichier
	         }
	         else  // sinon
	                 cerr << "Erreur à l'ouverture !" << endl;


}
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

bool Segment::contient(int x, int y)
{
	// On commence par vérifier si tous les points sont alignés

	double coeffDirAB = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
	double coeffDirAC = (y - pointA.getY()) / (x - pointA.getX());

	double longueurAB = sqrt(pow(pointB.getY() - pointA.getY(), 2) + pow(pointB.getX() - pointA.getX(), 2));
	double longueurAC = sqrt(pow(y - pointA.getY(), 2) + pow(x - pointA.getX(), 2));

	if (abs(coeffDirAB) != abs(coeffDirAC))
	{
		return false; // Les points ne sont pas alignés, donc (x,y) n'appartient pas au segment
	}
	else if (coeffDirAB == - coeffDirAC)
	{
		return false;
	}
	else if (longueurAC > longueurAB)
	{
		return false; // (x,y) est sur la droite (AB), mais pas sur le segment
	}
	else
	{
		return true;
	}
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
