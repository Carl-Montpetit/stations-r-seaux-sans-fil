/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#if !defined(_STATION__H_)
#define _STATION__H_

#include <iostream>
#include <string>

using namespace std;

class Station {
public:
  /*************************************************/
  // CONSTRUCTEURS (DÉCLARATIONS)
  /*************************************************/
  Station(string nom = "<sans nom>", double rayon = 0,
          double hauteurMinimale = 0, double frequence = 0);
  Station(const Station &station);
private:
  /*************************************************/
  // DÉCLARATION DES ATTRIBUTS (DATA) -> TJS PRIVÉ -> ✩ENCAPSULATION✩
  /*************************************************/
  string nom;
  double rayon;
  double hauteurMinimale;
  double frequence;
  friend int tp1(istream &entree);
  /*************************************************/
  // SURCHARGE DES OPÉRATEURS (DÉCLARATIONS)
  /*************************************************/
  friend istream &operator>>(istream &istream, Station &station);
  friend ostream &operator<<(ostream &ostream, const Station &station);
};

#endif