# MakeSureDirectoryPathExists function

## Description

Creates all the directories in the specified path, beginning with the root.

## Parameters

### `DirPath` [in]

A valid path name. If the final component of the path is a directory, not a file name, the string must end
with a backslash (\\) character.

## Return value

If the function succeeds, the return value is **TRUE**.

If the function fails, the return value is **FALSE**. To retrieve extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Each directory specified is created, if it does not already exist. If only some of the directories are
created, the function will return **FALSE**.

This function does not support Unicode strings. To specify a Unicode path, use the
[SHCreateDirectoryEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreatedirectoryexa) function.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)