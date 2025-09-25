# PathCchCanonicalize function

## Description

Converts a path string into a canonical form.

This function differs from [PathCchCanonicalizeEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalizeex) in that you are restricted to a final path of length MAX_PATH.

This function differs from [PathAllocCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccanonicalize) in that the caller must declare the size of the returned string, which is stored on the stack.

This function differs from [PathCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, [PathCchCanonicalizeEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalizeex), or [PathAllocCanonicalize](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathalloccanonicalize) should be used in place of [PathCanonicalize](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathcanonicalizea) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPathOut` [out]

A pointer to a buffer that, when this function returns successfully, receives the canonicalized path string.

### `cchPathOut` [in]

The size of the buffer pointed to by *pszPathOut*, in characters.

### `pszPathIn` [in]

A pointer to the original path string. If this value points to an empty string, or results in an empty string once the "." and ".." elements are removed, a single backslash is copied to the buffer pointed to by *pszPathOut*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** code, including the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *cchPathOut* value is greater than **PATHCCH_MAX_CCH**. |
| **PATHCCH_E_FILENAME_TOO_LONG** | A path segment exceeds the standard path segment length limit of 256 characters. |
| **E_OUTOFMEMORY** | The function could not allocate a buffer of the necessary size. |

## Remarks

This function responds to the strings "." and ".." embedded in a path. The ".." string indicates to remove the immediately preceding path segment. The "." string indicates to skip over the next path segment. Note that the root segment of the path cannot be removed. If there are more ".." strings than there are path segments, the function returns S_OK and the buffer pointed to by *pszPathOut* contains a single backslash, "\\".

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

[PathCchCanonicalizeEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchcanonicalizeex)