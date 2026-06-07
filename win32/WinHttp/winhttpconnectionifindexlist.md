# WINHTTP_CONNECTION_IFINDEX_LIST structure

Contains a list of connection-to-interface-index mappings used to update the WinHTTP routing table.

## Members

### pConnectionIfIndexEntries

Pointer to an array of [WINHTTP_CONNECTION_IFINDEX_ENTRY](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionifindexentry) structures, each mapping a connection name to an interface index.

### nEntries

The number of entries in the **pConnectionIfIndexEntries** array. Set to 0 to clear all connection-interface mappings.

## Remarks

> [!NOTE]
> This type is not currently included in an SDK header file. You must declare it yourself in your code.

## Requirements

| Requirement | Value |
|---|---|
| Header | N/A |

## See also

- [WINHTTP_CONNECTION_IFINDEX_ENTRY](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionifindexentry)
- [WinHttpConnectionUpdateIfIndexTable](https://learn.microsoft.com/windows/win32/winhttp/winhttpconnectionupdateifindextable)