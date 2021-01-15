#include <stdio.h>
#include "student_data.h"

/** @file file.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in file.h. Le funzioni svolgono le operazioni
 *                         principali per la gestione (lettura e scrittura) di dati su file.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */

/**
 *  Funzione che si occupa di acquisire i dati da file ed inserirli nell'archivio.
 *  Acquisisce tutti i dati presenti all'interno del file.
 *  Inolte nel caso i dati acquisiti non siano validi, vengono ignorati.
 *  @pre L'archivio degli studenti deve essere vuoto, non inizializzato
 *  @post L'archivio degli studenti conterrà i dati acquisiti dal file
 *
 */
void initLoadStudentArchive(FILE *file, sStudentData *studentsArchive)
{
    int i = 0;
    // Legge dal file fin quando non si raggiunge la fine, o la dimensione dell'archivio termina
    while (!feof(file) && i < MAX_STUDENT_ARCHIVE_SIZE)
    {
        sStudentData newStudentData;
        int line = fscanf(file, "%s\t%s\t%s\t%hu\n", newStudentData.name, newStudentData.surname,
                         newStudentData.id, &newStudentData.vote);

        // Controlla che ci sia corrispondenza con i dati richiesti e che questi siano validi
        if (line > 0 && isValidStudentData(newStudentData))
        {
            sStudentData *currStudentData = &studentsArchive[i];    // Variabile che corrisponde all'attuale utente nell'archivio

            setStudentDataName(currStudentData, newStudentData.name);
            setStudentDataSurname(currStudentData, newStudentData.surname);
            setStudentDataID(currStudentData, newStudentData.id);
            setStudentDataVote(currStudentData, newStudentData.vote);

            i++;
        }
    }
}

/**
 *  Funzione che si occupa di salvare i dati presenti nell'archivio su file.
 *  @pre L'archivio degli studenti deve essere inizializzato
 *  @post Il file conterrà l'archivio degli studenti presente nella struttura
 *
 */
void saveStudentArchiveToFile(FILE *file, sStudentData *studentsArchive)
{
    int i;
    for (i = 0; i < MAX_STUDENT_ARCHIVE_SIZE; i++)
    {
        sStudentData *currStudentData = &studentsArchive[i];    // Variabile che corrisponde all'attuale utente nell'archivio
        fprintf(file, "%s\t%s\t%s\t%hu\n", getStudentDataName(currStudentData), getStudentDataSurname(currStudentData),
                getStudentDataID(currStudentData), getStudentDataVote(currStudentData));    // Scrive su file i singoli dati
    }
}
