/*************************************************************************
                           Union  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Union> (fichier Union.h) ------
#if ! defined ( UNION_H )
#define UNION_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "Forme.h"
#include <vector>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Union>
//
//
//------------------------------------------------------------------------ 

class Union : public Forme
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
	virtual Union* clone();
	virtual bool contient(int x, int y);
	virtual void sauver(string nomfic);
	void changerNom();
//-------------------------------------------- Constructeurs - destructeur
    Union ( const Union & unUnion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Union (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Forme*> lesFormes );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Union ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Attributs priv�s
std::vector<Forme*> formes;

};

//----------------------------------------- Types d�pendants de <PolygoneConvexe>

#endif  // UNION_H
