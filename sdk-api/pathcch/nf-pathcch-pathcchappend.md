# PathCchAppend function

## Description

Appends one path to the end of another.

This function differs from [PathCchAppendEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappendex) in that you are restricted to a final path of length MAX_PATH.

This function differs from [PathAppend](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, or [PathCchAppendEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappendex), should be used in place of [PathAppend](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathappenda) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to a buffer that, on entry, contains the original path. When this function returns successfully, the buffer contains the original path plus the appended path.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

### `pszMore` [in, optional]

A pointer to the path to append to the end of the path pointed to by *pszPath*. UNC paths and paths beginning with the "\\?\" sequence are accepted and recognized as fully-qualified paths. These paths replace the string pointed to by *pszPath* instead of being appended to it.

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

[PathCchAppendEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchappendex)