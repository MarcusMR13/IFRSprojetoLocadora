#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUERREIROS  10
#define MAX_DRAGOES  16

//guerreiros ('\0' = vazio)
char nomeGuerreiro [MAX_GUERREIROS][30];
char reinoGuerreiro[MAX_GUERREIROS][15];
char tituloGuerreiro[MAX_GUERREIROS][15];

//locar dragao (-1 = vazio)
int dragaoLocado[MAX_GUERREIROS];
char dataEntrega[MAX_GUERREIROS][15];

//dragoes (-1 = vazio)
char nomeDragao[MAX_DRAGOES][30];
int idadeDragao[MAX_DRAGOES];
char elementoDragao[MAX_DRAGOES][30];

//menu
int menu;
int indiceGuerreiro, indiceDragao;
char nomeProcurado[30];

//index
int i;

//começo do programinha
int main()
{
    
    //espaço em branco guerreiros ('\0' = vazio)
    for (i=0;i<MAX_GUERREIROS;i++)
    {
        nomeGuerreiro[i][0] = '\0';
        reinoGuerreiro[i][0] = '\0';
        tituloGuerreiro[i][0] = '\0';
        dragaoLocado[i] = -1;
        dataEntrega[i][0] = '\0';
    }
    //espaço em branco dragoes (-1 = vazio)
    for (i=0;i<MAX_DRAGOES;i++)
    {
        nomeDragao[i][0] = '\0';
        elementoDragao[i][0] = '\0';
        idadeDragao[i] = -1;
    }
    
    //Guerreiros Pré-Cadastrados 
    strcpy(nomeGuerreiro[0], "Garen");
    strcpy(reinoGuerreiro[0], "Demacia");
    strcpy(tituloGuerreiro[0], "Principe");

    strcpy(nomeGuerreiro[1], "Lux");
    strcpy(reinoGuerreiro[1], "Demacia");
    strcpy(tituloGuerreiro[1], "Princesa");

    //Dragões Pré-Cadastrados
    strcpy(nomeDragao[0], "Shyvanna");
    idadeDragao[0] = 900;
    strcpy(elementoDragao[0], "Fogo");

    strcpy(nomeDragao[1], "Elder");
    idadeDragao[1] = 5000;
    strcpy(elementoDragao[1], "Temporal");

    //menu
    do
    {
        
        int procurado = 0;

        printf("BEM VINDOS A LOCADORA KALEESI\n");
        printf("para continuarmos, por favor escolha uma das opcoes do menu abaixo: \n\n");
        
        printf("0. Sair\n");
        printf("1. Listar guerreiros\n");
        printf("2. Cadastrar guerreiro pelo codigo\n");
        printf("3. Pesquisar guerreiro pelo nome\n");
        printf("4. Excluir guerreiro pelo codigo\n");
        printf("5. Listar dragoes\n");
        printf("6. Cadastrar dragao pelo codigo\n");
        printf("7. Pesquisar dragao pelo nome\n");
        printf("8. Excluir dragao pelo codigo\n");
        printf("9. Listar dragoes locados\n");
        printf("10. Locar dragao\n");
        printf("11. Devolver dragao pelo codigo do guerreiro\n");

        printf("\nInforme qual opcao do menu deseja entrar: ");
        scanf("%d", &menu);

        switch(menu)
        {   
            //Listar Guerreiros
            case 0:
            {
                printf("\nObrigado por utilizar nossa locadora!!!\n\n");
                break;
            }
            case 1:
            {
                printf("\nGUERREIROS CADASTRADOS:\n");
                printf("Codigo Nome Reino Titulo\n\n");
                
                for(i = 0;i < MAX_GUERREIROS;i++)
                {
                   if(nomeGuerreiro[i][0] != '\0')
                   {
                       printf("%d %s %s %s\n", i, nomeGuerreiro[i], reinoGuerreiro[i], tituloGuerreiro[i]);
                   }
                }
                printf("\n");
                break;
            }
            //Cadastro de Guerreiros
            case 2:
            {
                printf("\nGUERREIROS CADASTRADOS:\n");
                printf("Codigo Nome Reino Titulo\n\n");
                
                for(i = 0;i < MAX_GUERREIROS;i++)
                {
                   if(nomeGuerreiro[i][0] != '\0')
                   {
                       printf("%d %s %s %s\n", i, nomeGuerreiro[i], reinoGuerreiro[i], tituloGuerreiro[i]);
                   }
                }

                printf("\nPara cadastrarmos um guerreiro eh preciso que diga em qual codigo deseja coloca-lo: ");
                scanf("%d", &indiceGuerreiro);

                if (indiceGuerreiro < MAX_GUERREIROS && indiceGuerreiro >= 0)
                {
                    if (nomeGuerreiro[indiceGuerreiro][0] == '\0')
                    {
                        printf("Informe o nome do guerreiro que deseja cadastrar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", nomeGuerreiro[indiceGuerreiro]);

                        printf("Informe o reino do guerreiro que deseja cadastrar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", reinoGuerreiro[indiceGuerreiro]);

                        printf("Informe o titulo do guerreiro que deseja cadastrar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", tituloGuerreiro[indiceGuerreiro]);
                    }
                    else if (nomeGuerreiro[indiceGuerreiro][0] != '\0')
                    {
                        printf("\nPor favor, escolha outro codigo de guerreiro, pois ja possuimos alguem cadastrado nesta posicao!!\n\n");
                    }
                }    
                else if ( indiceGuerreiro >= MAX_GUERREIROS || indiceGuerreiro < 0)
                {
                    printf("\nO indice eh invalido, utilize outro!!!!\n\n");
                }

                break;
            }
            //Busca por Guerreiros
            case 3:
            {
                printf("\nInforme o nome do guerreiro que deseja procurar: ");
                fflush(stdin);
                scanf("%[^\n]s", &nomeProcurado);

                for(i = 0; i < MAX_GUERREIROS; i++)
                {
                    if (strcmp(nomeProcurado, nomeGuerreiro[i]) == 0)
                    {
                        printf("\nO guerreiro %s esta no indice %d\n\n", nomeGuerreiro[i], i);
                        procurado += 1;
                    }
                }

                if (procurado == 0)
                {
                    printf("\nNao foi encontrado nenhum guerreiro com este nome!!!\n\n");
                }

                break;
            }
            //Apagar Guerreiro
            case 4:
            {
                printf("\nGUERREIROS CADASTRADOS:\n");
                printf("Codigo Nome Reino Titulo\n\n");
                
                for(i = 0;i < MAX_GUERREIROS;i++)
                {
                   if(nomeGuerreiro[i][0] != '\0')
                   {
                       printf("%d %s %s %s\n", i, nomeGuerreiro[i], reinoGuerreiro[i], tituloGuerreiro[i]);                    
                   }
                }

                printf("\nInforme o codigo do guerreiro que deseja excluir: ");
                scanf("%d", &indiceGuerreiro);

                if (indiceGuerreiro < MAX_GUERREIROS && indiceGuerreiro >= 0)
                {
                    if (nomeGuerreiro[indiceGuerreiro][0] != '\0')
                    {
                        if (dragaoLocado[indiceGuerreiro] == -1)
                        {     
                            strcpy(nomeGuerreiro[indiceGuerreiro], "\0");
                            strcpy(reinoGuerreiro[indiceGuerreiro], "\0");
                            strcpy(tituloGuerreiro[indiceGuerreiro], "\0"); 
                        }
                        else if( dragaoLocado[indiceGuerreiro] != -1)
                        {
                            printf("Como este guerreiro possui um dragao logo ele nao pode ser excluido\n\n");
                        }

                    }
                    else if (nomeGuerreiro[indiceGuerreiro][0] == '\0')
                    {
                        printf("\nEste codigo nao possui nenhum guerreiro registrado portanto escolha outro!!!\n\n");
                    }
                }
                else if (indiceGuerreiro >= MAX_GUERREIROS || indiceGuerreiro < 0)
                {
                    printf("\nEste codigo eh invalido portanto escolha outro!!!\n\n");
                }
                break;
            }
            //Listar Dragoes
            case 5:
            {
                printf("\nDRAGOES CADASTRADOS:\n");
                printf("Codigo Nome Idade Elemento\n\n");
                
                for(i = 0;i < MAX_DRAGOES;i++)
                {
                    if (idadeDragao[i] > 0)
                    {
                        printf("%d %s %d %s\n", i, nomeDragao[i], idadeDragao[i], elementoDragao[i]);
                    }
                }
                printf("\n");
                break;
            }
            //Cadastro de Dragoes
            case 6:
            {
                printf("\nDRAGOES CADASTRADOS:\n");
                printf("Codigo Nome Idade Elemento\n\n");
                
                for(i = 0;i < MAX_DRAGOES;i++)
                {
                    if (idadeDragao[i] > 0)
                    {
                        printf("%d %s %d %s\n", i, nomeDragao[i], idadeDragao[i], elementoDragao[i]);
                    }
                }

                printf("\nPara cadastrarmos um dragao eh preciso que diga em qual codigo deseja coloca-lo: ");
                scanf("%d", &indiceDragao);

                if (indiceDragao < MAX_DRAGOES && indiceDragao >= 0)
                {
                    if (idadeDragao[indiceDragao] == -1)
                    {
                        printf("Informe o nome do dragao que deseja cadastrar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", nomeDragao[indiceDragao]);

                        printf("Informe o elemento do dragao que deseja cadastrar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", elementoDragao[indiceDragao]);

                        printf("Informe a idade do dragao que deseja cadastrar: ");
                        scanf("%d", &idadeDragao[indiceDragao]);

                        if (idadeDragao[indiceDragao] <= 0)
                        {   
                            printf("\nComo a idade digitada nao pode ser negativa, por favor comece o cadastro do zero!!!\n\n");
                            
                            idadeDragao[indiceDragao] = -1;
                            strcpy(nomeDragao[indiceDragao], "\0");
                            strcpy(elementoDragao[indiceDragao], "\0");
                        }

                    }
                    else if (idadeDragao[indiceDragao] > 0)
                    {
                        printf("\nPor favor, escolha outro codigo de dragao, pois ja possuimos um cadastrado nesta posicao!!\n\n");
                    }
                }    
                else if ( indiceDragao >= MAX_DRAGOES || indiceDragao < 0)
                {
                    printf("\nO codigo eh invalido, utilize outro!!!!\n\n");
                }
                break;
            }
            //Busca por Dragoes
            case 7:
            {
                printf("\nInforme o nome do dragao que deseja procurar: ");
                fflush(stdin);
                scanf("%[^\n]s", &nomeProcurado);

                for(i = 0; i < MAX_DRAGOES; i++)
                {
                    if (strcmp(nomeProcurado, nomeDragao[i]) == 0)
                    {
                        printf("O dragao %s esta no codigo %d\n", nomeDragao[i], i);
                        procurado += 1;
                    }
                    
                }
                
                if (procurado == 0)
                {
                    printf("Nao foi encontrado nenhum dragao com este nome!!!\n\n");
                }

                break;
            }
            //Excluir Dragoes
            case 8:
            {
                printf("\nDRAGOES CADASTRADOS:\n");
                printf("Codigo Nome Idade Elemento\n\n");
                
                for(i = 0;i < MAX_DRAGOES;i++)
                {
                    if (idadeDragao[i] > 0)
                    {
                        printf("%d %s %d %s\n", i, nomeDragao[i], idadeDragao[i], elementoDragao[i]);
                    }
                }

                printf("\nInforme o codigo do dragao que deseja excluir: ");
                scanf("%d", &indiceDragao);

                if (indiceDragao < MAX_DRAGOES && indiceDragao >= 0)
                {
                    if (idadeDragao[indiceDragao] > 0)
                    {
                        for(i=0;i<MAX_GUERREIROS;i++)
                        {
                            if (dragaoLocado[i] == indiceDragao)
                            {
                                printf("Este dragao esta atualmente locado no guerreiro %s, portanto nao pode ser excluido!!\n\n", nomeGuerreiro[i]);
                                procurado += 1;
                            }
                        }
                        
                        if( procurado == 0 )
                        {
                            idadeDragao[indiceDragao] = -1;
                            strcpy(nomeDragao[indiceDragao], "\0");
                            strcpy(elementoDragao[indiceDragao], "\0"); 
                        }                  
                    }
                    else if (idadeDragao[indiceDragao] == -1)
                    {
                        printf("\nEste codigo nao possui nenhum dragao registrado portanto escolha outro!!!\n\n");
                    }
                }
                else if (indiceDragao >= MAX_DRAGOES || indiceDragao < 0)
                {
                    printf("\nEste codigo eh invalido portanto escolha outro!!!\n\n");
                }
                break;
            }
            //Listar Dragoes Locados
            case 9:
            {
                printf("\nDragoes Locados:\n");
                printf("Codigo Dragao Data p/ Entrega\n");
                
                for(i = 0;i < MAX_GUERREIROS;i++)
                {
                    if (dragaoLocado[i] != -1)
                    {
                        printf("%d %s %s\n", i, nomeDragao[dragaoLocado[i]], dataEntrega[i]);
                    }
                }
                printf("\n");

                break;
            }
            //Locar dragoes
            case 10:
            {
                printf("\nDRAGOES CADASTRADOS:\n");
                printf("Codigo Nome Idade Elemento\n\n");
                
                for(i = 0;i < MAX_DRAGOES;i++)
                {
                    if (idadeDragao[i] > 0)
                    {
                        printf("%d %s %d %s\n", i, nomeDragao[i], idadeDragao[i], elementoDragao[i]);
                    }
                }

                printf("\nInforme o codigo do dragao que deseja locar: ");
                scanf("%d", &indiceDragao);

                if (indiceDragao < MAX_DRAGOES && indiceDragao >= 0)
                {
                    if (idadeDragao[indiceDragao] > 0)
                    {
                        printf("\nGUERREIROS CADASTRADOS:\n");
                        printf("Codigo Nome Reino Titulo\n\n");
                        
                        for(i = 0;i < MAX_GUERREIROS;i++)
                        {
                            if(nomeGuerreiro[i][0] != '\0')
                            {
                                printf("%d %s %s %s\n", i, nomeGuerreiro[i], reinoGuerreiro[i], tituloGuerreiro[i]);
                            }
                        }

                        printf("\nInforme o codigo do guerreiro que deseja o dragao: ");
                        scanf("%d", &indiceGuerreiro);

                        if (indiceGuerreiro < MAX_GUERREIROS && indiceGuerreiro >= 0)
                        {
                            if (nomeGuerreiro[indiceGuerreiro][0] != '\0')
                            {
                                if (dragaoLocado[indiceGuerreiro] == -1)
                                {
                                    dragaoLocado[indiceGuerreiro] = indiceDragao;

                                    printf("Informe a data de entrega do dragao: ");
                                    fflush(stdin);
                                    scanf("%[^\n]s", dataEntrega[indiceGuerreiro]);
                                }
                                else if (dragaoLocado[indiceGuerreiro] >= 0)
                                {
                                    printf("\nEste guerreiro ja possui um dragao, portanto deve devolver ou locar em outro guerreiro: \n\n");
                                }
                            } 
                            else if (nomeGuerreiro[indiceGuerreiro][0] == '\0') 
                            {
                                printf("\nEste guerreiro ainda nao foi cadastrado por tando cadastre-o e volte mais tarde!!\n\n");
                            }               
                        }
                        else if ( indiceGuerreiro >= MAX_GUERREIROS || indiceGuerreiro < 0)
                        {
                            printf("\nO codigo do guerreiro eh invalido, por favor tente outro\n\n");
                        }
                    }
                    else if  (idadeDragao[indiceDragao] == -1)
                    {
                        printf("\nNao temos nenhum dragao cadastrado neste codigo, por favor volte e cadastre um!!\n\n");
                    }
                }
                else if ( indiceDragao >= MAX_DRAGOES || indiceDragao < 0)
                {
                    printf("\nCodigo invalido, por favor digite outro!!\n\n");
                }
                break;
            }
            //Devolução de Dragoes
            case 11:
            {
                printf("\nGUERREIROS COM DRAGOES LOCADOS:\n");
                printf("Codigo Nome Dragao Data p/ Entrega\n\n");
                
                for(i = 0;i < MAX_GUERREIROS;i++)
                {
                   if(dragaoLocado[i] != -1)
                   {
                       printf("%d %s %d %s\n",i, nomeGuerreiro[i], dragaoLocado[i], dataEntrega[i]);
                   }
                }

                printf("\nInforme o codigo do guerreiro que deseja devolver o dragao: ");
                scanf("%d", &indiceGuerreiro);

                if (indiceGuerreiro < MAX_GUERREIROS && indiceGuerreiro >= 0)
                {
                    if (nomeGuerreiro[indiceGuerreiro][0] != '\0')
                    {
                        if (dragaoLocado[indiceGuerreiro] >= 0)
                        {
                            dragaoLocado[indiceGuerreiro] = -1;
                            dataEntrega[indiceGuerreiro][0] = '\0';
                        }
                        else if(dragaoLocado[indiceGuerreiro] == -1)
                        {
                            printf("\nEste guerreiro ainda nao locou nenhum dragao\n\n");
                        }
                    }
                    else if(nomeGuerreiro[indiceGuerreiro][0] == '\0')
                    {
                        printf("\nNao existe nenhum guerreiro cadastrado neste codigo, verifique-o e tente novamente\n\n");
                    }
                }
                else if (indiceGuerreiro >= MAX_GUERREIROS || indiceGuerreiro < 0)
                {
                    printf("\nO codigo digitado eh invalido, por favor digite outro\n\n");
                }
                break;
            }
            //Erro menu
            default:
            {
                printf("\nCodigo do menu eh inexistente por favor digite outro!!!\n\n");
            }
        }

    } while (menu != 0);

    return 0;
}