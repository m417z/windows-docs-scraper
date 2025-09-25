# SHGetPathFromIDListEx function

## Description

Converts an item identifier list to a file system path. This function extends [SHGetPathFromIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetpathfromidlista) by allowing you to set the initial size of the string buffer and declare the options below.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to an item identifier list that specifies a file or directory location relative to the root of the namespace (the desktop).

### `pszPath` [out]

Type: **PWSTR**

When this function is called it is passed a null-terminated, Unicode buffer to receive the file system path. This buffer is of size *cchPath*.

When this function returns, contains the address of a null-terminated, Unicode buffer that contains the file system path. This buffer is of size *cchPath*.

### `cchPath`

Type: **DWORD**

The size of the buffer pointed to by *pszPath*, in characters.

### `uOpts`

Type: **GPFIDL_FLAGS**

These flags determine the type of path returned.

#### GPFIDL_DEFAULT (0x0000)

Win32 file names, servers, and root drives are included.

#### GPFIDL_ALTNAME (0x0001)

Uses short file names.

#### GPFIDL_UNCPRINTER (0x0002)

Include UNC printer names items.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

Except for UNC printer names, if the location specified by the *pidl* parameter is not part of the file system, this function fails.

If the *pidl* parameter specifies a shortcut, the *pszPath* contains the path to the shortcut, not to the shortcut's target.

## See also

[SHParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shparsedisplayname)