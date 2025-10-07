# SdbFreeFileAttributes function

Frees the specified file attribute data.

## Parameters

*pFileAttributes* \[in\]

An [**ATTRINFO**](https://learn.microsoft.com/windows/win32/devnotes/attrinfo) structure returned by the [**SdbGetFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfileattributes) function.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetFileAttributes**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfileattributes)

