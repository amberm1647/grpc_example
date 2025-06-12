# gRPC Example (C++)

A simple hello world project to test a connection between a gRPC client running in Unreal Engine and a gRPC server running on a remote machine.

# Setup

## Repository

```
git clone https://github.com/amberm1647/ghost_gpu_grpc.git --recurse-submodules
```

Follow the "Preparation" steps at the DepthAnything readme to install the necessary Python packages and model files: https://github.com/DepthAnything/Depth-Anything-V2#usage

## Install gRPC using vcpkg

Run in Powershell:

```
mkdir C:\src\
cd C:\src\
git clone https://github.com/microsoft/vcpkg
cd vcpkg
git checkout -b 2025.02.14 2025.02.14
.\bootstrap-vcpkg.bat
.\vcpkg.exe --triplet x64-windows install protobuf grpc
.\vcpkg.exe integrate install
```

If behind proxy:

```
$ENV:HTTP_PROXY='http://proxy-dmz.intel.com:912'
$ENV:HTTPS_PROXY='http://proxy-dmz.intel.com:912'
```

## Install Visual Studio 2022

Install the following workloads:

- .NET desktop development
- Desktop development with C++
- Universal Windows Platform development
- Game development with C++

Make sure you have the latest MSVC v143 (v14.45-17.15 or above) and Windows 11 SDK 10.0.22621.0 or above.

## Install CMake for Windows

Download and install the latest version (4.0 or above): https://cmake.org/download

# Build

(Referenced from https://sanoj.in/2020/05/07/working-with-grpc-in-windows.html)

C++ source files for protobuf have already been generated and included in this repository. Use these commands to re-generate them if needed:

```
cd proto

C:\src\vcpkg\installed\x64-windows\tools\protobuf\protoc.exe  --cpp_out=. --proto_path=. helloworld.proto

C:\src\vcpkg\installed\x64-windows\tools\protobuf\protoc.exe --proto_path=. --grpc_out=. --plugin=protoc-gen-grpc="C:\src\vcpkg\packages\grpc_x64-windows\tools\grpc\grpc_cpp_plugin.exe" helloworld.proto
```

Then, create a build directory and run CMake to generate build files:

```
mkdir build

cd build

cmake "-DCMAKE_TOOLCHAIN_FILE:PATH=C:\src\vcpkg\scripts\buildsystems\vcpkg.cmake" "-DCMAKE_PREFIX_PATH=C:\src\vcpkg\packages"  ..
```

Open the .sln file in Visual Studio. Set the solution configuration to "Release" (dropdown menu in the top toolbar, defaults to "Debug") and then build the server and client. This setting ensures that the client dll will not try to link with debug versions of libraries which are not installed. 

Once the build completes, the build/Release/ directory should include server.exe, client.dll, client.exp, and client.lib. Refer to https://github.com/amberm1647/unreal_grpc_helloworld for Unreal integration.
