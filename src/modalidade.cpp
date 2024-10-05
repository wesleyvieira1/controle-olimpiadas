#include <iostream>
#include "modalidade.h" // Inclui o arquivo de cabeçalho da classe modalidade

// Construtor
modalidade::modalidade(const std::string& nome_modalidade, const std::string& tipo_modalidade) 
    : nome_modalidade(nome_modalidade), tipo_modalidade(tipo_modalidade) {
    std::cout << "Construtor de modalidade chamado" << std::endl;
    }

// Destrutor
modalidade::~modalidade() {
    std::cout << "Destrutor de modalidade chamado" << std::endl;
}

// Métodos getters
std::string modalidade::getNome(){
    return nome_modalidade;
}

std::string modalidade::getTipo(){
    return tipo_modalidade;
}

// Métodos setters
void modalidade::setNome(const std::string& nome) {
    nome_modalidade = nome;
}

void modalidade::setTipo(const std::string& tipo) {
    tipo_modalidade = tipo;
}

// Método para exibir as informações da modalidade
void modalidade::exibirModalidade() const {
    std::cout << "Nome da modalidade: " << nome_modalidade << std::endl;
    std::cout << "Tipo da modalidade: " << tipo_modalidade << std::endl;
}

