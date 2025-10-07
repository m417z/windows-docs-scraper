# Ctl3dColorChange function

Handles system color changes for applications that use CTL3D.

## Parameters

This function has no parameters.

## Return value

Returns **TRUE** if the function succeeds; otherwise, it returns **FALSE**.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

This function should be called in the application's main window procedure for the **WM\_SYSCOLORCHANGE** message, as shown below.

## Examples

``` syntax
case WM_SYSCOLORCHANGE:
   Ctl3dColorChange();
   break;
```

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

