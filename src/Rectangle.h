/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Forme.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
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
//------------------------------------------------------- Attributs privés

    Point pointA;
    Point pointB;
};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H
