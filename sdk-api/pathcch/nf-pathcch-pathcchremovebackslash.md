# PathCchRemoveBackslash function

## Description

Removes the trailing backslash from the end of a path string.

This function differs from [PathRemoveBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function, or [PathCchRemoveBackslashEx](https://learn.microsoft.com/windows/desktop/api/pathcch/nf-pathcch-pathcchremovebackslashex), should be used in place of [PathRemoveBackslash](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremovebackslasha) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the string contains the path with any trailing backslash removed. If no trailing backslash was found, the string is unchanged.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the function was successful, **S_FALSE** if the string was a root path or if no backslash was found, or an error code otherwise.

## Remarks

This function will not remove the backslash from a root path string, such as "C:\".