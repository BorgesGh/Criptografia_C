#include <stdio.h>
#include <string.h>
#define TAMANHO 5000


char *LerString(int *largura){ // Função para adicionar a string principal.
	
	int t;
	char *palavra; 
	
	palavra = (char *) malloc( TAMANHO * sizeof(char)); 
	
	printf("Insira a string: "); 
	gets(palavra); 
	
	t = strlen(palavra); 
	
	t--; // Decrementando o T para facilitar a indexação.
	
	*largura = t ; // Adquirindo Tamanho por passagem por refencia.
	
	return palavra; // Retornar a string mestra.
		
}

//------------------------------------------------------------------------------
int *SepararString(char *string, 
				   int tama, 
				   int *T_Vetor){
	
	int *vetorIndices; 
	
	vetorIndices = (int *) malloc ( TAMANHO * sizeof(int));
	
	int i, o = 0; 
	
	vetorIndices[0] = 0;
	o++;
	
	for(i = 0; i < tama; i++){ 
	
		if (string[i] == ' '){ 
		
			vetorIndices[o] = i - 1;// Determina o final da string anterior
			o++; 
			vetorIndices[o] = i + 1;// Determina o inicio da nova string
			o++; 
		}	
	}
	
	vetorIndices[o] = i; 
	
	*T_Vetor = o; 
	
	return vetorIndices;
}
//------------------------------------------------------------------------------
char *CopiarString(char *Mestra, int inicio, int fim){ 

	int i = inicio; 
	int o = 0;
	
	char *copia = (char *) malloc (TAMANHO * sizeof(char)); 
	
	while ( i <= fim ){ 
	
		copia[o] = Mestra[i]; 
		o++; 
		i++;
	}
	
	copia[o] = '\0';

	return copia;
}

//------------------------------------------------------------------------------

int encontrarDigito(char *stringModelo, char *elemento){ // Retorna o indice do primeiro elemento passado

	int tam_Elemento, indice_elemento; 
	int tam_Modelo, indice_modelo;
	int i, i2, pit, cont;
	 
	tam_Modelo = strlen(stringModelo);
	indice_modelo = tam_Modelo - 1; 
	
	tam_Elemento = strlen(elemento); 
	indice_elemento = tam_Elemento - 1; 
	
	for(pit = 0; pit <= indice_modelo; pit++) { 
		
		i = pit;
		cont = 0;
		
		for(i2 = 0; i2 <= indice_elemento; i2++){
			
			if (stringModelo[i] == elemento[i2])
				cont++;
				
			if (cont == tam_Elemento)
				return pit;
				
			i++;
		}		
	}
	
	return -1;
	
	}
//------------------------- Movimentação --------------------------------------	
char *MoverMais(char *stringRetorno, char *elemento, int poderosoIndice){ // avança o numero de casas de acordo com o tamanho do elemento
 
    char *string = (char *) malloc ( TAMANHO * sizeof(char)); 
    
    strcpy(string,stringRetorno); 
    
    int T_elemento = strlen(elemento); 
    int I_elemento = T_elemento - 1;
    
    int T_string = strlen(stringRetorno); 
    int I_string = T_string - 1;
    
    int i; 
    
    for (i = T_string; i > poderosoIndice; i--) { 
        string[i + I_elemento] = string[i];
        
    }
    
    
    return string;
    
}

