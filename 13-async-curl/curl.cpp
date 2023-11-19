#include <iostream>
#include <curl/curl.h>
using namespace std;

size_t manejarRespuesta(char* datos, size_t tamanio, size_t nmemb, string* resultado) {
    size_t tamanioTotal = tamanio * nmemb;
    resultado->append(datos, tamanioTotal);
    return tamanioTotal;
}

int main() {
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Error al inicializar cURL." << endl;
        return 1;
    }

    const char* url = "https://jsonplaceholder.typicode.com/posts";
    string respuesta;
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, manejarRespuesta);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &respuesta);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Error en la solicitud cURL: " << curl_easy_strerror(res) << endl;
    } else {
        cout << "Respuesta: " << respuesta << endl;
    }

    curl_easy_cleanup(curl);
    return 0;
}
