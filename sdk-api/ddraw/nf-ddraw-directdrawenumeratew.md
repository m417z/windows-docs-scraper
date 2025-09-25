# DirectDrawEnumerateW function

## Description

This function is superseded by the [DirectDrawEnumerateEx](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawenumerateexa) function.

The **DirectDrawEnumerate** function enumerates the primary DirectDraw display device and a nondisplay device (such as a 3-D accelerator that has no 2-D capabilities), if one is installed. The NULL entry always identifies the primary display device shared with the GDI.

## Parameters

### `lpCallback` [in]

Address of a [DDEnumCallback](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumcallbacka) function to be called with a description of each enumerated DirectDraw-enabled hardware abstraction layer (HAL).

### `lpContext` [in]

Address of an application-defined context to be passed to the enumeration callback function each time that it is called.

## Return value

If the function succeeds, the return value is **DD_OK**.

If it fails, the function returns **DDERR_INVALIDPARAMS**.

## Remarks

You must use [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) to explicitly link to Ddraw.dll and then use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) to access the **DirectDrawEnumerate** function.