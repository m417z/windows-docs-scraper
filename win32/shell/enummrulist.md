# EnumMRUListW function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. \]

Enumerates the contents of the most recently used (MRU) list. Optionally retrieves an item from the enumeration.

## Parameters

*hMRU* \[in\]

Type: **HANDLE**

The handle of the MRU list, obtained when the list was created.

*nItem* \[in\]

Type: **int**

The item to return. If this value is less than 0, the function returns the number of items in the MRU list.

*lpData* \[out\]

Type: **void\***

A pointer to a buffer that receives the item requested in *nItem*. If *nItem* is less than 0, the contents of this buffer are unchanged.

*uLen* \[in\]

Type: **UINT**

The size of the buffer, including the terminating null character. If the MRU list was created with the **MRU\_BINARY** flag, this is the size in bytes. Otherwise, it is the size in characters.

## Return value

Type: **int**

Returns one of the following values.

- Returns the number of items in the enumeration, if *nItem* is less than 0.
- Returns -1 if an error occurred.
- Otherwise, returns the size of the string returned in *lpData*, including the terminating null character. If the MRU list was created with the **MRU\_BINARY** flag, this is the size in bytes. Otherwise, it is the size in characters.

## Remarks

This function is not included in a public header or library. It can be accessed through [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) or extracted from comctl32.dll by its ordinal, which is 403 for **EnumMRUListW**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **EnumMRUListW** (Unicode)<br> |

## See also

[**CreateMRUListW**](https://learn.microsoft.com/windows/win32/shell/createmrulist)

[**MRUINFO**](https://learn.microsoft.com/windows/win32/shell/mruinfo)

