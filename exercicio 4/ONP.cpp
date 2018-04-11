#include<stdio.h>
#include<string.h>
#include<ctype.h>

int indice = -1;

char pilha[200];

//Empilha os valores na pilha
void ins(int num)
{
    pilha[++indice]=num;
}

//Remove do topo da pilha
char remov()
{
    return pilha[indice--];
}

int main()
{
    //Declaracao da expressao a ser lida
    char expressao[401];
    int t,      //Quantidade de expressoes a serem lidas 
	    i,      //Variavel de controle do laco  
		tam;    //Tamanho da expressao
 
    scanf("%d",&t);
    
    //Ler as expressoes
	while(t--)
    {
    	//Scanf para ler a expressao
    	scanf("%s",expressao);
    	
    	//Pega o tamanho da expressao
        tam = strlen(expressao);
        
        //Checa a expressao: precendencia de operadores, parenteses...
		for(i=0;i<tam;i++)
        {
        	//Se eh uma letra
            if(isalpha(expressao[i]))
               printf("%c",expressao[i]);
            else if(expressao[i]=='(')
               ins('(');
            else if(expressao[i]==')')
            { 
				while(pilha[indice]!='(')
                     printf("%c",remov());
                
				remov();

            }
            else if(expressao[i]=='^')
            {
                while(pilha[indice]=='^')
                    printf("%c",remov());
                
				ins(expressao[i]);
            }
            else if(expressao[i]=='/'||expressao[i]=='*')
            {
                while(pilha[indice]=='/'||pilha[indice]=='*'||pilha[indice]=='^')
                    printf("%c",remov());
                
				ins(expressao[i]);
            }
            else if(expressao[i]=='+'||expressao[i]=='-')
			{
                while(pilha[indice]!='(')
                   printf("%c",remov());
            
				ins(expressao[i]);
            }
        } //Fim do for

        printf("\n");
     
    }

    return 0;

}
