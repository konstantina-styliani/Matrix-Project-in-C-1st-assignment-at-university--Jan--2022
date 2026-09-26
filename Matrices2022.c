#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 200

struct matrix{
    
    int rows;
    int collumns;
    float **Matrix;
    char *name;

};

/*NOT
    struct multiply{

    int result;
    float **multiply

}*/

typedef struct multiply MU;
typedef struct matrix MATRIX;
void name_matrix(MATRIX *m); //Function for giving a name to a Matrix
void fill_matrix(MATRIX *m); //Function for filling a Matrix with elements
void dimentions_matrix(MATRIX *m); //Function for defining the dementions of the Matrix
void print_matrix(MATRIX x); //Function for printing the Matrix

/*NOT
char* return_name(MATRIX x); //Function for returning the names of the created matrices
void free_matrix(MATRIX x); //Function for freeing the allocated memory
void printRow(int len, int row[]);*/

int main(int argc, char *argv[]) {

    char choice1, choice2, choice4, choice5, choice6;
   
    int r[30];
    MATRIX *matrix;
    int nm;
    int i, j;
   
    int Matrix1[2][5];
    int Matrix2[2][5];

    /*NOT
    int r1, r2, r3, r4, r5;
    int scalar;
    char mmatrix[SIZE];
    char one[] = "Matrix1";
    char two[] = "Matrix2";
    char file[] = "FileMatrix";
    MU m1, m2, m3, m4, m5;*/

    char c;
    char *filename;
    int col = 0, row = 1 , col1 = 0;
    int count = 1;
    int **array;
    FILE *fp;

    //Initiating two matrices with random elements, in order for them to be used for the operations(These are the "Built-in" Matrices)
    for(i = 0; i < 2; i++){
        for(j= 0; j < 5; j++){
            Matrix1[i][j] = rand()%100;
        }
    } 

    for(i = 0; i < 2; i++){
        for(j= 0; j < 5; j++){
            Matrix2[i][j] = rand()%100;
        }
    } 

    do {
        //Main navigation menu
        system("cls");
        printf("-------------------------------\n");
        printf("Main Menu\n");
        printf("[C/c]Create Matrix/Matrices\n");
        printf("[V/v]View existing Matrices\n");
        printf("[O/o]Matrices operations\n");
        printf("[L/l]Load Matrix from file\n");
        printf("[Q/q]Quit\n");
        printf("-------------------------------\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice1);

        switch (choice1) {
            case 'C':
            case 'c':
                system("cls");
                printf("           ***           \n");
                printf("Enter the wanted number of matrices that you want to create\n");
                scanf("%d", &nm);
                matrix = malloc(sizeof(MATRIX) * nm);
                    if(!matrix){
                        printf("Failure of memory allocation\n");
                        exit(0);
                    }                     

					i = 0;
                    while (i < nm) {
                        system("cls");
                        printf("-------------------------------\n");
                        printf("Choose an action for matrix number %d.\n", i+1);
                        printf("[N/n]Define a name for the matrix\n");
                        printf("[D/d]Define the dimentions of the matrix\n");       
                        printf("[F/f]Fill the matrix \n");      
                        printf("[P/p]Print Matrix\n");                
                        printf("[N/n]Next Matrix\n");
                        printf("-------------------------------\n");
                        printf("Enter your choice:\n");
                        scanf(" %c", &choice2);

                            switch (choice2) {
                                case 'N':
                                case 'n':
                                    name_matrix(&matrix[i]);
                                    break;

                                case 'D':
                                case 'd':
                                    dimentions_matrix(&matrix[i]);
                                    break;

                                case 'F':
                                case 'f':
                                    fill_matrix(&matrix[i]);
                                    break;
                                
                                case 'P':
                                case 'p':
                                    print_matrix(matrix[i]);
                                    i++;
                                    break;

                                case 'M':
                                case 'm':

                                i++;
                                break;
                                    
                                default:
                                    printf("Invalid input\n");
                        }
                        system("pause");
                    }
            break;

            case 'V':
            case 'v':
                system("cls");
                printf("     ");
                printf("Available Matrices:\n");
                printf("***********************\n");
                printf("[C/c]Created matrices\n");
                printf("[B/b]Built-in matrices\n");
                printf("[F/f]Matrice from file\n");
                printf("[M/m]Main Menu");
                printf("Enter your choice\n");
                printf("***********************\n");
                scanf(" %c", &choice4);

                i = 0;

                while ((choice4 != 'M') && (choice4 != 'm'))
                    switch(choice4){
                        case 'C':
                        case 'c':
                            while (i < nm){
                                print_matrix(matrix[i]); //printing the matrices from [C/c]
                                i++;
                            }
                        break;

                        /*NOT
                        case 'B':
                        case 'b':
                            int width = 5;

                            for (i = 0; i < width; i++) {
                                printf("|\t");
                                printRow(width, Matrix1[i]);
                                printf("\t");
                                printRow(width, Matrix2[i]);
                                printf("\t|\n");
                            }
                        break;*/

                        case 'F':
                        case 'f':
                            for(i = 0; i < row; i++) {
                                for(j = 0; j < col; j++) { 
                                    printf("%d\t ", array[i][j]);
                                }
                                printf("\n");
                            fclose(fp);
                            }
                        break;

                        case 'M':
                        case 'm':
                        
                        break;

                        default:
                            printf("Enter a valid option\n");
                        break;
                    }
                    system("pause");
            break;

            case 'L': 
            case 'l': 
            
                filename = malloc(sizeof(char) * SIZE);
                if (!filename){
                    printf("Failure of memory allocation");
                    exit(0);
                }

                printf("Enter the path of the file that you want to read\n");
                scanf("%s", filename);

                fp = fopen(filename, "r");
                if(fp == NULL){
                    printf("%s file not found\n", filename);
                    exit(0);
                }
                //Calculating the no. of rows and columns in the text file 
                do {  
                    c = getc(fp);
                    if(c == ' ')
                        col1++;
                    if(c == '\n'){
                        row++;
                    }
                } while (c != EOF);

                col = ((col1 / 2) + 1);

                if (count >= 2)
                    col = ((col1 / count) + 1);
                else
                    col = (col1 + 1);

                array = (int**)malloc(sizeof(int*) * row);
                if(!array){
                    printf("Failure of memory allocation\n");
                    exit(0);
                }

                for(i = 0; i < row; i++){
                    array[i] = (int*)malloc(sizeof(int) * col);
                    if(!array[i]){
                        printf("Failure of memory allocation\n");
                        exit(0);
                    }
                }

                printf("%dx%d\n", row, col);

                rewind(fp);
                //Filling the array:
                for( i= 0; i < row; i++) {
                    for(j = 0; j < col; j++) {
                        fscanf(fp, "%d", &array[i][j]);
                    }
                }
                
            break;

           /*NOT
            case 'O':
            case 'o':

                printf("*******************\n");
                printf("      ");
                printf("Operations:\n");
                printf("[M/m] Multiplication\n");
                printf("[A/a] Addition\n");
                printf("[S/s] Substraction\n");
                printf("Choose your option\n");
                scanf("%c", &choice5);

                switch(choice5){
                    
                    case 'M':
                    case 'm':
                        printf("***************\n");
                        printf("[N/n] Scalar multiplication\n");
                        printf("[M/m] Multiply two matrices together\n");
                        printf("Choose your option\n");
                        printf("***************\n");
                        scanf("%d", &choice6);

                        switch(choice6){

                            case 'N':
                            case 'N':

                            printf("You have to choose one of the matrices\n");
                            scanf("%s", &mmatrix);
                            printf("Now choose a number to multiply it with the matrix\n");
                            scanf("%d", &scalar);

                            r1 = strcmp(mmatrix, one);
                            r2 = strcmp(mmatrix, two);
                            r3 = strcmp(mmatrix, file);
                            for(i = 0; i <nm; i++) {
                                return_name(matrix[i]);
                                r[i] = strcmp(mmatrix, return_name(MATRIX x));
                            }

                            if (r1 == 1){
                                for(i = 0; i < 2; i++){
                                    for(j= 0; j < 5; j++){
                                        m1.multiply = (Matrix1[i][j] * scalar);
                                    }
                                } 
                            }
                                m1.multiply = (Matrix1 * number);

                            if (r2 == 1)
                                m2.multiply = (Matrix2 * number);

                            if (r3 == 1)
                                m3.multiply = (array * number)
                        }
                }
            break;*/

            case 'Q':
            case 'q':

                printf("The program is terminating\n");
                exit(0);
        }    
        system("pause");
    }while(1);
    
return(0);
}


void name_matrix(MATRIX *m){

    m -> name = malloc(sizeof(char) * SIZE);
    if (!m -> name){
        printf("Failure of memory allocation");
        exit(0);
    }

    printf("Enter the name:\n");
    scanf("%s", m -> name);
 
}

void dimentions_matrix(MATRIX *m){

    int i;

    printf("Enter the wanted number of rows and collumns(ixj)\n");
    scanf("%dx%d", &(m -> rows), &(m -> collumns));


    m -> Matrix =(float **) malloc(sizeof(float*) * (m -> rows));
    if (!m -> Matrix){
        printf("Failure of memory allocation");
        exit(0);
    }
  
    for (i = 0; i < (m -> rows); i++){
        m -> Matrix[i] = (float *) malloc(sizeof(float) * (m -> collumns));
        if (!m -> Matrix[i]){
        	printf("Failure of memory allocation");
        	exit(0);
    	}
    }
}

void fill_matrix(MATRIX *m){

    char choice3;
    int i, j;

    srand(time(NULL));
	
	do{
        system("cls");
        printf("-------------------------------\n");
        printf("Choose one of the following options:\n");
        printf("[R/r]Fill the matrix with random numbers\n");
        printf("[W/w]Fill the matrix with the numbers that you want\n");
        printf("[N/n]Next Matrix\n");
        printf("Enter you choice\n");
        scanf(" %c", &choice3);

        switch (choice3){
            case 'R':
            case 'r':
                for (i = 0; i < (m -> rows); i++){
                    for (j = 0; j < (m -> collumns); j++){
                        m -> Matrix[i][j] = rand()%1000;
                    }
                }
            break;
            
            case 'W':
            case 'w':
                for (i = 0; i < (m -> rows); i++) {
                    for (j = 0; j < (m -> collumns); j++) {
                        scanf(" %f", &(m -> Matrix[i][j]));
                    }
                }
            break;

            case 'N':
            case 'n':
            break;

            default:
                printf("Enter a valid option");
                exit(0);
        }
    }while((choice3 != 'N')&&(choice3 != 'n'));
}

/*NOT
void free_matrix(MATRIX x){

    int i;

    free(x.name);
    free(x.rows);
    free(x.collumns);

    for (i = 0; i < (m -> rows); i++ ){
        free(x.Matrix[i]);
    free(x.Matrix);
    }
}*/

void print_matrix(MATRIX x){

    int i, j;

    for (i = 0; i < (x.rows); i++) {
        for (j = 0; j < (x.collumns - 1); j++) {
            printf("%f\t", x.Matrix[i][j]);
        }
        printf("%f", x.Matrix[i][x.collumns - 1]);
        printf("\n");
    }
}

void printRow(int len, int row[]) {
    int i =0;
    for (i = 0; i < len; i++) {
        printf("%d\t", row[i]);
    }
}

/*NOT
char* return_name(MATRIX x){

    return ("m -> name");
}*/
