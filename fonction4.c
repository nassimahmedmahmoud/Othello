#include "couleursTerminal.h"
#include "projetc.h"

int sauvegardePartie(struct partie *p) {
    FILE *f=NULL;
    int i;
    f=fopen("sauvegarde.txt","wt"); //ouvre un fichier texte avec les droits d'ecriture w
    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }
    fprintf(f,"%s\n",p->nomJ1); //ecrit sur le fichier tous les elements de la partie
    fprintf(f,"%s\n",p->nomJ2);
    fprintf(f,"%d\n",p->premierJoueurJoue);
    for(i=0;i<NB_CASES;i++)
	{
		fprintf(f,"%d\n",p->damier[i]);
	}
    fclose(f);  // fermeture du fichier
    return 1;
}


int chargementPartie(struct partie *p)
{
    FILE *f=NULL;
    int i;
    //char ch[]="";
    f=fopen("sauvegarde.txt","rt"); //ouvre un fichier texte avec les droits d'ecriture w
    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }
    fscanf(f,"%s",p->nomJ1); //lit le fichier et "copie" dans la structure mis en parametre
    while(!feof(f)){
        fscanf(f,"%s",p->nomJ2);
        fscanf(f,"%d",&p->premierJoueurJoue);
        for(i=0;i<NB_CASES;i++)
        {
            fscanf(f,"%d\n",&p->damier[i]);
        }
        
    }
    fclose(f); // fermeture du fichier
    return 1;
}

int menu(struct partie *p)
{
	int choix;
	if(p==NULL) // si la partie passé en parametre n'a pas ete instancié
	{
		do{
			printf("0----Quittez le jeu\n1----Commencez une nouvelle partie\n");
			printf("2----Charger la derniere partie sauvegardee\n");
			scanf("%d",&choix);
            
		}while(choix<0 || choix>2); // choix du joueur compris entre 0 et 2
	}
	else
	{
		do{
			printf("0----Quittez le jeu\n1----Commencez une nouvelle partie\n");
			printf("2----Charger la derniere partie sauvegardee\n3----Sauvegarder la partie courante\n");
			printf("4----Reprendre la partie en cours\n");
			scanf("%d",&choix);
            
		}while(choix<0 || choix >4); // choix du joueur compris entre 0 et 4
        
	}
	return choix;
}


void score(struct partie *p){
    
    int i,noir=0,blanc=0;
    
    
    for(i=0;i<NB_CASES;i++){ // compte le nombre de noir et de blanc sur le damier
        if(p->damier[i]==-1)
            blanc++;
        else if(p->damier[i]==1)
            noir++;
    }
    printf("\n");
    printf("Score :\n");
    changerCouleursTerminal(7,5); // affiche le score en cours
    printf("%s",p->nomJ1);
    changerCouleursTerminal(0,6);
    printf("%s",p->nomJ2);
    changerCouleursTerminal(9,9);
    printf("\n");
    changerCouleursTerminal(0,6);
    printf("  %d  ",blanc);
    changerCouleursTerminal(7,5);
    printf("  %d  ",noir);
    changerCouleursTerminal(9,9);
    printf("\n");
    printf("\n");
}









