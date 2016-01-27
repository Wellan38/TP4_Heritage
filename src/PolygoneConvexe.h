/*************************************************************************
                           PolygoneConvexe  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <PolygoneConvexe> (fichier PolygoneConvexe.h) ------
#if ! defined ( POLYGONECONVEXE_H )
#define POLYGONECONVEXE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "Forme.h"
#include <vector>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <PolygoneConvexe>
//
//
//------------------------------------------------------------------------ 

class PolygoneConvexe : public Forme
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
	virtual PolygoneConvexe* clone();
	virtual bool contient(int x, int y);
	virtual void sauver(string nomfic);


//-------------------------------------------- Constructeurs - destructeur
    PolygoneConvexe ( const PolygoneConvexe & unPolygoneConvexe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PolygoneConvexe (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Point> lesPoints );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PolygoneConvexe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Attributs priv�s
std::vector<Point> points;

};

//----------------------------------------- Types d�pendants de <PolygoneConvexe>

#endif // POLYGONECONVEXE_H
