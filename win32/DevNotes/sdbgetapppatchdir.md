# SdbGetAppPatchDir function

Retrieves the system AppPatch directory.

## Parameters

*hSDB* \[in, optional\]

A handle to the shim database returned by the [**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase) function.

*szAppPatchPath* \[out\]

The resulting path.

*cchSize* \[in\]

The size of the *szAppPatchPath* buffer, in characters. If the function fails, this parameter is set to the empty string ("").

## Return value

This function does not return a value.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase)

