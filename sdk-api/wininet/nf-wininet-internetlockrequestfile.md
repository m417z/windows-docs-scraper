# InternetLockRequestFile function

## Description

Places a lock on the file that is being used.

## Parameters

### `hInternet` [in]

Handle returned by
the [FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea),
[GopherOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopheropenfilea),
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta), or
[InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla) function.

### `lphLockRequestInfo` [out]

Pointer to a handle that receives the lock request handle.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handle passed to
*hInternet* was created using
[INTERNET_FLAG_NO_CACHE_WRITE](https://learn.microsoft.com/windows/desktop/WinInet/api-flags) or
[INTERNET_FLAG_DONT_CACHE](https://learn.microsoft.com/windows/desktop/WinInet/api-flags), the function creates a temporary file with the extension .tmp, unless it is an HTTPS resource. If the handle was created using **INTERNET_FLAG_NO_CACHE_WRITE** or **INTERNET_FLAG_DONT_CACHE** and it is accessing an HTTPS resource,
**InternetLockRequestFile** fails.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[InternetUnlockRequestFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetunlockrequestfile)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)