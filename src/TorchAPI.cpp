#include <DirectXTemplatePCH.h>
#include "TorchAPI.h"
#include "TorchRender.h"

void TorchAPI::EnableOGL()
{
	int PixelFormat;
	int PixelFormat2;
	int PixelFormat3;
	int PixelFormat4;

	hDC1 = GetDC(TorchChild1);
	hDC2 = GetDC(TorchChild2);
	hDC3 = GetDC(TorchChild3);
	hDC4 = GetDC(TorchChild4);

	PIXELFORMATDESCRIPTOR pfd;

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 32;
	
	PixelFormat = ChoosePixelFormat(hDC1, &pfd);
	PixelFormat2 = ChoosePixelFormat(hDC2, &pfd);
	PixelFormat3 = ChoosePixelFormat(hDC3, &pfd);
	PixelFormat4 = ChoosePixelFormat(hDC4, &pfd);

	SetPixelFormat(hDC1, PixelFormat, &pfd);
	SetPixelFormat(hDC2, PixelFormat2, &pfd);
	SetPixelFormat(hDC3, PixelFormat3, &pfd);
	SetPixelFormat(hDC4, PixelFormat4, &pfd);

	hRC1 = wglCreateContext(hDC1);
	hRC2 = wglCreateContext(hDC1);
	hRC3 = wglCreateContext(hDC1);
	hRC4 = wglCreateContext(hDC1);


}


