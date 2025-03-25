#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura da carta
struct cartaEstadoCidade {
    char estado[60];               
    char codigo_carta[5];          
    char nome_cidade[60];          
    long long int populacao;       
    float area_km2;                 
    float pib;                     
    int pontos_turisticos;
    float densidade; 
    float pib_per_capita;      

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
    scanf("%4s", carta->codigo_carta);
    getchar(); // Limpa o buffer antes de fgets()

    // Armazenar nome da cidade
    printf("Digite o nome da cidade: "); 
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin); // Usa fgets para aceitar espaços
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = 0; 

    // Armazenar população
    printf("Digite a quantidade da população: ");
    scanf("%lld", &carta->populacao);
    getchar();

    // Armazenar área em km²
    printf("Digite a área em km²: ");
    scanf("%f", &carta->area_km2);
    getchar();

    // Armazenar PIB
    printf("Digite o PIB (em bilhões, sem pontos, colocar todos os numeros.): ");
    scanf("%f", &carta->pib);
    getchar();

    // Armazenar pontos turísticos
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    getchar(); // Limpa o buffer

    // Calculo densidade
    carta->densidade = carta->populacao / carta->area_km2;// (população) dividida por (area_km²) 

    // Calculo Pib per Capita
    carta->pib_per_capita = carta->pib / carta->populacao;// (pib_per_capita) dividido por (população)


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
    printf("Densidade: %.2f hab/km²\n", carta.densidade);
    printf("Pib per Capita %.2f reais\n", carta.pib_per_capita);
    
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