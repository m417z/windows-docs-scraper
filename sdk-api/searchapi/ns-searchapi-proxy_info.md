# PROXY_INFO structure

## Description

Stores information about a proxy. Used by [ISearchProtocol](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchprotocol).

## Members

### `dwSize`

Type: **DWORD**

The size of the structure in bytes.

### `pcwszUserAgent`

Type: **LPCWSTR**

A pointer to a Unicode string buffer containing the user agent string.

### `paUseProxy`

Type: **[PROXY_ACCESS](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-proxy_access)**

The proxy type to use.

### `fLocalBypass`

Type: **BOOL**

The bypass proxy for local addresses.

### `dwPortNumber`

Type: **DWORD**

The port number to use.

### `pcwszProxyName`

Type: **LPCWSTR**

A pointer to a Unicode string buffer that contains the name of the proxy server.

### `pcwszBypassList`

Type: **LPCWSTR**

The list of sites that will bypass the proxy.