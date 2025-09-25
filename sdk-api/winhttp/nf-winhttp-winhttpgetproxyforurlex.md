# WinHttpGetProxyForUrlEx function

## Description

The **WinHttpGetProxyForUrlEx** function retrieves the proxy data for the specified URL.

## Parameters

### `hResolver` [in]

The WinHTTP resolver handle returned by the [WinHttpCreateProxyResolver](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateproxyresolver) function.

### `pcwszUrl` [in]

A pointer to a null-terminated Unicode string that contains a URL for which proxy information will be determined.

### `pAutoProxyOptions` [in]

A pointer to a [WINHTTP_AUTOPROXY_OPTIONS](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_autoproxy_options) structure that specifies the auto-proxy options to use.

### `pContext` [in]

Context data that will be passed to the completion callback function.

## Return value

A status code indicating the result of the operation.

| The following codes may be returned. | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The operation is continuing asynchronously. |
| **ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR** | Returned by [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex) when a proxy for the specified URL cannot be located. |
| **ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT** | An error occurred executing the script code in the Proxy Auto-Configuration (PAC) file. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INVALID_URL** | The URL is invalid. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was canceled, usually because the handle on which the request was operating was closed before the operation completed. |
| **ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT** | The PAC file could not be downloaded. For example, the server referenced by the PAC URL may not have been reachable, or the server returned a 404 NOT FOUND response. |
| **ERROR_WINHTTP_UNRECOGNIZED_SCHEME** | The URL of the PAC file specified a scheme other than "http:" or "https:". |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. (Windows error code) |

## Remarks

This function implements the Web Proxy Auto-Discovery (WPAD) protocol for automatically configuring the proxy settings for an HTTP request. The WPAD protocol downloads a Proxy Auto-Configuration (PAC) file, which is a script that identifies the proxy server to use for a given target URL. PAC files are typically deployed by the IT department within a corporate network environment. The URL of the PAC file can either be specified explicitly or **WinHttpGetProxyForUrlEx** can be instructed to automatically discover the location of the PAC file on the local network.

**WinHttpGetProxyForUrlEx** supports only ECMAScript-based PAC files.

**WinHttpGetProxyForUrlEx** must be called on a per-URL basis, because the PAC file can return a different proxy server for different URLs. This is useful because the PAC file enables an IT department to implement proxy server load balancing by mapping (hashing) the target URL (specified by the *lpcwszUrl* parameter) to a certain proxy in a proxy server array.

**WinHttpGetProxyForUrlEx** caches the autoproxy URL and the autoproxy script when auto-discovery is specified in the **dwFlags** member of the *pAutoProxyOptions* structure. For more information, see [Autoproxy Cache](https://learn.microsoft.com/windows/desktop/WinHttp/autoproxy-cache).

**WinHttpGetProxyForUrlEx** provides a fully Asynchronous and cancellable API that [WinHttpGetProxyForUrl](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurl) does not. **WinHttpGetProxyForUrlEx** also provides the application with the full proxy list that was returned by the PAC script allowing the application to better handle failover to "DIRECT" and to understand SOCKS if desired.

**WinHttpGetProxyForUrlEx** always executes asynchronously and returns immediately with **ERROR_IO_PENDING** on success. The callback is set by calling [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback) on the *hSession* provided by [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen). Alternately call **WinHttpSetStatusCallback** on the *hResolver* provided by [WinHttpCreateProxyResolver](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateproxyresolver) to have a specific callback for each call.

You must call [WinHttpSetStatusCallback](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetstatuscallback) before [WinHttpCreateProxyResolver](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpcreateproxyresolver). When calling **WinHttpSetStatusCallback**, use **WINHTTP_CALLBACK_FLAG_REQUEST_ERROR |
WINHTTP_CALLBACK_FLAG_GETPROXYFORURL_COMPLETE**. See [WINHTTP_STATUS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winhttp/nc-winhttp-winhttp_status_callback) for information on the use of the callback.

Once a callback of status **WINHTTP_CALLBACK_STATUS_GETPROXYFORURL_COMPLETE** is returned, the application can call [WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult) on the resolver handle used to issue **WinHttpGetProxyForUrlEx** to receive the results of that call.

If the call fails after returning **ERROR_IO_PENDING** then a callback of **WINHTTP_CALLBACK_STATUS_REQUEST_ERROR** will be issued.

This function always executes out-of-process.