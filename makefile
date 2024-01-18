CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB=basicClassification.o advancedClassificationLoop.o advancedClasificationRecursion.o
FLAGS= -Wall -g


all: libclassrec.a libclassrec.so libclassloops.a libclassloops.so mains maindrec maindloop

mains: $(OBJECT_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECT_MAIN) libclassrec.a
maindloop: $(OBJECT_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECT_MAIN) ./libclassloops.so
maindrec: $(OBJECT_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECT_MAIN) ./libclassrec.so


libclassloops.a: $(OBJECT_LIB)
	$(AR) -rcs libclassloops.a $(OBJECT_LIB)
libclassrec.a: $(OBJECT_LIB)
	$(AR) -rcs libclassrec.a $(OBJECT_LIB)
libclassloops.so: $(OBJECT_LIB)
	$(CC) -shared -o libclassloops.so $(OBJECT_LIB)
libclassrec.so: $(OBJECT_LIB)
	$(CC) -shared -o libclassrec.so $(OBJECT_LIB)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClasificationRecursion.o: advancedClasificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClasificationRecursion.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec