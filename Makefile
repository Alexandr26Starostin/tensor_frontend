CC=g++

MODE=DEBUG
#MODE=RELEASE

#-DINTRINSICS  по 32
#-DINLINE_ASM

#-fno-inline

#-DPRINT_TEXT_FROM_FILE
#-DPRINT_INF_ABOUT_HASH_FUNC  

FILES=main.o color_print.o onnx_graph.o
TARGET=frontend
#INTRINSICS=-mavx2 -msse -msse2
#INLINE_ASM=-masm=intel
DEFINES=-D DARK_THEME_    
#       -D LIGHT_THEME_

ifeq ($(MODE),DEBUG)
	FLAGS=-Iinclude -O2 -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=40000 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D_EJC
	SANITIZERS=-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
else
	FLAGS=-Iinclude -DNDEBUG -O3 -fno-inline
	SANITIZERS=
endif

#SFML_TARGETS=sfml-app -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system #-lsfml-audio
#g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# pathsub
# addprefix
# wildcard

#nasm -f elf64 -l my_printf.lst my_printf.s
#g++ -static main.cpp my_printf.o  -o my_printf

COMPILATION=$(FLAGS) $(SANITIZERS) $(DEFINES)

PATCHED_FILES = $(addprefix build/, $(FILES))

all: prepare $(TARGET)

prepare:
	mkdir -p build

$(TARGET): $(FILES)
	@echo "Linling..."
	@$(CC) $(COMPILATION) $(PATCHED_FILES) -o $(TARGET) 
#-o $(SFML_TARGETS) 

main.o: src/main.cpp
	@$(CC) -c $(COMPILATION) src/main.cpp -o build/main.o

color_print.o: src/color_print.cpp
	@$(CC) -c $(COMPILATION) src/color_print.cpp -o build/color_print.o

onnx_graph.o: src/onnx_graph.cpp
	@$(CC) -c $(COMPILATION) src/onnx_graph.cpp -o build/onnx_graph.o

clean:
	rm -rf $(TARGET)
	cd build && rm -rf *.o