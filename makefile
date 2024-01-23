CC=gcc
AR=ar
OBJECT_MAIN=main.o
OBJECT_LIB_REC=basicClassification.o advancedClasificationRecursion.o
OBJECT_LIB_LOOP=basicClassification.o advancedClassificationLoop.o
FLAGS= -Wall -g

all: libclassrec.a libclassrec.so libclassloops.a libclassloops.so mains maindrec maindloop
loops: libclassloops.a
loopd: libclassloops.so
recursives: libclassrec.a
recursived: libclassrec.so

mains: $(OBJECT_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECT_MAIN) libclassrec.a
maindloop: $(OBJECT_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECT_MAIN) ./libclassloops.so
maindrec: $(OBJECT_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECT_MAIN) ./libclassrec.so

libclassloops.a: $(OBJECT_LIB_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_LIB_LOOP)
libclassrec.a: $(OBJECT_LIB_REC)
	$(AR) -rcs libclassrec.a $(OBJECT_LIB_REC)
libclassloops.so: $(OBJECT_LIB_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECT_LIB_LOOP)
libclassrec.so: $(OBJECT_LIB_REC)
	$(CC) -shared -o libclassrec.so $(OBJECT_LIB_REC)

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