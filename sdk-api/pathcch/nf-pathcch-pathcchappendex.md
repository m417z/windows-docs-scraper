# PathCchAppendEx function

## Description

Appends one path to the end of another.

This function differs from [PathCchAppend](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappend) in that it allows for a longer final path to be constructed.

This function differs from [PathAppend](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, or [PathCchAppend](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappend), should be used in place of [PathAppend](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to a buffer that, on entry, contains the original path. When this function returns successfully, the buffer contains the original path plus the appended path.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

### `pszMore` [in, optional]

A pointer the path to append to the end of the path pointed to by *pszPath*. UNC paths and paths that begin with the sequence \\?\ are accepted and recognized as fully-qualified paths. These paths replace the string pointed to by *pszPath* instead of being appended to it.

### `dwFlags` [in]

One or more of the following flags:

| Value | Meaning |
| --- | --- |
| **PATHCCH_NONE**<br><br>0x0000000 | Do not allow for the construction of \\?\ paths (ie, long paths) longer than **MAX_PATH**. |
| **PATHCCH_ALLOW_LONG_PATHS**<br><br>0x00000001 | Allow the building of \\?\ paths longer than **MAX_PATH**. |
| **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**<br><br>0x00000002 | Forces the API to treat the caller as long path enabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**. <br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**<br><br>0x00000004 | Forces the API to treat the caller as long path disabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**<br><br>0x00000008 | Disables the normalization of path segments that includes removing trailing dots and spaces. This enables access to paths that win32 path normalization will block.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH**<br><br>0x00000010 | Converts the input path into the extended length DOS device path form (with the \\?\ prefix) if not already in that form. This enables access to paths that are otherwise not addressable due to Win32 normalization rules (that can strip trailing dots and spaces) and path length limitations. This option implies the same behavior of **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** code, including the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Either *pszPath* or *pszMore* is **NULL**, *cchPath* is 0, or *cchPath* is greater than **PATHCCH_MAX_CCH**. |
| **PATHCCH_E_FILENAME_TOO_LONG** | The resulting string would exceed **PATHCCH_MAX_CCH**. |
| **E_OUTOFMEMORY** | The function could not allocate a buffer of the necessary size. |

## Remarks

This function inserts a backslash between the two strings, if one is not already present.

## See also

[PathCchAppend](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappend)