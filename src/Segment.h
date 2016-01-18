/*************************************************************************
                           Segment  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier Segment.h) ------
#if ! defined ( SEGMENT_H )
#define SEGMENT_H


#include <string>
#include <cmath>


//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "Forme.h"



//------------------------------------------------------------------------ 
// R�le de la classe <Segment>
//Represente un segment,herite de formeSimple
//
//------------------------------------------------------------------------ 

class Segment : public Forme

{

//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	virtual void  deplacer(int dx,int dy);
	virtual Segment* clone();
	virtual bool contient(int x, int y);
	void afficher();
//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Segment (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,Point unPointA,Point unPointB );

    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Segment ( );
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

//----------------------------------------- Types d�pendants de <Segment>

#endif // SEGMENT_H
