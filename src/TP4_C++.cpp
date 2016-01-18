//============================================================================
// Name        : TP4_C++.cpp
// Author      : lolo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;


#include "Forme.h"
#include "PolygoneConvexe.h"
#include "Segment.h"
#include"Point.h"
#include "Rectangle.h"
#include "Union.h"
#include "Intersection.h"
#include "Ardoise.h"


int Split(vector<string>& vecteur, string chaine, char separateur);
int stringToInt(string s);
bool estConvexe(const vector<Point> &lesPoints);
bool nbPairCoordonnees(int debut,int fin);

int main()
{

	Ardoise lArdoise;
	string commande;
	vector<string> result;

	do
	{
		cout<<"rentrez la commande"<<endl;
		getline( cin, commande );
		Split(result, commande,' ');

//---------------------------------------------------------------Segment---------------------------
		if(result[0].compare("S")==0)
		{

			if(lArdoise.rechercheParNom(result[1])==NULL)//--------Si le nom n'existe pas déjà
			{
				if(result.size()!=6)//--------------- Si il n'y a pas au moins 6 arguments dans la commande
				{
					cout<<"ERR"<<endl;
				}

				else
				{
				Point a(stringToInt(result[2]),stringToInt(result[3]));
				Point b(stringToInt(result[4]),stringToInt(result[5]));
				lArdoise.ajouter(new Segment(result[1],commande,segm,a,b));
				cout<<"OK"<<endl;

				}
			}

			else
			{
				cout<<"ERR"<<endl;
			}

		}
//----------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------Rectangle------------------------------------------
		else if(result[0].compare("R")==0)
		{

			if(lArdoise.rechercheParNom(result[1])==NULL)//--------Si le nom n'existe pas déjà
			{


				//-------------Si il n'y a pas assez d'arguments--------------------
					if(result.size()!=6)
					{
						cout<<"ERR"<<endl;
					}
                //--------------------------------------------------------------------
					else
					{
						//------------Si le premier point n'est pas celui en haut à gauche -------------------------------
						if((stringToInt(result[5])>=stringToInt(result[3]))|| (stringToInt(result[2])>=stringToInt(result[4])))

						{
							cout<<"ERR"<<endl;
						}
						//-----------------------------------------------------------------------------------------------------
						else
						{
						Point c(stringToInt(result[2]),stringToInt(result[3]));
						Point d(stringToInt(result[4]),stringToInt(result[5]));
						lArdoise.ajouter(new Rectangle(result[1],commande,rect,c,d));
						cout<<"OK"<<endl;
						}
					}
			}
			else
			{
				cout<<"ERR"<<endl;
			}
		}
//----------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------Polygone convexe-------------------------------------------



		else if(result[0].compare("PC")==0)
		{

			if(lArdoise.rechercheParNom(result[1])==NULL)//--------Si le nom n'existe pas déjà
			{
				if(result.size()<8)//---------si il n'y a pas assez d'arguments--------------
				{
					cout<<"ERR"<<endl;
				}
				else if(!nbPairCoordonnees(2,result.size()))//--------------si le nombre de coordonnées de ppints n'est pas pair
				{
					cout<<"ERR"<<endl;

				}
				else
				{
					//--------------------ajout des points dans un vecteur de points----------------
					vector<Point> lesPoints;
					for(int i=2;i<result.size();i+=2)
					{

						lesPoints.push_back(Point(  stringToInt(result[i])   ,stringToInt(result[i+1])  ));
					}

					//-----------------------si le polygone est convexe-----------------------

					if(estConvexe(lesPoints))
					{
						lArdoise.ajouter(new PolygoneConvexe(result[1],commande,poly,lesPoints));
						cout<<"OK"<<endl;

					}
					//------------------------------------------------------------------------------
					else
					{
						cout<<"message d'erreur"<<endl;
					}
				}
			}
			else
			{
				cout<<"ERR"<<endl;
			}

		}
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------Union-------------------------------------------
		else if(result[0].compare("OR")==0)
		{

			if(lArdoise.rechercheParNom(result[1])==NULL)//--------Si le nom n'existe pas déjà
			{



					if(result.size()<4)//--------------------si il n'y a pas assez d'arguments--------------
					{
						cout<<"ERR"<<endl;
					}

					//-----------------Si les noms n'existent pas-----------------------------
					else
					{

						bool nomsExistent=true;
						for(int i=2;i<result.size();i++)
						{
							if(lArdoise.rechercheParNom(result[i])==NULL)
							{
								nomsExistent=false;
							}
						}

						if(nomsExistent)
						{
							vector<Forme*> z;
							for(int i=2;i<result.size();i++)
							{
							  z.push_back(lArdoise.rechercheParNom(result[i]));

							}
							lArdoise.ajouter(new Union(result[1],commande,uni,z));
							cout<<"OK"<<endl;
							lArdoise.afficher();
						}

						//-------------------------------------------------------------------------
						else
						{
							cout<<"ERR"<<endl;
						}
					}
			}

			else
			{
				cout<<"ERR"<<endl;
			}


		}
//--------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------Intersection----------------------------------------
		else if(result[0].compare("OI")==0)
		{

			if(lArdoise.rechercheParNom(result[1])==NULL)//--------Si le nom n'existe pas déjà
			{
					if(result.size()<4)//---------------si il n'y a pas assez d'arguments--------------
					{
						cout<<"ERR"<<endl;
					}
					//-----------------------si les noms n'existent pas dans la liste------------------
					else
					{
						bool nomsExistent=true;
						for(int i=2;i<result.size();i++)
						{
							if(lArdoise.rechercheParNom(result[i])==NULL)
							{
								nomsExistent=false;
							}
						}

						if(nomsExistent)
						{
							vector<Forme*> z;
							for(int i=2;i<result.size();i++)
							{
								 z.push_back(lArdoise.rechercheParNom(result[i]));

							}
							lArdoise.ajouter(new Intersection(result[1],commande,inter,z));
							cout<<"OK"<<endl;
						}
						//-------------------------------------------------------------------------------------------
						else
						{
							cout<<"ERR"<<endl;
						}
					}
			}
			else
			{
				cout<<"ERR"<<endl;
			}


		}
//------------------------------------------------------------------------------------------------------------------------------------
		else if(result[0].compare("HIT")==0)
		{
			if (result.size() != 4)
			{
				cout << "ERR" << endl;
			}
			else
			{
				Forme* f = lArdoise.rechercheParNom(result[1]);

				if (f == NULL)
				{
					cout << "ERR" << endl;
				}
				else
				{
					if (f->contient(stringToInt(result[2]), stringToInt(result[3])))
					{
						cout << "YES" << endl;
					}
					else
					{
						cout << "NO" << endl;
					}
				}
			}
		}
//-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------Supprimer des formes---------------------------------------------------------------
		else if(result[0].compare("DELETE")==0)
		{

			//----------------------On verifie qu'il y ait suffisamment d'arguments-------------------------------------------------
			if(result.size()<2)
			{
				cout<<"ERR"<<endl;
			}
			else
			{
					//----------------On regarde si tous les noms existent------------------------------------------------------------------
					bool nomsExistent=true;
					for(int i=1;i<result.size();i++)
					{
						if(lArdoise.rechercheParNom(result[i])==NULL)
						{
							nomsExistent=false;
						}
					}
					//---------------------------------------------------------------------------------
					//----------------------------Supprimer les formes---------------------------------
					Forme* f;
					if(nomsExistent)
					{
						for(int i=1;i<result.size();i++)
						{
							f=lArdoise.rechercheParNom(result[i]);
							lArdoise.supprimer(f);
						}
					}
					//----------------------------------------------------------------------------------
					else
					{
						cout<<"ERR"<<endl;
					}
			}
		}
//--------------------------------------------------Deplacer les formes-------------------------------------------------
		else if(result[0].compare("MOVE")==0)
		{
			//----------------------On verifie qu'il y ait suffisamment d'arguments-------------------------------------------------
			if(result.size()!=4)
			{
				cout<<"ERR"<<endl;
			}
			else
			{

				Forme* f=lArdoise.rechercheParNom(result[1]);
				//---------------------------------------verifier que le nom existe------------
				if(f==NULL)
				{
					cout<<"ERR"<<endl;
				}
				else
				{
					f->deplacer(stringToInt(result[2]),stringToInt(result[3]));

				}
			}

		}

		else if(result[0].compare("LIST")==0)
		{
			lArdoise.afficher();
		}

		else if(result[0].compare("UNDO")==0)
		{
			string com = lArdoise.undo();

			if (com.compare("") == 0)
			{
				cout << "ERR" << endl;
			}
			else
			{
				vector<string> args;
				Split(args, com, ' ');

				if (args[0].compare("S") || args[0].compare("R") || args[0].compare("PC") || args[0].compare("OR") || args[0].compare("OI"))
				{
					Forme* f = lArdoise.rechercheParNom(args[1]);

					if (f != NULL)
					{
						lArdoise.supprimer(f);
					}
					else
					{
						cout << "ERR" << endl;
					}
				}
			}
		}

		else if(result[0].compare("REDO")==0)
		{

		}

		else if(result[0].compare("LOAD")==0)
		{
			string com = lArdoise.undo();

			if (com.compare(""))
			{
				cout << "ERR" << endl;
			}
			else
			{
				vector<string> args;
				Split(args, com, ' ');


			}
		}

		else if(result[0].compare("SAVE")==0)
		{

		}

		else if(result[0].compare("CLEAR")==0)
		{
			lArdoise.vider();
		}

		else
		{
			if(commande.compare("EXIT")!=0)
			{
				cout<<"ERR"<<endl;
			}
		}



	}while((commande.compare("EXIT"))!=0);

	lArdoise.vider();
	return 0;

}

