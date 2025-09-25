## Description

Retrieves a description of the current state of WinHttp's connections.

## Parameters

### `hInternet`

Type: \_In\_ **[HINTERNET](https://learn.microsoft.com/windows/win32/winhttp/hinternet-handles-in-winhttp#about-hinternet-handles)**

A request handle or a connect handle.

If a connect handle, then WinHttp assumes that the host uses HTTPS by default. But you can pass **WINHTTP_QUERY_CONNECTION_GROUP_FLAG_INSECURE** (0x0000000000000001ull) in *ullFlags* to indicate that you want non-HTTPS connections.

### `pGuidConnection`

Type: \_In\_ **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)\***

An optional GUID. If provided, then only connections matching the GUID are returned. Otherwise, the function returns all connections to the host (specified in *hInternet* either by a request handle or a connect handle).

### `ullFlags`

Type: \_In\_ **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags. Pass **WINHTTP_QUERY_CONNECTION_GROUP_FLAG_INSECURE** to indicate that you want non-HTTPS connections (see *hInternet*).

### `ppResult`

Type: \_Inout\_ **[PWINHTTP_QUERY_CONNECTION_GROUP_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_query_connection_group_result)\***

The address of a pointer to a [WINHTTP_QUERY_CONNECTION_GROUP_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_query_connection_group_result), through which the results are returned.

WinHttp performs an allocation internally, so once you're done with it you must free this pointer by calling [WinHttpFreeQueryConnectionGroupResult](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpfreequeryconnectiongroupresult).

## Return value

## Remarks

## See also

* [WINHTTP_QUERY_CONNECTION_GROUP_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_query_connection_group_result)
* [WinHttpFreeQueryConnectionGroupResult](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpfreequeryconnectiongroupresult)