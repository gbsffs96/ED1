#include <stdio.h>
#include <stdlib.h>

typedef struct _no
{
	struct _no* proximo;
	struct _no* anterior;
	int valor;
} No;

No* lista;

//Adiciona o valor antes de p
//Se p n esiver criado, cria p tb
void addAntes()
{
	int indice;
	No*tmp= (No*)malloc(sizeof(No));
	
	if ((indice == 0) || (s->prim == NULL)){
		
		tmp -> valor = valor;
		tmp -> prox = s ->prim;
		s -> prim = tmp;
	}
	else{
		No *Nov = s ->prim;
		tmp -> valor = valor;
		
		int i;
		
		if (indice >= s-> tam)
			i = s -> tam - 1;
		else
			i = indice - 1;
			while (i--)
				Nov = Nov -> prox;
				
				tmp -> prox = Nov -> prox
	}
}


//Adiciona o valor depois de p
//Se p n esiver criado, cria p tb
void addDepois(long p, long valor)
{
	
}

//Retorna o valor antes de p
int getFirst(unsigned long long p)
{
	
}

//retorna o valor depois de p
int getSecond(long p)
{
	
}


int main(void)
{
   lista = malloc(sizeof(No));
   	
   long p1, p2,temp;
   long ptr1_first, ptr1_second, ptr2_first, ptr2_second, tmp_first, tmp_second;

   //map< long, pair<long,long> > endmap;

   scanf("%x %x %x", &p1, &ptr1_first, &ptr1_second);
   scanf("%x %x %x", &p2, &ptr2_first, &ptr2_second);

   addAntes(p1, ptr1_first);
   addDepois(p1, ptr1_second);
   addAntes(p2, ptr2_first);
   addDepois(p2, ptr2_second);
    	
   //endmap[p1] = ptr1_st;
   //endmap[p2] = ptr2_st;

   while( scanf("%x %x %x", &temp, &tmp_first, &tmp_second) == 3 )
   {
   	  addAntes(temp, tmp_first);
      addDepois(temp, tmp_second);
   }
    //endmap[temp]=tmp_st;

   int sana   = 1;
   temp       = p1;
   tmp_first  = ptr1_first;
   tmp_second = ptr1_second;
  
   while(temp != p2)
   {

	   long next_first = getFirst(tmp_second);
	   long next_second= getSecond(tmp_second);
       //pair<long,long> next_st = endmap[tmp_st.second];	   	

       if(next_first == temp)
       {
           temp       = tmp_second;
           tmp_first  = next_first;
           tmp_second = next_second;
       }
       else
       {
           sana = 0;
           break;
       }
   }
  
   printf("%s\n", sana?"sana":"insana");
  
   return 0;
}
