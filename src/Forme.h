/*************************************************************************
                           Forme  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Forme> (fichier Forme.h) ------
#if ! defined ( FORME_H )
#define FORME_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef enum {segm,rect,poly,uni,inter} typeForme;
//------------------------------------------------------------------------ 
// Rôle de la classe <Forme>
//Forme est une classe abstraite.
//Elle est la racine de toutes les formes geometriques
//Elle est la forme geometrique la plus generale
//------------------------------------------------------------------------ 

class Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	virtual void  deplacer(int dx,int dy)=0;
	virtual void afficher();
	virtual Forme* clone()=0;
	virtual bool contient(int x, int y)=0;

//-------------------------------------------- Constructeurs - destructeur
Forme ( const Forme & unForme );

Forme (const std::string& unNom,const std::string& uneSauvegarde,typeForme unType ):nom(unNom),sauvegarde(uneSauvegarde),type(unType)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Forme>" << endl;
	#endif
}
    virtual ~Forme ( );
	const std::string& getNom() const;
	void setNom(const std::string& nom);
	const std::string& getSauvegarde() const;
	void setSauvegarde(const std::string& sauvegarde);
	typeForme getType() const;
	void setType(typeForme type);

//------------------------------------------------------------------ PRIVE 
protected:
//------------------------------------------------------- Attributs privés
std::string nom;
std::string sauvegarde;
typeForme type;
};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
