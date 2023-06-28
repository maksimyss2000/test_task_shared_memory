build_dir=./build

all: create_build_dir writer reader 
	gcc $(build_dir)/common.o $(build_dir)/writer.o -o $(build_dir)/writer.out
	gcc $(build_dir)/common.o $(build_dir)/reader.o -o $(build_dir)/reader.out

writer: create_build_dir commom
	gcc -c ./writer.c -o $(build_dir)/writer.o 

reader: create_build_dir commom
	gcc -c ./reader.c -o $(build_dir)/reader.o 

commom: create_build_dir
	gcc -c ./common.c -o $(build_dir)/common.o 

create_build_dir:
	mkdir -p $(build_dir)
