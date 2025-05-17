#include "../../includes/hash_table/hashtable.h"

void main_hash() {
	system("cls");
	char resp;
    int table[M];
    int option, key;
	
    init_table(table);

    do {
        printf("================================\n");
        printf("=                              =\n");
		printf("=      HASH TABLE - MENU       =\n");
		printf("=                              =\n");
		printf("= 1 - Inserir   chave          =\n");
		printf("= 2 - Pesquisar chave          =\n");
		printf("= 3 - Imprimir 	tabela         =\n");
		printf("= 0 - Sair                     =\n");
		printf("=                              =\n");
		printf("================================\n");
		printf("= : ");
        scanf("%d", &option);
        switch (option) {
            case 1:
            	do{
            	printf("Digite a chave: ");
                scanf("%d", &key);
                insert(table, key);
                printf("\nDeseja continuar com a insercao? S  /  N \n");
                scanf(" %c", &resp);
				} while(resp == 'S' || resp == 's');
            		
            break;
            
			case 2:
                printf("Digite a chave: ");
                scanf("%d", &key);
                int pos = search(table, key);
                if (pos != -1)
                    printf("Chave %d encontrada na posicao %d\n", key, pos);
                else
                    printf("Chave %d nao encontrada\n", key);
                break;
            case 3:
                print_table(table);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (option != 0);
}
