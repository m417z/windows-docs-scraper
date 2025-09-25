## Description

Represents the GUID of a connection, for purposes of connection-matching.

See the option flag [**WINHTTP_OPTION_MATCH_CONNECTION_GUID**](https://learn.microsoft.com/windows/win32/winhttp/option-flags). That option takes as input a **WINHTTP_MATCH_CONNECTION_GUID** value.

## Members

### `ConnectionGuid`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**

A connection's **GUID**.

When **WINHTTP_OPTION_MATCH_CONNECTION_GUID** is set on a request, WinHttp attempts to serve the request on a connection matching *ConnectionGuid*.

### `ullFlags`

Type: **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags.

Due to the nature of connection-matching logic, it's possible for an unmarked connection to be assigned to serve the request (if one is encountered before a matching marked connection is). Set *ullFlags* to **WINHTTP_MATCH_CONNECTION_GUID_FLAG_REQUIRE_MARKED_CONNECTION** if you don't want an unmarked connection to be matched. When using that flag, if no matching marked connection is found, then a new connection is created, and the request is sent on that connection.

## Remarks

## See also