/*
 * cf-utils.c
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#include "cf-utils.h"

static const int ZERO = 0;
static const char EOS = '\0';
static const char U = 'U';
static const char O = 'O';
static const char I = 'I';
static const char E = 'E';
static const char A = 'A';

static bool is_vowel(char a){
	return a == A || a == tolower(A) || a == E || a == tolower(E) || a == I
			|| a == tolower(I) || a == O || a == tolower(O) ||
			a == U || a == tolower(U);
}

static bool is_consonant(char a){
	return isalpha(a)&&!is_vowel(a);
}

static bool all_vowels(char* text){
	bool flag = true;
	for (int i = ZERO; i < strlen(text) && flag; i++)
		flag = is_vowel(text[i]);
	return flag;
}

static bool all_consonants(char* text){
	bool flag = true;
	for (int i = ZERO; i < strlen(text) && flag; i++)
		flag = is_consonant(text[i]);
	return flag;
}

static bool char_in_text(const char* a, char b){
	bool flag = false;
	for (int i = ZERO; i < strlen(a) && !flag; i++)
		flag = (a[i]==b);
	return flag;
}

static bool text_in_text(const char* a, char* b){
	bool flag = true;
	for (int i = ZERO; i < strlen(b) && flag; i++)
		flag = char_in_text(a,b[i]);
	return flag;
}

static int get_vowel(const char* text, int i, int j, char* vow) {
	if (is_vowel(text[i]))
		vow[j++] = text[i];
	return j;
}

static void get_vowels(const char* text, char* vow) {
	int j = ZERO;
	for (int i = ZERO; i < strlen(text); i++)
		j = get_vowel(text, i, j, vow);
	vow[j] = EOS;
}

static int get_consonant(const char* text, int i, int j, char* cons) {
	if (is_consonant(text[i]))
		cons[j++] = text[i];
	return j;
}

static void get_consonants(const char* text, char* cons) {
	int j = ZERO;
	for (int i = ZERO; i < strlen(text); i++)
		j = get_consonant(text, i, j, cons);
	cons[j] = EOS;
}

static bool are_valid_length(const char* text, char* cons, char* vow) {
	return strlen(text) >= strlen(cons) + strlen(vow);
}

void cons_vow(const char* text, char* cons, char* vow){
	assert(text!=NULL);
	assert(cons!=NULL);
	assert(vow!=NULL);
	get_vowels(text, vow);
	get_consonants(text, cons);
	assert(are_valid_length(text,cons,vow));
	assert(all_vowels(vow));
	assert(all_consonants(cons));
	assert(text_in_text(text,cons));
	assert(text_in_text(text,vow));
}
