# SHGetPathFromIDListW function

## Description

Converts an item identifier list to a file system path.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

The address of an item identifier list that specifies a file or directory location relative to the root of the namespace (the desktop).

### `pszPath` [out]

Type: **LPTSTR**

The address of a buffer to receive the file system path. This buffer must be at least MAX_PATH characters in size.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

If the location specified by the *pidl* parameter is not part of the file system, this function will fail.

If the *pidl* parameter specifies a shortcut, the *pszPath* will contain the path to the shortcut, not to the shortcut's target.

> [!NOTE]
> The shlobj_core.h header defines SHGetPathFromIDList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SHGetPathFromIDListEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetpathfromidlistex)

[SHParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shparsedisplayname)