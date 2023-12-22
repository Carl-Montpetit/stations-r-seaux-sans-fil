/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#include "point.h"
#include <cassert>
#include <cmath>

using namespace std;

/*************************************************/
// CONSTRUCTEURS ET DESTRUCTEUR (DÉFINITIONS)
/*************************************************/
/**
 * @brief Construit un objet Point par défaut
 *
 * @param x_
 * @param y_
 */
Point::Point(double x_, double y_) : x(x_), y(y_) {}

/**
 * @brief Construit un objet Point par copie
 *
 * @param point
 */
Point::Point(const Point &point) : x(point.x), y(point.y) {}

/*************************************************/
// FONCTIONS UTILITAIRES (DÉFINITIONS)
/*************************************************/
/**
 * @brief Retourne la distance euclidienne entre deux points (x,y)
 *
 * @note D = √{(x2-x1)^2 + (y2-y1)^2}
 * @note O(1)
 * @param point
 * @return distance (en mètre)
 */
double Point::distance(const Point &point) const {
  return sqrt(pow(point.x - this->x, 2) + pow(point.y - this->y, 2));
}

/*************************************************/
// SURCHARGE DES OPÉRATEURS (DÉFINITIONS)
/*************************************************/
/**
 * @brief Définition du comportement de la sortie standard pour un objet Point
 *
 * @note O(1)
 * @param outStream
 * @param point
 * @return outStream
 */
ostream &operator<<(ostream &outStream, const Point &point) {
  outStream << "(" << point.x << "," << point.y << ")";
  return outStream;
}

/**
 * @brief Définition du comportement de l'entré standard pour un objet Point
 *
 * @note O(1)
 * @param inStream
 * @param point
 * @return inStream
 */
istream &operator>>(istream &inStream, Point &point) {
  char ouvertureParenthese, virgule, fermetureParenthese;
  inStream >> ouvertureParenthese;
  if (inStream) {
    inStream >> point.x >> virgule >> point.y >> fermetureParenthese;
    assert(ouvertureParenthese == '(');
    assert(virgule == ',');
    assert(fermetureParenthese == ')');
  }
  return inStream;
}

/**
 * @brief Définition du comportement de l'opérateur != pour un objet de type
 * Point
 * @note O(1)
 * @param point
 * @return
 */
int Point::operator!=(Point &point) {
  return !(this->x == point.x && this->y == point.y);
}