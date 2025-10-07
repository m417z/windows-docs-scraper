# SdbReleaseMatchingExe function

Releases resources used by the [**SdbGetMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetmatchingexe) function.

## Parameters

*hSDB* \[in\]

A handle to the shim database returned by the [**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase) function.

*trExe* \[in\]

The [**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref) returned by [**SdbGetMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetmatchingexe).

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetMatchingExe**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetmatchingexe)

[**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase)

