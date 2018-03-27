#include <stdio.h>
#include <map>

using namespace std;

main()
{
   long list, lista,tempo;
   		pair<long, long> ptr1, ptr2,tmp;

  		map< long, pair<long,long> > endmap;

   scanf("%x %x %x",&list, &ptr1.first,&ptr1.second);
   scanf("%x %x %x",&lista, &ptr2.first,&ptr2.second);
  		endmap[list] = ptr1;
  	 	endmap[lista] = ptr2;

   while(scanf("%x %x %x",&tempo, &tmp.first, &tmp.second) == 3)
      endmap[tempo]=tmp;

   bool sana=true;
   tempo  = list;
   tmp = ptr1;
  
   while(tempo != lista)
   {
       pair<long,long> next = endmap[tmp.second];

       if(next.first == tempo)
       {
           tempo = tmp.second;
           tmp = next;
       }
       else
       {
           sana=false;
           break;
       }
   }
   printf("%s\n", sana?"sana":"insana");
	return 0;
}
