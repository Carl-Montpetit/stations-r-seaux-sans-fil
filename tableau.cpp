/* UQAM / Département d'informatique
INF3105 - Structures de données et algorithmes
Squelette pour classe générique Tableau<T> pour le TP1 et Lab3.

AUTEUR(S): 1. Carl Montpetit ⟺ MONC08069000
           2. Kim Joziak     ⟺ JOZK05559701
*/
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#include "tableau.h"
#include <assert.h>

using namespace std;

/*************************************************/
// DÉFINITIONS DES CONSTRUCTEURS ET DU DESTRUCTEUR
/*************************************************/
// Définition du constructeur de la classe tableau de type générique (par défaut
// la capacité est de 8)
template <class T> Tableau<T>::Tableau(int capacite_) {
  this->nbElements = 0;
  this->capacite = capacite_;
  elements = new T[capacite];
}

// Définition du constructeur par copie
template <class T> Tableau<T>::Tableau(const Tableau &autre) {
  this->nbElements = autre.nbElements;
  this->capacite = autre.capacite;
  this->elements = new T[capacite];
  for (int i = 0; i < capacite; i++)
    this->elements[i] = autre.elements[i];
}

// Définition du destructeur
template <class T> Tableau<T>::~Tableau() { delete[] elements; }

/*************************************************/
// DÉFINITIONS DES FONCTIONS DE MODIFICATIONS
/*************************************************/
/**
 * @brief Ajoute un élément à la fin du tableau
 * Et double la capacité s'il y a débordement
 *
 * @note min : O(1) (amortie en doublant la capacité une fois plein) max : O(n)
 * @tparam T
 * @param item -> l'élément à ajouter dans le tableau
 */
template <class T> void Tableau<T>::ajouter(const T &item) {
  assert(this->nbElements <= this->capacite);
  if (this->nbElements == this->capacite) {
    redimensionner(capacite * 2);
  }
  this->elements[this->nbElements++] = item;
}

/**
 * @brief Vide le tableau i.e enlèver tous les éléments dans le tableau
 *
 * @note O(1)
 * @tparam T
 */
template <class T> void Tableau<T>::vider() { this->nbElements = 0; }

/**
 * @brief Insère un élément à l'indice (index) en paramètre
 * et décale la position de chacun des éléments (vers la droite)
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param element
 * @param index
 */
template <class T> void Tableau<T>::inserer(const T &element, int index) {
  assert(index < nbElements);
  if (this->nbElements >= this->capacite)
    redimensionner(capacite * 2);

  for (int i = this->nbElements; i > index; i--)
    this->elements[i] = this->elements[i - 1];
  this->elements[index] = element;
  nbElements++;
}

/**
 * @brief Enlève un élément à l'indice (index)
 * et décale les éléments d'une position vers la gauche
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param index
 */
template <class T> void Tableau<T>::enlever(int index) {
  assert(index < this->nbElements);
  for (int i = index; i < this->nbElements - 1; i++)
    this->elements[i] = this->elements[i + 1];
  this->nbElements--;
}

/**
 * @brief Enlève le dernier élément du tableau
 *
 * @note O(1)
 * @tparam T
 */
template <class T> void Tableau<T>::enlever_dernier() { this->nbElements--; }

/*************************************************/
// DÉFINITIONS DES OPÉRATEURS D'ACCÈS []
/*************************************************/
template <class T> T &Tableau<T>::operator[](int index) {
  assert(index < this->nbElements);
  return this->elements[index];
}

template <class T> const T &Tableau<T>::operator[](int index) const {
  assert(index < this->nbElements);
  return this->elements[index];
}

/*************************************************/
// DÉFINITIONS DES FONCTIONS UTILITAIRES
/*************************************************/
/**
 * @brief Affiche les éléments du tableau à la console
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 */
template <class T> void Tableau<T>::afficher() {
  for (int i = 0; i <= capacite - 1; i++)
    cout << *(elements + i) << " ";
  cout << endl;
}

/**
 * @brief Redimensionne la capacité du tableau en fonction du paramètre
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param nouvCapacite
 */
template <class T> void Tableau<T>::redimensionner(int nouvCapacite) {
  this->capacite = nouvCapacite;
  T *temp = new T[capacite];
  for (int i = 0; i < this->nbElements; i++)
    temp[i] = this->elements[i];
  delete[] elements;
  elements = temp;
}

/**
 * @brief Vérifie si le tableau est vide
 *
 * @note O(1)
 * @tparam T
 * @return true si le tableau est vide
 * @return false sinon
 */
template <class T> bool Tableau<T>::vide() const {
  bool valid = false;
  if (this->nbElements == 0)
    valid = true;
  else
    valid = false;
  return valid;
}

/**
 * @brief Retourne le nombre d'éléments dans le tableau
 * @note O(1)
 * @tparam T
 * @return int i.e le nombre d'éléments dans le tableau
 */
template <class T> int Tableau<T>::taille() const { return this->nbElements; }

/**
 * @brief Cherche l'élément dans le tableau et retourne sa position (indice) ->
 * La première occurence si pas unique
 *
 * @note min : O(1) max : O(n)
 * @tparam T
 * @param element
 * @return int i.e indice de la position
 * @return -1 sinon
 */
