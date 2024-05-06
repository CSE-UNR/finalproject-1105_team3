//Author: Abbygail Nerger & Simone Palanca 
//Date:4/29/24
//Objective: final project/ 2D Arrays

#include <stdio.h>


char dim();
int brighten(int* currentFile);
int crop(); 

int main(){
int choice1, choice2; 
	do{
		printf("\n**ERINSTAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("\nChoose from one of the options above: ");
		scanf("%d", &choice1);
		
		switch(choice1){
		case 1: // Reads the file
{
    char filename[100];
    printf("What is the name of the image file? ");
    scanf(" %s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not find an image with that filename.\n");
        break;
    }
    
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    
    int image[height][width];
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }
    
    fclose(file);
    printf("Image loaded successfully!\n");
    
   
    break;
}

		case 2:
    {
        char filename[100];
        printf("Enter filename: ");
        scanf("%s", filename);
        
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Failed to open file.\n");
            break;
        }
       
        char line[100]; 
        while (fgets(line, sizeof(line), file) != NULL) {
            for (int i = 0; line[i] != '\0'; i++) {
                char display_char;
                switch (line[i]) {
                    case '0':
                        display_char = ' ';
                        break;
                    case '1':
                        display_char = '.';
                        break;
                    case '2':
                        display_char = 'o';
                        break;
                    case '3':
                        display_char = 'O';
                        break;
                    case '4':
                        display_char = '0';
                        break;
                }
                printf("%c", display_char);
            }
            printf("\n"); // Move to the next line after printing each line
        }
        
        fclose(file);
    }
    break;
		case 3: 
			printf("\n\n**EDITING**\n");
			printf("1: Crop image\n");
			printf("2: Dim image\n");
			printf("3: Brighten iamge\n");
			printf("0: Return to main menu\n\n");
			printf("Choose from one of the options above: ");
			scanf("%d", &choice2);
			
				if(choice2 == 1){
					crop();
//					printf("\nWould you like to save the file? (y/n) ");
//					scanf(" %c", &response);
				}
				if(choice2 == 2){
					dim();
					printf("\nWould you like to save the file? (y/n) ");
//					scanf(" %c", &response);
				}
				if(choice2 == 3){
//					brighten(); 
					printf("\nWould you like to save the file? (y/n) ");
//					scanf(" %c", &response); 
				}
				if(choice2 == 0){
					printf("\n"); 
				}
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



char dim(){     
 char filename[100];
	   FILE *file = fopen(filename, "r");
        if (file == NULL) {
            printf("Failed to open file.\n");

        }
char line[100];
    for (int i = 0; line[i] != '\0'; i++) {
                char display_char;
                switch (line[i]) {
                    case '0':
                        display_char = ' ';
                        break;
                    case '1':
                        display_char = ' ';
                        break;
                    case '2':
                        display_char = '.';
                        break;
                    case '3':
                        display_char = 'o';
                        break;
                    case '4':
                        display_char = 'O';
                        break;
                }
                printf("%c", display_char);
            }
            printf("\n"); // Move to the next line after printing 
	}
	//fclose(file);

int brighten(int* currentFile){

}

int crop(){
int length, width. Lcol, Rcol, top, bottom;
	printf("The image you want to crop is %d x %d.\n", length, width);
	printf("The row and column values start in the upper lefthand corner.\n\n");
	printf("Which column do you want to be the new left side?");
	scanf("%d", Lcol); 
	printf("\nwhich column do you want to be the new right side?");
	scanf("%d", Rcol);
	printf("\nWhich row do you want to be the new top?");
	scanf("%d", top); 
	printf("\nWhich row do you you want to be the new bottom?");
	scanf("%d", bottom); 
	//display new image

}
