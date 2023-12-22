/*  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  Automne 2016 | TP1
 *  http://ericbeaudry.ca/INF3105/
 */
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#include "immeuble.h"

using namespace std;

/*************************************************/
// CONSTRUCTEURS (DÉFINITIONS)
/*************************************************/
Immeuble::Immeuble() {}

Immeuble::Immeuble(const Immeuble &immeuble)
    : nom(immeuble.nom), position(immeuble.position), hauteur(immeuble.hauteur),
      nbClient(immeuble.nbClient) {}

Immeuble::Immeuble(string nom_, Point position_, double hauteur_, int nbClient_)
    : nom(nom_), position(position_), hauteur(hauteur_), nbClient(nbClient_) {}

/*************************************************/
// SURCHARGE DES OPÉRATEURS (DÉFINITIONS)
/*************************************************/
/**
 * @brief Définition du comportement de l'entré standard pour un objet Immeuble
 *
 * @note O(1)
 * @param istream
 * @param immeuble
 * @return istream
 */
istream &operator>>(istream &istream, Immeuble &immeuble) {
  istream >> immeuble.nom;
  if (istream) {
    istream >> immeuble.position >> immeuble.hauteur >> immeuble.nbClient;
  }
  return istream;
}

/**
 * @brief Définition du comportement de la sortie standard pour un objet
 * Immeuble
 *
 * @note O(1)
 * @param ostream
 * @param immeuble
 * @return ostream
 */
ostream &operator<<(ostream &ostream, const Immeuble &immeuble) {
  // pour voir tous les attributs :
  // return ostream << immeuble.nom << ' ' << immeuble.position << ' '
  //   << immeuble.hauteur << ' ' << immeuble.nbClient;
  return ostream << immeuble.nom;
}
