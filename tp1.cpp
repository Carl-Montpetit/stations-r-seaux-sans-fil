/*  INF3105 | Structures de données et algorithmes
UQAM | Département d'informatique
Automne 2016 | TP1
http://ericbeaudry.ca/INF3105/

AUTEUR(S): 1. Carl Montpetit ⟺ MONC08069000
           2. Kim Joziak     ⟺ JOZK05559701
*/
/*************************************************/
// TÂCHES DE PRÉ-COMPILATION
/*************************************************/
#include "immeuble.h"
#include "point.h"
#include "station.h"
#include "tableau.cpp"
#include "tableau.h"
#include <fstream>

using namespace std;

/**
 * @brief La fonction lit un fichier contenant les informations importantes
 * (immeubles, stations, etc...), execute l'analyse en fonction du nombre
 * de stations qui existe dans ce fichier et finalement affiche les résultats
 * @note Si le nombre de station est de 0 : O(1)
 *       Si le nombre de station est de 1 : si 0 immeuble : O(1)
 *                                          si m immeuble : O(m^2)
 *       Si le nombre de station est de 2 : si 0 immeuble : O(n)
 *                                          si m immeuble : O(n•m^2)
 *       Pour n le nombre de station et m le nombre d'immeuble
 *       Or, le cas max est de O(n•m^2) et le cas min est de O(1)
 *       Le cas moyen va dépendre des entrés du programme
 *
 * @param entree
 * @return code succès/erreurs
 */
int tp1(std::istream &entree);

/*************************************************/
// POINT D'ENTRÉ PRINCIPAL POUR L'EXÉCUTION DU PROGRAMME
/*************************************************/
/**
 * @note minimum : O(1) (si une station et 1 immeuble), maximum O(m•n),
 * (si n stations et m immeubles)
 * @param argc : nombre d'arguments passés
 * @param argv : tableau de chaines de caractère
 * @return code de retour du programme (int)
 */
int main(int argc, const char **argv) {
  if (argc > 1) {
    ifstream fichierEntree(argv[1]);
    if (fichierEntree.fail()) {
      cerr << "Erreur de lecture du fichier '" << argv[1] << "'" << endl;
      return 1;
    }
    return tp1(fichierEntree);
  } else {
    return tp1(cin);
  }
}
/*************************************************/
// FONCTIONS UTILITAIRES
/*************************************************/
int tp1(istream &entree) {
  Tableau<Station> stationsListe;
  Tableau<Immeuble> immeublesListe;
  int nombreStations = 0;
  {
    entree >> nombreStations;
    for (int i = 0; i < nombreStations; i++) {
      Station station;
      entree >> station;
      stationsListe.ajouter(station);
    }
    while (entree) {
      Immeuble immeuble;
      entree >> immeuble;
      if (!entree)
        break;
      immeublesListe.ajouter(immeuble);
    }
  }
  Station &laStation = stationsListe[0];
  Immeuble immeubleChoisi;
  int nbClients;
  int nbClientMax = -1;
  int nbClientsTotal = 0;

  switch (nombreStations) {
  case 1:
    for (int i = 0; i < immeublesListe.taille(); i++) {
      if (immeublesListe[i].hauteur >= stationsListe[0].hauteurMinimale) {
        nbClients = 0;
        for (int j = 0; j < immeublesListe.taille(); j++) {
          double d =
              immeublesListe[i].position.distance(immeublesListe[j].position);
          if (d <= stationsListe[0].rayon)
            nbClients += immeublesListe[j].nbClient;
        }
        if (nbClients > nbClientMax) {
          nbClientMax = nbClients;
          immeubleChoisi = immeublesListe[i];
        }
      }
    }
    cout << laStation << ' ' << immeubleChoisi << endl;
    cout << nbClientMax << endl;
    return 0;

  case 2:
    for (int i = 0; i < nombreStations; i++) {
      Immeuble immeubleChoisi;
      int nbClientMax = -1;

      for (int j = 0; j < immeublesListe.taille(); j++) {
        if (immeublesListe[j].hauteur >= stationsListe[i].hauteurMinimale &&
            immeublesListe[j].dejaChoisi != 1) {
          nbClients = 0;
          for (int k = 0; k < immeublesListe.taille(); k++) {
            double d =
                immeublesListe[j].position.distance(immeublesListe[k].position);
            if (d <= stationsListe[i].rayon)
              nbClients += immeublesListe[k].nbClient;
          }
          if (nbClients > nbClientMax) {
            nbClientMax = nbClients;
            immeubleChoisi = immeublesListe[j];
          }
        }
      }
      // déterminer immeubles touchés
      if (i == 0) {
        for (int j = 0; j < immeublesListe.taille(); j++) {
          double d2 =
              immeubleChoisi.position.distance(immeublesListe[j].position);
          if (d2 <= stationsListe[i].rayon) {
            immeublesListe[j].dejaTouche = 1;
          }
          if (immeubleChoisi.nom == immeublesListe[j].nom) {
            immeublesListe[j].dejaChoisi = 1;
          }
        }
      }
      // Assure que les clients ne sont pas comptés deux fois.
      if (i == 1) {
        for (int j = 0; j < immeublesListe.taille(); j++) {
          double d3 =
              immeubleChoisi.position.distance(immeublesListe[j].position);
          if (d3 <= stationsListe[i].rayon &&
              (immeublesListe[j].dejaTouche == 1 ||
               immeublesListe[j].dejaChoisi == 1)) {
            nbClientsTotal -= immeublesListe[j].nbClient;
          }
        }
      }
      if (nbClientsTotal == 0 && i == 1) {
        cout << stationsListe[i] << ' ' << "--" << endl;
      } else {
        cout << stationsListe[i] << ' ' << immeubleChoisi << endl;
      }
      nbClientsTotal += nbClientMax;
    }
    cout << nbClientsTotal << endl;
    return 0;

  default:
    for (int i = 0; i < nombreStations; i++) {
      Station &laStation = stationsListe[i];
      Immeuble immeubleChoisi;
      int nbClientMax = -1;

      for (int j = 0; j < immeublesListe.taille(); j++) {

        if (immeublesListe[j].hauteur >= stationsListe[i].hauteurMinimale) {
          nbClients = 0;

          for (int k = 0; k < immeublesListe.taille(); k++) {
            double d =
                immeublesListe[j].position.distance(immeublesListe[k].position);

            if (d <= stationsListe[i].rayon)
              nbClients += immeublesListe[k].nbClient;
          }

          if (nbClients > nbClientMax) {
            nbClientMax = nbClients;
            immeubleChoisi = immeublesListe[j];
          }
        }
      }
      nbClientsTotal += nbClientMax;
      cout << laStation << ' ' << immeubleChoisi << endl;
    }
    cout << nbClientsTotal << endl;
    return 0;
  }
}
