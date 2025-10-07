# Ctl3dUnregister function

Unregisters an application as a client of CTL3D.

## Parameters

*hinstApp*

A handle to the application to be unregistered as a client.

## Return value

Returns **TRUE** if the application is unregistered as a client of CTL3D; otherwise, it returns **FALSE**.

## Remarks

An application that uses CTL3D should call this function in WinMain.

3D effects are not available on systems that have less than VGA resolution.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

