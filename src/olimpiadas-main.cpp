#include <iostream>
#include <vector>
#include <memory>
#include "pais.h"
#include "modalidade.h"
#include "atleta.h"
#include "medalha.h"

// Função para cadastrar um país
void cadastrarPais(std::vector<pais*>& paises) {
    std::string nome_pais, continente;
    std::cout << "Nome do Pais: ";
    std::getline(std::cin, nome_pais);
    std::cout << "Continente: ";
    std::getline(std::cin, continente);

    pais* novo_pais = new pais(nome_pais, continente);
    paises.push_back(novo_pais);

    std::cout << "Pais cadastrado com sucesso!" << std::endl;
}

// Função para exibir os países cadastrados
void exibirPaises(const std::vector<pais*>& paises) {
    // Verifica se o vetor está vazio
    if (paises.empty()) {
        std::cout << "Nenhum pais cadastrado." << std::endl;
        return;
    }

    // Exibe os países cadastrados
    std::cout << "Paises cadastrados:\n";
    // Itera sobre o vetor de países
    for (std::vector<pais*>::size_type i = 0; i < paises.size(); ++i) {
        std::cout << i << ". " << paises[i]->getNome() << " - " << paises[i]->getContinente() << std::endl;
    }
}

// Função para cadastrar uma modalidade
void cadastrarModalidade(std::vector<std::shared_ptr<modalidade>>& modalidades) {
    std::string nome_modalidade, tipo_modalidade;
    std::cout << "Nome da Modalidade: ";
    std::getline(std::cin, nome_modalidade);
    std::cout << "Tipo da Modalidade (individual/coletiva): ";
    std::getline(std::cin, tipo_modalidade);

    // Cria um novo objeto modalidade e adiciona ao vetor
    auto nova_modalidade = std::make_shared<modalidade>(nome_modalidade, tipo_modalidade);
    modalidades.push_back(nova_modalidade);// Adiciona a modalidade ao vetor

    std::cout << "Modalidade cadastrada com sucesso!" << std::endl;// Mensagem de sucesso
}

// Função para exibir as modalidades cadastradas
void exibirModalidades(const std::vector<std::shared_ptr<modalidade>>& modalidades) {
    // Verifica se o vetor está vazio
    if (modalidades.empty()) {
        std::cout << "Nenhuma modalidade cadastrada." << std::endl;
        return;
    }
    // Exibe as modalidades cadastradas
    std::cout << "Modalidades cadastradas:\n";
    // Itera sobre o vetor de modalidades
    for (std::vector<std::shared_ptr<modalidade>>::size_type i = 0; i < modalidades.size(); ++i) {
        std::cout << i << ". " << modalidades[i]->getNome() << " - " << modalidades[i]->getTipo() << std::endl;
    }
}

// Função para cadastrar um atleta
void cadastrarAtleta(std::vector<atleta*>& atletas, const std::vector<pais*>& paises, const std::vector<std::shared_ptr<modalidade>>& modalidades) {
    std::string nome_atleta;
    std::vector<pais*>::size_type id_pais;
    std::vector<std::shared_ptr<modalidade>> modalidades_atleta;

    std::cout << "Nome do Atleta: ";
    std::getline(std::cin, nome_atleta);
    // Verifica se o nome do atleta é vazio
    if (nome_atleta.empty()) {
        std::cout << "Nome do atleta nao pode ser vazio." << std::endl;
        return;
    }
    // Verifica se o vetor de países está vazio
    if (paises.empty()) {
        std::cout << "Nenhum pais cadastrado. Cadastre um pais primeiro." << std::endl;
        return;
    }
    // Verifica se o vetor de modalidades está vazio
    if (modalidades.empty()) {
        std::cout << "Nenhuma modalidade cadastrada. Cadastre uma modalidade primeiro." << std::endl;
        return;
    }
    // Seleção de país
    exibirPaises(paises);
    // Exibe a mensagem para escolher o ID do país
    std::cout << "Escolha o ID do pais de origem (0 a " << paises.size() - 1 << "): ";
    std::cin >> id_pais;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro

    // Verifica se o ID do país é válido
    if (id_pais < paises.size()) {
        // Seleção de modalidades
        char adicionar_mais = 'n';// Variável para adicionar mais modalidades
        // Loop para adicionar modalidades
        do {
            exibirModalidades(modalidades);
            std::vector<std::shared_ptr<modalidade>>::size_type id_modalidade;
            std::cout << "Escolha o ID da modalidade (0 a " << modalidades.size() - 1 << "): ";
            std::cin >> id_modalidade;
            std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro
            // Verifica se o ID da modalidade é válido
            if (id_modalidade < modalidades.size()) {
                modalidades_atleta.push_back(modalidades[id_modalidade]);
            } else {
                std::cout << "ID de modalidade invalido!" << std::endl;
            }
            // Pergunta se deseja adicionar mais modalidades
            std::cout << "Deseja adicionar mais uma modalidade para este atleta? (s/n): ";
            std::cin >> adicionar_mais;
            std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura
        } while (adicionar_mais == 's' && !modalidades_atleta.empty());

        // Verifica se o vetor de modalidades do atleta não está vazio
        if (modalidades_atleta.empty()) {
            std::cout << "Nenhuma modalidade foi selecionada. Atleta nao cadastrado." << std::endl;
        } else {
            atleta* novo_atleta = new atleta(nome_atleta, paises[id_pais], modalidades_atleta);
            atletas.push_back(novo_atleta);

            std::cout << "Atleta cadastrado com sucesso!" << std::endl;
        }
    } else {
        std::cout << "ID de pais inválido!" << std::endl;
    }
}


