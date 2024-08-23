// Rafael Alves de Sousa Costa  | RA:22304563
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
char* ascii_to_binary_char(char letra);
char binary_to_ascii_char(char* numbin);


void clear_screen(void);

//MAIN
int main(){
    menuprincipal();
    return(0);

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
    printf("\nTipo de criptografia\n\n1) Cesar\n2) Vernam\n3) VOLTAR\n\n");//todo

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
                //todo();

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

//MENU PRINCIPAL -> MENU CODE -> MENU VERNAM

void menuVerman(){

    char* texto= malloc((1024)*sizeof(char));
    char* senha= malloc((1024)*sizeof(char));
    int escolha;

    printf("\nCIFRA VERMAN");
    printf("\nDigite o texto:\n");

    char dummy[1024];
    fgets(dummy, 1024, stdin);


    fgets(texto,1024,stdin);


    printf("\n\nDigite a chave da sua mensagem:\n");

    fgets(senha,1024,stdin);
   /* char* retorno =codificadorVernam(texto,senha);*/

    clear_screen();
    printf("");

}

//MENU PRINCIPAL -> MENU DECODE

void menudecode(){

    int escolha;
    printf("\nMENU DECODE");
    printf("\nTipo de criptografia\n\n1) Cesar\n2) Vernam\n3) VOLTAR\n\n");//todo

    scanf("%d",&escolha);
        
        switch(escolha)
        {

            case 1:

                clear_screen();
                menudecodecesar();
                break;

            case 2:

                clear_screen();
                menuVerman();
                break;
                //todo();

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
    //todo    
    /*printf("\n Rotacao (0 a 25)\n210) Testa todos\n");
    scanf("%d",&selecao);*/

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

    /*
        1)
        sob metricas normais essa declaração parece errada pois junta char com ints, entretanto a
        liguagem C comprende que se trata do calculo baseado no codigo asc  primeiramente o codigo
        vai descobrir de 0 a 25 qual termo do alfabeto está o Temp, no primeiro modelo acabei por
        fazer uma tabela que retornava o valor mas da pra resumir 50 linhas em 1

        temp(um termo char) - 'A' faz com que encontremos entre 0 e 25 onde o valor se encontra 
        ex: F - 'A' = 70 - 65 = 5 <- posicao alfabeto
        ai adicionamos o K e checamos se é maior que 25(limite alfabeto) vendo se existe resto,
        depois adicionamos o valor de 'A' subtraido anteriormente
*/

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
    
    printf("\nCódigo Cifrado:\n\n%s\n",retorno);
    
}

//CODIFICADORES VERNAM
/*
char* codificadorVernam(char* mensagem, char* chave){
    
    int lenm= strlen(mensagem);
    int lenk= strlen(chave);
    char* chavecomp=equalizadordestring(mensagem, chave);
    char temp;
    char* resultado=malloc((lenm+1)*sizeof(char));
    for(int i=0;i<lenm;i++)
    {

        temp = mensagem[i] ^ chavecomp[i];
        printf("%c",temp);
    }
    resultado[lenm]='\0';
    free(chavecomp);
    return resultado;
}

char* equalizadordestring(char* mensagem,char* chave){

    int lenm=strlen(mensagem);
    int lenk=strlen(chave);
    char* temp=malloc((lenm+1)*sizeof(char));

    for(int i=0;i<lenm;i++)
    {

        temp[i]=chave[i % lenk];
    
    }
    
    temp[lenm]='\0';
    return temp;

}

*/
/*  
    ideia principal transformar o valor asc em um valor binario, realizar xor por meio da chave
    para caber em strings de tamanhos diversos, esse nao possui limitador de alfabeto, tampouco
    deve realizar o reset ao chegar ao fim da tabela asc
*/

char* equalizador_de_string(char* frase, char* senha)
{

    if (!frase || !senha) {
        return NULL;
    }

    int lens = strlen(frase);
    int lensenha = strlen(senha);

    char* retorno = malloc(lens * sizeof(char));
    if (!retorno) {
        return NULL;
    }

    char* temp = malloc(lens * sizeof(char));
    if (!temp) {
        free(retorno);
        return NULL;
    }

    for (int i = 0; i < lens; i++) {
        temp[i] = senha[i % lensenha];
    }

    strcpy(retorno, temp);
    free(temp);
    return retorno;

}

char* ascii_to_binary_string(char* frase)
{

    int len=strlen(frase);
    char* retorno=malloc(((len*8)+1)*sizeof(char));
    retorno[0]='\0';
    char* temp=malloc(9*sizeof(char));

    for(int i=0;i<len;i++){
            temp=ascii_to_binary_char(frase[i]);
            strcat(retorno,temp);
            free(temp);

    }
    return retorno;
}

char* ascii_to_binary_char(char letra)
{

    unsigned char asciivalue= letra;
    char* retornobin=malloc(9*sizeof(char));
    if(retornobin==NULL){
        return NULL;
    }
    sprintf(retornobin,"%08b",asciivalue);
    return retornobin;

}

char* xor(char* mensagembin, char* chave)
{   
    int len =  strlen(mensagembin);
    char* retorno=malloc((len+1)*sizeof(char));
    if(retorno==NULL)
    {
        return NULL;
    }
    for (int i = 0; i < len; i++)
    {
        retorno[i] = (mensagembin[i] == chave[i]) ? '0' : '1';
    }
    retorno[len]='\0';
    return retorno;
}

char* binary_to_ascii_string(char* frasebin)
{
    
    int len=strlen(frasebin);
    char* retorno= malloc((len/8)+1);
    retorno[0]='\0';
    for(int i=0; i<len;i+=8){
        char* temp= binary_to_ascii_char(frasebin + i);
        strcat(retorno, temp);
        free(temp);
    }
    return retorno;

}

char binary_to_ascii_char(char* numbin)
{

    long valor= strtol(numbin ,NULL ,2);
    char retorno = (char)valor;
    return retorno;

}
//todo


//ADICIONAR CODIFICADORES AQUI

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

        if(i<10)
        {

            printf("Rotacao 0%d: %s",i,retorno);
        
        }
        else
        {


            printf("Rotacao %d: %s",i,retorno);

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

//todo

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

//todo














//cp paste residual


//base input copiar nos menus.


//codigo a seguir pode ser substituido por um simples "^" entre 2 strings....


/*    fflush();
    char* texto= malloc((1024)*sizeof(char));
    printf("Digite o texto:\n");
    fgets(texto,1024,stdin);
    printf("\nAgora digite um numero de 0 a 25:\n");
    scanf("%d",&k);

}*/