char *MoverMenos(char *stringRetorno, char *elemento, int poderosoIndice){ 

    char *string = (char *) malloc ( TAMANHO * sizeof(char)); 
    
    strcpy(string,stringRetorno); 
    
    int T_elemento = strlen(elemento); 
    int I_elemento = T_elemento - 1;
    
    int T_string = strlen(stringRetorno); 
    int I_string = T_string - 1;
    
    int i; 
    
    for (i = poderosoIndice + I_elemento + 1 ; i <= T_string; i++) { 
        
        string[i - I_elemento] = string[i];
        
    }
    
    
    return string;
    
}
//--------------------------------------------------------------------------- 
char *adicionarAbd(char *string, int indice){ 

	string[indice] = 'A'; 
	string[indice + 1] = 'b'; 
	string[indice + 2] = 'd'; 

	return string;
}
//----------------------------------------------------------------------------
char *inverter(char *string){
    
    int t = strlen(string); 
    int i; 
    char *temp; 
    temp = (char * )malloc (TAMANHO * sizeof(char));
    
    
    t--;
    for (i = 0; i <= t; i++)
        temp[i] = string[t - i];
    
    temp[i] = '\0';
    return temp;
}
//-------------------------------------------------------------------------- 
int IndiceMenor(int indice1, int indice2, int indice3){ // Retorna o menor indice, não contabilzando o -1
    
    
    if(indice1 != -1 && indice2 != -1 && indice3 != -1){
    
    
        if (indice1 < indice2)
            if(indice1 < indice3)
                return indice1;
                
            else //indice3 < indice1 
                return indice3;
                
                
        
        else // indice1 > indice2
            if(indice2 < indice3)
                return indice2;
            
            else //indice3 < indice2 
                return indice3;
                
            
    }else if (indice1 != -1 && indice2 != -1){
        if(indice1 < indice2)
            return indice1;
        else 
            return indice2;
        
        
    }else if(indice1 != -1 && indice3 != -1){
        
        if(indice1 < indice3)
            return indice1;
        else 
            return indice3;
        
        
        
    }else if(indice2 != -1 && indice3 != -1){
        if(indice2 < indice3)
            return indice2;
        else
            return indice3;
        
    
        
    }else{ 
    
        if(indice1 != -1){
            return indice1;
            
        }else if (indice2 != -1){
            return indice2;
            
        }else{
            return indice3;
        }
        
    }
    
}

//---------------------------------------------------------------------------------- 
// -------------------- Criptografia ---------------------------------------------- 
// TUDO ABD--------------------------------------------------------------
char *TudoAbd(char *stringMestra, int inicio, int fim, char *Ordem){ 
	int indice1,indice2,indice3;
	char *pasto;
	
	char *SequenciaDeElementos; 
	SequenciaDeElementos = (char *) malloc(TAMANHO * sizeof(char)); // Colocar os #@$ em sequencia
	SequenciaDeElementos[0] = '\0';
	
	int menor;
	
	int i = strlen(Ordem);// Indice para a adição de novos elementos
	
	char elemento1[10] = "@";
	char elemento2[10] = "#";
	char elemento3[10] = "$";
	char ABD[10] = "Abd";
	
	char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
	
	indice1 = encontrarDigito(stringRetorno, elemento1);
	indice2 = encontrarDigito(stringRetorno, elemento2);
	indice3 = encontrarDigito(stringRetorno, elemento3);
	
	
	while (indice1 != -1 || indice2 != -1 || indice3 != -1){
		
		menor = IndiceMenor(indice1,indice2,indice3);
		Ordem[i] = stringRetorno[menor];// Adiciona o elemento substituido por Abd
		i++;
		
		stringRetorno = MoverMais(stringRetorno, ABD , menor);
		stringRetorno = adicionarAbd(stringRetorno, menor);
		
		indice1 = encontrarDigito(stringRetorno, elemento1);
		indice2 = encontrarDigito(stringRetorno, elemento2);
		indice3 = encontrarDigito(stringRetorno, elemento3);
		
		
	}
	
	Ordem[i] = '\0';

	return stringRetorno;
	
}
// SUFIXO RABBU -----------------------------------------------------
char *Rabbu(char *stringMestra, int inicio, int fim){ 

	char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);

	int t = strlen(stringRetorno);
	int pares = 0, impares = 0; 
	char Rabu[10] = "Rabbu";
	
	int i; 
	for(i = 0; i < t; i++){ 
		
		if (stringRetorno[i]%2 == 0){
		
			pares++; 
		
		}else{
	
			impares++; 
		}
	}

	if (pares > impares){ 
	
		strcat (stringRetorno, Rabu);
	}
	return stringRetorno;
}
// INVERSÃO QUASE TOTAL ------------------------------------------------- 
char *InversaoTotal(char *stringMestra, int inicio, int fim){
    
    char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
    
    char elemento[10] = "##"; // elemento qualquer para adionar um espaço a mais     
    int t = strlen(stringRetorno); 
    
    int divisor = t%2;
    stringRetorno = inverter(stringRetorno);
    
    if (divisor == 0){ 
    
        int indiceTroca = t/2; 
        indiceTroca--;
        stringRetorno = MoverMais(stringRetorno,elemento,indiceTroca);
        stringRetorno[indiceTroca + 1] = elemento[0];
        return stringRetorno;
        
    }else { 
    
        return stringRetorno;
       
    }
      
}
// INVERSAO 2 A 2 -------------------------------------------------------
char *Inversao2(char *stringMestra, int inicio, int fim){
    
    char temp[10]; 
    
    char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
    
    int i,t; 
    t = strlen(stringRetorno);
    t--;
    for(i = 1; i <= t; i += 2){ 
    
        if (stringRetorno[i] == '\0' || stringRetorno[i - 1] == '\0'){
            return stringRetorno;
        }
        
        temp[0] = stringRetorno[i]; 
        stringRetorno[i] = stringRetorno[i - 1]; 
        stringRetorno[i - 1] = temp[0];
        
        
    }
    
    
    return stringRetorno;
}
// JUNÇÃO ----------------------------------------------------------------------------
char *Juncao(char *stringMestra, int inicio, int fim, char* Ordem){
    
    char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
    
    int t; 
    t = strlen(stringRetorno);
    t--;
    stringRetorno = TudoAbd(stringRetorno, 0 , t, Ordem);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = Rabbu(stringRetorno, 0, t);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = InversaoTotal(stringRetorno, 0,  t);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = Inversao2(stringRetorno, 0,  t);
    
    
    return stringRetorno;
    

}


