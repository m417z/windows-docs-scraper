# PathIsUNCEx function

## Description

Determines if a path string is a valid Universal Naming Convention (UNC) path, as opposed to a path based on a drive letter.

This function differs from [PathIsUNC](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathisunca) in that it also allows you to extract the name of the server from the path.

## Parameters

### `pszPath` [in]

A pointer to the path string.

### `ppszServer` [out, optional]

A pointer to a string that, when this function returns successfully, receives the server portion of the UNC path. This value can be **NULL** if you don't need this information.

## Return value

Returns **TRUE** if the string is a valid UNC path; otherwise, **FALSE**.