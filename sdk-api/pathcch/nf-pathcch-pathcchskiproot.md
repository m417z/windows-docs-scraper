# PathCchSkipRoot function

## Description

Retrieves a pointer to the first character in a path following the drive letter or Universal Naming Convention (UNC) server/share path elements.

This function differs from [PathSkipRoot](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathskiproota) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

## Parameters

### `pszPath` [in]

A pointer to the path string.

### `ppszRootEnd` [out]

The address of a pointer that, when this function returns successfully, points to the first character in a path following the drive letter or UNC server/share path elements. If the path consists of only a root, this value will point to the string's terminating null character.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.