#ifndef MEDALHA_H
#define MEDALHA_H

#include <memory> // Inclui a biblioteca memory
#include <string> // Inclui a biblioteca string
#include "modalidade.h" // Inclui o arquivo de cabeçalho da classe modalidade
#include "atleta.h"    // Inclui o arquivo de cabeçalho da classe atleta

class medalha{
    private:
        std::string tipo_medalha; // Tipo da medalha (ouro, prata ou bronze)
        int ano; // Ano em que a medalha foi conquistada
        atleta* dados_atleta; // Ponteiro para o objeto da classe atleta (referência)
        std::shared_ptr<modalidade> dados_modalidade; // Ponteiro para o objeto da classe modalidade

    public:
        // Construtor
        medalha(const std::string& tipo_medalha, int ano, atleta* dados_atleta, std::shared_ptr<modalidade> dados_modalidade);

        // Destrutor
        ~medalha();

        // Métodos getters
        std::string getTipo(); // Retorna o tipo da medalha
        int getAno(); // Retorna o ano da conquista
        atleta* getAtleta(); // Retorna o atleta
        std::shared_ptr<modalidade> getModalidade(); // Retorna a modalidade

        // Métodos setters
        void setTipo(const std::string& tipo); // Define o tipo da medalha
        void setAno(int ano); // Define o ano da conquista
        void setAtleta(atleta* dados_atleta); // Define o atleta
        void setModalidade(std::shared_ptr<modalidade> dados_modalidade); // Define a modalidade

        // Método para exibir as informações da medalha
        void exibirMedalha() const;
};

#endif
