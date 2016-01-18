/*************************************************************************
                           Rectangle  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "Forme.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //



	virtual void  deplacer(int dx,int dy);
	virtual void afficher();
	virtual Rectangle* clone();
	virtual bool contient(int x, int y);

//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Rectangle (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,Point unPointA,Point unPointB  );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Rectangle ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Attributs priv�s

    Point pointA;
    Point pointB;
};

//----------------------------------------- Types d�pendants de <Rectangle>

#endif // RECTANGLE_H
