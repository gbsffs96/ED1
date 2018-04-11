#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trabalho = 0;
//Estrutura No
typedef struct node 
{
  int data;
  struct node * prev;
  struct node * next;
} no;

//Cria No
no * make_node (int new_data) 
{
    no * new_node = (no*) malloc(sizeof(no));
    new_node->data  = new_data; 
    new_node->prev  = NULL;
    new_node->next  = NULL;
    return new_node;
}

//Insere o no na cabeca
void insere_na_cabeca(int new_data, no ** front, no ** back, int *direction) 
{

   no * new_node = make_node(new_data);
   
   if ((*front) == NULL && (*back) == NULL) 
   {
      *front = new_node;
      *back = new_node;
      *direction = +1;
   } else 
   {
   	  //So quando tiver um elemento
   	  if(trabalho == 1)
   	     *back = *front;
				
      if (direction > 0) 
	  {
         new_node->prev = *front;
         (*front)->next = new_node;
         new_node->next = NULL;
         
      } else 
	  {
         new_node->next = *front;
         (*front)->prev = new_node;
         new_node->prev = NULL;
      }

      *front = new_node;         
      
   }
  
  trabalho++;
}

//Insere no final
void insere_atras(int new_data, no** front, no** back, int *direction) 
{

   no * new_node = make_node(new_data);
   
   if ((*front) == NULL && (*back) == NULL) 
   {
      *front = new_node;
      *back = new_node;
      *direction = +1;
   } else 
   {
      if (direction > 0) 
	  {
         new_node->next = *back;
         (*back)->prev = new_node;
         new_node->prev = NULL;
      } else 
	  {
         new_node->prev = *back;
         (*back)->next = new_node;
         new_node->next = NULL;
      }
 
      *back = new_node;
  }
  
  trabalho++;
}

//Remove da cabeca
void remove_da_cabeca(no** front, no** back, int *direction) 
{
   if (trabalho == 1) 
   {
      *front = NULL;
      *back = NULL;
      *direction = +1;
   } else 
   {
      if (direction > 0) 
	  {
         *front = (*front)->prev;
      } else 
	  {
         *front = (*front)->next;
      }
   }
  
   trabalho--;
  
}

//Remove do final
void remove_do_fim(no** front, no** back, int *direction) 
{
   if (trabalho == 1) 
   {
       *front = NULL;
       *back = NULL;
       *direction = +1;
   } else 
   {
      if (direction > 0) 
	  {
         *back = (*back)->next;
      } else 
	  {
         *back = (*back)->prev;
      }
   }
  
   trabalho--;
}

int main() 
{
  int q,  //Quantidade de linhas 
      n, direcao = +1;
 
  no * front = malloc(sizeof(no));
  no * back  = malloc(sizeof(no));
 
  char operacao[50];
  
  scanf("%d", &q);
  
  int z;

  for (z = 0; z < q; z++) 
  {
     strcpy(operacao, "");
     while (strcmp(operacao, "") == 0) 
        scanf("%s",operacao);
        
     if (strcmp(operacao, "back") == 0)
	 {
     
	    if (trabalho == 0)
           printf("No job for Ada?\n");
        else 
		{
           printf("%d\n", back->data);
           remove_do_fim(&front, &back, &direcao);
        }
     
	 } else if (strcmp(operacao, "front") == 0) 
	 {
     
	    if (trabalho == 0)
           printf("No job for Ada?\n");
        else 
		{
		   printf("%d\n", front->data);
           remove_da_cabeca(&front, &back, &direcao);
        }
     
	 } else if (strcmp(operacao, "reverse") == 0)
	 {
     
	    no * tmp = front;
        front = back;
        back  = tmp;
        direcao = direcao * (-1);
     
	 } else if (strcmp(operacao, "push_back") == 0)
	 {
     
	    scanf("%d", &n);
        insere_atras(n, &front, &back, &direcao);
    
	 } else if (strcmp(operacao, "tofront") == 0)
	 {
     
	  scanf("%d", &n);
      insere_na_cabeca(n, &front, &back, &direcao);
     
	 }
   } //Fim do for

}
