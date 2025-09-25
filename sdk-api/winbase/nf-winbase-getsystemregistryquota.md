# GetSystemRegistryQuota function

## Description

Retrieves the current size of the registry and the maximum size that the registry is allowed to attain on the system.

## Parameters

### `pdwQuotaAllowed` [out, optional]

A pointer to a variable that receives the maximum size that the registry is allowed to attain on this system, in bytes.

### `pdwQuotaUsed` [out, optional]

A pointer to a variable that receives the current size of the registry, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)