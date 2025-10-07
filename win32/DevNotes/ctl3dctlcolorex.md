# Ctl3dCtlColorEx function

Handles the **WM\_CTLCOLOR** message for applications that use CTL3D.

## Parameters

*wm*

The **WM\_CTLCOLOR** message for the application.

*wParam*

A handle to the display context (DC).

*lParam*

A handle to a child window (control).

## Return value

Returns a handle to the appropriate brush if the function succeeds; otherwise, it returns `(HBRUSH)(0)` indicating that an error occurred.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

