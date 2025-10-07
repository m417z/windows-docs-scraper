# FreeMRUList function

Frees the handle associated with the most recently used (MRU) list and writes cached data to the registry.

## Parameters

*hMRU* \[in\]

Type: **HANDLE**

The handle of the MRU list to free.

## Return value

Type: **int**

Returns a non-negative value if successful, -1 otherwise.

## Remarks

If the MRU list was created using the **MRU\_CACHEWRITE** flag, calling **FreeMRUList** causes any changes not yet written to the version of the MRU list stored in registry to be written at this time.

This function is not included in a public header or library. It must be extracted from comctl32.dll by ordinal 152.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.0 or later) |

