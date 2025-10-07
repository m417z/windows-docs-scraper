# SdbGetFirstChild function

Searches for a child TAG within the specified parent and returns the **TAGID** of the first child.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiParent* \[in\]

The **TAGID** of the search start. This parameter can be **TAGID\_ROOT** or **TAG\_TYPE\_LIST**.

## Return value

The **TAGID** of the first child or **TAGID\_NULL** is no child is found.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFindFirstTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirsttag)

[**SdbFindNextTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindnexttag)

[**SdbGetNextChild**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetnextchild)

