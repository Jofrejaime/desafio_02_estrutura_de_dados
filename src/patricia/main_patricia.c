#include "../../includes/patricia/PATRICIA.h"


void main_patricia() 
{
	system("cls");
    node* arv = NULL;
    int op, num;
    do {
        menu();
        scanf("%d", &op);
        printf("\n");

        switch(op) {

            case 1:
                printf("Digite a key que deseja inserir: ");
                scanf("%d", &num);

                if (Pesquisar(arv, num)) {
                    printf("Chave %d ja existe na arvore.\n", num);
                } else {
                    arv = Inserir(arv, num);
                    printf("Chave %d inserida com sucesso!\n", num);
                }
                break;

            case 2:
                printf("Digite a key que deseja remover: ");
                scanf("%d", &num);
                arv = removerNo(arv, num);
                break;

            case 3:
                printf("Digite a key que queres pesquisar: ");
                scanf("%d", &num);

                if (Pesquisar(arv, num)) {
                    printf("Chave %d encontrada!\n", num);
                } else {
                    printf("Chave %d nao encontrada.\n", num);
                }
                break;
                
				case 4: 
    				if (arv == NULL) 
					{
        				printf("A arvore esta vazia.\n");
    				} 
					else 
					{
				        printf("\n-----------nodeore Atual-----------\n");
				        Imprimir(arv);
				        printf("\n");
   					}
   					break;
            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida, digite novamente.\n");
        }

    } while (op != 0);
}

void menu() {
	    printf("================================\n");
        printf("=                              =\n");
		printf("=       PATRICIA - MENU        =\n");
		printf("=                              =\n");
		printf("= 1 - Inserir   chave          =\n");
		printf("= 2 - Remover   chave          =\n");
		printf("= 3 - Pesquisar chave          =\n");
		printf("= 4 - Imprimir  nodeore        =\n");
		printf("= 0 - Sair                     =\n");
		printf("=                              =\n");
		printf("================================\n");
		printf("= : ");
}
