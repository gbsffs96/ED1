/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ed;

import java.util.*;

/**
 *
 * @author Gabriel
 */
public class ED {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
                Scanner s = new Scanner(System.in);
        
        int n1, n2;
            
            n1 = s.nextInt();
            int numeros1[] = new int[n1];
                                
            for(int i=0; i<n1; i++){
                
                numeros1[i] = s.nextInt();
            }
                            
            
            n2 = s.nextInt();
            int numeros2[] = new int[n2];
            
            for(int j=0; j<n2; j++){
                
                numeros2[j] = s.nextInt();
            }
            
            for(int q = 0; q < n1; q++){
                boolean t = true;
                for (int w = 0; w<n2; w++){
                if(numeros1[q] == numeros2[w]){
                    t = false;
                    break;
                    }
                }
                if (t){
                    System.out.print(numeros1[q]+" ");
                }
            }  
        // TODO code application logic here
    }
    
}