template <class T> int Tableau<T>::chercher(const T &element) const {
  for (int i = 0; i < this->nbElements; i++) {
    if (this->elements[i] == element)
      return i;
  }
  return -1;
}

/**
 * @brief Vérifie si le tableau contient l'élément en paramètre
 *
 * @note min : O(1), max : O(n) et moyen : O(n)
 * @tparam T
 * @param element i.e l'élément à vérifier
 * @return true si l'élément est dans le tableau
 * @return false sinon
 */
template <class T> bool Tableau<T>::contient(const T &element) const {
  for (int i = 0; i < nbElements; i++) {
    if (this->elements[i] == element)
      return true;
  }
  return false;
}

/**
 * @brief Vérifie si le tableau est trié en ordre croissant
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @return true
 * @return false
 */
template <class T> bool Tableau<T>::estTrie() {
  bool valid = true;
  if (this->nbElements == 1 || this->nbElements == 0)
    valid = true;
  for (int i = 0; i < this->nbElements; i++) {
    if (elements[i] > elements[i + 1]) {
      std::cout << "Pas Trié !" << std::endl;
      valid = false;
    } else {
      std::cout << "Trié !" << std::endl;
      valid = true;
    }
  }
  return valid;
}

/**
 * @brief Trier les éléments dans un tableau (en ordre croissant)
 *
 * @note O(n^2)
 * J'ai essayé d'implémenter l'algorithme récursif de trie par
 * fusion, mais sans succès pour l'instant... Or, je sais que ce n'est pas
 * l'algorithme de trie le plus efficace en temps d'exécution car l'autre
 * m'aurait donné une complexité O(n*log(n)) -> Si on a le temps de le faire
 * on le fera
 * @tparam T
 */
template <class T> void Tableau<T>::trier() {
  int i, j, temp;
  if (!(this->estTrie())) {
    for (i = 0; i < this->nbElements; i++) {
      for (j = i + 1; j < this->nbElements; j++) {
        if (this->elements[i] > this->elements[j]) {
          temp = this->elements[i];
          this->elements[i] = this->elements[j];
          this->elements[j] = temp;
        }
      }
    }
  }
}

/*************************************************/
// DÉFINITIONS DE LA SURCHARGE DES OPÉRATEURS =, ==, += et +
/*************************************************/
/**
 * @brief Le tableau à gauche du symbole = devient égale au tableau à droite du
 * symbole =
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param autre -> Le tableau à droite du symbole =
 * @return Tableau<T>&
 */
template <class T> Tableau<T> &Tableau<T>::operator=(const Tableau<T> &autre) {
  if (this == &autre) {
    return *this;
  }
  this->nbElements = autre.nbElements;
  if (this->capacite < autre.nbElements) {
    delete[] elements;
    this->capacite = autre.nbElements;
    this->elements = new T[capacite];
  }
  for (int i = 0; i < this->nbElements; i++) {
    this->elements[i] = autre.elements[i];
  }
  return *this;
}

/**
 * @brief Vérifie si le tableau à gauche du symbole == est égale au tableau à
 * droite du symbole ==
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param autre -> Le tableau à droite du symbole ==
 * @return true si le tableau à gauche du == est égale à celui à droite du ==
 * @return false sinon
 */
template <class T> bool Tableau<T>::operator==(const Tableau<T> &autre) const {
  if (this->nbElements == autre.nbElements) {
    for (int i = 0; i < this->nbElements; i++) {
      if (this->elements[i] != autre.elements[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

/**
 * @brief Concatène deux tableaux ensemble pour obtenir un nouveau tableau
 * contenant la concaténation des deux
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param autre -> Le tableau à droite du symbole +
 * @return Tableau<T> -> Le nouveau tableau contenant la concaténation des deux
 * autres tableaux
 */
template <class T>
Tableau<T> Tableau<T>::operator+(const Tableau<T> &autre) const {
  int nbElementsTotale = this->nbElements + autre.nbElements;
  Tableau<T> tab(nbElementsTotale);
  tab = *this;
  for (int i = 0; i < autre.nbElements; i++)
    tab.ajouter(autre.elements[i]);
  return tab;
}

/**
 * @brief Le tableau à gauche du symbole (implicite) += devient la somme de
 * lui-même avec le tableau à droite du symbole += i.e t1 += t2 <-> t1 = t1 + t2
 * Il faut faire attention au cas ou le paramètre implicite est le même objet
 * (pas une copie ⟺ même adresse) que l'objet donné en paramètre i.e ex : tab1
 * += tab1
 *
 * @note min : O(1) et max : O(n)
 * @tparam T
 * @param autre -> Le tableau à droite du symbole +=
 * @return Tableau<T>&
 */
template <class T> Tableau<T> &Tableau<T>::operator+=(const Tableau &autre) {
  if (&autre == this)
    *this = *this + *this;
  else
    for (int i = 0; i < autre.nbElements; i++)
      this->ajouter(autre.elements[i]);
  return *this;
}