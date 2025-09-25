# PathAllocCombine function

## Description

Concatenates two path fragments into a single path. This function also canonicalizes any relative path elements, replacing path elements such as "." and "..".

This function differs from [PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine) and [PathCchCombineEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombineex) in that it returns the result on the heap. This means that the caller does not have to declare the size of the returned string and reduces stack use.

This function differs from [PathCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, [PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine), or [PathCchCombineEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombineex), should be used in place of [PathCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea).

<

## Parameters

### `pszPathIn` [in]

A pointer to the first path string.

### `pszMore` [in]

A pointer to the second path string. If this path begins with a single backslash, it is combined with only the root of the path pointed to by *pszPathIn*. If this path is fully qualified, it is copied directly to the output buffer without being combined with the other path.

### `dwFlags` [in]

One or more of the following flags:

| Value | Meaning |
| --- | --- |
| **PATHCCH_NONE**<br><br>0x0000000 | Do not allow for the construction of \\?\ paths (ie, long paths) longer than **MAX_PATH** . |
| **PATHCCH_ALLOW_LONG_PATHS**<br><br>0x00000001 | Allow the construction of \\?\ paths longer than **MAX_PATH** . |
| **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**<br><br>0x00000002 | Forces the API to treat the caller as long path enabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**<br><br>0x00000004 | Forces the API to treat the caller as long path disabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**<br><br>0x00000008 | Disables the normalization of path segments that includes removing trailing dots and spaces. This enables access to paths that win32 path normalization will block.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH**<br><br>0x00000010 | Converts the input path into the extended length DOS device path form (with the \\?\ prefix) if not already in that form. This enables access to paths that are otherwise not addressable due to Win32 normalization rules (that can strip trailing dots and spaces) and path length limitations. This option implies the same behavior of **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_TRAILING_SLASH**<br><br>0x00000020 | When combining or normalizing a path, ensure there is a trailing backslash.<br><br>**Note** This value is available starting in Windows 10, version 1703. |

### `ppszPathOut` [out]

The address of a pointer to a buffer that, when this function returns successfully, receives the combined path string. It is the responsibility of the caller to free this resource, when it is no longer needed, by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function. This value cannot be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

While either *pszPathIn* or *pszMore* can **NULL**, they cannot both be **NULL**.

This function supports these alternate path forms:

* \\?\
* \\?\\UNC\
* \\?\Volume{guid}\

## See also

[PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine)

[PathCchCombineEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombineex)