programa
{


	//faça um programa que tenha uma função que receba um número, e diga se ele é positivo, negativo ou zero.

	funcao inteiro verificaChilindro(inteiro x){
		escreva("\n", x)	
		se(x >= 18){
			retorne 1	
		}senao{
			retorne 0	
		}
	}

	funcao imprimeResultado(inteiro r){
			se(r == 1){
				escreva("\nChilindro")	
			}senao{
				escreva("\nLiberdade")	
			}
	}
	
	funcao inicio()
	{	
		inteiro idade, resultado
		leia(idade)
		resultado = verificaChilindro(idade)
		imprimeResultado(resultado)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 356; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */