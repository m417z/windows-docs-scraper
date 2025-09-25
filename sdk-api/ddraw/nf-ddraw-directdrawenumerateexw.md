# DirectDrawEnumerateExW function

## Description

Enumerates all DirectDraw devices that are installed on the computer. The NULL entry always identifies the primary display device that is shared with GDI.

## Parameters

### `lpCallback` [in]

Address of a [DDEnumCallbackEx](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumcallbackexa) function to be called with a description of each enumerated DirectDraw-enabled hardware abstraction layer (HAL).

### `lpContext` [in]

Address of an application-defined value to be passed to the enumeration callback function each time that it is called.

### `dwFlags` [in]

Flags that specify the enumeration scope. This parameter can be 0 or a combination of the following flags. If the value is 0, the function enumerates only the primary display device.

#### DDENUM_ATTACHEDSECONDARYDEVICES

The function enumerates the primary device and any display devices that are attached to the desktop.

#### DDENUM_DETACHEDSECONDARYDEVICES

The function enumerates the primary device and any display devices that are not attached to the desktop.

#### DDENUM_NONDISPLAYDEVICES

The function enumerates the primary device and any nondisplay devices, such as 3-D accelerators that have no 2-D capabilities.

##### - dwFlags.DDENUM_ATTACHEDSECONDARYDEVICES

The function enumerates the primary device and any display devices that are attached to the desktop.

##### - dwFlags.DDENUM_DETACHEDSECONDARYDEVICES

The function enumerates the primary device and any display devices that are not attached to the desktop.

##### - dwFlags.DDENUM_NONDISPLAYDEVICES

The function enumerates the primary device and any nondisplay devices, such as 3-D accelerators that have no 2-D capabilities.

## Return value

If the function succeeds, the return value is **DD_OK**.

If it fails, the function returns **DDERR_INVALIDPARAMS**.

## Remarks

On computers with multiple monitors, **DirectDrawEnumerateEx** enumerates multiple display devices.

You must use [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) to explicitly link to Ddraw.dll. To retrieve the address of the **DirectDrawEnumerateEx** function, call the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) Win32 function with the "DirectDrawEnumerateExA" (ANSI) or "DirectDrawEnumerateExW" (Unicode) process name strings.

> [!NOTE]
> The ddraw.h header defines DirectDrawEnumerateEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).