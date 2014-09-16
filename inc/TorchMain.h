#include <Windows.h>
#include "GL/glew.h"
#include "TorchResource.h"

#pragma comment(lib, "opengl32.lib") // link opengl32.lib
#pragma comment(lib, "GLu32.lib")    // link glu32.lib

extern HWND TorchWnd;
extern HWND TorchChild1;
extern HWND TorchChild2;
extern HWND TorchChild3;
extern HWND TorchChild4;

extern HDC	hDC1;
extern HDC	hDC2;
extern HDC	hDC3;
extern HDC	hDC4;

extern HGLRC hRC1;
extern HGLRC hRC2;
extern HGLRC hRC3;
extern HGLRC hRC4;

extern bool running;

extern LRESULT CALLBACK TorchWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);