# pre install

## install grpc
```
git clone git@github.com:grpc/grpc.git -b v1.47.0
cd grpc
git submodule update --init
mkdir -p cmake/build
cd cmake/build
cmake ../..
make
```
you will get protoc and cpp plugin.
## install conan
```
pip install conan
```

# build this project

```
mkdir build
cd build 
conan install ..
cmake ..
cmake --build . or make
```