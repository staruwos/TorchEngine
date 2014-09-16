// System includes
#include <windows.h>
#include <iostream>
 
/////////////
// LINKING //
/////////////
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")


//////////////
// INCLUDES //
//////////////
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dx10math.h>

// Safely release a COM object.
template<typename T>
inline void SafeRelease( T& ptr )
{
    if ( ptr != NULL )
    {
        ptr->Release();
        ptr = NULL;
    }
}