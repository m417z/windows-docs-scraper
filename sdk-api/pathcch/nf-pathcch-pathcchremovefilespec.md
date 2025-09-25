# PathCchRemoveFileSpec function

## Description

Removes the last element in a path string, whether that element is a file name or a directory name. The element's leading backslash is also removed.

This function differs from [PathRemoveFileSpec](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

**Note**This function should be used in place of [PathRemoveFileSpec](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathremovefilespeca) to prevent the possibility of a buffer overrun.

## Parameters

### `pszPath` [in, out]

A pointer to the fully-qualified path string. When this function returns successfully, the string will have had its last element and its leading backslash removed. This function does not affect root paths such as "C:\". In the case of a root path, the path string is returned unaltered. If a path string ends with a trailing backslash, only that backslash is removed.

### `cchPath` [in]

The size of the buffer pointed to by *pszPath*, in characters.

## Return value

This function returns **S_OK** if the function was successful, **S_FALSE** if there was nothing to remove, or an error code otherwise.

## Remarks

The following table shows the effect of this function on a selection of path strings.

| Original String | Returned String |
| --- | --- |
| "C:\path1" | "C:\" |
| "C:\path1\path2" | "C:\path1" |
| "C:\path1\" | "C:\path1" |
| "\\path1\path2\path3" | "\\path1\path2" |
| "\path1" | "\" |