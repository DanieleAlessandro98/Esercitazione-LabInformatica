#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "student_data.h"
#include "userinterface.h"
#include "file.h"

/** @file student_data.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in student_data.h. Le funzioni svolgono le operazioni
 *                         principali per la gestione e visualizzazione degli studenti.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


/**
 *  La funzione gestisce l'inizializzazione dell'archivio.
 *  Essa procederà prima a verificare se il file è esistente o no, per poi procedere con la generazione dei dati casuali
 *  Nel caso invece del file esistente, acquisirà la scelta dell'utente se generarli casualmente o da file.
 *  @pre Il file potrebbe anche corrispondere a NULL, in tal caso il file non è esistente
 *  @pre L'archivio degli studenti deve essere vuoto, non inizializzato
 *  @post L'utente verrà notificato se l'inizializzazione è avvenuta con successo o ci sono stati errori
 *
 */
void manageInitStudentArchive(FILE *file, sStudentData *studentsArchive)
{
    srand(time(NULL));

    // Se il file è NULL, quindi se questo non esiste procede con la generazione random.
    if (file == NULL)
    {
        initRandomStudentArchive(studentsArchive);
    }
    else
    {
        // In base alla scelta dell'utente il programma genera random i dati o li carica da file.
        int choice = selectInitMode();
        switch (choice)
        {
        case 1:
            initRandomStudentArchive(studentsArchive);
            break;
        case 2:
            initLoadStudentArchive(file, studentsArchive);
            break;
        default:
            printf("Scelta errata. Riprova.\n");
            break;
        }
    }
}

/**
 *  Funzione che si occupa di generare i dati degli studenti in modo casuale.
 *  Per ogni studente genera dei dati casuali salvandoli su una struttura di supporto, dopodichè li sovrascrive all'archivio.
 *  @pre L'archivio degli studenti deve essere vuoto, non inizializzato
 *  @post L'archivio degli studenti conterrà i dati generati casualmente
 *
 */
void initRandomStudentArchive(sStudentData *studentsArchive)
{
    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        sStudentData newStudent = generateRandomStudentData();      // Richiama la funzione che genera i dati casuali per l'utente
        sStudentData *currStudentData = &studentsArchive[i];        /* Variabile che corrisponde all'utente attuale dell'archivio
                                                                        dove verranno sovrascritti i nuovi dati generati usando
                                                                        la struttura di appoggio.
                                                                    */
        setStudentDataName(currStudentData, newStudent.name);
        setStudentDataSurname(currStudentData, newStudent.surname);
        setStudentDataID(currStudentData, newStudent.id);
        setStudentDataVote(currStudentData, newStudent.vote);

    }
}

/**
 *  Funzione che si occupa di generare casualmente i dati relativi allo studente.
 *  Utilizza una struttura di appoggio che memorizza al suo interno i dati e successivamente viene restituita alla funzione
 *  chiamante. La generazione viene effettuata richiamando una funzione per ciascuna informazione.
 *  @post La struttura studente conterrà i dati generati casualmente
 *
 */
sStudentData generateRandomStudentData()
{
    sStudentData newStudentData;

    strcpy(newStudentData.name, "");        // La stringa viene azzerata a null per evitare problemi di sovrascrizione o di terminatore.
    generateRandomStudentName(newStudentData.name);

    strcpy(newStudentData.surname, "");     // La stringa viene azzerata a null per evitare problemi di sovrascrizione o di terminatore.
    generateRandomStudentSurname(newStudentData.surname);

    strcpy(newStudentData.id, "");          // La stringa viene azzerata a null per evitare problemi di sovrascrizione o di terminatore.
    generateRandomStudentID(newStudentData.id);

    newStudentData.vote = generateRandomStudentVote();

    return newStudentData;
}


/**
 *  Genera un nome casuale usando un index di nomi preimpostati.
 *  Quindi viene usato un index di nomi, dove viene generato random l'index cui prendere il nome.
 *  Infine viene sovrascritto il nome generato.
 *  @pre La stringa deve essere vuota per evitare eventuali sovrascritture errate
 *  @post Stringa generata casualmente
 *
 */
