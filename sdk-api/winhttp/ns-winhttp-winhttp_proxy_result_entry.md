# WINHTTP_PROXY_RESULT_ENTRY structure

## Description

The **WINHTTP_PROXY_RESULT_ENTRY** structure contains a result entry from a call to [WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult).

## Members

### `fProxy`

A **BOOL** that whether a result is from a proxy. It is set to **TRUE** if the result contains a proxy or **FALSE** if the result does not contain a proxy.

### `fBypass`

A BOOL that indicates if the result is bypassing a proxy (on an intranet). It is set to **TRUE** if the result is bypassing a proxy or **FALSE** if all traffic is direct. This parameter applies only if *fProxy* is **FALSE**.

### `ProxyScheme`

An [INTERNET_SCHEME](https://learn.microsoft.com/windows/desktop/WinHttp/internet-scheme) value that specifies the scheme of the proxy.

### `pwszProxy`

A string that contains the hostname of the proxy.

### `ProxyPort`

An [INTERNET_PORT](https://learn.microsoft.com/windows/desktop/WinHttp/internet-port) value that specifies the port of the proxy.

## Remarks

This structure is stored in an array inside of a [WINHTTP_PROXY_RESULT](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result) structure.

## See also

[WINHTTP_PROXY_RESULT](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result)

[WinHttpFreeProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpfreeproxyresult)

[WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult)