#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED

/** @file userinterface.h
 *
 *  Synthetic description. Header file contenente le strutture e i prototipi per le funzioni richiamate e utilizzate che riguardano
 *                         l'iterazione tra l'utente e programma, principalmente input da tastiera.
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */

/** @brief Visualizza le modalità di caricamento dell'archivio, e ne acquisisce la scelta
 *
 * @return int Scelta effettuata dall'utente
 *
 */
int selectInitMode();


/** @brief Acquisisce tramite input da tastiera una matricola
 *
 * @param id char* Stringa dove viene sovrascritta la matricola acquisita
 * @return void
 *
 */
void selectIDStudent(char *id);

#endif // USERINTERFACE_H_INCLUDED
