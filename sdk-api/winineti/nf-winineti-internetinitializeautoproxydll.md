# InternetInitializeAutoProxyDll function

## Description

There are two WinINet functions named **InternetInitializeAutoProxyDll**. The first, which merely refreshes the internal state of proxy configuration information from the registry, has a single parameter as documented directly below.

The second function, prototyped as **pfnInternetInitializeAutoProxyDll**, is part of WinINet's limited autoproxy support, and must be called by dynamically linking to "JSProxy.dll". For autoproxy support, use Windows HTTP Services (WinHTTP) version 5.1. For more information, see [WinHTTP AutoProxy Support](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-autoproxy-support).

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because the **InternetInitializeAutoProxyDll** function takes time to complete its operation, it should not be called from a UI thread.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[DetectAutoProxyUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-detectautoproxyurl)

[InternetDeInitializeAutoProxyDll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa384580(v=vs.85))

[InternetGetProxyInfo](https://learn.microsoft.com/windows/desktop/WinInet/internetgetproxyinfo)

[WinHTTP AutoProxy Support](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-autoproxy-support)