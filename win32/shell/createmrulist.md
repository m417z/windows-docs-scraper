# CreateMRUListW function

Creates a new most recently used (MRU) list.

## Parameters

*lpmi* \[in\]

Type: **LPMRUINFO**

A pointer to an [**MRUINFO**](https://learn.microsoft.com/windows/win32/shell/mruinfo) structure defining the MRU list.

## Return value

Type: **int**

Returns a handle to the new MRU list, or 0 in case of an error.

## Remarks

This function is not included in a public header or library. It can be accessed through [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) or extracted from comctl32.dll by its ordinal, which is 400 for **CreateMRUListW**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Comctl32.dll (version 5.0 or later) |
| Unicode and ANSI names<br> | **CreateMRUListW** (Unicode)<br> |

