#ifndef STUDENT_DATA_H_INCLUDED
#define STUDENT_DATA_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include "constants.h"

/** @file student_data.h
 *
 *  Synthetic description. Header file contenente le strutture e i prototipi per le funzioni richiamate e utilizzate che riguardano unicamente
 *                         gli studenti.
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


/**
 * @brief La struct sStudentData è una struttura che racchiude per ciascun studente le varie informazioni.
 */
typedef struct {
    char name[MAX_STUDENT_NAME_LENGHT];         /**< Indica il nome dello studente. */
    char surname[MAX_STUDENT_SURNAME_LENGHT];   /**< Indica il cognome dello studente. */
    char id[MAX_STUDENT_ID_LENGHT];             /**< Indica la matricola dello studente. */
    unsigned short vote;                        /**< Indica il voto dello studente. */
} sStudentData;


/** @brief Gestisce l'inizializzazione dell'archivio
 *
 * @param file FILE* File di apertura
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void manageInitStudentArchive(FILE *file, sStudentData *studentsArchive);


/** @brief Inizializza l'archivio con dati casuali
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void initRandomStudentArchive(sStudentData *studentsArchive);


/** @brief Genera i dati casuali dello studente e li salva su una struttura (d'appoggio) che poi viene restituita
 *
 * @return sStudentData Struttura contenete i dati generati casualmente
 *
 */
sStudentData generateRandomStudentData();


/** @brief Genera un nome casuale
 *
 * @param name char* Stringa dove viene sovrascritto il nome generato
 * @return void
 *
 */
void generateRandomStudentName(char *name);

/** @brief Genera un cognome casuale
 *
 * @param surname char* Stringa dove viene sovrascritto il cognome generato
 * @return void
 *
 */
void generateRandomStudentSurname(char *surname);

/** @brief Genera una matricola casuale
 *
 * @param ID char* Stringa dove viene sovrascritta la matricola generato
 * @return void
 *
 */
void generateRandomStudentID(char *ID);


/** @brief Genera un voto casuale
 *
 * @return unsigned short Intero dove viene sovrascritto il voto generato
 *
 */
unsigned short generateRandomStudentVote();


/** @brief Insieme di istruzioni che hanno lo scopo di verificare se i dati di uno studente sono corretti
 *
 * @param currStudentData const sStudentData Studente cui verificare i dati
 * @return bool True se i dati sono validi, False se non lo sono
 *
 */
bool isValidStudentData(const sStudentData currStudentData);


/** @brief Funzione di controllo che verifica se il nome di uno studente è corretto
 *
 * @param name const char* Nome da verificare
 * @return bool True se il nome è valido, False se non lo è
 *
 */
bool isValidNameString(const char *name);


/** @brief Funzione di controllo che verifica se il cognome di uno studente è corretto
 *
 * @param surname const char* Cognome da verificare
 * @return bool True se il cognome è valido, False se non lo è
 *
 */
bool isValidSurnameString(const char *surname);


/** @brief Funzione di controllo che verifica se la matricola di uno studente è corretta
 *
 * @param id const char* Matricola da verificare
 * @return bool True se la matricola è valida, False se non lo è
 *
 */
bool isValidIDString(const char *id);

/** @brief Funzione di controllo che verifica se il voto di uno studente è corretto
 *
 * @param vote const unsigned short Matricola da verificare
 * @return bool True se il voto è valido, False se non lo è
 *
 */
bool isValidVote(const unsigned short vote);


/** @brief Gestisce la visualizzazione in output gli studenti
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void managePrintStudentArchive(sStudentData *studentsArchive);


/** @brief Gestisce la modifica dei dati di un dato studente
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void manageEditStudentArchive(sStudentData *studentsArchive);


/** @brief Data la matricola, restituisce lo studente con quella matricola
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @param id const char* Matricola dello studente
 * @return sStudentData* Struttura contenete i dati dell'utente con quella matricola
 *
 */
sStudentData *getStudentByID(sStudentData *studentsArchive, const char *id);


/** @brief Acquisisce i nuovi dati dello studente e li salva su una struttura (d'appoggio) che poi verrà restituita
 *
 * @param id const char*
 * @return sStudentData Struttura contente i nuovi dati
 *
 */
sStudentData acquireNewStudentData(const char *id);


/** @brief Funzione che controlla se esiste uno studente con una determinata matricola
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @param id const char* Matricola da verificare
 * @return bool True se è stato trovato un utente con una data matricola, False se non è stato trovato
 *
 */
bool isFindStudentID(sStudentData *studentsArchive, const char *id);


/** @brief Acquiscisce tramite input da tastiera il nome
 *
 * @param name char* Stringa dove viene sovrascritto il nome acquisito
 * @return void
 *
 */
void acquireStudentDataName(char *name);

/** @brief Acquiscisce tramite input da tastiera il cognome
 *
 * @param surname char* Stringa dove viene sovrascritto il cognome acquisito
 * @return void
 *
 */
void acquireStudentDataSurname(char *surname);


/** @brief Acquiscisce tramite input da tastiera il voto
 *
 * @return unsigned short Voto acquisito da tastiera
 *
 */
unsigned short acquireStudentDataVote();


/** @brief Gestisce lo scambio dei voti tra due studenti
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void manageExchangeStudentVote(sStudentData *studentData);


/** @brief Gestisce la visualizzazione in output dello studente con il voto più alto
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void managePrintStudentHighestVote(sStudentData *studentsArchive);


/** @brief Calcola lo studente con il voto più alto, e ritorna una struttura a quello studente
 *
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return sStudentData Struttura contenete i dati dell'utente con voto più alto
 *
 */
sStudentData calculateStudentHighestVote(sStudentData *studentsArchive);

void setStudentDataName(sStudentData *studentData, const char *name);
void setStudentDataSurname(sStudentData *studentData, const char *surname);
void setStudentDataID(sStudentData *studentData, const char *id);
void setStudentDataVote(sStudentData *studentData, const unsigned short vote);

const char *getStudentDataName(sStudentData *studentData);
const char *getStudentDataSurname(sStudentData *studentData);
const char *getStudentDataID(sStudentData *studentData);
unsigned short getStudentDataVote(sStudentData *studentData);


#endif // STUDENT_DATA_H_INCLUDED
