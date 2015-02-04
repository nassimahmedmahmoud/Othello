#include "couleursTerminal.h"
#include "projetc.h"

int saisieJoueur(int *ligne, int *colonne) {
    char ch[2]="";
    char l[3]="";
    printf("A----Abandonner\nM----Menu\nS--Saisir une case:\n");
    scanf("%s",ch); //le joueur entre une chaine de caractere
    if(ch[0]=='A')// le joueur entre A si il veut abandonner
        return -2;
    else if(ch[0]=='M')// le joueur entre M si il veut acceder au menu
        return -1;
    else if(ch[0]=='S') // le joueur entre S si il veut saisir des coordonnees
	{
        printf("Saisir la lettre correspondant a la ligne suivi du chiffre correpondant à la colonne :\n");
        scanf("%s",l);
        if(l[0]>='a'  && l[0]<='h' && l[1]<='8' && l[1]>='1'  )// le joueur saisie les coordonee compris entre a et h et 1 et 8
		{
			*ligne=l[0]-'a';
			*colonne=l[1]-'1';
			return 1;
		}
        else
		{
            return 0;
		}
    }
    else
        return 0;
}

int tourJoueur(struct partie *p){
    int ligne=0,colonne=0,saisie=0;
    affichage3(p);
    score(p);
    if(p->premierJoueurJoue==1)
        printf("Tour de %s (blanc) \n",p->nomJ1); // on affiche le nom du joueur courant
    else
        printf("Tour de %s (noir) \n",p->nomJ2);
    
    if(joueurPeutJouer(p))
    {
        do{
            saisie=saisieJoueur(&ligne,&colonne);
        }while(saisie==0 || (coupValide(p,ligne,colonne)==0 && saisie==1)); // la saisie est repeté tant que la saisie est valide et que le coupValide soit valide
        
        if(saisie==-2 || saisie==-1)
        {
            return saisie;
        }
        else{
            mouvement(p,ligne,colonne); // on effectue le mouvement
            changementJoueur(p); // on change de joueur
            return 1;
        }
    }
    else{
        printf("Vous passez votre tour\n");
        changementJoueur(p);
        return 0;
    }
}

int gagnant(struct partie *p){
    int i,noir=0,blanc=0;
    
    
    for(i=0;i<NB_CASES;i++){ // compte le nombre et noir et de blanc sur le damier
        if(p->damier[i]==-1)
            blanc++;
        else if(p->damier[i]==1)
            noir++;
    }
    if(noir>blanc){ //compare les noirs et les blancs
        printf("Les noirs l'emportent avec %d sur %d\n",noir,blanc);
        return 1;
    }
    else if(blanc>noir){
        printf("Les noirs l'emportent avec %d sur %d\n",blanc,noir);
        return -1;
    }
    else
    {
        printf("Egalite !");
        return 0;
    }
    
}

int finPartie (struct partie *p){
	int a=0;
    a=a+joueurPeutJouer(p); // on ajoute joueurPeutJouer(valant 1 si le joueur peut jouer) au compteur a
    changementJoueur(p);
    a=a+joueurPeutJouer(p);
    changementJoueur(p);
    
    if(a) // si a est different de 0 alors au moins un des deux joueur peut jouer donc la partie continue
        return 0;
    else
        return 1;
    
}

int jouerPartie(struct partie *p){
    int tour=0,end=0;
    do{
        tour=tourJoueur(p);
        end=finPartie(p);
    }while(end!=1 && tour!=-2 && tour!=-1); // on repete les fonction tourJoueur (pour que le joueur joue) et finPartie (pour pouvoir arreter la partie qd elle sera terminer)
    if(tour!=-2 && tour!=-1) // si le joueur n'abandonne pas ou n'accede pas au menu alors on appelle la fonction gagnant
        gagnant(p);
    if(tour==-1)
        return 0;
    else
        return 1;
    
}