void generateRandomStudentName(char *name)
{
    const char *names[] = { "nome1", "nome2", "nome3", "nome4", "nome5", "nome6", "nome7" };

    const int tempIndex = rand() % MAX_STUDENT_NAME_RANGE_SIZE;
    const char *tempString = names[tempIndex];

    strcpy(name, tempString);
}

/**
 *  Genera un cognome casuale usando un index di cognomi preimpostati.
 *  Quindi viene usato un index di cognomi, dove viene generato random l'index cui prendere il cognome.
 *  Infine viene sovrascritto il cognome generato.
 *  @pre La stringa deve essere vuota per evitare eventuali sovrascritture errate
 *  @post Stringa generata casualmente
 *
 */
void generateRandomStudentSurname(char *surname)
{
    const char *surnames[] = { "cognome1", "cognome2", "cognome3", "cognome4", "cognome5", "cognome6", "cognome7" };

    const int tempIndex = rand() % MAX_STUDENT_SURNAME_RANGE_SIZE;
    const char *tempString = surnames[tempIndex];

    strcpy(surname, tempString);
}


/**
 *  Genera una matricola casuale usando una stringa di caratteri contenente solo numeri.
 *  Quindi viene utilizzato un loop della lunghezza della matricola (togliendo il terminatore).
 *  Viene preso random un carattere dalla stringa dei numeri e concatenato con la matricola.
 *  @pre La stringa deve essere vuota per evitare eventuali sovrascritture errate
 *  @post Stringa generata casualmente
 *
 */
void generateRandomStudentID(char *ID)
{
    const char *numbers = "1234567890";

    int i;
    for (i = 0; i < MAX_STUDENT_ID_LENGHT - 1; i++)
    {
        // randCharacter è l'index della stringa preso casualmente da 0 alla lunghezza massima della stringa
        int randCharacter = rand() % strlen(numbers);

        // Viene usata la variabile randCharacter per prendere il carattere casuale
        char newChar[] = { numbers[randCharacter], '\0' };

        // Concatena la matricola con il nuovo carattere
        strcat(ID, newChar);
    }

    // Viene aggiunto il terminatore per correttezza e per evitare errori
    ID[MAX_STUDENT_ID_LENGHT] = '\0';
}


/**
 *  Genera un voto casuale usando un range di valori.
 *  Dopodichè restituisce quel valore.
 *  @post Intero valido tra i due range limite
 *
 */
unsigned short generateRandomStudentVote()
{
    int value = rand() % (MAX_STUDENT_VOTE_RANGE_VALUE - MIN_STUDENT_VOTE_RANGE_VALUE + 1) + MIN_STUDENT_VOTE_RANGE_VALUE;
    return value;
}

/**
 *  Funzione che ha lo scopo di controllare i dati di un dato studente
 *  Restituisce false se solo uno dei dati presenti non è corretto, nel caso contrario restituisce true.
 *  @pre La struttura deve esistere e non deve essere vuota
 *  @post Valore booleano vero se i dati sono validi, altrimenti falso
 *
 */
bool isValidStudentData(const sStudentData currStudentData)
{
    if (!isValidNameString(currStudentData.name))
        return false;

    if (!isValidSurnameString(currStudentData.surname))
        return false;

    if (!isValidIDString(currStudentData.id))
        return false;

    if (!isValidVote(currStudentData.vote))
        return false;

    return true;
}


/**
 *  Funzione che ha lo scopo di controllare se il nome di uno studente è corretto o no
 *  Per non corretto, si intende una lunghezza inferiore o superiore ai limiti impostati, oppure un carattere speciale.
 *  Restituisce false se non è corretto, nel caso contrario restituisce true.
 *  @post Valore booleano vero se la stringa è valida, altrimenti falso
 *
 */
bool isValidNameString(const char *name)
{
    int lenght = strlen(name);

    if (lenght < MIN_STUDENT_NAME_LENGHT)
        return false;

    if (lenght > MAX_STUDENT_NAME_LENGHT)
        return false;

    int i;
    for (i = 0; i < lenght; i++)
    {
        if (!isalnum(name[i]))          // Se è presente almeno un carattere speciale, la stringa non è valida
            return false;
    }

    return true;
}


