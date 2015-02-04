#include "couleursTerminal.h"
#include "projetc.h"

int getCase(struct partie *p,int ligne,int colonne)
{
    if((ligne>=0 && ligne<=NB_CASES_PAR_LIGNE-1)&&(colonne>=0 && colonne<=NB_CASES_PAR_LIGNE-1))
    {
        return p->damier[ligne*NB_CASES_PAR_LIGNE+colonne];
    }
    else
        exit(-1);
}

void setCase(struct partie *p,int ligne,int colonne,int val)
{
    if((ligne>=0 && ligne<=NB_CASES_PAR_LIGNE-1)&&(colonne>=0 && colonne<=NB_CASES_PAR_LIGNE-1))
    {
        if(val>=PION_J1 && val<=PION_J2)
        {
            p->damier[ligne*NB_CASES_PAR_LIGNE+colonne]=val;
        }
        else
            exit(-1);
    }
    else
        exit(-1);
}

void changementJoueur(struct partie *p)
{
    if(p->premierJoueurJoue==0)
    {
        p->premierJoueurJoue=1;
    }
    else
    {
        p->premierJoueurJoue=0;
    }
}

struct partie* creerPartie()
{
    struct partie *p=(struct partie*)malloc(sizeof(struct partie*));
    
    if(p==NULL){
        printf("La memoire est saturée \n");
        exit(1);
    }
    p->premierJoueurJoue=1;
    int i;
    for(i=0;i<NB_CASES;i++)
    {
        if(i==27 ||  i==36)
        {
            p->damier[i]=PION_J1;
        }
        else if(i==28 || i==35)
        {
            p->damier[i]=PION_J2;
        }
        else
        {
            p->damier[i]=PION_ABS;
        }
    }
    
    printf("Que le premier joueur entre son nom  :\t");
    scanf("%s",p->nomJ1);
    printf("Que le deuxieme joueur entre son nom :\t");;
    scanf("%s",p->nomJ2);
    
    return p;
}



void affichage1(struct partie *p)
{
    int i=0;
    for(i=0;i<NB_CASES;i++)
    {
        if(i%NB_CASES_PAR_LIGNE==7)
        {
            printf("%d\n",p->damier[i]);
        }
        else
        {
            if(p->damier[i+1]==PION_J1)
            {
                printf("%d ",p->damier[i]);
            }
            else
            {
                printf("%d  ",p->damier[i]);
            }
        }
    }
}

/*!
 * Fonction affichant le damier sur le terminal
 *
 * \param p : pointeur sur la partie que l’on souhaite afficher
 */
void affichage2(struct partie *p)
{
    int a=0,i,k,m=5,c=6,n=NB_CASES_PAR_LIGNE;
    char ch;
    while(a<n)
    {
        for (i=0;i<=3;i++)
        {
            for (k=0;k<n*m+1;k++) //affiche la case
            {
                if(getCase(p,k/m,a)==PION_J2)
                    ch='N';
                else if(getCase(p,k/m,a)==PION_J1)
                    ch='B';
                else
                    ch=' ';
                if ( (i==0 || k%m==0 ||k==n*m)){
                    printf("*");
                }
                
                else if(k%m==2 && i%m==2)
                {
                    printf("%c",ch);
                }
                else // affiche l'espace
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        a++;
    }
    for(i=0;i<n*m+1;i++) // affiche la derniere ligne
        printf("*");
    printf("\n");
}

/*!
 * Fonction affichant le damier sur le terminal
 *
 * \param p : pointeur sur la partie que l’on souhaite afficher
 */
void affichage3(struct partie *p)
{
    int i=0,j=0,f,k=0,r;
    changerCouleurFondTerminal(9);
    for(i=0;i<NB_CASES+17;i++)
    {
        f=48+i; //chiffre en ascii
        if(j==0)
        {
            if(i==8 && i!=0)
            {
                printf("  %c \n",f);
                j++;
            }
            
            else if(i!=0)
            {
                printf("  %c",f);
            }
        }
        
        
        else if(j%2==0 &&j!=0)
            
        {   if(i%9==0)
        {
            r=97+j-1; //lettre en ascii
            printf("%c",r);
        }
        else if(i%(NB_CASES_PAR_LIGNE+1)==8)
        {
            changerCouleurFondTerminal(6);
            if(p->damier[k]==PION_ABS)
            {
                printf("   ");
            }
            else if(p->damier[k]==PION_J2)
            {
                changerCouleurEcritureTerminal(0);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            else
            {
                changerCouleurEcritureTerminal(7);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            changerCouleurFondTerminal(9);
            printf("\n");
            j++;
            k++;
        }
        else if(i%2==0)
        {
            changerCouleurFondTerminal(6);
            if(p->damier[k]==PION_ABS)
            {
                printf("   ");
            }
            else if(p->damier[k]==PION_J2)
            {
                changerCouleurEcritureTerminal(0);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            else
            {
                changerCouleurEcritureTerminal(7);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            k++;
        }
        else if(i%2==1)
        {
            changerCouleurFondTerminal(5);
            if(p->damier[k]==PION_ABS)
            {
                printf("   ");
            }
            else if(p->damier[k]==PION_J2)
            {
                changerCouleurEcritureTerminal(0);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            else
            {
                changerCouleurEcritureTerminal(7);
                printf("###");
                changerCouleurEcritureTerminal(9);
            }
            k++;
        }
            
        }
        else
        {
            if(i%9==0)
            {
                r=97+j-1;
                printf("%c",r);
            }
            else if(i%(NB_CASES_PAR_LIGNE+1)==8)
            {
                changerCouleurFondTerminal(5);
                if(p->damier[k]==PION_ABS)
                {
                    printf("   ");
                }
                else if(p->damier[k]==PION_J2)
                {
                    changerCouleurEcritureTerminal(0);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                else
                {
                    changerCouleurEcritureTerminal(7);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                changerCouleurFondTerminal(9);
                k++;
                printf("\n");
                j++;

            }
            else if(i%2==0)
            {
                changerCouleurFondTerminal(6);
                if(p->damier[k]==PION_ABS)
                {
                    printf("   ");
                }
                else if(p->damier[k]==PION_J2)
                {
                    changerCouleurEcritureTerminal(0);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                else
                {
                    changerCouleurEcritureTerminal(7);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                k++;
            }
            else
            {
                changerCouleurFondTerminal(5);
                if(p->damier[k]==PION_ABS)
                {
                    printf("   ");
                }
                else if(p->damier[k]==PION_J2)
                {
                    changerCouleurEcritureTerminal(0);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                else
                {
                    changerCouleurEcritureTerminal(7);
                    printf("###");
                    changerCouleurEcritureTerminal(9);
                }
                k++;
            }
        }
    }
}
