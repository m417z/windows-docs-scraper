# AuxKlibQueryModuleInformation function

Retrieves information about the currently loaded set of modules for the system.

## Parameters

*BufferSize* \[in, out\]

On input, the size of the *QueryInfo* buffer, in bytes. On output, receives the actual required size. Because the system module list can change between calls, this value can also change between calls.

*ElementSize* \[in\]

The size, in bytes, of an array element. This size determines the format of the output.

*QueryInfo* \[out, optional\]

A pointer to a buffer that receives the module information. This information is returned in an array whose elements are one of the following structures: [**AUX\_MODULE\_BASIC\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-basic-info-struct) or [**AUX\_MODULE\_EXTENDED\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-extended-info-struct). The specific structure used depends on the specified element size.

If this parameter is **NULL**, the function returns the required buffer size.

## Return value

If the function succeeds, the return value is STATUS\_SUCCESS.

If the function fails, the return value can be one of the status codes defined in Ntstatus.h, which is available in the WDK.

## Remarks

You must call the [**AuxKlibInitialize**](https://learn.microsoft.com/windows/win32/devnotes/auxklibinitialize-func) function before calling this function.

The object library that implements this API can be downloaded from [here](https://www.microsoft.com/?ref=go).

## Requirements

| Requirement | Value |
|----------------------------|------------------------------------------------------------------------------------------|
| Redistributable<br> | Windows Auxiliary API library version 1.0 or later<br> |
| Header<br> | Aux\_klib.h |
| Library<br> | Aux\_klib.lib |

## See also

[**AuxKlibInitialize**](https://learn.microsoft.com/windows/win32/devnotes/auxklibinitialize-func)

[**AUX\_MODULE\_BASIC\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-basic-info-struct)

[**AUX\_MODULE\_EXTENDED\_INFO**](https://learn.microsoft.com/windows/win32/devnotes/aux-module-extended-info-struct)

