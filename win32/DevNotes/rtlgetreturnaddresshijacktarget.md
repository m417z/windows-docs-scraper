# RtlGetReturnAddressHijackTarget function

Gets the address of the function that's used for the OS-supported return address hijacking. When user-mode wants to perform such a hijack, it overwrites a return address on the stack with said address.

## Parameters

None.

## Return value

The address that's used to perform an OS-supported return address hijack.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------|
| Minimum supported client | Windows 10 Build 19041 |
| DLL | Ntdll.dll |

## See also

