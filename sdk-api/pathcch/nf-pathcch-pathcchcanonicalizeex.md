# PathCchCanonicalizeEx function

## Description

Simplifies a path by removing navigation elements such as "." and ".." to produce a direct, well-formed path.

This function differs from [PathCchCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalize) in that it allows for a longer final path to be constructed.

This function differs from [PathAllocCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccanonicalize) in that the caller must declare the size of the returned string, which is stored on the stack.

This function differs from [PathCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, [PathCchCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalize), or [PathAllocCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccanonicalize) should be used in place of [PathCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPathOut` [out]

A pointer to a buffer that, when this function returns successfully, receives the edited path string.

### `cchPathOut` [in]

The size of the buffer pointed to by *pszPathOut*, in characters.

### `pszPathIn` [in]

A pointer to the original path string. If this value is **NULL**, points to an empty string, or results in an empty string once the "." and ".." elements are removed, a single backslash is copied to the buffer pointed to by *pszPathOut*.

### `dwFlags` [in]

One or more of the following flags:

| Value | Meaning |
| --- | --- |
| **PATHCCH_NONE**<br><br>0x0000000 | Do not allow for the construction of \\?\ paths (ie, long paths) longer than **MAX_PATH** . |
| **PATHCCH_ALLOW_LONG_PATHS**<br><br>0x00000001 | Allow the building of \\?\ paths longer than **MAX_PATH** . Note that *cchPathOut* must be greater than **MAX_PATH** . If it is not, this flag is ignored. |
| **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**<br><br>0x00000002 | Forces the API to treat the caller as long path enabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**<br><br>0x00000004 | Forces the API to treat the caller as long path disabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**<br><br>0x00000008 | Disables the normalization of path segments that includes removing trailing dots and spaces. This enables access to paths that win32 path normalization will block.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH**<br><br>0x00000010 | Converts the input path into the extended length DOS device path form (with the \\?\ prefix) if not already in that form. This enables access to paths that are otherwise not addressable due to Win32 normalization rules (that can strip trailing dots and spaces) and path length limitations. This option implies the same behavior of **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_TRAILING_SLASH**<br><br>0x00000020 | When combining or normalizing a path, ensure there is a trailing backslash.<br><br>**Note** This value is available starting in Windows 10, version 1703. |

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** code, including but not limited to the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *cchPathOut* value is greater than **PATHCCH_MAX_CCH**. |
| **PATHCCH_E_FILENAME_TOO_LONG** | A path segment has more than **PATHCCH_MAX_CCH** characters, or, if the **PATHCCH_ALLOW_LONG_PATHS** flag is not set, exceeds the standard path segment length limit of 256 characters. |
| **E_OUTOFMEMORY** | The function could not allocate a buffer of the necessary size. |

## Remarks

This function responds to the strings "." and ".." embedded in a path. The ".." string indicates to remove the immediately preceding path segment. The "." string indicates to skip over the next path segment. Note that the root segment of the path cannot be removed. If there are more ".." strings than there are path segments, the function returns **S_OK** and the buffer pointed to by *pszPathOut* contains a single backslash, "\\".

All trailing periods are removed from the path, except when preceded by the "*" wild card character. In that case, a single period is retained after the '*' character, but all other trailing periods are removed.

If the resulting path is a root drive ("x:"), a backslash is appended ("x:\\").

This function does not convert forward slashes (/) into back slashes (\\). With untrusted input, this function by itself, cannot be used to convert paths into a form that can be compared with other paths for sub-path or identity. Callers that need that ability should convert forward to back slashes before using this function.

The following examples show the effect of these strings.

| Original string | Canonicalized string |
| --- | --- |
| C:\name_1\.\name_2\..\name_3 | C:\name_1\name_3 |
| C:\name_1\..\name_2\.\name_3 | C:\name_2\name_3 |
| C:\name_1\name_2\.\name_3\..\name_4 | C:\name_1\name_2\name_4 |
| C:\name_1\.\name_2\.\name_3\..\name_4\.. | C:\name_1\name_2 |
| C:\name_1\*... | C:\name_1\*. |
| C:\.. | C:\ |

## See also

[PathCchCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalize)