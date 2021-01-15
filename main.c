#include <stdio.h>
#include <stdbool.h>
#include "student_data.h"
#include "menu.h"
#include "file.h"
#include "test.h"

/** @file main.c
 *
 *  Synthetic description. Il file contiene le funzionalita' principali (di dominio) per l'implementazione di questo programma.
 *                         Le funzionalita' di dominio richiamate dal main sono utili BLABLA VARIE FUNZIONI.
 *
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */


int main()
{
    bool bEsc = false;  // Variabile sentinella utilizzata per il controllo sull'uscita dal menu.
    sStudentData studentsArchive[MAX_STUDENT_ARCHIVE_SIZE];     // Archivio contente gli studenti.

    FILE *file;
    file = fopen(FILE_NAME, "r");

    while (bEsc == false)
    {
        int choice = selectMenu();  // Gestione del menu tramite scelta dell'utente.
        switch (choice)
        {
        case 1:
            manageInitStudentArchive(file, studentsArchive);
            fclose(file);       // Chiude il file poichè l'ipotetica lettura è stata effettuata, quindi il file non serve più.
            break;
        case 2:
            managePrintStudentArchive(studentsArchive);
            break;
        case 3:
            manageEditStudentArchive(studentsArchive);
            break;
        case 4:
            manageExchangeStudentVote(studentsArchive);
            break;
        case 5:
            managePrintStudentHighestVote(studentsArchive);
            break;
        case 6:
            testing();
            break;
        case 7:
            bEsc = true;
            break;
        default:		// Nel caso l'utente digitasse un input valido (numero valido) ma non corrisponde a nessuna scelta del menu, notifica l'utente.
            printf("Scelta errata. Riprova.\n\n");
            break;
        }
    }

    // Controlla se è possibile salvare le modifiche su file.
    // Se ciò è possibile, procede con il salvataggio su file, altrimenti notifica l'utente.
    file = fopen(FILE_NAME, "w");
    if (file != NULL)
    {
        saveStudentArchiveToFile(file, studentsArchive);
        fclose(file);
    }
    else
    {
        printf("Impossibile salvare su file le modifiche.\n");
    }

    return 0;
}
