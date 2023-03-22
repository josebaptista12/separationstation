// ---------- Máquina de estados -----------
/*

	FALTA ARRANJAR AS MAQUINAS DE ESTADO DA SEPAÇAO


*/

#include "IO.c"


#undef DEBUG

// Tipos de dados

// Estados da máquina
typedef enum{
	PARADO,
	OPERAR,
	A_PARAR,
	A_PARAR2,
} Maq_Geral;
typedef enum{
	COUNT_AZUIS,
} Contador_Azuis;
typedef enum{
	COUNT_VERDES,
} Contador_Verdes;
typedef enum{
	LW_OFF,
	LW_ON,
} LED_WAIT_BLINK;
typedef enum{
	PARADO_A1,
	INICIO_A1,
	DETETOU_AZUL,
	AVANÇA_T1,
	INICIA_TRANSF1,
	AVANÇA_T2
} Separação_Azul_T1;
typedef enum{
	PARADO_V1,
	INICIO_V1,
	DETETOU_VERDE,
	AVANÇA_V_T1,
	INICIA_TRANSF_V1,
	ESTICA_P1,
	RECOLHE_P1,
	AVANÇA_V_T3
} Separação_Verde_T1;
typedef enum{
	PARADO_A4,
	INICIO_A4,
	DETETOU_AZUL4,
    AVANÇA_A_T4,
	INICIA_TRANSF_A4,
	ESTICA_P2,
	RECOLHE_P2,
	AVANÇA_A_T2
} Separação_Azul_T4;
typedef enum{
	PARADO_V4,
	INICIO_V4,
	Detetou_VERDE4,
	AVANÇA_T4,
	INICIA_TRANSF2,
	AVANÇA_T3
} Separação_Verde_T4;
typedef enum{
	LIVRE,
	OCUPADO,
} Semaforo;

// Funções
void ME1();
void ME2();
void ME3();
void ME4();
void ME5();
void ME6();
void ME7();
void ME8();
void ME9();


Maq_Geral currentState1 = PARADO;
Contador_Azuis currentState2 = COUNT_AZUIS;
Contador_Verdes currentState3 = COUNT_VERDES;
LED_WAIT_BLINK currentState4 = LW_OFF;
Separação_Azul_T1 currentState5 = PARADO_A1;
Separação_Verde_T1 currentState6 = PARADO_V1;
Separação_Azul_T4 currentState8 = PARADO_A4;
Separação_Verde_T4 currentState7 = PARADO_V4;
Semaforo currentState9 = LIVRE;


Maq_Geral nextState1 = PARADO;
Contador_Azuis nextState2= COUNT_AZUIS;
Contador_Verdes nextState3= COUNT_VERDES;
LED_WAIT_BLINK nextState4 = LW_OFF;
Separação_Azul_T1 nextState5= PARADO_A1;
Separação_Verde_T1 nextState6 = PARADO_V1;
Separação_Azul_T4 nextState8= PARADO_A4;
Separação_Verde_T4 nextState7= PARADO_V4;
Semaforo nextState9 = LIVRE;
/*Tempo de ciclo
uint64_t scan_time = 25;	*/



bool p_START = 0;
bool p_STOP = 1;
bool p_ST2 = 0;
bool p_ST3 = 0;
bool p_STR1 = 0;
bool p_STR2 = 0;
bool p_SPE1=0;
bool p_SPR1=0;
bool p_SV=0;
bool re_START = 0;
bool fe_START = 0;
bool re_STOP = 0;
bool fe_STOP = 0;
bool re_STR1 = 0;
bool fe_STR1 = 0;
bool fe_STR2 = 0;
bool re_ST2 = 0;
bool fe_ST2 = 0;
bool re_ST3 = 0;
bool fe_ST3 = 0;
bool re_SV = 0;
bool fe_SV = 0;
bool re_SPE1 = 0;
bool re_SPR1 = 0;
bool fe_SPE1 = 0;
bool fe_SPR1 = 0;


