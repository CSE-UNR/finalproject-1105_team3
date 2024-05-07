//Author: Abbygail Nerger & Simone Palanca 
//Date:4/29/24
//Objective: final project/ 2D Arrays

#include <stdio.h>


char dim();
int brighten();
int crop(); 

char line[100];
FILE *file;
char filename[100];

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
    printf("What is the name of the image file? ");
    scanf("%s", filename); 
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not find an image with that filename.\n");
        break;
    }
    
    fclose(file);
    printf("Image loaded successfully!\n");
    
    break;
}

        case 2://displays image
{

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Sorry, no image to display\n");
        break;
    }

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
    
    fclose(file); // Close the file after reading
}
break;
		case 3: //edits the image
			printf("\n\n**EDITING**\n");
			printf("1: Crop image\n");
			printf("2: Dim image\n");
			printf("3: Brighten iamge\n");
			printf("0: Return to main menu\n\n");
			printf("Choose from one of the options above: ");
			scanf("%d", &choice2);
			
				if(choice2 == 1){
					crop();
					printf("\nWould you like to save the file? (y/n) ");
//					scanf(" %c", &response);
				}
				if(choice2 == 2){
					dim();
//					scanf(" %c", &response);
				}
				if(choice2 == 3){
					brighten(); 
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
	FILE *readFile = fopen(filename, "r");
	if (readFile == NULL) {
	    printf("Failed to open file.\n");
	    return 1;
	}
	
	 FILE *writeFile = NULL;
         int saveOption = 0;
	    

while (fgets(line, sizeof(line), readFile) != NULL) {
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
            printf("\n"); // Move to the next line after printing each line
        }
           fclose(file);

    // if user wants to save file
    char response;
    printf("\nWould you like to save the file? (y/n) ");
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        saveOption = 1;
    }

    if (saveOption) {
        printf("What do you want to name the image file? (include the extension)  ");
        scanf("%s", filename);

        writeFile = fopen(filename, "w");
        if (writeFile == NULL) {
            printf("Failed to open file for writing.\n");
            return 1;
        }

        // Write all number lines to the new file
        readFile = fopen(filename, "r");
        while (fgets(line, sizeof(line), readFile) != NULL) {
            fprintf(writeFile, "%s", line);
        }
        fclose(writeFile);
        printf("Image successfully saved!");
        printf("\n");
    }
    return 0;
}

int brighten() {
    FILE *readFile = fopen(filename, "r");
    if (readFile == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    FILE *writeFile = NULL;
    int saveOption = 0;

    // Read and display the image
    while (fgets(line, sizeof(line), readFile) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            char display_char;
            switch (line[i]) {
                case '0':
                    display_char = '.';
                    break;
                case '1':
                    display_char = 'o';
                    break;
                case '2':
                    display_char = 'O';
                    break;
                case '3':
                    display_char = '0';
                    break;
                case '4':
                    display_char = '0';
                    break;
                default:
                    display_char = line[i]; 
            }
            printf("%c", display_char);
        }
 
    }
     fclose(readFile);

    // if user wants to save file
    char response;
    printf("\nWould you like to save the file? (y/n) ");
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        saveOption = 1;
    }

    if (saveOption) {
        printf("What do you want to name the image file? (include the extension)  ");
        scanf("%s", filename);

        writeFile = fopen(filename, "w");
        if (writeFile == NULL) {
            printf("Failed to open file for writing.\n");
            return 1;
        }

        // Write all number lines to the new file
        readFile = fopen(filename, "r");
        while (fgets(line, sizeof(line), readFile) != NULL) {
            fprintf(writeFile, "%s", line);
        }
        fclose(writeFile);
        printf("Image successfully saved!");
        printf("\n");
    }
    return 0;
}

int crop(){
int Lcol, Rcol, top, bottom;

  FILE *readFile = fopen(filename, "r");
    if (readFile == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
int rows = 0, columns = 0; 
char ch; 
	
	fgets(line, sizeof(line),readFile);
	for(int i = 0; line[i] != '\0'; i++){
		if(line[i] != '\n'){
			columns++;,
			
/*	printf("1"); 
		for(int j = 0; line[j] = columns; j++){
			if(line[j]= j){
				printf(" ");
			}
		}
	printf("%d", columns);
*/	
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
	}
	printf("\n");
	while(fgets(line, sizeof (line), readFile) != NULL){
			rows++;

			
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
        printf("\n"); 
		} 
		rows++;

		
	//while (fgets(line, sizeof(line), file) != NULL) {
      // Move to the next line after printing each line
    
    
	printf("The image you want to crop is %d x %d.\n", rows, columns);
	printf("The row and column values start in the upper lefthand corner.\n\n");
	printf("Which column do you want to be the new left side?");
	scanf("%d", &Lcol); 
	printf("\nwhich column do you want to be the new right side?");
	scanf("%d", &Rcol);
	printf("\nWhich row do you want to be the new top?");
	scanf("%d", &top); 
	printf("\nWhich row do you you want to be the new bottom?");
	scanf("%d", &bottom); 
	//display new image

}
