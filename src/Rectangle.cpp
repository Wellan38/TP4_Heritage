/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Rectangle::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
void  Rectangle::deplacer(int dx,int dy)
{
	pointA.deplacer(dx,dy);
	pointB.deplacer(dx,dy);
}
void Rectangle::afficher()
{

	cout<<"R ";
	Forme::afficher();
	pointA.afficherPoint();
	pointB.afficherPoint();
	cout<<endl;
}

 Rectangle* Rectangle::clone()
{
	return new Rectangle (*this);
}

bool Rectangle::contient(int x, int y)
{
	if (x >= pointA.getX() && x <= pointB.getX() && y >= pointB.getY() && y <= pointA.getY())
 	{
 		return true;
 	}
 	else
 	{
 		return false;
	}
}

//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ):Forme::Forme(unRectangle.nom,unRectangle.sauvegarde,unRectangle.type),pointA(unRectangle.pointA),pointB(unRectangle.pointB)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,Point unPointA,Point unPointB ): Forme(unNom,uneSauvegarde, unType),pointA(unPointA),pointB(unPointB)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
