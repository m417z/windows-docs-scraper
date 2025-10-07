# Ctl3dAutoSubclass function

Automatically subclasses and adds 3D effects to all dialog boxes in the application.

## Parameters

*hinstApp*

A handle to the application to be registered as a client.

## Return value

Returns **TRUE** unless one of the following conditions exists, in which case it returns **FALSE**:

- CTL3D is running under Windows version 3.0 or earlier.
- CTL3D does not have space available in its tables for the current application. CTL3D can service up to 32 applications at the same time.
- CTL3D cannot install its CBT hook.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Ctl3d32.dll |

