# InternetUnlockRequestFile function

## Description

Unlocks a file that was locked using
[InternetLockRequestFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetlockrequestfile).

## Parameters

### `hLockRequestInfo` [in]

Handle to a lock request that was returned by
[InternetLockRequestFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetlockrequestfile).

## Return value

Returns TRUE if successful, or FALSE otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)