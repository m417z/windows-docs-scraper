# PathCchStripToRoot function

## Description

Removes all file and directory elements in a path except for the root information.

This function differs from [PathStripToRoot](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note** This function should be used in place of [PathStripToRoot](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathstriptoroota) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the path string. When this function returns successfully, this string contains only the root information taken from that path.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the path was truncated, **S_FALSE** if the path was already just a root, or an **HRESULT** failure code.

## Remarks

Some examples of the effect of this function:

| Initial string | Final string |
| --- | --- |
| "C:\path1\path2\file" | "C:\" |
| "\\path1\path2\path3" | "\\path1\path2" |
| "\path1" | "\" |