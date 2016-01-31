/*************************************************************************
                           PolygoneConvexe  -  description
                             -------------------
    début                : 12 janv. 2016
    copyright            : (C) 2016 par Laurent
*************************************************************************/

//---------- Réalisation de la classe <PolygoneConvexe> (fichier PolygoneConvexe.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "PolygoneConvexe.h"



//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type PolygoneConvexe::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void PolygoneConvexe::afficher()
{
	cout<<"PC ";
	Forme::afficher();
	for(unsigned int i=0;i<points.size();i++)
	{
		points[i].afficherPoint();
	}
	cout<<endl;
}
void PolygoneConvexe::sauver(string nomfic)
{
	ofstream fichier(nomfic.c_str(), ios::out | ios::app);

	 if(fichier)  // si l'ouverture a réussi

	 {
		 // instructions
			 fichier<<"PC "<<nom;
			 for(unsigned int i=0;i<points.size();i++)
			 	{
			 		fichier<<" "<<points[i].getX()<<" "<<points[i].getY();
			 	}
			 fichier<<endl;
			 fichier.close();  // on referme le fichier
	 }
	 else  // sinon
			 cerr << "Erreur à l'ouverture !" << endl;
}
void PolygoneConvexe::deplacer(int dx,int dy)
{
	for(unsigned int i=0;i<points.size();i++)
	{
		points[i].deplacer(dx,dy);
	}
}
PolygoneConvexe* PolygoneConvexe::clone()
{

	    return new PolygoneConvexe (*this);

}

bool PolygoneConvexe::contient(int x, int y)
{

	float dPrec;
	float d;
	for(int i=0;i<points.size();i++)
	  {
	     Point A = points[i];

	     if (i==points.size()-1)
	     {// si c'est le dernier point, on relie au premier
	        Point B = points[0];
	        Point VectA(B.getX() - A.getX(),B.getY() - A.getY());
	        Point VectB(x - A.getX(),y - A.getY());

	        if(i==0)
	        {
	        	dPrec=VectA.getX()*VectB.getY() - VectA.getY()*VectB.getX();
	        }
	        else
	        {
	        	dPrec=d;
	        }

	        d = VectA.getX()*VectB.getY() - VectA.getY()*VectB.getX();
	     }
	     else
	     {// sinon on relie au suivant.
	        Point B = points[i+1];
	        Point VectA(B.getX() - A.getX(),B.getY() - A.getY());
	        Point VectB(x - A.getX(),y - A.getY());

	        if(i==0)
			{
				dPrec=VectA.getX()*VectB.getY() - VectA.getY()*VectB.getX();
			}
			else
			{
				dPrec=d;
			}
	        d = VectA.getX()*VectB.getY() - VectA.getY()*VectB.getX();
	     }

	     if (d*dPrec<0)
	        return false;  // un point à gauche et on arrête tout.
	  }
	  return true;  // si on sort du for, c'est qu'aucun point n'est à droite, donc c'est bon.


}


//-------------------------------------------- Constructeurs - destructeur
PolygoneConvexe::PolygoneConvexe ( const PolygoneConvexe & unPolygoneConvexe ):Forme::Forme(unPolygoneConvexe.nom,unPolygoneConvexe.sauvegarde,unPolygoneConvexe.type),points(unPolygoneConvexe.points)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de PolygoneConvexe (constructeur de copie)


PolygoneConvexe::PolygoneConvexe ( const std::string& unNom,const std::string& uneSauvegarde,typeForme unType,std::vector<Point> lesPoints): Forme(unNom,uneSauvegarde, unType)
// Algorithme :
//
{
	points=lesPoints;
#ifdef MAP
    cout << "Appel au constructeur de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de PolygoneConvexe


PolygoneConvexe::~PolygoneConvexe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PolygoneConvexe>" << endl;
#endif
} //----- Fin de ~PolygoneConvexe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
