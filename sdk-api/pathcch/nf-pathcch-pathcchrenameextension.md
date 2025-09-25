# PathCchRenameExtension function

## Description

Replaces a file name's extension at the end of a path string with a new extension. If the path string does not end with an extension, the new extension is added.

This function differs from [PathRenameExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function should be used in place of [PathRenameExtension](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathrenameextensiona) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, this value points to the same string, but with the renamed or added extension.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

### `pszExt` [in]

A pointer to the new extension string. The leading '.' character is optional. In the case of an empty string (""), any existing extension in the path string is removed.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.