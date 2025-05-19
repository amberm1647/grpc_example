#pragma once

#ifdef CLIENT_EXPORTS
#define CLIENT_API __declspec(dllexport)
#else
#define CLIENT_API __declspec(dllimport)
#endif

#ifdef __cplusplus		//if C++ is used convert it to C to prevent C++'s name mangling of method names
extern "C"
{
#endif

	int CLIENT_API main(int argc, char** argv);

#ifdef __cplusplus
}
#endif