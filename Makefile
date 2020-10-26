AMP = @

CC = ${AMP}g++
CC_FLAGS = -fPIC -Wall

INCLUDE_FLAG = -Iinclude
LINK_FLAG = -lmetal

AR = ${AMP}ar
RM = ${AMP}rm -f

METAL_NAMES = 
METAL_NAMES += metal

METAL_OBJ_NAMES = ${addsuffix .o, ${METAL_NAMES}}
METAL_OBJS = ${addprefix build/, ${METAL_OBJ_NAMES}}

METAL_STATIC_LIB = build/libmetal.a
METAL_DYNAMIC_LIB = build/libmetal.so

MAIN_SRC = src/main.cpp
MAIN_OBJ = build/main.o

BIN = build/metal

default: clean lib ${BIN}

lib: ${METAL_STATIC_LIB} ${METAL_DYNAMIC_LIB}

debug:
	${eval AMP := }

${BIN}: ${MAIN_OBJ} ${METAL_OBJS}
	${CC} $^ -o $@

${MAIN_OBJ}: ${MAIN_SRC}
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${METAL_OBJS}: build/%.o: lib/%.cpp include/metal/%.hpp
	${CC} -c ${CC_FLAGS} $< -o $@ ${INCLUDE_FLAG}

${METAL_STATIC_LIB}: ${METAL_OBJS}
	${AR} rcs $@ $^

${METAL_DYNAMIC_LIB}: ${METAL_OBJS}
	${CC} -shared $^ -o $@

redo: clean default

run: ${BIN}
	@${BIN}

move:
	sudo cp ${BIN} /usr/bin

clean:
	${RM} ${BIN}
	${RM} ${MAIN_OBJ}
	${RM} ${METAL_OBJS}
	${RM} ${METAL_STATIC_LIB}
	${RM} ${METAL_DYNAMIC_LIB}


