// ---------- Máquina de estados -----------
/*

	FALTA ARRANJAR AS MAQUINAS DE ESTADO DA SEPARAÇÃO


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
	PARADO_S,
	INICIO,
	//
	AZUL1_ESPERA,
	//
	//
	AZUL_AZUL,
	TRANSF1,
	LIMPA1,
	AZUL_AZUL2,
	TRANSF2,
	ESTICA2_1,
	RECOLHE2_1,
	LIMPA2,
	//
	AZUL_VERDE,
	TRANSF_CONJUNTA,
	LIMPA_CONJUNTO,
	//
	//
	VERDE1_ESPERA,
	VERDE_AZUL,
	TRANSF3,
	ESTICA1_1,
	RECOLHE1_1,
	LIMPA3,
	VERDE_AZUL2,
	TRANSF4,
	ESTICA2_2,
	RECOLHE2_2,
	LIMPA4,
	//
	VERDE_VERDE,
	TRANSF5,
	ESTICA1_2,
	RECOLHE1_2,
	LIMPA5,
	VERDE_VERDE2,
	TRANSF6,
	LIMPA6,
	//
	//
	AZUL1_ESPERA,
	//
	//
	AZUL2_ESPERA,
	//
	AZUL_AZUL3,
	TRANSF7,
	LIMPA7,
	AZUL_AZUL4,
	TRANSF8,
	ESTICA2_3,
	RECOLHE2_3,
	LIMPA8,
	//
	AZUL_VERDE3,
	TRANSF_CONJUNTA2,
	LIMPA_CONJUNTO2,
	//
	//
	VERDE2_ESPERA,
	VERDE_AZUL3,
	TRANSF9,
	ESTICA1_3,
	RECOLHE1_3,
	LIMPA9,
	VERDE_AZUL4,
	TRANSF10,
	ESTICA2_4,
	RECOLHE2_4,
	LIMPA10,
	//
	VERDE_VERDE3,
	TRANSF11,
	ESTICA1_4,
	RECOLHE1_4,
	LIMPA11,
	VERDE_VERDE4,
	TRANSF12,
	LIMPA12,
} Separação;
/*typedef enum{
	PARADO_V1,
	INICIO_V1,
	ESPERA_V1,
	AVANÇA_V_T1,
	INICIA_TRANSF_V1,
	ESTICA_P1,
	RECOLHE_P1,
	AVANÇA_V_T3
} Separação_Verde_T1;
typedef enum{
	PARADO_A4,
	INICIO_A4,
	ESPERA_A4,
    AVANÇA_A_T4,
	INICIA_TRANSF_A4,
	ESTICA_P2,
	RECOLHE_P2,
	AVANÇA_A_T2
} Separação_Azul_T4;
typedef enum{
	PARADO_V4,
	INICIO_V4,
	ESPERA_V4,
	AVANÇA_T4,
	INICIA_TRANSF2,
	AVANÇA_T3
} Separação_Verde_T4;
typedef enum{
	LIVRE,
	OCUPADO,
	//T4_CEDE
} Semaforo;*/

// Funções
void ME1();
void ME2();
void ME3();
void ME4();
void ME5();
/*void ME6();
void ME7();
void ME8();
void ME9();*/


Maq_Geral currentState1 = PARADO;
Contador_Azuis currentState2 = COUNT_AZUIS;
Contador_Verdes currentState3 = COUNT_VERDES;
LED_WAIT_BLINK currentState4 = LW_OFF;
Separação currentState5 = PARADO_S;
/*Separação_Verde_T1 currentState6 = PARADO_V1;
Separação_Verde_T4 currentState7 = PARADO_V4;
Separação_Azul_T4 currentState8 = PARADO_A4;
Semaforo currentState9 = LIVRE;*/


Maq_Geral nextState1 = PARADO;
Contador_Azuis nextState2= COUNT_AZUIS;
Contador_Verdes nextState3= COUNT_VERDES;
LED_WAIT_BLINK nextState4 = LW_OFF;
Separação nextState5= PARADO_S;
/*Separação_Verde_T1 nextState6 = PARADO_V1;
Separação_Azul_T4 nextState8= PARADO_A4;
Separação_Verde_T4 nextState7= PARADO_V4;
Semaforo nextState9 = LIVRE;*/
/*Tempo de ciclo
uint64_t scan_time = 25;	*/



