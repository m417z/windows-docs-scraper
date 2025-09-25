# PathCchAddBackslash function

## Description

Adds a backslash to the end of a string to create the correct syntax for a path. If the source path already has a trailing backslash, no backslash will be added.

This function differs from [PathCchAddBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslashex) in that you are restricted to a final path of length MAX_PATH.

This function differs from [PathAddBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, or [PathCchAddBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslashex), should be used in place of [PathAddBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the buffer contains the string with the appended backslash. This value should not be **NULL**.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the function was successful, **S_FALSE** if the path string already ends in a backslash, or an error code otherwise.

## See also

[PathCchAddBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslashex)