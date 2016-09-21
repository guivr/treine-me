#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//Feito por Guilherme Vieira Rizzo - http://github.com/guivr - Favor manter creditos

/* function declaration */
void requerirDadosExc(int *limite, int *exerc);
void gerarNumsAleatorios (int limite);
void acertou ();
void errou ();
int msgFinal(int a, int e);

/*var globais*/
int a, e, x, y;

int main()
{
    int r, i, opcao, exerc, limite;
    a=e=limite=exerc=0;
    srand(time(NULL));
    printf("\n\n|------------------------------|\n| Treine.me  -  Guilherme Rizzo |\n|------------------------------|");
    printf("\n\nSelecione o tipo de operacao que voce deseja treinar:\n");
    printf("1.\tSoma\n2.\tSubtracao\n3.\tMultiplicacao\n4.\tDivisao\n5.\tPotenciacao\n6.\tRaiz quadrada\n7. \tSair\n\n");
    scanf("%d", &opcao);

    if (opcao >= 8 || opcao <= 0){
        printf("Opcao invalida.");
    }

    else if(opcao == 1){ //soma
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            gerarNumsAleatorios(limite);
            printf("\n\nQual a soma de %d + %d (para parar, digite -1)\n", x, y);
            scanf("%d", &r);
            if(r == -1){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == x+y ? acertou():errou();
            }
        }
        msgFinal(a,e);
        main();
    }

    else if(opcao==2){ //subtracao
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            gerarNumsAleatorios(limite);
            printf("\n\nQual a subtracao de %d - %d (para parar, digite -123)\n", x, y);
            scanf("%d", &r);
            if(r == -123){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == x-y ? acertou():errou();
            }
        }
        msgFinal(a,e);
        main();
    }

    else if(opcao==3){ //multiplicacao
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            gerarNumsAleatorios(limite);
            printf("\n\nQual a multiplicacao de %d * %d (para parar, digite -1)\n", x, y);
            scanf("%d", &r);
            if(r == -1){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == x*y ? acertou():errou();
            }
        }
        msgFinal(a,e);
        main();
    }

    else if(opcao==4){ //divisao
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            gerarNumsAleatorios(limite);
            printf("\n\nQual a divisao de %d / %d (para parar, digite -1)\n", x, y);
            scanf("%d", &r);
            if(r == -1){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == x/y ? acertou():errou();
            }
        }
        msgFinal(a,e);
        main();
    }

    else if(opcao==5){ //potenciacao
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            gerarNumsAleatorios(limite);
            printf("\n\nQual a potenciacao de %d com %d (para parar, digite -1)\n", x, y);
            scanf("%d", &r);
            if(r == -1){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == pow(x,y) ? acertou():errou();
            }
        }
        msgFinal(a,e);
        main();
    }

    else if(opcao==6){ //raiz quadrada
        int racional = 0;
        requerirDadosExc(&limite, &exerc);
        for(i=0; i<exerc; i++){
            racional = 0;
            while(racional==0){
                x = rand()%limite;
                if(x!=0 && x!=1){
                    if(sqrt(x) == floor(sqrt(x))){
                        racional += x;
                    }
                }
            }
            printf("\n\nQual a raiz quadrada de %d (para parar, digite -1)\n", racional);
            scanf("%d", &r);
            if(r == -1){
                if(a==0 && e==0){
                    main();
                }
                else{
                    break;
                }
            }
            else{
                r == sqrt(racional) ? acertou():errou();
            }
        }

        msgFinal(a,e);
        main();
    }

    else if(opcao==7){ //sair
        exit(0);
    }
}

void requerirDadosExc(int *limite, int *exerc){
    printf("\nDigite um limite para os numeros que serao gerados entre as operacaoes.\n");
    scanf("%d", limite);
    printf("\nAgora digite o numero de exercicios que voce deseja resolver.\n");
    scanf("%d", exerc);
}

void gerarNumsAleatorios(int limite){
    x = rand()%limite + 1;
    y = rand()%limite + 1;
}

void acertou(){
    printf("Acertou! Acertos ate agora: %d\n", ++a);
}

void errou(){
    printf("Errou! Erros ate agora: %d\n", ++e);
}

int msgFinal(int a, int e){
    printf("\nNumeros de questoes: %d", a+e);
    printf("\nAcertos: %d. Erros: %d.", a, e);
    printf("\nMedia de acertos: %d", ((a * 100) / (a+e)));
    return 0;
}
