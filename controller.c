// ---------- Máquina de estados -----------

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
uint64_t  scan_time = 1;	// 1 segundo


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

// Código principal
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

		// Leitura das entradas
		read_inputs();

		// Transição entre estados
			switch (currentState1) {
					
			case PARADO :
				 int prevSTART = 0; // assuming START is initially HIGH
				 printf ("\n*** PARADO***\n");
				// Testa transição PARADO -> OPERAR
				 if (START == 1 && prevSTART == 0) {
					// Próximo estado
					currentState1 = OPERAR;
					prevSTART = START; }
					init_ME1();
				break;
			
			case OPERAR :
			printf ("\n*** OPERAR ***\n");
				int prevSTOP = 1;
				int A_PARAR_timer = 0; 
            	// Testa transição OPERAR -> A_PARAR
				if (STOP == 0 && prevSTOP == 1) {
					// Próximo estado
					currentState1 = A_PARAR;
					prevSTOP = STOP; }
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
			 	A_PARAR_timer++;
				int A_PARAR_timer2 = 0; 
                	// Testa transição A_PARAR -> A_PARAR2
				 if (A_PARAR_timer >= 1400) { 
                 if (SV1 == 0 && SV2 == 0) { 
					// Próximo estado
					currentState1 = A_PARAR2; }
				 }
					LWAIT=1;
					LSTART=0;
					LSTOP=0;
					E1=0;
					E2=0;
					T1A=1;
					T4A=1;
			break;
			
			case A_PARAR2 :
				printf ("\n*** oOLAAAAAAAAAAAAAAAAAAAA ***\n");
			    A_PARAR_timer2++;
				// Testa transição A_PARAR2 -> PARADO
				 if (A_PARAR_timer2 >= 2100) { 
                 if (ST2 == 0 && ST3 == 0) { 
					// Próximo estado
					currentState1 = PARADO; }
				 }
				T2A=1;
				T3A=1;
			break;
		} //end case
				
		// Atualiza saídas
		//Escrita nas saídas
		write_outputs();

		//Aguarda pelo próximo ciclo
		sleep_abs(scan_time);
		
	} // end loop
	
} // end main
