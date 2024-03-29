// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>


// C RunTime Header Files
#if _DEBUG
	#define _CRTDBG_MAP_ALLOC  
	#include <crtdbg.h> 
#endif
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

// STL Headers
#include <iostream>
#include <string>
#include <vector>
#include <random>

// DirectX Header Files
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9tex.h>
#include <d3d9types.h>