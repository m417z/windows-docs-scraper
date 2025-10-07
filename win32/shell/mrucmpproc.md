# MRUCMPPROC callback function

Used to determine whether an item is present in a most recently used (MRU) list.

## Parameters

*pString1*

Type: **LPCTSTR**

The first string.

*pString2*

Type: **LPCTSTR**

A second string to compare to the first.

## Return value

Type: **int**

Returns 0 if the items are identical, a nonzero value otherwise.

## Remarks

This function can be optionally specified for use in the [**MRUINFO**](https://learn.microsoft.com/windows/win32/shell/mruinfo) structure passed to [**CreateMRUListW**](https://learn.microsoft.com/windows/win32/shell/createmrulist). This is useful when the MRU list was created with the **MRU\_BINARY** flag. When this function is not specified, standard string comparison functions are used.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Unicode and ANSI names<br> | **MRUCMPPROCW** (Unicode) and **MRUCMPPROCA** (ANSI)<br> |

