# Folosește o imagine de bază cu suport pentru C++
FROM mcr.microsoft.com/dotnet/sdk:6.0

# Setează directorul de lucru
WORKDIR /app

# Copiază fișierele sursă în container
COPY . /app

# Instalăm un compilator C++
RUN apt-get update && apt-get install -y g++

# Compilăm aplicația C++
RUN g++ -o program main.cpp

# Comanda de rulare a aplicației
CMD ["./program"]
