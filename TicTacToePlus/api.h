#pragma once

#ifdef TICTACTOEPLUS_EXPORTS
#define TTTP_API __declspec(dllexport)
#else
#define TTTP_API __declspec(dllimport)
#endif