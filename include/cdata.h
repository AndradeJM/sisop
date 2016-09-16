/*
 * cdata.h: arquivo de inclus�o de uso apenas na gera��o da libpithread
 *
 * Esse arquivo pode ser modificado. ENTRETANTO, deve ser utilizada a TCB fornecida
 *
 */
#ifndef __cdata__
#define __cdata__
#include <ucontext.h>

#include "../include/support.h"
#include "../include/cthread.h"

#define	PROCST_CRIACAO	0
#define	PROCST_APTO	1
#define	PROCST_EXEC	2
#define	PROCST_BLOQ	3
#define	PROCST_TERMINO	4

/* N�O ALTERAR ESSA struct */
typedef struct s_TCB { 
	int		tid; 		// identificador da thread
	int		state;		// estado em que a thread se encontra
					// 0: Cria��o; 1: Apto; 2: Execu��o; 3: Bloqueado e 4: T�rmino
	int 		ticket;		// "bilhete" de loteria da thread, para uso do escalonador
	ucontext_t 	context;	// contexto de execu��o da thread (SP, PC, GPRs e recursos) 
} TCB_t; 

int createQueue(PFILA2 fila);
void dispatch(PFILA2 filaAptos,PFILA2 executando);
int generateTicket();
void runsThroughQueue(PFILA2 fila);
TCB_t *searchForBestTicket(PFILA2 fila, int loteryTicket);
int searchForTid(PFILA2 fila, int tid);
void terminate(ucontext_t contextMain, PFILA2 filaBloqueados, PFILA2 filaAptos, PFILA2 executando);
void unjoinProcesses(PFILA2 filaBloqueados, PFILA2 filaAptos, int tidThreadTerminated);

#endif
