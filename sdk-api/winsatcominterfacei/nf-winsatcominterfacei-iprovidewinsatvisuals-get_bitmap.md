# IProvideWinSATVisuals::get_Bitmap

## Description

[IProvideWinSATVisuals::get_Bitmap may be altered or unavailable for releases after Windows 8.1.]

Retrieves a bitmap for the WinSAT base score.

## Parameters

### `bitmapSize` [in]

Determines the size of the bitmap that this method returns. For possible values, see the [WINSAT_BITMAP_SIZE](https://learn.microsoft.com/windows/win32/api/winsatcominterfacei/ne-winsatcominterfacei-winsat_bitmap_size) enumeration.

### `state` [in]

The state of the assessment. To get this value, call the [IProvideWinSATResultsInfo::get_AssessmentState](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_assessmentstate) method.

### `rating` [in]

The base score for the computer. To get this value, call the [IProvideWinSATResultsInfo::get_SystemRating](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_systemrating) method.

### `pBitmap` [out]

The handle to the bitmap. To free the handle when finished, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function.

## Return value

This method can return one of these values.

The following table lists some of the HRESULT values that this method returns.

| Return code/value | Description |
| --- | --- |
| **S_OK** | Successfully retrieved the bitmap. |
| **WINSAT_ERROR_FAILEDTOLOADRESOURCE**<br><br>0x80040016 | The *rating* value is not valid. Valid values are 1.0 through 9.9. |

## Remarks

The bitmap is returned only for the WINSAT_ASSESSMENT_STATE_VALID and WINSAT_ASSESSMENT_STATE_INCOHERENT_WITH_HARDWARE states. The method will succeed (return value is S_OK) if you pass another state value, but the *pBitmap* parameter will be **NULL**.

#### Examples

The following example shows how to retrieve a bitmap that represents the base score of the assessment. The example uses the [Win32_WinSAT](https://learn.microsoft.com/windows/desktop/WinSAT/win32-winsat) WMI MOF class to get the state and base score that you pass to this method.

```cpp
#include <windows.h>
#include <comutil.h>
#include <commctrl.h>
#include <wbemidl.h>
#include <winsatcominterfacei.h>

#pragma comment(lib, "comsupp.lib") // For _bstr_t
#pragma comment(lib, "comctl32.lib") // For common controls
#pragma comment(lib, "gdi32.lib")

// The WQL query used to retrieve an instance of the Win32_WinSAT class.
#define WINSAT_QUERY_STRING  L"Select * \
From Win32_WinSAT \
Where TimeTaken = 'MostRecentAssessment'"

HRESULT GetBaseScore(float* pBaseScore, WINSAT_ASSESSMENT_STATE* pState);
HRESULT GetScoreBitmap(const float BaseScore, const WINSAT_ASSESSMENT_STATE State, HBITMAP* phbitmap);
LRESULT CALLBACK MonitorWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

// Global variables
HINSTANCE g_hinst;
HWND g_hwndStatus;
HBITMAP g_hScoreBitmap;

#define IDC_MONITOR        100

int WINAPI WinMain(HINSTANCE hinst,
    HINSTANCE hinstPrev,
    LPSTR pszCmdLine,
    int nCmdShow)
{
    WNDCLASSEX wc;
    ATOM atom;
    HWND hwnd;
    MSG msg;

    g_hinst = hinst;

    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = MonitorWndProc;
    wc.hInstance = hinst;
    wc.lpszClassName = TEXT("MainWClass");
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    atom = RegisterClassEx(&wc);
    hwnd = CreateWindowEx(0,
        TEXT("MainWClass"),
        TEXT("Experience Index Base Score"),
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
        CW_USEDEFAULT, CW_USEDEFAULT,
        390, 165,
        NULL,
        NULL,
        hinst,
        NULL);

    if (NULL == hwnd)
    {
        return (int)GetLastError();
    }

    ShowWindow(hwnd, nCmdShow);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK MonitorWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    HRESULT  hr = S_OK;

    switch(msg)
    {
        case WM_CREATE:
        {
            INITCOMMONCONTROLSEX initctrls;
            RECT rc;
            float BaseScore = 0.0;
            WINSAT_ASSESSMENT_STATE AssessmentState;

            SetWindowText(hwnd, TEXT("Experience Index Base Score"));

            initctrls.dwSize = sizeof(initctrls);
            initctrls.dwICC = ICC_BAR_CLASSES;
            InitCommonControlsEx(&initctrls);

            GetClientRect(hwnd, &rc);

            g_hwndStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL,
                WS_CHILD | WS_BORDER | WS_VISIBLE,
                rc.left, rc.bottom - 20, rc.right, 20,
                hwnd, (HMENU) IDC_MONITOR, g_hinst, NULL);

            if (NULL == g_hwndStatus)
                return (LRESULT) NULL;

            hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

            // Get the base score and the state of the assessment.
            if (FAILED(hr = GetBaseScore(&BaseScore, &AssessmentState)))
            {
                SetWindowText(g_hwndStatus, TEXT("Failed to get base score and state"));
            }

            // Get the bitmap for the specified score and state values.
            if (FAILED(hr = GetScoreBitmap(BaseScore, AssessmentState, &g_hScoreBitmap)) || NULL == g_hScoreBitmap)
            {
                SetWindowText(g_hwndStatus, TEXT("Failed to get base score bitmap"));
            }

            break;
        }

        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hdcWin;
            HDC hdcCompatible;
            HGDIOBJ bmpOld;
            BITMAP bitmap;

            // Write the bitmap to the window.
            if (g_hScoreBitmap)
            {
                hdcWin = BeginPaint(hwnd, &ps);
                hdcCompatible = CreateCompatibleDC(hdcWin);
                bmpOld = SelectObject(hdcCompatible, g_hScoreBitmap);
                GetObject(g_hScoreBitmap, sizeof(BITMAP), &bitmap);
                BitBlt(hdcWin, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcCompatible, 0, 0, SRCCOPY);
                SelectObject(hdcCompatible, bmpOld);
                DeleteDC(hdcCompatible);
                EndPaint(hwnd, &ps);
            }

            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            CoUninitialize();
            DeleteObject(g_hScoreBitmap);
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return 0;
}

// Use the Win32_WinSAT WMI class to retrieve the base score and
// state of the most recent assessment.
HRESULT GetBaseScore(float* pBaseScore, WINSAT_ASSESSMENT_STATE* pState)
{
    HRESULT hr = S_OK;
    IWbemServices* pServices = NULL;
    IWbemLocator* pLocator = NULL;
    IEnumWbemClassObject* pEnum = NULL;
    IWbemClassObject* pWinSAT = NULL;
    _variant_t vBaseScore;
    _variant_t vState;
    ULONG returned = 0;

    // WMI code to retrieve the Win32_WinSAT instance.
    hr = CoCreateInstance(__uuidof(WbemLocator),
        NULL,
        CLSCTX_INPROC_SERVER,
        __uuidof(IWbemLocator),
        (void**)&pLocator);

    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    hr = pLocator->ConnectServer(_bstr_t(L"root\\cimv2"),
        NULL, NULL, NULL, 0L, NULL, NULL,
        &pServices);

    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    hr = pServices->ExecQuery(_bstr_t(L"WQL"),
        _bstr_t(WINSAT_QUERY_STRING),
        WBEM_FLAG_USE_AMENDED_QUALIFIERS | WBEM_FLAG_FORWARD_ONLY,
        NULL,
        &pEnum);

    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    // The query will return only one instance.
    hr = pEnum->Next(WBEM_INFINITE, 1, &pWinSAT, &returned);
    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    hr = pWinSAT->Get(L"WinSPRLevel", 0, &vBaseScore, NULL, NULL);
    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    *pBaseScore = vBaseScore.fltVal;

    hr = pWinSAT->Get(L"WinSATAssessmentState", 0, &vState, NULL, NULL);
    if (FAILED(hr))
    {
        // Handle error
        goto cleanup;
    }

    *pState = (WINSAT_ASSESSMENT_STATE)vState.lVal;

cleanup:

    if (pLocator)
        pLocator->Release();

    if (pServices)
        pServices->Release();

    if (pEnum)
        pEnum->Release();

    if (pWinSAT)
        pWinSAT->Release();

    return hr;
}

HRESULT GetScoreBitmap(const float BaseScore, const WINSAT_ASSESSMENT_STATE State, HBITMAP* phbitmap)
{
    HRESULT hr = S_OK;
    IProvideWinSATVisuals* pVisuals = NULL;

    // Code to retrieve the bitmap from WinSAT. Get the bitmap
    // only if the state is one of the following states.
    if (WINSAT_ASSESSMENT_STATE_VALID == State ||
        WINSAT_ASSESSMENT_STATE_INCOHERENT_WITH_HARDWARE == State)
    {
        hr = CoCreateInstance(__uuidof(CProvideWinSATVisuals),
            NULL,
            CLSCTX_INPROC_SERVER,
            __uuidof(IProvideWinSATVisuals),
            (void**)&pVisuals);

        if (FAILED(hr))
        {
            // Handle error
            goto cleanup;
        }

        hr = pVisuals->get_Bitmap(WINSAT_BITMAP_SIZE_NORMAL,
            State,
            BaseScore,
            phbitmap);

        if (FAILED(hr))
        {
            // Handle error
            goto cleanup;
        }
    }

cleanup:

    if (pVisuals)
        pVisuals->Release();

    return hr;
}

```

## See also

[IProvideWinSATVisuals](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nn-winsatcominterfacei-iprovidewinsatvisuals)