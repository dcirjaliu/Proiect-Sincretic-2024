# Folosește o imagine de bază cu suport pentru C++
FROM ubuntu:latest

# Setează directorul de lucru
WORKDIR /app

# Actualizează pachetele și instalează dependențele necesare
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    build-essential \
    g++

# Copiază fișierele sursă în container
COPY . /app

# Compilăm aplicația C++
RUN g++ -o program main.cpp

# Comanda de rulare a aplicației
CMD ["./program"]
