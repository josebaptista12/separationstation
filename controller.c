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
	PARADO_V1
	INICIO_V1,
	LIGA_T2_V,
    ESTICA_1,
	RECOLHE_1,
	ARRANCA_T3,
} Separação_Verde_T1;
typedef enum{
	PARADO_A4
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
Contador_Azuis currentState1 = COUNT_AZUIS;
Contador_Verdes currentState1 = COUNT_VERDES;
LED_WAIT_BLINK currentState1 = LW_OFF;
Separação_Azul_T1 currentState1 = PARADO_A1;
Separação_Verde_T1 currentState1 = PARADO_V1;
Separação_Azul_T4 currentState1 = PARADO_A4;
Separação_Verde_T4 currentState1 = PARADO_V4;


// Tempo de ciclo
uint64_t  scan_time = 1000;	// 1 segundo


// Inicializa a ME
void init_ME1()
{
	
}
void init_ME2()
{
	
}
void init_ME3()
{
	
}
void init_ME4()
{
	
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

		#ifdef DEBUG
		printf ("\n*** Inicio do Ciclo ***\n");
		#endif


		// Leitura das entradas
		read_inputs();


		// Transição entre estados
		switch (currentState) {
		
			
			case Encher :
					
				// Testa transição Encher -> Esvaziar
				if (HI == 1)
					// Próximo estado
					currentState = Esvaziar;
			
				break;
			
			case Esvaziar :
				
				// Testa transição Esvaziar -> Encher
				if (LOW == 0)
					// Próximo estado
					currentState = Encher;
					
			break;
		} //end case
		

		// Atualiza saídas

		// Saídas booleanas
		FILL = (currentState == Encher);
		DRAIN = (currentState == Esvaziar);
		
		//Escrita nas saídas
		write_outputs();

		//Aguarda pelo próximo ciclo
		sleep_abs(scan_time);
		
	} // end loop
	
} // end main
