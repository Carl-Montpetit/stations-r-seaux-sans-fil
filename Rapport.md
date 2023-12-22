# Rapport

#### Auto-évaluation

> Indiquer si le programme fonctionne correctement, partiellement ou aucunement.

Le programme fonctionne **partiellement**, les cas avec seulement une station fonctionnent tous. Certains cas avec deux stations ne fonctionnent pas. Nous n'avons pas implémenté le cas où deux stations pourraient avoir la même fréquence. De plus, lorsqu'un immeuble est choisi pour une station, celui-ci ne peut être changé. Les cas n'assurent donc pas de couvrir le plus grand nombre de clients.

#### Un tableau montrant les temps d'exécution sur les fichiers tests fournis

| Fichier_test | #Stat | #Imm | #Cli | Opt? | CPU  | Mém.(k) |
| :----------: | :---: | :--: | :--: | :--: | :--: | :-----: |
| testC00.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3600k  |
| testC01.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3480k  |
| testC02.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3800k  |
| testC03.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  4324k  |
| testD00.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3532k  |
| testD01.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3668k  |
| testD02.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3852k  |
| testD03.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  4412k  |
| testD04.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3744k  |
| testD05.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3708k  |
| testG00.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3740k  |
| testG01.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3724k  |
| testG02.txt  |   ?   |  ?   |  -   |  -   | 0.01 |  4292k  |
| testG03.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  4292k  |
| testG04.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3880k  |
| testG05.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3708k  |
| testG06.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3740k  |
| testH00.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3768k  |
| testH01.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  4332k  |
| testH02.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  3892k  |
| testH03.txt  |   ?   |  ?   |  -   |  -   | 0.00 |  4368k  |
| testH04.txt  |   ?   |  ?   |  -   |  -   | 2.01 | 17044k  |
| testH05.txt  |   ?   |  ?   |  -   |  -   | 0.29 |  6812k  |

#### Analyse de la complexité temporelle (pire cas/max ou min) en notation $O$ 

> Voir les `docstrings` dans les fichiers source du projet.