#include <stdio.h>
#include <string.h>
#include<locale.h>
#include<stdlib.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 50
#define MAX_PASS_LEN 50

// armazena usu�rio e senha criptografada
typedef struct {
    char username[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
} User;

User users[MAX_USERS];
int userCount = 0;

//  criptografia de senha 
void encryptPassword(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] += 3;  
    }
}

// Fun��o de descriptografia de senha
void decryptPassword(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] -= 3;  
    }
}

// Adicionarum novo usu�rio
void addUser() {
    if (userCount < MAX_USERS) {
        printf("Digite o nome de usu�rio: ");
        scanf("%s", users[userCount].username);
        printf("Digite a senha: ");
        scanf("%s", users[userCount].password);

        // Criptografa a senha antes de armazena
        encryptPassword(users[userCount].password);

        userCount++;
        printf("Usu�rio adicionado com sucesso!\n");
    } else {
        printf("Limite de usu�rios atingido!\n");
    }
}

// Altera a senha do usu�rio
void changePassword() {
    char username[MAX_NAME_LEN];
    char newPassword[MAX_PASS_LEN];
    int found = 0;

    printf("Digite o nome de usu�rio: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Digite a nova senha: ");
            scanf("%s", newPassword);
            
            // Criptografa a nova senha e atualiza normal
            encryptPassword(newPassword);
            strcpy(users[i].password, newPassword);

            printf("Senha alterada com sucesso!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Usu�rio n�o encontrado!\n");
    }
}

// Excluir o usu�rio
void deleteUser() {
    char username[MAX_NAME_LEN];
    int found = 0;

    printf("Digite o nome de usu�rio a ser exclu�do: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            // Desloca os elementos para remover o usu�rio
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("Usu�rio exclu�do com sucesso!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Usu�rio n�o encontrado!\n");
    }
}

// todos os usu�rios
void listUsers() {
    if (userCount == 0) {
        printf("Nenhum usu�rio cadastrado!\n");
    } else {
        printf("Lista de usu�rios:\n");
        for (int i = 0; i < userCount; i++) {
            printf("Usu�rio: %s\n", users[i].username);
        }
    }
}

// menu
int main() {
    int option;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar novo usu�rio e senha\n");
        printf("2. Alterar senha\n");
        printf("3. Excluir usu�rio/senha\n");
        printf("4. Listar usu�rios\n");
        printf("5. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addUser();
                break;
            case 2:
                changePassword();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                listUsers();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

