#include <DirectXTemplatePCH.h>
#include "TorchRender.h"


void TorchRender::MainRender()
{
	TorchRender::Window1Render();
	TorchRender::Window2Render();
	TorchRender::Window3Render();
	TorchRender::Window4Render();
}

void TorchRender::Window1Render()
{
	wglMakeCurrent(hDC1, hRC1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
			SwapBuffers(hDC1);
}

void TorchRender::Window2Render()
{
	wglMakeCurrent(hDC2, hRC2);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
			SwapBuffers(hDC2);
}

void TorchRender::Window3Render()
{
	wglMakeCurrent(hDC3, hRC3);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
			glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
			SwapBuffers(hDC3);
}

void TorchRender::Window4Render()
{
	wglMakeCurrent(hDC4, hRC4);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
			glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
			SwapBuffers(hDC4);
}