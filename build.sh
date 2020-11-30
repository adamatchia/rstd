mkdir build
cd build
cmake ..
make
cp librstd.so ../bin/librstd.so
sudo mkdir /usr/lib/rcloud
sudo cp librstd.so /usr/lib/rcloud/librstd.so
cd ../
