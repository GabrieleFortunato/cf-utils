/*
 ============================================================================
 Name        : cf-utils_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 *  Semplice template di CUnit.
 *
 *  L'esempio e' tratto da http://cunit.sourceforge.net/example.html e semplificato
 *  per scopi didattici.
 *
 */

#include <stdio.h>
#include "CUnit/Basic.h"

#include "cf-utils.h"


/* Funzione di inizializzazione. */
int init_suite1(void)
{
	return 0;	// nessuna inizializzazioe
}

/* Funzione di cleanup. */
int clean_suite1(void)
{
	return 0; // nessun cleanup
}


/* Test method */
void test_fun1(void)
{
	char vow[20];
	char cons[20];

	cons_vow("a", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "a");
	cons_vow("aiuom", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "m"); CU_ASSERT_STRING_EQUAL(vow, "aiuo");
	cons_vow("vBnMeio", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "vBnM"); CU_ASSERT_STRING_EQUAL(vow, "eio");
	cons_vow("ghj", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "ghj"); CU_ASSERT_STRING_EQUAL(vow, "");
	cons_vow("oy", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "y"); CU_ASSERT_STRING_EQUAL(vow, "o");
	cons_vow("tu", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "t"); CU_ASSERT_STRING_EQUAL(vow, "u");
	cons_vow("wr", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "wr"); CU_ASSERT_STRING_EQUAL(vow, "");
	cons_vow("ei", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "ei");
	cons_vow("q", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "q"); CU_ASSERT_STRING_EQUAL(vow, "");

}

/* Test method */
void test_fun2(void)
{
	char vow[20];
	char cons[20];

	cons_vow("", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "");
//	cons_vow("10", cons, vow);
//	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "");
	cons_vow("C Ii10", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "C"); CU_ASSERT_STRING_EQUAL(vow, "Ii");
	cons_vow("I z-X", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "zX"); CU_ASSERT_STRING_EQUAL(vow, "I");
//	cons_vow("KL O", cons, vow);
//	CU_ASSERT_STRING_EQUAL(cons, "KL"); CU_ASSERT_STRING_EQUAL(vow, "O");
	cons_vow("d' f", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, "df"); CU_ASSERT_STRING_EQUAL(vow, "");
	cons_vow(" ", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "");
//	cons_vow("p s", cons, vow);
//	CU_ASSERT_STRING_EQUAL(cons, "ps"); CU_ASSERT_STRING_EQUAL(vow, "");
	cons_vow("?", cons, vow);
	CU_ASSERT_STRING_EQUAL(cons, ""); CU_ASSERT_STRING_EQUAL(vow, "");
}

/* Test method */
void test_fun3(void)
{
	CU_PASS("test supplementare vuoto");
	char cons[50];
	char vow[50];
	cons_vow("CIAO",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"C");
	CU_ASSERT_STRING_EQUAL(vow,"IAO");
	cons_vow("IAO",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"");
	CU_ASSERT_STRING_EQUAL(vow,"IAO");
	cons_vow("C",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"C");
	CU_ASSERT_STRING_EQUAL(vow,"");
	cons_vow("DI ANA",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"DN");
	CU_ASSERT_STRING_EQUAL(vow,"IAA");
	cons_vow("D'ANA",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"DN");
	CU_ASSERT_STRING_EQUAL(vow,"AA");
	cons_vow("",cons,vow);
	CU_ASSERT_STRING_EQUAL(cons,"");
	CU_ASSERT_STRING_EQUAL(vow,"");
}

/* La funzione main() serve a strutturare ed eseguire i test.
 * Ritorna CUE_SUCCESS in caso di esecuzione con successo (tutti i test sono superati)
 * altrimenti restituisce un codice di errore come da documentazione CUnit.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test base", test_fun1)) ||
       (NULL == CU_add_test(pSuite, "test hard", test_fun2)) ||
	   (NULL == CU_add_test(pSuite, "test bh", test_fun3)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }


   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