//----------------------------------------  Descriptografia -------------------
// NADA ABD
char *NadaAbd(char *stringMestra, int inicio, int fim, char *Ordem, int *Valor){ 
	int indice1;
    
	char ABD[10] = "Abd";
	char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
	
	indice1 = encontrarDigito(stringRetorno, ABD);
	
	int v = *Valor;
	while (indice1 != -1 ){
		
		stringRetorno = MoverMenos(stringRetorno, ABD, indice1);
		stringRetorno[indice1] = Ordem[v];
		
		v++;
		
		indice1 = encontrarDigito(stringRetorno, ABD);
		
	} 

    *Valor = v;

	return stringRetorno;
	
}
	
// TIRA RABBU ------------------------------------------------------
char *RemoverRabbu(char *stringMestra, int inicio, int fim){ 

	char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
	
	int indice;
	char rabu[10] = "Rabbu";
	
	indice = encontrarDigito(stringRetorno, rabu); 
	if (indice != -1){
	
		stringRetorno[indice] = '\0'; 
		return stringRetorno;
		
	}else{
	
		return stringRetorno;
	
	}
}
// INVERTE E TIRA A # --------------------------------------------------
char *desInversaoTotal(char *stringMestra, int inicio, int fim){
    
    char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
	
    char elemento[10] = "##";
    int t = strlen(stringRetorno); 
    
    stringRetorno = inverter(stringRetorno);
    int indiceTroca = t/2;
    
    if (stringRetorno[indiceTroca] == '#'){ 
        indiceTroca--;
        stringRetorno = MoverMenos(stringRetorno, elemento, indiceTroca);
        return stringRetorno;
        
    }else { 
    
        return stringRetorno;
       
    }
}
// DESJUNCAO ----------------------------------------------------- 
char *Desjuncao(char *stringMestra, int inicio, int fim, char *Ordem, int *Valor){
    char *stringRetorno; 
	stringRetorno = CopiarString(stringMestra, inicio, fim);
    
    int t; 
    
    t = strlen(stringRetorno);
    t--;
    stringRetorno = Inversao2(stringRetorno, 0, t);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = desInversaoTotal(stringRetorno, 0,t);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = RemoverRabbu(stringRetorno, 0, t);
    t = strlen(stringRetorno);
    t--;
    stringRetorno = NadaAbd(stringRetorno, 0,t, Ordem, Valor);
    
    return stringRetorno;
    
    
} 
//---------------------------------- CRIPTOGRAFA DADOS --------------
char *criptografaDados(char *Mestra, int T_Mestra, char *Ordem){
    int *VetorIndices; int T_vetor;
    
    char *stringCripto;
    stringCripto = (char *) malloc (TAMANHO * sizeof(char));
    stringCripto[0] = '\0';
    char *Temp; 
    Temp = (char *) malloc (TAMANHO * sizeof(char));
    
    VetorIndices = SepararString(Mestra, T_Mestra, &T_vetor);
    
    int i, delimitador = 0; 
    
    for(i = 1; i <= T_vetor; i += 2){
        
         
        if (delimitador == 0){
            
            Temp = TudoAbd(Mestra, VetorIndices[i - 1], VetorIndices[i], Ordem);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else if (delimitador == 1){
            
            Temp = Rabbu(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
            
        }else if (delimitador == 2){
            
            Temp = InversaoTotal(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else if (delimitador == 3){
            
            Temp = Inversao2(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else{
            
            Temp = Juncao(Mestra, VetorIndices[i - 1], VetorIndices[i], Ordem);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            delimitador = -1;
        }
        
        delimitador++;
         
    }
    int t = strlen(stringCripto); 
        t--;
    	stringCripto[t] = '\0';
    
    return stringCripto;
    
}

//------------------------------------------DESCRIPTOGRAFA DADOS --------------- 
char *desCriptografaDados(char *Mestra, int T_Mestra,char *Ordem){
    int *VetorIndices; int T_vetor;
    int Valor = 0;
    
    char *stringCripto;
    stringCripto = (char *) malloc (TAMANHO * sizeof(char));
    stringCripto[0] = '\0';
    char *Temp; 
    Temp = (char *) malloc (TAMANHO * sizeof(char));
    
    VetorIndices = SepararString(Mestra, T_Mestra, &T_vetor);
    
    int i, delimitador = 0; 
    
    for(i = 1; i <= T_vetor; i += 2){
        
         
        if (delimitador == 0){
            
            Temp = NadaAbd(Mestra, VetorIndices[i - 1], VetorIndices[i], Ordem, &Valor);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else if (delimitador == 1){
            
            Temp = RemoverRabbu(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
            
        }else if (delimitador == 2){
            
            Temp = desInversaoTotal(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else if (delimitador == 3){
            
            Temp = Inversao2(Mestra, VetorIndices[i - 1], VetorIndices[i]);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            
        }else{
            
            Temp = Desjuncao(Mestra, VetorIndices[i - 1], VetorIndices[i], Ordem, &Valor);
            strcat(stringCripto,Temp);
            strcat(stringCripto," ");
            delimitador = -1;
        }
        
        delimitador++;
         
    }
    
    int t = strlen(stringCripto); 
        t--; 
       	stringCripto[t] = '\0';
    
    
    return stringCripto;
}
// ------------------------- PROGRAMA PRINCIPAL -------------------------------
int main(int argc, char *argv[]) {
	
	char *Mestra; int T_Mestra; 

	Mestra = LerString(&T_Mestra); 
	
	char *Ordem; //Vetor para designar a sequencia de elementos (#@$)
	Ordem = (char *) malloc (TAMANHO * sizeof(char));
	Ordem[0] = '\0';
	
	char *S_cripto; 
	S_cripto = (char *) malloc (TAMANHO * sizeof(char));
	char *S_desCripto;
	
	
	S_cripto = criptografaDados(Mestra, T_Mestra, Ordem); 
	T_Mestra = strlen(S_cripto);
	T_Mestra--;
	
	S_desCripto = desCriptografaDados(S_cripto,T_Mestra, Ordem);
	
    printf("\nString Criptografada: %s\n", S_cripto);
    printf("\nString Descriptografada: %s", S_desCripto);
    
	
	return 0;

}

