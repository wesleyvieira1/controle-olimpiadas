#include <iostream>
#include "pais.h"

// Construtor
pais::pais(const std::string& nome_pais, const std::string& continente) : nome_pais(nome_pais), continente(continente) {
    std::cout << "Construtor de pais chamado" << std::endl;
}


// Destrutor
pais::~pais() {
    std::cout << "Destrutor de pais chamado" << std::endl;
}

// Métodos getters
std::string pais::getNome() {
    return nome_pais;
}

std::string pais::getContinente() {
    return continente;
}

// Métodos setters
void pais::setNome(const std::string& nome) {
    nome_pais = nome;
}

void pais::setContinente(const std::string& nome_continente) {
    continente = nome_continente;
}

// Método para exibir as informações do país
void pais::exibirPais() const{
    std::cout << "Nome do país: " << nome_pais << std::endl;
    std::cout << "Continente: " << continente << std::endl;
}