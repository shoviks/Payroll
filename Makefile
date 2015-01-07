p2: main.o Payroll.o Employee.o Payrecord.o
	g++ -g -O0 -I/usr/local/gcc/4.9.0/lib64/libstdc++.so.6 -o p2 main.o Payroll.o Employee.o Payrecord.o

main.o: main.cpp Payroll.h
	g++ -g -O0 -c  -std=c++11 main.cpp

Employee.o: Employee.cpp Employee.h EOverloads.h
	g++ -g -O0 -c -std=c++11 Employee.cpp

Payrecord.o: Payrecord.cpp Payrecord.h POverloads.h
	g++ -g -O0 -c -std=c++11 Payrecord.cpp

Payroll.o: Payroll.cpp Payroll.h EOverloads.h POverloads.h Employee.h Payrecord.h
	g++ -g -O0 -c  -std=c++11 Payroll.cpp

make: p2
	./p2

clean:
	rm -rf p2
	rm -rf *.o