bool estConvexe(const vector<Point> &lesPoints)
{
	bool cvexe=true;
	bool positif;
	bool changerSigne = true;

	for (int i = 0; i < lesPoints.size() - 2; i++)
	{
		int dx1 = lesPoints[i+1].getX() - lesPoints[i].getX();
		int dy1 = lesPoints[i+1].getY() - lesPoints[i].getY();
		int dx2 = lesPoints[i+2].getX() - lesPoints[i+1].getX();
		int dy2 = lesPoints[i+2].getY() - lesPoints[i+1].getY();

		int zcrossproduct = dx1*dy2 - dy1*dx2;

		if (changerSigne)
		{
			if (zcrossproduct > 0)
			{
				positif = true;
				changerSigne = false;
			}
			else if (zcrossproduct < 0)
			{
				positif = false;
				changerSigne = false;
			}
		}

		if ((zcrossproduct < 0 && positif) || (zcrossproduct > 0 && !positif))
		{
			cvexe = false;
			break;
		}
	}

	return cvexe;
}

bool nbPairCoordonnees(int debut,int fin)
{
	if((fin-debut)%2!=0)//--------------si le nombre de coordonnées de ppints n'est pas pair
	{
		return false;
	}
	else
	{
		return true;
	}
}

int stringToInt(string s)
{
	const char* c;
	c=s.c_str();
    return atoi(c);
}

int Split(vector<string>& vecteur, string chaine, char separateur)
{
	vecteur.clear();

	string::size_type stTemp = chaine.find(separateur);

	while(stTemp != string::npos)
	{
		vecteur.push_back(chaine.substr(0, stTemp));
		chaine = chaine.substr(stTemp + 1);
		stTemp = chaine.find(separateur);
	}

	vecteur.push_back(chaine);

	return vecteur.size();
}























/*Point p1(1,1);
Point p2(2,0);
Point p3(3,2);
Point p4(0,3);

vector<Point> p;
p.push_back(p1);
p.push_back(p2);
p.push_back(p3);
p.push_back(p4);

vector<Forme*> f;
Forme *a;
Forme* b;
Forme* c;

Segment s("s1","sauv1",segm,p1,p2);
Rectangle r("r1","sauv2",rect,p3,p4);
PolygoneConvexe pc("s1","sauv3",poly,p);


a=&s;
b=&r;
c=&pc;
Ardoise ad;
ad.ajouter(a);
ad.ajouter(b);
ad.ajouter(c);
ad.afficher();
//ad.sauvegarder("test");




/*s.afficher();
s.deplacer(1,1);
s.afficher();


r.afficher();
r.deplacer(1,1);
r.afficher();


pc.afficher();
pc.deplacer(1,1);
pc.afficher();

f.push_back(a);
f.push_back(b);
f.push_back(c);

Intersection i("i1","sauv1",uni,f);*/
