# SdbGetStringTagPtr function

Retrieves the string data for the specified **TAGID**.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiWhich* \[in\]

The **TAGID** that corresponds to the string data to be retrieved.

## Return value

The function returns a pointer to the string data or **NULL** if the **TAGID** is invalid or not of type **TAG\_TYPE\_STRING** or **TAG\_TYPE\_STRINGREF**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetBinaryTagData**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetbinarytagdata)

[**SdbReadDWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreaddwordtag)

[**SdbReadQWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadqwordtag)

[**SdbReadStringTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadstringtag)

