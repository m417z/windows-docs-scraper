# SdbGetIndex function

Retrieves the index for the specified tag and key type from the specified database.

## Parameters

*pdb* \[in\]

A handle to the shim database.

*tWhich* \[in\]

The TAG.

*tKey* \[in\]

The key type.

*lpdwFlags* \[out, optional\]

This parameter can be 0 or **SHIMDB\_INDEX\_UNIQUE\_KEY** (0x00000001).

## Return value

The **TAGID** of the index or **TAGID\_NULL**.

## Remarks

The resulting index can be used for read operations.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Apphelp.dll |

