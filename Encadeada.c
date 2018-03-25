#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct fila
{
    int dado;
    struct fila *prox;

} NODO;

///inicializo a lista
void inicia_lista(NODO **L)
{
    *L=NULL;
}

///Apagar Lista
int apaga_lista (NODO **L)
{
    free(*L);
    return 1;
}

///Crio Nodo
NODO *Cria_Nodo()
{
    NODO *p;
    p=(NODO*)malloc(sizeof(NODO));
    if(!p)
    {
        printf("Problema de Alocaçao");
        exit(0);
    }
    return p;
}

///insiro no Inicio
void insere_inicio(NODO **L,int dado)
{
    NODO *p;

    p= Cria_Nodo();
    p->dado=dado;
    p->prox=*L;
    *L= p;
    printf("Inserido Com Sucesso\n");

}

///insiro no Fim
void insere_fim(NODO **L,int dado)
{
    NODO *novo, *aux;

    novo=Cria_Nodo();
    novo->dado=dado;
    novo->prox=NULL;
    if(*L==NULL)
    {
        *L=novo;
    }
    else
    {
        aux=*L;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=novo;

    }

}
///Insere Ordenado
void insere_ordenado(NODO **L,int valor)
{
    NODO *atual, *novo, *anterior;

    novo = (NODO*)malloc(sizeof(NODO));

    atual = *L;
    anterior = NULL;

    novo->dado = valor;

    if(atual == NULL)
    {
        novo->prox = NULL;
        *L = novo;
    }
    else
    {
        while(atual != NULL && atual->dado < valor)
        {
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL)
        {
            *L = novo;
        }
        else
        {
            anterior->prox = novo;
        }
    }

}
///Quantidade de Elementos Inseridos
void quantidade (NODO *L,int tot)
{
    NODO * aux;
    if(L==NULL)
    {
        printf("\nLista Vazia");
    }
    for(aux=L; aux!=NULL; aux=aux->prox)
        tot=tot++;
}
///Impressão
void imprime (NODO *L)
{
    NODO * aux;

    if(L==NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        for(aux=L; aux!=NULL; aux=aux->prox)
            printf("\n%d",aux->dado);

    }
}
///Exclui um elemento determinado
void exclui_determinado(NODO **L, int procura)
{
    NODO *aux,*dado;

    if(*L == NULL)
        printf("Lista Vazia");

    for(aux=*L; aux!=NULL; aux=(*L)->prox)
    {
        if(aux->dado==procura)
        {
            dado = (*L)->prox;
            free(*L);
            *L = dado;
        }
    }


}

///Procura Elemento
int procura_elemento(NODO **L, int procura)
{
    NODO *aux,*dado;

    if(*L == NULL)
        printf("Lista Vazia");

    for(aux=*L; aux!=NULL; aux=(*L)->prox)
    {
        if(aux->dado==procura)
        {
            printf("\n Dado Localizado!\n");
        }
        else
        {
            return 0;
        }
    }

}
///Exclui pelo Inicio
int exlui_inicio(NODO **L)
{
    NODO *aux;
    if((*L)->prox == NULL)
    {
        printf("Lista vazia\n");
        return NULL;
    }
    else
    {
        aux = (*L)->prox;
        (*L)->prox = aux->prox;

        return 1;
    }
}

///Exclui Pelo Fim
int exclui_fim(NODO **L)
{
    NODO *ultimo,*penultimo;

    if((*L)->prox == NULL)
    {
        printf("Lista vazia\n\n");
        return NULL;
    }
    else
    {
        ultimo = (*L)->prox,
        penultimo = (*L);

        while(ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;

        return 1;
    }
}
void main()
{
    NODO *L;
    int dado,opcao,aux,aux1;
    ///Inicio o ponteiro
    inicia_lista(&L);

    while (opcao != 11)
    {
        printf("\nBEM VINDO AO SISTEMA ARMAZENADOR DE DADOS\n");
        printf("1-Inserir elemento no fim da lista\n");
        printf("2-Inserir no Inicio da Lista\n");
        printf("3-Imprime Lista\n");
        printf("4-Quantidade de Elementos na Lista\n");
        printf("5-Exclui Inicio\n");
        printf("6-Exclui Fim\n");
        printf("7-Excluir elemento determinado\n");
        printf("8-Procurar elemento\n");
        printf("9-Eleminar Lista\n");
        printf("10-Insere Ordenado\n");
        printf("11-Sair\n");

        scanf("%d",&opcao);
        system("cls");
        switch(opcao)
        {
        case 1:
            printf("Digite o dado a ser armazenado\n");
            scanf("%d",&dado);
            insere_fim(&L,dado);
            break;

        case 2:
            printf("Digite o dado a ser armazenado\n");
            scanf("%d",&dado);
            insere_inicio(&L,dado);
            break;

        case 3:
            imprime(L);
            break;

        case 4:
            printf("Quantidade de elementos no Vetor:\n");
            quantidade(L,aux);
            printf("%d",aux);
            break;

        case 5:
            printf("Excluindo Inicio\n");
            aux=exlui_inicio(&L);
            if(aux==1)
                printf("Exclusão Realizada");
            system("cls");
            break;

        case 6:
            printf("Excluindo Fim\n");
            aux=exclui_fim(&L);
            if(aux==1)
                printf("Exclusão Realizada");
            system("cls");
            break;

        case 7:
            printf("Digite o elemento que deseja excluir\n");
            scanf("%d",&aux);
            exclui_determinado(&L,aux);
            break;

        case 8:
            printf("Digite o elemento que deseja procurar\n");
            scanf("%d",&aux);
            aux=procura_elemento(&L,aux);
            if(aux==0)
                printf("\n Dado não Localizado!\n");

            break;

        case 9:
            printf("Deletando Lista\n");

            aux= apaga_lista(&L);
            if(aux==1)
                printf("\n Lista Excluida!\n");

            break;

        case 10:
            printf("Digite o dado a ser armazenado\n");
            scanf("%d",&dado);
            insere_ordenado(&L,dado);
            break;




        }

    }

}
