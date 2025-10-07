# SdbFindNextTag function

Searches for the next TAG match within the specified parent and returns the **TAGID** of the match.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiParent* \[in\]

The **TAGID** of the search start. This parameter can be **TAGID\_ROOT** or **TAG\_TYPE\_LIST**.

*tiPrev* \[in\]

The **TAGID** of the previous match.

## Return value

The **TAGID** of the match.

## Remarks

Before calling this function, call the [**SdbFindFirstTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirsttag) function.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFindFirstTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirsttag)

[**SdbTagRefToTagID**](https://learn.microsoft.com/windows/win32/devnotes/sdbtagreftotagid)

