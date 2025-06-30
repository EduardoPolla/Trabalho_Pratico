CC = gcc
TARGET = trabalho_pratico
SOURCE = ./src
INCLUDE = ./INCLUDE
OBJETOS = ./objs

all: obj
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/arquivos.o $(OBJETOS)/cadastros.o $(OBJETOS)/relatorios.o $(OBJETOS)/consultas.o $(OBJETOS)/trabalho1.o -o $(TARGET)


obj:
	$(CC) -c $(SOURCE)/utils.c -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/arquivos.c -o $(OBJETOS)/arquivos.o
	$(CC) -c $(SOURCE)/cadastros.c -o $(OBJETOS)/cadastros.o
	$(CC) -c $(SOURCE)/relatorios.c -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/consultas.c -o $(OBJETOS)/consultas.o
	$(CC) -c trabalho1.c -o $(OBJETOS)/trabalho1.o


clear:
	rm $(TARGET)
	rm $(OBJETOS)/*.o
