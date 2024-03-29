#include "stdafx.h"
#include "D3DEngine.h"
#include "TheHive.h"

#define MAX_LOADSTRING 100

// Global Variables:
BOOL g_bShutdown = FALSE;												// Flag to shutdown the application
HWND g_hWnd;																		// Global flag that holds the applicataion window handle
RECT g_Rect;																		// Global flag that holds the window rectangle that is being used for rendering game
HINSTANCE g_hInst;                              // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

																								// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass( HINSTANCE , HBRUSH );
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{

#if _DEBUG
	// This will create a checkpoint for the debugger to detect
	// any memory leaks that are present in the application
	// No way thats ever going to happen on my shift.
	_CrtMemState s1;
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtMemCheckpoint(&s1);
#endif

	UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);
	HBRUSH hbrBackground = ::CreateSolidBrush(RGB(0, 0, 0));

	// Initialize global strings
	LoadStringW( hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING );
	LoadStringW( hInstance, IDC_THEHIVE, szWindowClass, MAX_LOADSTRING );
	MyRegisterClass( hInstance, hbrBackground );

	// Perform application initialization:
	if (!InitInstance (hInstance, SW_HIDE))
	{
			return FALSE;
	}

  HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_THEHIVE));

	// Initialize the super elite directx 9 engine
	D3DEngine* engine = new D3DEngine(g_hWnd, D3DCOLOR_XRGB(0, 0, 0));

	// Check to see if the user is a total loser and has a crappy computer.
	if ( !engine->IsValidDevice() ) {
		
		// Hide the window so we can display the error message
		// to the technology retarded user
		ShowWindow(g_hWnd, SW_HIDE);

		// Release the directx 9 game engine in double shame
		delete engine;

		// Display Message to let user know they need to upgrade their system today I'm mean what the fuck you don't have DirectX 9?
		// That is just sad! You need to stop trying to install elite directx application like this if you do not at least
		// have an outdated DirectX library installed on your shitty computer.
		return MessageBox(g_hWnd, L"Could not intialize the DirectX 9", L"DirectX Exception", MB_OK);
	}

	ShowWindow(g_hWnd, SW_SHOW);

	UpdateWindow(g_hWnd);

  MSG msg;

	// Intialize the message 
	ZeroMemory(&msg, sizeof(MSG));

	// Start the game loop
	while (g_bShutdown != TRUE) {

		// Retreive messages
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			
			// Translate any keysroks that the user enters
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}
		else {

			// Validate the D3DEngine is valid
			if (engine) {

				// Validate the Direct3D9 Device is valid
				if (engine->IsValidDevice()) {
					
					// Update the Diect3D9 devices game objects
					engine->Update();

					// Render Diect3D9 devices
					if (engine->Render() == FALSE) {

						// Reset the Diect3D9 devices
						if (engine->Reset() == FALSE) {

							// Send an application destory message	if reset fails
							SendMessage(g_hWnd, WM_DESTROY, 0, 0);

						}
					}
				}
				else {

					// Reset the Diect3D9 devices
					if (engine->Reset() == FALSE) {
						
						// Send an application destroymessage	if reset fails
						SendMessage(g_hWnd, WM_DESTROY, 0, 0);

					}
				}
			}
		}
	}

	// Delete the D3DEngine object
	delete engine;

	// Release the background brush
	DeleteObject(hbrBackground);

#if _DEBUG
	//This will dump any memory leak statics if there are any
	_CrtMemDumpStatistics(&s1);
	_CrtDumpMemoryLeaks();
#endif

    return (int) msg.wParam;
}

ATOM MyRegisterClass( HINSTANCE hInstance, HBRUSH hbrBackground )
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_THEHIVE));
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = hbrBackground;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

  return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	g_hInst = hInstance; // Store instance handle in our global variable

	DWORD dwExStyle = WS_EX_TOPMOST | WS_EX_APPWINDOW;
	DWORD dwStyle = WS_POPUP;

	#if _DEBUG
		g_Rect.top = 0;
		g_Rect.left = 0;
		g_Rect.right = GetSystemMetrics(SM_CXSCREEN);
		g_Rect.bottom = GetSystemMetrics(SM_CYSCREEN);
	#else
		g_Rect.top = GetSystemMetrics(SM_XVIRTUALSCREEN);
		g_Rect.left = GetSystemMetrics(SM_YVIRTUALSCREEN);
		g_Rect.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
		g_Rect.bottom = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	#endif

	g_hWnd = CreateWindowEx(dwExStyle,szWindowClass,szTitle,dwStyle, g_Rect.top, g_Rect.left, g_Rect.right, g_Rect.bottom, nullptr,nullptr, hInstance, nullptr);

	if (!g_hWnd)
	{
		return FALSE;
	}
	
	ShowWindow(g_hWnd, nCmdShow);

	UpdateWindow(g_hWnd);
	

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	/*case WM_ACTIVATE: {
		if (wParam == WA_INACTIVE) {
			SendMessage(hWnd, WM_DESTROY, 0, 0);
		}
	}break;*/
	case WM_RBUTTONDOWN:
	case WM_LBUTTONDOWN:
	case WM_KEYDOWN: {
		SendMessage(hWnd, WM_DESTROY, 0, 0);
	} break;
	case WM_SETCURSOR: {
		SetCursor(NULL);
	}break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
		g_bShutdown = TRUE;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}