/**
 *  Funzione che ha lo scopo di controllare se il cognome di uno studente è corretto o no
 *  Per non corretto, si intende una lunghezza inferiore o superiore ai limiti impostati, oppure un carattere speciale.
 *  Restituisce false se non è corretto, nel caso contrario restituisce true.
 *  @post Valore booleano vero se la stringa è valida, altrimenti falso
 *
 */
bool isValidSurnameString(const char *surname)
{
    int lenght = strlen(surname);

    if (lenght < MIN_STUDENT_SURNAME_LENGHT)
        return false;

    if (lenght > MAX_STUDENT_SURNAME_LENGHT)
        return false;

    int i;
    for (i = 0; i < lenght; i++)
    {
        if (!isalnum(surname[i]))       // Se è presente almeno un carattere speciale, la stringa non è valida
            return false;
    }

    return true;
}


/**
 *  Funzione che ha lo scopo di controllare se la matricola di uno studente è corretta o no
 *  Per non corretto, si intende una lunghezza diversa dai limiti impostati, oppure un carattere che non è una lettera.
 *  Restituisce false se non è corretto, nel caso contrario restituisce true.
 *  @post Valore booleano vero se la stringa è valida, altrimenti falso
 *
 */
bool isValidIDString(const char *id)
{
    int lenght = strlen(id);
    if (lenght != MAX_STUDENT_ID_LENGHT - 1)
        return false;

    int i;
    for (i = 0; i < lenght; i++)
    {
        if (!isdigit(id[i]))        // Se è presente almeno un carattere che non è un numero, la stringa non è valida
            return false;
    }

    return true;
}

/**
 *  Funzione che ha lo scopo di controllare se il voto di uno studente è corretta o no
 *  Per non corretto, si intende un valore fuori dai range limite impostati.
 *  Restituisce false se non è corretto, nel caso contrario restituisce true.
 *  @post Valore booleano vero se l'intero è valido, altrimenti falso
 *
 */
bool isValidVote(const unsigned short vote)
{
    if (vote < MIN_STUDENT_VOTE_RANGE_VALUE)
        return false;

    if (vote > MAX_STUDENT_VOTE_RANGE_VALUE)
        return false;

    return true;
}

/**
 *  È una funzione che si occupa di visualizzare in output tutte le informazioni
 *  riguardanti gli studenti. Ciò avviene attraverso l'uso di un loop, dove per ciascun studente
 *  vengono acquisite le sue informazioni e visualizzate in output.
 *  @pre L'archivio degli studenti deve inizializzato
 *  @post L'utente visualizzerà la lista degli utenti con i loro dati
 *
 */
void managePrintStudentArchive(sStudentData *studentsArchive)
{
    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        sStudentData *currStudentData = &studentsArchive[i];
        printf("Studente numero: %d\n", i+1);

        printf("%10s\t\t", "Nome:");
        printf("%s\n", getStudentDataName(currStudentData));

        printf("%10s\t\t", "Cognome:");
        printf("%s\n", getStudentDataSurname(currStudentData));

        printf("%10s\t\t", "Matricola:");
        printf("%s\n", getStudentDataID(currStudentData));

        printf("%10s\t\t", "Voto:");
        printf("%hu\n", getStudentDataVote(currStudentData));

        printf("\n");
    }
}


/**
 *  La funzione gestisce la modifica dei dati di uno studente.
 *  Se l'id dell'utente è presente nell'archivio procede con il prendere i nuovi dati in input e li sovrascrive.
 *  @pre L'archivio degli studenti deve inizializzato
 *  @post L'utente verrà notificato se la modifica dei dati è avvenuta con successo o ci sono stati errori
 *
 */
void manageEditStudentArchive(sStudentData *studentsArchive)
{
    char id[MAX_STUDENT_ID_LENGHT];
    selectIDStudent(id);

    // Controlla che l'id esista nell'archivio
    if (isFindStudentID(studentsArchive, id))
    {
        // Acquisisce i nuovi su una struttura d'appoggio e memorizza qual'è l'utente da modificare all'interno dell'archivio
        sStudentData editStudent = acquireNewStudentData(id);
        sStudentData *currStudent = getStudentByID(studentsArchive, id);

        // Ulteriore verifica che lo studente che si vuole modificare esista
        if (currStudent != NULL)
        {
            // Sovrascrive i nuovi dati
            setStudentDataName(currStudent, editStudent.name);
            setStudentDataSurname(currStudent, editStudent.surname);
            setStudentDataVote(currStudent, editStudent.vote);
        }
    }
    else
    {
        printf("La matricola non è stata trovata.\n");
    }
}

