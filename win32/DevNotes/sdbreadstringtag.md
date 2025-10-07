# SdbReadStringTag function

Retrieves the string for the specified **TAGID**.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tiWhich* \[in\]

The **TAGID** that corresponds to the data to be retrieved.

*pwszBuffer* \[out\]

The buffer that receives the string. This parameter cannot be **NULL**.

*cchBufferSize* \[in\]

The size of the *pwszBuffer* buffer, in characters.

## Return value

The function returns **TRUE** on success or **FALSE** on failure.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

## See also

[**SdbGetBinaryTagData**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetbinarytagdata)

[**SdbGetStringTagPtr**](https://learn.microsoft.com/windows/win32/devnotes/sdbgetstringtagptr)

[**SdbReadBinaryTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreadbinarytag)

[**SdbReadDWORDTag**](https://learn.microsoft.com/windows/win32/devnotes/sdbreaddwordtag)

