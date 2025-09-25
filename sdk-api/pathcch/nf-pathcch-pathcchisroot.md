# PathCchIsRoot function

## Description

Determines whether a path string refers to the root of a volume.

This function differs from [PathIsRoot](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathisroota) in that it accepts paths with "\\", "\\?\" and "\\?\UNC\" prefixes.

## Parameters

### `pszPath` [in, optional]

A pointer to the path string.

## Return value

Returns **TRUE** if the specified path is a root, or **FALSE** otherwise.

## Remarks

The following table shows the **PathCchIsRoot** return value for various paths.

| Path | PathCchIsRoot |
| --- | --- |
| "c:\" | TRUE |
| "c:" | FALSE |
| "c:\path1" | FALSE |
| "\path1" | TRUE |
| "path1" | FALSE |
| "\\path1\path2" | TRUE |
| "\\path1\path2\" | FALSE |
| "\\path1\path2\path3" | FALSE |
| "\\path1" | TRUE |
| "\\path1\" | FALSE |
| "\\" | TRUE |
| "\\?\UNC\" | TRUE |
| "\\?\UNC\path1\path2" | TRUE |
| "\\?\UNC\path1\path2\" | FALSE |
| "\\?\UNC\path1\path2\path3" | FALSE |
| "\\?\UNC\path1" | TRUE |
| "\\?\UNC\path1\" | FALSE |
| "\\?\c:\" | TRUE |
| "\\?\c:" | FALSE |
| "\\?\c:\path1" | FALSE |
| "\\?\Volume{guid}\" | TRUE |
| "\\?\Volume{guid}" | FALSE |
| "\\?\Volume{guid}\path1" | FALSE |
| NULL | FALSE |
| "" | FALSE |

This function returns **TRUE** for paths such as "\", "*X*:\" or "\\*server*\*share*". Paths such as "..\path2" or "\\*server*\" return **FALSE**.