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
#include <fstream>
#include<sstream>
using namespace std;
//commit test

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
void ajouterForme(string commande,Ardoise& uneArdoise,bool Load,vector<Forme*>& undoDelete);
string itos(int i);
void viderVector(vector<Forme*>& vect);

bool derniereCommandeUndo=false;
int main()
{

	Ardoise lArdoise;
	string commande;
	vector<string> result;
	vector<Forme*> undoDelete;
	vector<Forme*> undoClear;
	vector<string> undoLoad;
	vector<Forme*> redoLoad;
	vector<string> redoClear;


	do
	{
		cout<<"rentrez la commande"<<endl;
		getline( cin, commande );
		Split(result, commande,' ');

		ajouterForme(commande,lArdoise,false,undoDelete);


		if(result[0].compare("HIT")==0)
		{
			if (result.size() != 4)
			{
				cout << "ERR" << endl;
				cout<<"# Nombre de parametres incorrect"<<endl;

			}
			else
			{
				Forme* f = lArdoise.rechercheParNom(result[1]);

				if (f == NULL)
				{
					cout << "ERR" << endl;
					cout<<"# La forme n'existe pas"<<endl;
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

//--------------------------------------------------Deplacer les formes-------------------------------------------------
		else if(result[0].compare("MOVE")==0)
		{
			//----------------------On verifie qu'il y ait suffisamment d'arguments-------------------------------------------------
			if(result.size()!=4)
			{
				cout<<"ERR"<<endl;
				cout<<"# Nombre de parametres incorrect"<<endl;
			}
			else
			{

				Forme* f=lArdoise.rechercheParNom(result[1]);
				//---------------------------------------verifier que le nom existe------------
				if(f==NULL)
				{
					cout<<"ERR"<<endl;
					cout<<"# La forme n'existe pas"<<endl;
				}
				else
				{
					f->deplacer(stringToInt(result[2]),stringToInt(result[3]));
					//lArdoise.ajouterCommande("MOVE " + result[1] + " " + result[2] + " " + result[3]);
					lArdoise.ajouterCommande(commande);//-----02/02
					derniereCommandeUndo=false;
					cout<<"OK"<<endl;
					cout<<"# Forme deplacee"<<endl;
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
				cout<<"# Pas de commande a annuler"<<endl;
			}
			else
			{
				vector<string> args;
				Split(args, com, ' ');

				if (args[0].compare("S") == 0 || args[0].compare("R") == 0 || args[0].compare("PC") == 0 || args[0].compare("OR") == 0 || args[0].compare("OI") == 0)
				{
					Forme* f = lArdoise.rechercheParNom(args[1]);

					if (f != NULL)
					{
						lArdoise.supprimer(f);
						derniereCommandeUndo=true;
						cout<<"OK"<<endl;
						cout<<"# Commande annulee"<<endl;



					}
					else
					{
						cout << "ERR" << endl;
					}
				}
				else if (args[0].compare("MOVE") == 0)
				{
					Forme* f=lArdoise.rechercheParNom(args[1]);

					//--------------------------------verifier que le nom existe------------
					if(f==NULL)
					{
						cout<<"ERR"<<endl;
					}
					else
					{
						f->afficher();
						f->deplacer(-(stringToInt(args[2])),-(stringToInt(args[3])));
						derniereCommandeUndo=true;
						cout<<"OK"<<endl;
						cout<<"# Commande annulee"<<endl;


					}
				}
				else if (args[0].compare("LOAD") == 0)
				{
					int nb=stringToInt(args[2]);
					redoLoad.clear();
					for(int i=0;i<nb;i++)
					{
						Forme*f=lArdoise.rechercheParNom(undoLoad[0]);
						redoLoad.insert(redoLoad.begin(),f);
						lArdoise.supprimer(f);
						undoLoad.erase(undoLoad.begin());
					}
					derniereCommandeUndo=true;
					cout<<"OK"<<endl;
					cout<<"# Commande annulee"<<endl;


				}

				else if (args[0].compare("CLEAR") == 0)
				{
					int nb=stringToInt(args[1]);
					redoClear.clear();
					for(int i=0;i<nb;i++)
					{
						lArdoise.ajouter(undoClear[0],false);
						redoClear.insert((redoClear.begin()),undoClear[0]->getNom());
						undoClear.erase(undoClear.begin());
					}
					derniereCommandeUndo=true;
					cout<<"OK"<<endl;
					cout<<"# Commande annulee"<<endl;


				}
				else if (args[0].compare("DELETE") == 0)
				{

					for(int i=1;i<args.size();i++)
					{
						lArdoise.ajouter(undoDelete[0],false);
						undoDelete.erase(undoDelete.begin());
					}

					derniereCommandeUndo=true;
					cout<<"OK"<<endl;
					cout<<"# Commande annulee"<<endl;

				}
			}
		}

		else if(result[0].compare("REDO")==0)
		{

			if(derniereCommandeUndo)
			{
					string com = lArdoise.redo();

					if (com.compare("") == 0)
					{
						cout << "ERR" << endl;
						cout<<"#Pas de commande annulee"<<endl;
					}
					else
					{
						vector<string> args;
						Split(args, com, ' ');

						if (args[0].compare("S") == 0 || args[0].compare("R") == 0 || args[0].compare("PC") == 0 || args[0].compare("OR") == 0 || args[0].compare("OI") == 0)
						{
							Forme* f = lArdoise.rechercheParNom(args[1]);

							if (f == NULL)
							{
								ajouterForme(com, lArdoise, true,undoDelete);
								cout<<"OK"<<endl;
								cout<<"# Commande retablie"<<endl;
							}
							else
							{
								cout << "ERR" << endl;
								cout << "# La forme " + f->getNom() + " existe deja." << endl;
							}
						}

						//---------------02/02
						else if (args[0].compare("DELETE") == 0)
						{
							ajouterForme(com,lArdoise,true,undoDelete);
							cout<<"OK"<<endl;
							cout<<"# Commande retablie"<<endl;

						}
		//-------------------------------------------------------------

						else if (args[0].compare("MOVE") == 0)
						{
							Forme* f=lArdoise.rechercheParNom(args[1]);
							//---------------------------------------verifier que le nom existe------------
							if(f==NULL)
							{
								cout<<"ERR"<<endl;
							}
							else
							{
								f->deplacer(stringToInt(args[2]),stringToInt(args[3]));
								cout<<"OK"<<endl;
								cout<<"# Commande retablie"<<endl;
							}
						}

						else if (args[0].compare("LOAD") == 0)
						{
							int nb=stringToInt(args[2]);
							for(int i=0;i<nb;i++)
							{
								lArdoise.ajouter(redoLoad[0],false);
								undoLoad.insert(undoLoad.begin(),redoLoad[0]->getNom());
								redoLoad.erase(redoLoad.begin());
							}
							cout<<"OK"<<endl;
							cout<<"# Commande retablie"<<endl;
						}
						else if (args[0].compare("CLEAR") == 0)
						{
							int nb=stringToInt(args[1]);
							Forme*f;
							for(int i=0;i<nb;i++)
							{
								f=lArdoise.getFormes()[0];
								undoClear.insert(undoClear.begin(),f);
								lArdoise.supprimer(f);

							}
							cout<<"OK"<<endl;
							cout<<"# Commande retablie"<<endl;



						}


					}
			}
			else
			{
				cout<<"ERR"<<endl;
				cout<<"# La derniere commande n'est pas un undo"<<endl;
			}
		}

		else if (result[0].compare("LISTUNDO") == 0)
		{
			lArdoise.afficherCommandes();
		}
		else if (result[0].compare("LISTANNUL") == 0)
		{
			lArdoise.afficherCommandesAnnulees();
		}
		else if(result[0].compare("LOAD")==0)
		{
			if(result.size()!=2)
			{
				cout<<"ERR"<<endl;
				cout<<"# Nombre de parametres incorrect"<<endl;
			}

			else
			{

					string com;
					Ardoise uneArdoise;
					string a=result[1];
					bool b =true;
					ifstream fichier(a.c_str(), ios::in);  // on ouvre le fichier en lecture

						if(fichier)  // si l'ouverture a r�ussi
						{
									vector<Forme*> formeTemp;
									while(getline(fichier, com))  // tant que l'on peut mettre la ligne dans "contenu"
									{
										ajouterForme(com,uneArdoise,true,undoDelete);
									}
									for(int i=0;i<uneArdoise.getFormes().size();i++)
									{
										if(lArdoise.rechercheParNom(uneArdoise.getFormes()[i]->getNom())!=NULL)
										{
											b=false;
											break;
										}
									}
									if(!b)
									{
										cout<<"ERR"<<endl;
										cout<<"# Une forme du meme nom existe deja"<<endl;
									}
									else
									{
										int nbFormesAjoutLoad=uneArdoise.getFormes().size();
										for(int i=0;i<uneArdoise.getFormes().size();i++)
										{
											undoLoad.insert(undoLoad.begin(),uneArdoise.getFormes()[i]->getNom());
											lArdoise.ajouter(uneArdoise.getFormes()[i],true);
										}


										string nbFormeLoad=itos(nbFormesAjoutLoad);

										commande=commande+" "+nbFormeLoad;
										lArdoise.ajouterCommande(commande);//-------------02/02
										derniereCommandeUndo=false;
										cout<<"OK"<<endl;
										cout<<"# Le fichier: "+result[1]+" a ete charge"<<endl;
									}
											// instructions
									 fichier.close();  // on ferme le fichier


							}
							else
							{
								cout << "ERR" << endl;
								cout<<"# Echec lors de l'ouverture du fichier"<<endl;
							}
				}
		}

		else if(result[0].compare("SAVE")==0)
		{
			if(result.size()!=2)
			{
				cout<<"ERR"<<endl;
				cout<<"# Nombre de parametres incorrect"<<endl;
			}

			else
			{
				lArdoise.sauvegarder(result[1]);
				cout<<"OK"<<endl;
				cout<<"# Ardoise sauvegardee dans:"+result[1]<<endl;
			}
		}

		else if(result[0].compare("CLEAR")==0)
		{
			//lArdoise.vider();
			Forme*f;

			int tailleForme=lArdoise.getFormes().size();
			for(int i=0;i<tailleForme;i++)
			{
				f=lArdoise.getFormes()[0];
				undoClear.insert(undoClear.begin(),f);
				lArdoise.supprimer(f);

			}
			int nbFormesAjoutLoad=tailleForme;
			cout<<"OK"<<endl;
			cout<<"# Ardoise videe"<<endl;
			string nbFormeLoad=itos(nbFormesAjoutLoad);


			commande=commande+" "+nbFormeLoad;
			lArdoise.ajouterCommande(commande);//----------02/02
			//au lieu de commande, donner commande plus x=formes. size comme �a quand on a undo,
			//on remet les x premieres formes dans l'ardoise


			derniereCommandeUndo=false;
		}

		else
		{
			if((commande.compare("EXIT")!=0)&&(result[0].compare("S"))&&(result[0].compare("R"))&&(result[0].compare("DELETE"))&&(result[0].compare("PC"))&&(result[0].compare("OR"))&&(result[0].compare("OI")))
			{
				cout<<"ERR"<<endl;
				cout<<"# Commande incorrecte"<<endl;
			}
		}



	}while((commande.compare("EXIT"))!=0);
	viderVector(undoDelete);
	viderVector(undoClear);
	viderVector(redoLoad);
	lArdoise.vider();
	return 0;

}

void viderVector(vector<Forme*>& vect)
{
	for(int i=0;i<vect.size();i++)
	{
		delete vect[i];
	}
	vect.clear();
}






string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
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
	if((fin-debut)%2!=0)//--------------si le nombre de coordonn�es de ppints n'est pas pair
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

//---------------------Ajouter forme--------------------------------------------------------------------------------------------

void ajouterForme(string commande,Ardoise& uneArdoise,bool Load,vector<Forme*>& undoDelete)
{
	vector<string> resultLoad;
	Split(resultLoad, commande,' ');
	if(resultLoad[0].compare("S")==0)
	{

		if(uneArdoise.rechercheParNom(resultLoad[1])==NULL)//--------Si le nom n'existe pas d�j�
		{
			if(resultLoad.size()!=6)//--------------- Si il n'y a pas au moins 6 arguments dans la commande
			{
				cout<<"ERR"<<endl;
				cout<<"# Nombre de parametres incorrect"<<endl;
			}

			else
			{
			Point a(stringToInt(resultLoad[2]),stringToInt(resultLoad[3]));
			Point b(stringToInt(resultLoad[4]),stringToInt(resultLoad[5]));
			uneArdoise.ajouter(new Segment(resultLoad[1],commande,segm,a,b), false);
			if(!Load)
			{
				uneArdoise.ajouterCommande(commande);//---02/02
				derniereCommandeUndo=false;
				cout<<"OK"<<endl;
				cout<<"# "+commande+" ajoute a l'ardoise"<<endl;
			}

			}
		}

		else
		{
			cout<<"ERR"<<endl;
			cout<<"# Une forme du meme nom existe deja"<<endl;
		}

	}
	else if(resultLoad[0].compare("R")==0)
			{

				if(uneArdoise.rechercheParNom(resultLoad[1])==NULL)//--------Si le nom n'existe pas d�j�
				{


					//-------------Si il n'y a pas assez d'arguments--------------------
						if(resultLoad.size()!=6)
						{
							cout<<"ERR"<<endl;
							cout<<"# Nombre de parametres incorrect"<<endl;
						}
	                //--------------------------------------------------------------------
						else
						{
							//------------Si le premier point n'est pas celui en haut � gauche -------------------------------
							if((stringToInt(resultLoad[5])>=stringToInt(resultLoad[3]))|| (stringToInt(resultLoad[2])>=stringToInt(resultLoad[4])))

							{
								cout<<"ERR"<<endl;
								cout<<"# Ce n'est pas un rectangle bien defini "<<endl;
							}
							//-----------------------------------------------------------------------------------------------------
							else
							{
							Point c(stringToInt(resultLoad[2]),stringToInt(resultLoad[3]));
							Point d(stringToInt(resultLoad[4]),stringToInt(resultLoad[5]));
							uneArdoise.ajouter(new Rectangle(resultLoad[1],commande,rect,c,d), false);
							if(!Load)
							{
								uneArdoise.ajouterCommande(commande);//---02/02
								derniereCommandeUndo=false;
								cout<<"OK"<<endl;
								cout<<"# "+commande+" ajoute a l'ardoise"<<endl;
							}
							}
						}
				}
				else
				{
					cout<<"ERR"<<endl;
					cout<<"# Une forme du meme nom existe deja"<<endl;
				}
			}

	else if(resultLoad[0].compare("PC")==0)
			{

				if(uneArdoise.rechercheParNom(resultLoad[1])==NULL)//--------Si le nom n'existe pas d�j�
				{
					if(resultLoad.size()<8)//---------si il n'y a pas assez d'arguments--------------
					{
						cout<<"ERR"<<endl;
						cout<<"# Nombre de parametres incorrect"<<endl;
					}
					else if(!nbPairCoordonnees(2,resultLoad.size()))//--------------si le nombre de coordonn�es de ppints n'est pas pair
					{
						cout<<"ERR"<<endl;
						cout<<"# Nombre de parametres incorrect (coordonnee ou nom manquant)"<<endl;

					}
					else
					{
						//--------------------ajout des points dans un vecteur de points----------------
						vector<Point> lesPoints;
						for(int i=2;i<resultLoad.size();i+=2)
						{

							lesPoints.push_back(Point(  stringToInt(resultLoad[i])   ,stringToInt(resultLoad[i+1])  ));
						}

						//-----------------------si le polygone est convexe-----------------------

						if(estConvexe(lesPoints))
						{
							uneArdoise.ajouter(new PolygoneConvexe(resultLoad[1],commande,poly,lesPoints), false);
							if(!Load)
							{
								uneArdoise.ajouterCommande(commande);//---02/02
								derniereCommandeUndo=false;
								cout<<"OK"<<endl;
								cout<<"# "+resultLoad[1]+" cree"<<endl;
							}

						}
						//------------------------------------------------------------------------------
						else
						{
							cout<<"ERR"<<endl;
							cout<<"# Polynome non convexe"<<endl;
						}
					}




				}
				else
				{
					cout<<"ERR"<<endl;
					cout<<"# Une forme du meme nom existe deja"<<endl;
				}

			}

	else if(resultLoad[0].compare("OR")==0)
	{

		if(uneArdoise.rechercheParNom(resultLoad[1])==NULL)//--------Si le nom n'existe pas d�j�
		{
			if(resultLoad.size()<4)//--------------------si il n'y a pas assez d'arguments--------------
			{
				cout<<"ERR"<<endl;
				cout<<"# Nombre de parametres incorrect"<<endl;
			}

			//-----------------Si les noms n'existent pas-----------------------------
			else
			{

				bool nomsExistent=true;
				for(int i=2;i<resultLoad.size();i++)
				{
					if(uneArdoise.rechercheParNom(resultLoad[i])==NULL)
					{
						nomsExistent=false;
					}
				}

				if(nomsExistent)
				{
					vector<Forme*> z;
					for(int i=2;i<resultLoad.size();i++)
					{

						z.push_back(uneArdoise.rechercheParNom(resultLoad[i]));

					}
					//-----------changement de nom-------------------



					uneArdoise.ajouter(new Union(resultLoad[1],commande,uni,z), false);

					if(!Load)
					{
						uneArdoise.getFormes().back()->changerNom();
						uneArdoise.ajouterCommande(commande);//---02/02
						derniereCommandeUndo=false;
						cout<<"OK"<<endl;
						cout<<"# "+resultLoad[1]+": cree"<<endl;
					}


				}

				//-------------------------------------------------------------------------
				else
				{
					cout<<"ERR"<<endl;
					cout<<"# Une des formes a unir n'existe pas"<<endl;
				}
			}
		}
		else
		{
			cout<<"ERR"<<endl;
			cout<<"# Une forme du meme nom existe deja"<<endl;
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------Intersection----------------------------------------
			else if(resultLoad[0].compare("OI")==0)
			{

				if(uneArdoise.rechercheParNom(resultLoad[1])==NULL)//--------Si le nom n'existe pas d�j�
				{
						if(resultLoad.size()<4)//---------------si il n'y a pas assez d'arguments--------------
						{
							cout<<"ERR"<<endl;
							cout<<"# Nombre de parametres incorrect"<<endl;
						}
						//-----------------------si les noms n'existent pas dans la liste------------------
						else
						{
							bool nomsExistent=true;
							for(int i=2;i<resultLoad.size();i++)
							{
								if(uneArdoise.rechercheParNom(resultLoad[i])==NULL)
								{
									nomsExistent=false;
								}
							}



							if(nomsExistent)
							{
								vector<Forme*> z;
								for(int i=2;i<resultLoad.size();i++)
								{

									z.push_back(uneArdoise.rechercheParNom(resultLoad[i]));

								}

								uneArdoise.ajouter(new Intersection(resultLoad[1],commande,inter,z), false);
								if(!Load)
								{
									uneArdoise.getFormes().back()->changerNom();
									uneArdoise.ajouterCommande(commande);//---02/02
									derniereCommandeUndo=false;
									cout<<"OK"<<endl;
									cout<<"# "+resultLoad[1]+": cree"<<endl;
								}
							}
							//-------------------------------------------------------------------------------------------
							else
							{
								cout<<"ERR"<<endl;
								cout<<"# Une des formes a intersecter n'existe pas"<<endl;
							}
						}
				}
				else
				{
					cout<<"ERR"<<endl;
					cout<<"# Une forme du meme nom existe deja"<<endl;
				}


			}

			else if(resultLoad[0].compare("DELETE")==0)
						{

							//----------------------On verifie qu'il y ait suffisamment d'arguments-------------------------------------------------
							if(resultLoad.size()<2)
							{
								cout<<"ERR"<<endl;
								cout<<"# Aucune forme pr�cis�e"<<endl;
							}
							else
							{
									//----------------On regarde si tous les noms existent------------------------------------------------------------------
									bool nomsExistent=true;
									for(int i=1;i<resultLoad.size();i++)
									{
										if(uneArdoise.rechercheParNom(resultLoad[i])==NULL)
										{
											nomsExistent=false;
										}
									}
									//---------------------------------------------------------------------------------
									//----------------------------Supprimer les formes---------------------------------
									Forme* f;
									if(nomsExistent)
									{
										//string com = "DELETE";

										for(int i=1;i<resultLoad.size();i++)
										{
											f=uneArdoise.rechercheParNom(resultLoad[i]);

											undoDelete.insert(undoDelete.begin(),f);//ajout du 02/02
											uneArdoise.supprimer(f);
											//com += " " + resultLoad[i];
										}
										if(!Load)
										{

											uneArdoise.ajouterCommande(commande);//---02/02
											derniereCommandeUndo=false;
											cout<<"OK"<<endl;
											cout<<"# Formes supprimees"<<endl;
										}
									}
									//----------------------------------------------------------------------------------
									else
									{
										cout<<"ERR"<<endl;
										cout<<"# Un des noms ne correspond a aucune forme"<<endl;
									}
							}


						}

}//---------------------------------------------------Fin ajouter forme--------------------------------------------------------------

