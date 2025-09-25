# WTSEnumerateServersW function

## Description

Returns
a list of all Remote Desktop Session Host (RD Session Host) servers within the specified domain.

## Parameters

### `pDomainName` [in]

Pointer to the name of the domain to be queried. If the value of this parameter is
**NULL**, the specified domain is the current domain.

### `Reserved` [in]

Reserved. The value of this parameter must be 0.

### `Version` [in]

Version of the enumeration request. The value of the parameter must be 1.

### `ppServerInfo`

Points to an array of [WTS_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_server_infoa)
structures, which contains the returned results of the enumeration. After use, the memory used by this buffer
should be freed by calling [WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory).

### `pCount`

Pointer to a variable that receives the number of
[WTS_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_server_infoa) structures returned in the
*ppServerInfo* buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

 If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function will not work if NetBT is disabled.

> [!NOTE]
> The wtsapi32.h header defines WTSEnumerateServers as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WTS_SERVER_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_server_infoa)