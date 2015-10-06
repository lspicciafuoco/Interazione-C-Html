#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FNAME "checkbox.html"
#define FINGLESE "inglese.txt"
#define FMATEMATICA "matematica.txt"
#define FITALIANO "italiano.txt"
#define FINFORMATICA "informatica.txt"
#define MAX_FNAMELEN 255
#define MAX_STRLEN 255



int main(int argc, char** argv){
    
    char matematica[MAX_STRLEN+1];
    char informatica[MAX_STRLEN+1];
    char inglese[MAX_STRLEN+1];
    char italiano[MAX_STRLEN+1];
    
    FILE *puntafileInglese;
    puntafileInglese= fopen(FINGLESE, "r");
    fscanf(puntafileInglese,"%s", inglese);
   
    FILE *puntafileMatematica;
    puntafileMatematica= fopen(FMATEMATICA,"r");
    fscanf(puntafileInglese,"%s", inglese);
    
    FILE *puntafileInformatica;
    puntafileInformatica=fopen(FINFORMATICA,"r");
    fscanf(puntafileInformatica,"%s", informatica);
    
    FILE *puntafileItaliano;
    puntafileItaliano=fopen(FITALIANO, "r");
    fscanf(puntafileItaliano,"%s", italiano);
    
     int i;
    FILE *puntaFile;
    char elenco[MAX_FNAMELEN];
    
    
    
 puntaFile = fopen(FNAME, "w");
    if(puntaFile == NULL) {
        fprintf(stderr, "Impossibile creare il file %s\n", FNAME);
        exit(1);
    }
    else{
        printf("IL FILE E' STATO CREATO\n");
    }    
    
 fprintf(puntaFile,"<html>"
"<body>" 
 "<select>"
  "<option value=\"%s\">Matematica</option>"
  "<option value=\"%s\">Informatica</option>"
  "<option value=\"%s\">Inglese</option>"
  "<option value=\"%s\">Italiano</option>"
"</select>"
  
"</body>"
"</html>"
,inglese,italiano,matematica,informatica);

    
    fclose(puntaFile);
    printf("Dati salvati in %s\n", FNAME);
    
    return (EXIT_SUCCESS);
}
