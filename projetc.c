#include "projetc.h"

int main(void)
{
	int jeu,partie=0;
    struct partie *p1=NULL;
    printf("\n\n**********Vous jouez à l'othello**********\n\n");
    
	do{
		jeu=menu(p1);
		if(jeu==0)
		{
			return 0;
		}
		else if(jeu==1)
		{
            p1=creerPartie();
			partie=jouerPartie(p1);
        }
        else if(jeu==2)
        {
            p1=(struct partie*)calloc(sizeof(struct partie*),NB_CASES);
            chargementPartie(p1);
            partie=jouerPartie(p1);
        }
        else if(jeu==3)
        {
            sauvegardePartie(p1);
        }
        else
        {
            partie=jouerPartie(p1);
        }
        
    }while(jeu!=0);
    
    free(p1);
    
    return 0;
}
