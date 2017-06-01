#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "create_tree.c"
#include "depot_shell.c"

#define NON_ARC 888888
#define MaxNumSom 100

#define bug printf(" i'm here %d\n",__LINE__);
/*
typedef struct Hauteur{
    int high;
}Hauteur;
*/

int c=1;

void verifier_print(int *H,Hauteur *haut_t){
    int j;
    printf("Verifier le nb des somments dans chaque niveau:\n");
    for(j=0;j<(haut_t->high);j++){
        printf(" T[%d]:%d ",j,H[j]);
    }printf("\n---------------------------\n");
}

void ranking(int *H,int *r,int *p,int n,int m,int n_total,Hauteur *haut_t,char (*strings)[100]){

    int ht=0,a;
    if(m==1){ //il reste un seul place où on peut mettre les chiffres
        if(r[0]==1){
            printf("**********************************************************\n  tree :\n ");
            for(;r!=p;++r){
                a=*r;
                //printf("%d",*r);
                H[ht]=a; 
                //printf(" T[%d]:%d ",ht,H[ht]);
                ht++;
            }
             H[ht]=n; //le restant est la dernier element
             haut_t->high=ht+1;
            //printf(" T[%d]:%d \n",ht,H[ht]); 
 
            //printf("%d ",n);
            //printf("compteur:%d\n",c++);
           verifier_print(H,haut_t);
            printf("\n Le hauteur de l'arbre est :%d\n",haut_t->high);
            create_tree(H,haut_t,n_total,strings);
        }
    }else{
        for(*p=1;*p<=n-1;++*p){
            ranking(H,r,p+1,n-*p,m-1,n_total,haut_t,strings);
        }
    }
}

void g(int *H,int n,int m,int n_total,Hauteur *haut_t,char (*strings)[100]){
    int r[m];

    ranking(H,r,r,n,m,n_total,haut_t,strings);
}



int main(){

    int i,nb;
    
    Hauteur haut_t;
    int *H;
    H=(int*)malloc(sizeof(int)*nb);

	char strings[10000][100];

    printf("Are you ready? Go!!!\nPlease insert the number of vertice\n");
    scanf("%d",&nb);
    if(nb<=1){
        printf("%d\n",nb);
    }else{
        for(i=2;i<=nb;i++){
           
            g(H,nb,i,nb,&haut_t,strings);
             //printf("hauteur: %d \n",haut_t.high);

            printf("\n");
        }
    }
	cp_tree-=1;
	printf("cp_tree:%d \n",cp_tree);
	
	stock(strings,nb);
	shell(cp_tree);

    return 0;
}

