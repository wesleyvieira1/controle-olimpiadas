# Projeto Controle Olímpico

Este projeto é um programa C++ para gerenciar um sistema de cadastro e exibição de informações sobre países, modalidades, atletas e medalhas nas Olimpíadas.

## Estrutura do Projeto

- `src/`: Contém os arquivos fonte `.cpp`.
- `include/`: Contém os arquivos de cabeçalho `.h`.
- `obj/`: Diretório onde os arquivos objeto são gerados (gerado automaticamente pelo Makefile).

```markdown
# Instruções para Compilar e Executar o Projeto

Este projeto utiliza um `Makefile` para gerenciar a compilação, limpeza, instalação e desinstalação do programa. Abaixo estão as instruções para uso tanto em sistemas Unix/Linux quanto em Windows.

## Como Usar o Makefile em Unix/Linux

### Compilar o Projeto

Para compilar o projeto e gerar o executável, execute o seguinte comando no terminal:

```bash
make
```

### Limpar Arquivos Compilados

Para remover os arquivos objeto e o executável gerados, use:

```bash
make clean
```

### Instalar o Programa

Para instalar o executável no diretório padrão `/usr/local/bin`, use:

```bash
make install
```

### Desinstalar o Programa

Para desinstalar o programa, removendo o executável do diretório `/usr/local/bin`, execute:

```bash
make uninstall
```

### Verificar o Status

Para verificar se há alterações nos arquivos e ver o que seria feito sem executar realmente as ações, use:

```bash
make -n
```

### Recompilar o Projeto

Se você fez alterações no `Makefile` ou nos arquivos fonte e deseja recompilar, execute:

```bash
make clean
make
```

### Executar o Programa

Depois de compilar o projeto, execute o programa com:

```bash
./programa
```

## Como Usar o Makefile no Windows com MinGW

### Compilar o Projeto

Para compilar o projeto e gerar o executável, execute o seguinte comando no terminal:

```bash
mingw32-make
```

### Limpar Arquivos Compilados

Para remover os arquivos objeto e o executável gerados, use:

```bash
mingw32-make clean
```

### Instalar o Programa

Para instalar o executável no diretório padrão `/usr/local/bin`, use:

```bash
mingw32-make install
```

### Desinstalar o Programa

Para desinstalar o programa, removendo o executável do diretório `/usr/local/bin`, execute:

```bash
mingw32-make uninstall
```

### Verificar o Status

Para verificar se há alterações nos arquivos e ver o que seria feito sem executar realmente as ações, use:

```bash
mingw32-make -n
```

### Recompilar o Projeto

Se você fez alterações no `Makefile` ou nos arquivos fonte e deseja recompilar, execute:

```bash
mingw32-make clean
mingw32-make
```

### Executar o Programa

Depois de compilar o projeto, execute o programa com:

```bash
./programa
```

### Observações

- Certifique-se de estar no diretório onde o `Makefile` está localizado ou forneça o caminho correto para o `Makefile` ao executar os comandos.
- Em sistemas Windows, você precisará ter o `MinGW` corretamente configurado no seu PATH para usar o `mingw32-make`.

```
