#include <iostream>
#include <cmath>         
#include <cstdio>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* meio = NULL;

int quantidade = 0;
int soma = 0;
float fmedia;
int imedia;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
void Delete(NO* elemInicial, int delNum, bool mid);
void mostrarDados();
void Procurar(int Num, NO* inicio, NO* fim);
NO* posicaoElemento(int numero);

//--------------------------
int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:           
            return;     
        case 8: mostrarDados();     
            break;     
        default:           
            break;           
                           }   

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	quantidade = 0;
	soma = 0;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento() {

    int elemento;
    cout << "Digite o elemento que deseja inserir: ";
    cin >> elemento;
    bool insNum = false;
    
    if (posicaoElemento(elemento) == NULL){
        
    	NO* novo = (NO*)malloc(sizeof(NO));
    	bool first = true;
    	if (novo == NULL)
    	{
    		return;
    	}
    
        novo->valor = elemento;
    	novo->prox = NULL;
    	NO* elemAtual = primeiro;
    	NO* anterior;
    
    	if (primeiro == NULL)
    	{
    		primeiro = novo;
    	}
    	else{
    	    while (elemAtual != NULL){
    	        if (first){
    	            if(novo->valor>elemAtual->valor){
    	                novo->prox = elemAtual;
    	                primeiro = novo;
    	                insNum = true;
    	            }
    	            else{
    	                if(elemAtual->prox == NULL){
    	                    elemAtual->prox = novo;
    	                    insNum = true;
    	                }
    	            anterior = elemAtual;
    	            }
    	        first = false;
    	        }
    	        else{
    	            if (novo->valor>elemAtual->valor){
    	                anterior->prox = novo;
    	                novo->prox = elemAtual;
    	                insNum = true;
    	            }
    	            else{
    	                if (elemAtual->prox == NULL){
    	                    elemAtual->prox = novo;
    	                    insNum = true;
    	                }
    	            }
    	        }
    	    if (insNum){
    	        break;
    	    }
    	    elemAtual=elemAtual->prox;
    	    }
    	}
        cout <<"Elemento inserido \n";
        cout << endl;
        quantidade++;  
        fmedia = quantidade/2;
        imedia = static_cast<int>(round(fmedia)); 
        
        elemAtual = primeiro;
        anterior = primeiro;
        for(int i = 0; i < quantidade + 1; i++){
            if (i == imedia){
                meio = elemAtual;
            }
            else{
                elemAtual=elemAtual->prox;
            }
        }
        
    }
    else
    {
        cout << "O elemento já está na lista. \n";
        cout << endl;
    }
}

void excluirElemento()
{
	int delNum;
	NO* elemAtual = primeiro;
	NO* anterior = primeiro;
	
	if (quantidade <= 0){
	    cout << "Lista vazia.";
	    cout << endl;
	}
	else {
	    cout << "Digite o elemento a ser excluído: ";
	    cin >> delNum;
	    if (quantidade >= 3 && meio != NULL){
	        if (delNum < meio->valor){
	            cout << "Meio da lista";
	            cout << endl;
	            Delete(meio, delNum, true);
	        }
	        else{
	            cout << "Começo da lista";
	            Delete(primeiro, delNum, false);
	        }
	    }
	    else{
	        Delete(primeiro, delNum, false);
	    }
	    fmedia = quantidade / 2;
	    imedia = static_cast<int>(round(fmedia));
	    elemAtual = primeiro;
	    anterior = primeiro;
	    
        for(int i = 0; i < quantidade + 1; i++){
            if (i == imedia){
                meio = elemAtual;
            }
            else{
                elemAtual=elemAtual->prox;
            }
        }
	}
}

void buscarElemento()
{
	int buscarNum;
	if (quantidade <= 0){
	    cout << "Lista vazia.";
	    cout << endl;
	}
	else{
	    cout << "Digite o elemento que está procurando: ";
	    cin >> buscarNum;
	    
	    if (quantidade >= 5){
	        if (buscarNum < meio->valor){
	            Procurar(buscarNum, meio, NULL);
	        }
	        else{
	            Procurar(buscarNum, primeiro, meio);
	        }
	    }
	    else{
	        Procurar(buscarNum, primeiro, NULL);
	    }
	}
}

void mostrarDados(){
    cout << "Media: "<<imedia;
    cout << "Quantidade: "<<quantidade;
    cout << endl;
    
    if (meio == NULL){
        cout << "A variável está vazia.";
    }
    else{
        cout << "Meio: "<<meio->valor;
        cout << endl;
    }
}


NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

void Procurar(int Num, NO* inicio, NO* fim){
    while(inicio != fim){
        if (inicio->valor == Num){
            cout << "Elemento encontrado. \n";
            break;
        }
        else{
            if (inicio->prox == fim){
                cout << "Elemento não encontrado. \n";
                break;
            }
        }
        inicio = inicio->prox;
    }
}

void Delete(NO* elemInicial, int delNum, bool mid){
    NO* elemAtual;
    NO* anterior;
    bool first = true;
    bool del = false;
    
    if (mid){
        elemAtual = elemInicial->prox;
        anterior = elemAtual;
    }
    else{
        elemAtual = elemInicial;
    }
    
    while (elemAtual = NULL){
        if (first){
            if (elemAtual->valor == delNum){
                if (mid == false){
                    primeiro = elemAtual->prox;
                }
                else{
                    anterior->prox = elemAtual->prox;
                }
                cout << "Elemento excluído. \n";
                cout << endl;
                quantidade --;
                soma = soma - elemAtual->valor;
                free (elemAtual);
                del = true;
            }
            else{
                if (elemAtual->prox == NULL){
                    cout << "Elemento não encontrado. \n";
                    cout << endl;
                }
                anterior = elemAtual;
            }
            first = false;
        } 
        else{
        if (elemAtual->valor == delNum){
            anterior->prox = elemAtual->prox;
            cout << "Elemento excluído. \n";
            quantidade --;
            soma = soma - elemAtual->valor;
            free(elemAtual);
            del = true;
        }
        else{
            anterior = elemAtual;
            if (elemAtual->prox == NULL){
                cout << "Elemento não encontrado. \n";
            }
        }
    }
    if(del){
        break;
    }
    elemAtual = elemAtual->prox;
    }
}

