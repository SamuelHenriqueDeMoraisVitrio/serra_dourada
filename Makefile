
CC=gcc
FILE_MAIN=main.c
SRC=src/${FILE_MAIN}
OUT_NAME=serra_dourada.out
WATH=./silver.out --src src --tags mac const dep globals dec def --watch

all: comp

silver:
	@echo ""
	@${WATH}
	@echo ""

comp:
	@echo ""
	${CC} ${SRC} -o ${OUT_NAME}
	@echo ""
