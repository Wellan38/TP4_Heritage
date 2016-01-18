/*************************************************************************
                           Forme  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- R�alisation de la classe <Forme> (fichier Forme.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Forme.h"




//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Forme::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
void Forme::afficher()
{
	cout<<this->nom<<" ";
	//cout<<this->sauvegarde<<endl;
	//cout<<this->type<<endl;
}



//-------------------------------------------- Constructeurs - destructeur

Forme::Forme ( const Forme & unForme )
{
	this->nom=unForme.nom;
	this->sauvegarde=unForme.sauvegarde;
	this->type=unForme.type;

}
/*Forme::Forme (string unNom,string uneSauvegarde,typeForme unType )
// Algorithme :
//
{


} //----- Fin de Forme*/


Forme::~Forme ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Forme>" << endl;
#endif
} //----- Fin de ~Forme

const std::string& Forme::getNom() const {
	return nom;
}

void Forme::setNom(const std::string& nom) {
	this->nom = nom;
}

const std::string& Forme::getSauvegarde() const {
	return sauvegarde;
}

void Forme::setSauvegarde(const std::string& sauvegarde) {
	this->sauvegarde = sauvegarde;
}

typeForme Forme::getType() const {
	return type;
}

void Forme::setType(typeForme type) {
	this->type = type;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
