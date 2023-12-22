/* UQAM / Département d'informatique
   INF3105 - Structures de données et algorithmes
   Squelette pour classe générique Tableau<T> pour le TP1 et Lab3.

   AUTEUR(S): 1. Carl Montpetit ⟺ MONC08069000
              2. Kim Joziak     ⟺ JOZK05559701
*/
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <iostream>
// Une classe de type générique
template <class T> class Tableau {
public:
  /*************************************************/
  // CONSTRUCTEURS ET DESTRUCTEUR
  /*************************************************/
  Tableau(int capacite_initiale = 8);
  Tableau(const Tableau<T> &autre);
  ~Tableau();

  /*************************************************/
  // FONCTIONS DE MODIFICATIONS (DÉCLARATIONS)
  /*************************************************/
  void ajouter(const T &element);
  void vider();
  void inserer(const T &element, int index = 0);
  void enlever(int index = 0);
  bool estTrie();
  void enlever_dernier();

  /*************************************************/
  // OPÉRATEURS D'ACCÈS [] (DÉCLARATIONS)
  /*************************************************/
  T &operator[](int index);

  const T &operator[](int index) const;

  /*************************************************/
  // FONCTIONS UTILITAIRES (DÉCLARATIONS)
  /*************************************************/
  void afficher();
  void redimensionner(int nouvCapacite);
  bool vide() const;
  int taille() const;
  int chercher(const T &element) const;
  bool contient(const T &element) const;
  void trier();

  /*************************************************/
  // OPÉRATEURS =, ==, += et + (DÉCLARATIONS)
  /*************************************************/
  Tableau<T> &operator=(const Tableau<T> &autre);
  bool operator==(const Tableau<T> &autre) const;
  Tableau<T> &operator+=(const Tableau<T> &autre);
  Tableau<T> operator+(const Tableau<T> &autre) const;

  /*************************************************/
  // DÉCLARATION DES ATTRIBUTS (DATA) -> TJS PRIVÉ -> ✩ENCAPSULATION✩
  /*************************************************/
private:
  T *elements;
  int capacite;
  int nbElements;
};

#endif // define _TABLEAU___H_
