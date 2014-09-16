#include "TorchMain.h"
#include "d3dclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class TorchWindow
{
public:
	int CreateTorchClass(HINSTANCE hInstance);
	int CreateTorchWin(HINSTANCE hInstance, char *TorchWinName, int TorchWinWidth, int TorchWinHeight);

	int WinLoop(MSG msg);

};