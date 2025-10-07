# AuxKlibInitialize function

Initializes the Aux\_klib library. This function must be called before any other function in the library can be called.

## Parameters

This function has no parameters.

## Return value

If the function succeeds, the return value is STATUS\_SUCCESS.

If the function fails, the return value can be one of the status codes defined in Ntstatus.h, which is available in the WDK.

## Remarks

The object library that implements this API can be downloaded from [here](https://www.microsoft.com/?ref=go).

## Requirements

| Requirement | Value |
|----------------------------|------------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Auxiliary API library version 1.0 or later<br> |
| Header<br> | Aux\_klib.h |
| Library<br> | Aux\_klib.lib |

## See also

[**AuxKlibQueryModuleInformation**](https://learn.microsoft.com/windows/win32/devnotes/auxklibquerymoduleinformation-func)

