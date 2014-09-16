#include <DirectXTemplatePCH.h>
#include "TorchWindow.h"
#include "TorchAPI.h"
#include "TorchRender.h"
#include "d3dclass.h"

TorchAPI *Graphics = NULL;
TorchRender *Render = NULL;
D3DClass* m_D3D = 0;
D3DClass* m_D3D2 = 0;
D3DClass* m_D3D3 = 0;
D3DClass* m_D3D4 = 0;

HMENU Menu;

int TorchWindow::CreateTorchClass(HINSTANCE hInstance)
{
	WNDCLASSEX wc;;
	DEVMODE dmScreenSettings;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hCursor			= LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOGO));
	wc.hInstance		= hInstance;
	wc.lpfnWndProc		= TorchWndProc;
	wc.lpszClassName	= "TME";
	wc.style			= CS_OWNDC | CS_VREDRAW | CS_HREDRAW;

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Error: Cannot Register Windows Class", "ERRO!", MB_OK);
		return 0;
	}

	return 0;
}

int TorchWindow::CreateTorchWin(HINSTANCE hInstance, char *TorchWinName, int TorchWinWidth, int TorchWinHeight)
{
	TorchWnd = CreateWindowEx(WS_EX_APPWINDOW, "TME", TorchWinName, WS_VISIBLE | WS_MINIMIZEBOX  | WS_SYSMENU, 0, 0, TorchWinWidth, TorchWinHeight, NULL, NULL, hInstance, NULL);

	if(!TorchWnd)
	{
		MessageBox(NULL, "Error: Cannot create Main Window", "ERRO!", MB_OK);
		return 0;
	}

	TorchChild1 = CreateWindowEx(WS_EX_APPWINDOW, "TME", TorchWinName, WS_VISIBLE | WS_DLGFRAME | WS_CHILD, 100, 0, 630, 370, TorchWnd, NULL, hInstance, NULL);
	TorchChild2 = CreateWindowEx(WS_EX_APPWINDOW, "TME", TorchWinName, WS_VISIBLE | WS_DLGFRAME | WS_CHILD, 100, 370, 630, 370, TorchWnd, NULL, hInstance, NULL);
	TorchChild3 = CreateWindowEx(WS_EX_APPWINDOW, "TME", TorchWinName, WS_VISIBLE | WS_DLGFRAME | WS_CHILD, 730, 0, 630, 370, TorchWnd, NULL, hInstance, NULL);
	TorchChild4 = CreateWindowEx(WS_EX_APPWINDOW, "TME", TorchWinName, WS_VISIBLE | WS_DLGFRAME | WS_CHILD, 730, 370, 630, 370, TorchWnd, NULL, hInstance, NULL);

	Graphics->EnableOGL();
	
	bool result;

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	m_D3D2 = new D3DClass;
	m_D3D3 = new D3DClass;
	m_D3D4 = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(630, 670, VSYNC_ENABLED, TorchChild1, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(TorchWnd, "Could not initialize Direct3D.", "Error", MB_OK);
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D2->Initialize(630, 670, VSYNC_ENABLED, TorchChild2, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(TorchWnd, "Could not initialize Direct3D.", "Error", MB_OK);
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D3->Initialize(630, 670, VSYNC_ENABLED, TorchChild3, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(TorchWnd, "Could not initialize Direct3D.", "Error", MB_OK);
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D4->Initialize(630, 670, VSYNC_ENABLED, TorchChild4, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(TorchWnd, "Could not initialize Direct3D.", "Error", MB_OK);
		return false;
	}

	Menu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU));
	SetMenu(TorchWnd, Menu);

	return 0;
}

int TorchWindow::WinLoop(MSG msg)
{

	while(running)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			//Render->MainRender();
			m_D3D->BeginScene(1.0f, 0.0f, 0.0f, 1.0f);
			m_D3D2->BeginScene(0.0f, 1.0f, 0.0f, 1.0f);
			m_D3D3->BeginScene(0.0f, 0.0f, 1.0f, 1.0f);
			m_D3D4->BeginScene(1.0f, 0.0f, 1.0f, 1.0f);
			m_D3D->EndScene();
			m_D3D2->EndScene();
			m_D3D3->EndScene();
			m_D3D4->EndScene();
		}

	}

	return 0;
}