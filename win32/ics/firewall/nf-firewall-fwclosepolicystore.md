# FWClosePolicyStore function

Receives an opened store handle, closes it, and deallocates the corresponding policy store connection object.

See **Remarks** for info about how to call the function.

## Parameters

`hPolicyStore`

An opened policy store **HANDLE** that was successfully opened by using the [FWOpenPolicyStore](https://learn.microsoft.com/windows/win32/ics/firewall/nf-firewall-fwopenpolicystore) function. The handle must have read/write access rights.

## Return value

0 if successful. If it fails, it returns a nonzero error code, as specified in [MS-ERREF](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/1bc92ddf-b79e-413c-bbaa-99a5281a6c90).

## Remarks

This function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`FirewallAPI.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11, version 23H2 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | FirewallAPI.dll |

## See also

* [Windows Firewall with Advanced Security enums and structs](https://learn.microsoft.com/windows/win32/ics/firewall-enums-structs)