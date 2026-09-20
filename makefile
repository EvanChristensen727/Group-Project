CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

program.out: main.o Reservation.o ReservationManager.o Resource.o
	$(CXX) $(CXXFLAGS) main.o Reservation.o ReservationManager.o Resource.o -o program.out

main.o: src/main.cpp include/Reservation.h include/ReservationManager.h include/Resource.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

Reservation.o: src/Reservation.cpp include/Reservation.h
	$(CXX) $(CXXFLAGS) -c src/Reservation.cpp -o Reservation.o

ReservationManager.o: src/ReservationManager.cpp include/ReservationManager.h include/Reservation.h
	$(CXX) $(CXXFLAGS) -c src/ReservationManager.cpp -o ReservationManager.o

Resource.o: src/Resource.cpp include/Resource.h
	$(CXX) $(CXXFLAGS) -c src/Resource.cpp -o Resource.o

clean:
	rm -f *.o program.out
