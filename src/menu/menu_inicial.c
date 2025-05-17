#include "../../includes/menu/menu.h"

void menu_inicial()
{
	int op;
	do{	
		system("cls");
		printf("================================\n");
		printf("=                              =\n");
		printf("= 1 - Testar a PATRICIA        =\n");
		printf("= 2 - Testar a Hash Table      =\n");
		printf("= 0 - Sair                     =\n");
		printf("=                              =\n");
		printf("================================\n");
		printf("= : ");
		while(scanf("%d", &op) != 1);
		switch(op)
		{
			case 1:
				{
					main_patricia();
					break;
				}
			case 2:
				{
					main_hash();
					break;
				}
			case 0:
				{
					printf("\n|VOLTE SEMPRE!|\n");
					break;
				}
			default:
				{
					printf("\nEscolha uma opcao valida.\n");
					break;
				}
		}
	}while(op != 0);
}