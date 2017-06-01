#define MaxNbfile 1000


int index1=1;

char file[MaxNbfile];


// depoter des donnees dans des fichiers .gv pour dessiner des graphes 
void stock(char **strings,int n){
	FILE *fp;
	int i,j;
	
	for(i=0;i<cp_tree;i++){
		sprintf(file,"binarytree%d.gv",i);
		fp=fopen(file,"wa+");
	
		fprintf(fp,"graph G {\n\tnodesep=0.3;\n\tranksep=0.2;\n\tmargin=0.1;\n\tnode [shape=circle];\n\tedge [arrowsize=0.8];\n\t0;\n" );


			for(j=0;j<n-1;j++){		
				fprintf(fp,"\t%s;\n",strings[index1+j]);
				//printf("fich %d index 1 --: %d\n",i,index2+j);
			}index1=(n-1)*(i+1)+1;
			//printf("index 2 : %d\n",index1);
				
			
		fprintf(fp,"\n}");
	fclose(fp);	
	}
}



void shell(int cp_tree){
	int i;
	char shells[100];
	/*system("gcc arbre_parenthese.c -o arbre_parenthese");
	system("./arbre_parenthese");*/
	printf("le nombre des abres generes pour dessiner: %d\n",cp_tree);	
	for(i=0;i<cp_tree;i++){
		//sprintf(shells,"dot binarytree%d.gv|gvpr -c -f t.gv|neato -n -Tpng -o binarytree%d.png",i,i);
		sprintf(shells,"dot -Tgif binarytree%d.gv -o binarytree%d.gif",i,i);
		system(shells);

	}
}
