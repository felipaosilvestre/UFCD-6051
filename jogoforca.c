#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 100
#define MAX_LETRAS 26  // Total de letras no alfabeto

// Lista de animais
const char* lista_animais[] = {
    "abelha", "alpaca", "andorinha", "anta", "arara", "avestruz", 
    "baleia", "barata", "beija-flor", "besouro", "bode", "borboleta", 
    "bufalo", "cabra", "cachorro", "camelo", "canario", "capivara", "caranguejo", 
    "cavalo", "cegonha", "chimpanze", "cobra", "coelho", "coruja", "corvo", "crocodilo", 
    "elefante", "esquilo", "falcao", "foca", "formiga", "gaivota", "galo", "gato", 
    "girafa", "golfinho", "gorila", "grilo", "hamster", "hipopotamo", "hiena", "iguana", 
    "jacare", "jaguar", "javali", "lagosta", "lagarto", "leao", "leopardo", "lhama", 
    "lontra", "macaco", "morcego", "ostra", "panda", "papagaio", "pato", "pavao", 
    "pinguim", "polvo", "pombo", "porco", "raposa", "rato", "rinoceronte", "sapo", 
    "serpente", "tartaruga", "tigre", "touro", "tubarao", "urso", "veado", "vaca", "zebra"
};
const int total_animais = sizeof(lista_animais) / sizeof(lista_animais[0]);

// Lista de filmes
const char* lista_filmes[] = {
    "branca de neve", "garfield", "transformers", "madagascar", 
    "jumanji", "click", "eu sou a lenda", "hotel transilvania", 
    "up altas aventuras", "a espera de um milagre", "creed", "kunf fu panda", "homem aranha", 
    "o grinch", "a bela e a fera", "robocop", 
    "divertidamente", "duro de matar", "senhor dos aneis", "homens de preto", 
    "liga da justiça", "wall e", "mulher maravilha", "os caca fantasmas", 
    "game of thrones", "jogos vorazes", "jogos mortais", 
    "minions", "john wick", "meu malvado favorito", 
    "shrek", "gladiador", "procurando dory", 
    "avatar", "o rei leao", "procurando nemo", "a familia addams", "dr estranho", 
    "invasao a casa branca", "cidade de Deus", "willy wonka", 
    "tropa de elite", "o lobo de wall street", "batman o cavaleiro das trevas", 
    "viuva negra", "mr bean", "detona ralph", 
    "cinderela", "malevola", "wolwerine", "jurassic park", 
    "deadpool", "a fuga de alcatraz", "capitao america", "godzilla", 
    "titanic", "matrix", "toy story", "o alien", "thor", 
    "clube da luta", "o hulk", "harry potter", 
    "king kong", "a ressaca", "um morto muito louco", "lanterna verde", 
    "superman", "star wars", "homem de ferro", "vingadores", 
    "corações de ferro", "uma noite no museu", "barbied", 
    "beetlejuice", "the equalizer", "o tubarao", "velozes e furiosos", 
    "monstros SA", "hobbit", "os incriveis", 
    "a pequena sereia", "frozen", "x men", 
    "piratas do caribe", "aladdin", "forrest gump o contador de historias", 
    "indiana jones", "de volta para o futuro", 
    "star wars uma nova esperanca", "a lista de schindler", "edward maos de tesoura", 
    "et o extraterrestre", "casablanca", 
    "pulp fiction", "ratatui", "tarzan", 
    "o magico de oz", "o poderoso chefao"
};
const int total_filmes = sizeof(lista_filmes) / sizeof(lista_filmes[0]);

// Lista de países
const char* lista_paises[] = {
    "afeganistao", "alemanha", "angola", "argelia", "argentina", "australia", 
    "austria", "belgica", "bolivia", "brasil", "canada", "chile", "china", 
    "colombia", "coreia do sul", "costa rica", "cuba", "dinamarca", "egito", 
    "espanha", "estados unidos", "etiopia", "filipinas", "finlandia", 
    "franca", "grecia", "guatemala", "haiti", "holanda", "india", "indonesia", 
    "inglaterra", "ira", "iraque", "islandia", "israel", "italia", "jamaica", 
    "japao", "kenia", "mexico", "moçambique", "nepal", "nigeria", "noruega", 
    "nova zelandia", "panama", "paraguai", "peru", "polonia", "portugal", 
    "quenia", "reino unido", "russia", "senegal", "suecia", "suica", 
    "tailandia", "turquia", "ucrania", "uruguai", "venezuela", "vietna", 
    "zimbabue"
};
const int total_paises = sizeof(lista_paises) / sizeof(lista_paises[0]);

