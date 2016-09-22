// Tips Calculator Helper.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Tips Calculator Helper.h"
#include <windowsx.h>
#include <winuser.h>
#include <commctrl.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "ComCtl32.lib")
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TIPSCALCULATORHELPER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TIPSCALCULATORHELPER));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TIPSCALCULATORHELPER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_BTNFACE+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TIPSCALCULATORHELPER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
#define CreateTextBox(text, left, top, width, height, ID) 

HWND txtSo1;
HWND txtSo2;
HWND txtKetQua;
HWND txtKetQua2;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	
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
		break;
	case WM_CREATE:
	{
		INITCOMMONCONTROLSEX icc;
		icc.dwSize = sizeof(icc);
		icc.dwICC = ICC_WIN95_CLASSES;
		InitCommonControlsEx(&icc);

		// Lấy font hệ thống
		LOGFONT lf;
		GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
		HFONT hFont = CreateFont(lf.lfHeight, lf.lfWidth,
			lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
			lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
			lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
			lf.lfPitchAndFamily, lf.lfFaceName);

		HWND hwnd = CreateWindowEx(0, L"BUTTON", L"Tính tip của mỗi khách", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 10, 200, 40, hWnd, (HMENU)IDC_BUTTON1, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng số tiền:", WS_CHILD | WS_VISIBLE | SS_LEFT, 200, 100, 100, 40, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

		hwnd = CreateWindowEx(0, L"STATIC", L"Tổng số khách:", WS_CHILD | WS_VISIBLE | SS_LEFT, 200, 200, 100, 40, hWnd, NULL, hInst, NULL);
		SendMessage(hwnd, WM_SETFONT, WPARAM(hFont), TRUE);

		txtSo1 = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE| WS_BORDER, 350, 100, 100, 40, hWnd, NULL, hInst, NULL);
		SendMessage(txtSo1, WM_SETFONT, WPARAM(hFont), TRUE);

		txtSo2 = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 350, 200, 100, 40, hWnd, NULL, hInst, NULL);
		SendMessage(txtSo2, 0, WPARAM(hFont), TRUE);


		txtKetQua = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 350, 300, 300, 40, hWnd, NULL, hInst, NULL);
		SendMessage(txtKetQua, WM_SETFONT, WPARAM(hFont), TRUE);

		txtKetQua2 = CreateWindowEx(0, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER, 350, 400, 300, 40, hWnd, NULL, hInst, NULL);
		SendMessage(txtKetQua2, WM_SETFONT, WPARAM(hFont), TRUE);
	}
	break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);

		WCHAR* buffer1 = NULL;
		WCHAR* buffer2 = NULL;
		WCHAR* bufferKQ = new WCHAR[255];
		WCHAR* bufferKQ2 = new WCHAR[255];

		int size1;
		int size2;
		int sizeKQ;
		int sizeKQ2;

		int TongSoTien;
		int TongSoKhach;
		int kq;
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDC_BUTTON1: {
			size1 = GetWindowTextLength(txtSo1);
			size2 = GetWindowTextLength(txtSo2);
			
			buffer1 = new WCHAR[size1 + 1];
			buffer2 = new WCHAR[size2 + 1];

			GetWindowText(txtSo1, buffer1, size1 + 1);
			GetWindowText(txtSo2, buffer2, size2 + 1);

			TongSoTien = _wtoi(buffer1);
			TongSoKhach = _wtoi(buffer2);
			
			int SumTip = TongSoTien * 10 / 100;
			
			wsprintf(bufferKQ2, L"Lượng tiền tip : %d vnd", (SumTip ));
			wsprintf(bufferKQ, L"Lượng tiền tip của mỗi khách: %d vnd", (SumTip / TongSoKhach));

			SetWindowText(txtKetQua, bufferKQ);
			SetWindowText(txtKetQua2, bufferKQ2);
			break;


			if (!buffer1)
				delete[] buffer1;
			if (!buffer2)
				delete[] buffer2;
			if (!bufferKQ)
				delete[] bufferKQ;
			if (!bufferKQ2)
				delete[] bufferKQ2;
		}
						  break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
