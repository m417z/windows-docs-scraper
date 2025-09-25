## Description

Represents a description of the current state of WinHttp's connections. Retrieved via [WinHttpQueryConnectionGroup](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpqueryconnectiongroup).

## Members

### `cHosts`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in *pHostConnectionGroups*.

### `pHostConnectionGroups`

Type: **[PWINHTTP_HOST_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_host_connection_group)**

An array of [WINHTTP_HOST_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_host_connection_group) objects.

## Remarks

## See also

* [WinHttpQueryConnectionGroup](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpqueryconnectiongroup)
* [WINHTTP_HOST_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_host_connection_group)