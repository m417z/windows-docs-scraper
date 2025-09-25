# ShutdownBlockReasonQuery function

## Description

Retrieves the reason string set by the [ShutdownBlockReasonCreate](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasoncreate) function.

## Parameters

### `hWnd` [in]

A handle to the main window of the application.

### `pwszBuff` [out, optional]

A pointer to a buffer that receives the reason string. If this parameter is **NULL**, the function retrieves the number of characters in the reason string.

### `pcchBuff` [in, out]

A pointer to a variable that specifies the size of the *pwszBuff* buffer, in characters. If the function succeeds, this variable receives the number of characters copied into the buffer, including the **null**-terminating character. If the buffer is too small, the variable receives the required buffer size, in characters, not including the **null**-terminating character.

## Return value

If the call succeeds, the return value is nonzero.

If the call fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can only be called from the thread that created the window specified by the *hWnd* parameter. Otherwise, the function fails and the last error code is ERROR_ACCESS_DENIED.

#### Examples

The following example retrieves the required buffer size, allocates memory for the reason string, retrieves the reason string, and displays the string as debug output.

```cpp
#include <windows.h>

#pragma comment(lib, "User32.lib")

HWND hWnd;

BOOL DisplayShutdownBlockReason()
{
    DWORD cch=0;

    if (ShutdownBlockReasonQuery(hWnd, NULL, &cch))
    {
        WCHAR *pch = (WCHAR *)LocalAlloc(LMEM_FIXED, cch * sizeof(*pch));
        if (NULL != pch)
        {
            if (ShutdownBlockReasonQuery(hWnd, pch, &cch))
            {
                OutputDebugStringW(L"Shutdown block reason: ");
                OutputDebugStringW(pch);
                OutputDebugStringW(L"\n");
            }
            LocalFree(pch);
            return TRUE;
        }
    }
    return FALSE;
}

```

## See also

[ShutdownBlockReasonCreate](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasoncreate)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)