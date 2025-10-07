# SdbFindFirstTag function

Searches for a TAG match within the specified parent and returns the **TAGID** of the first match.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiParent* \[in\]

The **TAGID** of the search start. This parameter can be **TAGID\_ROOT** or **TAG\_TYPE\_LIST**.

*tTag* \[in\]

The TAG to be matched. See [TAG](https://learn.microsoft.com/windows/win32/devnotes/tag) for a list of possible values.

## Return value

The **TAGID** of the first match.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFindNextTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindnexttag)

[**SdbTagRefToTagID**](https://learn.microsoft.com/windows/win32/devnotes/sdbtagreftotagid)

