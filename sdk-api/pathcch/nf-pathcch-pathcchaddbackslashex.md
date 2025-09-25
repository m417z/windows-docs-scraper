# PathCchAddBackslashEx function

## Description

Adds a backslash to the end of a string to create the correct syntax for a path. If the source path already has a trailing backslash, no backslash will be added.

This function differs from [PathCchAddBackslash](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslash) in that it can return a pointer to the new end of the string and report the number of unused characters remaining in the buffer.

This function differs from [PathAddBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, or **[PathCchAddBackslash](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslash)**, should be used in place of [PathAddBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathaddbackslasha) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the buffer contains the string with the appended backslash. This value should not be **NULL**.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

### `ppszEnd` [out, optional]

A value that, when this function returns successfully, receives the address of a pointer to the terminating null character at the end of the string.

### `pcchRemaining` [out, optional]

A pointer to a value that, when this function returns successfully, is set to the number of unused characters in the destination buffer, including the terminating null character.

## Return value

This function returns **S_OK** if the function was successful, **S_FALSE** if the path string already ends in a backslash, or an error code otherwise.

## See also

[PathCchAddBackslash](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchaddbackslash)