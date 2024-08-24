#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//ascii seguranca, outros algoritmos estavam dando problema por conta de caracteres nao "printaveis"
const char* ascii_armor_table = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "
                                 "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "0123456789";

//DECLARACAO DE FUNCOES
void menuprincipal(void);
void menucode(void);
void menudecode(void);
void menucesar(void);
void menudecodecesar(void);
void derCaesarEncoder(char* mensagem, int k);
char codeRevCesar(char letra,int k);
void decoderCesar(char* mensagem, int selecao);
char* equalizador_de_string(char* frase, char* senha);
void menuVerman();
void codeurVernam(char* texto,char* senha,char* cripto);
void decodeurVernam(char *cripto,char*senha,char* texto);
void menuDecodeVernam(void);
void clear_screen(void);

//MAIN
int main(){
    menuprincipal();
    return 0;
}

//menus

//MENU PRINCIPAL

void menuprincipal(){

    int escolha,k;
    printf("decoder.c");
    printf("\nCifrar ou Decifrar?\n\n1) Cifrar\n2) Decifrar\n3) SAIR\n\n");
    scanf("%d",&escolha);
    
    switch(escolha)
    {

        case 1:

            clear_screen();
            menucode();
            break;

        case 2:

            clear_screen();
            menudecode();
            break;

        case 3:

            printf("\n\n");
            clear_screen();
            exit(0);

        default:

            clear_screen();
            printf("\n");
            menuprincipal();
            break;

    }
}

//MENU PRINCIPAL - MENU CODE

void menucode(){

    int escolha;

    printf("\nMENU CODE");
    printf("\nTipo de criptografia\n\n1) Cesar\n2) Vernam\n3) VOLTAR\n\n");

    scanf("%d",&escolha);
        
        switch(escolha)
        {

            case 1:

                clear_screen();
                menucesar();
                break;

            case 2:
                clear_screen();
                menuVerman();
                break;

            case 3:

                clear_screen();
                printf("\n");
                menuprincipal();
                break;

            default:

                clear_screen();
                printf("VALOR INVALIDO!!");
                menuprincipal();
                break;

        }
}

//MENU PRINCIPAL -> MENU CODE -> MENU CESAR

void menucesar(){

    char* texto= malloc((1024)*sizeof(char));
    int k,escolha;

    printf("\nCIFRA CESAR");
    printf("\nDigite o texto:\n");

    char dummy[1024];
    fgets(dummy, 1024, stdin);

    fgets(texto,1024,stdin);


    printf("\nAgora digite um numero de 0 a 25:");
    

    scanf(" %d",&k);
    clear_screen();
    if(k>=0 && k<=25)
    {
    
        derCaesarEncoder(texto,k);
        printf("\n1) Continuar usando\n0) Fechar\n");
        scanf("%d",&escolha);

        switch(escolha)
        {

            case 1:

                clear_screen();
                printf("\n");
                menuprincipal();
                break;
            //case 2:
                //todo cifracao recursiva
            default:

                printf("\n\n");
                clear_screen();
                exit(0);
        
        }
    }

    else
    {

        clear_screen();
        printf("VALOR INVALIDO!!\nESCOLHA UM NUMERO ENTRE 0 E 25\n\n");
        menucesar();

    }

}
//MENU PRINCIPAL -> MENU DECODE

void menudecode(){

    int escolha;
    printf("\nMENU DECODE");
    printf("\nTipo de criptografia\n\n1) Cesar\n2) Vernam\n3) VOLTAR\n\n");

    scanf("%d",&escolha);
        
        switch(escolha)
        {

            case 1:

                clear_screen();
                menudecodecesar();
                break;

            case 2:

                clear_screen();
                menuDecodeVernam();
                break;

            case 3:

                clear_screen();
                printf("\n");
                menuprincipal();
                break;

            default:

                clear_screen();
                printf("VALOR INVALIDO!!");
                menuprincipal();
                break;

        }
}

//MENU PRINCIPAL -> MENU DECODE -> MENUDECODECESAR

void menudecodecesar(){
    char* texto= malloc((1024)*sizeof(char));
    int k,escolha;

    printf("\nDECIFRADOR DE CESAR");
    printf("\nDigite o texto a ser decifrado:\n");

    char dummy[1024];
    fgets(dummy, 1024, stdin);

    fflush(stdin);

    fgets(texto,1024,stdin);


    printf("\nRotacao (0 a 25)\n210) Testa todos\n");
    

    scanf(" %d",&k);
    clear_screen();

    if((k>=1 && k<=25) ||k==210)
    {
    
        decoderCesar(texto,k);
        printf("\n1) Continuar usando\n0) Fechar\n");
        scanf("%d",&escolha);

        switch(escolha)
        {

            case 1:

                clear_screen();
                printf("\n");
                menuprincipal();
                break;
            //case 2:
                //todo cifracao recursiva
            default:

                printf("\n\n");
                clear_screen();
                exit(0);
        
        }
    }

    else
    {

        clear_screen();
        printf("VALOR INVALIDO!!\nESCOLHA UM NUMERO ENTRE 0 E 25 OU 210\n\n");
        menucesar();

    }

}

//MENU PRINCIPAL -> MENU DECODE -> MENUCECODEVERMAN

//codificadores

//CODIFICADORES DE CESAR 

char codificadorCesar(char letra,int k){

    char retorno,temp; 

    if(isalpha(letra)){

        temp=toupper(letra);
        retorno=(temp -'A' + k) %26 + 'A'; 

        //Essa linha de codigo aqui explicada 1:

    }else if(isspace(letra))
    {
    
        retorno=letra;

    }

    return retorno;

}

void derCaesarEncoder(char* mensagem,int k){

    int len= strlen(mensagem);
    char* retorno=malloc((len+1)*sizeof(char));

    for(int i=0;mensagem[i]!='\0';i++)
    {

        if(isalpha(mensagem[i]) || isspace(mensagem[i])){

            char c=codificadorCesar(mensagem[i],k);
            strncat(retorno,&c,1);

        }
        else
        {
            
            char c=mensagem[i];
            strncat(retorno,&c,1);

        }

    }

    strcat(retorno,"\0");
    printf("\nMensagem: %sRotacao: %d\nMensagem Cifrada:\n%s\n",mensagem, k, retorno);
    
}


//MENU PRINCIPAL -> MENU CODE -> MENU VERNAM

void menuVerman() {
    char* texto = malloc(1024 * sizeof(char));
    char* senha = malloc(1024 * sizeof(char));
    char* cripto = malloc(1024 * sizeof(char));
    char* decrypted_texto = malloc(1024 * sizeof(char));

    printf("\nCIFRA VERMAN");
    printf("\nDigite o texto:\n");
    char dummy[1024];
    fgets(dummy, 1024, stdin);

    fgets(texto, 1024, stdin);
    texto[strcspn(texto, "\n")] = 0;

    printf("\nDigite a chave da sua mensagem:\n");
    fgets(senha, 1024, stdin);
    senha[strcspn(senha, "\n")] = 0;

    codeurVernam(texto, senha, cripto);
    clear_screen();

    printf("\nMensagem: %s\nSenha: %s\nTexto cifrado:\n%s\n",texto,senha, cripto);

    free(texto);
    free(senha);
    free(cripto);
    
    printf("\n1) Continuar usando\n0) Fechar\n");
    int escolha;
    scanf("%d",&escolha);

    switch(escolha)
    {

        case 1:

            clear_screen();
            printf("\n");
            menuprincipal();
            break;
        //case 2:
        //todo cifracao recursiva
        default:

            printf("\n\n");
            clear_screen();
            exit(0);
        
    }

}


//CODIFICADORES VERNAM

void codeurVernam(char* texto,char* senha,char* cripto)
{
    int i, j;
    for (i = 0, j = 0; i < strlen(texto); i++, j = (j + 1) % strlen(senha)) {
        unsigned char c = texto[i] ^ senha[j];
        cripto[i] = ascii_armor_table[c % (strlen(ascii_armor_table) - 1)];
    }
    cripto[i] = '\0';
}


void decodeurVernam(char *cripto,char*senha,char* texto)
{
    int i, j;
    for (i = 0, j = 0; i < strlen(cripto); i++, j = (j + 1) % strlen(senha)) {
        unsigned char c = cripto[i];
        for (int k = 0; k < strlen(ascii_armor_table); k++) {
            if (c == ascii_armor_table[k]) {
                c = k;
                break;
            }
        }
        texto[i] = c ^ senha[j];
    }
    texto[i] = '\0';
}
//todo


//ADICIONAR CODIFICADORES FUTUROS

//todo

//decodificadores



//DECODIFICADOR DE CESAR

void decoderCesar(char* mensagem,int selecao){

    int len= strlen(mensagem);
    char* retorno=malloc((len+1)*sizeof(char));

    if(selecao>=0 && selecao<=25){

        for(int i=0;mensagem[i]!='\0';i++){

            char c=codeRevCesar(mensagem[i],selecao);
            strncat(retorno,&c,1);
            
        }
        strcat(retorno,"\0");
    
        printf("\nCódigo Decifrado:\n\n%s\n",retorno);
    }
    else if (selecao==210)
    {
        for (int i = 0; i <= 25; i++)
        {
        memset(retorno, 0, len + 1);


            for(int j=0;mensagem[j]!='\0';j++)
            {

                char c=codeRevCesar(mensagem[j],i+1);
                strncat(retorno,&c,1);

            }

        strcat(retorno,"\0");    

        if(i<9)
        {

            printf("Rotacao 0%d: %s",i+1,retorno);
        
        }
        else if(i==25){
            printf("Codigo: %s",retorno);
        }
        else
        {


            printf("Rotacao %d: %s",i+1,retorno);

        }

        }
        printf("Fim"); 

    }

}
    

char codeRevCesar(char letra,int k){

    char temp,retorno;
    
    if(isalpha(letra))
    {

        temp=toupper(letra);
        retorno=(temp - 'A' - k) %26 + 'A';
        
        if(retorno < 'A')
        {

            retorno += 26;

        }
    }
    else
    {

        retorno=letra;
    
    }
    
    return retorno;

}

//DECODIFICADOR DE VERNAM

void menuDecodeVernam() {
    char* cripto = malloc(1024 * sizeof(char));
    char* senha = malloc(1024 * sizeof(char));
    char* decrypted_texto = malloc(1024 * sizeof(char));

    printf("\nDECIFRAR CIFRA VERMAN");
    printf("\nDigite o texto cifrado:\n");
    char dummy[1024];
    fgets(dummy, 1024, stdin);

    fgets(cripto, 1024, stdin);
    cripto[strcspn(cripto, "\n")] = 0;

    printf("\n\nDigite a chave da sua mensagem:\n");
    fgets(senha, 1024, stdin);
    senha[strcspn(senha, "\n")] = 0;
    clear_screen();

    decodeurVernam(cripto, senha, decrypted_texto);
    printf("\nCodigo: %s\nSenha: %s\nTexto decifrado:\n%s\n",cripto,senha, decrypted_texto);

    free(cripto);
    free(senha);
    free(decrypted_texto);

    printf("\n1) Continuar usando\n0) Fechar\n");
    int escolha;
    scanf("%d",&escolha);

    switch(escolha)
    {

        case 1:

            clear_screen();
            printf("\n");
            menuprincipal();
            break;
        default:

            printf("\n\n");
            clear_screen();
            exit(0);
        
    }
}

//DECODIFICADORES FUTUROS

//todo

//FUNCOES ADICIONAIS

//limpa tela

void clear_screen(){

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}