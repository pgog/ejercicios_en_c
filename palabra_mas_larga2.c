#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int contador = 0;
int maximo=0;
int n_caracteres;
char m_larga[250];
int inicio=0;

void LongestWord(char * sen) {
  n_caracteres= strlen(sen);
  

   
  for(int i=0; i<n_caracteres; i++){
    if (48<= sen[i] && sen[i] <= 57) {
      contador+=1;
        if (inicio==0){
          inicio= i;

        }
      

    }else if (65<= sen[i] && sen[i] <= 90){
      contador+=1;
      if (inicio==0){
          inicio= i;
        }
      
    }else if (97<= sen[i] && sen[i] <= 122){
      contador+=1;
      if (inicio==0){
          inicio= i;
        }

    }else{
        printf("else contador %d\n", contador);
      if (contador<maximo){inicio=0;}
      contador=0;
      }
  
    while(contador>maximo){
      maximo=contador;
    }
  } 

  printf("inicio %d max %d\n",inicio,maximo);
  if(inicio==1){
    inicio=0;
    for (int j=0;j<maximo;j++){
    
          m_larga[j]=sen[j];
      }

      
      printf("%s\n",m_larga);

    }else{

    for (int j=0;j<maximo;j++){
        
      
            m_larga[j]=sen[j+inicio];
            printf("M_larga: %s\n", m_larga);
        }

    }
      
      printf("%s\n",m_larga);
     

  // code goes here  
  //printf("%s", sen);

}


int main(void) { 
   
  // keep this function call here
   char * intento = "vamddd  nue";
  LongestWord(intento);
  return 0; 
}