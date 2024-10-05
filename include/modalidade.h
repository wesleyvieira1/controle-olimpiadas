#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <string> // Inclui a biblioteca string

class modalidade {
    private:
        std::string nome_modalidade; // Nome da modalidade
        std::string tipo_modalidade; // Tipo da modalidade (individual ou coletiva)

    public:
        // Construtor
        modalidade(const std::string& nome_modalidade, const std::string& tipo_modalidade);

        // Destrutor
        ~modalidade();

        // Métodos getters
        std::string getNome(); // Retorna o nome da modalidade
        std::string getTipo();// Retorna o tipo da modalidade

        // Métodos setters
        void setNome(const std::string& nome); // Define o nome da modalidade
        void setTipo(const std::string& tipo); // Define o tipo da modalidade

        // Método para exibir as informações da modalidade
        void exibirModalidade() const; // Exibe as informações da modalidade
};

#endif