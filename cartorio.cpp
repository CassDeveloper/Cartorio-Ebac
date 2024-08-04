#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema
{
    // Início da criação de variáveis/strings
    char arquivo[40];    // variável para armazenar o nome do arquivo
    char cpf[40];        // variável para armazenar o CPF do usuário
    char nome[40];       // variável para armazenar o nome do usuário
    char sobrenome[40];  // variável para armazenar o sobrenome do usuário
    char cargo[40];      // variável para armazenar o cargo do usuário
    // Fim da criação de variáveis/strings

    printf("Digite o CPF para ser cadastrado: "); // Solicita o CPF do usuário
    scanf("%s", cpf); // Lê o CPF fornecido pelo usuário e armazena na variável cpf (o %s indica que é uma string)

    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

    FILE *file;                // Cria um ponteiro para o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
    if (file != NULL) // Verifica se o arquivo foi criado com sucesso
    {
        fprintf(file, "%s", cpf); // Salva o valor da variável CPF no arquivo
        fclose(file);       // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, ","); // Adiciona uma vírgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o nome a ser cadastrado: "); // Solicita o nome do usuário
        scanf("%s", nome); // Lê o nome fornecido pelo usuário e armazena na variável nome (o %s indica que é uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, "%s", nome); // Adiciona o nome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, ","); // Adiciona uma vírgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o sobrenome a ser cadastrado: "); // Solicita o sobrenome do usuário
        scanf("%s", sobrenome); // Lê o sobrenome fornecido pelo usuário e armazena na variável sobrenome (o %s indica que é uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, "%s", sobrenome); // Adiciona o sobrenome no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, ","); // Adiciona uma vírgula no arquivo
        fclose(file); // Fecha o arquivo

        printf("Digite o cargo a ser cadastrado: "); // Solicita o cargo do usuário
        scanf("%s", cargo); // Lê o cargo fornecido pelo usuário e armazena na variável cargo (o %s indica que é uma string)

        file = fopen(arquivo, "a"); // Abre o arquivo em modo de adição
        fprintf(file, "%s", cargo); // Adiciona o cargo no arquivo
        fclose(file); // Fecha o arquivo
    }
    {
        printf("Erro ao criar o arquivo.\n"); // Mensagem de erro
    }

    system("pause"); // Pausa o sistema para que o usuário possa ver as mensagens
}

int consulta() // função responsável por consultar os usuários no sistema
{
    setlocale(LC_ALL, "Portuguese"); // Define o local para suporte a português
    
    // Início da criação de variáveis/strings
    char cpf[40];        // Variável para armazenar o CPF do usuário
    char conteudo[200];  // Variável para armazenar o conteúdo do arquivo
    // Fim da criação de variáveis/strings

    printf("Digite o CPF a ser consultado: "); // Solicita o CPF para consulta
    scanf("%s", cpf); // Lê o CPF fornecido pelo usuário e armazena na variável cpf (o %s indica que é uma string)

    FILE *file; // Cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // Abre o arquivo em modo de leitura

    if (file == NULL) // Verifica se o arquivo foi aberto com sucesso
    {
        printf("Não foi possível abrir o arquivo, não localizado.\n"); // Mensagem de erro
    }
    {
        while (fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo
        {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo); // Exibe o conteúdo do arquivo
            printf("\n\n");
        }
        fclose(file); // Fecha o arquivo
    }

    system("pause"); // Pausa o sistema para que o usuário possa ver as mensagens
}

int deletar() // função responsável por deletar os usuários no sistema
{
    char cpf[40]; // Variável para armazenar o CPF do usuário
    
    printf("Digite o CPF a ser deletado: "); // Solicita o CPF para deletar
    scanf("%s", cpf); // Lê o CPF fornecido pelo usuário e armazena na variável cpf (o %s indica que é uma string)

    remove(cpf); // Remove o arquivo associado ao CPF

    FILE *file; // Cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo para verificar se foi removido

    if (file == NULL) // Verifica se o arquivo foi removido com sucesso
    {
        printf("O usuário não se encontra no sistema!\n"); // Mensagem de sucesso
        system("pause"); // Pausa o sistema para que o usuário possa ver as mensagens
    }
    {
        fclose(file); // Fecha o arquivo caso ele ainda exista
    }
}

int main() // Função principal que controla o fluxo do programa
{
    int opcao = 0; // Variável para armazenar a opção do menu
    int laco = 1; // Variável de controle do loop

    while (laco == 1) // Loop principal do programa
    {
        system("cls"); // Limpa a tela

        setlocale(LC_ALL, "Portuguese"); // Define o local para suporte a português

        // Início do menu
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazena a escolha do usuário

        system("cls"); // Responsável por limpar a tela

        switch (opcao) // Início da seleção do menu
        {
            case 1:
                registro(); // Chama a função de registro
                break;

            case 2:
                consulta(); // Chama a função de consulta
                break;

            case 3:
                deletar(); // Chama a função de deletar
                break;
            
            case 4:
                printf("Obrigado por utilizar o sistema!\n"); // Mensagem de despedida
                return 0; // Encerra o programa
                
            default: // Caso o usuário escolha uma opção inválida
                printf("Essa opção não está disponível!\n"); // Mensagem de erro
                system("pause"); // Pausa o sistema para que o usuário possa ver as mensagens
                break;
        }
    }
}
