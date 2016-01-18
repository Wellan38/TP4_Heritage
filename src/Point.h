/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H


// Rôle de la classe <Point>
//Un point contient deux coordonnées entières
//On peut déplacer un point.
//On peut savoir si il est inclus dans une forme.
//------------------------------------------------------------------------ 

#include "Forme.h"

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void deplacer( int dx,int dy );
    // Mode d'emploi :
    //Ajoute dx à x et dy à y

    bool estInclus(Forme* f) const;
    //Permet de savoir si le point est contenu dans la Forme passée en paramètre

    void afficherPoint()const;


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    //Point();
    Point (int unX,int unY );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

    // Mode d'emploi :
    //
    // Contrat :
    //



private:
//------------------------------------------------------- Attributs privés
int x;
int y;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
