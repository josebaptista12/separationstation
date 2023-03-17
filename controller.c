// ---------- Máquina de estados -----------
/*

	FIZEMOS IMPLEMENTAÇÃO PERIÓDICA, 
	ACHO QUE TEMOS DE ALTERAR PARA CICLICAS


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
	LIGA_T2_A,
} Separação_Azul_T1;
typedef enum{
	PARADO_V1,
	INICIO_V1,
	LIGA_T2_V,
    ESTICA_1,
	RECOLHE_1,
	ARRANCA_T3,
} Separação_Verde_T1;
typedef enum{
	PARADO_A4,
	INICIO_A4,
	LIGA_T3_A,
    ESTICA_2,
	RECOLHE_2,
	ARRANCA_T2,
} Separação_Azul_T4;
typedef enum{
	PARADO_V4,
	INICIO_V4,
	LIGA_T3_V,
} Separação_Verde_T4;

// Funções
void ME1();
void ME2();
void ME3();
void ME4();
void ME5();
void ME6();
void ME7();
void ME8();

// Estado atual da máquina
Maq_Geral currentState1 = PARADO;
Contador_Azuis currentState2 = COUNT_AZUIS;
Contador_Verdes currentState3 = COUNT_VERDES;
LED_WAIT_BLINK currentState4 = LW_OFF;
Separação_Azul_T1 currentState5 = PARADO_A1;
Separação_Verde_T1 currentState6 = PARADO_V1;
Separação_Azul_T4 currentState7 = PARADO_A4;
Separação_Verde_T4 currentState8 = PARADO_V4;


// Tempo de ciclo
uint64_t scan_time = 200;	// 200ms

//VARIAVEIS FLANCOS

//re ==> rising edge
//fe ==> falling edge

bool p_START = 0;
bool p_STOP = 1;
bool p_ST2 = 0;
bool p_ST3 = 0;
bool p_STR = 0;
bool p_SPE=0;
bool p_SPR=0;
bool p_SV=0;
bool re_START = 0;
bool fe_START = 0;
bool re_STOP = 0;
bool fe_STOP = 0;
bool re_STR = 0;
bool fe_STR = 0;
bool re_ST2 = 0;
bool fe_ST2 = 0;
bool re_ST3 = 0;
bool fe_ST3 = 0;
bool re_SV = 0;
bool fe_SV = 0;

void edge_detection_start() {
	// Flancos ascendentes start
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
}

void edge_detection_stop(){
	
	// Flancos descendentes stop
	if (p_STOP == 1 && STOP == 0) {
 		fe_STOP = 1;
	}
	else {
 		fe_STOP = 0;
	}
	p_STOP=STOP;
}

// Implementar ME1
void init_ME1()
{
	LSTOP = 1;
	START = 0;
	LSTART=0;
	E1=0;
	E2=0;
	T1A=0;
	T2A=0;
	T3A=0;
	T4A=0;
	LWAIT=0;
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

	typedef struct {
	bool on;
	uint64_t time;
	} timerBlock;

	timerBlock timer1, timer2, timer3, timer4, timer5;

	void update_timers() {
			// Atualiza temporizadores
			if (timer1.on)
			timer1.time = timer1.time + scan_time;
			if (timer2.on)
			timer2.time = timer2.time + scan_time;
			if (timer3.on)
			timer2.time = timer2.time + scan_time; 
			if (timer4.on)
			timer2.time = timer2.time + scan_time; 
			if (timer5.on)
			timer2.time = timer2.time + scan_time; 
			}
	void start_timer(timerBlock* t) {
		t->on = true;
		t->time = 0;
	}
	void stop_timer(timerBlock* t) {
		t->on = false;
		t->time = 0; }
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
	
	
	// Ciclo de execução
	while(1) {

        update_timers();
		// Leitura das entradas
		read_inputs();
       
		// Transição entre estados
		    void ME1() {
			edge_detection_start();
			edge_detection_stop();
		
			switch (currentState1) {
			
			case PARADO :
			
				  printf ("\n*** PARADO***\n");
				// Testa transição PARADO -> OPERAR
				 if (re_START == 1) {
					// Próximo estado
					printf ("\n*** KKKKKK***\n");
					currentState1 = OPERAR;
					}
					init_ME1();
				break;
			
			case OPERAR :
			printf ("\n*** OPERAR ***\n");
				 
            	// Testa transição OPERAR -> A_PARAR
				if (fe_STOP == 1) {
					// Próximo estado
					currentState1 = A_PARAR;
					start_timer(&timer1);

					 }
					LSTART=1;
				    E1=1;
				    E2=1;
				    T1A=1;
					T2A=1;
					T3A=1;
				    T4A=1;
										
			break;

			case A_PARAR :
			printf ("\n*** A_PARAR ***\n");
			       	// Testa transição A_PARAR -> A_PARAR2
				 if (timer1.time >= 10000) { 
                 if (SV1 == 0 && SV2 == 0) { 
					// Próximo estado
					stop_timer(&timer1);
					currentState1 = A_PARAR2;
					start_timer(&timer2); }
				 }
					LWAIT=1;
					LSTART=0;
					LSTOP=0;
					E1=0;
					E2=0;
					T1A=1;
					T2A=0;
					T3A=0;
					T4A=1;
			break;
			
			case A_PARAR2 :
				printf ("\n*** oOLAAAAAAAAAAAAAAAAAAAA ***\n");
				// Testa transição A_PARAR2 -> PARADO
				 if (timer2.time >= 15000) { 
                 if (ST2 == 0 && ST3 == 0) { 
					// Próximo estado
					stop_timer(&timer2);
					currentState1 = PARADO; }
				 }
				T1A=0;
				T2A=1;
				T3A=1;
				T4A=0;
			break;
		}
		} //end case

		void ME2() {
		if (re_START == 1) {
			AZUIS = 0; 
		}
		if (re_ST2 == 1) {
			AZUIS = AZUIS + 1; 
		}
	}
	    void ME3() {
		if (re_START == 1) {
			VERDES = 0; 
		}
		if (re_ST3 == 1) {
			VERDES = VERDES + 1; 
		}
	}
		// Transição entre estados
		ME1();
		ME2();
		ME3();
		
		//Escrita nas saídas
		write_outputs();

		//Aguarda pelo próximo ciclo
		sleep_abs(scan_time);
		
	} // end loop
	
} // end main
