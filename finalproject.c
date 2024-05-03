//Author: Abbygail Nerger & Simone Palanca 
//Date:4/29/24
//Objective: final project/ 2D Arrays

#include <stdio.h>



int main(){
int choice1, choice2; 
	do{
		printf("**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above: ");
		scanf("%d", &choice1);
		
		switch(choice1){
		case 1:
		
			break;
		case 2:
		
			break;
		case 3: 
			printf("\n\n**EDITING**\n");
			printf("1: Crop image\n");
			printf("2: Dim image\n");
			printf("3: Brighten iamge\n");
			printf("0: Return to main menu\n\n");
			printf("Choose from one of the options above: ");
			scanf("%d", &choice2);
			break;
		case 0:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid option\nTry again!\n\n"); 
			break;
			}
		
	}while(choice1 != 0); 
	
	

	return 0; 
}