/**
 *  La funzione data una matricola in input restituisce l'utente con quella matricola.
 *  Nel caso l'utente non esista (caso improbabile per altri controlli fatti in precedenza) restituisce NULL.
 *  La funzione utilizza un loop per ogni studente, e nel caso lo studente abbia la stessa matricola lo restituisce.
 *
 */
sStudentData *getStudentByID(sStudentData *studentsArchive, const char *id)
{
    // Puntatore alla struttura ed inizializzata con NULL per motivi di integrità e sicurezza
    sStudentData *currStudentData = NULL;

    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        currStudentData = &studentsArchive[i];  // Variabile che corrisponde alla posizione dell'attuale utente nell'archivio
        if (strcmp(getStudentDataID(currStudentData), id) == 0) // Nel caso sia la stessa matricola termina il loop e il puntatore viene mantenuto in memoria
        {
            i = MAX_STUDENT_ARCHIVE_SIZE;
        }
    }

    // Restituisce l'ultimo puntatore processato dal loop, quindi quello con la matricola uguale, oppure NULL
    return currStudentData;
}

/**
 *  Funzione che si occupa di acquisire i dati da modificare relativi allo studente.
 *  Utilizza una struttura di appoggio che memorizza al suo interno i dati e successivamente viene restituita alla funzione
 *  chiamante. L'acquisizione viene effettuata richiamando una funzione per ciascuna informazione.
 *
 */
sStudentData acquireNewStudentData(const char *id)
{
    sStudentData editStudent;

    printf("Modificati i dati dello studente:\n");

    acquireStudentDataName(editStudent.name);
    acquireStudentDataSurname(editStudent.surname);
    editStudent.vote = acquireStudentDataVote();

    return editStudent;
}

/**
 *  È una funzione che si occupa di cercare uno studente in base alla matricola.
 *  La funzione restituirà true se l'utente è stato trovato, false se non è stato trovato.
 *  La funzione utilizza un loop per ogni studente, e nel caso lo studente abbia la stessa matricola restituisce true.
 *
 */
bool isFindStudentID(sStudentData *studentsArchive, const char *id)
{
    bool bFind = false;     // Variabile sentinella

    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        sStudentData *currStudentData = &studentsArchive[i];    // Variabile che corrisponde all'attuale utente nell'archivio
        if (strcmp(getStudentDataID(currStudentData), id) == 0) // Se l'utente attule ha la stessa matricola la variabile sentinella viene impostata su true ed esce dal ciclo
        {
            bFind = true;
            i = MAX_STUDENT_ARCHIVE_SIZE;
        }
    }

    return bFind;

}


/**
 *  Funzione che si occupa di acquisire da tastiera il nome dello studente.
 *  Dopo aver effettuato i dovuti controlli, il nome viene passato alla funzione chiamante.
 *
 */
void acquireStudentDataName(char *name)
{
    char tempName[MAX_STRING_LENGHT] = "";

    // Acquisisce l'input da tastiera fin quando non è un'input valido
    do
    {
        printf("Inserisci il nome dello studente:\n");
        scanf("%s", tempName);
        fflush(stdin);
    } while (!isValidNameString(tempName));

    strcpy(name, tempName);
}


/**
 *  Funzione che si occupa di acquisire da tastiera il cognome dello studente.
 *  Dopo aver effettuato i dovuti controlli, il cognome viene passato alla funzione chiamante.
 *
 */
void acquireStudentDataSurname(char *surname)
{
    char tempSurname[MAX_STRING_LENGHT] = "";

    // Acquisisce l'input da tastiera fin quando non è un'input valido
    do
    {
        printf("Inserisci il cognome dello studente:\n");
        scanf("%s", tempSurname);
        fflush(stdin);
    } while (!isValidSurnameString(tempSurname));

    strcpy(surname, tempSurname);
}

/**
 *  Funzione che si occupa di acquisire da tastiera il voto dello studente.
 *  Dopo aver effettuato i dovuti controlli, il voto viene passato alla funzione chiamante.
 *
 */
