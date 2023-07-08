#include <stdio.h>
#include <stdlib.h>

#define N 20 //Nome
#define C 20 //Cognome
#define I 20 //Indirizzo
#define CITTA 20 //Citta
#define E 20 //e-mail
#define H 100 //max numero elementi rubrica

//nome cognome indirizzo CAP citta numero di telefono e-mail
typedef struct{
    int Indice;
    char Nome[N];
    char Cognome[C];
    char Indirizzo[I];
    int CAP;
    char Citta[CITTA];
    int Numero;
    char email[E];
    struct rubrica_t *contatto_next; 
    struct rubrica_t *contatto_prev; 
}rubrica_t;

struct elemento_t{
    int Indice;
    struct rubrica_t *contatto;
};

struct elemento_t hash[100];
 
rubrica_t *rubrica=NULL;

void inserisci(){
rubrica_t *nuovo;
rubrica_t *attuale= rubrica;
nuovo=(rubrica_t*)malloc(sizeof(rubrica_t));
nuovo->contatto_next=NULL;
printf("inserisci il nome,cognome,indirizzo,CAP,citta,numero,email\n");
scanf("%s %s %s %d %s %d %s",nuovo->Nome,nuovo->Cognome,nuovo->Indirizzo,&nuovo->CAP,nuovo->Citta,&nuovo->Numero,nuovo->email);
if(attuale!=NULL){
    if(attuale->contatto_next==NULL){
        nuovo->Indice=2;
        attuale->contatto_next=nuovo;
    }
    else{
        while(attuale->contatto_next!=NULL){
            attuale=attuale->contatto_next;
        }
        nuovo->Indice=attuale->Indice+1;
        attuale->contatto_next=nuovo;
    }
}
else{
    nuovo->Indice=1;
    rubrica=nuovo;
}
}

