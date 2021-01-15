#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

/** @file menu.c
 *
 *  Synthetic description. Implementazione delle funzioni presentate in menu.h. Le funzioni svolgono le operazioni
 *                         principali per la gestione del menu.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


/**
 *  � una funzione che descrive all'utente quali sono le scelte del menu che pu� effettuare.
 *  Successivamente acquisisce la scelta dell'utente, e la restituisce dopo aver controllato sia una scelta valida.
 *  @post L'intero restituito � un numero valido e maggiore di 0
 *
 */
int selectMenu()
{
    char choice[MAX_STRING_LENGHT];
    int value = 0;
    do
    {
        printf("Inserisci la scelta che vuoi effettuare.\n");
        printf("1- Caricamento dei dati.\n");
        printf("2- Visualizza dati generati o caricati.\n");
        printf("3- Modifica dell'anagrafica di uno studente.\n");
        printf("4- Scambio del voto tra due studenti.\n");
        printf("5- Visualizza l'utente con il voto pi� alto.\n");
        printf("6- Testing.\n");
        printf("7- Esci.\n");

        scanf("%s", choice);
        fflush(stdin);

        value = atoi(choice);

    } while (value == 0);

    return value;
}
