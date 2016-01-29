/*************************************************************************
                           Ardoise  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Interface de la classe <Ardoise> (fichier Ardoise.h) ------
#if ! defined ( ARDOISE_H )
#define ARDOISE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Forme.h"
#include <vector>
#include <string>
#include <fstream>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Ardoise>
//
//
//------------------------------------------------------------------------ 

class Ardoise
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	 void ajouter(Forme* f, bool load);
	 void supprimer(Forme* f);
	 void afficher() const;
	 void enumerer() const;
	 void vider();
	 void sauvegarder(std::string nomFichier) const;
	 Forme* rechercheParNom(const std::string& nom);
	 std::string undo();
	 std::string redo();
	 void ajouterCommande(std::string commande);
	 void afficherCommandes();


//-------------------------------------------- Constructeurs - destructeur
    Ardoise ( const Ardoise & unArdoise );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ardoise ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ardoise ( );
	const std::vector<Forme*>& getFormes() const;
	void setFormes(const std::vector<Forme*>& formes);

    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

private:
//------------------------------------------------------- Attributs priv�s
std::vector<Forme*> formes;

std::vector<std::string> commandes;
std::vector<std::string> commandesAnnulees;

//--------------------------------------------------------Méthodes privées

};

//----------------------------------------- Types d�pendants de <Ardoise>

#endif // ARDOISE_H
