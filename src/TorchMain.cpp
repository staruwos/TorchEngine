#include <DirectXTemplatePCH.h>
#include "TorchMain.h"
#include "TorchWindow.h"


HWND TorchWnd;
HWND TorchChild1;
HWND TorchChild2;
HWND TorchChild3;
HWND TorchChild4;

HDC hDC1;
HDC hDC2;
HDC hDC3;
HDC hDC4;

HGLRC hRC1;
HGLRC hRC2;
HGLRC hRC3;
HGLRC hRC4;

bool running = true;

MSG msg;
TorchWindow *Win = NULL;

void WinCommands(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(wParam == ID_FILEEXIT)
	{
		running = false;
		PostQuitMessage(0);
	}

}

LRESULT CALLBACK TorchWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_CREATE:
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		running = false;
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		WinCommands(hWnd, msg, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevious, LPSTR lpCmdLine, int nCmdShow)
{
	Win->CreateTorchClass(hInstance);
	Win->CreateTorchWin(hInstance, "Torch Engine", 1366, 768);
	Win->WinLoop(msg);

	return(int) msg.wParam;
}