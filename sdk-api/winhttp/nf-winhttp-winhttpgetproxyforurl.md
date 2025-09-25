# WinHttpGetProxyForUrl function

## Description

The **WinHttpGetProxyForUrl** function retrieves the proxy data for the specified URL.

## Parameters

### `hSession` [in]

The WinHTTP session handle returned by the [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen) function.

### `lpcwszUrl` [in]

A pointer to a null-terminated Unicode string that contains the URL of the HTTP request that the application is preparing to send.

### `pAutoProxyOptions` [in]

A pointer to a [WINHTTP_AUTOPROXY_OPTIONS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_autoproxy_options) structure that specifies the auto-proxy options to use.

### `pProxyInfo` [out]

A pointer to a [WINHTTP_PROXY_INFO](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_proxy_info) structure that receives the proxy setting. This structure is then applied to the request handle using the WINHTTP_OPTION_PROXY option. Free the **lpszProxy** and **lpszProxyBypass** strings contained in this structure (if they are non-NULL) using the [GlobalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalfree) function.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error data, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

 Possible error codes include the folllowing.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR** | Returned by [WinHttpGetProxyForUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) when a proxy for the specified URL cannot be located. |
| **ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT** | An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_LOGIN_FAILURE** | The login attempt failed. When this error is encountered, close the request handle with [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle). A new request handle must be created before retrying the function that originally produced this error. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT** | The PAC file could not be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL of the PAC file specified a scheme other than "http:" or "https:". |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

This function implements the Web Proxy Auto-Discovery (WPAD) protocol for automatically configuring the proxy settings for an HTTP request. The WPAD protocol downloads a Proxy Auto-Configuration (PAC) file, which is a script that identifies the proxy server to use for a given target URL. PAC files are typically deployed by the IT department within a corporate network environment. The URL of the PAC file can either be specified explicitly or **WinHttpGetProxyForUrl** can be instructed to automatically discover the location of the PAC file on the local network.

**WinHttpGetProxyForUrl** supports only ECMAScript-based PAC files.

**WinHttpGetProxyForUrl** must be called on a per-URL basis, because the PAC file can return a different proxy server for different URLs. This is useful because the PAC file enables an IT department to implement proxy server load balancing by mapping (hashing) the target URL (specified by the *lpcwszUrl* parameter) to a certain proxy in a proxy server array.

**WinHttpGetProxyForUrl** caches the autoproxy URL and the autoproxy script when auto-discovery is specified in the **dwFlags** member of the *pAutoProxyOptions* structure. For more information, see [Autoproxy Cache](https://learn.microsoft.com/windows/desktop/WinHttp/autoproxy-cache).

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-versions)