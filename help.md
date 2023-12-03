# db.cpp

Este arquivo C++ é responsável por estabelecer uma conexão com o banco de dados PostgreSQL. Ele utiliza a biblioteca `pqxx`, que é uma biblioteca de acesso a banco de dados C++ específica para o PostgreSQL. Essa biblioteca proporciona uma interface C++ para interagir com bancos de dados PostgreSQL, utilizando o protocolo do próprio PostgreSQL. Após a execução do código, a conexão com o banco de dados é estabelecida.

## Pausa Temporizada

O trecho de código abaixo introduz uma pausa de 1 segundo no fluxo da execução:

```cpp
std::this_thread::sleep_for(std::chrono::seconds(1));
```
Essa linha utiliza a biblioteca <thread> e <chrono> do C++ para fazer a thread atual aguardar por 1 segundo antes de continuar a execução. Esse tipo de pausa é frequentemente utilizado para controlar a taxa de execução de determinadas partes do código.

## Conexão com o Banco de Dados
O código a seguir é responsável pela criação da conexão com o banco de dados PostgreSQL:

```cpp
connection C("dbname=crow user=root password=root hostaddr=127.0.0.1 port=5432");
```
- dbname: Nome do banco de dados ao qual se deseja conectar.
- user: Nome do usuário que será utilizado na conexão.
- password: Senha associada ao usuário para autenticação no banco de dados.
- hostaddr: Endereço IP ou hostname da máquina onde o banco de dados está hospedado.
- port: Número da porta utilizada para a conexão (o valor padrão para o PostgreSQL é 5432).

## Compilação e Execução
Para compilar e executar o arquivo db.cpp, utilize o seguinte comando:

```bash
g++ db.cpp -o db -lpqxx -lpq -std=c++11
```
Certifique-se de substituir os parâmetros de conexão do banco de dados pelos valores corretos para o seu ambiente. Este comando compila o código, criando um executável chamado db, e vincula as bibliotecas necessárias para a utilização da pqxx e do PostgreSQL.

# api.cpp

Este arquivo C++ implementa um servidor HTTP simples usando a biblioteca C++ Rest SDK (`cpprest`). Ele cria uma API que responde a solicitações GET com um JSON simples. Abaixo, você encontrará uma breve explicação do código.

## Inclusão de Bibliotecas

O código utiliza duas bibliotecas principais da C++ Rest SDK:

```cpp
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
```

Essas bibliotecas fornecem funcionalidades para criar um servidor HTTP e manipular objetos JSON.

## Definição da Classe MyListener

- #### A classe MyListener é responsável por configurar e gerenciar o servidor HTTP. Aqui estão os pontos principais:

- #### Construtor: Configura o listener para escutar o URL fornecido e define o suporte para solicitações GET.

- #### Métodos open e close: São responsáveis por abrir e fechar o servidor.

- #### Método handle_get: Manipula solicitações GET, exibe uma mensagem no console e responde com um JSON simples.


## Função main
A função main cria uma instância da classe MyListener e a inicia. O servidor HTTP será executado em http://localhost:8080. A aplicação continuará executando até que o usuário pressione Enter, momento em que o servidor será fechado.


## Compilação e Execução
Para compilar e executar o arquivo api.cpp, utilize o seguinte comando:

```bash
g++ api.cpp -o api -lcpprest -lboost_system -lboost_thread -pthread
```
Este comando compila o código, criando um executável chamado api, e vincula as bibliotecas necessárias para a utilização da C++ Rest SDK.