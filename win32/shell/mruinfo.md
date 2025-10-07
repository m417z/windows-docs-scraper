# MRUINFO structure

Contains information that defines a new most recently used (MRU) list. Used by [**CreateMRUListW**](https://learn.microsoft.com/windows/win32/shell/createmrulist).

## Members

**cbSize**

Type: **DWORD**

The size of the structure.

**uMax**

Type: **UINT**

The maximum number of entries in the MRU list.

**fFlags**

Type: **UINT**

One or more of the following flags.

**MRU\_BINARY** (0x0001)

Data is stored in the registry as binary data rather than string data.

**MRU\_CACHEWRITE** (0x0002)

Write changes to the version of the MRU stored in the registry only when a new item is added or the MRU list's resources are freed from memory. Note that the active version of the MRU in memory is updated immediately in response to any change in contents or ordering.

**hKey**

Type: **HKEY**

A handle to the currently open key, or one of the following predefined values under which to store the MRU data.

**HKEY\_CURRENT\_USER**

**HKEY\_LOCAL\_MACHINE**

**lpszSubKey**

Type: **LPCTSTR**

The subkey under which to store the MRU data.

**lpfnCompare**

Type: **[**MRUCMPPROC**](https://learn.microsoft.com/windows/win32/shell/mrucmpproc)**

A pointer to an optional data comparison function that can be used to determine whether an item is present in the MRU list. This is useful when the MRU list was created with the **MRU\_BINARY** flag. If this member is **NULL**, standard string comparison functions are used; for binary data, a direct memory comparison is used.

## Remarks

This structure is not defined in a header file. You must define it yourself.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Unicode and ANSI names<br> | **MRUINFOW** (Unicode) and **MRUINFOA** (ANSI)<br> |

