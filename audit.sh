echo Running Audit

# Build library
./build.sh

# Building all tests
cd test

cd StringUtilsTest
./build.sh
cd ../

cd ../

# Running tests
cd test

cd StringUtilsTest
./test
cd ../

cd ../

# Finished
echo Audit Complete!

