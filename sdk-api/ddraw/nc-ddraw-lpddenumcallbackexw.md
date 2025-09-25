## Description

The *DDEnumCallbackEx* function is an application-defined callback function for the [DirectDrawEnumerateEx](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawenumerateexa) function.

## Parameters

### `unnamedParam1`

A pointer to the unique identifier of the DirectDraw object.

### `unnamedParam2`

Address of a string that contains the driver name.

### `unnamedParam3`

Address of a string that contains the driver description.

### `unnamedParam4`

A pointer to an application-defined structure to be passed to the callback function each time that the function is called.

### `unnamedParam5`

Handle of the monitor that is associated with the enumerated DirectDraw object. This parameter is NULL when the enumerated DirectDraw object is for the primary device, a nondisplay device (such as a 3-D accelerator with no 2-D capabilities), or devices not attached to the desktop.

## Return value

The callback function returns nonzero to continue the enumeration.

It returns zero to stop the enumeration.

## Remarks

After the [DirectDrawEnumerateEx](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawenumerateexa) function completes, the pointer to the GUID at *lpGUID* is no longer valid. You must save a copy of the GUID structure itself, not the pointer, or the [DirectDrawCreateEx](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawcreateex) function fails.

You can use the LPDDENUMCALLBACKEX data type to declare a variable that can contain a pointer to this callback function.

If UNICODE is defined, the string values are returned as type LPWSTR, rather than LPSTR.

> [!NOTE]
> The ddraw.h header defines LPDDENUMCALLBACKEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).