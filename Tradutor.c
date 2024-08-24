#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    unsigned char opcode;
    int endereco;
    char leitura[1000];
    
    // criando a variável ponteiro para o arquivo
    FILE *pont_arqm; //Ponteiro de Modificacao
    FILE *pont_arql; //Ponteiro de Leitura

    //abrindo arquivo para leitura
    pont_arql = fopen("prog1.asm", "r");

    //confirmacao da abertura de arquivo
    if (pont_arql == NULL){
        printf("ERRO! O arquivo nao foi aberto! Verifique se o arquivo está na mesma pasta que o Tradutor.exe\n");
        return 1;//encerra o programa caso de erro
    } else {
        printf("O arquivo foi aberto com sucesso!\n");
    }

    // Abrindo o arquivo para escrita
    pont_arqm = fopen("prog1.mem", "a");
    if (pont_arqm == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        fclose(pont_arql);
        return 1;
    }

    //printar o cabecalho do codigo
    opcode = 3;
    fwrite(&opcode,sizeof(opcode),1,pont_arqm);
    opcode = 78;
    fwrite(&opcode,sizeof(opcode),1,pont_arqm);
    opcode = 68;
    fwrite(&opcode,sizeof(opcode),1,pont_arqm);
    opcode = 82;
    fwrite(&opcode,sizeof(opcode),1,pont_arqm);


    //leitura de caracteres
    while(fgets(leitura, sizeof(leitura), pont_arql) != NULL){
        leitura[strcspn(leitura, "\n")] = 0;   //Remove o caractere de nova linha ('\n')    
        if (strcmp(leitura, "NOP") == 0){
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "STA") == 0){
            opcode=16;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "LDA") == 0){
            opcode=32;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "ADD") == 0){
            opcode=48;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "OR") == 0){
            opcode=64;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "AND") == 0){
            opcode=80;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "NOT") == 0){
            opcode=96;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "JMP") == 0){
            opcode=128;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "JN") == 0){
            opcode=144;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            opcode= endereco;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "JZ") == 0){
            opcode=160;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            fscanf(pont_arql,"%i",&endereco);
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
        if (strcmp(leitura, "HLT") == 0){
            opcode=240;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
            opcode=0;
            fwrite(&opcode,sizeof(opcode),1,pont_arqm);
        }
    }
    // fechando arquivo
    fclose(pont_arql);
    fclose(pont_arqm);
        
    //mensagem para o usuário
    printf("O arquivo foi convertido com sucesso!");
        
    system("pause");
    return(0);
}