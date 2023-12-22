/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#include "station.h"

using namespace std;

/*************************************************/
// CONSTRUCTEURS (DÉFINITIONS)
/*************************************************/
Station::Station(string nom_, double rayon_, double hauteurMinimale_,
                 double frequence_) {
  this->nom = nom_;
  this->rayon = rayon_;
  this->hauteurMinimale = hauteurMinimale_;
  this->frequence = frequence_;
}

Station::Station(const Station &station_) {
  this->nom = station_.nom;
  this->rayon = station_.rayon;
  this->hauteurMinimale = station_.hauteurMinimale;
  this->frequence = station_.frequence;
}

/*************************************************/
// SURCHARGE DES OPÉRATEURS (DÉFINITIONS)
/*************************************************/
/**
 * @brief Définition du comportement de l'entré standard pour un objet Station
 *
 * @note O(1)
 * @param istream
 * @param station
 * @return istream
 */
istream &operator>>(istream &istream, Station &station) {
  istream >> station.nom;
  if (istream) {
    istream >> station.rayon >> station.hauteurMinimale >> station.frequence;
  }
  return istream;
}

/**
 * @brief Définition du comportement de la sortie standard pour un objet Station
 *
 * @note O(1)
 * @param station
 * @return ostream
 */
ostream &operator<<(ostream &ostream, const Station &station) {
  // Pour afficher tous les attributs :
  // return ostream << station.nom << ' ' << station.rayon << ' '
  //   << station.hauteurMinimale << ' ' << station.frequence;
  return ostream << station.nom;
}