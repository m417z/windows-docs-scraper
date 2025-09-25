# PathCchCombineEx function

## Description

Combines two path fragments into a single path. This function also canonicalizes any relative path elements, removing "." and ".." elements to simplify the final path.

This function differs from [PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine) in that it allows for a longer final path to be constructed.

This function differs from [PathAllocCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccombine) in that the caller must declare the size of the returned string, which is stored on the stack.

This function differs from [PathCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, [PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine), or [PathAllocCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccombine) should be used in place of [PathCombine](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcombinea) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPathOut` [out]

A pointer to a buffer that, when this function returns successfully, receives the combined path string. This parameter can point to the same buffer as *pszPathIn* or *pszMore*.

### `cchPathOut` [in]

The size of the buffer pointed to by *pszPathOut*, in characters.

### `pszPathIn` [in, optional]

A pointer to the first path string. This value can be **NULL**.

### `pszMore` [in, optional]

A pointer to the second path string. If this path begins with a single backslash, it is combined with only the root of the path pointed to by *pszPathIn*. If this path is fully qualified, it is copied directly to the output buffer without being combined with the other path. This value can be **NULL**.

### `dwFlags` [in]

One or more of the following flags:

| Value | Meaning |
| --- | --- |
| **PATHCCH_NONE**<br><br>0x0000000 | Do not allow for the construction of \\?\ paths (ie, long paths) longer than **MAX_PATH** . |
| **PATHCCH_ALLOW_LONG_PATHS**<br><br>0x00000001 | Allow the construction of \\?\ paths longer than **MAX_PATH**. Note that *cchPathOut* must be greater than **MAX_PATH**. If it is not, this flag is ignored. |
| **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**<br><br>0x00000002 | Forces the API to treat the caller as long path enabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_FORCE_DISABLE_LONG_NAME_PROCESS**<br><br>0x00000004 | Forces the API to treat the caller as long path disabled, independent of the process's long name enabled state. This option can be used only when **PATHCCH_ALLOW_LONG_PATHS** is specified, and cannot be used with **PATHCCH_FORCE_ENABLE_LONG_NAME_PROCESS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**<br><br>0x00000008 | Disables the normalization of path segments that includes removing trailing dots and spaces. This enables access to paths that win32 path normalization will block.<br><br>**Note** This value is available starting in Windows 10, version 1703. |
| **PATHCCH_ENSURE_IS_EXTENDED_LENGTH_PATH**<br><br>0x00000010 | Converts the input path into the extended length DOS device path form (with the \\?\ prefix) if not already in that form. This enables access to paths that are otherwise not addressable due to Win32 normalization rules (that can strip trailing dots and spaces) and path length limitations. This option implies the same behavior of **PATHCCH_DO_NOT_NORMALIZE_SEGMENTS**.<br><br>**Note** This value is available starting in Windows 10, version 1703. |

## Return value

This function returns an **HRESULT** code, including the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. Note that this also includes the case of an empty extension, such as a period with no characters following it. In that case, the original string is returned unaltered. |
| **E_INVALIDARG** | This value can be caused by several things, such as the *pszPathOut* param being set to **NULL**, or the *cchPathOut* value being set to 0 or a value greater than **PATHCCH_MAX_CCH** . |
| **E_OUTOFMEMORY** | The function could not allocate enough memory to perform the operation. |
| **PATHCCH_E_FILENAME_TOO_LONG** | The size of one or both of the original paths exceeded **PATHCCH_MAX_CCH** . |

## Remarks

If both *pszPathIn* and *pszMore* are **NULL** or point to empty strings, a single backslash is copied to the buffer pointed to by *pszPathOut*.

## See also

[PathCchCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalize)

[PathCchCanonicalizeEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalizeex)

[PathCchCombine](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcombine)