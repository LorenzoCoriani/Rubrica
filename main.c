#include <stdio.h>

#define N 20 //Nome
#define C 20 //Cognome
#define I 20 //Indirizzo
#define Cap 20 //CAP
#define CITTA 20 //Citta
#define NUM 20 //Numero
#define E 20 //e-mail


//nome cognome indirizzo CAP citta numero di telefono e-mail
typedef struct{
    char Nome[N];
    char Cognome[C];
    char Indirizzo[I];
    int CAP[Cap];
    char Citta[CITTA];
    int Numero[NUM];
    char email[E];
    struct rubrica_t *contatto_next; 
    struct rubrica_t *contatto_prev; 
}rubrica_t;

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
        attuale->contatto_next=nuovo;
    }
    else{
        while(attuale->contatto_next!=NULL){
            attuale=attuale->contatto_next;
        }
        attuale->contatto_next=nuovo;
    }
}
else{
    rubrica=nuovo;
}
}

void visualizza(){
    rubrica_t* attuale= rubrica;
    printf("Lista Rubrica:\n");
    if(attuale!=NULL){
        printf("%s %s %s %d %s %d %s\n",attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
        while(attuale->contatto_next!=NULL){
            attuale=attuale->contatto_next;
            printf("%s %s %s %d %s %d %s\n",attuale->Nome,attuale->Cognome,attuale->Indirizzo,attuale->CAP,attuale->Citta,attuale->Numero,attuale->email);
        }
    }
    printf("\n");
}


int main(){
    int scelta;
    do
    {
        printf("=======================================================\n");
        printf("Scegli un' opzione:\n");
        printf("=======================================================\n");
        printf("1  - Visualizza la rublica\n");
        printf("2  - Inserire nuovo nome in rubrica\n");
        printf("3  - Cancellare un elemento della rubrica\n");
        printf("4  - Modificare un elemento della rubrica\n"); 
        printf("5  - Ricercare un elemento della rubrica\n");
        printf("6  - Visualizzare un elemento della rubrica\n");
        printf("7  - Visualizzarla tutti gli elementi\n");
        printf("8  - Ordinare gli elementi della lista per nome\n");
        printf("9  - Ordinare gli elementi della lista per cognome\n"); 
        printf("10 - Ordinare gli elementi della lista per indirizzo\n");
        printf("11 - Ordinare gli elementi della lista per CAP\n");
        printf("12 - Ordinare gli elementi della lista per Citta\n");
        printf("13 - Ordinare gli elementi della lista per Numero\n");
        printf("14 - Ordinare gli elementi della lista per e-mail\n");
        printf("15 - exit\n");
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
        		
				break;
			}
			case 4:{
				
				break;
			}
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
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
    }while(scelta!=5);     
    
}