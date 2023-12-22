/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#if !defined(_IMMEUBLE__H_)
#define _IMMEUBLE__H_

#include "point.h"
#include "station.h"
#include "tableau.h"
#include <iostream>
#include <string>

using namespace std;

class Immeuble {
public:
  /*************************************************/
  // CONSTRUCTEURS (DÉCLARATIONS)
  /*************************************************/
  Immeuble();
  Immeuble(const Immeuble &immeuble);
  Immeuble(string nom, Point position, double hauteur, int nbClient);

private:
  /*************************************************/
  // DÉCLARATION DES ATTRIBUTS (DATA) -> TJS PRIVÉ -> ✩ENCAPSULATION✩
  /*************************************************/
  string nom;
  Point position;
  double hauteur;
  int nbClient;
  unsigned int dejaTouche;
  unsigned int dejaChoisi;
  friend int tp1(istream &entree);
  /*************************************************/
  // SURCHARGE DES OPÉRATEURS (DÉCLARATIONS)
  /*************************************************/
  friend istream &operator>>(istream &istream, Immeuble &immeuble);
  friend ostream &operator<<(ostream &ostream, const Immeuble &immeuble);
};
#endif
