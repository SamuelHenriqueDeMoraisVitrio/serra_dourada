
CC=gcc
FILE_MAIN=main.c
SRC=src/${FILE_MAIN}
OUT_NAME=serra_dourada.out
WATH=./silver.out --src src --tags inc mac str const dep globals dec def --watch

all: clear comp

silver:
	@echo ""
	@${WATH}
	@echo ""

comp:
	@echo ""
	${CC} ${SRC} -o ${OUT_NAME}
	@echo ""

clear:
	clear
	@echo ""
