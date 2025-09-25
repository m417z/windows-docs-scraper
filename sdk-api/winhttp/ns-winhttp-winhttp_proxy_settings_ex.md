## Description

Represents extended proxy settings.

## Members

### `ullGenerationId`

Type: **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The current network generation (incremented each time the configuration is changed).

### `ullFlags`

Type: **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags for the proxy settings (for example, **WINHTTP_PROXY_TYPE_DIRECT**).

### `pcwszAutoconfigUrl`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The PAC URL for the network (for example, L"http://proxy.contoso.com/wpad.dat").

### `pcwszProxy`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The proxy address and port for HTTP traffic (for example, L"http://192.168.1.1:8888").

### `pcwszSecureProxy`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The proxy address and port for HTTPS traffic (for example, L"http://192.168.1.1:8888").

### `cProxyBypasses`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of entries in the proxy bypass list (*rgpcwszProxyBypasses*).

### `rgpcwszProxyBypasses`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

An array of strings containing each site in the proxy bypass list. (for example, L"contoso.com").

### `dwInterfaceIndex`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The interface index for which settings were retrieved.

### `pcwszConnectionName`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The WCM connection name for which settings were retrieved.

## Remarks

## See also