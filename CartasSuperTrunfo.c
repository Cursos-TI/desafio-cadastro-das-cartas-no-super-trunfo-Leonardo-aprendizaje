#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura da carta
struct cartaEstadoCidade {
    char estado[60];               
    char codigo_carta[4];          
    char nome_cidade[60];          
    long long int populacao;       
    float area_km2;                 
    float pib;                     
    int pontos_turisticos;         
};

// Função para coletar os dados da carta
void coletarDados(struct cartaEstadoCidade *carta, int numero) { // Usa ponteiro para modificar a estrutura
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    
    // Armazenar Estado
    printf("Digite o Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin); // Usa fgets para aceitar espaços
    carta->estado[strcspn(carta->estado, "\n")] = 0;  

    // Armazenar código da carta
    printf("Digite o código da carta: ");
    scanf("%3s", carta->codigo_carta);
    getchar(); // Limpa o buffer antes de fgets()

    // Armazenar nome da cidade
    printf("Digite o nome da cidade: "); 
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin); // Usa fgets para aceitar espaços
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = 0;  

    // Armazenar população
    printf("Digite a quantidade da população: ");
    scanf("%lld", &carta->populacao);

    // Armazenar área em km²
    printf("Digite a área em km²: ");
    scanf("%f", &carta->area_km2);

    // Armazenar PIB
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    // Armazenar pontos turísticos
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar(); // Limpa o buffer
}

// Função para exibir os dados da carta
void exibirDados(struct cartaEstadoCidade carta, int numero) {
    printf("\n=== Dados da Carta %d ===\n", numero); // Exibir os dados da carta na tela
    printf("Estado: %s\n", carta.estado);
    printf("Código da carta: %s\n", carta.codigo_carta);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %lld habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area_km2);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    setlocale(LC_CTYPE, "pt_BR.UTF-8"); // Melhor compatibilidade com acentos

    struct cartaEstadoCidade carta1, carta2; // Criando as duas cartas

    // Coletar dados das duas cartas
    coletarDados(&carta1, 1);
    coletarDados(&carta2, 2);

    // Exibir dados das duas cartas
    exibirDados(carta1, 1);
    exibirDados(carta2, 2);

    return 0;
}
