#ifndef ATLETA_H 
#define ATLETA_H 

#include <string> // Inclui a biblioteca string
#include <vector> // Inclui a biblioteca vector
#include "pais.h" // Inclui o arquivo de cabeçalho da classe pais
#include "modalidade.h" // Inclui o arquivo de cabeçalho da classe modalidade
#include <memory> // Inclui a biblioteca memory
#include <iostream> // Inclui a biblioteca iostream para std::cout

#define TAM_MODALIDADES 12 // Define o tamanho do vetor de modalidades

class atleta {
    private:
        std::string nome_atleta; // Nome do atleta
        pais* pais_origem; // Passagem por referência
        std::shared_ptr<modalidade> modalidades[TAM_MODALIDADES]; // Vetor de modalidades (agregação)
        
    public:
        // Construtor
        atleta(const std::string& nome_atleta, pais* pais_origem, const std::vector<std::shared_ptr<modalidade>>& modalidades);
        
        // Destrutor
        ~atleta();

        // Métodos getters
        std::string getNome() const; // Retorna o nome do atleta
        pais* getPais() const; // Retorna o país de origem do atleta
        std::shared_ptr<modalidade> getModalidade(int posicao) const; // Retorna a modalidade na posição especificada

        // Métodos setters
        void setNome(const std::string& nome_atleta); // Define o nome do atleta
        void setPais(pais* pais_origem); // Define o país de origem do atleta
        void setModalidade(const std::shared_ptr<modalidade>& modalidade, int posicao); // Define a modalidade na posição especificada 

        void exibirAtleta() const; // Exibe as informações do atleta
};

#endif
