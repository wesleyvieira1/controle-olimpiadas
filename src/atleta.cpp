#include "atleta.h"

// Construtor
atleta::atleta(const std::string& nome_atleta, pais* pais_origem, const std::vector<std::shared_ptr<modalidade>>& modalidades_vector) 
        : nome_atleta(nome_atleta), pais_origem(pais_origem) {
        
        // Inicializa o array de modalidades
        std::size_t i = 0;
        for (; i < modalidades_vector.size() && i < TAM_MODALIDADES; ++i) {
            modalidades[i] = modalidades_vector[i];
        }

        // Se o vetor for menor que o tamanho da matriz, preenche o restante com nullptr
        for (; i < TAM_MODALIDADES; ++i) {
            modalidades[i] = nullptr;
        }
    }

// Destrutor
atleta::~atleta() {
    // Não é necessário liberar memória para std::shared_ptr, pois libera automaticamente
}

// Métodos getters
std::string atleta::getNome() const {
    return nome_atleta;
}

pais* atleta::getPais() const {
    return pais_origem; // Retorna um ponteiro para o objeto pais
}

std::shared_ptr<modalidade> atleta::getModalidade(int posicao) const {
    if (posicao >= 0 && posicao < TAM_MODALIDADES) {
        return modalidades[posicao];
    }
    return nullptr; // Retorna null se a posição for inválida
}

// Métodos setters
void atleta::setNome(const std::string& nome_atletas) {
    nome_atleta = nome_atletas;
}

void atleta::setPais(pais* pais_origems) {
    pais_origem = pais_origems;
}

void atleta::setModalidade(const std::shared_ptr<modalidade>& modalidade, int posicao) {
    if (posicao >= 0 && posicao < TAM_MODALIDADES) {
        modalidades[posicao] = modalidade;
    }
}

// Método para exibir as informações do atleta
void atleta::exibirAtleta() const {
    std::cout << "Nome: " << nome_atleta << std::endl;
    std::cout << "Pais de Origem: " << pais_origem->getNome() << std::endl; 
    
    std::cout << "Modalidades: " << std::endl;
    for (int i = 0; i < TAM_MODALIDADES; ++i) {
        if (modalidades[i] != nullptr) {
            std::cout << "Modalidade " << i + 1 << ": " << modalidades[i]->getNome() << std::endl;
        }
    }
}
