# SdbGetNextChild function

Searches for the next child TAG within the specified parent and returns the **TAGID** of the next child.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiParent* \[in\]

The **TAGID** of the search start. This parameter can be **TAGID\_ROOT** or **TAG\_TYPE\_LIST**.

*tiPrev* \[in\]

The **TAGID** of the previous child.

## Return value

The **TAGID** of the child or **TAGID\_NULL** if no child is found.

## Remarks

Before calling this function, call the [**SdbGetFirstChild**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfirstchild) function.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbFindFirstTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindfirsttag)

[**SdbFindNextTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbfindnexttag)

[**SdbGetFirstChild**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetfirstchild)