// Função para exibir os atletas cadastrados
void exibirAtletas(const std::vector<atleta*>& atletas) {
    if (atletas.empty()) {
        std::cout << "Nenhum atleta cadastrado." << std::endl;
        return;
    }
    // Exibe os atletas cadastrados
    std::cout << "Atletas cadastrados:\n";
    // Itera sobre o vetor de atletas
    for (std::vector<atleta*>::size_type i = 0; i < atletas.size(); ++i) {
        std::cout << i << ". " << atletas[i]->getNome() << " - Pais: " << atletas[i]->getPais()->getNome() << std::endl;
    }
}

// Função para cadastrar uma medalha
void cadastrarMedalha(std::vector<medalha*>& medalhas, const std::vector<atleta*>& atletas, const std::vector<std::shared_ptr<modalidade>>& modalidades) {
    std::string tipo_medalha;
    int ano;
    std::vector<atleta*>::size_type id_atleta;
    std::vector<std::shared_ptr<modalidade>>::size_type id_modalidade;
    std::cout << "Tipo da Medalha (ouro/prata/bronze): ";
    std::getline(std::cin, tipo_medalha);
    std::cout << "Ano da Conquista: ";
    std::cin >> ano;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro

    // Verifica se os vetores de atletas
    if (atletas.empty()) {
        std::cout << "Nenhum atleta cadastrado. Cadastre um atleta primeiro." << std::endl;
        return;
    }
    // Verifica se o vetor de modalidades está vazio
    if (modalidades.empty()) {
        std::cout << "Nenhuma modalidade cadastrada. Cadastre uma modalidade primeiro." << std::endl;
        return;
    }

    exibirAtletas(atletas);
    std::cout << "Escolha o ID do atleta (0 a " << atletas.size() - 1 << "): ";
    std::cin >> id_atleta;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro

    exibirModalidades(modalidades);
    std::cout << "Escolha o ID da modalidade (0 a " << modalidades.size() - 1 << "): ";
    std::cin >> id_modalidade;
    std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro


    // Verifica se o ID do atleta e da modalidade são válidos
    if (id_atleta < atletas.size() && id_modalidade < modalidades.size()) {
        medalha* nova_medalha = new medalha(tipo_medalha, ano, atletas[id_atleta], modalidades[id_modalidade]);
        medalhas.push_back(nova_medalha);

        std::cout << "Medalha cadastrada com sucesso!" << std::endl;
    } else {
        std::cout << "ID de atleta ou modalidade invalido!" << std::endl;
    }
}

// Função para exibir as medalhas cadastradas
void exibirMedalhas(const std::vector<medalha*>& medalhas) {
    if (medalhas.empty()) {
        std::cout << "Nenhuma medalha cadastrada." << std::endl;
        return;
    }

    // Exibe as medalhas cadastradas
    std::cout << "Medalhas cadastradas:\n";
    for (const auto& med : medalhas) {
        med->exibirMedalha();
        std::cout << std::endl;
    }
}

// Função para exibir todos os dados cadastrados
void exibirTodos(const std::vector<pais*>& paises, const std::vector<std::shared_ptr<modalidade>>& modalidades, const std::vector<atleta*>& atletas, const std::vector<medalha*>& medalhas) {
    std::cout << "\nTodos os dados cadastrados:\n";
    exibirPaises(paises);
    exibirModalidades(modalidades);
    exibirAtletas(atletas);
    exibirMedalhas(medalhas);
}

// Função principal
int main() {
    // Vetores para armazenar os objetos
    std::vector<pais*> paises;
    std::vector<std::shared_ptr<modalidade>> modalidades;
    std::vector<atleta*> atletas;
    std::vector<medalha*> medalhas;

    int opcao = 0;

    // Menu principal
    while (opcao != 10) {
        std::cout << "\nMenu:\n";
        std::cout << "[1] Cadastrar Pais\n";
        std::cout << "[2] Cadastrar Modalidade\n";
        std::cout << "[3] Cadastrar Atleta\n";
        std::cout << "[4] Cadastrar Medalha\n";
        std::cout << "[5] Exibir Paises\n";
        std::cout << "[6] Exibir Modalidades\n";
        std::cout << "[7] Exibir Atletas\n";
        std::cout << "[8] Exibir Medalhas\n";
        std::cout << "[9] Exibir Todos\n";
        std::cout << "[10] Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(); // Ignorar o caractere de nova linha após a leitura de inteiro

        // Executa a opção escolhida
        switch (opcao) {
            case 1:
                cadastrarPais(paises);
                break;
            case 2:
                cadastrarModalidade(modalidades);
                break;
            case 3:
                cadastrarAtleta(atletas, paises, modalidades);
                break;
            case 4:
                cadastrarMedalha(medalhas, atletas, modalidades);
                break;
            case 5:
                exibirPaises(paises);
                break;
            case 6:
                exibirModalidades(modalidades);
                break;
            case 7:
                exibirAtletas(atletas);
                break;
            case 8:
                exibirMedalhas(medalhas);
                break;
            case 9:
                exibirTodos(paises, modalidades, atletas, medalhas);
                break;
            case 10:
                std::cout << "Saindo do Programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida!" << std::endl;
        }
    }

    // Limpeza da memoria alocada
    for (auto& p : paises) delete p;
    for (auto& a : atletas) delete a;
    for (auto& m : medalhas) delete m;

    return 0;
}
