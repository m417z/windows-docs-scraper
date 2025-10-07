# SdbGetMatchingExe function

Searches for the specified executable.

## Parameters

*hSDB* \[in, optional\]

A handle to the shim database returned by the [**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase) function.

*szPath* \[in\]

The path of the executable.

*szModuleName* \[in, optional\]

The module name.

*pszEnvironment* \[in, optional\]

The environment variables to be used as search context.

*dwFlags* \[in\]

This parameter can be 0 or **SDBGMEF\_IGNORE\_ENVIRONMENT** (0x1).

*pQueryResult* \[out\]

An [**SDBQUERYRESULT**](https://learn.microsoft.com/windows/win32/devnotes/sdbqueryresult) structure. If no match is found, the structure contains **TAGREF\_NULL**.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

When you have finished with the returned [**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref), free it using the [**SdbReleaseMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbreleasematchingexe) function.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase)

[**SdbReleaseMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbreleasematchingexe)