void edge_detection() {
	if (p_START == 0 && START == 1) {
 		re_START = 1;
	}
	else {
 		re_START = 0;
	}
	p_START=START;

	if (p_ST2 == 0 && ST2 == 1) {
 		re_ST2 = 1;
	}
	else {
 		re_ST2 = 0;
	}
	p_ST2=ST2;

	if (p_ST3 == 0 && ST3 == 1) {
 		re_ST3 = 1;
	}
	else {
 		re_ST3 = 0;
	}
	p_ST3=ST3;

	if (p_SPE1 == 0 && SPE1 == 1) {
 		re_SPE1 = 1;
	}
	else {
 		re_SPE1 = 0;
	}
	p_SPE1=SPE1;

	if (p_SPR1 == 0 && SPR1 == 1) {
 		re_SPR1 = 1;
	}
	else {
 		re_SPR1 = 0;
	}
	p_SPR1=SPR1;
	if (p_STOP == 1 && STOP == 0) {
 		fe_STOP = 1;
	}
	else {
 		fe_STOP = 0;
	}
	p_STOP=STOP;

	if (p_ST2 == 1 && ST2 == 0) {
 		fe_ST2 = 1;
	}
	else {
 		fe_ST2 = 0;
	}
	p_ST2=ST2;

	if (p_STR1 == 1 && STR1 == 0) {
 		fe_STR1 = 1;
	}
	else {
 		fe_STR1 = 0;
	}
	p_STR1=STR1;

	if (p_STR2 == 1 && STR2 == 0) {
 		fe_STR2 = 1;
	}
	else {
 		fe_STR2 = 0;
	}
	p_STR2=ST2;

	if (p_ST3 == 1 && ST3 == 0) {
 		fe_ST3 = 1;
	}
	else {
 		fe_ST3 = 0;
	}
	p_ST3=ST3;
}


// Implementar ME1
void init_ME1()
{
	LSTOP = 1;
	E1=0;
	E2=0;

}
void init_ME2()
{
	AZUIS = 0;
}
void init_ME3()
{
	VERDES = 0;
}
void init_ME4()
{
	LWAIT=0;
}
void init_ME5()
{
	
}
void init_ME6()
{
	
}
void init_ME7()
{
	
}
void init_ME8()
{
	
}
void init_ME9()
{
	
}
typedef struct {
	bool on;
	uint64_t time;
} timerBlock;

timerBlock timer1, timer2, timer3, timer4, timer5;

uint64_t start_time=0, end_time=0, cycle_time=0;

void update_timers(){

 	end_time = get_time();

 	if (start_time == 0) {
 		cycle_time = 0;
	}
	else {
 		cycle_time = end_time - start_time;
	}

	// o fim do ciclo atual é o inicio do próximo 
	start_time = end_time;
    // Atualiza temporizadores
 	if (timer1.on)
 		timer1.time = timer1.time + cycle_time;
	if (timer2.on)
 		timer2.time = timer2.time + cycle_time;
	if (timer3.on)
 		timer3.time = timer3.time + cycle_time;
	if (timer4.on)
 		timer4.time = timer4.time + cycle_time;
    if (timer5.on)
 		timer5.time = timer5.time + cycle_time;
}
void start_timer(timerBlock* t) {
	t->on = true;
	t->time = 0;
}
void stop_timer(timerBlock* t) {
	t->on = false;
	t->time = 0; 
}


void ME1() {
		
	switch (currentState1) {
			
		case PARADO :
			/*T2A=0;
			T3A=0;*/
			//printf ("\n*** PARADO***\n");
			// Testa transição PARADO -> OPERAR
			if (re_START == 1) {
				// Próximo estado
				printf ("\n*** KKKKKK***\n");
				nextState1 = OPERAR;
			}
			init_ME1();
			break;
			
		case OPERAR :
			//printf ("\n*** OPERAR ***\n");
				
			// Testa transição OPERAR -> A_PARAR
			if (fe_STOP == 1) {
				// Próximo estado
				nextState1 = A_PARAR;
				start_timer(&timer1);
				start_timer(&timer3);
				
			}
			/*LSTART=1;
			LWAIT=0;
			LSTOP = 0;
			E1=1;
			E2=1;
			T1A=1;
			T2A=1;
			T3A=1;
			T4A=1;*/
			break;

		case A_PARAR :
			//printf ("\n*** A_PARAR ***\n");
			// Testa transição A_PARAR -> A_PARAR2
			if (timer1.time >= 10000) { 
				if (SV1 == 0 && SV2 == 0) { 
					// Próximo estado
					stop_timer(&timer1);
					stop_timer(&timer3);

					
					nextState1 = A_PARAR2;
					start_timer(&timer2);
					start_timer(&timer4);
					
				}
			}
			/*LSTART=0;
			LSTOP=0;
			E1=0;
			E2=0;
			T1A=1;
			T2A=1;
			T3A=1;
			T4A=1;*/
			break;
		
		case A_PARAR2 :
			//printf ("\n*** oOLAAAAAAAAAAAAAAAAAAAA ***\n");
			// Testa transição A_PARAR2 -> PARADO
			if (timer2.time >= 15000) { 
				if (ST2 == 0 && ST3 == 0) { 
					// Próximo estado
					stop_timer(&timer2);
					stop_timer(&timer4);
					nextState1 = PARADO; 
				}
			}
			/*T1A=0;
			T2A=1;
			T3A=1;
			T4A=0;*/
			break;
	}	
}

