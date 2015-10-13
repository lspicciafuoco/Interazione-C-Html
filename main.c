#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FDOCENTI "DOCENTI.txt"       
#define FALUNNI "ALUNNI.txt"
#define MAXSTRLEN 255


//Funzione per scambiare il carattere '-' con il carattere ' '
void sostituisci(char* stringa, char vecchio, char nuovo){
    int i;
    for(i=0;i<strlen(stringa);i++){    // scorre le stringhe e sostituisce il vecchio carattere con quello indicato al richiamo della funzione
        if(stringa[i]==vecchio)
            stringa[i]=nuovo;
  }
}

int main(int argc, char** argv) {

    char alunni[MAXSTRLEN+1];
    char docenti[MAXSTRLEN+1];
  
    //apre i file DOCENTI e ALUNNI in modalità lettura
    FILE *puntafileDocenti;
    puntafileDocenti = fopen(FDOCENTI,"r");
    fscanf(puntafileDocenti,"%s",docenti);       // assegno a puntafileDocenti la stringa docenti
    sostituisci(docenti, '_',' ');              //sostituisce il carattere '_' con il carattere ' ' grazie alla funzione sostituisci
            
            
    FILE *puntafileAlunni;
    puntafileAlunni = fopen(FALUNNI,"r");
    fscanf(puntafileAlunni,"%s",alunni);     // assegno a puntafileDocenti la stringa docenti
    sostituisci(alunni, '_',' ');           //sostituisce il carattere '_' con il carattere ' ' grazie alla funzione sostituisci
            
                   
    
    // La parte del JavaScript è stata ricercata sul web e anche grazie all'aiuto di un mio compagno di classe 
    
     FILE *puntafileHTML;
    puntafileHTML = fopen("checkbox.html","w");      //apertura del file Html in modalità scrittura
    
    fprintf(puntafileHTML,"<html>\n");
    fprintf(puntafileHTML,"<body>\n");
    
    //Istruzioni per la select
    fprintf(puntafileHTML,"<form id=\"frm\"><select id=\"sel\" onchange=\"printNames()\"><option value=\"\" selected=\"selected\"><option value=\"%s\">alunni</option><option value=\"%s\">docenti</option></select></form>",alunni, docenti);
    fprintf(puntafileHTML,"<SCRIPT>function printNames(){var e = document.getElementById(\"sel\");var strUser = e.options[e.selectedIndex].value;document.getElementById(\'box\').innerHTML = strUser;}</SCRIPT>");
    fprintf(puntafileHTML,"<div id=\"box\"></div>");
    
    fprintf(puntafileHTML,"</body>\n");
    fprintf(puntafileHTML,"</html>\n");
    fclose(puntafileHTML);

    
    return (EXIT_SUCCESS);
}
    

//Come far comparire vuota la checkbox all'apertura della pagina?
//Riflettendo sul funzionamento del Javascript ho creato un 'altra opzione vuota selezionata già all'apertura

//Come 