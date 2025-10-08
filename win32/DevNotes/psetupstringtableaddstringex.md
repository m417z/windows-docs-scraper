# pSetupStringTableAddStringEx function

\[This function is not available in Windows Vista or Windows Server 2008.\]

Adds a string and extra data to a table.

## Parameters

*StringTable* \[in\]

A pointer to the string table.

*String* \[in\]

A pointer to string to be added to the table.

*Flags* \[in\]

The value of this parameter can be `STRTAB_CASE_SENSITIVE | STRTAB_NEW_EXTRADATA`.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------|
| **STRTAB\_CASE\_SENSITIVE**<br>0x001 | String is case sensitive.<br> |
| **STRTAB\_NEW\_EXTRADATA**<br>0x004 | There is extra data.<br> |

*ExtraData* \[in, optional\]

A optional pointer to an extra data object.

*ExtraDataSize* \[in, optional\]

The size of the extra data.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Setupapi.dll |

