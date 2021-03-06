echo Running Audit

# Build library
./build.sh

# Building all tests
cd test

cd StringUtilsTest
sudo chmod 770 build.sh
./build.sh
cd ../

cd CSVTest
sudo chmod 770 build.sh
./build.sh
cd ../

cd ConsoleTest
sudo chmod 770 build.sh
./build.sh
cd ../

cd FileTest
sudo chmod 770 build.sh
./build.sh
cd ../

cd ../

# Running tests
cd test

cd StringUtilsTest
./test
cd ../

cd CSVTest
./test
cd ../

cd ConsoleTest
./test g++ --compile --o main.cc
cd ../

cd FileTest
./test
cd ../

cd ../

# Finished
echo Audit Complete!

