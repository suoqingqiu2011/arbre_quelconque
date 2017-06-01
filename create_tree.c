


typedef struct Hauteur{
    int high;
}Hauteur;

typedef struct data{
    int nb_compteur;
}Data;


int p=1;
int cp_tree=1;

void comb1(Data *D,int **T,int i,int *H,int n,int (*tab)[2],int cp){
    int j,k;

    for(j=0;j<H[i-1];j++){
        for(k=0;k<H[i];k++){
            //printf("%d-%d \n",T[i-1][j], T[i][k]);
            tab[cp][0]=T[i-1][j];
            tab[cp][1]=T[i][k];
            //printf("tab[%d][0]-tab[%d][1] :%d-%d \n",cp,cp,tab[cp][0], tab[cp][1]);
            cp++;
        }
    }
    D->nb_compteur=cp;
    //printf("nb_compteur %d:%d \n",i,D->nb_compteur);
}
/*
//la fonction pour factorielle
int liancheng(int n){
    int res=1,i;
    for(i=1;i<=n;i++)
    res*=i;
    return res;
}
*/

void printArray(int *a, int len,int (*tab)[2],int **T,int hauteur,int *H,char (*strings)[100]){
    int i,j;
    int s1;
    int haut=0;

    int *cpt;
    cpt=malloc(sizeof(int*)*hauteur);
/*
    //tous les possibilites de combinations
  	for(i=0;i<len;i++){
        printf("%d-%d ",tab[a[i]][0],tab[a[i]][1]);
     }printf("\n---------------------\n");
*/
    //verifier si les sommets soient bien les succesives
    for(i=0;i<hauteur;i++){
        cpt[i]=0;
    }
    while (haut<hauteur){
        for(i=0;i<len;i++){
            s1=tab[a[i]][0];  // tab[a[i]][0] est le père et tab[a[i]][1] est son fils  comme un arc en format 'père-fils'
            for(j=0;j<H[haut];j++){  // H[haut] est  le nombre des sommets à la hauteur 'haut'
                //printf("T[%d][%d]:%d\n",haut,j,T[haut][j]);
                if(s1==T[haut][j]&&haut<hauteur){  // T[haut][j] est le numéro du sommet distribués à chaque niveau
                    //printf("s1:%d T:%d\n",s1,T[haut][j]);
                    cpt[haut+1]++;
                     //printf("cpt[%d] %d \n",haut+1,cpt[haut+1]);
                }
            }
        }//printf("-------------\n");
        ++haut;
    }


    for(haut=0;haut<hauteur;haut++){
        //printf("cpt[%d] %d h[%d] %d\n",haut+1,cpt[haut+1],haut+1,h[haut+1]);
        if(cpt[haut+1]==H[haut+1]){
                //printf("cpt[%d] %d h[%d] %d\n",haut+1,cpt[haut+1],haut+1,h[haut+1]);
                if(haut+1==hauteur-1){
                    goto here;
                }
                //continue;
            }else{
                goto there;
            }

    }goto there;

    here:
     for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            //printf("tab[%d][1] %d tab[%d][1] %d\n",a[i],tab[a[i]][1],a[j],tab[a[j]][1]);
            if(tab[a[i]][1]==tab[a[j]][1]){
                goto there;
            }
        }
    }printf("\n# Enfin,l'arbre '%d' de hauteur %d est:\n",cp_tree,hauteur);
    for(i=0;i<len;i++){
        printf("%d-%d ",tab[a[i]][0],tab[a[i]][1]);
		sprintf((strings[p]),"%d -- %d",tab[a[i]][0],tab[a[i]][1]);
		//printf("strings[%d] : %s\n",p,strings[p]);
     	p++;
	}; 
	printf(" --- Compteur de tree: %d\n",cp_tree++);
     printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    there:;

	
}

void combine(int *Array, int nb_array,int apos,int *btmp,int nbarc,int bpos,int (*tab)[2],int **T,int hauteur,int *H,char (*strings)[100])
{ //combine(Array,nb_array,0,btmp,nb_arc,0,tab,T,hauteur,H,strings);
    int ai;
    if(bpos>=nbarc){
        printArray(btmp,nbarc,tab,T,hauteur,H,strings);

    }else{
        for(ai=apos; ai<nb_array; ai++){
            btmp[bpos]=Array[ai];
            combine(Array,nb_array,ai+1,btmp,nbarc,bpos+1,tab,T,hauteur,H,strings);
        }
    }
}

void create_tree(int *H,Hauteur *haut_t,int n_total,char (*strings)[100]){
/*int main(){
   int *H;
    H=malloc(sizeof(int*));
     H[0]=1;
     H[1]=4;
     H[2]=2;

     Hauteur haut_t;
    int n_total=7;
    haut_t.high=3;
*/
    int n=n_total;
    int hauteur=haut_t->high;

    int i=0,num=0;
    int j;

     int n1=10000,n2=n-1;
     int **T;
	T=malloc(sizeof(int*)*n1);
	for (i = 0; i < n1; i++){
		T[i]=malloc(sizeof(int)*n2);
	}

    for(i=0;i<hauteur;i++){
        for(j=0;j<H[i];j++){
            T[i][j]=num; // les numéros des sommets sont distribués à chaque niveau
            num+=1;
        }
    }
/*
    for(i=0;i<3;i++){
        for(j=0;j<H[i];j++){
            printf("T[%d][%d]:%d \n",i,j,T[i][j]);
        }
    }*/
    int (*tab)[2];
	tab=malloc(sizeof(int*)*n1);
    //int cp=0;
    Data D;
    D.nb_compteur=0;

    for(i=1;i<hauteur;i++){
        comb1(&D,T,i,H,n,tab,(D.nb_compteur));
    }

   // printf("D->nb_compteur: %d\n",D.nb_compteur);

	
    printf("--------------\n");
    printf("Tous les possibilites de combinations avec la hauteur %d:\n",hauteur);
    for(i=0;i<D.nb_compteur;i++){
        for(j=0;j<2;j++){
         printf("%d ",tab[i][j]);
        }printf("| ");
    }printf("\n");
    //printf("compteur: %d\n",D.nb_compteur);
    printf("--------------\n");

    int nb_arc=n-1, nb_array=D.nb_compteur;
    int * btmp=(int*)malloc(sizeof(int)*nb_arc);
    int *Array;

    Array=(int *) malloc(sizeof(int)*nb_array);
    for(i=0;i<nb_array;i++){
        Array[i]=i;
    }

    /*int a,b,c,total;
     a=liancheng(nb_array);
     b=liancheng(nb_array-nb_arc);
     c=liancheng(nb_arc);
     // printf("a=%d,b=%d\n",a,b);
     total=a/b/c;*/
    combine(Array,nb_array,0,btmp,nb_arc,0,tab,T,hauteur,H,strings);
   // return 0;
}
