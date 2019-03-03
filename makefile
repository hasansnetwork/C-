hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/imei.o -c ./src/imei.c
	gcc -I ./include/ -o ./lib/kisi.o -c ./src/kisi.c
	gcc -I ./include/ -o ./lib/tc.o -c ./src/tc.c
	gcc -I ./include/ -o ./lib/tel.o -c ./src/tel.c
	gcc -I ./include/ -o ./bin/main ./lib/imei.o ./lib/kisi.o ./lib/tc.o ./lib/tel.o ./src/main.c
calistir:
	./bin/main
