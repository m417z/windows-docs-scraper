# RtlExtendedIntegerMultiply function

\[The **RtlExtendedIntegerMultiply** function is exported to support existing driver binaries and is obsolete. For better performance, use the compiler support for 64-bit integer operations.\]

Multiplies extended integers.

## Parameters

*Multiplicand* \[in\]

Multiplicand.

*Multiplier* \[in\]

Multiplier.

## Return value

Returns multiplication result.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|--------------------------------------------------------------------------------------|
| DLL<br> | Ntdll.dll |

