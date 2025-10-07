# SeciFreeCallContext function

The **SeciFreeCallContext** function frees the memory allocated by [SeciAllocateAndSetIPAddress](https://learn.microsoft.com/windows/win32/secauthn/SeciAllocateAndSetIPAddress).

## Remarks

This function is not present in the SDK headers. To use it, call the [LoadLibrary](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to obtain a handle to `SSPICLI.DLL` and then use [GetProcAddress](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) to obtain the function address.

Call this function if [SeciAllocateAndSetIPAddress](https://learn.microsoft.com/windows/win32/secauthn/SeciAllocateAndSetIPAddress) sets `FreeCallContext` to `TRUE`.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows Vista \[desktop apps \| UWP apps\] |
| Minimum supported server | Windows Server 2008 \[desktop apps \| UWP apps\] |
| Target platform | Windows |
| Header | None |
| Library | None |
| DLL | SSPICLI.DLL |

## See also

[SeciAllocateAndSetIPAddress](https://learn.microsoft.com/windows/win32/secauthn/SeciAllocateAndSetIPAddress)