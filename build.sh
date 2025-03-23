rm -rf build
mkdir csv_data
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .