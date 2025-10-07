# IsWindowRedirectedForPrint function

The **IsWindowRedirectedForPrint** function determines whether the specified window is currently redirected for printing.

## Parameters

*hWnd* \[in\]

The handle of the window.

## Return value

If the window is currently redirected for printing, the function returns a nonzero value; otherwise, it returns zero.

## Remarks

A window is redirected for printing when it processes a call to [**PrintWindow**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-printwindow). In a call to **PrintWindow**, a window renders its content to an off-screen device context.

This function has no associated import library or header file; you must call it by using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | User32.dll |

## See also

[**PrintWindow**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-printwindow)

[**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[**WM\_PRINT**](https://learn.microsoft.com/windows/desktop/gdi/wm-print)

[**WM\_PRINTCLIENT**](https://learn.microsoft.com/windows/desktop/gdi/wm-printclient)

