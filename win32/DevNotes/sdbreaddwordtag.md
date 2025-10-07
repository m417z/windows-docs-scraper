# SdbReadDWORDTag function

Retrieves the **DWORD** value for the specified **TAGID**.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiWhich* \[in\]

The **TAGID** that corresponds to the data to be retrieved.

*dwDefault* \[in\]

The default value to be returned on failure.

## Return value

The function returns the value on success or *dwDefault* on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetBinaryTagData**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetbinarytagdata)

[**SdbGetStringTagPtr**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetstringtagptr)

[**SdbReadQWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadqwordtag)

[**SdbReadStringTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadstringtag)

