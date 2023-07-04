//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//2 - Calcule a média das notas de 10 alunos de uma disciplina e determine o número de alunos que tiveram nota superior a média calculada/////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include <locale.h>

#define TAM 10

int main(){
    setlocale(LC_ALL,"Portuguese");
	float v[TAM],media=0;
	int c=0;
	for(int i=0;i<TAM;i++){
        cout << "Digite um valor: ";
		cin >> v[i];
		media=media+v[i];
	}
	media=media/TAM;
	cout << "\nA média é " << media;
	cout << "\n\nAs seguintes notas estão acima da média:\n";
	for(int i=0;i<TAM;i++){
		if(v[i]>media)	{
		    c++;
			cout << "-> " << v[i] << endl;
		}
	}
	cout << "Qtd: " << c;
    return 0;
}

