INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS =


all: $(BIN)/usopilas

# ******** Generación de documentación **************
documentacion:
	doxygen doc/doxys/Doxyfile

# ******** Compilación de módulos ********
$(BIN)/usopilas : $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas $(OBJ)/usopilas_max.o

$(OBJ)/usopilas_max.o : $(SRC)/usopilas_max.cpp  $(INC)/Pila_max.h
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/usopilas_max.o $(SRC)/usopilas_max.cpp

# ******** Limpieza ********
clean :
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*

