#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//Estrutura No
struct node 
{
  int data;
  node * prev;
  node * next;
};

//Cria No
node * make_node (int new_data) 
{
    node * new_node = new node();
    new_node->data  = new_data; 
    new_node->prev  = NULL;
    new_node->next  = NULL;
    return new_node;
}

//Insere o no na cabeca
void insere_na_cabeca(int new_data, node ** front, node ** back, int & nb_elements, int & direction) 
{

   node * new_node = make_node(new_data);
   
   if ((*front) == NULL && (*back) == NULL) 
   {
      *front = new_node;
      *back = new_node;
      direction = +1;
   } else 
   {
      if (direction > 0) 
	  {
         new_node->next = *front;
         (*front)->prev = new_node;
      } else 
	  {
         new_node->prev = *front;
         (*front)->next = new_node;
      }
      
	  *front = new_node;
   }
   
   nb_elements++;
}

//Insere no final
void insere_atras(int new_data, node** front, node** back, int &nb_elements, int &direction) 
{

   node * new_node = make_node(new_data);
   
   if ((*front) == NULL && (*back) == NULL) 
   {
      *front = new_node;
      *back = new_node;
      direction = +1;
   } else 
   {
      if (direction > 0) 
	  {
         new_node->prev = *back;
         (*back)->next = new_node;
      } else 
	  {
         new_node->next = *back;
         (*back)->prev = new_node;
      }
 
      *back = new_node;
  }
  
  nb_elements++;
}

//Remove da cabeca
void remove_da_cabeca(node** front, node** back, int &nb_elements, int &direction) 
{
   
   if (nb_elements == 1) 
   {
      *front = NULL;
      *back = NULL;
      direction = +1;
   } else 
   {
      node * tmp_node;
      if (direction > 0) 
	  {
         tmp_node = (*front)->next;
         tmp_node->prev = NULL;
         (*front) = tmp_node;
      } else 
	  {
         tmp_node = (*front)->prev;
         tmp_node->next = NULL;
         (*front) = tmp_node;
      }
   }
   
   nb_elements -= 1;
}

//Remove do final
void remove_do_fim(node** front, node** back, int &nb_elements, int &direction) 
{
   if (nb_elements == 1) 
   {
       *front = NULL;
       *back = NULL;
       direction = +1;
   } else 
   {
      node *tmp_node;
      if (direction > 0) 
	  {
         tmp_node = (*back)->prev;
         tmp_node->next = NULL;
         (*back) = tmp_node;
      } else 
	  {
         tmp_node = (*back)->next;
         tmp_node->prev = NULL;
         (*back) = tmp_node;
      }
   }
   
   nb_elements -= 1;
}

int main() 
{
  int q,  //Quantidade de linhas 
      n, trabalho = 0, direcao = +1;
 
  node * front = NULL;
  node * back  = NULL;
 
  string operacao;
  
  cin >> q;

  for (int z = 0; z < q; z++) 
  {
     operacao = "";
     while (operacao == "") 
        cin >> operacao;
        
     if (operacao == "back") 
	 {
     
	    if (trabalho == 0)
           cout << "No job for Ada?\n";
        else 
		{
           cout << back->data << "\n";
           remove_do_fim(&front, &back, trabalho, direcao);
        }
     
	 } else if (operacao == "front") 
	 {
     
	    if (trabalho == 0)
           cout << "No job for Ada?\n";
        else 
		{
           cout << front->data << "\n";
           remove_da_cabeca(&front, &back, trabalho, direcao);
        }
     
	 } else if (operacao == "reverse") 
	 {
     
	    node * tmp = front;
        front = back;
        back  = tmp;
        direcao = direcao * (-1);
     
	 } else if (operacao == "push_back") 
	 {
     
	    cin >> n;
        insere_atras(n, &front, &back, trabalho, direcao);
    
	 } else if (operacao == "toFront") 
	 {
     
	  cin >> n;
      insere_na_cabeca(n, &front, &back, trabalho, direcao);
     
	 }
   } //Fim do for

}