bool p_START = 0;
bool p_STOP = 1;
bool pf_ST2 = 0;
bool p_ST2 = 0;
bool p_ST3 = 0;
bool pf_ST3 = 0;
bool pr_STR1 = 0;
bool pf_STR1 = 0;
bool p_STR2 = 0;
bool pf_STR2 = 0;
bool p_SPE1=0;
bool p_SPR1=0;
bool p_SV=0;
bool re_START = 0;
bool fe_START = 0;
bool re_STOP = 0;
bool fe_STOP = 0;
bool re_STR1 = 0;
bool fe_STR1 = 0;
bool re_STR2 = 0;
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

	if (pr_STR1 == 0 && STR1 == 1) {
 		re_STR1 = 1;
	}
	else {
 		re_STR1 = 0;
	}
	pr_STR1=STR1;

	if (p_STOP == 1 && STOP == 0) {
 		fe_STOP = 1;
	}
	else {
 		fe_STOP = 0;
	}
	p_STOP=STOP;

	if (p_STR2 == 0 && STR2 == 1) {
 		re_STR2 = 1;
	}
	else {
 		re_STR2 = 0;
	}
	p_STR2=STR2;
	if (pf_ST2 == 1 && ST2 == 0) {
 		fe_ST2 = 1;
	}
	else {
 		fe_ST2 = 0;
	}
	pf_ST2=ST2;

	if (pf_STR1 == 1 && STR1 == 0) {
 		fe_STR1 = 1;
	}
	else {
 		fe_STR1 = 0;
	}
	pf_STR1=STR1;

	if (pf_STR2 == 1 && STR2 == 0) {
 		fe_STR2 = 1;
	}
	else {
 		fe_STR2 = 0;
	}
	pf_STR2=STR2;

	if (pf_ST3 == 1 && ST3 == 0) {
 		fe_ST3 = 1;
	}
	else {
 		fe_ST3 = 0;
	}
	pf_ST3=ST3;
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
/*void init_ME6()
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
	
}*/
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
			
			//printf ("\n*** PARADO***\n");
			// Testa transição PARADO -> OPERAR
			if (re_START == 1) {
				// Próximo estado
				//printf ("\n*** KKKKKK***\n");
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
			break;
		
		case A_PARAR2 :
			
			if (timer2.time >= 15000) { 
				if (ST2 == 0 && ST3 == 0) { 
					// Próximo estado
					stop_timer(&timer2);
					stop_timer(&timer4);
					nextState1 = PARADO; 
				}
			}
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
                break;
            case LW_ON:
                if (timer3.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
                }
        
                break;
        }
    }
    else if (currentState1 == A_PARAR2) {
        switch (currentState4) {
            case LW_OFF:
                if (timer4.time >= 1000 && LWAIT == 0) {
                    nextState4 = LW_ON;
                }
                break;
            case LW_ON:
                if (timer4.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
                }
                break;
        }
    }
}

void ME5() {

}



int main() {


	// Inicialização das ME
	init_ME1();
	init_ME2();
	init_ME3();
	init_ME4();
	init_ME5();
	/*init_ME6();
	init_ME7();
	init_ME8();
	init_ME9();*/

	
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
		/*ME9();
		ME5();
		ME9();
		ME6();
		ME9();
		ME7();
		ME9();
		ME8();*/
		

		currentState1 = nextState1;
        currentState2 = nextState2;
        currentState3 = nextState3;
        currentState4 = nextState4;
        currentState5 = nextState5;
        /*currentState6 = nextState6;
        currentState7 = nextState7;
        currentState8 = nextState8;
        currentState9 = nextState9;*/

		LSTOP = (currentState1 == PARADO);
		LSTART = (currentState1 == OPERAR);				
		E1 = ( currentState1 == OPERAR);
        E2 = ( currentState1 == OPERAR);
		LWAIT = (currentState4 == LW_ON);
		T1A = (currentState5 == INICIO) || (currentState5 == AZUL_AZUL) || (currentState5 == TRANSF1) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == VERDE_AZUL) || (currentState5 == TRANSF3) || (currentState5 == VERDE_VERDE) || (currentState5 == TRANSF5) || (currentState5 == AZUL2_ESPERA) || (currentState5 == AZUL_AZUL3) || (currentState5 == TRANSF7) || (currentState5 == AZUL_VERDE3) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == VERDE2_ESPERA)|| (currentState5 == VERDE_AZUL3) || (currentState5 == TRANSF9) || (currentState5 == VERDE_VERDE3) || (currentState5 == TRANSF11);
		T2A = (currentState5 == TRANSF1) || (currentState5 == LIMPA1) || (currentState5 == LIMPA2) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == LIMPA_CONJUNTO)|| (currentState5 == TRANSF3)|| (currentState5 == LIMPA4)|| (currentState5 == TRANSF5) || (currentState5 == TRANSF7) || (currentState5 == LIMPA7) || (currentState5 == LIMPA8) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == LIMPA_CONJUNTO2)|| (currentState5 == TRANSF9)|| (currentState5 == LIMPA10)|| (currentState5 == TRANSF11);
        T3A = (currentState5 == TRANSF2) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == LIMPA_CONJUNTO) || (currentState5 == LIMPA3) || (currentState5 == TRANSF4) || (currentState5 == LIMPA5) || (currentState5 == TRANSF6) || (currentState5 == LIMPA6) || (currentState5 == TRANSF8) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == LIMPA_CONJUNTO2) || (currentState5 == LIMPA9) || (currentState5 == TRANSF10) || (currentState5 == LIMPA11) || (currentState5 == TRANSF12) || (currentState5 == LIMPA12);
		T4A = (currentState5 == INICIO) || (currentState5 == AZUL1_ESPERA) || (currentState5 == AZUL_AZUL2) || (currentState5 == TRANSF2) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == VERDE1_ESPERA) || (currentState5 == VERDE_AZUL2) || (currentState5 == TRANSF4) || (currentState5 == VERDE_VERDE2) || (currentState5 == TRANSF6) || (currentState5 == AZUL_AZUL4) || (currentState5 == TRANSF8) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == VERDE_AZUL4) || (currentState5 == TRANSF10) || (currentState5 == VERDE_VERDE4) || (currentState5 == TRANSF12);																							
		PE1 = (currentState5 == ESTICA1_1) || (currentState5 == ESTICA1_2) || (currentState5 == ESTICA1_3) || (currentState5 == ESTICA1_4);
		PR1 = (currentState5 == RECOLHE1_1) || (currentState5 == RECOLHE1_2) || (currentState5 == RECOLHE1_3) || (currentState5 == RECOLHE1_4);
        PE2 = (currentState5 == ESTICA2_1) || (currentState5 == ESTICA2_2) || (currentState5 == ESTICA2_3) || (currentState5 == ESTICA2_4);
		PR1 = (currentState5 == RECOLHE2_1) || (currentState5 == RECOLHE2_2) || (currentState5 == RECOLHE2_3) || (currentState5 == RECOLHE2_4);
		//printf("%d\n", currentState8);
		


		//Escrita nas saídas
		write_outputs();

			
	} // end loop
	
} // end main