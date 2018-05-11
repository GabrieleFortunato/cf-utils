/*
 * cf-utils.c
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#include "cf-utils.h"

static bool isvowel(char a){
	return
			a==A||a==tolower(A)||a==E||a==tolower(E)||a==I||a==tolower(I)||
			a==O||a==tolower(O)||a==U||a==tolower(U);
}

static bool iscons(char a){
	return isalpha(a)&&!isvowel(a);
}

static bool all_vow(char* text){
	bool flag=true;
	for (int i=ZERO;i<strlen(text)&&flag;i++)
		flag= isvowel(text[i]);
	return flag;
}

static bool all_cons(char* text){
	bool flag=true;
	for (int i=ZERO;i<strlen(text)&&flag;i++)
		flag= iscons(text[i]);
	return flag;
}

static bool char_in_text(const char* text, char a){
	bool flag = false;
	for (int i=ZERO;i<strlen(text)&&!flag;i++)
		flag = (a==text[i]);
	return flag;
}

static bool text_in_text(const char* text, char* a){
	bool flag = true;
	for (int i=ZERO;i<strlen(text)&&!flag;i++)
		flag = char_in_text(text,a[i]);
	return flag;
}

static void get_consonant(const char* text, char* cons, int* k, int i){
	if (iscons(text[i]))
		cons[(*k)++]=text[i];
}

static void get_consonants(const char* text, char* cons){
	int k=ZERO;
	for (int i=ZERO;i<strlen(text);i++)
		get_consonant(text,cons,&k,i);
	cons[k]=EOS;
}

static void get_vowel(const char* text, char* vow, int* k, int i){
	if (isvowel(text[i]))
		vow[(*k)++]=text[i];
}
static void get_vowels(const char* text, char* vow){
	int k=ZERO;
	for (int i=ZERO;i<strlen(text);i++)
		get_vowel(text,vow,&k,i);
	vow[k]=EOS;
}

void cons_vow(const char* text, char* cons, char* vow){
	assert(text!=NULL&&cons!=NULL&&vow!=NULL);
	get_vowels(text,vow);
	get_consonants(text,cons);
	assert(all_vow(vow)&&all_cons(cons)&&text_in_text(text,vow)&&text_in_text(text,cons));
}
