# SdbGetBinaryTagData function

Retrieves the binary data for the specified **TAGID**.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiWhich* \[in\]

The **TAGID** that corresponds to the data to be retrieved.

## Return value

The function returns a pointer to the binary data or **NULL** if the **TAGID** is invalid.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetStringTagPtr**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetstringtagptr)

[**SdbReadDWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreaddwordtag)

[**SdbReadQWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadqwordtag)

[**SdbReadStringTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadstringtag)

