 
#include<stdio.h> 

int unlock();
// int tryAgain();

   int main(){
   int input,i,password;
   printf("Enter new password : ");
   scanf("%d",&password);
   printf("Match the password : ");
   scanf("%d",&input);

   if(input==password){
    unlock();
   }
else{
 for(i =0; ; i++){
   printf("Match the password : ");
   scanf("%d",&input);
   if(input ==password){
      unlock();
   }
 }

   }
   // return 0;
}


int unlock(){
   int i ,password ,input;
 printf("Congratulations ! Password Matched. \n \n \n");
 for(i=0; ; i++){
   int input,i,password;
   printf("Enter new password : ");
   scanf("%d",&password);
   printf("Match the password : ");
   scanf("%d",&input);

   if(input==password){
    unlock();
   }
else{
 for(i =0; ; i++){
   printf("Match the password : ");
   scanf("%d",&input);
   if(input ==password){
      unlock();
   }
 }
   }
   return 0;
 }
}
