/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#if !defined(_POINT__H_)
#define _POINT__H_

#include <iostream>

using namespace std;

class Point {
public:
  /*************************************************/
  // CONSTRUCTEURS ET DESTRUCTEUR (DÉCLARATIONS)
  /*************************************************/
  Point(const Point &point);
  Point(double x = 0, double y = 0);
  /*************************************************/
  // FONCTIONS UTILITAIRES (DÉCLARATIONS)
  /*************************************************/
  double distance(const Point &point) const;
  int operator!=(Point &point);
private:
  /*************************************************/
  // DÉCLARATION DES ATTRIBUTS (DATA) -> TJS PRIVÉ -> ✩ENCAPSULATION✩
  /*************************************************/
  double x;
  double y;
  /*************************************************/
  // SURCHARGE DES OPÉRATEURS (DÉCLARATIONS)
  /*************************************************/
  friend istream &operator>>(istream &istream, Point &point);
  friend ostream &operator<<(ostream &ostream, const Point &point);
};

#endif