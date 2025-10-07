# RtlExtendedLargeIntegerDivide function

\[The **RtlExtendedLargeIntegerDivide** function is exported to support existing driver binaries and is obsolete. For better performance, use the compiler support for 64-bit integer operations.\]

Divides extended integers.

## Parameters

*Dividend* \[in\]

Dividend.

*Divisor* \[in\]

Divisor.

*Remainder* \[in, out\]

Pointer to division remainder.

## Return value

Returns the result of the division operation.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

