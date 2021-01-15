#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

/** @file constants.h
 *  Synthetic description. Header file contenente costanti e macro utilizzate nel progetto.
 */

/// Numero di caratteri massimo da cui può essere composta una generica stringa
#define MAX_STRING_LENGHT 30

/// Numero di caratteri massimo da cui può essere composto il nome dello studente
#define MAX_STUDENT_NAME_LENGHT 30

/// Numero di caratteri minimo da cui può essere composto il nome dello studente
#define MIN_STUDENT_NAME_LENGHT 3

/// Numero di caratteri massimo da cui può essere composto il cognome dello studente
#define MAX_STUDENT_SURNAME_LENGHT 30

/// Numero di caratteri minimo da cui può essere composto il cognome dello studente
#define MIN_STUDENT_SURNAME_LENGHT 1

/// Numero di caratteri massimo da cui può essere composta la matricola dello studente
#define MAX_STUDENT_ID_LENGHT 7

/// Dimensione massima dell'archivio contente gli studenti
#define MAX_STUDENT_ARCHIVE_SIZE 10

/// Dimensione massima del range di nomi che possono essere estratti casualmente
#define MAX_STUDENT_NAME_RANGE_SIZE 7

/// Dimensione massima del range di cognomi che possono essere estratti casualmente
#define MAX_STUDENT_SURNAME_RANGE_SIZE 7

/// Valore massimo che può assumere il voto dello studente
#define MAX_STUDENT_VOTE_RANGE_VALUE 30

/// Valore minimo che può assumere il voto dello studente
#define MIN_STUDENT_VOTE_RANGE_VALUE 1

/// Nome del file contenente l'archivio
#define FILE_NAME "studenti.txt"

#endif // CONSTANTS_H_INCLUDED
