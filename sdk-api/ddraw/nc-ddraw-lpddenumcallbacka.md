# LPDDENUMCALLBACKA callback function

## Description

The *DDEnumCallback* function is an application-defined callback function for the [DirectDrawEnumerate](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawenumeratew) function.

## Parameters

### `unnamedParam1`

A pointer to the unique identifier of the DirectDraw object.

### `unnamedParam2`

Address of a string that contains the driver name.

### `unnamedParam3`

Address of a string that contains the driver description.

### `unnamedParam4`

A pointer to an application-defined structure to be passed to the callback function each time the function is called.

## Return value

The callback function returns nonzero to continue the enumeration.

It returns zero to stop the enumeration.

## Remarks

You can use the LPDDENUMCALLBACK data type to declare a variable that can contain a pointer to this callback function.

If UNICODE is defined, the string values are returned as type LPWSTR, rather than LPSTR.

> [!NOTE]
> The ddraw.h header defines LPDDENUMCALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).