## Description

Represents a collection of connection groups.

## Members

### `pwszHost`

Type: **[PCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A string containing the host name.

### `cConnectionGroups`

Type: **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in *pConnectionGroups*.

### `pConnectionGroups`

Type: **[PWINHTTP_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_connection_group)**

An array of [WINHTTP_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_connection_group) objects.

## Remarks

## See also

* [WINHTTP_QUERY_CONNECTION_GROUP_RESULT](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_query_connection_group_result)
* [WINHTTP_CONNECTION_GROUP](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_connection_group)