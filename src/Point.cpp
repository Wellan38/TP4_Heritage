/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques



void Point::deplacer( int dx,int dy )
{

	x+=dx;
	y+=dy;

}

bool Point::estInclus(Forme* f) const
{
	bool inclus=false;
		return inclus;
}
//Point::Point(){}
void Point::afficherPoint() const
{
	cout<<x<<" "<<y<<" ";

}
//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme :
//
{
	x=unPoint.getX();
	y=unPoint.getY();

#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


Point::Point (int unX,int unY )
// Algorithme :
//
{
	x=unX;
	y=unY;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point

int Point::getX() const {
	return x;
}

void Point::setX(int x) {
	this->x = x;
}

int Point::getY() const {
	return y;
}

void Point::setY(int y) {
	this->y = y;
}
