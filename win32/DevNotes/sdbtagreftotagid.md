# SdbTagRefToTagID function

Retrieves the **TAGID** and a handle to the shim database for the specified [**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref).

## Parameters

*hSDB* \[in\]

A handle to the shim database returned by the [**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase) function.

*trWhich* \[in\]

The [**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref).

*ppdb* \[out\]

The resulting handle to the shim database.

*ptiWhich* \[out\]

The resulting **TAGID**.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbInitDatabase**](https://learn.microsoft.com/windows/win32/devnotes/sdbinitdatabase)

[**TAGID**](https://learn.microsoft.com/windows/win32/devnotes/tagid)

[**TAGREF**](https://learn.microsoft.com/windows/win32/devnotes/tagref)

