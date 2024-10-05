#ifndef PAIS_H
#define PAIS_H

#include <string> // Inclui a biblioteca string

class pais{
    private:
        std::string nome_pais; // Nome do país
        std::string continente; // Continente onde o país está localizado

    public:
        // Construtor
        pais(const std::string& nome_pais, const std::string& continente); // Construtor
        
        // Destrutor
        ~pais();
        
        // Métodos getters
        std::string getNome(); // Retorna o nome do país
        std::string getContinente(); // Retorna o continente onde o país está localizado

        // Métodos setters
        void setNome(const std::string& nome_pais); // Define o nome do país
        void setContinente(const std::string& continente); // Define o continente onde o país está localizado

        void exibirPais() const;
};

#endif