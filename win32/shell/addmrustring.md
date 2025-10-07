# AddMRUStringW function

\[This function is available through Windows XP with Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. \]

Adds a string to the top of the most recently used (MRU) list.

## Parameters

*hMRU* \[in\]

Type: **HANDLE**

The handle of the MRU list.

*szString* \[in\]

Type: **LPCTSTR**

A pointer to the data. This can be either a string or, if the MRU list was created with the **MRU\_BINARY** flag, binary data. In the case of binary data, the first **DWORD** indicates its size.

## Return value

Type: **int**

Returns a non-negative value if successful, -1 otherwise.

## Remarks

This function is not included in a public header or library. It can be accessed through [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) or extracted from comctl32.dll by its ordinal, which is 401 for **AddMRUStringW**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **AddMRUStringW** (Unicode)<br> |

