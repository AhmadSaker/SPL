# All Targets

all: bin/warehouse


# Tool invocations

# Executable "warehouse" depends on the files main.o bin/WareHouse.o bin/Volunteer.o bin/Customer.o bin/Order.o bin/Action.o

bin/warehouse: bin/main.o bin/WareHouse.o bin/readConfigFile.o bin/Volunteer.o bin/CollectorVolunteer.o bin/DriverVolunteer.o bin/LimitedCollectorVolunteer.o bin/LimitedDriverVolunteer.o bin/Customer.o bin/CivilianCustomer.o bin/SoldierCustomer.o bin/Order.o bin/BaseAction.o bin/SimulateStep.o bin/AddOrder.o bin/AddCustomer.o bin/PrintOrderStatus.o bin/PrintCustomerStatus.o bin/PrintVolunteerStatus.o bin/PrintActionsLog.o bin/Close.o bin/BackupWareHouse.o bin/RestoreWareHouse.o

	g++ -o bin/warehouse bin/main.o bin/WareHouse.o bin/readConfigFile.o bin/Volunteer.o bin/CollectorVolunteer.o bin/DriverVolunteer.o bin/LimitedCollectorVolunteer.o bin/LimitedDriverVolunteer.o bin/Customer.o bin/CivilianCustomer.o bin/SoldierCustomer.o bin/Order.o bin/BaseAction.o bin/SimulateStep.o bin/AddOrder.o bin/AddCustomer.o bin/PrintOrderStatus.o bin/PrintCustomerStatus.o bin/PrintVolunteerStatus.o bin/PrintActionsLog.o bin/Close.o bin/BackupWareHouse.o bin/RestoreWareHouse.o


# Depends on the source and header files

bin/main.o: src/main.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

# Depends on the source and header files

bin/BaseAction.o: src/BaseAction.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp

bin/RestoreWareHouse.o: src/RestoreWareHouse.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RestoreWareHouse.o src/RestoreWareHouse.cpp

bin/BackupWareHouse.o: src/BackupWareHouse.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BackupWareHouse.o src/BackupWareHouse.cpp

bin/Close.o: src/Close.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Close.o src/Close.cpp

bin/PrintActionsLog.o: src/PrintActionsLog.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp

bin/PrintVolunteerStatus.o: src/PrintVolunteerStatus.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintVolunteerStatus.o src/PrintVolunteerStatus.cpp

bin/PrintCustomerStatus.o: src/PrintCustomerStatus.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintCustomerStatus.o src/PrintCustomerStatus.cpp

bin/PrintOrderStatus.o: src/PrintOrderStatus.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintOrderStatus.o src/PrintOrderStatus.cpp

bin/AddCustomer.o: src/AddCustomer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/AddCustomer.o src/AddCustomer.cpp

bin/AddOrder.o: src/AddOrder.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/AddOrder.o src/AddOrder.cpp

bin/SimulateStep.o: src/SimulateStep.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/SimulateStep.o src/SimulateStep.cpp

# Depends on the source and header files

bin/WareHouse.o: src/WareHouse.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/WareHouse.o src/WareHouse.cpp

# Depends on the source and header files

bin/Volunteer.o: src/Volunteer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Volunteer.o src/Volunteer.cpp

bin/CollectorVolunteer.o: src/CollectorVolunteer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CollectorVolunteer.o src/CollectorVolunteer.cpp

bin/DriverVolunteer.o: src/DriverVolunteer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/DriverVolunteer.o src/DriverVolunteer.cpp

bin/LimitedCollectorVolunteer.o: src/LimitedCollectorVolunteer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LimitedCollectorVolunteer.o src/LimitedCollectorVolunteer.cpp

bin/LimitedDriverVolunteer.o: src/LimitedDriverVolunteer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LimitedDriverVolunteer.o src/LimitedDriverVolunteer.cpp

# Depends on the source and header files

bin/readConfigFile.o: src/readConfigFile.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/readConfigFile.o src/readConfigFile.cpp

# Depends on the source and header files

bin/Customer.o: src/Customer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

bin/CivilianCustomer.o: src/CivilianCustomer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CivilianCustomer.o src/CivilianCustomer.cpp

bin/SoldierCustomer.o: src/SoldierCustomer.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/SoldierCustomer.o src/SoldierCustomer.cpp

# Depends on the source and header files

bin/Order.o: src/Order.cpp

	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Order.o src/Order.cpp

#Clean the build directory

clean:

	rm -f bin/*