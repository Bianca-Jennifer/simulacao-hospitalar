SISTEMA_OPERACIONAL := $(shell uname -s)

main:arquivos_obj/main.o arquivos_obj/deque.o arquivos_obj/leito_lista.o arquivos_obj/log.o arquivos_obj/pacientes_tabela.o arquivos_obj/pilha.o
	gcc arquivos_obj/main.o arquivos_obj/deque.o arquivos_obj/leito_lista.o arquivos_obj/log.o arquivos_obj/pacientes_tabela.o arquivos_obj/pilha.o -o main

arquivos_obj/main.o:projeto/main.c
	gcc -c projeto/main.c -o arquivos_obj/main.o

arquivos_obj/deque.o:projeto/deque.c projeto/deque.h
	gcc -c projeto/deque.c -o arquivos_obj/deque.o

arquivos_obj/leito_lista.o:projeto/leito_lista.c projeto/leito_lista.h
	gcc -c projeto/leito_lista.c -o arquivos_obj/leito_lista.o

arquivos_obj/log.o: projeto/log.c projeto/log.h
	gcc -c projeto/log.c -o arquivos_obj/log.o

arquivos_obj/pacientes_tabela.o: projeto/pacientes_tabela.c projeto/pacientes_tabela.h
	gcc -c projeto/pacientes_tabela.c -o arquivos_obj/pacientes_tabela.o

arquivos_obj/pilha.o: projeto/pilha.c projeto/pilha.h
	gcc -c projeto/pilha.c -o arquivos_obj/pilha.o

clean_log:main pacientes_e_log/processamento.log
	> pacientes_e_log/processamento.log


clean:
ifeq ($(SISTEMA_OPERACIONAL),Linux)
	rm -f arquivos_obj/*.o main
endif
ifeq ($(SISTEMA_OPERACIONAL),Windows_NT)
	del /q arquivos_obj\*.o
	del /q main.exe
endif

