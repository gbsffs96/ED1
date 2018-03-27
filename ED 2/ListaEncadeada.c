#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{    int valor;
    struct _no *prox;
} No;

typedef struct _lista
{    No *prim;
    int tam;
} Lista;


void Deletar(Lista *s, int indice)
{    No *Nov = s->prim;

    if((indice >= s->tam) || (s->prim == NULL))
		
		return;
		
    else if(indice == 0){ 
	  
	 s->prim = Nov->prox;
        free(Nov);
    }
    else{    
	
		No *Nov2;

        int i = indice - 1;
        
		while(i--) 
		Nov = Nov->prox;

        Nov2 = Nov->prox->prox;
        free(Nov->prox);
        Nov->prox = Nov2;
    }

    (s->tam)--;
}
void Inserir(Lista *s, int valor, int indice)
{    No *tmp = (No*)malloc(sizeof(No));

    if((indice == 0) || (s->prim == NULL)){    
    
	tmp->valor = valor;
        tmp->prox = s->prim;
        s->prim = tmp;
    }
    else{    
	
		No *Nov = s->prim;
        tmp->valor = valor;

        int i;
       
	    if(indice >= s->tam) 
			i = s->tam - 1;
        else 
			i = indice - 1;
        while(i--) 
			Nov = Nov->prox;

        tmp->prox = Nov->prox;
        Nov->prox = tmp;
    }

    (s->tam)++;
}


void Exibir(Lista *s)
{    if(s->prim == NULL) 
		printf("empty\n");
    else{   
		 No *Nov = s->prim;

        while(Nov != NULL){  
		
		  printf("%d ", Nov->valor);
            Nov = Nov->prox;
        }
        printf("\n");
    }
}

int main(){    

	Lista *s = (Lista*)malloc(sizeof(Lista));
    s->prim = NULL;
    s->tam = 0;

    char opc;
    int Mem, Num;

    while(scanf("%c", &opc) && (opc != 'q'))
    {    switch(opc)
        {    case 'f':
                scanf("%d", &Num);
                Inserir(s, Num, 0);
                break;
            case 'i':
                scanf("%d %d", &Mem, &Num);
                Inserir(s, Num, Mem);
                break;
            case 'r':
                Deletar(s, 0);
                break;
            case 'd':
                scanf("%d", &Mem);
                Deletar(s, Mem);
        }

        scanf("%c", &opc);
        Exibir(s);
    }
}
