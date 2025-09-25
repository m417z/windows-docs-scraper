# PathCchStripPrefix function

## Description

Removes the "\\?\" prefix, if present, from a file path.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, the same path string will have had the prefix removed, if the prefix was present. If no prefix was present, the string will be unchanged.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the prefix was removed, **S_FALSE** if the path did not have a prefix to remove, or an **HRESULT** failure code.