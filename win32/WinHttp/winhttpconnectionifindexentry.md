# WINHTTP_CONNECTION_IFINDEX_ENTRY structure

Maps a named network connection to its active network interface index.

## Members

### pwszConnectionName

A null-terminated Unicode string containing the network connection name (for example, "Cellular" or "Wi-Fi").

### dwIfIndex

The active network interface index (**IF_INDEX**) associated with this connection.

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WINHTTP_CONNECTION_IFINDEX_LIST](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionifindexlist)
- [WinHttpConnectionUpdateIfIndexTable](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionupdateifindextable)