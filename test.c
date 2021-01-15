#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "student_data.h"

void testing()
{
    printf("Fase di testing:\n");

    assert(isValidNameString("nome1") == true);                         // Nome corretto
    assert(isValidNameString("n") == false);                            // Nome non corretto (lunghezza minima)
    assert(isValidNameString("nome1_") == false);                       // Nome non corretto (carattere speciale)
    assert(isValidNameString("nome1nome1nome1nome1nome1nome1nome1") == false); // Nome non corretto (lunghezza massima)

    assert(isValidSurnameString("cognome1") == true);                   // Cognome corretto
    assert(isValidNameString("c") == false);                            // Cognome non corretto (lunghezza minima)
    assert(isValidNameString("cognome1_") == false);                    // Cognome non corretto  (carattere speciale)
    assert(isValidNameString("cognome1cognome1cognome1cognome1cognome1") == false); // Cognome non corretto (lunghezza massima)

    assert(isValidIDString("123456") == true);      // Matricola corretta
    assert(isValidIDString("12") == false);         // Matricola non corretta (lunghezza minima)
    assert(isValidIDString("12345678") == false);   // Matricola non corretta (lunghezza massima)
    assert(isValidIDString("123456A") == false);    // Matricola non corretta (carattere non numerico)

    assert(isValidVote(25) == true);                // Voto corretto
    assert(isValidVote(10) == true);                // Voto corretto
    assert(isValidVote(0) == false);                // Voto non corretto (fuori dal range)
    assert(isValidVote(40) == false);               // Voto non corretto (fuori dal range)

    printf("Testing eseguito con successo.\n");
}
