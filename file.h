#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

/** @file file.h
 *
 *  Synthetic description. Header file contenente i prototipi per le funzioni richiamate e utilizzate che riguardano unicamente
 *                         la gestione dei files.
 *  @version 1.0
 *  @date 10/06/2020
 *  @author Alessandro Daniele
 */

/** @brief Acquisisce i nuovi dati dello studente tramite file e li salva all'interno dell'archivio
 *
 * @param file FILE* File contente i dati
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void initLoadStudentArchive(FILE *file, sStudentData *studentsArchive);


/** @brief Salva i dati presenti nell'archivio su file
 *
 * @param file FILE* File dove salvare i dati
 * @param studentsArchive sStudentData* Archivio contente gli studenti
 * @return void
 *
 */
void saveStudentArchiveToFile(FILE *file, sStudentData *studentsArchive);

#endif // FILE_H_INCLUDED
