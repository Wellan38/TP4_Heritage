/*************************************************************************
                           Point  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H


// R�le de la classe <Point>
//Un point contient deux coordonn�es enti�res
//On peut d�placer un point.
//On peut savoir si il est inclus dans une forme.
//------------------------------------------------------------------------ 

#include "Forme.h"

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void deplacer( int dx,int dy );
    // Mode d'emploi :
    //Ajoute dx � x et dy � y

    bool estInclus(Forme* f) const;
    //Permet de savoir si le point est contenu dans la Forme pass�e en param�tre

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
//------------------------------------------------------- Attributs priv�s
int x;
int y;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Point>

#endif // POINT_H
