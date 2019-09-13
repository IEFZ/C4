#include "Matriz.h"

Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            // Inicializamos con valores que no sean cuadrados mágicos
            this->matriz[i][j] = (i*j);
        }
    }
}

Matriz::Matriz(const std::string& orig) {
    llenar(orig);
}

Matriz::Matriz(const Matriz& orig) {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
}

Matriz::~Matriz() {
}

void Matriz::llenar(const std::string& orig) {
    try {
        Matriz();
        std::string linea(orig.c_str());
        if (!linea.empty()) {
            // Quitamos caracters innecesarios
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());

            // Obtenemos un token
            std::replace(linea.begin(), linea.end(), ';', ' ');


            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }
	    reverse(arreglo.begin(),arreglo.end());
            for (int i = 0; i < LARGO; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
		
                }
		reverse(columnas.begin(),columnas.end());
		
                for (int j = 0; j < LARGO; j++) {
                    	std::string valor = columnas[j];
			int numero= atoi(valor.c_str());
                    this->matriz[i][j] = numero;
                }
            }
        }
    } catch (...) {
        Matriz();
    }
}



std::string Matriz::toString() {
    std::stringstream ss;
    ss << '[' << this->matriz[0][0] << ',' << this->matriz[0][1] << ',' << this->matriz[0][2] << ';' << this->matriz[1][0] << ',' << this->matriz[1][1] << ',' << this->matriz[1][2] << ';' << this->matriz[2][0] << ',' << this->matriz[2][1] << ',' << this->matriz[2][2] << ']' << std::endl;
    return ss.str();
}
