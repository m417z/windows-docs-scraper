# PathCchRemoveExtension function

## Description

Removes the file name extension from a path, if one is present.

This function differs from [PathRemoveExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note**This function, should be used in place of [PathRemoveExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremoveextensiona) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the string contains the path with any extension removed. If no extension was found, the string is unchanged.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the function was successful, **S_FALSE** if no extension was found, or an error code otherwise.