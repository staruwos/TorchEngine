#include "TorchMain.h"

#pragma comment(lib, "opengl32.lib") // link opengl32.lib
#pragma comment(lib, "GLu32.lib")    // link glu32.lib

class TorchAPI
{
public:
	void EnableOGL();
	void DisableOGL();


	const int screenHeight;
	const int screenWidth;
};