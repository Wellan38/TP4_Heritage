/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Intersection> (fichier Intersection.h) ------
#if ! defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Forme.h"
#include <vector>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Intersection>
//
//
//------------------------------------------------------------------------ 

class Intersection : public Forme
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
	virtual Intersection* clone();
	virtual bool contient(int x, int y);
	virtual void sauver(std::string nomfic);
	void changerNom();

//-------------------------------------------- Constructeurs - destructeur
	Intersection ( const Intersection & unIntersection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Intersection (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Forme*> lesFormes );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Intersection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Attributs privés
std::vector<Forme*> formes;

};

//----------------------------------------- Types dépendants de <PolygoneConvexe>

#endif  // INTERSECTION_H
