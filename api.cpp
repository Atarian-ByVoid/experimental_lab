#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class MyListener {
public:
    MyListener(const utility::string_t& url) : listener_(url) {
        listener_.support(methods::GET, std::bind(&MyListener::handle_get, this, std::placeholders::_1));
    }
    pplx::task<void> open() { return listener_.open(); }
    pplx::task<void> close() { return listener_.close(); }

private:
    void handle_get(http_request message)
    {
        ucout << "Received GET request" << std::endl;

        // Responder com um JSON simples
        json::value response;
        response[U("message")] = json::value::string(U("Hello, C++!"));

        message.reply(status_codes::OK, response);
    }

    http_listener listener_;
};
int main() {
    MyListener listener(U("http://localhost:8080"));

    try {
        listener.open().wait();
        ucout << U("API está executando. Pressione Enter para encerrar.") << std::endl;
        std::string line;
        std::getline(std::cin, line);
        listener.close().wait();
    } catch (const std::exception& e) {
        ucout << U("Erro: ") << e.what() << std::endl;
    }

    return 0;
}