# Str_SetPtrW function

## Description

Sets *ppszCurrent* to a copy of *pszNew* and frees the previous value, if necessary.

## Parameters

### `ppsz` [in, out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The address of a pointer to the current string. The current string is freed and the pointer is set to a copy of *pszNew*.

### `psz`

Type: **[LPCTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the string to copy into *ppszCurrent*.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

The ANSI version of **Str_SetPtrW**, **Str_SetPtrA**, is not exported by name or declared in a public header file. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 234 from ComCtl32.dll to obtain a function pointer.