void visualizza(){
    rubrica_t* attuale= rubrica;
    printf("Lista Rubrica:\n");
    if(attuale!=NULL){
        printf("%d %s %s %s %d %s %d %s\n",attuale->Indice,attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
        while(attuale->contatto_next!=NULL){
            attuale=attuale->contatto_next;
            printf("%d %s %s %s %d %s %d %s\n",attuale->Indice,attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
        }
    }
    printf("\n");
}

void salva(){
    FILE* pfile;
	rubrica_t* attuale=rubrica;

	pfile=fopen("Rubrica.txt","w");
	
    if(attuale!=NULL){
		fprintf(pfile,"%d %s %s %s %d %s %d %s\n",attuale->Indice,attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
		
		while(attuale->contatto_next!=NULL){
			attuale=attuale->contatto_next;
            fprintf(pfile,"%d %s %s %s %d %s %d %s\n",attuale->Indice,attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
		}			
	}
	
	fclose(pfile);
}
void leggi_file(){
    FILE *pfile;
	rubrica_t *nuovo;
	rubrica_t *attuale=rubrica;
    rubrica_t *precedente;
	pfile=fopen("Rubrica.txt","r");
	
	while(!feof(pfile)){	

		nuovo=(rubrica_t*)malloc(sizeof(rubrica_t));
    	nuovo->contatto_next=NULL;
		fscanf(pfile,"%d %s %s %s %d %s %d %s\n",&nuovo->Indice,nuovo->Nome,nuovo->Cognome,nuovo->Indirizzo,&nuovo->CAP,nuovo->Citta,&nuovo->Numero,nuovo->email);
		if (precedente!=NULL) nuovo->contatto_prev=precedente;

        hash[nuovo->Indice].Indice=nuovo->Indice;
        hash[nuovo->Indice].contatto=nuovo;

		if(attuale!=NULL){
			
			if(attuale->contatto_next==NULL) {
				attuale->contatto_next=nuovo;
			} 
			else {
				
				while(attuale->contatto_next!=NULL){
					attuale=attuale->contatto_next;
				}
						
				attuale->contatto_next=nuovo;
			}
		}
		else{
			rubrica=nuovo;
			attuale=nuovo;
		}
        precedente=attuale;
	}
	fclose(pfile);
} 

void ricerca(){
    int indice;
    printf("Inserisci l'indice dell'elemento che desideri visualizzare: \n");
    scanf("%d", &indice);

    rubrica_t *attuale = hash[indice].contatto;

    printf("%d %s %s %s %d %s %d %s\n",attuale->Indice,attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
    
}

void modifica(){
    int indice;
    printf("Inserisci l'indice dell'elemento che desideri modificare: \n");
    scanf("%d", &indice);

    rubrica_t *attuale = hash[indice].contatto;

    if(attuale != NULL) {
        printf("Inserisci i nuovi valori per il nome, cognome, indirizzo, CAP, citta, numero, e-mail:\n");
        scanf("%s %s %s %d %s %d %s", attuale->Nome, attuale->Cognome, attuale->Indirizzo, &attuale->CAP, attuale->Citta, &attuale->Numero, attuale->email);
    } else {
        printf("Elemento non trovato.\n");
    }
    salva();
}

void cancella(){
int indice;
    printf("Inserisci l'indice dell'elemento che desideri cancellare: ");
    scanf("%d", &indice);

    rubrica_t *attuale = hash[indice].contatto;
    rubrica_t *precedente;
    rubrica_t *successivo;
    if (attuale != NULL) {
    
        precedente=attuale->contatto_prev;
        successivo=attuale->contatto_next;
        precedente->contatto_next=attuale->contatto_next;

        hash[attuale->Indice].contatto=NULL;
        hash[attuale->Indice].Indice=NULL;

        while(successivo->contatto_next!=NULL){
            successivo->Indice=successivo->Indice-1;
            successivo=successivo->contatto_next;
        }
        successivo->Indice=successivo->Indice-1;
        
        free(attuale);
        salva();
    } else {
        printf("Elemento non trovato.\n");
    }
}
int main(){
    FILE *pfile;
    pfile=fopen("Lista_concorrenti.txt","r");
	if(pfile!=NULL){
		leggi_file(&rubrica);
		fclose(pfile);
	}
    leggi_file();
    int scelta;
    do
    {
        printf("=======================================================\n");
        printf("Scegli un' opzione:\n");
        printf("=======================================================\n");
        printf("1  - Visualizza la rublica\n");
        printf("2  - Inserire nuovo nome in rubrica\n");
        printf("3  - Salva un elemento della rubrica\n");
        printf("4  - Leggi la rubrica dal file\n");
        printf("5  - Modificare un elemento della rubrica\n"); 
        printf("6  - Ricercare un elemento della rubrica\n");
        printf("7  - Visualizzare un elemento della rubrica\n");
        printf("8  - Visualizzarla tutti gli elementi\n");
        printf("9  - Ordinare gli elementi della lista per nome\n");
        printf("10  - Ordinare gli elementi della lista per cognome\n"); 
        printf("11 - Ordinare gli elementi della lista per indirizzo\n");
        printf("12 - Ordinare gli elementi della lista per CAP\n");
        printf("13 - Ordinare gli elementi della lista per Citta\n");
        printf("14 - Ordinare gli elementi della lista per Numero\n");
        printf("15 - Ordinare gli elementi della lista per e-mail\n");
        printf("16 - exit\n");
        printf("=======================================================\n");
        scanf(" %d",&scelta);
        switch(scelta) {
            case 1:{
            	visualizza();            	
				break;
			}
            case 2:{
                inserisci();
				break;
			}
        	case 3:{
        		salva();
				break;
			}
			case 4:{
				leggi_file();
				break;
			}
            case 5:{
                modifica();
                break;
            }
            case 6:{
                ricerca();
                break;
            }
            case 7:{
                cancella();
                break;
            }
            case 8:{

                break;
            }
            case 9:{

                break;
            }
            case 10:{

                break;
            }
            case 11:{

                break;
            }
            case 12:{

                break;
            }
            case 13:{

                break;
            }
            case 14:{

                break;
            }
            case 15:{
                printf("Uscita dal programma.\n");
                break;
            }
            default:
                printf("Scelta non valida.\n");
        }
    }while(scelta!=15);     
    
}