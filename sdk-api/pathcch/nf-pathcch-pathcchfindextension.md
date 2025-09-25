# PathCchFindExtension function

## Description

Searches a path to find its file name extension, such as ".exe" or ".ini". This function does not search for a specific extension; it searches for the presence of any extension.

This function differs from [PathFindExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function should be used in place of [PathFindExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathfindextensiona) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in]

A pointer to the path to search.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath* in characters, including the null terminator.

### `ppszExt` [out]

The address of a pointer that, when this function returns successfully, points to the "." character that precedes the extension within *pszPath*. If no extension is found, it points to the string's terminating null character.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.