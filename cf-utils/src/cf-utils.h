/*
 * cf-utils.h
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#ifndef CF_UTILS_H_
#define CF_UTILS_H_

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ZERO   0
#define A     'A'
#define E     'E'
#define I     'I'
#define O     'O'
#define U     'U'
#define EOS   '\0'

/**
 * Estrae le consonanti e le vocali da una stringa di caratteri.
 * La procedura popola due array (parametri di output) secondo questo criterio:
 * nell'array cons sono inserite tutte le consonanti di text (nell'ordine in cui
 * compaiono), mentre in vow sono inserite tutte le vocali di text (nell'ordine
 * in cui compaiono).
 *
 * @warning Il case delle lettere deve essere rispettato.
 * @warning I caratteri non afabetici devono essere ignorati.
 * @warning La lettera 'Y' o 'y' è considerata consonante.
 * @warning tutti i parametri sono stringhe.
 *
 *
 * @param[in] text la stringa da suddividere
 * @param[out] cons la sequenza di consonanti
 * @param[out] vow la sequenza di vocali
 *
 * @pre nessun parametro deve essere NULL
 * @post la lunghezza di str non deve essere inferiore alla somma delle lunghezze
 * 		 di cons e di vow
 * @post tutti i caratteri di cons devono essere consonanti
 * @post tutti i caratteri di vow devono essere vocali
 * @post tutti i caratteri di cons devono occorrere in text
 * @post tutti i caratteri di vow devono occorrere in text
 */
void cons_vow(const char* text, char* cons, char* vow);

#endif /* CF_UTILS_H_ */
