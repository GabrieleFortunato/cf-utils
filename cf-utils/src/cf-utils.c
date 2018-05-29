/*
 * cf-utils.c
 *
 *  Created on: 10 mag 2018
 *      Author: gabriele
 */

#include "cf-utils.h"
#include <stdio.h>

static bool isvowel(char a){
	return a==A||a==tolower(A)||a==E||a==tolower(E)||
			a==I||a==tolower(I)||a==O||a==tolower(O)||a==U||a==tolower(U);
}

static void getvowel(const char* a, char* b, int i, int* k){
	if (isvowel(a[i]))
		b[(*k)++]=a[i];
}

static void getvowels(const char* text, char* vow){
	int k=ZERO;
	for (int i=ZERO;i<strlen(text);i++)
		getvowel(text,vow,i,&k);
	vow[k]=EOS;
}

static bool isconsonant(char a){
	return isalpha(a)&&!isvowel(a);
}

static void getconsonant(const char* a, char* b, int i, int* k){
	if (isconsonant(a[i]))
		b[(*k)++]=a[i];
}

static void getconsonants(const char* text, char* cons){
	int k=ZERO;
	for (int i=ZERO;i<strlen(text);i++)
		getconsonant(text,cons,i,&k);
	cons[k]=EOS;
}

static bool allconsonants(char* string){
	bool flag = true;
	for (int i=ZERO;i<strlen(string)&&flag;i++)
		flag = isconsonant(string[i]);
	return flag;
}

static bool allvowels(char* string){
	bool flag = true;
	for (int i=ZERO;i<strlen(string)&&flag;i++)
		flag = isvowel(string[i]);
	return flag;
}

static bool charintext(const char* text, char string){
	bool flag = false;
	for (int i=ZERO;i<strlen(text)&&!flag;i++)
		flag = (text[i]==string)?true:false;
	return flag;
}

static bool textintext(const char* text, char* string){
	bool flag;
	for (int i=ZERO;i<strlen(string);i++)
		flag = charintext(text,string[i]);
	return flag;
}

void cons_vow(const char* text, char* cons, char* vow){
	assert(cons!=NULL);
	assert(text!=NULL);
	assert(vow!=NULL);
	getvowels(text,vow);
	getconsonants(text,cons);
	assert(strlen(text)>=(strlen(cons)+strlen(vow)));
	assert(allconsonants(cons));
	assert(allvowels(vow));
	assert(textintext(text,vow));
	assert(textintext(text,cons));
}