void ME2() {
	//CONTER AZUIS
	if (re_START == 1) {
		AZUIS = 0; 
	}
	if (re_ST2 == 1) {
		AZUIS = AZUIS + 1; 
	}
}
void ME3() {
	//COUNTER VERDES
	if (re_START == 1) {
		VERDES = 0; 
	}
	if (re_ST3 == 1) {
		VERDES = VERDES + 1; 
	}
}

void ME4() {
    // LWAIT BLINKING
    if (currentState1 == A_PARAR) {
        switch (currentState4) {
            case LW_OFF:
                if (timer3.time >= 1000 && LWAIT == 0) {
                    nextState4 = LW_ON;
                }
                init_ME4();
                printf("ENTROU NO CARALHO DO BLINKING\n");
                break;
            case LW_ON:
                if (timer3.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
                }
                //LWAIT = 1;
                break;
        }
    }
    else if (currentState1 == A_PARAR2) {
        switch (currentState4) {
            case LW_OFF:
                if (timer4.time >= 1000 && LWAIT == 0) {
                    nextState4 = LW_ON;
                }
                //init_ME4();
                break;
            case LW_ON:
                if (timer4.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
                }
                //LWAIT = 1;
                break;
        }
    }
}

void ME5() {
		
	switch (currentState5) {
			
		case PARADO_A1 :
			if(currentState1 == OPERAR || currentState1 == A_PARAR) {
				// Próximo estado
				printf("ASSS\n");
				nextState5 = INICIO_A1;
			}
			init_ME5();
			break;
			
		case INICIO_A1 :
			// 
			if (SV1 == 1 /*&& currentState9==LIVRE*/) {
				// Próximo estado
				printf("SEI\n");
				nextState5 = LIGA_T2_A;		
			}
			break;

		case LIGA_T2_A :
			//
			if (re_ST2 == 1) { 
				nextState5 = PARADO_A1;
			}
			//T2A=1;
			break;
	}	
}

void ME6() {

		
	switch (currentState6) {
			
		case PARADO_V1 :
			if(currentState1 == OPERAR || currentState1 == A_PARAR) {
				// Próximo estado

				nextState6 = INICIO_V1;
			}
			//init_ME6();
			break;
			
		case INICIO_V1 :
	 
			if (SV1==4) {
				// Próximo estado

				nextState6 = LIGA_T2_V1;		
			}
			break;

		case LIGA_T2_V1 :
			//problema aqui
			if (fe_STR1 == 1 /*&& currentState9==LIVRE*/) { 

				nextState6 = ESTICA_1;

			}

			//T2A=1;
			break;

		case ESTICA_1 :
			// 
			
			if (SPE1== 1) {
				// Próximo estado
				nextState6 = RECOLHE_1;	
			}
			/*T1A=0;
			T2A=0;
			T3A=0;
			T4A=0;
			PE1=1;*/
			break;

		case RECOLHE_1 :
			// 
			if (SPR1 == 1) {
				// Próximo estado
				
				nextState6 = ARRANCA_T3;		
			}
			/*PE1=0;
			PR1=1;
			T1A=0;
			T2A=0;
			T3A=0;
			T4A=0;*/
			break;

		case ARRANCA_T3 :
			// 
			if (re_ST3 == 1) {
				// Próximo estado
				nextState6 = PARADO_V1;		
			}
			/*PR1=0;
			T1A=1;
			T2A=1;
			T3A=1;
			T4A=1;*/
			break;

	}	
}

void ME7() {
		
	switch (currentState7) {
			
		case PARADO_V4 :
			if(currentState1 == OPERAR || currentState1 == A_PARAR) {
				// Próximo estado
				
				nextState7 = INICIO_V4;
			}
			
			//init_ME7();
			break;
			
		case INICIO_V4 :
			// 
			if (SV2 == 4 /*&& currentState9==LIVRE*/) {
				// Próximo estado
				
				nextState7 = LIGA_T3_V;		
			}
			break;

		case LIGA_T3_V :
			//
			if (re_ST3 == 1) { 
				nextState7 = PARADO_V4;

			}
			//T3A=1;
			break;
	}	
}

