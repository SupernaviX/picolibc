rm -rf build-v810-unknown-vb
mkdir build-v810-unknown-vb
cd build-v810-unknown-vb
../scripts/do-v810-configure
ninja
cd ..

rm -rf build-bundle
mkdir build-bundle
mkdir build-bundle/include
cp build-v810-unknown-vb/picolibc.h build-bundle/include
cd libc/include && find . -name "*.h" -exec cp --parents {} ../../build-bundle/include \; && cd ../..
mkdir build-bundle/lib
cp build-v810-unknown-vb/libc.a build-bundle/lib

cd build-bundle
tar -czvf libc.tar.xz include lib