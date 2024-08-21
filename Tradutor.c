#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcode, endereco, i;
    char leitura[1000],leitor[100];
    
    // criando a variável ponteiro para o arquivo
    FILE *pont_arqm;
    FILE *pont_arql;

    //abrindo arquivo para leitura
    pont_arql = fopen("arquivo.txt", "r");

    //confirmacao da abertura de arquivo
    if (pont_arql == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
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
    fprintf(pont_arqm,"03 4E 44 52");

    //leitura de caracteres
    while(fgets(leitura, sizeof(leitura), pont_arql) != NULL){
    // printf("%s", leitura);    
        if (strstr(leitura, "NOP") == 0){
            opcode=0;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        if (strstr(leitura, "STA") == 0){
            opcode=10;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "LDA") == 0){
            opcode=20;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "ADD") == 0){
            opcode=30;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "OR") == 0){
            opcode=40;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "AND") == 0){
            opcode=50;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "NOT") == 0){
            opcode=60;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "JMP") == 0){
            opcode=80;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "JN") == 0){
            opcode=90;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        else if (strstr(leitura, "JZ") == 0){
            opcode='A0';
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
            fscanf("falta algo aqui","%i",&endereco);
            opcode= endereco;
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
        if (strstr(leitura, "HLT") == 0){
            opcode='F0';
            fwrite(&pont_arql,sizeof(pont_arql),1,pont_arqm);
        }
    }
    // fechando arquivo
    fclose(pont_arql);
    fclose(pont_arqm);
        
    //mensagem para o usuário
    printf("O arquivo convertido foi criado com sucesso!");
        
    system("pause");
    return(0);
}