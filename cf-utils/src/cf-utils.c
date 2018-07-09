/*
 * cf-utils.c
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#include "cf-utils.h"

static const char EOS = '\0';
static const int ZERO = 0;
static const char U = 'U';
static const char O = 'O';
static const char I = 'I';
static const char E = 'E';
static const char A = 'A';

static bool is_vowel(char a){
	return a == A || a == tolower(A) || a == E || a == tolower(E) || a == I ||
		   a == tolower(I) || a == O || a == tolower(O) || a == U|| a == tolower(U);
}

static bool is_consonant(char a){
	return isalpha(a)&&!is_vowel(a);
}

static void get_vowel(const char* text, char* vow, int i, int* k){
	if (is_vowel(text[i]))
		vow[(*k)++] = text[i];
}

static void get_vowels(const char* text, char* vow){
	int k = ZERO;
	for (int i = ZERO; i < strlen(text); i++)
		get_vowel(text,vow,i,&k);
	vow[k] = EOS;
}

static void get_consonant(const char* text, char* cons, int i, int* k){
	if (is_consonant(text[i]))
		cons[(*k)++] = text[i];
}

static void get_consonants(const char* text, char* cons){
	int k = ZERO;
	for (int i = ZERO; i < strlen(text); i++)
		get_consonant(text,cons,i,&k);
	cons[k] = EOS;
}

static bool all_consonants(char* string){
	bool flag = true;
	for (int i = ZERO; i < strlen(string) && flag; i++)
		flag = is_consonant(string[i]);
	return flag;
}


static bool all_vowels(char* string){
	bool flag = true;
	for (int i = ZERO; i < strlen(string) && flag; i++)
		flag = is_vowel(string[i]);
	return flag;
}

static bool char_in_text(const char* text ,char a){
	bool flag = false;
	for (int i = ZERO; i < strlen(text) && !flag; i++)
		flag = (text[i] == a);
	return flag;
}

static bool string_in_text(const char* text ,char* string){
	bool flag = true;
	for (int i = ZERO; i < strlen(string) && flag; i++)
		flag = char_in_text(text , string[i]);
	return flag;
}

void cons_vow(const char* text, char* cons, char* vow){
	assert(text!=NULL);
	assert(cons!=NULL);
	assert(vow!=NULL);
	get_vowels(text,vow);
	get_consonants(text,cons);
	assert(all_consonants(cons));
	assert(all_vowels(vow));
	assert(string_in_text(text,cons));
	assert(string_in_text(text,vow));
}
