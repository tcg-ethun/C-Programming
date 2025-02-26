 
#include<stdio.h> 

void unlock();
void tryAgain();

   int main(){
   int input,i,password;
   printf("Enter new password : ");
   scanf("%d",&password);
   printf("Match the password : ");
   scanf("%d",&input);

   if(input==password){
    unlock();
    return 0;
   }

else{
  for(i=0;  ;i++){
   if(input==password){
    unlock();
    return 0;
   } 
   tryAgain();
   printf("Enter the password Again : ");
   scanf("%d",&input);
  }
}
   return 0;
}

void unlock(){
 printf("Congratulations ! Password Matched . \n");
}
void tryAgain(){
 printf("Please try again :(  \n");

}
