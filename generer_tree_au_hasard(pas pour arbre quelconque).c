#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>

typedef struct tree  
{  //definition de la structure de l'arbre 'container'
	int data;
	char post[100];    
	struct tree *left;  
     struct tree *right;  
}treenode, *b_tree;  
  
 
b_tree insert_node(b_tree t,int node_ajout)  
{  
	b_tree newnode;  
	b_tree currentnode;  
	b_tree parentnode;  
	int tmp;

	newnode=(b_tree)malloc(sizeof(treenode));  
	//printf("%d\n",node_ajout);
	newnode->data=node_ajout;  
	newnode->right=NULL;  
	newnode->left=NULL;  
	int h=0;	
	sprintf((newnode->post),"%s(%d)","root_N",h);
	if(t==NULL)  
		return newnode;  
	else{  
		currentnode=t;
		h=1;  
		while(currentnode!=NULL){  
			parentnode=currentnode;
			tmp=parentnode->data;
			//printf("%d %d\n",(currentnode->data),node_ajout);  
			if((currentnode->data)>node_ajout){  
				currentnode=currentnode->left; /* continuer à gauche pour comparer la valeur*/ 
				sprintf((newnode->post),"%s(%d) de %d ","left_N",h++,tmp);
				
			}else{  
				currentnode=currentnode->right; /* continuer à droit pour comparer la valeur*/ 
				sprintf((newnode->post),"%s(%d) de %d","Right_N",h++,tmp);
			}  
		
			if(parentnode->data > node_ajout)  
				parentnode->left=newnode;  
			else  
				parentnode->right=newnode;  
		}
	}  
	printf("---------------\n");
	return t;  
}  
 
b_tree create_btree(int *list,int nb)  
{  
	b_tree t=NULL;  
	int i;  
	for(i=0;i<nb;i++){  
		t=insert_node(t,list[i]);
	}  
	return t;  
}  
 
void print_btree(b_tree t)  
{   
	if(t==NULL)  
	   return;  
	printf("%s:%d; ",t->post,t->data); 
	print_btree(t->left);  
	print_btree(t->right);  
  
}  

void main()  
{  
	b_tree t=NULL;  
	int i,index,n;
	int value;  
	int nodelist[200];  

	printf("please input the number of the node :\n");
	scanf("%d",&n);   
	index=0;  
	srand((int)time(0));
	for(index=0;index<n;index++){
		value=rand()%(199);
		nodelist[index]=value;
	}
	for(index=0;index<n;index++){		
		printf("%d ",nodelist[index]);
	}
	printf("\n__________\n");
	/*scanf("%d",&value);  
	while(value!='#'){  
		nodelist[index]=value;  
		index=index+1;  
		scanf("%d",&value);  
    }*/
		  
	t=create_btree(nodelist,index);  
	print_btree(t); 
	printf("\n"); 
}
