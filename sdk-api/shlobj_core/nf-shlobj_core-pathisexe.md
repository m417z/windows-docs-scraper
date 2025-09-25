# PathIsExe function

## Description

[**PathIsExe** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Determines whether a file is an executable by examining the file name extension.

## Parameters

### `pszPath` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string that contains the file path, which includes the name of the file.

## Return value

Type: **BOOL**

Returns **TRUE** if the file name extension is .cmd, .bat, .pif, .scf, .exe, .com, or .scr; otherwise, **FALSE**.