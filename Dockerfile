# Imagine de bază Ubuntu (pentru a avea g++ și alte tool-uri)
FROM ubuntu:22.04

# Actualizează și instalează g++ și make
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make

# Setează directorul de lucru
WORKDIR /app

# Copiază fișierele sursă din proiect în container
COPY . .

# Compilează aplicația C++ (presupunând că fișierul principal este main.cpp)
RUN g++ -o my_app main.cpp

# Comanda pentru a rula aplicația
CMD ["./my_app"]
