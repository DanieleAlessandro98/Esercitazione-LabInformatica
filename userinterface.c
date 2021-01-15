#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "student_data.h"

/** @file userinterface.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in userinterface.h. Le funzioni svolgono le operazioni
 *                         principali per l'iterazione e acquisizione tra utente e programma.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */

/**
 *  È una funzione che descrive all'utente quali sono le modalità di caricamento dell'archivio che può effettuare.
 *  Successivamente acquisisce la scelta dell'utente, e la restituisce dopo aver controllato sia una scelta valida.
 *
 */
int selectInitMode()
{
    char choice[MAX_STRING_LENGHT];
    int value;
    do
    {
        printf("Inserisci la modalità di caricamento:\n");
        printf("1- Generazione random.\n");
        printf("2- Caricamento da file.\n");

        scanf("%s", choice);
        fflush(stdin);

        value = atoi(choice);

    } while (value == 0);

    return value;
}

/**
 *  È una funzione che acquisisce una matricola inserita dall'utente, e la restituisce dopo aver controllato sia una matricola valida sintatticamente.
 *
 */
void selectIDStudent(char *id)
{
    char tempID[MAX_STUDENT_ID_LENGHT];
    do
    {
        printf("Inserisci la matricola dello studente:\n");

        scanf("%s", tempID);
        fflush(stdin);

    } while (!isValidIDString(tempID));

    strcpy(id, tempID);
}