// Função para desenhar a forca junto com o boneco
void desenharBoneco(int erros) {
    printf("  _______\n");
    printf("  |     |\n");

    switch (erros) {
        case 0:
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 1:
            printf("  |     O\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 2:
            printf("  |     O\n");
            printf("  |     |\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 3:
            printf("  |     O\n");
            printf("  |    /|\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 4:
            printf("  |     O\n");
            printf("  |    /|\\\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 5:
            printf("  |     O\n");
            printf("  |    /|\\\n");
            printf("  |    / \n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        case 6:
            printf("  |     O\n");
            printf("  |    /|\\\n");
            printf("  |    / \\\n");
            printf("  |\n");
            printf(" _|_\n\n");
            break;
        default:
            break;
    }
}

// Função para remover acentos e transformar a string para minúsculas
char* removerAcentos(char* palavra) {
    char* palavraSemAcento = malloc(strlen(palavra) + 1);
    char* p = palavraSemAcento;
    while (*palavra) {
        char c = *palavra;
        switch (c) {
            case 'á': case 'à': case 'ã': case 'â': c = 'a'; break;
            case 'é': case 'è': case 'ê': c = 'e'; break;
            case 'í': case 'ì': case 'î': c = 'i'; break;
            case 'ó': case 'ò': case 'õ': case 'ô': c = 'o'; break;
            case 'ú': case 'ù': case 'û': c = 'u'; break;
            case 'ç': c = 'c'; break;
            case 'Á': case 'À': case 'Ã': case 'Â': c = 'A'; break;
            case 'É': case 'È': case 'Ê': c = 'E'; break;
            case 'Í': case 'Ì': case 'Î': c = 'I'; break;
            case 'Ó': case 'Ò': case 'Õ': case 'Ô': c = 'O'; break;
            case 'Ú': case 'Ù': case 'Û': c = 'U'; break;
            case 'Ç': c = 'C'; break;
            default: c = tolower(c); break;
        }
        *p++ = c;
        palavra++;
    }
    *p = '\0';
    return palavraSemAcento;
}

// Função para verificar se o jogo terminou
int verificarFimDeJogo(const char* palavraSecreta, const char* letrasCorretas, int erros) {
    if (erros >= MAX_TENTATIVAS) {
        printf("Você foi enforcado! A palavra era: %s\n", palavraSecreta);
        return 1;
    }

    if (strcmp(palavraSecreta, letrasCorretas) == 0) {
        printf("Parabéns! Você adivinhou a palavra: %s\n", palavraSecreta);
        return 1;
    }

    return 0;
}

// Função para escolher uma palavra aleatória de uma lista
const char* escolherPalavraAleatoria(const char* lista[], int tamanhoLista) {
    srand(time(NULL));
    int indiceAleatorio = rand() % tamanhoLista;
    return lista[indiceAleatorio];
}

// Função para executar o jogo da forca
void jogarForca() {
    int categoria;
    printf("Bem-vindo ao jogo da forca!\n");
    printf("Escolha uma categoria:\n");
    printf("1. Animais\n");
    printf("2. Filmes\n");
    printf("3. Países\n");
    printf("Digite o número da categoria desejada: ");
    scanf("%d", &categoria);
    getchar();  // Consumir o caractere de nova linha deixado pelo scanf

    const char* palavraSecreta;

    switch (categoria) {
        case 1:
            palavraSecreta = escolherPalavraAleatoria(lista_animais, total_animais);
            break;
        case 2:
            palavraSecreta = escolherPalavraAleatoria(lista_filmes, total_filmes);
            break;
        case 3:
            palavraSecreta = escolherPalavraAleatoria(lista_paises, total_paises);
            break;
        default:
            printf("Categoria inválida. Saindo do jogo.\n");
            return;
    }

    // Remover acentos da palavra secreta
    char* palavraSecretaSemAcentos = removerAcentos((char*)palavraSecreta);

    int tamanhoPalavra = strlen(palavraSecretaSemAcentos);
    char letrasCorretas[tamanhoPalavra + 1];
    for (int i = 0; i < tamanhoPalavra; i++) {
        letrasCorretas[i] = (palavraSecretaSemAcentos[i] == ' ') ? ' ' : '_';
    }
    letrasCorretas[tamanhoPalavra] = '\0';

    int letrasTentadas[MAX_LETRAS] = {0};
    int erros = 0;
    char letra;

    while (!verificarFimDeJogo(palavraSecretaSemAcentos, letrasCorretas, erros)) {
        desenharBoneco(erros);

        printf("Palavra: %s\n", letrasCorretas);
        printf("Digite uma letra: ");
        letra = getchar();
        getchar();  // Consumir o caractere de nova linha deixado pelo getchar

        letra = tolower(letra);

        if (!isalpha(letra)) {
            printf("Por favor, digite uma letra válida.\n");
            continue;
        }

        if (letrasTentadas[letra - 'a']) {
            printf("Você já tentou essa letra. Tente outra.\n");
            continue;
        }

        letrasTentadas[letra - 'a'] = 1;

        int acertou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavraSecretaSemAcentos[i] == letra) {
                letrasCorretas[i] = letra;
                acertou = 1;
            }
        }

        if (!acertou) {
            erros++;
            printf("Letra incorreta! Você tem %d tentativas restantes.\n", MAX_TENTATIVAS - erros);
        }
    }

    free(palavraSecretaSemAcentos);
}

// Função para perguntar ao jogador se ele deseja jogar novamente
int desejaJogarNovamente() {
    char resposta;
    printf("Deseja jogar novamente? (s/n): ");
    scanf(" %c", &resposta);  // Adiciona um espaço antes do %c para consumir o caractere de nova linha anterior
    getchar();  // Consumir o caractere de nova linha deixado pelo scanf

    return tolower(resposta) == 's';
}

int main() {
    do {
        jogarForca();
    } while (desejaJogarNovamente());

    printf("Obrigado por jogar! Até a próxima.\n");
    return 0;
}
