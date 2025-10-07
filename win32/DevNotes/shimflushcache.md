# ShimFlushCache function

Flushes the shim database cache. This function should be called after installing a new shim database.

## Parameters

*hwnd* \[in, optional\]

Unused; must be 0.

*hInstance* \[in, optional\]

Unused; must be 0.

*lpszCmdLine* \[in, optional\]

Unused; must be 0.

*nCmdShow* \[in\]

Unused; must be 0.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Remarks

The caller must be an administrator.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**BaseFlushAppcompatCache**](https://learn.microsoft.com/windows/win32/devnotes/baseflushappcompatcache)

