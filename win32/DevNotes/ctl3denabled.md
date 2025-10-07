# Ctl3dEnabled function

Verifies whether controls can use 3D effects.

## Parameters

This function has no parameters.

## Return value

Returns **TRUE** if controls can use 3D effects; otherwise, it returns **FALSE**.

## Remarks

In Windows 4.0 or later, **Ctl3dEnabled** and [**Ctl3dRegister**](https://learn.microsoft.com/windows/win32/devnotes/ctl3dregister) return **FALSE**.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