unsigned short acquireStudentDataVote()
{
    char stringVote[MAX_STUDENT_ID_LENGHT];
    unsigned short valueVote;

    // Acquisisce l'input da tastiera fin quando non è un'input valido
    do
    {
        printf("Inserisci il voto dello studente:\n");

        scanf("%s", stringVote);
        fflush(stdin);

        valueVote = atoi(stringVote);

    } while (!isValidVote(valueVote));

    return valueVote;
}


/**
 *  La funzione gestisce lo scambio dei voti tra due studenti.
 *  Se gli id degli studenti sono presente nell'archivio, procede con lo swap dei voti.
 *
 */
void manageExchangeStudentVote(sStudentData *studentsArchive)
{
    char firstStudentID[MAX_STUDENT_ID_LENGHT];
    selectIDStudent(firstStudentID);

    char secondStudentID[MAX_STUDENT_ID_LENGHT];
    selectIDStudent(secondStudentID);

    if (isFindStudentID(studentsArchive, firstStudentID) && isFindStudentID(studentsArchive, secondStudentID))
    {
        sStudentData *firstStudent = getStudentByID(studentsArchive, firstStudentID);
        sStudentData *secondStudent = getStudentByID(studentsArchive, secondStudentID);

        if (firstStudentID != NULL && secondStudentID != NULL)
        {
            unsigned short tempVote = getStudentDataVote(firstStudent);
            setStudentDataVote(firstStudent, getStudentDataVote(secondStudent));
            setStudentDataVote(secondStudent, tempVote);
        }
    }
    else
    {
        printf("La matricola non è stata trovata.\n");
    }
}


/**
 *  È una funzione che si occupa di visualizzare lo studente con il voto più alto in output.
 *  Ciò avviene attraverso l'uso di una struttura di supporto che memorizza chi è lo studente con voto più alto.
 *  Successivamente vengono visualizzati i dati.
 *
 */
void managePrintStudentHighestVote(sStudentData *studentsArchive)
{
    sStudentData studentHighestVote = calculateStudentHighestVote(studentsArchive);
    printf("Lo studente con il voto più alto è:\n");

    printf("%10s\t\t", "Nome:");
    printf("%s\n", getStudentDataName(&studentHighestVote));

    printf("%10s\t\t", "Cognome:");
    printf("%s\n", getStudentDataSurname(&studentHighestVote));

    printf("%10s\t\t", "Matricola:");
    printf("%s\n", getStudentDataID(&studentHighestVote));

    printf("%10s\t\t", "Voto:");
    printf("%hu\n", getStudentDataVote(&studentHighestVote));
}

/**
 *  Funzione che si occupa di calcolare chi è lo studente con il voto più alto.
 *  Utilizza una struttura di appoggio che memorizza al suo interno i dati e successivamente viene restituita alla funzione
 *  chiamante.
 *  Il calcolo viene effettuato attraverso un loop, dove si controlla per ogni studente se il voto è maggiore.
 *
 */
sStudentData calculateStudentHighestVote(sStudentData *studentsArchive)
{
    int indexMaxVote = 0;
    unsigned short maxVote = 0;

    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        sStudentData *currStudentData = &studentsArchive[i];
        unsigned short currentStudentVote = getStudentDataVote(currStudentData);

        if (currentStudentVote > maxVote)
        {
            indexMaxVote = i;
            maxVote = currentStudentVote;
        }
    }

    return studentsArchive[indexMaxVote];
}

void setStudentDataName(sStudentData *studentData, const char *name)
{
    strcpy(studentData->name, name);
}

void setStudentDataSurname(sStudentData *studentData, const char *surname)
{
    strcpy(studentData->surname, surname);
}

void setStudentDataID(sStudentData *studentData, const char *id)
{
    strcpy(studentData->id, id);
}

void setStudentDataVote(sStudentData *studentData, const unsigned short vote)
{
    studentData->vote = vote;
}


const char *getStudentDataName(sStudentData *studentData)
{
    return studentData->name;
}

const char *getStudentDataSurname(sStudentData *studentData)
{
    return studentData->surname;
}

const char *getStudentDataID(sStudentData *studentData)
{
    return studentData->id;
}

unsigned short getStudentDataVote(sStudentData *studentData)
{
    return studentData->vote;
}
