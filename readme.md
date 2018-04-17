to build:

pushd cpp_bindings
scons -j9 p=windows target=release_debug "godotbinpath=<steam prefix>\steamapps\common\Godot Engine\godot.windows.opt.tools.64.exe"
popd

mkdir build
pushd build
cmake -G "Visual Studio 15 2017 Win64" ..
popd

open tiamat.sln in build folder and have fun