void ME8() {

		
	switch (currentState8) {
			
		case PARADO_A4 :
			printf("\n\n\nENTROU NO ME8\n\n\n");
			if(currentState1 == OPERAR || currentState1 == A_PARAR) {
				// Próximo estado
				printf("\n\n\nSALTA PARA A 2a ETAPA\n\n\n");
				nextState8 = INICIO_V4;
			}
			//init_ME8();
			break;
			
		case INICIO_A4 :
			// 
			if (SV2==1) {
				// Próximo estado
				printf("\n\n\nSALTA PARA A 3a ETAPA\n\n\n");
				nextState8 = LIGA_T3_A;		
			}
			break;

		case LIGA_T3_A :
			
			if (fe_STR2 == 1 && currentState9==LIVRE) { 
				printf("\n\n\nSALTA PARA A 4a ETAPA\n\n\n");
				nextState8 = ESTICA_2;
				/*T1A=0;
				T2A=0;
				T3A=0;
				T4A=0;*/

			}

			//T3A=1;
			break;

		case ESTICA_2 :
			// 
			printf("\n\n\nSALTRA PAA A 5a ETAPA\n\n\n");
			if (SPE2== 1) {
				// Próximo estado
				//problema aqui!!!!!!!!!!!!!//problema aqui!!!!!!!!!!!!! NUNCA ENTRA AQUI
				nextState6 = RECOLHE_2;	
				printf("\n\n\n\nSALTA PARA A 6a ETAPA\n\n\n");	
			}

			//PE2=1;
			break;

		case RECOLHE_2:
			// 
			if (SPR2 == 1) {
				// Próximo estado
				
				nextState6 = ARRANCA_T2;		
				printf("\n\n\nSALTA PARA A 7 a ETAPA\n\n\n");
			}
			/*PE2=0;
			PR2=1;*/
			break;

		case ARRANCA_T2 :
			// 
			if (re_ST3 == 1) {
				// Próximo estado
				printf("\n\n\nSALTA PARA A 7a ETAPA\n\n\n");
				nextState6 = PARADO_A4;		
			}
			/*PR2=0;
			T1A=1;
			T2A=1;
			T3A=1;
			T4A=1;*/
			break;

	}	
}
/*
void ME9() {
	switch (currentState9) {
			
		case LIVRE :
			if(SV1>0 || SV2 >0) {
				// Próximo estado
				printf("\n\n\nOCUPADO\n\n\n");
				nextState9 = OCUPADO;
			}
			//init_ME9();
			break;
			
		case OCUPADO :
			// 
			if (re_ST2 || re_ST3) {
				// Próximo estado
				printf("\n\n\n\nLIVRE\n\n\n\n");
				nextState9 = LIVRE;		
			}
			break;

	}	
}
*/


int main() {

	
	// Inicialização das ME
	init_ME1();
	init_ME2();
	init_ME3();
	init_ME4();
	init_ME5();
	init_ME6();
	init_ME7();
	init_ME8();
	init_ME9();

	
	// Ciclo de execução
	while(1) {

        
		// Leitura das entradas
		read_inputs();
       
		update_timers();
		// Transição entre estados
		edge_detection();	    
		
		// Transição entre estados
		ME1();
		ME2();
		ME3();
		ME4();
		ME5();
		ME6();
		ME7();
		ME8();
		//ME9();

		currentState1 = nextState1;
        currentState2 = nextState2;
        currentState3 = nextState3;
        currentState4 = nextState4;
        currentState5 = nextState5;
        currentState6 = nextState6;
        currentState7 = nextState7;
        currentState8 = nextState8;
        currentState9 = nextState9;

		LSTOP = (currentState1 == PARADO);
		LSTART = (currentState1 == OPERAR);
		E1 = ( currentState1 == OPERAR);
        E2 = ( currentState1 == OPERAR);
		LWAIT = (currentState4 == LW_ON);
		T1A = (currentState5 == INICIO_A1) || (currentState5 == AVANÇA_T1) || (currentState5 == INICIA_TRANSF1) || (currentState6 == INICIO_V1) || (currentState6 == AVANÇA_V_T1) || (currentState5 == INICIA_TRANSF_V1);
		T2A = (currentState5 == INICIA_TRANSF1) || (currentState5 == AVANÇA_T2) || (currentState6 == INICIA_TRANSF_V1) || (currentState8 == AVANÇA_A_T2);
        T3A = (currentState6 == AVANÇA_V_T3) || (currentState7 == INICIA_TRANSF2) || (currentState7 == AVANÇA_T3) || (currentState8 == INICIA_TRANSF_A4);
		T4A = (currentState7 == INICIO_V4) || (currentState7 == AVANÇA_T4) || (currentState7 == INICIA_TRANSF2) || (currentState8 == INICIO_A4) || (currentState8 == AVANÇA_A_T4) || (currentState8 == INICIA_TRANSF_A4);
		PE1 = (currentState6 == ESTICA_P1);
		PR1 = (currentState6 == RECOLHE_P1);
        PE2 = (currentState8 == ESTICA_P2);
		PR2 = (currentState8= RECOLHE_P2);
        

		//Escrita nas saídas
		write_outputs();

			
	} // end loop
	
} // end main
