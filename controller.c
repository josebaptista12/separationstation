

#include "IO.c"


int aux1=0, aux2=0, aux3=0;
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

// Funções
void ME1();
void ME2();
void ME3();
void ME4();
void ME5();

Maq_Geral currentState1 = PARADO;
Contador_Azuis currentState2 = COUNT_AZUIS;
Contador_Verdes currentState3 = COUNT_VERDES;
LED_WAIT_BLINK currentState4 = LW_OFF;
Separação currentState5 = PARADO_S;


Maq_Geral nextState1 = PARADO;
Contador_Azuis nextState2= COUNT_AZUIS;
Contador_Verdes nextState3= COUNT_VERDES;
LED_WAIT_BLINK nextState4 = LW_OFF;
Separação nextState5= PARADO_S;


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
bool re_SPR1 = 0;
bool fe_SPR1 = 0;


void edge_detection() {
	
	re_START = (p_START == 0 && START == 1);
	p_START=START;


	re_STR1 = (pr_STR1 == 0 && STR1 == 1);
	pr_STR1=STR1;
	if(re_STR1) {
		aux1++;
	}

	re_STR2 = (p_STR2 == 0 && STR2 == 1);
	p_STR2=STR2;
	if(re_STR2) {
		aux1++;
	}

	fe_STR1 = (pf_STR1 == 1 && STR1 == 0);
	pf_STR1=STR1;
	if(fe_STR1) {
		aux2++;
	}

	fe_STR2 = (pf_STR2 == 1 && STR2 == 0);
	pf_STR2=STR2; 
	if(fe_STR2) {
		aux2++;
	}

	fe_STOP = (p_STOP == 1 && STOP == 0);
	p_STOP=STOP;

	fe_ST2 = (p_ST2 == 1 && ST2 == 0);
	p_ST2=ST2;
	if(fe_ST2) {
		aux3++;
	}

	fe_ST3 = (p_ST3 == 1 && ST3 == 0);
	p_ST3=ST3;
	if(fe_ST3) {
		aux3++;
	}
}


// Implementar ME1
void init_ME1()
{	LSTOP = 1;
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
{	}

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
 
	start_time = end_time;
    
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
			
			if (re_START == 1) {
				
				nextState1 = OPERAR;
			}
			init_ME1();
			break;
			
		case OPERAR :
			
			if (fe_STOP == 1) {
				// Próximo estado
				nextState1 = A_PARAR;
				start_timer(&timer1);
				start_timer(&timer3);
				
			}
			
			break;

		case A_PARAR :
			
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
	
	if (re_START == 1) {
		AZUIS = 0; 
	}
	if (fe_ST2 == 1) {
		AZUIS = AZUIS + 1; 
	}
}
void ME3() {
	
	if (re_START == 1) {
		VERDES = 0; 
	}
	if (fe_ST3 == 1) {
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
                    timer3.time=0;
                }
                break;
            case LW_ON:
                if (timer3.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
					timer3.time=0;
                }
        
                break;
        }
    }
    else if (currentState1 == A_PARAR2) {
        switch (currentState4) {
            case LW_OFF:
                if (timer4.time >= 1000 && LWAIT == 0) {
                    nextState4 = LW_ON;
					timer4.time=0;
                }
                break;
            case LW_ON:
                if (timer4.time >= 1000 && LWAIT == 1) {
                    nextState4 = LW_OFF;
					timer4.time=0;
                }
                break;
        }
    }
	else {
		nextState4=LW_OFF;
	}
}

void ME5() {  
	switch(currentState5) {
		//certo
        case PARADO_S:
		if(currentState1==OPERAR || currentState1 == A_PARAR){
			//printf("INICIO\n");
			nextState5=INICIO;
		}
		break;
        
		case INICIO:
		
		if(SV1==1){
			nextState5=AZUL1_ESPERA;
			//printf("AZUL1_ESPERA\n");
		}
		else if(SV1==4){
			nextState5=VERDE1_ESPERA;
			//printf("VERDE1_ESPERA\n");
		}
		else if(SV2==1){
			nextState5=AZUL2_ESPERA;
			//printf("AZUL2_ESPERA\n");
		}
		else if(SV2==4){
			nextState5=VERDE2_ESPERA;
			//printf("VERDE2_ESPERA\n");
		}
		else if(currentState1 == A_PARAR2) {
			nextState5 = PARADO_S;
		}
        break;

//------------RAMO  SV1=1 ----------- //

		case AZUL1_ESPERA:
			if(SV2==1) {
				nextState5 = AZUL_AZUL;
				//printf("AZUL_AZUL\n");
			}
			else if(SV2==4) {
				nextState5 = AZUL_VERDE;
				//printf("AZUL_VERDE\n");
				aux1=0;
			}
			break;
		case VERDE1_ESPERA:
			if(SV2==1) {
				nextState5 = VERDE_AZUL;
				//printf("VERDE_AZUL\n");
			}
			else if(SV2==4) {
				nextState5 = VERDE_VERDE;
				//printf("AZUL_VERDE\n");
			}
			break;

//------------RAMO  SV1=1  E sv2=1----------- //
		case AZUL_AZUL:
			if(re_STR1) {
				nextState5 = TRANSF1;
				//printf("TRANSF1\n");
			}
			break;

		case TRANSF1:
			if(fe_STR1) {
				nextState5 = LIMPA1;
				//printf("LIMPA1\n");
			}
			break;

		case LIMPA1:
			if(fe_ST2) {
				nextState5 = AZUL_AZUL2;
				//printf("AZUL_AZUL2\n");
			}
			break;

		case AZUL_AZUL2:
			if(re_STR2) {
				nextState5 = TRANSF2;
				//printf("TRANSF2\n");
			}
			break;

		case TRANSF2:
			if(fe_STR2) {
				nextState5 = ESTICA2_1;
				//printf("ESTICA2_1\n");
			}
			break;	

		case ESTICA2_1:
			if(SPE2==1) {
				nextState5 = RECOLHE2_1;
				//printf("RECOLHE2_1\n");
			}
			break;	

		case RECOLHE2_1:
			if(SPR2==1) {
				nextState5 = LIMPA2;
				//printf("LIMPA2\n");
			}
			break;

		case LIMPA2:
			if(fe_ST2) {
				nextState5 = PARADO_S;
				//printf("PARADO_S\n");
			}
			break;
//------------RAMO  SV1=1  E sv2=4----------- //

		case AZUL_VERDE:
			if(aux1==2) {
				nextState5 = TRANSF_CONJUNTA;
				//printf("TRANSF_CONJUNTA\n");
				aux2=0;
			}
			break;

		case TRANSF_CONJUNTA:
			if(aux2==2) {
				nextState5 = LIMPA_CONJUNTO;
				//printf("LIMPA_CONJUNTO\n");
				aux3=0;
			}
			break;

		case LIMPA_CONJUNTO:
			if(aux3==2) {
				nextState5 = PARADO_S;
			//	printf("PARADO_S\n");
			}
			break;

//------------RAMO  SV1=4  E sv2=1----------- //

		case VERDE_AZUL:
			if(re_STR1) {
				nextState5 = TRANSF3;
			//	printf("TRANSF3\n");
			}
			break;

		case TRANSF3:
			if(fe_STR1) {
				nextState5 = ESTICA1_1;
			//	printf("ESTICA1_1\n");
			}
			break;

		case ESTICA1_1:
			if(SPE1==1) {
				nextState5 = RECOLHE1_1;
			//	printf("RECOLHE1_1\n");
			}
			break;

		case RECOLHE1_1:
			if(SPR1==1) {
				nextState5 = LIMPA3;
			//	printf("LIMPA3\n");
			}
			break;

		case LIMPA3:
			if(fe_ST3) {
				nextState5 = VERDE_AZUL2;
			//	printf("VERDE_AZUL2\n");
			}
			break;	

		case VERDE_AZUL2:
			if(re_STR2) {
				nextState5 = TRANSF4;
			//	printf("TRANSF4\n");
			}
			break;	

		case TRANSF4:
			if(fe_STR2) {
				nextState5 = ESTICA2_2;
			//	printf("ESTICA2_2\n");
			}
			break;

		case ESTICA2_2:
			if(SPE2) {
				nextState5 = RECOLHE2_2;
			//	printf("RECOLHE2_2\n");
			}
			break;

		case RECOLHE2_2:
			if(SPR2) {
				nextState5 = LIMPA4;
			//	printf("LIMPA4\n");
			}
			break;

		case LIMPA4:
			if(fe_ST2) {
				nextState5 = PARADO_S;
			//	printf("PARADO_S\n");
			}
			break;

//------------RAMO  SV1=4  E sv2=4----------- //

case VERDE_VERDE:
			if(re_STR1) {
				nextState5 = TRANSF5;
			}
			break;

		case TRANSF5:
			if(fe_STR1) {
				nextState5=ESTICA1_2;  
			}
			break;
			
		case ESTICA1_2: 
			if(SPE1 == 1) {
				nextState5=RECOLHE1_2;
			}
			break;

		case RECOLHE1_2:
			if(SPR1 == 1) {
				nextState5=LIMPA5;
			}
			break;

		case LIMPA5:              
			if(fe_ST3 == 1) {
				nextState5=VERDE_VERDE2;
			}
			break;

		case VERDE_VERDE2:              
			if(re_STR2) {
				nextState5=TRANSF6;
			}
			break;

		case TRANSF6:              
			if(fe_STR2) {
				nextState5=LIMPA6;
			}
			break;

		case LIMPA6:
			if(fe_ST3) {
				nextState5=PARADO_S;
			}
			break;

//------------RAMO  SV2=4 ----------- // certo
		case VERDE2_ESPERA:
			if(SV1 == 1) {
				nextState5=VERDE_AZUL3;
			//	printf("VERDE_AZUL3\n");
			}
			else if(SV1 == 4) {
				nextState5=VERDE_VERDE3;
			//	printf("VERDE_VERDE3\n");
			}
			break;
//------------RAMO SV2=4 E SV1=4 ----------- // certo
       case VERDE_VERDE3:
			if(re_STR1) {
				nextState5 = TRANSF11;
			//	printf("TRANSF11\n");
			}
			break;

		case TRANSF11:
			if(fe_STR1) {
				nextState5=ESTICA1_4;  
			//	printf("ESTICA1_4\n");
			}
			break;
			
		case ESTICA1_4: 
			if(SPE1 == 1 && SPR1 == 0) {
			//	printf("%d\n", nextState5);
			//	printf("RECOLHE1_4\n");
				nextState5=RECOLHE1_4;
			}
			break;

		case RECOLHE1_4:
			if(SPR1 == 1 && SPE1 == 0) {
				nextState5=LIMPA11;
			//	printf("LIMPA11\n");
			}
			break;

		case LIMPA11:              
			if(fe_ST3 == 1) {
				nextState5=VERDE_VERDE4;
			//	printf("VERDE_VERDE4\n");
			}
			break;

		case VERDE_VERDE4:              
			if(re_STR2) {
				nextState5=TRANSF12;
			//	printf("TRANSF12\n");
			}
			break;

		case TRANSF12:              
			if(fe_STR2) {
				nextState5=LIMPA12;
			//	printf("LIMPA12\n");
			}
			break;

		case LIMPA12:
			if(fe_ST3) {
				nextState5=PARADO_S;
			//	printf("PARADO_S\n");
			}
			break; 
//------------RAMO  SV2=4 E SV1=1 ----------- // certo
		case VERDE_AZUL3: //a funcionar
		if(aux1==2) {						
			nextState5=TRANSF_CONJUNTA2;
			aux1=0;
			//printf("TRANSF_CONJUNTA2\n");
		}
		break;
			
		case TRANSF_CONJUNTA2:
			if(aux2==2) {
				nextState5=LIMPA_CONJUNTO2;
			//	printf("LIMPA_CONJUNTO2\n");
				aux2=0;
			}
			break;
			
		case LIMPA_CONJUNTO2:             
			if(aux3 == 2) {
				nextState5=PARADO_S;
			//	printf("PARADO_S\n");
			}
			break;
 
 // RAMO SV2=1 //
		 case AZUL2_ESPERA:
			if(SV1==4) {
				nextState5 = AZUL_VERDE3;
			//	printf("AZUL_VERDE3\n");
			}
			else if(SV1==1){
				nextState5=AZUL_AZUL3;
			//	printf("AZUL_AZUL3\n");
			}
            break;
 // RAMO SV2=1 // e SV1=1
		case AZUL_AZUL3: //a funcionar
			if(re_STR1) {
			nextState5=TRANSF7;
			//printf("TRANSF7\n");
			}
		break;
			
		case TRANSF7:
			if(fe_STR1) {
				nextState5=LIMPA7;
			//	printf("LIMPA7\n");
			}
			break;
			
		case LIMPA7:              
			if(fe_ST2 == 1) {
				nextState5=AZUL_AZUL4;
			//	printf("AZUL_AZUL4\n");
			}
			break;

		case AZUL_AZUL4:              
			if(re_STR2) {
				nextState5=TRANSF8;
			//	printf("TRANSF8\n");
			}
			break;

		case TRANSF8:             
			if(fe_STR2) {
				nextState5=ESTICA2_3;
			//	printf("ESTICA2_3\n");
			}
			break;

		case ESTICA2_3:              
			if(SPE2 == 1) {
				nextState5=RECOLHE2_3;
			//	printf("RECOLHE2_3\n");
			}
		break;

		case RECOLHE2_3:              
			if(SPR2 == 1) {
				nextState5=LIMPA8;
			//	printf("LIMPA8\n");
			}
			break;

		case LIMPA8:
		//adicionar transição no papel//
			if(fe_ST2) {
				nextState5=PARADO_S;
			//	printf("PARADO_S\n");
			}
			break;

		////RAMO SV2=1  e SV1=4 ////
		
		case AZUL_VERDE3:
			if(re_STR1) {
			nextState5=TRANSF9;
			//printf("TRANSF9\n");
		}
		break;
			
		case TRANSF9:
			if(fe_STR1) {
				nextState5=ESTICA1_3;
			//	printf("ESTICA1_3\n");
			}
			break;
			
		case ESTICA1_3:
			if(SPE1 == 1) {
				nextState5=RECOLHE1_3;
			//	printf("RECOLHE1_3\n");
			}
			break;

		case RECOLHE1_3:
			if(SPR1 == 1) {
				nextState5=LIMPA9;
			//	printf("LIMPA9\n");
			}
			break;

		case LIMPA9:              
			if(fe_ST3 == 1) {
				nextState5=VERDE_AZUL4;
			//	printf("VERDE_AZUL4\n");
			}
			break;

		case VERDE_AZUL4:              
			if(re_STR2) {
				nextState5=TRANSF10;
			//	printf("TRANSF10\n");
			}
			break;

		case TRANSF10:              
			if(fe_STR2) {
				nextState5=ESTICA2_4;
			//	printf("ESTICA2_4\n");
			}
			break;

		case ESTICA2_4:              
			if(SPE2 == 1) {
				nextState5=RECOLHE2_4;
			//	printf("RECOLHE2_4\n");
			}
		break;

		case RECOLHE2_4:              
			if(SPR2 == 1) {
				nextState5=LIMPA10;
			//	printf("LIMPA10\n");
			}
			break;

		case LIMPA10:
			if(fe_ST2) {
				nextState5=PARADO_S;
			//	printf("PARADO_S\n");
			}
			break;
	}	
}

int main() {


	// Inicialização das ME
	init_ME1();
	init_ME2();
	init_ME3();
	init_ME4();
	init_ME5();
	
	// Ciclo de execução
	while(1) {

        update_timers();
		read_inputs();
		edge_detection();	    
		
   		
		ME1();
		ME2();
		ME3();
		ME4();
		ME5();
		
		currentState1 = nextState1;
        currentState2 = nextState2;
        currentState3 = nextState3;
        currentState4 = nextState4;
        currentState5 = nextState5;


		LSTOP = (currentState1 == PARADO);
		LSTART = (currentState1 == OPERAR);				
		E1 = ( currentState1 == OPERAR);
        E2 = ( currentState1 == OPERAR);
		LWAIT = (currentState4 == LW_ON);
		T1A = (currentState5 == INICIO) || (currentState5 == AZUL_AZUL) || (currentState5 == TRANSF1) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == VERDE_AZUL) || (currentState5 == TRANSF3) || (currentState5 == VERDE_VERDE) || (currentState5 == TRANSF5) || (currentState5 == AZUL2_ESPERA) || (currentState5 == AZUL_AZUL3) || (currentState5 == TRANSF7) || (currentState5 == AZUL_VERDE3) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == VERDE2_ESPERA)|| (currentState5 == AZUL_VERDE3) || (currentState5 == TRANSF9) || (currentState5 == VERDE_VERDE3) || (currentState5 == TRANSF11) || (currentState5 == VERDE_AZUL3);
		T2A = (currentState1 == A_PARAR2) || (currentState5 == TRANSF1) || (currentState5 == LIMPA1) || (currentState5 == LIMPA2) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == LIMPA_CONJUNTO)|| (currentState5 == TRANSF3)|| (currentState5 == LIMPA4)|| (currentState5 == TRANSF5) || (currentState5 == TRANSF7) || (currentState5 == LIMPA7) || (currentState5 == LIMPA8) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == LIMPA_CONJUNTO2)|| (currentState5 == TRANSF9)|| (currentState5 == LIMPA10)|| (currentState5 == TRANSF11);
        T3A = (currentState1 == A_PARAR2) || (currentState5 == TRANSF2) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == LIMPA_CONJUNTO) || (currentState5 == LIMPA3) || (currentState5 == TRANSF4) || (currentState5 == LIMPA5) || (currentState5 == TRANSF6) || (currentState5 == LIMPA6) || (currentState5 == TRANSF8) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == LIMPA_CONJUNTO2) || (currentState5 == LIMPA9) || (currentState5 == TRANSF10) || (currentState5 == LIMPA11) || (currentState5 == TRANSF12) || (currentState5 == LIMPA12);
		T4A = (currentState5 == INICIO) || (currentState5 == AZUL1_ESPERA) || (currentState5 == AZUL_AZUL2) || (currentState5 == TRANSF2) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA) || (currentState5 == VERDE1_ESPERA) || (currentState5 == VERDE_AZUL2) || (currentState5 == TRANSF4) || (currentState5 == VERDE_VERDE2) || (currentState5 == TRANSF6) || (currentState5 == AZUL_AZUL4) || (currentState5 == TRANSF8) || (currentState5 == AZUL_VERDE) || (currentState5 == TRANSF_CONJUNTA2) || (currentState5 == VERDE_AZUL4) || (currentState5 == TRANSF10) || (currentState5 == VERDE_VERDE4) || (currentState5 == TRANSF12) || (currentState5 == VERDE_AZUL3);																							
		PE1 = (currentState5 == ESTICA1_1) || (currentState5 == ESTICA1_2) || (currentState5 == ESTICA1_3) || (currentState5 == ESTICA1_4);
		PR1 = (currentState5 == RECOLHE1_1) || (currentState5 == RECOLHE1_2) || (currentState5 == RECOLHE1_3) || (currentState5 == RECOLHE1_4);
        PE2 = (currentState5 == ESTICA2_1) || (currentState5 == ESTICA2_2) || (currentState5 == ESTICA2_3) || (currentState5 == ESTICA2_4);
		PR2 = (currentState5 == RECOLHE2_1) || (currentState5 == RECOLHE2_2) || (currentState5 == RECOLHE2_3) || (currentState5 == RECOLHE2_4);


		write_outputs();
		if(currentState5==PARADO_S) {
			aux1=0;
			aux2=0;
			aux3=0;
		}

			
	} 
	
}