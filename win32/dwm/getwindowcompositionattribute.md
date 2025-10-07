# GetWindowCompositionAttribute function

Retrieves the current value of a specified Desktop Window Manager (DWM) attribute applied to a window.

## Parameters

`hwnd`

An [**HWND**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types) specifying the handle to the window for which the attribute value is to be retrieved.

`pwcad`

A pointer to a [WINDOWCOMPOSITIONATTRIBDATA](https://learn.microsoft.com/windows/win32/dwm/windowcompositionattribdata) structure describing which attribute to retrieve and a memory location to hold its value.

## Return value

**TRUE** if the function succeeds; otherwise, **FALSE**.

## Remarks

The use of this API is not recommended. Use [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute) instead.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from user32.dll.

## Requirements

| Requirement | Value |
|-|-|
| Minimum supported client | Windows 7 \[desktop apps only\] |
| Minimum supported server | None supported |
| End of client support | Windows 7 |
| Header | N/A |
| DLL | user32.dll |