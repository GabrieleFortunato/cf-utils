/*
 * cf-utils.c
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#include "cf-utils.h"

static const char EOS = '\0';
static const int ZERO = 0;
static const char u = 'u';
static const char U = 'U';
static const char o = 'o';
static const char O = 'O';
static const char i = 'i';
static const char I = 'I';
static const char e = 'e';
static const char E = 'E';
static const char a = 'a';
static const char A = 'A';

static bool is_vowel(char letter){
	return letter == A || letter == a || letter == E || letter == e	|| letter == I ||
			letter == i || letter == O || letter == o
			|| letter == U || letter == u;
}

static bool is_consonant(char a){
	return isalpha(a)&&!is_vowel(a);
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

static bool lengths(const char* text, char* cons, char* vow){
	return strlen(text)>=(strlen(cons)+strlen(vow));
}

static bool all_consonants(char* cons){
	bool flag = true;
	for (int i = ZERO; i < strlen(cons) && flag;)
		flag = is_consonant(cons[i++]);
	return flag;
}

static bool all_vowels(char* cons){
	bool flag = true;
	for (int i = ZERO; i < strlen(cons) && flag;)
		flag = is_vowel(cons[i++]);
	return flag;
}

static bool char_in_text(const char* text, char a){
	bool flag = false;
	for (int i = ZERO; i < strlen(text) && !flag;)
		flag = (a == text[i++]);
	return flag;
}

static bool text_in_text(const char* text1, char* text2){
	bool flag = true;
	for (int i = ZERO; i < strlen(text2) && flag;)
		flag = char_in_text(text1,text2[i++]);
	return flag;
}

void cons_vow(const char* text, char* cons, char* vow){
	assert(text!=NULL);
	assert(cons!=NULL);
	assert(vow!=NULL);
	get_vowels(text, vow);
	get_consonants(text, cons);
	assert(lengths(text,cons,vow));
	assert(all_consonants(cons));
	assert(all_vowels(vow));
	assert(text_in_text(text,cons));
	assert(text_in_text(text,vow));
}
