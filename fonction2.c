#include "couleursTerminal.h"
#include "projetc.h"

int priseDansDirectionPossible(struct partie *p, int ligne, int colonne, int horizontal,int vertical){
    if(vertical>=-1 && vertical<=1 && horizontal>=-1 && horizontal<=1)
    {
       
       
        int a=3;
	int j=3;
	ligne=ligne+horizontal;
	    colonne=colonne+vertical;
        
        while(ligne>=0 && ligne<NB_CASES_PAR_LIGNE && colonne>=0 && colonne<NB_CASES_PAR_LIGNE && a!=0 && a==j)
        {
           
            
            if(p->premierJoueurJoue==1)
            {
		if(j==3)
		{
                	if(getCase(p,ligne,colonne)!=PION_J1 && getCase(p,ligne,colonne)!=PION_ABS)
				{
                    			a++;
		    			j++;
				}
                	else
				{
                    			a=0;
				}
		}
		else
		{
			if(getCase(p,ligne,colonne)==PION_ABS)
			{
				a=0;
			}
			else if(getCase(p,ligne,colonne)==PION_J1)
			{
				a++;
			}
			else
			{
				a++;
				j++;
			}		
		}
            }
            else
            {
              if(j==3)
		{
                	if(getCase(p,ligne,colonne)!=PION_J2 && getCase(p,ligne,colonne)!=PION_ABS)
				{
                    			a++;
                    			j++;
				}
               		 else
				{	
	                    		a=0;
				}
		}
	      else
		{
				if(getCase(p,ligne,colonne)==PION_ABS)
					{
						a=0;
					}
				else if(getCase(p,ligne,colonne)==PION_J2)
					{
					  a++;
					}
				else
					{
						a++;
						j++;
					}
		}
		
            }
		ligne=ligne+horizontal;
	    colonne=colonne+vertical;
        }
		if(a!=j && a!=0)
		{	
			a=1;
		}
		else
		{
			a=0;
		}
        return a;
    }
    else
    {
        printf("Les valeurs saisies sont mauvaises !");
        exit(-1);
    }
}

int coupValide(struct partie *p, int ligne, int colonne){
    int a=0;
    int i,j;
    if(getCase(p,ligne,colonne)==0)
    {
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                a+=priseDansDirectionPossible(p,ligne,colonne,i,j);
            }
        }
    }
    if(a)
        return 1;
    else
        return 0;
}

void mouvementDansDirection(struct partie *p, int ligne ,int colonne, int horizontal, int vertical)
{
    if(coupValide(p, ligne, colonne))
    {
        if(p->premierJoueurJoue == 1 )
        {
            
            while(priseDansDirectionPossible(p, ligne, colonne, horizontal, vertical) == 1)
            {
                setCase(p, ligne+horizontal, colonne+  vertical, -1);
                ligne= ligne+horizontal;
                colonne= colonne+vertical;
            }
        }
        else if(p->premierJoueurJoue == 0)
        {
            
            while(priseDansDirectionPossible(p, ligne ,colonne ,horizontal, vertical) == 1)
            {
                setCase(p, ligne+ horizontal, colonne+ vertical, 1);
                ligne= ligne+horizontal;
                colonne= colonne+vertical;
            }
        }
    }
}

void mouvement(struct partie  *p , int ligne, int colonne)
{
    int i=-1,j=-1;
    if(coupValide(p,ligne,colonne))
    {
        while(i<=1)
        {
            while(j<=1)
            {
                if(priseDansDirectionPossible(p,ligne,colonne,i,j)){
                    mouvementDansDirection(p,ligne,colonne,i,j);
                    
                }
                j++;
            }
            i++;
            j=-1;
        }
        if(p->premierJoueurJoue == 1 )
            setCase(p,ligne,colonne,PION_J1);
        else
            setCase(p,ligne,colonne,PION_J2);
    }
    
}

int joueurPeutJouer(struct partie *p)
{
    int i=0,j=0,a=0;
    while(i<NB_CASES_PAR_LIGNE && a==0)
    {
        while(j<NB_CASES_PAR_LIGNE && a==0)
        {
       if(coupValide(p,i,j)==0)
	   {
            j++;
	   }
       else
	  {
            a=1;
	  }
        }
	j=0;
	i++;
    }
    return a;
}
