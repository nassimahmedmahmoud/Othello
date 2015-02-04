#include <stdio.h>
#include <stdlib.h>
#define TAILLE_CH 256
#define NB_CASES 64
#define NB_CASES_PAR_LIGNE 8
#define PION_J1 -1
#define PION_J2 1
#define PION_ABS 0

struct partie
{
 int damier[NB_CASES];
 char nomJ1[TAILLE_CH];
 char nomJ2[TAILLE_CH];
 int premierJoueurJoue;
};
/*!
 * Fonction retournant la valeur de la case (ligne,colonne) de la partie p
 *
 *  \param p : pointeur sur la partie en cours
 *  \param ligne : entier compris entre [0,NB_CASES_LIGNE-1]
 *  \param colonne : entier compris entre [0,NB_CASES_LIGNE-1]
 */
int getCase(struct partie *p,int ligne,int colonne);

/*!
 * Fonction modifiant la valeur de la case (ligne,colonne) de la partie p
 *
 *  \param p : pointeur sur la partie en cours
 *  \param ligne : entier compris entre [0,NB_CASES_LIGNE-1]
 *  \param colonne : entier compris entre [0,NB_CASES_LIGNE-1]
 *  \param valeur : entier compris entre [-1,1]
 */
void setCase(struct partie *p,int ligne,int colonne,int val);

/*!
 * Fonction changeant le joueur dont c’est le tour
 *
 *  \param p : pointeur sur la partie en cours
 */
void changementJoueur(struct partie *p);

/*!
 *  Fonction créant une partie.
 *  Allocation dynamique d’une variable de type partie dont l’adresse est retournée.
 *  Le champ damier de la variable retournée doit correspondre à une configuration
 */
struct partie* creerPartie();

/*!
 * Fonction affichant le damier sur le terminal
 *
 * \param p : pointeur sur la partie que l’on souhaite afficher
 */
void affichage1(struct partie *p);
void affichage2(struct partie *p);
void affichage3(struct partie *p);

/*!
 * Fonction retournant 1 si le joueur posant un pion sur la case (ligne,colonne) mange un pion
 * adverse dans la direction donnée, 0 sinon.
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : numéro de ligne de la case sur laquelle le pion du joueur sera posé
 * \param colonne : numéro de colonne de la case sur laquelle le pion du joueur sera posé
 * \param horizontal : axe de direction horizontal (vers la gauche, pas de changement
 *                     ou vers la droite) (compris entre [-1,1])
 * \param vertical : axe de direction (vers le haut, pas de changement ou vers le bas)
 *                   (compris entre [-1,1])
 */
int priseDansDirectionPossible(struct partie *p, int ligne, int colonne, int horizontal,int vertical );

/*!
 * Fonction indiquant 1 si le joueur peut poser un pion sur la case (ligne,colonne), 0 sinon
 *
 ￼￼￼* \param p : pointeur sur la partie en cours
 * \param ligne : numéro de ligne de la case sur laquelle le pion du joueur sera posé
 * \param colonne : numéro de colonne de la case sur laquelle le pion du joueur sera posé
 */
int coupValide(struct partie *p, int ligne, int colonne);

/*!
 * Fonction effectuant la mise à jour (pions pris) dans la direction donnée
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : numéro de ligne de la case sur laquelle le pion du joueur sera posé
 * \param colonne : numéro de colonne de la case sur laquelle le pion du joueur sera posé
 * \param horizontal : axe de direction horizontal (vers la gauche, pas de changement
 * ou vers la droite) (compris entre [-1,1])
 * \param vertical : axe de direction (vers le haut, pas de changement ou vers le bas)
 * (compris entre [-1,1])
 */
void mouvementDansDirection(struct partie *p, int ligne, int colonne, int horizontal,int vertical );

/*!
 * Fonction jouant le pion sur la case (ligne,colonne) et mettant à jour le damier.
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : numéro de ligne de la case sur laquelle le pion du joueur sera posé
 * \param colonne : numéro de colonne de la case sur laquelle le pion du joueur sera posé
 */
void mouvement(struct partie  *p , int ligne, int colonne);

/*!
 * Fonction retournant 1 si le joueur dont c’est le tour peut poser un pion sur le damier, 0 sinon
 *
 * \param p : pointeur sur la partie en cours
 */
int joueurPeutJouer(struct partie *p);

int saisieJoueur(int*,int*);

int tourJoueur(struct partie *p);

int sauvegardePartie(struct partie *p);


int chargementPartie(struct partie *p);

int menu(struct partie *p);

struct partie* creerPartie2();
