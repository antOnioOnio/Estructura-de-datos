INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++ 
CPPFLAGS = #-Wall -g


all: $(BIN)/prueba

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/prueba : $(OBJ)/union_cronologia.o $(OBJ)/eventoHistorico.o $(OBJ)/cronologia.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/union_cronologia.o $(OBJ)/eventoHistorico.o $(OBJ)/cronologia.o

$(OBJ)/union_cronologia.o : $(INC)/cronologia.h $(INC)/eventoHistorico.h $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/union_cronologia.o $(SRC)/union_cronologia.cpp

$(OBJ)/cronologia.o : $(INC)/cronologia.h $(INC)/eventoHistorico.h $(SRC)/cronologia.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cronologia.o $(SRC)/cronologia.cpp

$(OBJ)/eventoHistorico.o : $(INC)/eventoHistorico.h $(SRC)/eventoHistorico.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/eventoHistorico.o $(SRC)/eventoHistorico.cpp

# ************ Limpieza ************
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*
