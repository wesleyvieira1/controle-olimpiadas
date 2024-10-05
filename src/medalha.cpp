#include "medalha.h"
#include <iostream>

// Construtor
medalha::medalha(const std::string& tipo, int ano, atleta* atleta, std::shared_ptr<modalidade> modalidade)
    : tipo_medalha(tipo), ano(ano), dados_atleta(atleta), dados_modalidade(modalidade) {
    std::cout << "Construtor de medalha chamado" << std::endl;
}

// Destrutor
medalha::~medalha() {
    std::cout << "Destrutor de medalha chamado" << std::endl;
}

// Métodos getters
std::string medalha::getTipo()  {
    return tipo_medalha;
}

int medalha::getAno() {
    return ano;
}

atleta* medalha::getAtleta(){
    return dados_atleta;
}

std::shared_ptr<modalidade> medalha::getModalidade() {
    return dados_modalidade;
}

// Métodos setters
void medalha::setTipo(const std::string& tipo) {
    tipo_medalha = tipo;
}

void medalha::setAno(int ano_novo) {
    ano = ano_novo;
}

void medalha::setAtleta(atleta* dados_atleta_novo) {
    dados_atleta = dados_atleta_novo;
}

void medalha::setModalidade(std::shared_ptr<modalidade> dados_modalidade_novo) {
    dados_modalidade = dados_modalidade_novo;
}

// Método para exibir as informações da medalha
void medalha::exibirMedalha() const {
    std::cout << "Tipo da medalha: " << tipo_medalha << std::endl;
    std::cout << "Ano da conquista: " << ano << std::endl;
    if (dados_atleta) {
        std::cout << "Informacoes do Atleta:" << std::endl;
        dados_atleta->exibirAtleta(); 
    }
    if (dados_modalidade) {
        std::cout << "Informacoes da Modalidade:" << std::endl;
        dados_modalidade->exibirModalidade(); 
    }
}
