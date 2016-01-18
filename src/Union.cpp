/*************************************************************************
                           Union  -  description
                             -------------------
    d�but                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- R�alisation de la classe <Union> (fichier Union.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Union.h"



//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- M�thodes publiques
// type PolygoneConvexe::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

Union* Union::clone()
{
	return new Union (*this);
}

void Union::afficher()
{
	/*Forme::afficher();
	for(unsigned int i=0;i<formes.size();i++)
	{
		formes[i]->afficher();
	}
	cout<<endl;*/

	cout<<"OR "<<this->nom;
	for(unsigned int i=0;i<formes.size();i++)
		{
			cout<<" "<<formes[i]->getNom();
		}
	cout<<endl;

}

void Union::deplacer(int dx,int dy)
{
	for(unsigned int i=0;i<formes.size();i++)
	{
		formes[i]->deplacer(dx,dy);
	}
}




//-------------------------------------------- Constructeurs - destructeur
Union::Union ( const Union & unUnion ):Forme::Forme(unUnion.nom,unUnion.sauvegarde,unUnion.type),formes(unUnion.formes)
// Algorithme :
//
{
	for(int i=0;i<unUnion.formes.size();i++)
		{
			formes.push_back(unUnion.formes[i]->clone());
		}
#ifdef MAP
    cout << "Appel au constructeur de copie de <Union>" << endl;
#endif
} //----- Fin de Union (constructeur de copie)


Union::Union ( const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Forme*> lesFormes): Forme(unNom,uneSauvegarde, unType)
// Algorithme :
//
{

	for(int i=0;i<lesFormes.size();i++)
	{
		formes.push_back(lesFormes[i]->clone());
	}
#ifdef MAP
    cout << "Appel au constructeur de <Union>" << endl;
#endif
} //----- Fin de Union


Union::~Union ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Union>" << endl;
#endif
} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
