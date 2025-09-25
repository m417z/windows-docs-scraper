# PathResolve function

## Description

[**PathResolve** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Converts a relative or unqualified path name to a fully qualified path name.

## Parameters

### `pszPath` [in, out]

Type: **PWSTR**

A null-terminated Unicode string that contains the path to resolve. When the function returns, the string contains the corresponding fully qualified path. This buffer should be at least MAX_PATH characters long.

### `dirs` [in, optional]

Type: **PZPCWSTR**

A pointer to an optional null-terminated array of directories to be searched first in the case that the path cannot be resolved from *pszPath*. This value can be **NULL**.

### `fFlags`

Type: **UINT**

Flags that specify how the function operates.

#### PRF_VERIFYEXISTS

Return **TRUE** if the file's existence is verified; otherwise **FALSE**.

#### PRF_TRYPROGRAMEXTENSIONS

Look for the specified path with the following extensions appended: .pif, .com, .bat, .cmd, .lnk, and .exe.

#### PRF_FIRSTDIRDEF

Look first in the directory or directories specified by *dirs*.

#### PRF_DONTFINDLNK

Ignore .lnk files.

#### PRF_REQUIREABSOLUTE

Require an absolute (full) path.

## Return value

Type: **int**

Returns **TRUE**, unless PRF_VERIFYEXISTS is set. If that flag is set, the function returns **TRUE** if the file is verified to exist and **FALSE** otherwise. It also sets an ERROR_FILE_NOT_FOUND error code that you can retrieve by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A **FALSE** return value does not necessarily mean that the file does not exist. It might mean that the function is simply unable to find the file from the supplied information.

If **PathResolve** cannot resolve the path specified in *pszPath*, it calls [PathFindOnPath](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathfindonpatha) using *pszPath* and *dirs* as the parameters.

## See also

[PathFindOnPath](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathfindonpatha)