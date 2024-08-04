#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // In�cio da cria��o de vari�veis/strings
    char arquivo[40];    // vari�vel para armazenar o nome do arquivo
    char cpf[40];        // vari�vel para armazenar o CPF do usu�rio
    char nome[40];       // vari�vel para armazenar o nome do usu�rio
    char sobrenome[40];  // vari�vel para armazenar o sobrenome do usu�rio
    char cargo[40];      // vari�vel para armazenar o cargo do usu�rio
    // Fim da cria��o de vari�veis/strings

    printf("Digite o CPF para ser cadastrado: "); // Solicita o CPF do usu�rio
    scanf("%s", cpf); // L� o CPF fornecido pelo usu�rio e armazena na vari�vel cpf (o %s indica que � uma string)

    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

    FILE *file;                // Cria um ponteiro para o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    if (file != NULL) // Verifica se o arquivo foi criado com sucesso
    {
        fprintf(file, "%s", cpf); // Salva o valor da vari�vel CPF no arquivo
        fclose(file);       // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, ","); // Adiciona uma v�rgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o nome a ser cadastrado: "); // Solicita o nome do usu�rio
        scanf("%s", nome); // L� o nome fornecido pelo usu�rio e armazena na vari�vel nome (o %s indica que � uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, "%s", nome); // Adiciona o nome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, ","); // Adiciona uma v�rgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o sobrenome a ser cadastrado: "); // Solicita o sobrenome do usu�rio
        scanf("%s", sobrenome); // L� o sobrenome fornecido pelo usu�rio e armazena na vari�vel sobrenome (o %s indica que � uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, "%s", sobrenome); // Adiciona o sobrenome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, ","); // Adiciona uma v�rgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o cargo a ser cadastrado: "); // Solicita o cargo do usu�rio
        scanf("%s", cargo); // L� o cargo fornecido pelo usu�rio e armazena na vari�vel cargo (o %s indica que � uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adi��o
        fprintf(file, "%s", cargo); // Adiciona o cargo no arquivo
        fclose(file); // Fecha o arquivo
    }
    {
        printf("Erro ao criar o arquivo.\n"); // Mensagem de erro
    }

    system("pause"); // Pausa o sistema para que o usu�rio possa ver as mensagens
}

int consulta() // fun��o respons�vel por consultar os usu�rios no sistema
{
    setlocale(LC_ALL, "Portuguese"); // Define o local para suporte a portugu�s
    
    // In�cio da cria��o de vari�veis/strings
    char cpf[40];        // Vari�vel para armazenar o CPF do usu�rio
    char conteudo[200];  // Vari�vel para armazenar o conte�do do arquivo
    // Fim da cria��o de vari�veis/strings

    printf("Digite o CPF a ser consultado: "); // Solicita o CPF para consulta
    scanf("%s", cpf); // L� o CPF fornecido pelo usu�rio e armazena na vari�vel cpf (o %s indica que � uma string)

    FILE *file; // Cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura

    if (file == NULL) // Verifica se o arquivo foi aberto com sucesso
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n"); // Mensagem de erro
    }
    {
        while (fgets(conteudo, 200, file) != NULL) // L� o conte�do do arquivo
        {
            printf("\nEssas s�o as informa��es do usu�rio: ");
            printf("%s", conteudo); // Exibe o conte�do do arquivo
            printf("\n\n");
        }
        fclose(file); // Fecha o arquivo
    }

    system("pause"); // Pausa o sistema para que o usu�rio possa ver as mensagens
}

int deletar() // fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40]; // Vari�vel para armazenar o CPF do usu�rio
    
    printf("Digite o CPF a ser deletado: "); // Solicita o CPF para deletar
    scanf("%s", cpf); // L� o CPF fornecido pelo usu�rio e armazena na vari�vel cpf (o %s indica que � uma string)

    remove(cpf); // Remove o arquivo associado ao CPF

    FILE *file; // Cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo para verificar se foi removido

    if (file == NULL) // Verifica se o arquivo foi removido com sucesso
    {
        printf("O usu�rio n�o se encontra no sistema!\n"); // Mensagem de sucesso
        system("pause"); // Pausa o sistema para que o usu�rio possa ver as mensagens
    }
    {
        fclose(file); // Fecha o arquivo caso ele ainda exista
    }
}

int main() // Fun��o principal que controla o fluxo do programa
{
    int opcao = 0; // Vari�vel para armazenar a op��o do menu
    int laco = 1; // Vari�vel de controle do loop

    while (laco == 1) // Loop principal do programa
    {
        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "Portuguese"); // Define o local para suporte a portugu�s

        // In�cio do menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); // Fim do menu

        scanf("%d", &opcao); // Armazena a escolha do usu�rio

        system("cls"); // Respons�vel por limpar a tela

        switch (opcao) // In�cio da sele��o do menu
        {
            case 1:
                registro(); // Chama a fun��o de registro
                break;

            case 2:
                consulta(); // Chama a fun��o de consulta
                break;

            case 3:
                deletar(); // Chama a fun��o de deletar
                break;
            
            case 4:
                printf("Obrigado por utilizar o sistema!\n"); // Mensagem de despedida
                return 0; // Encerra o programa
                
            default: // Caso o usu�rio escolha uma op��o inv�lida
                printf("Essa op��o n�o est� dispon�vel!\n"); // Mensagem de erro
                system("pause"); // Pausa o sistema para que o usu�rio possa ver as mensagens
                break;
        }
    }
}
